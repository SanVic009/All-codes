#include <iostream>
#include <stdexcept>
#include <string>
using namespace std;

class Hotel
{
private:
    string cust_name;
    int cust_id;
    int age;
    int income;
    string city;
    string room_type;

public:
    Hotel() : cust_name(""), cust_id(0), age(0), income(0), city(""), room_type("") {}

    void accept()
    {
        cout << "Enter customer name: ";
        cin >> cust_name;

        cout << "Enter customer ID: ";
        cin >> cust_id;
    }

    void display() const
    {
        cout << "\nCustomer Details:\n";
        cout << "Name: " << cust_name << endl;
        cout << "ID: " << cust_id << endl;
        cout << "Age: " << age << endl;
        cout << "Income: " << income << endl;
        cout << "City: " << city << endl;
        cout << "Room Type: " << room_type << endl;
    }

    void getage()
    {
        cout << "Enter age: ";
        cin >> age;
        if (age < 18 || age > 55)
        {
            throw runtime_error("Age must be between 18 and 55.");
        }
    }

    void getincome()
    {
        cout << "Enter income: ";
        cin >> income;
        if (income < 50000 || income > 100000)
        {
            throw runtime_error("Income must be between 50000 and 100000.");
        }
    }

    void getcity()
    {
        cout << "Enter city (Pune/Mumbai): ";
        cin >> city;
        getchar();
        if (city != "Pune" && city != "Mumbai")
        {
            throw runtime_error("City must be either Pune or Mumbai.");
        }
    }

    void getroom_type()
    {
        cout << "Enter room type (deluxe/superdeluxe): ";
        getline(cin, room_type);
        if (room_type != "deluxe" && room_type != "super deluxe")
        {
            throw runtime_error("Room type must be either 'deluxe' or 'superdeluxe'.");
        }
    }
};

int main()
{
    Hotel hotel;

    try
    {
        hotel.accept();
        hotel.getage();
        hotel.getincome();
        hotel.getcity();
        hotel.getroom_type();
        hotel.display();
    }
    catch (const runtime_error &e)
    {
        cout << "Error: " << e.what() << endl;
    }

    return 0;
}