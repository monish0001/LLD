#include <iostream>
using namespace std;

class Singleton
{
private:
    Singleton()
    {
        cout << "Singleton instance created!" << endl;
    }

public:
    Singleton(const Singleton &) = delete;
    Singleton &operator=(const Singleton &) = delete;

    static Singleton &getInstance()
    {
        static Singleton instance; // Thread-safe in C++11+
        return instance;
    }

    void showMessage()
    {
        cout << "Hello from Singleton!" << endl;
    }
};

int main()
{
    Singleton &s1 = Singleton::getInstance();
    Singleton &s2 = Singleton::getInstance();

    s1.showMessage();

    cout << "s1 and s2 are the same instance? " << (&s1 == &s2 ? "Yes" : "No") << endl;

    return 0;
}
