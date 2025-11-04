#include <bits/stdc++.h>

using namespace std;

class Burger
{
public:
    virtual void prepare() = 0;
    virtual ~Burger() = default;
};

class BasicBurger : public Burger
{
public:
    void prepare() override
    {
        cout << "Preparing Basic Burger" << endl;
    }
};

class StandardBurger : public Burger
{
public:
    void prepare() override
    {
        cout << "Preparing Standard Burger" << endl;
    }
};
class PremiumBurger : public Burger
{
public:
    void prepare() override
    {
        cout << "Preparing Premium Burger" << endl;
    }
};

class basicWheatBurger : public Burger
{
public:
    void prepare() override
    {
        cout << "Preparing Basic Wheat Burger" << endl;
    }
};
class standardWheatBurger : public Burger
{
public:
    void prepare() override
    {
        cout << "Preparing Standard Wheat Burger" << endl;
    }
};
class premiumWheatBurger : public Burger
{

public:
    void prepare() override
    {
        cout << "Preparing Premium Wheat Burger" << endl;
    }
};

class GarlicBread
{
public:
    virtual void prepare() = 0;
    virtual ~GarlicBread() = default;
};

class BasicGarlicBread : public GarlicBread
{
public:
    void prepare() override
    {
        cout << "Preparing Basic Garlic Bread" << endl;
    }
};
class StandardGarlicBread : public GarlicBread
{
public:
    void prepare() override
    {
        cout << "Preparing Standard Garlic Bread" << endl;
    }
};
class PremiumGarlicBread : public GarlicBread
{
public:
    void prepare() override
    {
        cout << "Preparing Premium Garlic Bread" << endl;
    }
};

class basicWheatGarlicBread : public GarlicBread
{
    void prepare() override
    {
        cout << "Preparing Basic Wheat Garlic Bread" << endl;
    }
};

class standardWheatGarlicBread : public GarlicBread
{
    void prepare() override
    {
        cout << "Preparing Standard Wheat Garlic Bread" << endl;
    }
};
class premiumWheatGarlicBread : public GarlicBread
{
    void prepare() override
    {
        cout << "Preparing Premium Wheat Garlic Bread" << endl;
    }
};

class MealFactory
{
public:
    virtual Burger *createBurger(const std::string &type) = 0;
    virtual GarlicBread *createGarlicBread(const std::string &type) = 0;
    virtual ~MealFactory() = default;
};

class RegularMealFactory : public MealFactory
{
public:
    Burger *createBurger(const std::string &type) override
    {
        if (type == "basic")
        {
            return new BasicBurger();
        }
        else if (type == "standard")
        {
            return new StandardBurger();
        }
        else if (type == "premium")
        {
            return new PremiumBurger();
        }
        return nullptr;
    }

    GarlicBread *createGarlicBread(const std::string &type) override
    {
        if (type == "basic")
        {
            return new BasicGarlicBread();
        }
        else if (type == "standard")
        {
            return new StandardGarlicBread();
        }
        else if (type == "premium")
        {
            return new PremiumGarlicBread();
        }
        return nullptr;
    }
};
class WheatMealFactory : public MealFactory
{
public:
    Burger *createBurger(const std::string &type) override
    {
        if (type == "basic")
        {
            return new basicWheatBurger();
        }
        else if (type == "standard")
        {
            return new standardWheatBurger();
        }
        else if (type == "premium")
        {
            return new premiumWheatBurger();
        }
        return nullptr;
    }

    GarlicBread *createGarlicBread(const std::string &type) override
    {
        if (type == "basic")
        {
            return new basicWheatGarlicBread();
        }
        else if (type == "standard")
        {
            return new standardWheatGarlicBread();
        }
        else if (type == "premium")
        {
            return new premiumWheatGarlicBread();
        }
        return nullptr;
    }
};

int main()
{
    MealFactory *regularFactory = new RegularMealFactory();
    Burger *burger1 = regularFactory->createBurger("standard");
    GarlicBread *bread1 = regularFactory->createGarlicBread("premium");

    if (burger1)
    {
        burger1->prepare();
        delete burger1;
    }
    if (bread1)
    {
        bread1->prepare();
        delete bread1;
    }

    delete regularFactory;

    MealFactory *wheatFactory = new WheatMealFactory();
    Burger *burger2 = wheatFactory->createBurger("premium");
    GarlicBread *bread2 = wheatFactory->createGarlicBread("standard");

    if (burger2)
    {
        burger2->prepare();
        delete burger2;
    }
    if (bread2)
    {
        bread2->prepare();
        delete bread2;
    }
    delete wheatFactory;

    return 0;
}