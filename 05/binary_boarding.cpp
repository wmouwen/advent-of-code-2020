#include <iostream>
#include <sstream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    priority_queue<int> seats;

    string line;
    while (getline(cin, line)) {
        if (line.empty()) {
            break;
        }

        int row{0};
        int column{0};

        for (int i = 0; i < 7; i++) {
            if (line[i] == 'B') {
                row += pow(2, 6 - i);
            }
        }

        for (int i = 0; i < 3; i++) {
            if (line[7 + i] == 'R') {
                column += pow(2, 2 - i);
            }
        }

        int seat{8 * row + column};
        seats.push(seat);
    }

    int previous = seats.top();
    seats.pop();

    cout << previous << endl;

    while (!seats.empty()) {
        int current = seats.top();
        seats.pop();

        if (previous - current != 1) {
            cout << current + 1 << endl;
            break;
        }

        previous = current;
    }

    return 0;
}
