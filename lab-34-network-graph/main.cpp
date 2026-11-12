// COMSC-210 | Lab 34 | Andrew
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

const int SIZE = 9;

struct Edge {
    int src, dest, weight;
};

typedef pair<int, int> Pair;

class Graph {
    public:
        vector<vector<Pair>> adjList;

        Graph(vector<Edge> const &edges) {
            adjList.resize(SIZE);

            for (auto &edge : edges) {
                adjList[edge.src].push_back(make_pair(edge.dest, edge.weight));
                adjList[edge.dest].push_back(make_pair(edge.src, edge.weight));
            }
        }

        void printGraph() {
            cout << "Graph adjacency list:" << endl;
            for (int i = 0; i < adjList.size(); i++) {
                cout << i << " --> ";
                for (Pair v : adjList[i]) {
                    cout << "(" << v.first << ", " << v.second << ") ";
                }
                cout << endl;
            }
        }

        void DFS(int startVertex) {
        vector<bool> visited(SIZE, false);
        stack<int> s;
        s.push(startVertex);

        cout << "DFS starting from vertex " << startVertex << ":" << endl;
        while (!s.empty()) {
            int curr = s.top();
            s.pop();

            if (!visited[curr]) {
                visited[curr] = true;
                cout << curr << " ";
                // Push neighbors in reverse order to match sample output (visit smaller first)
                for (auto it = adjList[curr].rbegin(); it != adjList[curr].rend(); ++it) {
                    if (!visited[it->first]) {
                        s.push(it->first);
                    }
                }
            }
        }
        cout << endl;
    }

    void BFS(int startVertex) {
        vector<bool> visited(SIZE, false);
        queue<int> q;
        visited[startVertex] = true;
        q.push(startVertex);

        cout << "BFS starting from vertex " << startVertex << ":" << endl;
        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            cout << curr << " ";

            for (Pair v : adjList[curr]) {
                if (!visited[v.first]) {
                    visited[v.first] = true;
                    q.push(v.first);
                }
            }
        }
        cout << endl;
    }
};

int main() {
    vector<Edge> edges = {
        {0,1,8},{0,2,21},{1,2,6},{1,3,5},{1,4,4},
        {2,7,11},{2,8,8},{3,4,9},{5,6,10},{5,7,15},
        {5,8,5},{6,7,3},{6,8,7}
    };

    Graph graph(edges);
    graph.printGraph();
    graph.DFS(0);
    graph.BFS(0);

    return 0;
}