#include <string>
#include <iostream>

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
        cout << "Preparing Veggie Burger" << endl;
    }
};
class ChickenBurger : public Burger
{
public:
    void prepare() override
    {
        cout << "Preparing Chicken Burger" << endl;
    }
};

class BurgerFactory
{
public:
    Burger *createBurger(const std::string &type)
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

int main()
{
    BurgerFactory factory;
    Burger *burger1 = factory.createBurger("veggie");
    if (burger1)
    {
        burger1->prepare();
        delete burger1;
    }
    Burger *burger2 = factory.createBurger("chicken");
    if (burger2)
    {
        burger2->prepare();
        delete burger2;
    }
    return 0;
}