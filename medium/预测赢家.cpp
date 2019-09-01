/*
* Author:czj
* Time:  2019/8/30 08:15
给定一个表示分数的非负整数数组。 玩家1从数组任意一端拿取一个分数，随后玩家2继续从剩余数组任意一端拿取分数，
然后玩家1拿，……。每次一个玩家只能拿取一个分数，
分数被拿取之后不再可取。直到没有剩余分数可取时游戏结束。最终获得分数总和最多的玩家获胜。
给定一个表示分数的数组，预测玩家1是否会成为赢家。你可以假设每个玩家的玩法都会使他的分数最大化。
示例 1:
输入: [1, 5, 2]
输出: False
解释: 一开始，玩家1可以从1和2中进行选择。
如果他选择2（或者1），那么玩家2可以从1（或者2）和5中进行选择。如果玩家2选择了5，那么玩家1则只剩下1（或者2）可选。
所以，玩家1的最终分数为 1 + 2 = 3，而玩家2为 5。
因此，玩家1永远不会成为赢家，返回 False。
来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/predict-the-winner
*/
/**
 * 我的解题思路：  类似于取石子的游戏，每次判断我从最左端和最右端取数字，在最后的结果
 * 处（即不能再取数字以后），剩余分数的情况。这里需要用一个标志变量判断当前是 对手 或者 自己
 * 是谁在选取数字
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
    bool PredictTheWinner(vector<int>& a) {
        int n = a.size();
        return dfs(0,0,a,0,a.size()-1, true);
    }
    bool dfs(int s1, int s2, vector<int>& a, int l, int r, int flag){
        if(l>r){
            return flag?s1>=s2:s1<s2;
        }
        if(flag){
            if(!dfs(s1+a[l],s2,a,l+1,r,!flag))
                return true;
            if(!dfs(s1+a[r],s2,a,l,r-1,!flag))
                return true;
        }else{
            if(!dfs(s1,s2+a[l],a,l+1,r,!flag))
                return true;
            if(!dfs(s1,s2+a[r],a,l,r-1,!flag))
                return true;
        }
        return false;
    }
};
int main(){
    vector<int> a = {0};
    Solution s;
    cout<<s.PredictTheWinner(a);
    return 0;
}



