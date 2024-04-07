#ifndef VARIABLESET_H
#define VARIABLESET_H

#include <vector>

#include "Item.h"

class VariableSet {
    std::vector<Item> variables;

  public:
    VariableSet();
    Item find(const std::string &n) const;
};

#endif