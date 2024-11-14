#include <iostream>
#include <vector>
#include <string>
#include <iomanip>   // For std::setw
#include <typeinfo>  // For typeid
#include <algorithm> // For std::find_if

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

    Product operator+(const Product &other)
    {
        if (this->name == other.name)
        {
            return Product(this->name, this->price, this->quantity + other.quantity);
        }
        return *this;
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
        cout << left << setw(5) << "No."
             << setw(25) << "Product"
             << setw(10) << "Price"
             << setw(10) << "Quantity";
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

    // Method to decrement product quantity after purchase
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

// Function to print the bill and decrement product quantities after purchase
template <typename T>
void printBill(const vector<pair<int, int>> &selectedItems, Supermarket<T> &supermarket)
{
    cout << "\n================= FINAL BILL =================\n";
    cout << left << setw(25) << "Product"
         << setw(10) << "Quantity"
         << setw(10) << "Price"
         << setw(10) << "Total" << endl;
    cout << string(65, '=') << endl;

    double totalBill = 0.0;
    for (const auto &item : selectedItems)
    {
        int productIndex = item.first - 1;
        int quantity = item.second;
        double price = supermarket.getProductPrice(productIndex);
        double totalPrice = price * quantity;
        totalBill += totalPrice;

        // Display product details in the bill
        cout << left << setw(25) << supermarket.getProductName(productIndex)
             << setw(10) << quantity
             << setw(10) << price
             << setw(10) << totalPrice << endl;

        // Decrement product quantity after the purchase
        supermarket.decrementProductQuantity(productIndex, quantity);
    }

    // Calculate tax and final bill
    double tax = totalBill * TAX_RATE;
    double finalBill = totalBill + tax;

    cout << string(65, '=') << endl;
    cout << "Total Before Tax: Rs." << totalBill << endl;
    cout << "Tax (7%): Rs." << tax << endl;
    cout << "------------------------\n";
    cout << "Total After Tax: Rs." << finalBill << endl;
    cout << "========================\n";
}

int main()
{
    Supermarket<Product> supermarket;

    // Adding some products
    supermarket.addProduct(Product("Milk", 15, 20));
    supermarket.addProduct(Product("Bread", 20, 15));
    supermarket.addProduct(PerishableProduct("Yogurt", 25, 10, "2024-11-01"));
    supermarket.addProduct(PerishableProduct("Butter", 40, 5, "2024-12-15"));
    supermarket.addProduct(Product("Rice", 60, 50));
    supermarket.addProduct(Product("Sugar", 45, 25));

    while (true)
    {
        cout << "\n================= Supermarket Menu =================\n";
        cout << "1. Display list of Products\n";
        cout << "2. Purchase Products\n";
        cout << "3. Delete Product\n";
        cout << "4. Update Product\n";
        cout << "5. Exit\n";
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

            // Confirm before printing bill
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
        {
            int index, newQuantity;
            double newPrice;
            cout << "Enter product number to update: ";
            cin >> index;
            cout << "Enter new price: ";
            cin >> newPrice;
            cout << "Enter new quantity: ";
            cin >> newQuantity;
            supermarket.updateProduct(index - 1, newPrice, newQuantity);
            break;
        }

        case 5:
            cout << "Thank you for visiting our supermarket!\n";
            return 0;

        default:
            cout << "Invalid option. Try again.\n";
        }
    }
}
