#include <iostream>
using namespace std;

// A simple Hero class
class Hero {
private:
    int health;   // private variable (cannot be accessed directly)

public:
    char level;   // public variable (can be accessed directly)

    // Getter functions
    int getHealth() {
        return health;
    }

    char getLevel() {
        return level;
    }

    // Setter functions
    void setHealth(int h) {
        health = h;
    }

    void setLevel(char l) {
        level = l;
    }
};

int main() {
    // --- Static allocation (object on stack) ---
    Hero h1;
    h1.setHealth(90);
    h1.setLevel('A');

    cout << "H1 health: " << h1.getHealth() << endl;
    cout << "H1 level : " << h1.level << endl;

    // --- Dynamic allocation (object on heap) ---
    Hero* h2 = new Hero;
    h2->setHealth(99);
    h2->setLevel('B');

    // Access using (*h2)
    cout << "H2 health (using *h2): " << (*h2).getHealth() << endl;
    cout << "H2 level  (using *h2): " << (*h2).level << endl;

    // Access using -> (arrow operator)
    cout << "H2 health (using ->): " << h2->getHealth() << endl;
    cout << "H2 level  (using ->): " << h2->level << endl;

    // Free dynamically allocated memory
    delete h2;

    return 0;
}
