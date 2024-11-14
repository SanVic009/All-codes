#include <iostream>
#include <list>
#include <string>
#include <algorithm>
using namespace std;

class Item
{
public:
    int Item_Code;
    string Item_Name;
    int Item_Quantity;
    float Item_Price;

    Item(int code, string name, int qty, float price)
        : Item_Code(code), Item_Name(name), Item_Quantity(qty), Item_Price(price) {}

    void display() const
    {
        cout << "Item Code: " << Item_Code << ", Item Name: " << Item_Name
             << ", Quantity: " << Item_Quantity << ", Price per unit: " << Item_Price << endl;
    }
};

class Inventory
{
    list<Item> items;

public:
    void addItem(int code, string name, int qty, float price)
    {
        items.push_back(Item(code, name, qty, price));
    }

    Item *searchItem(int code, const string &name = "")
    {
        for (auto &item : items)
        {
            if (item.Item_Code == code || item.Item_Name == name)
            {
                return &item;
            }
        }
        return nullptr;
    }

    void displayItems()
    {
        if (items.empty())
        {
            cout << "No items in inventory.\n";
            return;
        }

        cout << "\nItems in Inventory:\n";
        for (const auto &item : items)
        {
            item.display();
        }
    }

    void purchaseItem(int code, const string &name = "")
    {
        Item *item = searchItem(code, name);
        if (item != nullptr)
        {
            cout << "Item found.\n";
            item->display();
            int quantityRequired;
            cout << "Enter the quantity required: ";
            cin >> quantityRequired;

            if (quantityRequired <= item->Item_Quantity)
            {
                float totalCost = quantityRequired * item->Item_Price;
                item->Item_Quantity -= quantityRequired;
                cout << "Total cost: " << totalCost << endl;
                cout << "Purchase successful.\n";
            }
            else
            {
                cout << "Required item's quantity is not in stock.\n";
            }
        }
        else
        {
            cout << "Requested Item is not available.\n";
        }
    }

    void removeItem(int code)
    {
        items.remove_if([&code](const Item &item)
                        { return item.Item_Code == code; });
        cout << "Item removed successfully, if it was present.\n";
    }

    void sortItems(bool byCode = true)
    {
        if (byCode)
        {
            items.sort([](const Item &a, const Item &b)
                       { return a.Item_Code < b.Item_Code; });
        }
        else
        {
            items.sort([](const Item &a, const Item &b)
                       { return a.Item_Name < b.Item_Name; });
        }
        cout << "Items sorted successfully.\n";
    }
};

void inventoryMenu()
{
    Inventory inventory;
    int choice, code, quantity;
    float price;
    string name;

    do
    {
        cout << "\nInventory Management System\n";
        cout << "1. Add Item\n";
        cout << "2. Display All Items\n";
        cout << "3. Search Item\n";
        cout << "4. Purchase Item\n";
        cout << "5. Remove Item\n";
        cout << "6. Sort Items by Code\n";
        cout << "7. Sort Items by Name\n";
        cout << "8. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter Item Code: ";
            cin >> code;
            cout << "Enter Item Name: ";
            cin >> name;
            cout << "Enter Item Quantity: ";
            cin >> quantity;
            cout << "Enter Item Price: ";
            cin >> price;
            inventory.addItem(code, name, quantity, price);
            break;

        case 2:
            inventory.displayItems();
            break;

        case 3:
            cout << "Enter Item Code to search: ";
            cin >> code;
            {
                Item *item = inventory.searchItem(code);
                if (item != nullptr)
                {
                    item->display();
                }
                else
                {
                    cout << "Item not found.\n";
                }
            }
            break;

        case 4:
            cout << "Enter Item Code to purchase: ";
            cin >> code;
            inventory.purchaseItem(code);
            break;

        case 5:
            cout << "Enter Item Code to remove: ";
            cin >> code;
            inventory.removeItem(code);
            break;

        case 6:
            inventory.sortItems(true);
            break;

        case 7:
            inventory.sortItems(false);
            break;

        case 8:
            cout << "Exiting the program.\n";
            break;

        default:
            cout << "Invalid choice! Try again.\n";
            break;
        }
    } while (choice != 8);
}

int main()
{
    inventoryMenu();
    return 0;
}