/*
* Author:czj
* Time:  2019/8/15 09:15
*   给定一个只包含正整数的非空数组。是否可以将这个数组分割成两个子集，使得两个子集的元素和相等。
    注意:
    每个数组中的元素不会超过 100
    数组的大小不会超过 200
    示例 1:
    输入: [1, 5, 11, 5]
    输出: true
    解释: 数组可以分割成 [1, 5, 5] 和 [11].

    示例 2:
    输入: [1, 2, 3, 5]
    输出: false
    解释: 数组不能分割成两个元素和相等的子集.
*/
#include <iostream>
#include <string>
#include <algorithm>
#include <stack>
#include <vector>
#include <cmath>
/**
 * 解题思路：动态规划，找冗余， 直接的dfs超时的原因是
 * 在 sum[idx][sum] 这个状态会遇到很多次
 */
using namespace std;
class Solution {
public:
    bool canPartition(vector<int>& a) {
        int len = a.size();
        int sum = 0;
        for(int i=0; i<len; i++)
            sum += a[i];
        if(sum%2 != 0)
            return false;
        sort(a.begin(), a.end());
        vector<vector<int>> dp(len, vector<int>(sum/2+1, -1));
        return dfs(a, sum/2, len-1, dp);
    }
    bool dfs(vector<int>& a, int sum, int idx, vector<vector<int>>& dp){
        if(sum == 0)
            return true;
        if(sum < 0 || idx < 0)
            return false;
        if(dp[idx][sum] != -1)
            return dp[idx][sum]==1? true: false;
        bool flag = false;
        //加上该 idx 的值
        flag |= dfs(a, sum-a[idx], idx-1, dp);
        flag |= dfs(a, sum, idx-1, dp);
        dp[idx][sum] = flag;
        return flag;
    }
};
int main(){
    Solution s;
    vector<int> a = {1,2,3,4,5,6,7};
    bool b = s.canPartition(a);
    cout<<bool(b)<<endl;
    return 0;
}



