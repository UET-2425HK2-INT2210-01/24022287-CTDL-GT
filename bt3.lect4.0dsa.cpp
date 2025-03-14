#include <iostream>
using namespace std;

class Stack {
private:
    char data[1000];
    int top;
public:
    Stack() : top(-1) {}

    void push(char c) {
        if (top < 999) data[++top] = c;
    }

    void pop() {
        if (top >= 0) --top;
    }

    char peek() {
        return (top >= 0) ? data[top] : '\0';
    }

    bool empty() {
        return top == -1;
    }
};

bool isValid(string s) {
    Stack st;
    for (int i = 0; s[i] != '\0'; i++) {
        char c = s[i];
        if (c == '(' || c == '[' || c == '{') {
            st.push(c);
        } else {
            char top = st.peek();
            if ((c == ')' && top == '(') ||
                (c == ']' && top == '[') ||
                (c == '}' && top == '{')) {
                st.pop();
            } else {
                return false;
            }
        }
    }
    return st.empty();
}

int main() {
    string s;
    cin >> s;
    cout << (isValid(s) ? "Valid" : "Invalid") << endl;
    return 0;
}

