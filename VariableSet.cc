#include "VariableSet.h"

#include <iostream>

VariableSet::VariableSet() {
    std::string name;
    char equal;
    int value;
    while (std::cin >> name >> equal >> value) {
        variables.push_back(Item(name, value));
    }
}

Item VariableSet::find(const std::string &n) const {
    for (auto &variable : variables) {
        if (variable.getName() == n) {
            return Item(variable.getValue());
        }
    }
    exit(-1);
}