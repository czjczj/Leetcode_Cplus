/*
* Author:czj
* Time:  2019/9/4 08:18
*给定一个由 0 和 1 组成的矩阵，找出每个元素到最近的 0 的距离。
两个相邻元素间的距离为 1 。
示例 1:
输入:
0 0 0
0 1 0
0 0 0
输出:
0 0 0
0 1 0
0 0 0
来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/01-matrix
*/
/**
 * 解题思路：
 * 1. 从左上角向右下角遍历，对于每一个位置  v[i][j]  等于 周围最小值 加上1
 * 这种情况下可能出现的问题是这种情况
 *          0 0 0       0 0 0
 *          0 1 0  -->  0 1 0
 *          1 1 0       1 2 0   很显然这个最下面一行的2 输出是不对的
 * 这是因为从左上角向右下角遍历的过程中，  2 后面这个元素在其后面更新
 * 因此需要步骤2：
 * 2. 在从右下角向左上角更新，对于每一位置 v[i][j]  等于其周围最小值， 并判断当前
 * 该值的最小与周围最小值情况，取两者最小一个即可
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
    int dir[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
    vector<vector<int>> updateMatrix(vector<vector<int>>& a) {
        int m = a.size();
        if(m==0){
            vector<vector<int>> a;
            return a;
        }
        int n = a[0].size();
        vector<vector<int>> v(m, vector<int>(n, INT_MAX));
        //从左上到右下角遍历
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(a[i][j]==0){
                    v[i][j] = 0;
                    continue;
                }
                int tmp = INT_MAX;
                for(int k=0; k<4; k++){
                    int ni = i+dir[k][0];
                    int nj = j+dir[k][1];
                    if(ni<0||ni>=m||nj<0||nj>=n)
                        continue;
                    tmp = min(tmp, v[ni][nj]);
                }
                if(tmp == INT_MAX)
                    continue;
                v[i][j] = tmp+1;
            }
        }

        for(int i=m-1; i>=0; i--){
            for(int j=n-1; j>=0; j--){
                if(a[i][j]==0){
                    v[i][j] = 0;
                    continue;
                }
                int tmp = INT_MAX;
                for(int k=0; k<4; k++){
                    int ni = i+dir[k][0];
                    int nj = j+dir[k][1];
                    if(ni<0||ni>=m||nj<0||nj>=n)
                        continue;
                    tmp = min(tmp, v[ni][nj]);
                }
                if(tmp == INT_MAX)
                    continue;
                v[i][j] = min(tmp+1, v[i][j]);
            }
        }
        return v;
    }
};
int main(){
    Solution s;
    vector<vector<int>> v = {{0,0,0},{0,1,0},{1,1,1}};
    vector<vector<int>> r = s.updateMatrix(v);
    for(int i=0; i<v.size(); i++){
        for(int j=0; j<v[0].size(); j++){
            cout<<r[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}


