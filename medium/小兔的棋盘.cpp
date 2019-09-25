/*
* Author:czj
* Time  :2019/09/18 08:24
* Email :zj_cheng@csu.edu.cn
小兔的叔叔从外面旅游回来给她带来了一个礼物，小兔高兴地跑回自己的房间，拆开一看是一个棋盘，小兔有所失望。不
 过没过几天发现了棋盘的好玩之处。从起点(0，0)走到终点(n,n)的最短路径数是C(2n,n),现在小兔又想如果不穿越对角线(但可接触对角线上的格点)，
 这样的路径数有多少?小兔想了很长时间都没想出来，现在想请你帮助小兔解决这个问题，对于你来说应该不难吧!
Input
每次输入一个数n(1<=n<=35)，当n等于－1时结束输入。
Output
对于每个输入数据输出路径数，具体格式看Sample。
Sample Input
1
3
12
-1
Sample Output
1 1 2
2 3 10
3 12 416024
*/
#include <iostream>
#include <map>
#include <vector>
#include <queue>
using namespace std;
/**
 *  卡兰特数字，我这里直接使用了 dp 的算法
 */
int dfs(int i, int j, int n, vector<vector<int>>& dp){
    if(i==n && j==n)
        return 1;
    if(j>i || i>n || j>n)
        return 0;
    if(dp[i][j] != 0)
        return dp[i][j];
    int res = 0;
    res += dfs(i+1, j, n,dp);
    res += dfs(i, j+1, n,dp);
    dp[i][j] = res;
    return res;
}

int main() {
    int n = 100;
    vector<vector<int>> dp(n+1,vector<int>(n+1, 0));
    int res = dfs(0,0,n, dp);
    cout<<2*res;
    return 0;
}




