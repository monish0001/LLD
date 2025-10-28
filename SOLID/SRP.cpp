#include <bits/stdc++.h>
using namespace std;

class Product
{
private:
    string name;
    double price;

public:
    Product(const string &name, double price)
    {
        this->name = name;
        this->price = price;
    }
    string getName() { return name; }
    double getPrice() { return price; }
    void setName(const string &name) { this->name = name; }
    void setPrice(double price) { this->price = price; }
    void displayProduct()
    {
        cout << "Product Name: " << name << ", Price: $" << price << endl;
    }
};

class shoppingCart
{
private:
    vector<Product> products;

public:
    void addProduct(Product &product)
    {
        products.push_back(product);
    }

    double calculateTotal()
    {
        double total = 0.0;
        for (auto &product : products)
        {
            total += product.getPrice();
        }
        return total;
    }

    void printInvoice()
    {
        cout << "Invoice:" << endl;
        for (auto &product : products)
        {
            product.displayProduct();
        }
        cout << "Thank you for your purchase!" << endl;
    }

    void storeToDatabase()
    {
        cout << "Storing cart details to the database..." << endl;
        // Database storage logic would go here
    }
    void displayCart()
    {
        cout << "Shopping Cart Contents:" << endl;
        for (auto &product : products)
        {
            product.displayProduct();
        }
    }
};

int main()
{
    Product p1("Laptop", 999.99);
    Product p2("Smartphone", 499.99);

    shoppingCart cart;
    cart.addProduct(p1);
    cart.addProduct(p2);

    cout << "Total Amount: $" << cart.calculateTotal() << endl;

    cart.printInvoice();
    cart.storeToDatabase();
    cart.displayCart();

    return 0;
}

/*
 This code violates the Single Responsibility Principle (SRP).

The ShoppingCart class has multiple responsibilities:
   1. Managing the list of products in the cart.
   2. Handling business logic for calculating the total.
   3. Managing presentation logic by printing the receipt.
   4. Managing persistence by storing data to the database.



 To follow SRP:
   - Separate these concerns into different classes:
       • ShoppingCart → manages products only
       • ReceiptPrinter → handles receipt display
       • CartRepository → handles database storage
*/