#include <bits/stdc++.h>
using namespace std;
int main()
{
    double x[10000],y[10000],f[10000];
    int n;
    double dp[10000]={-1000000000000};
    for(int i=0;i<10000;i++){
        dp[i]=-1000000000000;
    }
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>x[i]>>y[i]>>f[i];
    }
    dp[0] = f[0];
	for (int i =1 ;i<n;i++){
	    for (int j = 0; j <i; j++) {
            double  aa=dp[j] - sqrt((x[j]-x[i])*(x[j]-x[i]) + (y[j]-y[i])*(y[j]-y[i]));
	        dp[i] = max(dp[i],aa);
	    }
	    dp[i] += f[i];
    }
        cout<<fixed<<setprecision(6)<<dp[n-1]<<endl;
    return 0;
}
