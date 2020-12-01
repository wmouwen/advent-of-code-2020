#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

int findPair(const vector<int> &numbers) {
    for (auto first: numbers) {
        for (auto second: numbers) {
            if (first + second == 2020) {
                return first * second;
            }
        }
    }

    throw exception("No valid solution found.");
}

int findTriplet(const vector<int> &numbers) {
    for (auto first: numbers) {
        for (auto second: numbers) {
            for (auto third: numbers) {
                if (first + second + third == 2020) {
                    return first * second * third;
                }
            }
        }
    }

    throw exception("No valid solution found.");
}

int main() {
    vector<int> numbers;

    string line;
    while (getline(cin, line)) {
        if (line.empty()) {
            break;
        }

        numbers.push_back(stoi(line));
    }

    cout << findPair(numbers) << endl;
    cout << findTriplet(numbers) << endl;

    return 0;
}
