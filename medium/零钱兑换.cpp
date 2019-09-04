/*
* Author:czj
* Time:  2019/9/3 08:15
*给定不同面额的硬币和一个总金额。写出函数来计算可以凑成总金额的硬币组合数。假设每一种面额的硬币有无限个。 
示例 1:
输入: amount = 5, coins = [1, 2, 5]
输出: 4
解释: 有四种方式可以凑成总金额:
5=5
5=2+2+1
5=2+1+1+1
5=1+1+1+1+1

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/coin-change-2
*/
#include <iostream>
#include <string>
#include <algorithm>
#include <stack>
#include <vector>
#include <cmath>
#include <set>
#include <map>
#include <queue>
using namespace std;
class Solution {
public:
    /**
     * 查看了解答是一个完全背包问题： 其实不太怎么理解
     * 定义  dp[i] 表示在剩余 amout=i 的情况下，能够划分兑换的零钱种类数
     * 那么在每一个循环  for coin in (1 到 n)  不断的按照规则
     *                    dp[i] = dp[i-coin] 的值
     * 代码如下
     */
    int change(int amount, vector<int>& c) {
        if(c.size()==0 && amount==0)
            return 1;
        if(c.size()==0)
            return 0;
        vector<int> dp(amount+1, 0);
        dp[0] = 1;
        for(int i=0; i<c.size(); i++){
            for(int j=c[i]; j<=amount; j++){
                dp[j] += dp[j-c[i]];
            }
        }
        return dp[amount];
    }

    /**
     * 我的方法：  超时了
     */
    int change1(int amount, vector<int>& c) {
        vector<vector<int>> dp(amount+1, vector<int>(c.size()+1, -1));
        return dfs1(amount, c, 0, dp);
    }
    int dfs1(int sum, vector<int>& c, int idx, vector<vector<int>> dp){
        if(sum == 0)
            return 1;
        if(idx == c.size())
            return 0;
        if(dp[sum][idx] != -1)
            return dp[sum][idx];
        int res = 0;
        for(int i=0; i<=(sum/c[idx]); i++){
            res += dfs1(sum-i*c[idx], c, idx+1, dp);
        }
        dp[sum][idx] = res;
        return res;
    }
};
int main(){
    Solution s;
    int amount = 5;
    vector<int> coins = {1, 2, 5};
    cout<<s.change(amount,coins);
    return 0;
}


