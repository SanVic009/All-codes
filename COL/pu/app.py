from flask import Flask, request, jsonify
import mysql.connector
from mysql.connector import Error

app = Flask(__name__)


def get_db_connection():
    connection = mysql.connector.connect(
        host="localhost",
        database="banking_system",
        user="root",
        password="your_password",
    )
    return connection


@app.route("/deposit", methods=["POST"])
def deposit():
    try:
        account_id = request.json["account_id"]
        amount = request.json["amount"]

        connection = get_db_connection()
        cursor = connection.cursor()

        cursor.execute(
            "UPDATE accounts SET balance = balance + %s WHERE account_id = %s",
            (amount, account_id),
        )
        connection.commit()

        cursor.execute(
            """
            INSERT INTO account_logs (action, account_id, old_balance, new_balance)
            SELECT 'Deposit', ?, balance - ?, balance + ? FROM accounts WHERE account_id = ?
        """,
            (account_id, amount, amount, account_id),
        )
        connection.commit()

        return jsonify({"message": "Deposit successful!"}), 200

    except Error as e:
        return jsonify({"error": str(e)}), 500
    finally:
        cursor.close()
        connection.close()


@app.route("/withdraw", methods=["POST"])
def withdraw():
    try:
        account_id = request.json["account_id"]
        amount = request.json["amount"]

        connection = get_db_connection()
        cursor = connection.cursor()

        cursor.execute(
            "SELECT balance FROM accounts WHERE account_id = %s", (account_id,)
        )
        balance = cursor.fetchone()[0]

        if balance >= amount:
            cursor.execute(
                "UPDATE accounts SET balance = balance - %s WHERE account_id = %s",
                (amount, account_id),
            )
            connection.commit()

            cursor.execute(
                """
                INSERT INTO account_logs (action, account_id, old_balance, new_balance)
                SELECT 'Withdrawal', ?, balance + ?, balance - ? FROM accounts WHERE account_id = ?
            """,
                (account_id, amount, amount, account_id),
            )
            connection.commit()

            return jsonify({"message": "Withdrawal successful!"}), 200
        else:
            return jsonify({"error": "Insufficient balance"}), 400

    except Error as e:
        return jsonify({"error": str(e)}), 500
    finally:
        cursor.close()
        connection.close()


@app.route("/balance", methods=["GET"])
def balance():
    try:
        account_id = request.args.get("account_id")

        connection = get_db_connection()
        cursor = connection.cursor()

        cursor.execute(
            "SELECT balance FROM accounts WHERE account_id = %s", (account_id,)
        )
        balance = cursor.fetchone()

        if balance:
            return jsonify({"account_id": account_id, "balance": balance[0]}), 200
        else:
            return jsonify({"error": "Account not found"}), 404

    except Error as e:
        return jsonify({"error": str(e)}), 500
    finally:
        cursor.close()
        connection.close()


if __name__ == "__main__":
    app.run(debug=True)
