#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main() {
	int t,n;
	cin>>t;
	while(t--)
	{
	    cin>>n;
	    int arr[n];
	    int tab[n];
	    for(int i=0;i<n;i++)
	    {
	        cin>>arr[i];
	        tab[i]=INT_MAX;
	    }
	    tab[0]=0;
	    for(int i=1;i<n;i++)
	    {
	        for(int j=0;j<i;j++)
	        {
                    if(arr[j]!=0&&i<=arr[j]+j)
	            {
	                tab[i]=min(tab[j]+1,tab[i]);   
	            }
	        }
	    }
	    int count=0;
	    if(0<tab[n-1]&&tab[n-1]<=1000)
	    {
	        cout<<tab[n-1];
	    }
	    else
	    {
	        cout<<-1;
	    }
	    cout<<"\n";
	}
	return 0;
}
