/*
* Author:czj
* Time  :2019/09/17 10:11
* Email :zj_cheng@csu.edu.cn
* 对于一个具有树特征的无向图，我们可选择任何一个节点作为根。图因此可以成为树，在所有可能的树中，具有最小高度的树被称为最小高度树。给
出这样的一个图，写出一个函数找到所有的最小高度树并返回他们的根节点。
格式
该图包含 n 个节点，标记为 0 到 n - 1。给定数字 n 和一个无向边 edges 列表（每一个边都是一对标签）。
你可以假设没有重复的边会出现在 edges 中。由于所有的边都是无向边， [0, 1]和 [1, 0] 是相同的，因此不会同时出现在 edges 里。
示例 1:
输入: n = 4, edges = [[1, 0], [1, 2], [1, 3]]
链接：https://leetcode-cn.com/problems/minimum-height-trees
*/
#include <iostream>
#include <map>
#include <vector>
#include <queue>
using namespace std;
class Solution {
public:
    /**
     * 参考答案的解法：
     * 1. 最后的树的  最小高度树的根节点只会有 2 个 或者 1 个; 当存在三个或者三个以上的时候那么保证边的连接， 一定不会出现共根的
     * 2. 从度为 1 的叶子节点一层一层拨离原始节点。最后得到对应的结果。
     * 总结:这道题目写了好久,太菜了
     * 注意： 对于 queue 使用for 循环的时候， 在想queue中添加元素的时候，其长度是会变化的。
     */
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& e){
        vector<int> du; //保存每个节点度
        vector<vector<int>> es(n,vector<int>()); //保存节点的临界矩阵
        queue<int> q; //保存度未1的节点 并用它来完成最后的不断更新
        vector<int> ans; //保存结果

        for(int i=0; i<n; i++){
            du.push_back(0);
        }
        for(int i=0; i<e.size(); i++){
            du[e[i][0]]++;
            du[e[i][1]]++;
            int s = e[i][0];
            int end = e[i][1];
            es[s].push_back(end);
            es[end].push_back(s);
        }

        for(int i=0; i<du.size(); i++){
            if(du[i]==1)
                q.push(i);
        }

        int r = n; //总的节点个数 并用其最后不断减少度未1的节点个数

        if(r==1)
            ans.push_back(0);
        while(r != 1 && r!=2){
            int len = q.size();
            r -= len;
            //遍历每一个du为1 节点更新。
            for(int i=0; i<len; i++){
                int idx = q.front(); q.pop();
                for(auto v:es[idx]){
                    if(du[v] > 0)
                        du[v]--;
                    if(du[v] == 1)
                        q.push(v);
                }
            }
        }

        while(!q.empty()){
            ans.push_back(q.front());
            q.pop();
        }
        return ans;
    }
    /**
     * 自己的思路： 超时，
     * 想法： 对于每一个 节点 进行一次bfs,最后进行统计需要 相同的 时间
     */
    vector<int> findMinHeightTrees1(int n, vector<vector<int>>& e) {
        vector<vector<int>> es(n);
        for(int i=0; i<e.size(); i++){
            int s = e[i][0];
            int end = e[i][1];
            es[s].push_back(end);
            es[end].push_back(s);
        }
        vector<int> rtn(n,0);
        for(int i=0; i<n; i++){
            vector<bool> dp(n, false);
            int res = bfs(i,es,dp);
            rtn[i] = res;
        }
        int min_num = INT32_MAX;
        for(int i=0; i<n; i++){
            min_num = min(rtn[i], min_num);
        }
        vector<int> t;
        for(int i=0; i<n; i++){
            if(rtn[i]==min_num)
                t.push_back(i);
        }
        return t;
    }
    int bfs(int idx, vector<vector<int>>& es, vector<bool>& dp){
        queue<int> q;
        q.push(idx);
        int res = 0;

        while(!q.empty()){
            queue<int> tmpq;
            while(!q.empty()){
                int ii = q.front(); q.pop();
                dp[ii] = true;
                for(int i=0; i<es[ii].size(); i++){
                    if(dp[es[ii][i]])
                        continue;
                    tmpq.push(es[ii][i]);
                }
            }
            q = tmpq;
            res++;
        }
        return res;
    }
};
int main() {
    Solution s;
    vector<vector<int>> edges = {{1, 0}, {1, 2}, {1, 3}};
    vector<vector<int>> ee = {{0, 3}, {1, 3}, {2, 3}, {4, 3}, {5, 4}};
    int n = 4;
    vector<int> v = s.findMinHeightTrees(4,edges);
    for(int i=0; i<v.size(); i++){
        cout<<v[i]<<" ";
    }
    return 0;
}



