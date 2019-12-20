/*
* Author:czj
* Time  :2019/12/16 09:00
* Email :zj_cheng@csu.edu.cn
*/

/**
 * 解题思路： 对于每一个分组里面，我们只能 选择一个物品  取一次， 或者这个分组中的所有物品我们都不取。
 * 对于 01背包， 完全背包， 多重背包来说， 物品之间可以看作是没有相互影响的，但是在这个题目中，其是有相互影响的。
 *
 * 定义状态：  f[i][j] 表示 前i组中，当我们的背包的最大容量为 j的时候， 能够获取的最大价值。
 * 1. 如果f[i][j] = f[i-1][j] 表示当前分组中 不再取任何物品
 * 2. 如果f[i][j] = f[i-1][j-v[k]]+w[k]  其中v[k], w[k] 分别表示对应于 i分组中每一个物品
 *
 * 那么显然  f[i][j] = max(1, 2)
 */
#include <iostream>
#include <algorithm>
using namespace std;

int f[101][101];
int main() {
    int N, V;
    cin>>N>>V;
    for(int i=1; i<=N; i++){
        int S;
        cin>>S;
        for(int s=0; s<S; s++){
            int v, w;
            cin>>v>>w;
            for(int j=0; j<=V; j++){
                if(j >= v)
                    f[i][j] = max(f[i][j], f[i-1][j-v]+w);
                f[i][j] = max(f[i][j], f[i-1][j]);
            }
        }
    }
    cout<<f[N][V];
    return 0;

}