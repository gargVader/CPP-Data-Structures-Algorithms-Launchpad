#include<bits/stdc++.h>
using namespace std;

/* given a sequence of matrices find the minimum cost of multiplying 
 * all the matrix together and defination of matrix is
 * Ai = arr[i] * arr[i - 1] ... for i 1, 2, 3, 4,... n
 */

/* recursive memorized function */
int mcm_rec(int arr[], int start, int end) {
    // one matrix has 0 cost of multiplication
    if(start >= end)    return 0;
    
    int minimum_cost = INT_MAX;
    /* try all indexes where parathenization is possible */
    for(int k = start; k < end; k++) {
        int temp = mcm_rec(arr, start, k) + mcm_rec(arr, k + 1, end) + arr[start - 1] * arr[k] * arr[end];
        minimum_cost = min(temp, minimum_cost);
    }
    return minimum_cost;
}


/* tabular DP */
int mcm_dp(int arr[], int num_matrix) {
    int n = num_matrix + 1;
    int dp[n][n];
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            dp[i][j] = 0;
        }
    }
    for(int l = 2; l < n; l++) {
        for(int i = 1; i < n - l + 1; i++) {
            int j = l + i - 1; 
            dp[i][j] = INT_MAX;
            /* i and j denote the length of matrix chain */
            for(int k = i; k < j; k++) {
                int temp = dp[i][k] + dp[k + 1][j] + arr[i - 1] * arr[k] * arr[j];
                if(dp[i][j] > temp) {
                    dp[i][j] = temp;
                }
            }
        }
    }
    return dp[1][n - 1];
}

int main(int argc, char const *argv[]) {
    int arr[] = {40, 20, 30, 10, 30};
    int num_matrix = (sizeof(arr) / sizeof(arr[0])) - 1;
    
    cout << mcm_dp(arr, num_matrix) << endl;
    
    return 0;
}
