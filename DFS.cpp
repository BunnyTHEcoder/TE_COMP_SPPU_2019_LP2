// Repo star kr phele
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
    dfs(adj,0);
    return 0;
}
