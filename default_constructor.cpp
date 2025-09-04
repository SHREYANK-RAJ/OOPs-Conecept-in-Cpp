#include <iostream>
using namespace std;

class Hero {
private:
    int health;

public:
    char level;

    // Default constructor
    Hero() {
        cout << "Hero object created!" << endl;
    }

    // Getter functions
    int getHealth() { return health; }
    char getLevel() { return level; }

    // Setter functions
    void setHealth(int h) { health = h; }
    void setLevel(char l) { level = l; }
};

int main() {
    // Static object (stack allocation)
    Hero h1;
    h1.setHealth(80);
    h1.setLevel('A');
    cout << "Static Hero -> Health: " << h1.getHealth()
         << ", Level: " << h1.getLevel() << endl;

    // Dynamic object (heap allocation)
    Hero* h2 = new Hero;
    h2->setHealth(95);
    h2->setLevel('S');
    cout << "Dynamic Hero -> Health: " << h2->getHealth()
         << ", Level: " << h2->getLevel() << endl;

    // Free memory for dynamic object
    delete h2;

    return 0;
}
