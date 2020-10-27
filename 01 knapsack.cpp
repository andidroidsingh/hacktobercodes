#include<bits/stdc++.h>
using namespace std;


int dpknapsack(int n, int maxw, int weights[], int profits[])
{
	int dparr[n+1][maxw+1];

	for(int i=0;i<n;i++)
	{
		for(int j=0;j<maxw;j++)
		{
			if(i==0 || j==0)
				dparr[i][j] = 0;
			else if(weights[i] > j)
			{
				dparr[i][j] = min( profits[i] +  dparr[i][j - weights[i]] ,
					dparr[i][j]);
			}
			else dparr[i][j] = dparr[i][j];
		}
	}
	return dparr[n][maxw];
}
int main()
{
	int n, maxw;
	cin>>n>>maxw;
	int weights[n], profits[n];

	for(int i=0;i<n;i++)
	{
		cin>>weights[i];
	}
	for(int i=0;i<n;i++)
	{
		cin>>profits[i];
	}
	cout<<weights[n+50];
	cout<<dpknapsack(n, maxw, weights, profits);
	return 0;
}