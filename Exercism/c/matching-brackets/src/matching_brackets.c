#include "matching_brackets.h"
#include <stdio.h>
#include <string.h>

char corresponding_bracket(char bracket);

bool is_paired(const char* input)
{
    int len = strlen(input);
    char stack[len];
    int idx = 0;

    for (int i = 0; i < len; ++i) {
        if (input[i] == '[' || input[i] == '{' || input[i] == '(') {
            stack[idx++] = input[i];
        } else if (input[i] == ']' || input[i] == '}' || input[i] == ')') {
            if (stack[idx - 1] != corresponding_bracket(input[i]))
                return false;
            idx--;
        }
    }

    return idx == 0;
}

char corresponding_bracket(char bracket)
{
    if (bracket == '[')
        return ']';
    if (bracket == ']')
        return '[';
    if (bracket == '(')
        return ')';
    if (bracket == ')')
        return '(';
    if (bracket == '}')
        return '{';
    if (bracket == '{')
        return '}';

    return ' ';
}