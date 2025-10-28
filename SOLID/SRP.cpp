#include <iostream>
#include <vector>

using namespace std;

class Product
{
private:
    string name;
    double price;

public:
    Product(const string &name, double price)
        : name(name), price(price)
    {
    }

    string getName() const
    {
        return name;
    }

    double getPrice() const
    {
        return price;
    }
};

class ShoppingCart
{
private:
    vector<Product> products; // Store products in the cart

public:
    // Add a product to the cart
    void addProduct(const Product &product)
    {
        products.push_back(product);
    }

    // Calculate the total price of the cart
    double calculateTotal()
    {
        double total = 0.0;
        for (const auto &product : products)
        {
            total += product.getPrice();
        }
        return total;
    }

    // Print a simple receipt
    void printReceipt()
    {
        cout << "Receipt:" << endl;
        for (const auto &product : products)
        {
            cout << product.getName() << ": $" << product.getPrice() << endl;
        }
        cout << "Total: $" << calculateTotal() << endl;
    }

    // Store the cart details to a database (placeholder function)
    void storeToDB()
    {
        cout << "Storing cart to database..." << endl;
        // Implement database logic here
    }
};

int main()
{
    cout << "Single Responsibility Principle (SRP) states that a class should have only one reason to change." << endl;

    // Creating products
    Product product1("Laptop", 999.99);
    Product product2("Mouse", 29.99);
    Product product3("Keyboard", 49.99);

    // Creating shopping cart and adding products
    ShoppingCart cart;
    cart.addProduct(product1);
    cart.addProduct(product2);
    cart.addProduct(product3);

    // Print receipt
    cart.printReceipt();

    return 0;
}
