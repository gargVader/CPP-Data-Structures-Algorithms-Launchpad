/*#include<bits/stdc++.h>
int MatrixChainOrder(int p[], int i, int j)
{
    if(i == j)
        return 0;
    int mid=(i+j)/2;

int x=MatrixChainOrder(p,i,mid);
    int y=MatrixChainOrder(p,mid+1,j);
    return min(x,y);
}
int mcm(int* p, int n){

  /* Don't write main().
   *  Don't read input, it is passed as function argument.
   *  Return output and don't print it.
   *  Taking input and printing output is handled automatically.
  */
/*int s=0;
    int e=n;
    return MatrixChainOrder(p,s,e);

}*/


#include<stdio.h>
#include<limits.h>
#include<bits/stdc++.h>
using namespace std;

// Matrix Ai has dimension p[i-1] x p[i] for i = 1..n

int mcm(int* p, int n)
{
    n++;
    int m[n][n];
    int i, j, k, L, q;

    for (i=1; i<n; i++)
        m[i][i] = 0;    //number of multiplications are 0(zero) when there is only one matrix

    //Here L is chain length. It varies from length 2 to length n.
    for (L=2; L<n; L++)
    {
        for (i=1; i<n-L+1; i++)
        {
            j = i+L-1;
            m[i][j] = INT_MAX;  //assigning to maximum value

            for (k=i; k<=j-1; k++)
            {
                q = m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j];
                if (q < m[i][j])
                {
                    m[i][j] = q;    //if number of multiplications found less that number will be updated.
                }
            }
        }
    }

    return m[1][n-1];   //returning the final answer which is M[1][n]

}

int main(){

  int n;
  cin >> n;
  int* p = new int[n];

  for(int i = 0; i <= n; i++){
    cin >> p[i];
  }

  cout << mcm(p, n);

}


