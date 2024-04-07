#ifndef STATEMENTS_H
#define STATEMENTS_H

#include <sstream>

#include "VariableSet.h"

class Statements {
    std::stringstream statements;

  public:
    Statements();
    void run(VariableSet &v);
};

#endif