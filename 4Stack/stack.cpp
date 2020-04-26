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
        }

    }
    return 0;
}