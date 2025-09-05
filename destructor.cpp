#include <iostream>
#include <cstring>
using namespace std;

class Hero {
private:
    int health;

public:
    char* name;
    char level;

    // Default constructor (allocates memory for name)
    Hero() {
        name = new char[100];
        cout << "Default Constructor Invoked ✅" << endl;
    }

    // Parameterized constructors
    Hero(int h) {
        health = h;
    }

    Hero(int h, char lvl) {
        health = h;
        level = lvl;
    }

    // Deep Copy Constructor
    Hero(const Hero& other) {
        char* temp = new char[strlen(other.name) + 1];
        strcpy(temp, other.name);
        name = temp;
        health = other.health;
        level = other.level;
        cout << "Deep Copy Constructor Invoked 📝" << endl;
    }

    // Getters
    int getHealth() { return health; }
    char getLevel() { return level; }

    // Setters
    void setHealth(int h) { health = h; }
    void setLevel(char l) { level = l; }
    void setName(char newName[]) { strcpy(name, newName); }

    // Utility
    void print() {
        cout << "Name: " << name
             << " | Level: " << level
             << " | Health: " << health << endl;
    }

    // Destructor
    ~Hero() {
        cout << "Destructor Released Memory 🗑️" << endl;
        delete[] name;
    }
};

int main() {
    // Static allocation (destructor called automatically)
    Hero h1;
    h1.setHealth(90);
    h1.setLevel('A');
    char n1[] = "Ironman";
    h1.setName(n1);
    h1.print();

    // Dynamic allocation (manual delete required)
    Hero* h2 = new Hero(75, 'B');
    char n2[] = "Batman";
    h2->setName(n2);
    h2->print();

    delete h2;  // explicitly calls destructor

    return 0;
}
