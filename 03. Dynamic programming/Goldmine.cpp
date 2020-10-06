#include<iostream>
#include<vector>

using namespace std;

int gold(vector<vector<int>> v)
{
vector<vector<int>> dp(v.size(),vector<int>(v[0].size(),0));

for(int i=0;i<v.size();i++)
    dp[i][v[0].size()-1] = v[i][v[0].size()-1];

for (int j = v.size() - 2; j >= 0; j--)
    for (int i = 0; i < v.size(); i++)
    {
         if(i==0)
             dp[i][j] =  max(dp[i + 1][j + 1], dp[i][j + 1]) + v[i][j];

             else if(i==v.size()-1)
                 dp[i][j] = max(dp[i - 1][j + 1], dp[i][j + 1]) + v[i][j];

       else  dp[i][j]=max(dp[i+1][j+1],max(dp[i-1][j+1],dp[i][j+1]))+v[i][j];
    }    


int max=0;
for(int i=0;i<v.size();i++)
if(max<dp[i][0])
max=dp[i][0];


return max;
}


int main()
{
    vector<vector<int>> v{{1, 5, 1, 0, 3},
                          {1, 4, 0, 2, 3},
                          {4, 0, 1, 3, 2},
                          {2, 4, 0, 4, 1},
                          {1, 2, 3, 3, 2}};

    int k = gold(v);
    cout << k;
}