/*
* Author:czj
* Time  :2019/12/20 16:08
* Email :zj_cheng@csu.edu.cn
link: https://www.acwing.com/problem/content/description/329/

 农夫约翰的土地由M*N个小方格组成，现在他要在土地里种植玉米。
非常遗憾，部分土地是不育的，无法种植。
而且，相邻的土地不能同时种植玉米，也就是说种植玉米的所有方格之间都不会有公共边缘。
现在给定土地的大小，请你求出共有多少种种植方法。
土地上什么都不种也算一种方法。
输入格式
第1行包含两个整数M和N。
第2..M+1行：每行包含N个整数0或1，用来描述整个土地的状况，1表示该块土地肥沃，0表示该块土地不育。

输出格式
输出总种植方法对100000000取模后的值。

数据范围
1≤M,N≤12
输入样例：
2 3
1 1 1
0 1 0
*/

/** 状态压缩 DP
 * dp[i][j] 表示第 i 行 在 state[j] 这个有效状态下的 玉米填充方案。
 *
 * 则 dp[i][j] = sum(dp[i-1][k]) k=0...N
 */
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int M, N;
int a[14];
int s;
int dp[14][1<<13];
vector<int> state;
int main() {
    cin>>M>>N;
    for(int i=1; i<=M; i++){
        for(int j=1; j<=N; j++){
            cin>>s;
            a[i] |= (s==0)<<(j-1);
        }
    }

    for(int i=0; i<(1<<N); i++){
        if( i&(i<<1) ) continue;
        state.push_back(i);
    }

    for(int i=0; i<state.size(); i++){
        if(state[i] & a[1]) continue;
        dp[1][i] = 1;
    }
    for(int i=2; i<=M+1; i++){
        for(int j=0; j<state.size(); j++){
            if(state[j] & a[i]) continue;
            int sum = 0;
            for(int k=0; k<state.size(); k++){
                if(state[j] & state[k]) continue;
                sum += dp[i-1][k]%100000000;
            }
            dp[i][j] = sum%100000000;
        }
    }
    cout<<dp[M+1][0];
    return 0;
}