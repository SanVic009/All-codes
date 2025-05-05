from faker import Faker
import csv

file = open('./Airflow/data.csv', 'w')
myWrite = csv.writer(file)


fake = Faker()
header =['name', 'age', 'street', 'city', 'state', 'zip', 'lat', 'lon'] 

myWrite.writerow(header)

for i in range(199):
    myWrite.writerow([fake.name(),
                       fake.random_int(min=18, max=120),
                       fake.street_address(),
                       fake.city(),
                       fake.state(),
                       fake.zipcode(),
                       fake.latitude(),
                       fake.longitude()])
    
file.close()
