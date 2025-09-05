#include <iostream>
using namespace std;

// A simple class to represent a Hero
class Hero {
private:
    int health;   // private data (can only be accessed using getters/setters)

public:
    char level;   // public data (can be accessed directly)

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
    // Static object (stored on stack)
    Hero h1;

    // Dynamic object (stored on heap)
    Hero* h2 = new Hero;

    // At this point, health has garbage value (not initialized yet)
    cout << "Initial health of h1: " << h1.getHealth() << endl;

    // Setting health properly using setter
    h1.setHealth(90);
    cout << "Updated health of h1: " << h1.getHealth() << endl;

    // Level is public, so we can set it directly
    h1.level = 'A';
    cout << "Level of h1: " << h1.level << endl;

    // Clean up dynamic object
    delete h2;

    return 0;
}
