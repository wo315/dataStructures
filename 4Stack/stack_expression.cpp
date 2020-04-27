#include <iostream>
#include <string>
#include <cassert>

using std::cin;
using std::cout;
using std::endl;
using std::string;

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

bool precede(char a, char b) {
    if (a == '*' && b == '+') {
        return true;
    } else {
        return false;
    }
}

int operate(char theta, int a, int b) {
    if (theta == '+') {
        return a + b;
    } else {
        return a * b;
    }
}

void calc(Stack<int> &numbers, Stack<char> &operators) {
    int a = numbers.top();
    numbers.pop();
    int b = numbers.top();
    numbers.pop();
    numbers.push(operate(operators.top(), a, b));
    operators.pop();
}

int main() {
    int n;
    cin >> n;
    Stack<int> numbers(n);
    Stack<char> operators(n);
    string buffer;
    cin >> buffer;
    int i = 0;

    while (i < n) {
		if (isdigit(buffer[i])) {
            numbers.push(buffer[i] - '0');
            i++;
        } else {
        	if (operators.empty() || precede(buffer[i], operators.top())) {
                operators.push(buffer[i]);
                i++;
            } else {
               	calc(numbers, operators); 
            }   
        } 
    }
    
    while (!operators.empty()) {
        calc(numbers, operators);
    }

    cout << numbers.top() << endl;
    return 0;
}