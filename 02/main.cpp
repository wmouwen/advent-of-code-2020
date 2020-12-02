#include <iostream>
#include <vector>
#include <regex>

using namespace std;

int main() {
    vector<int> numbers;

    string line;
    regex lineRegex("^(\\d+)-(\\d+)\\s(\\w):\\s(\\w+)$");
    smatch matches;

    int partOne = 0;
    int partTwo = 0;

    while (getline(cin, line)) {
        if (line.empty()) {
            break;
        }

        regex_match(line, matches, lineRegex);

        int left = stoi(matches[1]);
        int right = stoi(matches[2]);
        char needle = ((string) matches[3])[0];
        string haystack = matches[4];

        int characterOccurrences = 0;
        for (auto chr: haystack) {
            if (chr == needle) {
                characterOccurrences++;
            }
        }

        if (characterOccurrences >= left && characterOccurrences <= right) {
            partOne++;
        }

        if ((haystack[left - 1] == needle && haystack[right - 1] != needle)
            || (haystack[left - 1] != needle && haystack[right - 1] == needle)) {
            partTwo++;
        }
    }

    cout << partOne << endl;
    cout << partTwo << endl;

    return 0;
}
