#include <iostream>
#include <stack>
#include <queue>

class Solution {
    std::stack<char> my_stack;
    std::queue<char> my_queue;

public:
    void pushCharacter(char ch) {
        my_stack.push(ch);
    }

    void enqueueCharacter(char ch) {
        my_queue.push(ch);
    }

    char popCharacter() {
        char temp = my_stack.top();

        my_stack.pop();

        return temp;
    }

    char dequeueCharacter() {
        char temp = my_queue.front();

        my_queue.pop();

        return temp;
    }
};

int main() {
    Solution obj;

    return 0;
}
