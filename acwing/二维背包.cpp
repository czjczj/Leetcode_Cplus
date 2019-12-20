/*
* Author:czj
* Time  :2019/12/15 15:23
* Email :zj_cheng@csu.edu.cn
link: https://www.acwing.com/problem/content/8/

有 N 件物品和一个容量是 V 的背包，背包能承受的最大重量是 M。
每件物品只能用一次。体积是 vi，重量是 mi，价值是 wi。
求解将哪些物品装入背包，可使物品总体积不超过背包容量，总重量不超过背包可承受的最大重量，且价值总和最大。
输出最大价值。
输入格式
第一行两个整数，N，V,M，用空格隔开，分别表示物品件数、背包容积和背包可承受的最大重量。
接下来有 N 行，每行三个整数 vi,mi,wi，用空格隔开，分别表示第 i 件物品的体积、重量和价值。
输出格式
输出一个整数，表示最大价值。

数据范围
0<N≤1000
0<V,M≤100
0<vi,mi≤100
0<wi≤1000

输入样例
4 5 6
1 2 3
2 4 4
3 4 5
4 5 6
*/

/**
 * 解题思路：
 * f[i][j][k]  表示在 前 i个物品中， 在背包体积和重量最大分别为 j,k的情况下， 最大可以获取到的价值。
 *
 * 0-1选择的情况下
 * 动态规划思路：  dp[i][j][k] = max(dp[i-1][j][k], dp[i-1][j-v[i-1]][k- m[i-1]] + w[i-1])
 *
 * 如果有问题请先阅读前面的几个 关于背包问题的  几个题解
 */
#include <iostream>
#include <algorithm>
using namespace std;

int f[101][101];

int main() {
    int N, V, M;
    cin>>N>>V>>M;
    for(int i=1; i<=N; i++){
        int v,m,w;
        cin>>v>>m>>w;
        for(int i=V; i>=v; i--){
            for(int j=M; j>=m; j--){
                f[i][j] = max(f[i][j], f[i-v][j-m]+w);
            }
        }
    }
    cout<<f[N][V];
    return 0;
}


