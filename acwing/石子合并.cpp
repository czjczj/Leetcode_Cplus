/*
* Author:czj
* Time  :2019/12/19 13:05
* Email :zj_cheng@csu.edu.cn
link: https://www.acwing.com/problem/content/description/284/

设有N堆石子排成一排，其编号为1，2，3，…，N。
每堆石子有一定的质量，可以用一个整数来描述，现在要将这N堆石子合并成为一堆。
每次只能合并相邻的两堆，合并的代价为这两堆石子的质量之和，合并后与这两堆石子相邻的石子将和新堆相邻，合并时由于选择的顺序不同，合并的总代价也不相同。
例如有4堆石子分别为 1 3 5 2， 我们可以先合并1、2堆，代价为4，得到4 5 2， 又合并 1，2堆，代价为9，得到9 2 ，再合并得到11，总代价为4+9+11=24；
如果第二步是先合并2，3堆，则代价为7，得到4 7，最后一次合并代价为11，总代价为4+7+11=22。
问题是：找出一种合理的方法，使总的代价最小，输出最小代价。
输入格式
第一行一个数N表示石子的堆数N。
第二行N个数，表示每堆石子的质量(均不超过1000)。
输出格式
输出一个整数，表示最小代价。
数据范围
1≤N≤300
*/
/**
 * 解题思路：  区间dp 经典题目
 * 区间dp:  记住动态规划题目 都是 可以将问题划分为 最优子结构，子结构的问题解合并起来得到了原来问题的解
 *
 * 很显然这道题目就是符合这一题目意思的， 即合并问题从某一个位置划分后，  整个区间划分成为了 一个大区间和
 * 一个小区件， 这就是区间 dp 的由来。 然后根据决策过程进行对应的求解
 *
 * 同样的该题目的描述我们能够很快求解出  “搜索” 的解。 稍微优化一下这个解题过程，我们能够得到递推的求解方式。
 */
#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
using namespace std;

const int INF = INT32_MAX;
int a[301];
int s[301];
int N;
int dp[301][301];
int f[301][301];

/**
 * dp 递推的方式  时间复杂度 O(n^3)
 *
 * 循环 i，j, 对于每一位置我们需要计算其 i...j划分。其中求解方式有前缀和求解  合并 [l,r]的和（即为合并两个子堆的和）
 */
void dp(){
    for(int i=1; i<=N; i++) f[i][i] = 0;
    for(int dis=1; dis<N; dis++){
        for(int i=1, j; (j=i+d)<=N; i++){
            f[i][j] = INF;
            for(int k=i; k<j; k++){
                f[i][j] = min(f[i][j], f[i][k]+f[k+1][j]);
            }
            f[i][j] += (s[j-1]-s[i-1]+a[i-1]);
        }
    }
}
/**
 * dfs 搜索的方式
 */
int dfs(int l, int r){
    if(l == r)
        return 0;
    if(dp[l][r] != 0)
        return dp[l][r];
    int res = 0;
    for(int i=l; i<r; i++){
        int tmp = dfs(l,i) + dfs(i+1, r);
        res = max(res, tmp);
    }
    res += (s[r]-s[l]+a[l]);
    dp[l][r] = res;
    return res;
}
int main() {
    cin>>N;
    for(int i=0; i<N; i++) cin>>a[i];
    partial_sum(a,a+N,s);
    dp();
    cout<<dp[1][N];
    return 0;
}


