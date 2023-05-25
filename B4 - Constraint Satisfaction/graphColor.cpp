#include <iostream>
#include <vector>

using namespace std;

bool isSafe(vector<vector<int>>& graph, vector<int>& colors, int vertex, int color) {
    for (int i = 0; i < graph.size(); i++) {
        if (graph[vertex][i] == 1 && colors[i] == color) {
            return false;
        }
    }

    return true;
}

bool solveGraphColoring(vector<vector<int>>& graph, int m, vector<int>& colors, int vertex) {
    if (vertex == graph.size()) {
        return true;
    }

    for (int color = 1; color <= m; color++) {
        if (isSafe(graph, colors, vertex, color)) {
            colors[vertex] = color;
            if (solveGraphColoring(graph, m, colors, vertex+1)) {
                return true;
            }

            colors[vertex] = 0;
        }
    }
    return false;
}

int main() {
    // 4 
    // 3 
    // 0 1 0 1
    // 1 0 1 1
    // 0 1 0 1
    // 1 1 0 0
    int n, m;
    cout << "Enter the number of vertices: ";
    cin >> n;

    cout << "Enter the number of colors: ";
    cin >> m;

    vector<vector<int>> graph(n, vector<int>(n, 0));
    cout << "Enter the adjacency matrix:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> graph[i][j];
        }
    }

    vector<int> colors(n, 0);

    if (solveGraphColoring(graph, m, colors, 0)) {
        cout << "Solution: ";
        for (int i = 0; i < n; i++) {
            cout << colors[i] << " ";
        }
        cout << endl;
    } else {
        cout << "No solution found!" << endl;
    }

    return 0;
}