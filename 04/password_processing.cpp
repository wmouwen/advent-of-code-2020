#include <iostream>
#include <sstream>
#include <vector>
#include <map>
#include <regex>

using namespace std;
using passport = std::map<string, string>;

bool validPartOne(passport passport) {
    for (string key: {"byr", "iyr", "eyr", "hgt", "hcl", "ecl", "pid"}) {
        if (passport.find(key) == passport.end()) {
            return false;
        }
    }

    return true;
}

bool validPartTwo(passport passport) {
    int byr = stoi(passport.at("byr"));
    if (byr < 1920 || byr > 2002) {
        return false;
    }

    int iyr = stoi(passport.at("iyr"));
    if (iyr < 2010 || iyr > 2020) {
        return false;
    }

    int eyr = stoi(passport.at("eyr"));
    if (eyr < 2020 || eyr > 2030) {
        return false;
    }

    string hgt = passport.at("hgt");
    smatch matches;
    if (regex_match(hgt, matches, regex("^(\\d+)(\\w+)$"))) {
        int actualHeight = stoi(matches[1]);
        if (matches[2] == "in") {
            if (actualHeight < 59 || actualHeight > 76) {
                return false;
            }
        } else if (matches[2] == "cm") {
            if (actualHeight < 150 || actualHeight > 193) {
                return false;
            }
        } else {
            return false;
        }
    } else {
        return false;
    }

    string hcl = passport.at("hcl");
    if (!regex_match(hcl, regex("^#[a-f0-9]{6}$"))) {
        return false;
    }

    vector<string> validColors{"amb", "blu", "brn", "gry", "grn", "hzl", "oth"};
    string ecl = passport.at("ecl");
    if (find(validColors.begin(), validColors.end(), ecl) == validColors.end()) {
        return false;
    }

    string pid = passport.at("pid");
    if (!regex_match(pid, regex("^\\d{9}$"))) {
        return false;
    }

    return true;
}

int main() {
    passport passport;

    int partOne = 0;
    int partTwo = 0;

    string line;
    while (getline(cin, line)) {
        if (line.empty()) {
            if (passport.empty()) {
                break;
            }

            if (validPartOne(passport)) {
                partOne++;

                if (validPartTwo(passport)) {
                    partTwo++;
                }
            }

            // validate
            passport.clear();
            continue;
        }

        stringstream ss(line);
        string property;
        while (ss >> property) {
            passport.emplace(property.substr(0, 3), property.substr(4));
        }
    }

    cout << partOne << endl;
    cout << partTwo << endl;

    return 0;
}
