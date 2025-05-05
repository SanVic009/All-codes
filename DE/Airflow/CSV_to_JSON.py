import datetime as dt
from datetime import timedelta

from faker import Faker
from airflow import DAG
from airflow.operators.bash import BashOperator
from airflow.operators.python import PythonOperator

import pandas as pd

def csvToJson():
    df = pd.read_csv('data.csv')
    for i, r in df.iterrows():
        print(r['name'])
    df.to_json('fromAirflow.JSON', orient='records')
    
default_args = {
    'owner' : "adming",
    'start_date' : dt.datetime(2025, 4, 30),
    'retries' : 2,
    'retry_delay' : dt.timedelta(minutes=1)
}

with DAG('MyCSVDAG',
         default_args=default_args,
         schedule_interval=timedelta(minutes=2),
         # '0 * * * *'
        ) as dag:
    print_starting = BashOperator(task_id='starting',
                                  bash_command='echo "I am reading this CSV now..."')
    CSVJSON = PythonOperator(task_id='convertCSVToJSON',
                             python_callable=csvToJson)

# print_starting.set_downstream(CSVJSON)
# CSVJSON.set_upstream(print_starting)
print_starting >> CSVJSON
