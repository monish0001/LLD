#include <iostream>
#include <string>
using namespace std;
class Burger
{
public:
    virtual void prepare() = 0;
    virtual ~Burger() = default;
};
class VeggieBurger : public Burger
{
public:
    void prepare() override
    {
        // Implementation for preparing a veggie burger
        cout << "Preparing Veggie Burger" << endl;
    }
};
class ChickenBurger : public Burger
{
public:
    void prepare() override
    {
        // Implementation for preparing a chicken burger
        cout << "Preparing Chicken Burger" << endl;
    }
};
class WheatVeggieBurger : public VeggieBurger
{
public:
    void prepare() override
    {
        // Implementation for preparing a wheat veggie burger
        cout << "Preparing Wheat Veggie Burger" << endl;
    }
};
class wheatChickenBurger : public ChickenBurger
{
public:
    void prepare() override
    {
        // Implementation for preparing a wheat chicken burger
        cout << "Preparing Wheat Chicken Burger" << endl;
    }
};
class BurgerFactory
{
public:
    virtual Burger *createBurger(const std::string &type) = 0;
    virtual ~BurgerFactory() = default;
};

class KFCBurgerFactory : public BurgerFactory
{
public:
    Burger *createBurger(const std::string &type) override
    {
        if (type == "veggie")
        {
            return new VeggieBurger();
        }
        else if (type == "chicken")
        {
            return new ChickenBurger();
        }
        else
        {
            return nullptr;
        }
    }
};
class McBurgerFactory : public BurgerFactory
{
public:
    Burger *createBurger(const std::string &type) override
    {
        if (type == "veggie")
        {
            return new WheatVeggieBurger();
        }
        else if (type == "chicken")
        {
            return new wheatChickenBurger();
        }
        else
        {
            return nullptr;
        }
    }
};

int main()
{
    BurgerFactory *kfcFactory = new KFCBurgerFactory();
    Burger *burger1 = kfcFactory->createBurger("veggie");
    if (burger1)
    {
        burger1->prepare();
        delete burger1;
    }
    delete kfcFactory;

    BurgerFactory *mcFactory = new McBurgerFactory();
    Burger *burger2 = mcFactory->createBurger("chicken");
    if (burger2)
    {
        burger2->prepare();
        delete burger2;
    }
    delete mcFactory;

    return 0;
}