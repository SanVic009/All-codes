#include <iostream>
#include <vector>
#include <string>
#include <iomanip>   // For std::setw
#include <typeinfo>  // For typeid
#include <algorithm> // For std::find_if

using namespace std;

// Base class Product
class Product
{
public:
    string name;
    double price;
    int quantity;

    Product(string n = "", double p = 0.0, int q = 0) : name(n), price(p), quantity(q) {}

    // Virtual function for displaying product information (for polymorphism)
    virtual void display() const
    {
        cout << left << setw(25) << name << setw(10) << price << setw(10) << quantity;
    }

    // Overload the + operator to combine two products' quantities
    Product operator+(const Product &other)
    {
        if (this->name == other.name)
        {
            return Product(this->name, this->price, this->quantity + other.quantity);
        }
        return *this;
    }

    virtual ~Product() {} // Virtual destructor for proper cleanup in derived classes
};

// Derived class for perishable products
class PerishableProduct : public Product
{
public:
    string expirationDate;

    PerishableProduct(string n, double p, int q, string expDate) : Product(n, p, q), expirationDate(expDate) {}

    // Override display function to include expiration date (polymorphism)
    void display() const override
    {
        Product::display(); // Display base class product details
        cout << setw(15) << expirationDate;
    }
};

// Template class for Supermarket
template <typename T>
class Supermarket
{
private:
    vector<T> products; // Vector of products (can be of any type)

public:
    void addProduct(const T &product)
    {
        products.push_back(product);
    }

