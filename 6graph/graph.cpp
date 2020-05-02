#include <iostream>
#include <cstring>
using std::cin;
using std::cout;
using std::endl;

class Graph {
    private:
        int n;
        int **arr;
    public:
        Graph(int input_n) {
            n = input_n;
            arr = new int *[n];
            for (int i = 0; i < n; i++) {
                arr[i] = new int[n];
                memset(arr[i], 0, sizeof(int) * n); // 赋值
            }
        }

        ~Graph() {
            for (int i = 0; i < n; i++) {
                delete[] arr[i];
            }
            delete[] arr;
        }

        void insert(int x, int y){
            arr[x][y] = 1;
        }

        void output() {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n - 1; j++){
                    cout << arr[i][j] << " ";
                }
                cout << arr[i][n - 1] << endl;
            }
        }
};

int main() {
    int n, m;
    cin >> n >> m;
    int x, y, a;
    Graph graph(n);
    for (int i = 0; i < m; i++){
        cin >> a >> x >> y;
        if (a == 0) {
            graph.insert(x, y);
        } else if (a == 1) {
            graph.insert(x, y);
            graph.insert(y, x);
        }   
    }
    graph.output();
    return 0;
}