#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdbool.h>

bool valid_braces(char* str) {
    int size = 0;
    char bracket_stack[strlen(str)+1];

    for (size_t i = 0 ; i < strlen(str) ; ++i) {
        switch (str[i]) {

        case '(': case '{': case '[':
            bracket_stack[size++] = str[i];
            break;

        case ')':
            if (size == 0 || bracket_stack[(size--)-1] != '(')
                return false;
            break;

        case '}':
            if (size == 0 || bracket_stack[(size--)-1] != '{')
                return false;
            break;

        case ']':
            if (size == 0 || bracket_stack[(size--)-1] != '[')
                return false;
            break;
        }
    }

    return size == 0;
}

int main() {
    assert(valid_braces("()"));
    assert(!valid_braces("[(])"));
    assert(valid_braces("(){}[]"));
    assert(!valid_braces("(}"));
    assert(!valid_braces("[(])"));
    assert(valid_braces("([{}])"));
}
