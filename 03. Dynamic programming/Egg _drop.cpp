#include<iostream>
#include<vector>
#include<climits>

using namespace std;

int egg(int n, int k)
{

vector<vector<int>> dp(n+1,vector<int>(k+1,0));

for(int j=1;j<=k;j++)
dp[1][j]=j;

for(int i=1;i<=n;i++)
{
    dp[i][1]=1;
}

for(int i=2;i<=n;i++)
for(int j=2;j<=k;j++)
{
dp[i][j]=INT_MAX;

for(int x=1;x<=j;x++)
{
    int res=1+max(dp[i-1][x-1],dp[i][j-x]);
    if(res<dp[i][j])
   dp[i][j]=res;
}


}

for(int i=0;i<=n;i++)
{for(int j=0;j<=k;j++)
{
    cout<<dp[i][j]<<" ";
}
cout<<endl;
}

return dp[n][k];
}

int main()
{
    int n; //no. of eggs
    cin>>n; 
    int k; //no. of floors
    cin>>k;

   cout<<endl;
    cout<<egg(n,k);
}