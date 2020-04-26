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
            // 如果是队列，用尾巴。不是队列用count
            if (count >= length) {
                return false;
            }
            tail = (tail + 1) % length;
            // tail++;这里要用tail + 1与length取模操作判断位置了。
            data[tail] = element;
            count++;
            return true;
        }
        void output() {
            int i = head;
            do
            {
                cout << data[i] << " ";
                i = (i + 1) % length;
            } while (i != (tail + 1) % length);
            
            cout << endl;
        }
        
        Type front() {
            return data[head];
        }

        void pop() {
            head = (head + 1) % length;
            count--;
        }

        bool empty() {
            return count == 0;
        }
};

int main() {
    Queue<int> queue(100);
    for (int i = 1; i <= 10; i++) {
        queue.push(i);
    }
    queue.output();
    queue.pop();
    queue.output();
    return 0;
}