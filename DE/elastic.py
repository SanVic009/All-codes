from elasticsearch import Elasticsearch
from faker import Faker

fake = Faker()
es = Elasticsearch({'http://localhost:9200'})

doc = {
    "name":fake.name(),
    'street':fake.street_address(),
    'city':fake.city(),
    'zip':fake.zipcode()
}


res = es.index(index="users", body=doc)
print(res['results'])