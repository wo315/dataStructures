#include <iostream>
using std::cout;
using std::cin;
using std::endl;

class LinkedListNode {
public:
    int vertex;
    LinkedListNode *next;
    LinkedListNode(int vertex_input) {
        vertex = vertex_input;
        next = NULL;
    }
};

class LinkedList {
public:
    LinkedListNode *head;
    
    LinkedList() {
        head = NULL;
    }

    ~LinkedList() {
        while (head != NULL) {
            LinkedListNode *delete_node = head;
            head = head->next;
            delete delete_node;
        }
    }

    void insert(int vertex) {
        LinkedListNode *node = new LinkedListNode(vertex);
        node->next = head;
        head = node;
    }
};

class Graph {
private:
    LinkedList *edges;
    int n;
public:
    Graph(int input_n) {
        n = input_n;
        edges = new LinkedList[n];
    }
    ~Graph() {
        delete[] edges;
    }

    void insert(int x, int y) {
        edges[x].insert(y);
    }

    void output() {
        for (int i = 0; i < n; i++) {
            cout << i << ":";
            for (auto j = edges[i].head; j != NULL; j = j->next) {
                cout << " " << j->vertex;
            }
            cout << endl;
        }
    }
};

int main() {
    
    int n, m, a, x, y;
    cin >> n >> m;
    Graph g(n);
    for (int i = 0; i < m; i++) {
        cin >> a >> x >> y;
        if (a == 1) {
            g.insert(x, y);
            g.insert(y, x);
        } else if ( a == 0) {
            g.insert(x, y);
        }    
    }

    g.output();
    return 0;
}