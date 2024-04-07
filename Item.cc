#include "Item.h"

#include <iostream>
#include <string>

Item::Item(const std::string &s) {
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
Item Item::arithmetic(const Item &a, const Item &b) const {
    switch (type) {
        case ADD:
            return Item(a.getValue() + b.getValue());
        case SUB:
            return Item(a.getValue() - b.getValue());
        case MUL:
            return Item(a.getValue() * b.getValue());
        case DIV:
            return Item(a.getValue() / b.getValue());
        default:
            std::cout << "invalid arithmetic\n";
            exit(-1);
    }
}
bool Item::isVariable(const std::string &s) {
    for (auto i : s) {
        if (!isalpha(i) && i != '_' && i != '$' && !isdigit(i)) {
            return false;
        }
    }
    return !isdigit(s[0]);
}