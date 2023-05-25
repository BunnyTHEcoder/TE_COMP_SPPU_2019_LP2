#include <bits/stdc++.h>

using namespace std;
void bfs(const vector<vector<int>>& adj , int start){
   
    int n = adj.size();
    vector<int> order;
    queue<int> q;
    vector<bool> visit(n,false);
    q.push(start);
    
   
    visit[start]=true;
    while(!q.empty()){
        
        int u = q.front();
        order.push_back(u);
        q.pop();
        for(int v : adj[u]){
            if(!visit[v]){
                q.push(v);
                visit[v]=true;
            }
        }
    }
    
    for(int i=0;i<order.size();i++){
        cout<<order[i]<<" ";
    }
    
}

int main()
{
    int n;
    cin>>n;
    vector<vector<int>> adj;
    for(int i=0;i<n;i++){
        int m;
        cin>>m;
        vector<int> arr(m);
        for(int i=0;i<m;i++){
            cin>>arr[i];
        }
        adj.push_back(arr);
    }
    // vector<vector<int>> adj ={
    //     {1, 2},  // vertex 0 has neighbors 1 and 2  
    //     {0, 2,3},// vertex 1 has neighbors 0, 3, and 4  
    //     {0, 1,4},// vertex 2 has neighbors 0 and 4  
    //     {1, 4},  // vertex 3 has neighbors 1 and 4  
    //     {2, 3}
        
    // };
    bfs(adj,2);
    return 0;
    
}