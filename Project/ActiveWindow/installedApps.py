# import psutil
# import re

# app = []
# def getInstalledApps():
#     for proc in psutil.process_iter(['name']):
#         app.append(proc.info('name'))

# for apps in app:
#     print(app)

# from winapps import AppList

# def getInstalledApps():
#     apps = AppList().get_installed()
#     return [app['name'] for app in apps]

# def main():
#     installed_apps = getInstalledApps()
#     for app in installed_apps:
#         print(app)

# if __name__ == "__main__":
#     main()

from windows_tools.installed_software import get_installed_software
from pymongo import MongoClient


def connect_to_mongo():
    try:
        client = MongoClient("localhost", 27017)
        db = client["activeWindowDB"]
        collection = db["installedApps"]
        return collection
    except Exception as e:
        print(f"Error connecting to MongoDB: {e}")
        return None


appList = []


def installedAppNames(mongoCollection):
    for software in get_installed_software():
        # appList.append( software['name'])
        data = {"name": software["name"]}
        mongoCollection.insert_one(data)
        print(f"Logged {data}")


def main():
    mongoCollection = connect_to_mongo()
    installedAppNames(mongoCollection)


if __name__ == "__main__":
    main()
