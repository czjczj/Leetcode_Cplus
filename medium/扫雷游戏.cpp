/*
* Author:czj
* Time:  2019/8/27 15:36
让我们一起来玩扫雷游戏！
给定一个代表游戏板的二维字符矩阵。 'M' 代表一个未挖出的地雷，'E' 代表一个未挖出的空方块，'B' 代表没有相邻（上，下，左，右，和所有4个对角线）
 地雷的已挖出的空白方块，
 数字（'1' 到 '8'）表示有多少地雷与这块已挖出的方块相邻，'X' 则表示一个已挖出的地雷。
现在给出在所有未挖出的方块中（'M'或者'E'）的下一个点击位置（行和列索引），根据以下规则，返回相应位置被点击后对应的面板：
如果一个地雷（'M'）被挖出，游戏就结束了- 把它改为 'X'。
如果一个没有相邻地雷的空方块（'E'）被挖出，修改它为（'B'），并且所有和其相邻的方块都应该被递归地揭露。
如果一个至少与一个地雷相邻的空方块（'E'）被挖出，修改它为数字（'1'到'8'），表示相邻地雷的数量。
如果在此次点击中，若无更多方块可被揭露，则返回面板。
示例 1：
输入:
[['E', 'E', 'E', 'E', 'E'],
 ['E', 'E', 'M', 'E', 'E'],
 ['E', 'E', 'E', 'E', 'E'],
 ['E', 'E', 'E', 'E', 'E']]
Click : [3,0]
 ['B', '1', 'M', '1', 'B'],
 ['B', '1', '1', '1', 'B'],
 ['B', 'B', 'B', 'B', 'B']]
*/
/**
 * 解题思路： 对于初始位置做两个操作
 * 1. 遍历该位置的周围，统计其周围是否都是 'E'?  如果是的，则遍历周围是 E的位置
 * 2. 如果其周围不是存在  'M'?  则只需要  改变该点的值就可以了
 */
#include <iostream>
#include <string>
#include <algorithm>
#include <stack>
#include <vector>
#include <cmath>
#include <set>
#include <map>
using namespace std;
class Solution {
public:
    vector<vector<int>> dir = {{0,1},{0,-1},{1,0},{-1,0},{1,1},{-1,-1},{1,-1},{-1,1}};
    vector<vector<char>> updateBoard(vector<vector<char>>& b, vector<int>& c) {
        int m = b.size();
        if(m==0){
            vector<vector<char>> r;
            return r;
        }
        int n = b[0].size();
        int sx = c[0];  int sy = c[1];
        dfs(sx, sy, b, m, n);
        return b;
    }
    void dfs(int x, int y, vector<vector<char>>& map, int m, int n){
        if(map[x][y] == 'M'){
            map[x][y] = 'X';
            return;
        }
        int cnt = 0;
        for(int i=0; i<dir.size(); i++){
            int nx = x+dir[i][0];
            int ny = y+dir[i][1];
            if(nx<0 || nx>=m || ny<0 || ny>=n)
                continue;
            if(map[nx][ny] == 'M')
                cnt++;
        }
        if(cnt==0){
            map[x][y] = 'B';
            for(int i=0; i<dir.size(); i++){
                int nx = x+dir[i][0];
                int ny = y+dir[i][1];
                if(nx<0 || nx>=m || ny<0 || ny>=n)
                    continue;
                if(map[nx][ny] == 'E')
                    dfs(nx,ny,map,m,n);
            }
        }else{
            map[x][y] = (char)('0'+cnt);
        }
    }
};
int main(){
    Solution s;
    vector<vector<char>> v = {{'E', 'E', 'E', 'E', 'E'},
                              {'E', 'E', 'M', 'E', 'E'},
                              {'E', 'E', 'E', 'E', 'E'},
                              {'E', 'E', 'E', 'E', 'E'}};
    vector<int> c = {3,0};
    vector<vector<char>> r = s.updateBoard(v,c);

    for(int i=0; i<r.size(); i++){
        for(int j=0; j<r[i].size(); j++){
            cout<<r[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}


