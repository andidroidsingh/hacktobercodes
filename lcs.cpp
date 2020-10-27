#include<stdio.h>
using namespace std;    

int lcs2(string s1, string s2, int n, int m)
{
    int LCS[n+1][m+1];
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=m;j++)
        {
            if(i==0 || j==0)
            {
                LCS[i][j] = 0;
            }
            else if(s1[i-1]==s2[j-1])
            {
                LCS[i][j] = 1 + LCS[i-1][j-1];
                // cout<<s1[i-1]<<" ";
            }
            else
            {
                LCS[i][j] = max(LCS[i-1][j], LCS[i][j-1]);
            }
        }
    }
    int index = LCS[n][m];
    char finalstr[index+1]; 
    finalstr[index] = '\0';

    int i = n, j = m;
    while(i>0 && j>0)
    {
        if(s1[i-1]==s2[-j1])
        {
            finalstr[index - 1] = s1[i-1];
            i--;
            j--;
            index--;
        }
        else if(LCS[i-1][j]> LCS[i][j-1])
            i--;
        else j--;
    }
    cout<<finalstr<<endl;

    return LCS[n][m];
}
int lcs(string s1, string s2, int n, int m)
{
    if(n==0 || m==0)
        return 0;
    if(s1[n]==s2[m])
        return (1 + lcs(s1, s2, n-1, m-1));
    else return max(lcs(s1, s2, n-1, m), lcs(s1, s2, n, m-1));
}

int main()
{
    string s1, s2;
    cin>>s1>>s2;
    int n = s1.length();
    int m = s2.length();
    
    cout<<lcs(s1, s2, n, m);
    cout<<lcs2(s1, s2, n, m);
    return 0;
}

