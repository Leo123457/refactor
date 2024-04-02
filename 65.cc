#include <iostream>
#include <sstream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

string find(string s, vector<vector<string>> a) {
    for (vector<string> i : a) {
        if (i[0] == s) {
            return i[1];
        }
    }
}

int main() {
    vector<vector<string>> a;
    string b, v, x, y, o;

    getline(cin, b);
    stringstream ss(b);
    while (cin >> x >> o >> y) {
        a.push_back({x, y});
    }
    stack<string> s;
    string p;
    while (ss >> p) {
        if (p == "(") {
            continue;
        } else if (p == ")") {
            y = s.top();
            s.pop();
            if (y[0] != '-' && (y[0] < '0' || y[0] > '9')) {
                y = find(y, a);
            }
            x = s.top();
            s.pop();
            if (x[0] != '-' && (x[0] < '0' || x[0] > '9')) {
                x = find(x, a);
            }
            v = s.top();
            s.pop();
            if (v == "+") {
                s.push(to_string(stoi(x) + stoi(y)));
            } else if (v == "-") {
                s.push(to_string(stoi(x) - stoi(y)));
            } else if (v == "*") {
                s.push(to_string(stoi(x) * stoi(y)));
            } else if (v == "/") {
                s.push(to_string(stoi(x) / stoi(y)));
            }
        } else {
            s.push(p);
        }
    }
    cout << s.top() << '\n';
    return 0;
}
