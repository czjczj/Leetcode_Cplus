#include <iostream>
#include <string>
#include <stack>
#include <vector>
using namespace std;
class Solution {
public:
    int combinationSum4(vector<int>& a, int t) {
        int LEN = 100000;
        int dp[LEN];
        fill(dp,dp+LEN,-1);
        return dfs(a, t, dp);
    }
    int dfs(vector<int>& a, int t, int* dp){
        if(t<0)
            return 0;
        if(t==0)
            return 1;
        if(dp[t] != -1)
            return dp[t];
        int res = 0;
        for(int i=0; i<a.size(); i++){
            res += dfs(a, t-a[i], dp);
        }
        dp[t] = res;
        return res;
    }
    /**
     * 递归改为非递归  一直因为第38行报错，细心点
     */
    int combinationSum(vector<int>& a, int t){
        int dp[t+1];
        fill(dp, dp+t+1, 0);
        dp[0] = 1;
        for(int i=1; i<=t; i++){
            long res = 0;
            for(int k=0; k<a.size(); k++){
                if(i-a[k] >= 0)
                    res += dp[i-a[k]];
            }
            dp[i] = res;
        }
        return dp[t];
    }
};
int main(){
    vector<int> nums = {1,2,3};
    int target = 100;
    Solution s;
    int a = s.dfs2(nums, target);
    cout<<a;
    return 0;
}
