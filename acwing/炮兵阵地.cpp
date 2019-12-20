/*
* Author:czj
* Time  :2019/12/20 13:59
* Email :zj_cheng@csu.edu.cn

link: https://www.acwing.com/problem/content/294/
司令部的将军们打算在N*M的网格地图上部署他们的炮兵部队。一个N*M的地图由N行M列组成，地图的每一格可能是山地（用”H” 表示），也可能是平原（用”P”表示），如下图。
在每一格平原地形上最多可以布置一支炮兵部队（山地上不能够部署炮兵部队）；一支炮兵部队在地图上的攻击范围如图中黑色区域所示：
图上其它白色网格均攻击不到。
从图上可见炮兵的攻击范围不受地形的影响。
现在，将军们规划如何部署炮兵部队，在防止误伤的前提下（保证任何两支炮兵部队之间不能互相攻击，即任何一支炮兵部队都不在其他支炮兵部队的攻击范围内），在整个地图区域内最多能够摆放多少我军的炮兵部队。
输入格式
第一行包含两个由空格分割开的正整数，分别表示N和M；
接下来的N行，每一行含有连续的M个字符(‘P’或者’H’)，中间没有空格。按顺序表示地图中每一行的数据。
输出格式
仅一行，包含一个整数K，表示最多能摆放的炮兵部队的数量。
数据范围
N≤100,M≤10
*/
/**
 * 状态压缩：
 * 1. 明确状态有哪些 t. 在不考虑山坡的情况下，那么对于地图上的每一位置我们 可以  填充炮兵 或者 不填充，也就是对于每一个放个 0 or 1
 * 假设我们将一行看作一个状态集合， 那么这个集合可以 用一个 10进制数字表示  例如  1101 --> 9 (1,2,4位置填充炮兵)
 * 对于一个 有M列的 行状态，  其状态就可能有  2^M (即 1<<M) 个
 * 根据题目  (x,y)位置有炮兵，那么 (x, y +/- 1)  (x, y +/- 2)都不能有炮兵， 故行状态在初始化的时候就要缩小。
 *
 * 2. 定义状态 dp[i][j][k] 表示第 i 行状态为 j,  第 i-1 行状态为 k的时候， 炮兵个数
 * dp[i][j][k] = max(dp[i][j][k], dp[i-1][k][l] + cal(j))   l=0...状态个数
 *
 * 可以看出 在确定了 给出了 前两行的状态的情况下， 就可以不断向后地推后面的状态是多少。
 * 遍历最后两行可能出现的状态可能性，给出最后的结果。
 */
#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
int t;
int m[105];
int dp[105][105][105];
int state[1<<15];



//统计x 中有多少炮兵
int cal(int x){
    int res = 0;
    while(x){
        if(x&1)
            res++;
        x>>1;
    }
    return res;
}
void init(){
    for(int i=0; i<(1<<M); i++){
        if( (i&(i<<2)) || (i&(i<<1)) ) continue;
        state[++t] = i;
    }
    //初始化第一行
    for(int i=1; i<=t; i++){
        if(state[i] & m[1]) continue;
        dp[1][i][1] = cal(state[i]);
    }
}

int main() {
    cin>>N>>M;
    string s;
    for(int i=1; i<=N; i++){
        cin>>s;
        for(int j=1; j<=M; j++) {
            m[i] |= ((s[j-1] == 'H') << (j-1));
        }
    }

    //初始化所有状态为 -1;
    memset(dp, -1, sizeof(dp));
    init();

    for(int i=2; i<=N; i++){
        for(int j=1; j<=t; ++j){
            if(m[i] & state[j]) continue;  //如果当前行选择的状态 j 与 本行可能存在的山峰冲突
            for(int k=1; k<=t; ++k){
                if(state[k] & state[j]) continue;  //如果当前 行 选择的状态 与  上一行选择的状态冲突
                for(int l=1; l<=t; ++l){
                    if(i==2 && l>1) continue;       //避免初始化的第一行进行多次无用计算
                    if(state[j] & state[l]) continue;  //如果选择的倒数 i-2行 选择的状态与  当前行选择的状态冲突
                    dp[i][j][k] = max(dp[i][j][k], dp[i-1][k][l]+cal(state[j]));
                }
            }
        }
    }

    //最后的最大值就要枚举最后两行可能是什么状态决定
    ans = 0;
    for(int i=1; i<=t; ++i){
        for(int j=1; j<=t; ++j){
            ans = max(ans, dp[N][i][j]);
        }
    }
    cout<<ans;
    return 0;
}


