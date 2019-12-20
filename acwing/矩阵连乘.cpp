/*
* Author:czj
* Time  :2019/12/19 08:59
* Email :zj_cheng@csu.edu.cn
*/

#include <iostream>
#include <algorithm>
using namespace std;

int N = 4;
int a[] = {3,4,5,6,7};
int dp[N][N];

int dfs(int l, int r){
    if(l==r)
        return 0;
    if(dp[l][r] != 0)
        return dp[l][r];
    for(int i=l; i<r; ++i){
        int tmp = dfs(l,i)+dfs(i+1,r)+a[l-1]*a[i]*a[r];
        dp[l][r] = max(dp[l][r], tmp)
    }
    return dp[l][r];
}
int main() {
    cout<<dfs(1,4);
    return 0;
}


