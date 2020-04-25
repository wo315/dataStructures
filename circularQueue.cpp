#include <iostream>
using std::cout;
using std::cin;
using std::endl;

template <typename Type> class Queue {
    private:
        Type *data;
        int head, tail, length, count;
    public:
        Queue(int input_size) {
            length = input_size;
            data = new Type[length];
            head = 0;
            tail = -1;
            count = 0;
        }
        ~Queue() {
            delete []data;
        }

        bool push(Type element) {
            if (tail + 1 >= length) {
                return false;
            }
            tail++;
            data[tail] = element;
            return true;
        }
        void output() {
            for (int i = head; i < tail; i++)
            {
                cout << data[i] << " ";
            }
            cout << data[tail] << endl;
        }
};

int main() {
    return 0;
}