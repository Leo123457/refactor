# Refactor

## Introduction

This is the code I wrote for the problem "Expression Tree" on Judgegirl.
Here is the [link to the question](https://judgegirl.csie.org/problem/0/65),
and I also save the problem description in `65.md` for easier access.
I'll gradually refactor the code using the techniques taught in class (CSIE1211).

## Solution Idea

I can use a stack to store the prefix expression and evaluate it when needed.
Luckily, the given expressions have parenthesis, making them easy to parse.
I can read the expression from left to right and if I see a `(`,
I can just ignore it. If I see a `)`, I know I can take out three items
(two operands and one operator) to evaluate then push the result to stack.
Otherwise, simply push the item to the stack. In the end, the only remaining
item in the stack is the answer.

## Structure

There are three classes, `Item`, `VariableSet`, and `Statements`.

`Item` is for the item stored in the stack, whether it be an integer, operator,
or variable. I also implement arithmetic in it, since I think it's like
an operator takes two operands to operate.

`VariableSet` is for storing the name and value of the variables, and
a method to find them.

`Statements` is for storing and running the expression. Since the input is
separated by spaces, I use `stringstream` to separate them.

## Testing

To check whether my code is correct, I wrote a shell script to download
test data and another script to compare the output of my code with the answer.
I can run `./get 65` to download test data for this problem and `./test`
to test the code.
