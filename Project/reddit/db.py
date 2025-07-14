import psycopg2

def connection():
    conn = psycopg2.connect(
        database = "postgres",
        user = 'postgres',
        host = 'localhost',
        password= "Postgre,009",
        port = 5432
    )

# Initialize a cursor for database operations
# cur = conn.cursor();

# # standard query
# # cur.execute("""
# #             CREATE TABLE test(
# #                 entry_id SERIAL PRIMARY KEY,
# #                 name VARCHAR(44) NOT NULL,
# #                 employment_status NUMBER NOT NULL
# #             );
# #             """)

# cur.execute("""SELECT table_name FROM information_schema.tables
#             WHERE table_schema = 'public';
#             """)

# for table in cur.fetchall():
#     print(table)
# # To make the changes in database persistent or permanent
# # conn.commit()

# # To close the cursor and the connection.
# cur.close()
# conn.close()