#include <iostream>
#include <sstream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

enum Type { NUM,
            ADD,
            SUB,
            MUL,
            DIV };

class Item {
    int value;
    Type type;

  public:
    Item(const int v = 0, const Type t = NUM) : value{v}, type{t} {}
    Item(const string &s) {
        if (s == "+") {
            type = ADD;
        } else if (s == "-") {
            type = SUB;
        } else if (s == "*") {
            type = MUL;
        } else if (s == "/") {
            type = DIV;
        } else {
            type = NUM;
            value = stoi(s);
        }
    }
    int getValue() const { return value; }
    Item arithmetic(const Item &x, const Item &b) {
        switch (type) {
            case ADD:
                return Item(x.getValue() + b.getValue());
            case SUB:
                return Item(x.getValue() - b.getValue());
            case MUL:
                return Item(x.getValue() * b.getValue());
            case DIV:
                return Item(x.getValue() / b.getValue());
            default:
                cout << "invalid arithmetic\n";
                exit(-1);
        }
    }
};

class Variable {
    string name;
    int value;

  public:
    Variable(const string n = "", const int v = 0) : name{n}, value{v} {}
    string getName() const { return name; }
    int getValue() const { return value; }
    void setValue(const int v) { value = v; }
    static bool isVariable(const string &s) {
        for (auto i : s) {
            if (!isalpha(i) && i != '_' && i != '$' && !isdigit(i)) {
                return false;
            }
        }
        return !isdigit(s[0]);
    }
};

class VariableSet {
    vector<Variable> variables;

  public:
    VariableSet() {
        string name;
        char equal;
        int value;
        while (cin >> name >> equal >> value) {
            variables.push_back(Variable(name, value));
        }
    }
    Item find(const string n) const {
        for (auto &variable : variables) {
            if (variable.getName() == n) {
                return Item(variable.getValue());
            }
        }
        cout << "variable not found\n";
        exit(-1);
    }
};

class Statements {
    stringstream statements;

  public:
    Statements() {
        string s;
        getline(cin, s);
        statements = stringstream(s);
    }
    void run(VariableSet &v) {
        stack<Item> s;
        string item;
        while (statements >> item) {
            if (item == "(") {
                continue;
            }
            Item o, x, y;
            if (item == ")") {
                y = s.top();
                s.pop();
                x = s.top();
                s.pop();
                o = s.top();
                s.pop();
                s.push(o.arithmetic(x, y));
            } else {
                if (Variable::isVariable(item)) {
                    s.push(v.find(item));
                } else {
                    s.push(Item(item));
                }
            }
        }
        cout << s.top().getValue() << endl;
    }
};

int main() {
    Statements statements;
    VariableSet v;
    statements.run(v);
    return 0;
}
