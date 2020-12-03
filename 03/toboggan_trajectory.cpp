#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<vector<char>> map;

    string line;

    while (getline(cin, line)) {
        if (line.empty()) {
            break;
        }

        map.emplace_back(line.begin(), line.end());
    }

    ulong trees[30]{};

    ulong paths[5][2] = {
            {1, 1},
            {3, 1},
            {5, 1},
            {7, 1},
            {1, 2},
    };

    for (ulong p = 0; p < 5; p++) {
        for (ulong y = 0; y * paths[p][1] < map.size(); y++) {
            vector<char> row = map.at(y * paths[p][1]);

            ulong x = (paths[p][0] * y) % row.size();

            if (row.at(x) == '#') {
                trees[p]++;
            }
        }
    }

    cout << trees[1] << endl;
    cout << trees[0] * trees[1] * trees[2] * trees[3] * trees[4] << endl;

    return 0;
}
