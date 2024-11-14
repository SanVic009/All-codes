#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <iomanip>               // For std::setw
#include <typeinfo>              // For typeid
#include "html_bill_generator.h" // Include the header file for HTML bill generation

using namespace std;

const double TAX_RATE = 0.07; // 7% tax for this example

// Base class Product
class Product
{
public:
    string name;
    double price;
    int quantity;

    Product(string n = "", double p = 0.0, int q = 0) : name(n), price(p), quantity(q) {}

    virtual void display() const
    {
        cout << left << setw(25) << name << setw(10) << price << setw(10) << quantity;
    }

    virtual ~Product() {}
};

// Derived class for perishable products
class PerishableProduct : public Product
{
public:
    string expirationDate;

    PerishableProduct(string n, double p, int q, string expDate) : Product(n, p, q), expirationDate(expDate) {}

    void display() const override
    {
        Product::display();
        cout << setw(15) << expirationDate;
    }
};

// Template class for Supermarket
template <typename T>
class Supermarket
{
private:
    vector<T> products;

public:
    void addProduct(const T &product)
    {
        products.push_back(product);
    }

    void deleteProduct(int index)
    {
        if (index >= 0 && index < static_cast<int>(products.size()))
        {
            products.erase(products.begin() + index);
            cout << "Product removed successfully.\n";
        }
        else
        {
            cout << "Invalid product index. Unable to delete.\n";
        }
    }

    void displayProducts() const
    {
        cout << "\n================= Available Products =================\n";
        cout << left << setw(5) << "No." << setw(25) << "Product" << setw(10) << "Price" << setw(10) << "Quantity";
        if (typeid(T) == typeid(PerishableProduct))
        {
            cout << setw(15) << "Expiration Date";
        }
        cout << endl;
        cout << string(65, '=') << endl;

        for (size_t i = 0; i < products.size(); ++i)
        {
            cout << left << setw(5) << i + 1;
            products[i].display();
            cout << endl;
        }
        cout << string(65, '=') << endl;

        double totalInventoryValue = 0.0;
        for (const auto &product : products)
        {
            totalInventoryValue += product.price * product.quantity;
        }
        cout << "Total Inventory Value: Rs." << totalInventoryValue << endl;
    }

    string getProductName(int index) const
    {
        if (index >= 0 && index < static_cast<int>(products.size()))
        {
            return products[index].name;
        }
        return "Invalid Product";
    }

    double getProductPrice(int index) const
    {
        if (index >= 0 && index < static_cast<int>(products.size()))
        {
            return products[index].price;
        }
        return 0.0;
    }

    void decrementProductQuantity(int index, int quantity)
    {
        if (index >= 0 && index < static_cast<int>(products.size()))
        {
            if (products[index].quantity >= quantity)
            {
                products[index].quantity -= quantity;
            }
            else
            {
                cout << "Error: Not enough stock for " << products[index].name << endl;
            }
        }
    }
};

// Function to generate the bill and display items
template <typename T>
void printBill(const vector<pair<int, int>> &selectedItems, Supermarket<T> &supermarket)
{
    cout << "\n================= FINAL BILL =================\n";
    cout << left << setw(25) << "Product" << setw(10) << "Quantity" << setw(10) << "Price" << setw(10) << "Total" << endl;
    cout << string(65, '=') << endl;

    double totalBill = 0.0;
    vector<pair<string, pair<double, int>>> purchasedItems;

    for (const auto &item : selectedItems)
    {
        int productIndex = item.first - 1;
        int quantity = item.second;
        double price = supermarket.getProductPrice(productIndex);
        double totalPrice = price * quantity;
        totalBill += totalPrice;

        cout << left << setw(25) << supermarket.getProductName(productIndex) << setw(10) << quantity << setw(10) << price << setw(10) << totalPrice << endl;

        // Decrement product quantity after the purchase
        supermarket.decrementProductQuantity(productIndex, quantity);

        purchasedItems.push_back({supermarket.getProductName(productIndex), {price, quantity}});
    }

    double tax = totalBill * TAX_RATE;
    double finalBill = totalBill + tax;

    cout << string(65, '=') << endl;
    cout << "Total Before Tax: Rs." << totalBill << endl;
    cout << "Tax (7%): Rs." << tax << endl;
    cout << "------------------------\n";
    cout << "Total After Tax: Rs." << finalBill << endl;
    cout << "========================\n";

    // Generate the HTML bill and open it in the default browser
    string htmlFilename = "bill.html";
    generateHTMLBill(htmlFilename, purchasedItems);
    openHTMLFile(htmlFilename);
}

int main()
{
    Supermarket<Product> supermarket;

    // Adding some products
    supermarket.addProduct(Product("Milk", 15, 20));
    supermarket.addProduct(Product("Bread", 20, 15));
    supermarket.addProduct(PerishableProduct("Yogurt", 25, 10, "2024-11-01"));
    supermarket.addProduct(PerishableProduct("Butter", 40, 5, "2024-12-15"));

    while (true)
    {
        cout << "\n================= Supermarket Menu =================\n";
        cout << "1. Display Products\n";
        cout << "2. Purchase Products\n";
        cout << "3. Delete Product\n";
        cout << "4. Exit\n";
        cout << "Choose an option: ";
        int choice;
        cin >> choice;

        switch (choice)
        {
        case 1:
            supermarket.displayProducts();
            break;

        case 2:
        {
            vector<pair<int, int>> selectedItems;
            char continuePurchase;
            supermarket.displayProducts();

            do
            {
                int item;
                cout << "\nEnter product number (0 to finish): ";
                cin >> item;
                if (item == 0)
                    break;

                int quantity;
                cout << "Enter quantity for " << supermarket.getProductName(item - 1) << ": ";
                cin >> quantity;

                selectedItems.push_back({item, quantity});

                cout << "Do you want to add more products? (y/n): ";
                cin >> continuePurchase;
            } while (continuePurchase == 'y' || continuePurchase == 'Y');

            // Display the bill with a delete option
            while (true)
            {
                cout << "\nCurrent Bill:\n";
                printBill(selectedItems, supermarket);

                char deleteItem;
                cout << "Do you want to delete any item? (y/n): ";
                cin >> deleteItem;
                if (deleteItem == 'n' || deleteItem == 'N')
                {
                    break;
                }

                int itemToDelete;
                cout << "Enter the product number to delete: ";
                cin >> itemToDelete;

                // Find and delete the item from selectedItems
                auto it = find_if(selectedItems.begin(), selectedItems.end(), [&](const pair<int, int> &p)
                                  { return p.first == itemToDelete; });

                if (it != selectedItems.end())
                {
                    selectedItems.erase(it);
                    cout << "Item removed from the bill.\n";
                }
                else
                {
                    cout << "Invalid product number.\n";
                }
            }

            char confirmPurchase;
            cout << "Would you like to confirm your purchase? (y/n): ";
            cin >> confirmPurchase;

            if (confirmPurchase == 'y' || confirmPurchase == 'Y')
            {
                printBill(selectedItems, supermarket);
            }
            else
            {
                cout << "Purchase cancelled.\n";
            }

            break;
        }

        case 3:
        {
            int index;
            cout << "Enter product number to delete: ";
            cin >> index;
            supermarket.deleteProduct(index - 1);
            break;
        }

        case 4:
            cout << "Thank you for visiting our supermarket!\n";
            return 0;

        default:
            cout << "Invalid option. Try again.\n";
        }
    }
}
