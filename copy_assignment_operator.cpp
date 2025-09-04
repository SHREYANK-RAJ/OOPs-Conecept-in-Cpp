#include <iostream>
#include <cstring>
using namespace std;

class Hero {
private:
    int health;

public:
    char* name;
    char level;

    // Default Constructor (allocating memory for name)
    Hero() {
        name = new char[100];
        cout << "Default Constructor Invoked" << endl;
    }

    // Parameterized Constructors
    Hero(int h) {
        health = h;
    }

    Hero(int h, char l) {
        health = h;
        level = l;
    }

    // Deep Copy Constructor
    Hero(const Hero& other) {
        char* newName = new char[strlen(other.name) + 1];
        strcpy(newName, other.name);
        this->name = newName;

        this->health = other.health;
        this->level = other.level;

        cout << "Deep Copy Constructor Invoked" << endl;
    }

    // Getters
    int getHealth() { return health; }
    char getLevel() { return level; }

    // Setters
    void setHealth(int h) { health = h; }
    void setLevel(char l) { level = l; }

    void setName(char newName[]) {
        strcpy(this->name, newName);
    }

    // Print function
    void showDetails() {
        cout << "Name   : " << name << endl;
        cout << "Level  : " << level << endl;
        cout << "Health : " << health << endl;
        cout << endl;
    }
};

int main() {
    Hero hero1;
    hero1.setHealth(90);
    hero1.setLevel('A');
    char nm[10] = "Kishan";
    hero1.setName(nm);

    cout << "---- Hero 1 ----" << endl;
    hero1.showDetails();

    // Using copy constructor
    Hero hero2(hero1);
    cout << "---- Hero 2 (Copied) ----" << endl;
    hero2.showDetails();

    // Modifying hero1 name → won’t affect hero2 due to deep copy
    hero1.name[0] = 'B';
    cout << "---- After Changing Hero1's Name ----" << endl;
    hero1.showDetails();
    hero2.showDetails();

    // Copy assignment operator
    hero1 = hero2;
    cout << "---- Hero1 after Copy Assignment ----" << endl;
    hero1.showDetails();

    return 0;
}
