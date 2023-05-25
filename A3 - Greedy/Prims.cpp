#include<bits/stdc++.h>
using namespace std;


void primsMST(vector<vector<int>> &cost, int n){
    vector<int> parent(n, -1);
    vector<int> key(n, INT_MAX);
    vector<bool> vis(n, false);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, 0});
    key[0] = 0;
    while(!pq.empty()){
        int u = pq.top().second;
        pq.pop();
        vis[u] = true;
        for(int v=0;v<n;v++){
            if(cost[u][v] && !vis[v] && cost[u][v]<key[v]){
                key[v] = cost[u][v];
                pq.push({key[v], v});
                parent[v] = u;
            }
        }
    }
    for(int i=1;i<n;i++){
        cout<<parent[i]<<" - "<<i<<endl;
    }

    cout<<"min cost : "<<accumulate(key.begin(), key.end(),0)<<endl;  

}
int main(){
    // vertices 9 ,edges 14
    // (0,1,4)
    // (0,7,8)
    // (7,1,11)
    // (7,8,7)
    // (7,6,1)
    // (1,2,8)
    // (2,3,7)
    // (2,5,4)
    // (2,8,2)
    // (8,6,6)
    // (6,5,2)
    // (5,3,14)
    // (5,4,10)
    // (3,4,9)
     int n, e;
    cin >> n >> e;
    vector<vector<int>> cost(n, vector<int>(n, INT_MAX));
    for (int i = 0; i < e; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        cost[u][v] = w;
        cost[v][u] = w;
    }

    primsMST(cost,n);

    return 0;
}
