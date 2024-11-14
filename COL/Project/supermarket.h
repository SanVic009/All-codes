#ifndef SUPERMARKET_H
#define SUPERMARKET_H

#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <typeinfo>
#include <algorithm>

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

    virtual void display() const;

    Product operator+(const Product &other);

    virtual ~Product() {}
};

// Derived class for perishable products
class PerishableProduct : public Product
{
public:
    string expirationDate;

    PerishableProduct(string n, double p, int q, string expDate) : Product(n, p, q), expirationDate(expDate) {}

    void display() const override;
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

        // Display total inventory value
        double totalInventoryValue = 0.0;
        for (const auto &product : products)
        {
            totalInventoryValue += product.price * product.quantity;
        }
        cout << "Total Inventory Value: Rs." << totalInventoryValue << endl;
    }

    double calculateBill(const vector<pair<int, int>> &selectedItems) const
    {
        double total = 0.0;
        for (const auto &item : selectedItems)
        {
            int productIndex = item.first - 1;
            int quantity = item.second;

            if (productIndex >= 0 && productIndex < static_cast<int>(products.size()) && quantity <= products[productIndex].quantity)
            {
                total += products[productIndex].price * quantity;
            }
            else
            {
                cout << "Invalid quantity for " << products[productIndex].name << ". Skipping...\n";
            }
        }
        return total;
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

    void updateProduct(int index, double newPrice, int newQuantity)
    {
        if (index >= 0 && index < static_cast<int>(products.size()))
        {
            products[index].price = newPrice;
            products[index].quantity = newQuantity;
            cout << "Product updated successfully.\n";
        }
        else
        {
            cout << "Invalid product index. Unable to update.\n";
        }
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

#endif // SUPERMARKET_H
