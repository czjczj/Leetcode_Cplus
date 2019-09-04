/*
* Author:czj
* Time:  2019/9/4 07:56
*假设有从 1 到 N 的 N 个整数，如果从这 N 个数字中成功构造出一个数组，使得数组的第 i 位 (1 <= i <= N) 满足
如下两个条件中的一个，我们就称这个数组为一个优美的排列。条件：
第 i 位的数字能被 i 整除
i 能被第 i 位上的数字整除
现在给定一个整数 N，请问可以构造多少个优美的排列？
示例1:
输入: 2
输出: 2
解释:
第 1 个优美的排列是 [1, 2]:
  第 1 个位置（i=1）上的数字是1，1能被 i（i=1）整除
  第 2 个位置（i=2）上的数字是2，2能被 i（i=2）整除
来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/beautiful-arrangement
*/
/**
 *直接做一个dfs的遍历 ，判断  限定的两个条件就可以了
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
    int countArrangement(int N) {
        vector<bool> v(N+1, false);
        return dfs(0,N,v);
    }
    int dfs(int idx, int n, vector<bool>& v){
        if(idx==n)
            return 1;
        int res = 0;
        for(int i=1; i<=n; i++){
            if(v[i])
                continue;
            if(i%(idx+1) != 0 && (idx+1)%i != 0)
                continue;
            v[i] = true;
            res += dfs(idx+1, n, v);
            v[i] = false;
        }
        return res;
    }
};
int main(){
    Solution s;
    cout<<s.countArrangement(2);
    return 0;
}