    void deleteProduct(int index)
    {
        if (index >= 0 && index < static_cast<int>(products.size()))
        { // Cast size() to int to avoid signed/unsigned warning
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
        cout << "\nAvailable Products:\n";
        cout << left << setw(25) << "Product"
             << setw(10) << "Price"
             << setw(10) << "Quantity";
        if (typeid(T) == typeid(PerishableProduct))
        {
            cout << setw(15) << "Expiration Date";
        }
        cout << endl;
        cout << string(65, '-') << endl;
        for (size_t i = 0; i < products.size(); ++i)
        {
            cout << i + 1 << ". ";
            products[i].display(); // Polymorphic call
            cout << endl;
        }
    }

    double calculateBill(const vector<pair<int, int>> &selectedItems)
    {
        double total = 0.0;
        for (const auto &item : selectedItems)
        {
            int productIndex = item.first - 1; // Convert to 0-based index
            int quantity = item.second;
            if (productIndex >= 0 && productIndex < static_cast<int>(products.size()))
            {
                // Check if the product is out of stock
                if (products[productIndex].quantity == 0)
                {
                    cout << "Sorry, " << products[productIndex].name << " is not available in the inventory.\n";
                }
                else if (quantity <= products[productIndex].quantity)
                {
                    total += products[productIndex].price * quantity;

                    // Decrement the quantity in the inventory
                    products[productIndex].quantity -= quantity;
                }
                else
                {
                    cout << "Invalid quantity for " << products[productIndex].name << ". Skipping...\n";
                }
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
        return 0.0; // Return 0.0 for invalid index
    }
};

// Function to print the bill
template <typename T>
void printBill(const vector<pair<int, int>> &selectedItems, Supermarket<T> &supermarket)
{
    cout << "\n----- BILL -----\n";
    cout << left << setw(25) << "Product"
         << setw(10) << "Quantity"
         << setw(10) << "Price"
         << setw(10) << "Total" << endl;
    cout << string(65, '-') << endl;

    double totalBill = 0.0;
    for (const auto &item : selectedItems)
    {
        int productIndex = item.first - 1; // Convert to 0-based index
        int quantity = item.second;
        double price = supermarket.getProductPrice(productIndex);
        double totalPrice = price * quantity;
        totalBill += totalPrice;

        cout << left << setw(25) << supermarket.getProductName(productIndex)
             << setw(10) << quantity
             << setw(10) << price
             << setw(10) << totalPrice << endl;
    }

    cout << string(65, '-') << endl;
    cout << "Total Bill: Rs." << totalBill << endl;
    cout << "------------------------\n";
}

int main()
{
    // Create a supermarket that can store both products and perishable products
    Supermarket<Product> supermarket;

    // Adding some basic products and perishable products
    supermarket.addProduct(Product("Milk", 15, 20));
    supermarket.addProduct(Product("Bread", 20, 15));
    supermarket.addProduct(PerishableProduct("Yogurt", 25, 10, "2024-11-01"));
    supermarket.addProduct(PerishableProduct("Butter", 40, 5, "2024-12-15"));
    supermarket.addProduct(Product("Rice", 60, 50));
    supermarket.addProduct(Product("Rice", 60, 50));
    supermarket.addProduct(Product("Pasta", 35, 40));
    supermarket.addProduct(Product("Sugar", 45, 25));
    supermarket.addProduct(Product("Dairymilk", 15, 20));
    supermarket.addProduct(Product("Lays", 20, 15));
    supermarket.addProduct(Product("Kurkure", 30, 30));
    supermarket.addProduct(Product("Oreo", 40, 10));
    supermarket.addProduct(Product("Hide n seek", 50, 25));
    supermarket.addProduct(Product("Yamyam", 25, 18));
    supermarket.addProduct(Product("Maggi", 120, 10));
    supermarket.addProduct(Product("Parle-g", 60, 50));
    supermarket.addProduct(Product("Paan", 35, 40));
    supermarket.addProduct(Product("Salt", 45, 25));
    supermarket.addProduct(Product("Flour", 40, 50));
    supermarket.addProduct(Product("Toor Dal", 80, 30));
    supermarket.addProduct(Product("Moong Dal", 70, 25));
    supermarket.addProduct(Product("Chana Dal", 60, 20));
    supermarket.addProduct(Product("Urad Dal", 90, 15));
    supermarket.addProduct(Product("Besan (Gram Flour)", 50, 40));
    supermarket.addProduct(Product("Face Cream", 150, 30));
    supermarket.addProduct(Product("Shampoo", 200, 25));
    supermarket.addProduct(Product("Conditioner", 180, 20));
    supermarket.addProduct(Product("Body Lotion", 250, 15));
    supermarket.addProduct(Product("Sunscreen", 300, 10));
    supermarket.addProduct(Product("Toothpaste", 60, 20));
    supermarket.addProduct(Product("Soap", 30, 50));
    supermarket.addProduct(Product("Detergent", 100, 15));
    supermarket.addProduct(Product("Air Freshener", 200, 10));
    supermarket.addProduct(Product("Dishwashing Liquid", 150, 25));
    supermarket.addProduct(Product("Apples", 100, 50)); // Fruits
    supermarket.addProduct(Product("Bananas", 40, 30));
    supermarket.addProduct(Product("Oranges", 60, 40));
    supermarket.addProduct(Product("Tomatoes", 20, 60)); // Vegetables
    supermarket.addProduct(Product("Potatoes", 25, 50));
    supermarket.addProduct(Product("Onions", 30, 45));
    supermarket.addProduct(Product("Lemon", 10, 100));
    supermarket.addProduct(Product("Tea", 100, 20));
    supermarket.addProduct(Product("Coffee", 200, 15));
    supermarket.addProduct(Product("Juice", 60, 30));
    supermarket.addProduct(Product("Soda", 30, 50));
    supermarket.addProduct(Product("Chips", 50, 25));
    supermarket.addProduct(Product("Popcorn", 30, 40));
    supermarket.addProduct(Product("Chocolate Bar", 15, 35));
    supermarket.addProduct(Product("Gum", 5, 50));

    while (true)
    {
        cout << "\nMenu:\n";
        cout << "1. Display list of the Products available\n";
        cout << "2. Purchase Products\n";
        cout << "3. Delete Product\n";
        cout << "4. Update the product list (Add new item to the existing list)\n";
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

            vector<pair<int, int>> selectedItems; // Pair of product index and quantity
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

            // Before printing the bill, ask the user if they want to delete or add any item
            char modifyChoice;
            cout << "Would you like to modify your selection before printing the bill? (y/n): ";
            cin >> modifyChoice;

            if (modifyChoice == 'y' || modifyChoice == 'Y')
            {
                while (true)
                {
                    cout << "\n1. Delete an item\n2. Add more items\n3. Print bill\nChoose an option: ";
                    int modificationOption;
                    cin >> modificationOption;

                    if (modificationOption == 1)
                    {
                        int itemToDelete;
                        cout << "Enter product number to delete from your selection: ";
                        cin >> itemToDelete;

                        auto it = std::find_if(selectedItems.begin(), selectedItems.end(),
                                               [itemToDelete](const pair<int, int> &p)
                                               { return p.first == itemToDelete; });

                        if (it != selectedItems.end())
                        {
                            selectedItems.erase(it);
                            cout << "Item removed from selection.\n";
                        }
                        else
                        {
                            cout << "Item not found in your selection.\n";
                        }
                    }
                    else if (modificationOption == 2)
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
                    }
                    else if (modificationOption == 3)
                    {
                        break; // Break the loop and proceed to billing
                    }
                    else
                    {
                        cout << "Item no available\n";
                    }
                }
            }

            double totalBill = supermarket.calculateBill(selectedItems);
            printBill(selectedItems, supermarket);
            cout << "Thank you for shopping with us!\n";
        }
        break;

        case 3:
        {
            int index;
            supermarket.displayProducts();
            cout << "Enter product number to delete: ";
            cin >> index;
            supermarket.deleteProduct(index - 1);
        }
        break;

        case 4:
        {
            string name;
            double price;
            int quantity;
            char isPerishable;
            string expirationDate;

            cout << "Enter product name: ";
            cin.ignore();
            getline(cin, name);

            cout << "Enter price: ";
            cin >> price;

            cout << "Enter quantity: ";
            cin >> quantity;

            cout << "Is the product perishable? (y/n): ";
            cin >> isPerishable;

            if (isPerishable == 'y' || isPerishable == 'Y')
            {
                cout << "Enter expiration date (YYYY-MM-DD): ";
                cin >> expirationDate;
                supermarket.addProduct(PerishableProduct(name, price, quantity, expirationDate));
            }
            else
            {
                supermarket.addProduct(Product(name, price, quantity));
            }
        }
        break;

        case 5:
            cout << "Thank you for visiting the supermarket!\n";
            return 0;

        default:
            cout << "Invalid option. Please try again.\n";
        }
    }

    return 0;
}
