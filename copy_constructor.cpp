#include <iostream>
using namespace std;

class Hero {
private:
    int health;

public:
    char level;

    // Default constructor
    Hero() {
        cout << "Default Constructor Triggered" << endl;
    }

    // Parameterized constructors
    Hero(int h) {
        this->health = h;
    }

    Hero(int h, char l) {
        health = h;
        level = l;
    }

    // Copy constructor
    Hero(const Hero& other) {
        health = other.health;
        level = other.level;
        cout << "Copy Constructor Triggered" << endl;
    }

    // Getters
    int getHealth() { return health; }
    char getLevel() { return level; }

    // Setters
    void setHealth(int h) { health = h; }
    void setLevel(char l) { level = l; }

    // Display function
    void display() {
        cout << "Hero -> Level: " << level 
             << " | Health: " << health << endl;
    }
};

int main() {
    // Static allocation + parameterized constructor
    Hero hero1(100, 'S');
    cout << "Hero1 Details: ";
    hero1.display();

    // Copy constructor
    Hero hero2(hero1);
    cout << "Hero2 (Copied) Details: ";
    hero2.display();

    return 0;
}
