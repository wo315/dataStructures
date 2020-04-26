#include <iostream>
#include <string>
using std::cout;
using std::cin;
using std::endl;
using std::string;

template<typename Type> class Stack {
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
            delete []elements;
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
            // return top_index < 0; 我觉得这种写法更好。
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

};



int main() {
    int n, m;
    cin >> n >> m;
    Stack<string> stack(n);
    for (int i = 1; i <= m; i++) {
        int opr;
        cin >> opr;
        if (opr == 0) {
            string element;
            cin >> element;
            if (stack.push(element)) {
                cout << "push success!" << endl;
            } else {
                cout << "push failed!" << endl;
            }
        } else if (opr == 1) {
            if (stack.pop()) {
                cout << "pop success!" << endl;
            } else {
                cout << "pop failed!" << endl;
            }
        } else if (opr == 2) {
           	cout << stack.top() << endl; 
        }

    }
    return 0;
}