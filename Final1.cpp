#include <iostream>
#include <string>
#include <map>
#include <fstream>
using namespace std;

int main() {

    map<string, int> traffic;

    ifstream file("210-final-1-SP26.txt");

    if (!file) {
        cout << "Error opening file." << endl;
        return 1;
    }

    string origin, destination;

    while (file >> origin >> destination) {
        traffic[origin]++;

        traffic[destination]++;
    }

    cout << "All airport traffic counts: " << endl;
    for (auto airport : traffic) {
        cout << airport.first << " " << airport.second << endl;
    }

    file.close();

    return 0;
}