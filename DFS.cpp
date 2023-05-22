#include <bits/stdc++.h>

using namespace std;
void dfs(vector<vector<int>>& adj , int start){
    int n = adj.size();
    vector<int> order;
    stack<int> q;
    vector<bool> visit(n,false);
    q.push(start);
    visit[start]=true;
    
    while(!q.empty()){
        
        int u = q.top();
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
    vector<vector<int>> adj ={
        {3,2,1},  // vertex 0 has neighbors 1 and 2  
        {},// vertex 1 has neighbors 0, 3, and 4  
        {4},// vertex 2 has neighbors 0 and 4  
        {},  // vertex 3 has neighbors 1 and 4  
        {}
        
    };
    dfs(adj,0);
    return 0;
}
