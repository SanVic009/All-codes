import psycopg2 as db
from faker import Faker

conn_string = "dbname = 'de' host='localhost' user='postgres' password='root'"
conn = db.connect(conn_string)
cur = conn.cursor()

query = f"insert into users (name, street, city, zip) values('Lewis Hamilton', 'Wellington','London', {str(13134)})"
query2 = f"insert into users (name, street, city, zip) values(%s, %s, %s, %s)"

# data = ('Max Verstappen', '44444', 'Zandvoort', '24242')

data = []
fake = Faker()

for _ in range(200):
    ll = [fake.name(), fake.street_address(), fake.city(), str(fake.zipcode())]
    data.append(ll)

    
# print(data)

# print(cur.mogrify(query))
# print(cur.mogrify(query2, data[0]))
# print(cur.mogrify(query2, data[1]))

query3 = "select * from users;"

cur.execute(query3)

with open('users.csv', 'w') as file:
    cur.copy_to(file, 'users', sep=',')
    print("Print done.")

# for i in cur:
#     print(i)
# cur.executemany(query2, data)
# cur.execute(query)
# conn.commit()