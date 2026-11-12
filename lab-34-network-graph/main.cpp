// COMSC-210 | Lab 34 | Andrew
#include <iostream>

#include <vector>

#include <queue>

#include <stack>

#include <climits>

#include <algorithm>

using namespace std;

const int SIZE = 9;

struct Edge {
    int src, dest, weight;
};

typedef pair < int, int > Pair;

string nodeNames[9] = {
    "Downtown",
    "North Mall",
    "West Park",
    "South Station",
    "Airport",
    "East Hospital",
    "University",
    "Tech Hub",
    "Industrial Zone"
};

struct DSU {
    vector < int > parent;
    DSU(int n) {
        parent.resize(n);
        for (int i = 0; i < n; i++) parent[i] = i;
    }
    int find(int i) {
        if (parent[i] == i) return i;
        return parent[i] = find(parent[i]);
    }
    void unite(int i, int j) {
        int root_i = find(i);
        int root_j = find(j);
        if (root_i != root_j) parent[root_i] = root_j;
    }
};

class Graph {
    public: vector < vector < Pair >> adjList;

    Graph(vector < Edge >
        const & edges) {
        adjList.resize(SIZE);

        for (auto & edge: edges) {
            adjList[edge.src].push_back(make_pair(edge.dest, edge.weight));
            adjList[edge.dest].push_back(make_pair(edge.src, edge.weight));
        }
    }

    void printGraph() {
        cout << "City Traffic Network Topology:\n";
        cout << "================================\n";
        for (int i = 0; i < adjList.size(); i++) {
            cout << "Intersection " << i << " (" << nodeNames[i] << ") connects to:\n";
            for (Pair v: adjList[i]) {
                cout << "  -> Intersection " << v.first << " (" << nodeNames[v.first] << ") - Travel Time: " << v.second << " mins\n";
            }
        }
    }

    void DFS(int startVertex) {
        vector < bool > visited(SIZE, false);
        stack < int > s;
        s.push(startVertex);

        cout << "DFS starting from vertex " << startVertex << ":" << endl;
        while (!s.empty()) {
            int curr = s.top();
            s.pop();

            if (!visited[curr]) {
                visited[curr] = true;
                cout << nodeNames[curr] << " ";
                // Push neighbors in reverse order to match sample output (visit smaller first)
                for (auto it = adjList[curr].rbegin(); it != adjList[curr].rend(); ++it) {
                    if (!visited[it -> first]) {
                        s.push(it -> first);
                    }
                }
            }
        }
        cout << endl;
    }

    void BFS(int startVertex) {
        vector < bool > visited(SIZE, false);
        queue < int > q;
        visited[startVertex] = true;
        q.push(startVertex);

        cout << "BFS starting from vertex " << startVertex << ":" << endl;
        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            cout << nodeNames[curr] << " ";

            for (Pair v: adjList[curr]) {
                if (!visited[v.first]) {
                    visited[v.first] = true;
                    q.push(v.first);
                }
            }
        }
        cout << endl;
    }

    void shortestPath(int src) {
        vector < int > dist(SIZE, INT_MAX);
        priority_queue < Pair, vector < Pair > , greater < Pair >> pq;
        dist[src] = 0;
        pq.push(make_pair(0, src));

        while (!pq.empty()) {
            int d = pq.top().first;
            int u = pq.top().second;
            pq.pop();

            if (d > dist[u]) continue;

            for (Pair v: adjList[u]) {
                if (dist[u] + v.second < dist[v.first]) {
                    dist[v.first] = dist[u] + v.second;
                    pq.push(make_pair(dist[v.first], v.first));
                }
            }
        }

        cout << "Shortest path from node " << src << ":\n";
        for (int i = 0; i < SIZE; i++) {
            cout << src << " -> " << i << " : " << dist[i] << "\n";
        }
    }

    void findMST() {
        vector < Edge > allEdges;
        for (int i = 0; i < SIZE; i++) {
            for (Pair v: adjList[i]) {
                if (i < v.first) { // avoid duplicates for undirected graph
                    allEdges.push_back({
                        i,
                        v.first,
                        v.second
                    });
                }
            }
        }

        sort(allEdges.begin(), allEdges.end(), [](Edge a, Edge b) {
            return a.weight < b.weight;
        });

        DSU dsu(SIZE);
        cout << "Minimum Spanning Tree edges:\n";
        int totalCost = 0;
        for (Edge e: allEdges) {
            if (dsu.find(e.src) != dsu.find(e.dest)) {
                dsu.unite(e.src, e.dest);
                cout << "Edge from " << e.src << " to " << e.dest << " with capacity: " << e.weight << " units\n";
                totalCost += e.weight;
            }
        }
        cout << "Total cost of Minimum Spanning Tree: " << totalCost << endl;
    }
};

int main() {
    vector < Edge > edges = {
        {
            0,
            1,
            8
        },
        {
            0,
            2,
            21
        },
        {
            1,
            2,
            6
        },
        {
            1,
            3,
            5
        },
        {
            1,
            4,
            4
        },
        {
            2,
            7,
            11
        },
        {
            2,
            8,
            8
        },
        {
            3,
            4,
            9
        },
        {
            5,
            6,
            10
        },
        {
            5,
            7,
            15
        },
        {
            5,
            8,
            5
        },
        {
            6,
            7,
            3
        },
        {
            6,
            8,
            7
        }
    };

    Graph graph(edges);

    int choice;
    do {
        cout << "\nCity Traffic Network Menu:\n";
        cout << "[1] Display City Network\n";
        cout << "[2] Dispatch Area Analysis (BFS)\n";
        cout << "[3] Contamination Trace (DFS)\n";
        cout << "[4] Calculate Shortest Paths\n";
        cout << "[5] Find Minimum Spanning Tree\n";
        cout << "[0] Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            graph.printGraph();
            break;
        case 2:
            graph.BFS(0);
            break;
        case 3:
            graph.DFS(0);
            break;
        case 4:
            graph.shortestPath(0);
            break;
        case 5:
            graph.findMST();
            break;
        case 0:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice.\n";
        }
    } while (choice != 0);

    return 0;
}