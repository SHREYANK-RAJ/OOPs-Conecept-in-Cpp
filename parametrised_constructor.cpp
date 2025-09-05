#include <iostream>
using namespace std;

class Hero {
private:
    int health;   // private member

public:
    char level;   // public member

    // Default Constructor
    Hero() {
        cout << "Default Constructor Called" << endl;
    }

    // Parameterized Constructor (only health)
    Hero(int health) {
        this->health = health;
    }

    // Parameterized Constructor (health + level)
    Hero(int health, char level) {
        this->health = health;
        this->level = level;
    }

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

    // Print function
    void print() {
        cout << "Level : " << level << endl;
        cout << "Health: " << health << endl;
        cout << "-----------------" << endl;
    }
};

int main() {
    // --- Static Allocation ---
    Hero h1(10);      // calls constructor with health only
    h1.print();

    // --- Dynamic Allocation ---
    Hero* h2 = new Hero(32);     // health constructor
    h2->print();

    Hero* h3 = new Hero(25, 'A');  // health + level constructor
    h3->print();

    // Free dynamically allocated
