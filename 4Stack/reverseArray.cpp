#include <iostream>
#include <string>
#include <cassert>

using std::cin;
using std::cout;

template <typename Type> class Stack {
    private:
        Type *elements;
        int max_size, top_index;
    public:
        Stack(int length_input) {
            elements = new Type[length_input];
            max_size = length_input;
            top_index = -1;
        }

        ~Stack() {
            delete [] elements;
        }

        bool push(const Type& element) {
            if (top_index >= max_size - 1) {
                return false;
            }
            top_index++;
            elements[top_index] = element;
            return true;
        }

        bool pop() {
            if (top_index < 0) {
                return false;
            }
            top_index--;
            return true;
        }
        
        Type top() {
            assert(top_index >= 0);
            return elements[top_index];
        }

        bool empty() {
            return top_index < 0;
        }
};

int main() {
    int n, num;
    cin >> n;
    Stack<int> stack(n);
    for (int i = 1; i <= n; i++) {
        cin >> num;
        stack.push(num);
    }
    
    while (!stack.empty()) {
        cout << stack.top() << " ";
        stack.pop();
    }
    return 0;
}