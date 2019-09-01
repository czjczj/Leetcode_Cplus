/*
* Author:czj
* Time:  2019/9/1 08:01
*有 n 个城市通过 m 个航班连接。每个航班都从城市 u 开始，以价格 w 抵达 v。
现在给定所有的城市和航班，以及出发城市 src 和目的地 dst，你的任务是找到从 src 到 dst 最多经过 k 站中转的最便宜的价格。
 如果没有这样的路线，则输出 -1。
示例 1:
输入:
n = 3, edges = [[0,1,100],[1,2,100],[0,2,500]]
src = 0, dst = 2, k = 1
输出: 200
解释:
来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/cheapest-flights-within-k-stops
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
    int K = 0;
    /**
     * 该问题的解法使用的方法： DFS + 剪枝
     * 还要判断某个点是否已经访问过了吗
     * 1. 需要考虑存储图的数据结构， 我这里刚开始存储的是 边的结构,然后在这种情况下，
     *    由于边的个数时 n^2的，导致在dfs 循环的时候， 计算量非常的大
     * 2. 在dp 的时候需要知道  冗余的信息到底是什么，然后这里在dp的时候出现的问题是
     *    我开始使用的 dp[s][cnt]  s 表示当前所处的节点， cnt已经用的路径长度，这里的
     *    其实这个信息  dp[s][cnt] 其实并没有被多次的访问到。
     */
    int findCheapestPrice(int n, vector<vector<int>>& a, int s, int e, int k) {
        vector<vector<int>> map(n, vector<int>(n, -1));
        for(int i=0; i<a.size(); i++){
            map[a[i][0]][a[i][1]] = a[i][2];
        }
        K = k;
        int res = INT_MAX;
        vector<bool> isVis(n, false);
        isVis[s] = true;
        dfs(map,s,e,0,res,0,isVis);
        return res==INT_MAX?-1:res;
    }
    void dfs(vector<vector<int>> map, int s, int e, int haveCost, int& res, int cnt, vector<bool>& isVis){
        if(s == e){
            res = min(res, haveCost);
            return;
        }
        if(haveCost>=res || cnt>K)
            return;

        for(int i=0; i<map.size(); i++){
            if(!isVis[i] && map[s][i] != -1){
                isVis[i] = true;
                dfs(map,i,e,haveCost+map[s][i],res,cnt+1,isVis);
                isVis[i] = false;
            }
        }
    }
    /**
     * 我的方法: 刚开始超时了，  最后加上了 isVis  AC
     */
    int findCheapestPrice1(int n, vector<vector<int>>& a, int s, int e, int k) {
        map<int, vector<pair<int, int>>> m;
        for(int i=0; i<a.size(); i++){
            int s = a[i][0];
            m[s].push_back(make_pair(a[i][1],a[i][2]));
        }
        K = k;
        vector<vector<int>> dp(n,vector<int>(k+1,-1));
        vector<bool> isVis(n, false);
        isVis[s] = true;
        int res = dfs1(m,s,e,0,dp,isVis);
        return res==INT_MAX?-1:res;
    }
    int dfs1(map<int, vector<pair<int, int>>>& a, int s, int e, int cnt, vector<vector<int>>& dp, vector<bool>& isVis){
        if(s==e)
            return 0;
        if(cnt > K)
            return INT_MAX;
        int res = INT_MAX;
        if(dp[s][cnt] != -1)
            return dp[s][cnt];
        vector<pair<int, int>> v = a[s];
        for(int i=0; i<v.size(); i++){
            int ns = v[i].first;
            if(isVis[ns])
                continue;
            isVis[ns] = true;
            int rtn = dfs1(a,ns,e,cnt+1,dp,isVis);
            isVis[ns] = false;
            if(rtn != INT_MAX)
                res = min(res, rtn+v[i].second);
        }
        dp[s][cnt] = res;
        return res;
    }
};
int main(){
    vector<vector<int>> a = {{0,1,100},{1,2,100},{0,2,500}};
    int n = 3;
    int s = 0;
    int d = 2;
    int k = 0;
    Solution ss;
    cout<<ss.findCheapestPrice1(n,a,s,d,k);
    return 0;
}

