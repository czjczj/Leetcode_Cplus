/*
* Author:czj
* Time:  2019/8/31 08:28
*给定一个整数数组 nums ，你可以对它进行一些操作。
每次操作中，选择任意一个 nums[i] ，删除它并获得 nums[i] 的点数。之后，你
 必须删除每个等于 nums[i] - 1 或 nums[i] + 1 的元素。
开始你拥有 0 个点数。返回你能通过这些操作获得的最大点数。
示例 1:
输入: nums = [3, 4, 2]
输出: 6
解释:
删除 4 来获得 4 个点数，因此 3 也被删除。
之后，删除 2 来获得 2 个点数。总共获得 6 个点数。
来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/delete-and-earn
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
     * 这个问题的转换思路：  转化为 有序数组下你是否该取这个苏子
     * 使用数据结构 pair 点数有序存储  则
     * 例如   2  4 5 6 8 9 10
     *        1  1 1 1 1 1  1
     *  那么毫无疑问  2这个点一定要取，因为别人对他都没有影响
     *  但是 对于4  这个点我么需要判断   1.  取4的情况下，  后面5就不可以取
     *                                2.  不取4，       后面的5可以取
     *   问题转化为  v[i+1]-v[i]>1 ?  如果是  v[i]的数值和直接加入到sum中
     *              否则    dfs  判断取4  与  不取4 状态下的结果最后dfs 的结果。
     */
    int deleteAndEarn(vector<int>& a) {
        map<int, int> m;
        for(auto i:a){
            m[i]++;
        }
        vector<pair<int, int>> v;
        for(auto a=m.begin(); a!=m.end(); a++){
            v.push_back(make_pair(a->first, a->second));

        }
        int dp[v.size()];
        fill(dp,dp+v.size(),-1);
        return dfs(v, 0, dp);
    }
    int dfs(vector<pair<int, int>>& v, int idx, int* dp){
        if(idx >= v.size())
            return 0;
        if(idx == v.size()-1)
            return (v[idx].first)*(v[idx].second);
        if(dp[idx] != -1)
            return dp[idx];
        int res = 0;
        if(idx+1<v.size() && v[idx].first+1<v[idx+1].first){
            res = max(res, dfs(v, idx+1, dp)+(v[idx].first)*(v[idx].second));
        }else{
            res = max(res, dfs(v, idx+2, dp) + (v[idx].first)*(v[idx].second));
            res = max(res, dfs(v, idx+1, dp));
        }
        dp[idx] = res;
        return res;
    }


    //我的方法：  超出时间限制
    int deleteAndEarn1(vector<int>& a) {
        map<int, int> m;
        for(auto i:a){
            m[i]++;
        }
        return dfs1(m);
    }
    int dfs1(map<int, int> m){
        if(m.empty())
            return 0;
        if(m.size() == 1)
            return (m.begin()->second) * (m.begin()->first);
        int res = 0;
        map<int, int> b;
        b.insert(m.begin(), m.end());
        for(map<int, int>::iterator it=b.begin(); it!=b.end(); it++){
            int k = it->first;
            int v = it->second;
            int k1 = 0;
            int k2 = 0;
            if(m.count(k+1) != 0){
                k1 = m[k+1];
                m.erase(k+1);
            }
            if(m.count(k-1) != 0){
                k2 = m[k-1];
                m.erase(k-1);
            }
            m.erase(k);
            res = max(res, k*v + dfs1(m));
            m[k] = v;
            if(k1 != 0){
                m[k+1] = k1;

            }
            if(k2 != 0){
                m[k-1] = k2;
            }
        }
        return res;
    }
};
int main(){
    vector<int> a = {3,1};
    Solution s;
    cout<<s.deleteAndEarn(a);
    return 0;
}

