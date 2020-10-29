#include<bits/stdc++.h>
using namespace std;
void dfs2(int k,vector<int> adj[],vector<int> &vis)
{
    vis[k]=1;
    for(int i=0;i<adj[k].size();i++)
    {
        if(!vis[adj[k][i]])
        {
            dfs2(adj[k][i],adj,vis);
        }
    }
}
void dfs(int k,vector<int> adj[],stack<int> &s,vector<int> &vis)
{
    vis[k]=1;
    for(int i=0;i<adj[k].size();i++)
    {
        if(!vis[adj[k][i]])
        {
            dfs(adj[k][i],adj,s,vis);
        }
    }
    s.push(k);
}
int kosaraju(int V, vector<int> adj[])
{
    stack<int> s;
    vector<int> vis(V,0);
    vector<int> adj2[V];
    for(int i=0;i<V;i++)
    {
        if(!vis[i])
        {
            dfs(i,adj,s,vis);
        }
    }
    for(int i=0;i<V;i++)
    {
        for(int j=0;j<adj[i].size();j++)
        {
            adj2[adj[i][j]].push_back(i);
        }
    }
    int count=0;
    for(int i=0;i<V;i++)
    {
        vis[i]=0;
    }
    int k;
    while(!s.empty())
    {
        k=s.top();
        s.pop();
        if(!vis[k])
        {
            dfs2(k,adj2,vis);
            count++;
        }
    }
    return count;
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;
        int m, n;
        vector<int> adj[a];
        for (int i = 0; i < b; i++) {
            cin >> m >> n;
            adj[m].push_back(n);
        }
        cout << kosaraju(a, adj) << endl;
    }
    return 0;
}
