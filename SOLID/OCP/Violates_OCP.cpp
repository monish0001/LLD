#include <bits/stdc++.h>
using namespace std;

// ocp means open for extension closed for modification

// now new requirement comes that we need to save out data into a file also and mongodb, normalyy waht we will do is modify the existing code to add new functionality

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
    void storeCartDetailsToSQL(ShoppingCart *cart)
    {
        cout << "Storing cart details to the SQL database..." << endl;
        // Database storage logic would go here
    }
    void storeCartDetailsToMongoDB(ShoppingCart *cart)
    {
        cout << "Storing cart details to MongoDB..." << endl;
        // MongoDB storage logic would go here
    }
    void storeCartDetailsToFile(ShoppingCart *cart)
    {
        cout << "Storing cart details to a file..." << endl;
        // File storage logic would go here
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
    db.storeCartDetailsToSQL(&cart);
    db.storeCartDetailsToMongoDB(&cart);
    db.storeCartDetailsToFile(&cart);

    return 0;
}

// but if you see we had to modify the Database class to add new functionality, which violates OCP
// to follow OCP we can create an interface for storage and implement different storage classes for SQL, MongoDB and File
