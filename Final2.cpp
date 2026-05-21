#include <iostream>
#include <string>
#include <array>
#include <cstdlib>
#include <ctime>
using namespace std;

const int NUM_NAMES = 50;
const int NUM_ORDERS = 50;

const array<string, NUM_NAMES> NAMES = {
    "Alice", "Bob", "Charlie", "Diana", "Ethan",
    "Fiona", "Grace", "Henry", "Isabella", "Jack",
    "Kaitlyn", "Liam", "Mia", "Noah", "Olivia",
    "Parker", "Quinn", "Ryan", "Sophia", "Thomas",
    "Uma", "Victor", "Wendy", "Xavier", "Yasmine",
    "Zachary", "Ava", "Benjamin", "Chloe", "Daniel",
    "Ella", "Felix", "Gabriel", "Hannah", "Isaac",
    "Julia", "Kevin", "Lily", "Marcus", "Nora",
    "Owen", "Penelope", "Caleb", "Ruby", "Samuel",
    "Tessa", "Ulysses", "Violet", "Wyatt", "Zoe"
};

const array<string, NUM_ORDERS> ORDERS = {
    "Espresso", "Double Espresso", "Americano", "Long Black", "Latte",
    "Iced Latte", "Cappuccino", "Flat White", "Mocha", "White Mocha",
    "Caramel Macchiato", "Vanilla Latte", "Hazelnut Latte", "Pumpkin Spice Latte", "Matcha Latte",
    "Chai Latte", "Dirty Chai", "Hot Chocolate", "White Hot Chocolate", "Iced Coffee",
    "Cold Brew", "Nitro Cold Brew", "French Press Coffee", "Pour Over Coffee", "Drip Coffee",
    "Cortado", "Ristretto", "Affogato", "Macchiato", "Iced Americano",
    "Iced Mocha", "Iced Caramel Latte", "Iced Vanilla Latte", "Iced Matcha Latte", "Iced Chai Latte",
    "Espresso Con Panna", "Red Eye Coffee", "Black Eye Coffee", "Green Tea", "Black Tea",
    "Earl Grey Tea", "English Breakfast Tea", "Herbal Tea", "Mint Tea", "Lemon Tea",
    "Honey Latte", "Oat Milk Latte", "Almond Milk Latte", "Coconut Milk Latte", "Decaf Coffee"
};

struct Node {
    string name;
    string order;
    Node* next;
};

Node* front = nullptr;
Node* back = nullptr;

void enqueue(string name, string order);

void dequeue();

void printQueue();

void customer();

int main() {
    srand(time(0));


    return 0;
}

void enqueue(string name, string order) {
    Node* newNode = new Node{name, order, nullptr};

    if (back == nullptr) {
        front = back = newNode;
    }
    else {
        back->next = newNode;
        back = newNode;
    }

    cout << name << " joined the queue with " << order << endl;
}

void dequeue() {
    if (front == nullptr) {
        cout << "Queue is empty" << endl;
        return;
    }

    Node* tmp = front;
    
    cout << "Serving " << front->name << " with order " << front->order << endl;

    if (front == nullptr) {
        back == nullptr;
    }
    
    delete tmp;
}

void printQueue() {
    if (front == nullptr) {
        cout << "Queue is empty." << endl;
        return;
    } 

    Node* current = front;

    cout << "Queue: " << endl;
    while (current != nullptr) {
        cout << current->name << " " << current->order << endl;
        current = current->next;
    }
}

void customer() {
    int randName = rand() % NUM_NAMES;
    int randOrder = rand() % NUM_ORDERS;

    enqueue(NAMES[randName], ORDERS[randOrder]);
}