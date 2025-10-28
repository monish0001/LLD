#include <bits/stdc++.h>
using namespace std;

// ocp means open for extension closed for modification

// now by OCP we will create separate classes for each storage type

// OCP compliant code with the help of polymorphism(interface) and inheritance
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

class DBpersistence
{
public:
    virtual void storeCartDetails(ShoppingCart *cart) = 0;
};

class SQLDatabse : public DBpersistence
{
public:
    void storeCartDetails(ShoppingCart *cart) override
    {
        cout << "Storing cart details to the SQL database..." << endl;
        // Database storage logic would go here
    }
};

class MongoDB : public DBpersistence
{

public:
    void storeCartDetails(ShoppingCart *cart) override
    {
        cout << "Storing cart details to MongoDB..." << endl;
        // MongoDB storage logic would go here
    }
};

class FileDB : public DBpersistence
{

public:
    void storeCartDetails(ShoppingCart *cart) override
    {
        cout << "Storing cart details to a file..." << endl;
        // File storage logic would go here
    }
};

// class DatabaseDB
// {
// public:
//     void storeCartDetailsToSQL(ShoppingCart *cart)
//     {
//         cout << "Storing cart details to the SQL database..." << endl;
//         // Database storage logic would go here
//     }
//     void storeCartDetailsToMongoDB(ShoppingCart *cart)
//     {
//         cout << "Storing cart details to MongoDB..." << endl;
//         // MongoDB storage logic would go here
//     }
//     void storeCartDetailsToFile(ShoppingCart *cart)
//     {
//         cout << "Storing cart details to a file..." << endl;
//         // File storage logic would go here
//     }
// };

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

    // DBpersistence is abstracting the storage mechanism
    // we can add new storage types without modifying existing code
    // thus following OCP
    DBpersistence *db1 = new SQLDatabse();
    db1->storeCartDetails(&cart);
    DBpersistence *db2 = new MongoDB();
    db2->storeCartDetails(&cart);
    DBpersistence *db3 = new FileDB();
    db3->storeCartDetails(&cart);

    return 0;
}
