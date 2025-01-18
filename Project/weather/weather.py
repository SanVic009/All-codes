import mysql.connector
# import passw


db = mysql.connector.connect(
    host= "localhost",
    user= "root",
    password= "Mysql,009",
    database= "weather"
)

print(db)

cursor = db.cursor()
cursor.execute("create database if not exists weather;")

cursor.execute("Show databases;")

for i in cursor:
    print(i)
    