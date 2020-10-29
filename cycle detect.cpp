#include <bits/stdc++.h>
using namespace std;
bool dfs(int n,vector<int> &vis,vector<int> adj[],vector<int> &stat)
{
    vis[n]=1;
    stat[n]=0;
    for(int i=0;i<adj[n].size();i++)
    {
        if(!vis[adj[n][i]])
        {
            if(dfs(adj[n][i],vis,adj,stat))
            {
                return true;
            }
        }
        else
        {
            if(stat[adj[n][i]]==0)
            {
                return true;
            }
        }
    }
    stat[n]=1;
    return false;
}
bool isCyclic(int V, vector<int> adj[])
{
    vector<int> vis(V,0);
    vector<int> stat(V,-1);
    for(int i=0;i<V;i++)
    {
        if(!vis[i])
        {
            if(dfs(i,vis,adj,stat))
            {
                return true;
            }
        }
    }
    return false;
}
int main() 
{
	int t;
	cin >> t;
	while(t--)
	{
	    int v, e;
	    cin >> v >> e;
	    vector<int> adj[v];
	    for(int i =0;i<e;i++)
	   {
	        int u, v;
	        cin >> u >> v;
	        adj[u].push_back(v);
	    }
	    cout << isCyclic(v, adj) << endl;
	}
	return 0;
}
