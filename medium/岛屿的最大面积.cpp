/*
* Author:czj
* Time:  2019/8/28 09:10
*给定一个包含了一些 0 和 1的非空二维数组 grid , 一个 岛屿 是由四个方向 (水平或垂直) 的 1 (代表土地) 构成的组合。
你可以假设二维矩阵的四个边缘都被水包围着。
找到给定的二维数组中最大的岛屿面积。(如果没有岛屿，则返回面积为0。)
示例 1:

[[0,0,1,0,0,0,0,1,0,0,0,0,0],
 [0,0,0,0,0,0,0,1,1,1,0,0,0],
 [0,1,1,0,1,0,0,0,0,0,0,0,0],
 [0,1,0,0,1,1,0,0,1,0,1,0,0],
 [0,1,0,0,1,1,0,0,1,1,1,0,0],
 [0,0,0,0,0,0,0,0,0,0,1,0,0],
 [0,0,0,0,0,0,0,1,1,1,0,0,0],
 [0,0,0,0,0,0,0,1,1,0,0,0,0]]
对于上面这个给定矩阵应返回 6。注意答案不应该是11，因为岛屿只能包含水平或垂直的四个方向的‘1’。
来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/max-area-of-island
*/
/**
 * 解题思路： 基本的bfs, 对于每一个位置判断是否为1， 如果是则以该点为起始左边，bfs统计个数
 * get:  if(nx>=m || nx<0 || ny<0 || ny>=n || map[nx][ny]) 是无法这样判断的
 * 这里bfs需要注意的是，  判断在得到一个新的 map[][]位置后，需要将该位置立刻0
 * 否则延迟置为0 的情况下  会将这种
 *     11
 *     11
 * 的区域计算为5
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
int m = 0;
int n = 0;
vector<vector<int>> dir = {{1,0},{-1,0},{0,1},{0,-1}};
class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& map) {
        m = map.size();
        if(m==0)
            return 0;
        n = map[0].size();
        int rtn = 0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(map[i][j] == 1){
                    rtn = max(rtn,bfs(i,j,map));
                }
            }
        }
        return rtn;
    }
    int bfs(int x, int y, vector<vector<int>>& map){
        queue<pair<int, int>> q;
        q.push(make_pair(x,y));
        int cnt = 0;
//        map[x][y] = 0;
        while(!q.empty()){
            pair<int, int> p = q.front();
            q.pop();
            int x = p.first;
            int y = p.second;
            map[x][y] = 0;
            cnt++;
            for(int k=0; k<dir.size(); k++){
                int nx = x+dir[k][0];
                int ny = y+dir[k][1];
                if(nx>=m || nx<0 || ny<0 || ny>=n)
                    continue;
                if(map[nx][ny]==0)
                    continue;

                q.push(make_pair(nx,ny));
            }
        }
        return cnt;
    }
};
int main(){
    Solution s;
    vector<vector<int>> v = {{0,0,1,0,0,0,0,1,0,0,0,0,0},
                             {0,0,0,0,0,0,0,1,1,1,0,0,0},
                             {0,1,1,0,1,0,0,0,0,0,0,0,0},
                             {0,1,0,0,1,1,0,0,1,0,1,0,0},
                             {0,1,0,0,1,1,0,0,1,1,1,0,0},
                             {0,0,0,0,0,0,0,0,0,0,1,0,0},
                             {0,0,0,0,0,0,0,1,1,1,0,0,0},
                             {0,0,0,0,0,0,0,1,1,0,0,0,0}};
    cout<<s.maxAreaOfIsland(v);

    return 0;
}



