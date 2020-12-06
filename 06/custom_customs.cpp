#include <iostream>
#include <sstream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    unordered_map<char, int> group;

    int anyoneAnsweredYes = 0;
    int everyoneAnsweredYes = 0;
    int personCount = 0;

    string line;
    while (getline(cin, line)) {
        if (line.empty()) {
            if (group.empty()) {
                break;
            }

            anyoneAnsweredYes += group.size();

            for (auto &it: group) {
                if (it.second == personCount) {
                    everyoneAnsweredYes++;
                }
            }

            personCount = 0;
            group.clear();
            continue;
        }

        personCount++;

        for (auto chr: line) {
            int count = 1;

            if (group.find(chr) != group.end()) {
                count += group[chr];
            }

            group[chr] = count;
        }
    }

    cout << anyoneAnsweredYes << endl;
    cout << everyoneAnsweredYes << endl;

    return 0;
}
