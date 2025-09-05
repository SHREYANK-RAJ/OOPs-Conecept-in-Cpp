#include <iostream>
#include <cstring>   // for strlen, strcpy
using namespace std;

class Hero {
private:
    int health;

public:
    char* name;
    char level;

    // Default Constructor
    Hero() {
        name = new char[100];   // allocate memory for name
        cout << "Default Constructor Called" << endl;
    }

    // Parameterized Constructors
    Hero(int health) {
        this->health = health;
    }

    Hero(int health, char level) {
        this->health = health;
        this->level = level;
    }

    // Deep Copy Constructor
    Hero(const Hero& temp) {
        // Allocate new memory so we don’t just copy pointer
        char* ch = new char[strlen(temp.name) + 1];
        strcpy(ch, temp.name);
        this->name = ch;

        this->health = temp.health;
        this->level = temp.level;

        cout << "Deep Copy Constructor Called" << endl;
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

    void setName(char name[]) {
        strcpy(this->name, name);
    }

    // Print function
    void print() {
        cout << "Name   : " << this->name << endl;
        cout << "Level  : " << this->level << endl;
        cout << "Health : " << this->health << endl;
        cout << "---------------------------" << endl;
    }

    // Destructor (to free allocated memory)
    ~Hero() {
        delete[] name;
        cout << "Destructor Called" << endl;
    }
};

int main() {
    // Create first Hero
    Hero hero1;
    hero1.setHealth(90);
    hero1.setLevel('A');
    char name[7] = "Kishan";
    hero1.setName(name);

    cout << "Original Hero1:" << endl;
    hero1.print();

    // Copy hero1 into hero2 using Deep Copy Constructor
    Hero hero2(hero1);

    cout << "Copied Hero2 (Deep Copy):" << endl;
    hero2.print();

    // Modify hero1's name → Should NOT affect hero2
    hero1.name[0] = 'B';

    cout << "After modifying hero1’s name:" << endl;
    hero1.print();

    cout << "Hero2 remains unchanged (proof of deep copy):" << endl;
    hero2.print();

    return 0;
}
