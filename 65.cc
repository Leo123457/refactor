#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

typedef struct Stack {
    vector<string> a;
} Stack;

void push(Stack *s, string o) {
    s->a.push_back(o);
}

string pop(Stack *s) {
    string o = s->a.back();
    s->a.pop_back();
    return o;
}

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
    Stack *s = new Stack();
    string p;
    while (ss >> p) {
        if (p == "(") {
            continue;
        } else if (p == ")") {
            y = pop(s);
            if (y[0] != '-' && (y[0] < '0' || y[0] > '9')) {
                y = find(y, a);
            }
            x = pop(s);
            if (x[0] != '-' && (x[0] < '0' || x[0] > '9')) {
                x = find(x, a);
            }
            v = pop(s);
            if (v == "+") {
                push(s, to_string(stoi(x) + stoi(y)));
            } else if (v == "-") {
                push(s, to_string(stoi(x) - stoi(y)));
            } else if (v == "*") {
                push(s, to_string(stoi(x) * stoi(y)));
            } else if (v == "/") {
                push(s, to_string(stoi(x) / stoi(y)));
            }
        } else {
            push(s, p);
        }
    }
    cout << pop(s) << '\n';
    delete s;
    return 0;
}
