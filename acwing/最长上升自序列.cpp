/*
* Author:czj
* Time  :2019/12/18 08:40
* Email :zj_cheng@csu.edu.cn
给定一个长度为N的数列，求数值严格单调递增的子序列的长度最长是多少。
输入格式
第一行包含整数N。
第二行包含N个整数，表示完整序列。
输出格式
输出一个整数，表示最大长度。
数据范围
1≤N≤1000，
−109≤数列中的数≤109
输入样例：
7
1, 7, 3, 5, 9, 4, 8
*/

/**
 *                        1, 7, 3, 5, 9, 4, 8
 * 解题思路：
 *
 * 方法1. 先来看看这一题目写    搜索怎么写
 * dfs(idx, length){
 *      for(idx+1...N and a[new_idx]>cur){
 *          dfs(new_idx, length+1)
 *      }
 *      maxlen = max(maxLen, length);
 * }
 * 对于每一位置，记录该位置已经有的Len,  然后从该位置向后遍历， 不断更新后面的位置的 Len.
 * 注意：这里的一个冗余--> 例如 1 2 3 的序列， （idx=1, len=1） 向后for会更新 2,3,  在2的时候，还会向后更新3,  这里需要做一个剪枝操作
 *
 * 方法2. 有了方法1中搜索的基础，我们自然可以想到，是不是需要定义 dp[idx] 记录该位置结束的长度。 因此我们自然的想到了
 * 动态规划的方法。
 * 定义： dp[i] 表示以数组中第 i 个元素为最长上升序列的最后一个元素的时候， 序列的最大长度
 * 则：  dp[i] = max{dp[k]+1 and a[k]<a[i]} k=0...i-1
 * 最终最大值为：  maxLen = max{dp[0...N]}
 *
 *                       1,7, 3, 5, 9, 4, 8
 * 方法3. 然后我们继续看看这个问题可能会出现的冗余， 我们总是希望能够得到最小的元素值不断的向后添加
 * 1,7 --> 1,7,3  那么在后面的元素更新长度为2的时候，其实我们不用比较 7 了。 应为后面的存在着 3 使得这个元素能够更小，也就是向后添加的可能性更大
 *
 * 定义 f[i] 表示最长上升序列的最大长度为 i+1 的时候，最小的末尾元素值
 * 特别的：初始化的时候  f[0] = min{a[0...N]}
 * 那么 显然  f[i] 是一个单调递增的，  即 最大上升长度为大，  其最小的末尾元素也就越大
 *
 * 对于一个新来的元素 a[k], 则可以更加二分查找的方式，更新 f[0...k-1]
 * 1
 * f[0] = 1     f=[1]
 * 7
 * f[1] = 7     f=[1,7]
 * 3
 * f[1] = 3     f=[1,3]
 * 5
 * f[2] = 5     f=[1,3,5]
 * 9
 * f[3] = 9     f=[1,3,5,9]
 * 4
 * f[2] = 4     f=[1,3,4,9]
 * 8
 * f[3] = 8     f=[1,3,4,8]
 *
 * 可以看到对于每一个次， f数组是已经排列好序列的，所以我们可以使用二分查找找到需要插入的位置。最终f的最后一位即为我们需要的结果。
 * 相对于方法2的时间复杂度为O(n^2)  , 该方法的时间复杂度为 O(n log n)
 */



#include <iostream>
#include <algorithm>
using namespace std;
const int INF = INT32_MAX;

int a[1001];
int dp[1001];
int N;
int maxLen = 0;

int f[1001];  //动态规划2使用
////////////////////////////////////动态规划2开始
void dp2(){
    fill(f, f+N, INF);
    int k = 0;
    f[0] = a[k++];
    for(int i = 1; i < N; ++i){
        int tmp = a[i];
        int l = 0;
        int r = k;
        while(l<r){
            int mid = l+(l-r)/2;
            if(tmp <= f[mid])
                r = mid;
            else
                l = mid+1;
        }
        f[l] = tmp;
        maxLen = max(maxLen, l);
        if(l == k)
            k++;
    }
}
////////////////////////////////////动态规划2end


////////////////////////////////////动态规划1开始
void dp1(){
    fill(dp, dp+N, 1);
    for(int i=1; i<N; i++){
        for(int j=0; j<i; ++j){
            if(a[j]<a[i])
                dp[i] = max(dp[j]+1, dp[i]);
        }
    }
    for(int i=0; i<N; i++){
        maxLen = max(maxLen, dp[i]);
    }
}
////////////////////////////////////动态规划1end

////////////////////////////////////暴力搜索开始
void dfs(int idx, int len){
    for(int i=idx+1; i<N; ++i){
        if(a[i]>a[idx] && dp[i]<len+1){
            dfs(i, len+1);
        }
    }
    dp[idx] = len;
    maxLen = max(maxLen, len);
}
void search(){
    for(int i=0; i<N; i++){
        dfs(i,1);
    }
}
////////////////////////////////////暴力搜索end
int main() {
    cin>>N;
    for(int i=0; i<N; i++)  cin>>a[i];
    dp2();
    cout<<maxLen;
    return 0;
}


#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
#include <cstring>
using namespace std;

const int INF = INT32_MAX>>1;
int n;
int a[21][21];
int dp[1<<20][21];
int main(){
    cin>>n;
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++){
            int tmp;
            cin>>tmp;
            a[i][j] = tmp;
            a[j][i] = tmp;
        }

    memset(dp, INF, sizeof(dp));

    dp[1][0] = 0;

    for(int i=0; i< 1<<n; i++){
        for(int j=0; j<n; j++){
            if(i>>j & 1 == 0) continue;
            for(int k=0; k<n; k++){
                if((i^(1<<j))>>k & 1 == 0) continue;
                dp[i][j] = min(dp[i][j], dp[i^(1<<j)][k] + a[k][j]);
            }
        }
    }

    cout<<dp[(1<<n)-1][n-1];
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
int n,f[1<<20][21],i,j,k;
int weight[21][21];
int main()
{
    ios::sync_with_stdio(false);
    memset(f,0x3f,sizeof(f));
    cin>>n;
    for (i=0; i<n; i++)
        for (j=0; j<n; j++)
            cin>>weight[i][j];
    f[1][0]=0;
    for (i=1; i<(1<<n); i++)
        for (j=0; j<n; j++)
            if ((i>>j & 1))
                for (k=0; k<n; k++)
                    if ((i^(1<<j)) >> k & 1)
                        f[i][j]=min(f[i][j],f[i^(1<<j)][k]+weight[k][j]);
    cout<<f[(1<<n)-1][n-1];
    return 0;
    vector<int> a;
    a.push_back(1);
    a.pop_back()
}
