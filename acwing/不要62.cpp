/*
* Author:czj
* Time  :2019/12/20 22:17
* Email :zj_cheng@csu.edu.cn
*/
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;


int n, m;
int dp[8][10];
int a[8];

int dfs(int pos, int pre, int lead, int limit){
    if(pos < 0) return 1;
    if(dp[pos][pre] != -1 && !lead && !limit) return dp[pos][pre];
    int rtn = 0;
    int res = limit?a[pos]:9;
    for(int i=0; i<=res; i++){
        if(i==4) continue;
        if(i==2 && pre==6) continue;
        rtn += dfs(pos-1, i, i==0&&lead, i==res&&limit);
    }
    if(!lead && !limit) dp[pos][pre] = rtn;
    return rtn;
}

int part(int x){
    int len = 0;
    while(x){
        a[len++] = x%10;
        x  /= 10;
    }
    memset(dp, -1, sizeof(dp));
    return dfs(len-1, -1, 1, 1);
}
int main(){
    cin>>n>>m;
    while(n!=0 || m!=0){
        cout<<part(m)-part(n-1)<<endl;
        cin>>n>>m;
    }
    return 0;
}
