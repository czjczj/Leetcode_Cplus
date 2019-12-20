/*
* Author:czj
* Time  :2019/12/13 19:44
* Email :zj_cheng@csu.edu.cn
*/
#include<algorithm>
#include<iostream>
using namespace std;
/**
 * 解题思路： 对于遍历到的 第 i 个物品，  其 重量 w, 价值 v, 可选个数 s,  假设背包最大可以填充重量为 W
 * 1.  当 W/w <= s, 即这个物品提供的可选择的个数是 大于背包重量忍受范围的， 可以认为 这个物品 是可以选任意件的  这个时候为一个完全背包。
 *      这个时候从 小 到 大 遍历背包的可以忍受重量
 *      for(int j=w; j<=W; j++){
 *          f[j] = max(f[j], f[j-w]+v);
 *      }
 *
 * 2.  否则，分组操作。 当操作到第 i 个物品时候， 这个物品只能选择s个， 其实我们的背包可以忍受超过 s个的物品，  将这s物品表示为 1,2,...,2^n
 *     分组，那么 这个时候  通过组合分组的背包（这个时候每个背包只可以看作 取 或者  不取）， 于是我们能够组合  1-s种任意一种情况
 *     int k=1;
 *     while(k<=s){
 *          s -= k;
 *          for(int j=k*w; j<=W; j++){  这里注意我们相当于对于新的  分组的物品 取或者不取  01背包处理。
 *              f[j] = max(f[j], f[j-k*w]+k*v);
 *          }
 *          k *= 2;
 *     }
 *     for(int j=k*w; j<=W; j++){
*           f[j] = max(f[j], f[j-s*w]+s*v);
*      }
 */
int f[20001];
int main(){
    int N, V;
    cin>>N>>V;
    for(int i=0; i<N; i++){
        int v, w, s;
        cin>>v>>w>>s;
        if(v*s>=V){
            for(int j=v; j<=V; j++){
                f[j] = max(f[j], f[j-v]+w);
            }
        }else{
            int k=1;
            int tmp_n = s;
            while(k <= tmp_n){
                tmp_n -= k;
                for(int j=V; j>=k*v; j--){
                    f[j] = max(f[j], f[j-k*v]+k*w);
                }
                k *= 2;
            }
            for(int j=V; j>=tmp_n*v; j--){
                f[j] = max(f[j], f[j-tmp_n*v]+tmp_n*w);
            }
        }
    }
    cout<<f[V];
    return 0;
}

