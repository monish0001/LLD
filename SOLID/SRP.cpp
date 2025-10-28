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

class ShoppingCart
{
private:
    vector<Product> products;

public:
    void addProduct(Product &product)
    {
        products.push_back(product);
    }

    vector<Product> getProducts()
    {
        return products;
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
};

class Invoice
{
private:
    ShoppingCart *cart;

public:
    Invoice(ShoppingCart *cart)
    {
        this->cart = cart;
    }
    void printInvoice()
    {
        cout << "Invoice:" << endl;
        for (auto &product : cart->getProducts())
        {
            product.displayProduct();
        }
        cout << "Thank you for your purchase!" << endl;
    }
};

class Database
{
public:
    void storeCartDetails(ShoppingCart *cart)
    {
        cout << "Storing cart details to the database..." << endl;
        // Database storage logic would go here
    }
};

int main()
{
    ShoppingCart cart;
    Product p1("Laptop", 999.99);
    Product p2("Smartphone", 499.99);

    cart.addProduct(p1);
    cart.addProduct(p2);

    cout << "Total Amount: $" << cart.calculateTotal() << endl;

    Invoice invoice(&cart);
    invoice.printInvoice();
    Database db;
    db.storeCartDetails(&cart);

    return 0;
}

/*
 This code follows the Single Responsibility Principle (SRP).

Each class has only one reason to change:
   - Product: Handles product data (name and price).
   - ShoppingCart: Manages cart operations such as adding products and calculating total.
   - Invoice: Responsible for printing the invoice.
   - Database: Handles storing cart details to the database.

By separating these responsibilities, changes in one area (like modifying how invoices are printed
or how data is stored) do not affect other parts of the system. This makes the code more maintainable,
modular, and easier to extend.
*/

SRP ka mtlb yr nhi hota ki 1 class 1 hi function hona chahiye, balki iska matlab hai ki ek class ka ek hi responsibility hona chahiye.Jaise ki upar wale code me ShoppingCart class sirf cart ke products ko manage kar rahi hai aur total calculate kar rahi hai, jabki Invoice class sirf invoice print karne ki zimmedari le rahi hai aur Database class sirf data store karne ki zimmedari le rahi hai.Is tarah se har class ka ek hi reason hota hai change hone ka, jo ki SRP ka main matlb hai.
