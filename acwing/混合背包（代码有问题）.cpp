/*
* Author:czj
* Time  :2019/12/15 14:15
* Email :zj_cheng@csu.edu.cn
有 N 种物品和一个容量是 V 的背包。
物品一共有三类：
第一类物品只能用1次（01背包）；
第二类物品可以用无限次（完全背包）；
第三类物品最多只能用 si 次（多重背包）；
每种体积是 vi，价值是 wi。

求解将哪些物品装入背包，可使物品体积总和不超过背包容量，且价值总和最大。
输出最大价值。

输入格式
第一行两个整数，N，V，用空格隔开，分别表示物品种数和背包容积。

接下来有 N 行，每行三个整数 vi,wi,si，用空格隔开，分别表示第 i 种物品的体积、价值和数量。

si=−1 表示第 i 种物品只能用1次；
si=0 表示第 i 种物品可以用无限次；
si>0 表示第 i 种物品可以使用 si 次；
输出格式
输出一个整数，表示最大价值。

数据范围
0<N,V≤1000
0<vi,wi≤1000
−1≤si≤1000

4 5
1 2 -1
2 4 1
3 4 0
4 5 2

0 0 0 0 0 0
0 2 2 2 2 2
0 2 4 6 6 6
0 2 4 4 6 8
0 2 4 4 5 7
*/

/**
 * 解题思路：
 * 对于每一个新输入 物品，  判断这种物品 01,  无限次，  si次   分别调用三种方法
 */

#include <iostream>
#include <algorithm>
using namespace std;

int f[1001][1001];
int main() {
    int N, V;
    cin>>N>>V;
    for(int i=1; i<=N; i++){
        int v, w, s;
        cin>>v>>w>>s;
        if(s == -1){
            for(int j=v; j<=V; j++){
                f[i][j] = max(f[i-1][j], f[i-1][j-v]+w);
            }
        }else if(s == 0){
            for(int j=0; j<=V; j++){
                if(j >= v)
                    f[i][j] = max(f[i][j], f[i][j-v]+w);
                else
                    f[i][j] = max(f[i][j], f[i-1][j]);
            }
        //多重背包
        }else{
            //判断 v*s > V   判断 s 是否完全足够，如果完全足够，则可以认为是 完全背包
            if(v*s >= V){
                for(int j=0; j<=V; j++) {
                    if(j >= v)
                        f[i][j] = max(f[i][j], f[i][j-v]+w);
                    else
                        f[i][j] = max(f[i][j], f[i-1][j]);
                }
            }else{
                //按照 0-1 分组组装
                int k = 1;
                while(k <= s){
                    s -= k;
                    for(int j=k*v; j<=V; j++){
                        f[i][j] = max(f[i-1][j], f[i-1][j-k*v]+k*w);
                    }
                    k *= 2;
                }
                for(int j=s*v; j<=V; j++){
                    f[i][j] = max(f[i][j], f[i-1][j-s*v]+s*w);
                }
            }
        }
    }
    for(int i=0; i<=N; i++){
        for(int j=0; j<=V; j++){
            cout<<f[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<f[N][V];
    return 0;
}


