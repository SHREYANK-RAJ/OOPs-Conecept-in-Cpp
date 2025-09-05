#include <iostream>
using namespace std;

class Hero {
private:
    int health;   // Example private data (not used here, but for class completeness)

public:
    char* name;
    char level;

    // Static data member (shared across all objects of the class)
    static int x;

    // Default Constructor
    Hero() {
        cout << "Constructor Called" << endl;
    }

    // Static function (can access only static members)
    static int getStaticValue() {
        cout << "Inside static function" << endl;
        return x;
    }

    // Destructor
    ~Hero() {
        cout << "Destructor Called" << endl;
    }
};

// Initialize static data member outside the class
int Hero::x = 5;

int main() {
    // Accessing static member directly using class name
    cout << "Value of static x (via class): " << Hero::x << endl;

    // Creating an object
    Hero h;

    // Accessing static member using object (not recommended, but valid)
    cout << "Value of static x (via object): " << h.x << endl;

    // Calling static function using class name
    cout << "Static function returned: " << Hero::getStaticValue() << endl;

    return 0;
}
