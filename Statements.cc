#include "Statements.h"

#include <iostream>
#include <stack>

Statements::Statements() {
    std::string s;
    getline(std::cin, s);
    statements = std::stringstream(s);
}

void Statements::run(VariableSet &v) {
    std::stack<Item> s;
    std::string item;
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
            if (Item::isVariable(item)) {
                s.push(v.find(item));
            } else {
                s.push(Item(item));
            }
        }
    }
    std::cout << s.top().getValue() << std::endl;
}
