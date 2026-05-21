#include <iostream>
#include <string>
#include <array>
#include <cstdlib>
#include <ctime>
#include <deque>
#include <vector>
using namespace std;

const int NUM_NAMES = 50;
const int NUM_ORDERS = 50;

const int ROUNDS = 10;

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

const array<string, 50> MUFFINS = {
    "Blueberry Muffin", "Chocolate Chip Muffin", "Banana Nut Muffin", "Double Chocolate Muffin", "Bran Muffin",
    "Cranberry Orange Muffin", "Lemon Poppy Seed Muffin", "Pumpkin Spice Muffin", "Apple Cinnamon Muffin", "Strawberry Muffin",
    "Raspberry Muffin", "Blackberry Muffin", "Mixed Berry Muffin", "Coffee Cake Muffin", "Vanilla Bean Muffin",
    "Almond Muffin", "Peach Muffin", "Carrot Muffin", "Zucchini Muffin", "Maple Walnut Muffin",
    "Cherry Muffin", "Chocolate Banana Muffin", "Oatmeal Muffin", "Honey Muffin", "Coconut Muffin",
    "Lemon Blueberry Muffin", "Orange Cranberry Muffin", "White Chocolate Raspberry Muffin", "Mocha Muffin", "Salted Caramel Muffin",
    "Nutella Muffin", "Peanut Butter Muffin", "S'mores Muffin", "Toffee Muffin", "Espresso Muffin",
    "Pumpkin Chocolate Chip Muffin", "Strawberry Banana Muffin", "Mixed Nut Muffin", "Honey Oat Muffin", "Brown Sugar Muffin",
    "Dark Chocolate Muffin", "Gluten-Free Blueberry Muffin", "Vegan Banana Muffin", "Vegan Chocolate Muffin", "Low Sugar Muffin",
    "High Protein Muffin", "Pumpkin Cheesecake Muffin", "Blueberry Cheesecake Muffin", "Lemon Cheesecake Muffin", "Birthday Cake Muffin"
};

const array<string, 50> BRACELETS = {
    "Blue Friendship Bracelet", "Red Beaded Bracelet", "Rainbow Thread Bracelet", "Gold Charm Bracelet", "Silver Chain Bracelet",
    "Heart Pattern Bracelet", "Star Bead Bracelet", "Wave Pattern Bracelet", "Sunshine Bracelet", "Moonlight Bracelet",
    "Ocean Blue Bracelet", "Forest Green Bracelet", "Sunset Gradient Bracelet", "Pastel Mix Bracelet", "Neon Glow Bracelet",
    "Black & White Bracelet", "Floral Pattern Bracelet", "Spiral Design Bracelet", "Peace Sign Bracelet", "Infinity Knot Bracelet",
    "Boho Style Bracelet", "Minimalist String Bracelet", "Crystal Bead Bracelet", "Lucky Charm Bracelet", "Sport Wristband",
    "Leather Wrap Bracelet", "Braided Rope Bracelet", "Custom Name Bracelet", "Friendship Knot Bracelet", "Festival Beaded Bracelet",
    "Beach Shell Bracelet", "Galaxy Theme Bracelet", "Candy Color Bracelet", "Glow-in-the-Dark Bracelet", "Vintage Beaded Bracelet",
    "Pride Color Bracelet", "Emoji Bead Bracelet", "Animal Charm Bracelet", "Happiness Charm Bracelet", "Love Knot Bracelet",
    "Adventure Bracelet", "Travel Memory Bracelet", "Story Bead Bracelet", "Celebration Bracelet", "DIY Craft Bracelet",
    "Lucky Red String Bracelet", "Mixed Bead Charm Bracelet", "Soft Pastel Bracelet", "Bold Pattern Bracelet", "Classic Thread Bracelet"
};

struct Node {
    string name;
    string order;
    Node* next;
};

Node* front = nullptr;
Node* back = nullptr;

void coffeeEnqueue(string name, string order);

void coffeeDequeue();

deque<pair<string, string>> muffinQueue;

void muffinEnqueue(string name, string order);

void muffinDequeue();

vector<pair<string, string>> braceletQueue;

void braceletEnqueue(string name, string order);

void braceletDequeue();

void printQueue();

void customer();

int main() {
    srand(time(0));

    int random; 

    for (int i = 0; i < 3; ++i) {
        customer();
    }

    int round = 1;
    for (int i = 0; i < ROUNDS; ++i) {
        cout << "Round " << round << ":" << endl << endl;

        random = rand() % 10;

        if (front != nullptr) {
            coffeeDequeue();
        }
        else {
            cout << "Coffee queue is empty." << endl;
        }

        if (!muffinQueue.empty()) {
            muffinDequeue();
        }
        else {
            cout << "Muffin queue is empty." << endl;
        }

        if (!braceletQueue.empty()) {
            braceletDequeue();
        }
        else {
            cout << "Bracelet queue is empty." << endl;
        }

        if (random < 5) {   
            customer();  
        }
        round++;
        cout << endl;
    }

    return 0;
}

void coffeeEnqueue(string name, string order) {
    Node* newNode = new Node{name, order, nullptr};

    if (back == nullptr) {
        front = back = newNode;
    }
    else {
        back->next = newNode;
        back = newNode;
    }

    cout << name << " joined coffee queue with order: " << order << endl;
}

void coffeeDequeue() {
    if (front == nullptr) {
        cout << "Queue is empty" << endl;
        return;
    }

    Node* tmp = front;
    
    cout << "Serving " << front->name << " with order " << front->order << endl;

    front = front->next;

    if (front == nullptr) {
        back == nullptr;
    }
    
    delete tmp;
}

void muffinEnqueue(string name, string order) {
    muffinQueue.push_back({name, order});
    cout << name << " Joined muffin queue with order: " << order << endl;
}

void muffinDequeue() {
    if (muffinQueue.empty()) {
        return;
    }

    auto customer = muffinQueue.front();
    muffinQueue.pop_front();

    cout << "Serving " << customer.first << " with order " << customer.second << endl;
}

void braceletEnqueue(string name, string order) {
    braceletQueue.push_back({name, order});
    cout << name << " Joined bracelet queue with order: " << order << endl;
}

void braceletDequeue() {
    if (braceletQueue.empty()) {
        return;
    }

    auto customer = braceletQueue.front();
    braceletQueue.erase(braceletQueue.begin());

    cout << "Serving" << customer.first << " with order" << customer.second << endl;
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

    coffeeEnqueue(NAMES[randName], ORDERS[randOrder]);

    randName = rand() % NUM_NAMES;
    randOrder = rand() % NUM_ORDERS;

    muffinEnqueue(NAMES[randName], MUFFINS[randOrder]);

    randName = rand() % NUM_NAMES;
    randOrder = rand() % NUM_ORDERS;

    braceletEnqueue(NAMES[randName], BRACELETS[randOrder]);
}