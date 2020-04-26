#include <iostream>
#include <string>
using std::cout;
using std::cin;
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

};



int main() {
    int n;
    cin >> n;
    Stack<string> stack(n);
    return 0;
}