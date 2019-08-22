/*
* Author:czj
* Time:  2019/8/17 11:05
*   给定一个包含 0 和 1 的二维网格地图，其中 1 表示陆地 0 表示水域。
    网格中的格子水平和垂直方向相连（对角线方向不相连）。整个网格被水完全包围，但其中恰好有一个岛屿（或者说，一个或多个表示陆地的格子相连组成的岛屿）。
    岛屿中没有“湖”（“湖” 指水域在岛屿内部且不和岛屿周围的水相连）。格子是边长为 1 的正方形。网格为长方形，且宽度和高度均不超过 100 。计算这个岛屿的周长。
    示例 :
    输入:
    [[0,1,0,0],
     [1,1,1,0],
     [0,1,0,0],
     [1,1,0,0]]
    输出: 16
*/
#include <iostream>
#include <string>
#include <algorithm>
#include <stack>
#include <vector>
#include <cmath>
#include <set>
/**
 * 解题思路，对于每一个位置，如果 该位置为1， 则最后的和应该加上 （4 - 其周围是1的个数）， 比如
 * 一个位置为1，  其4个方向也都是1，那么该位置对于最后的总边数是没有贡献的
 */
using namespace std;
class Solution {
public:
    int dir[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
    int islandPerimeter(vector<vector<int>>& a) {
        int cnt = 0;
        int m = a.size();
        if(m == 0)
            return 0;
        int n = a[0].size();
        for(int i=0; i<a.size(); i++){
            for(int j=0; j<a[i].size(); j++){
                if(a[i][j] == 1){
                    cnt += 4;
                    for(int k=0; k<4; k++){
                        int x = i+dir[k][0];
                        int y = j+dir[k][1];
                        if(x>=0 && x<m && y>=0 && y<n && a[x][y]==1)
                            cnt--;
                    }
                }
            }
        }
        return cnt;
    }
};
int main(){
    Solution s;
    cout<<s.minMutation(start,end,a)<<endl;
    return 0;
}


