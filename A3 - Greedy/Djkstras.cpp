#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
 
typedef pair<int, int> iPair;
 
void addEdge(vector<pair<int, int> > adj[], int u, int v,
             int wt)
{
    adj[u].push_back(make_pair(v, wt));
    adj[v].push_back(make_pair(u, wt));
}

void shortestPath(vector<pair<int, int> > adj[], int V,
                  int src)
{
 
    priority_queue<iPair, vector<iPair>, greater<iPair> >
        pq;
 
   
    vector<int> dist(V, INF);
 
    pq.push(make_pair(0, src));
    dist[src] = 0;

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();
 
      
        for (auto x : adj[u]) {
            int v = x.first;
            int weight = x.second;
 
            if (dist[v] > dist[u] + weight) {
                dist[v] = dist[u] + weight;
                pq.push(make_pair(dist[v], v));
            }
        }
    }
 
    cout<<("Vertex Distance from Source\n");
    for (int i = 0; i < V; ++i)
        printf("%d \t\t %d\n", i, dist[i]);
}
 
int main()
{
    // 6  8
    // 0 1 2
    // 0 2 4
    // 1 2 1
    // 1 3 7
    // 2 4 3 
    // 4 3 2 
    // 4 5 5 
    // 3 5 1 
    
    int vertices,edges ;
    cout<<"enter no. of vertices"<<endl;
    cin>>vertices;
    cout<<"enter no. of edges"<<endl;
    cin>>edges;
    
    vector<iPair> adj[vertices];
    cout << "Enter the edges (source, destination, weight):\n";

    for(int i=0;i<edges;i++){
        int u,v,w;
        cin>> u >> v >> w;
        addEdge(adj, u, v, w);
    }
    cout<<"Enter the source node"<<endl;
    int source;
    cin>>source;
    shortestPath(adj, vertices, source);
 
    return 0;
}