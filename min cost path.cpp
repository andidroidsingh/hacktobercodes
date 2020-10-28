#include<bits/stdc++.h>
using namespace std;
int dij(vector<vector<int>> &arr,vector<vector<int>> &vis,int n,int l,int m)
{
    priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
    vector<vector<int>> dist(n,vector<int> (n,INT_MAX));
    pq.push(make_pair(arr[l][m],make_pair(l,m)));
    dist[l][m]=arr[l][m];
    while(!pq.empty())
    {
        int x,y;
        x=pq.top().second.first;
        y=pq.top().second.second;
        pq.pop();
        if(isvalid(x+1,y,n,vis)&&dist[x+1][y]>dist[x][y]+arr[x+1][y])
        {
            dist[x+1][y]=arr[x+1][y]+dist[x][y];
            pq.push(make_pair(dist[x+1][y],make_pair(x+1,y)));
        }
        if(isvalid(x-1,y,n,vis)&&dist[x-1][y]>dist[x][y]+arr[x-1][y])
        {
            dist[x-1][y]=arr[x-1][y]+dist[x][y];
            pq.push(make_pair(dist[x-1][y],make_pair(x-1,y)));
        }
        if(isvalid(x,y+1,n,vis)&&dist[x][y+1]>dist[x][y]+arr[x][y+1])
        {
            dist[x][y+1]=arr[x][y+1]+dist[x][y];
            pq.push(make_pair(dist[x][y+1],make_pair(x,y+1)));
        }
        if(isvalid(x,y-1,n,vis)&&dist[x][y-1]>dist[x][y]+arr[x][y-1])
        {
            dist[x][y-1]=arr[x][y-1]+dist[x][y];
            pq.push(make_pair(dist[x][y-1],make_pair(x,y-1)));
        }
    }
    return dist[n][n];
}
int main() 
{
	int t,n,a;
	cin>>t;
	while(t--)
	{
	    cin>>n;
	    vector<vector<int>> arr(n);
	    vector<vector<int>> vis(n,vector<int> (n,0));
	    for(int i=0;i<n;i++)
	    {
	        for(int j=0;j<n;j++)
	        {
	            cin>>a;
	            arr[i].push_back(a);
	        }
	    }
	    int sum;
	    sum=dij(arr,vis,n,0,0);
	    cout<<sum<<"\n";
	}
	return 0;
}
