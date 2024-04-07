#ifndef ITEM_H
#define ITEM_H

#include <string>

enum Type { NUM,
            VAR,
            ADD,
            SUB,
            MUL,
            DIV };

class Item {
    std::string name;
    int value;
    Type type;

  public:
    Item(const int v = 0) : value{v}, type{NUM} {}
    Item(const std::string &n, const int v) : name{n}, value{v}, type{VAR} {}
    Item(const std::string &s);
    int getValue() const { return value; }
    std::string getName() const { return name; }
    Item arithmetic(const Item &a, const Item &b) const;
    static bool isVariable(const std::string &s);
};

#endif