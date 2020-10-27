#include<bits/stdc++.h>
using namespace std;
int recurknapsack(int n, int maxw, int weights[], int profits[])
{
	if(n==0 || maxw == 0)
		return 0;

	else if(weights[n] > maxw)
	{
		return recurknapsack(n-1, maxw, weights, profits);
	}
	else
	{
		return max( profits[n] + recurknapsack(n-1, maxw- weights[n] , weights, profits), 
			recurknapsack(n-1, maxw, weights, profits));
	}
}

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
// 	cout<<weights[n];
	cout<<recurknapsack(n, maxw, weights, profits)<<endl;
	cout<<dpknapsack(n, maxw, weights, profits);
	return 0;
}
