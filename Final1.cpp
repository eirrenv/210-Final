#include <iostream>
#include <string>
#include <map>
#include <fstream>
#include <vector>
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

    cout << endl;

    int max;
    max = traffic["ATL"];
    vector<string> busiest;
    for (auto airport : traffic) {
        if (airport.second > max) {
            max = airport.second;
            busiest.clear();
            busiest.push_back(airport.first);
        }
        else if (airport.second == max) {
            busiest.push_back(airport.first);
        }
    }

    cout << "Busiest airport(s) with count " << max << ":" << endl;
    for (string code : busiest) {
        cout << code << " " << max << endl;
    }
    return 0;
}