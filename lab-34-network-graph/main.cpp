// COMSC-210 | Lab 34 | Andrew
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

const int SIZE = 7;

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
        {0,1,12},{0,2,8},{0,3,21},{2,3,6},{2,6,2},{5,6,6},{4,5,9},{2,4,4},{2,5,5}
    };

    Graph graph(edges);
    graph.printGraph();
    graph.DFS(0);
    graph.BFS(0);

    return 0;
}