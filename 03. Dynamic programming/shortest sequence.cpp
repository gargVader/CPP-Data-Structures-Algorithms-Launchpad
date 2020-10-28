


#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int helper(string s, string v, int n, int m, int **dp)
{
    if (n == 0)
	{
		return 1001;
	}
	if (m <= 0)
	{
		return 1;
	}
    if(dp[n][m]>=0)
    {
        return dp[n][m];
    }
    int ans;
    int option1=helper(s.substr(1), v, n-1, m, dp);
	int i = 0;
	for (; i < m; i++)
	{
		if (s[0] == v[i])
		{
			break;
		}
	}
	if (i == m)
	{
		return 1;
	}
    int option2=1 + helper(s.substr(1), v.substr(i+1), n-1, m-i-1, dp);
	ans= min(option1, option2);
    dp[n][m]=ans;
    return ans;
}
int solve(string s, string v)
{
    int n=s.length();
    int m=v.length();
	int **dp=new int* [n+1];
    for(int i=0; i<n+1; i++)
    {
        dp[i]=new int [m+1];
        for(int j=0; j<m+1; j++)
        {
            dp[i][j]=-1;
        }
    }
    return helper(s, v, n, m, dp);
    for(int i=0; i<s.length()+1; i++)
    {
        delete[]dp[i];
    }
    delete[]dp;
}

int main()
{
	string S,V;
	cin>>S>>V;
	cout<<solve(S,V)<<endl;
	return 0;
}
