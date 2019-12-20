/*
* Author:czj
* Time  :2019/12/17 12:21
* Email :zj_cheng@csu.edu.cn
link: https://www.acwing.com/problem/content/11/

有 N 件物品和一个容量是 V 的背包。每件物品只能使用一次。
第 i 件物品的体积是 vi，价值是 wi。
求解将哪些物品装入背包，可使这些物品的总体积不超过背包容量，且总价值最大。
输出 最优选法的方案数。注意答案可能很大，请输出答案模 10^9+7 的结果。
输入格式
第一行两个整数，N，V，用空格隔开，分别表示物品数量和背包容积。
接下来有 N 行，每行两个整数 vi,wi，用空格隔开，分别表示第 i 件物品的体积和价值。
输出格式
输出一个整数，表示 方案数 模 109+7 的结果。
数据范围
0<N,V≤1000
0<vi,wi≤1000
输入样例
4 5
1 2
2 4
3 4
4 6
*/

/**
 * 解题思路： cnt[j] 表示 最大容量空间为 j 的时候，能够达到最大价值的方案数目
 *          f[j]   表示 最大容量空间为 j 的时候，能够达到的最大价值是
 * 1.如果 f[j] > f[j-v]+w  表示在该次变化中，f[j]的最大价值来自于  前面的物品的 价值
 *   这个时候更新 cnt[j] = cnt[j]  即当遇到当前物品的时候，这个东西不将该标
 * 2.如果 f[j] == f[j-v]+w   表示在遇到一个新物品的时候，能够有两种方式使得达到最大价格，这个时候
 *   更新 cnt[j] = cnt[j]+cnt[j-v]  即有多种方法到达最大价值。
 * 3.f[j] < f[j-v]+w   cnt[j]=cnt[j-v]
 *
 * 初始化的时候 cnt[j]均为1
 *
 * 这道题目说实话可能我也不是理解的太清楚，如果有疑问的同学可以交流相互讨论。
 */
#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

const int mod = 1e9 + 7;

int f[1005];
int cnt[1005];
int main() {
    for(int i=0; i<1005; i++){
        cnt[i] = 1;
    }
    int N, V;
    cin>>N>>V;
    for(int i=1; i<=N; i++){
        int v, w;
        cin>>v>>w;
        for(int j=V; j>=v; --j){
            if(f[j] == f[j-v]+w){
                cnt[j] = cnt[j]+cnt[j-v];
            }else{
                cnt[j] = (f[j] > f[j-v]+w) ? cnt[j]:cnt[j-v];
            }
            cnt[j] = cnt[j] % mod;
            f[j] = max(f[j], f[j-v]+w);
        }
    }
    cout<<cnt[V];
    return 0;
}

