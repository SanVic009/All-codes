import time
import psutil
import pygetwindow as gw
from datetime import datetime
from pymongo import MongoClient

def get_active_window():
    try:
        active_window = gw.getActiveWindow()
        if active_window:
            return active_window.title
        else:
            return None
    except Exception as e:
        print(f"Error retrieving active window: {e}")
        return None

def log_active_window(mongo_collection):
    active_window_title = get_active_window()
    if active_window_title:
        current_time = datetime.now().strftime("%Y-%m-%d %H:%M:%S")
        data={
            "window": active_window_title,
            "time": current_time
        }
        mongo_collection.insert_one(data)
        print(f"Logged : {data}")

def connect_to_mongo():
    try:
        client = MongoClient('localhost', 27017)
        db = client['activeWindowDB']
        collection = db['windowLog']
        return collection
    except Exception as e:
            print(f"Error connecting to MongoDB: {e}")
            return None
        
if __name__ == "__main__":
    mongo_collection = connect_to_mongo()
    if mongo_collection is not None:
        while True:
            log_active_window(mongo_collection)
            time.sleep(5)