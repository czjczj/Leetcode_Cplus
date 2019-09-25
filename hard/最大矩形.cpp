/*
* Author:czj
* Time  :2019/09/18 18:05
* Email :zj_cheng@csu.edu.cn
给定一个仅包含 0 和 1 的二维二进制矩阵，找出只包含 1 的最大矩形，并返回其面积。
示例:
输入:
[
  ["1","0","1","0","0"],
  ["1","0","1","1","1"],
  ["1","1","1","1","1"],
  ["1","0","0","1","0"]
]
输出: 6
链接：https://leetcode-cn.com/problems/maximal-rectangle
*/
#include <iostream>
#include <map>
#include <vector>
#include <queue>
#include <stack>
using namespace std;
class Solution {
public:
    /**
     * 思路： 先将问题简化为
     *
     *  {'1','0','1','0','0'},
        {'1','0','1','1','1'},
        {'1','1','1','1','1'},
        {'1','0','0','1','0'}
        转化为依照每个低为的的连续柱状高度
        1 0 1 0 0
        2 0 2 1 1
        3 1 3 2 2
        4 0 0 3 0

        按照 leetcode84: 柱状图的最大矩阵求解得到最后的结果
     */
    int maximalRectangle(vector<vector<char>>& a) {
        int res = 0;
        int m = a.size();
        if(m==0)
            return 0;
        int n = a[0].size();
        vector<vector<int>> v(m, vector<int>(n,0));
        for(int i=0; i<n; i++){
            if(a[0][i]=='1'){
                v[0][i] = 1;
            }else{
                v[0][i] = 0;
            }
        }
        for(int i=1; i<m; i++){
            for(int j=0; j<n; j++){
                if(a[i][j] == '1'){
                    v[i][j] = v[i-1][j]+1;
                }else{
                    v[i][j] = 0;
                }
            }
        }

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                cout<<v[i][j]<<" ";
            }
            cout<<endl;
        }

        //对每一行进行 85 那种操作
        for(int i=0; i<m; i++){
            stack<int> s;
            v[i].push_back(0);// 记住这个后面需要加入一个0元素。
            for(int j=0; j<v[i].size(); j++){
                if(s.empty() || v[i][s.top()] <= v[i][j]){
                    s.push(j);
                }else{
                    int cur_idx = s.top(); s.pop();
                    res = max(res, v[i][cur_idx]*(s.empty()?j:(j-s.top()-1)));
                    j--;
                }
            }
        }
        return res;
    }
};
int main() {
    Solution s;
    vector<vector<char>> a = {{'1','0','1','0','0'},
                              {'1','0','1','1','1'},
                              {'1','1','1','1','1'},
                              {'1','0','0','1','0'}};
    int res = s.maximalRectangle(a);
    cout<<res;
    return 0;
}





