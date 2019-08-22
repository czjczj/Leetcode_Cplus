/*
* Author:czj
* Time:  2019/8/18 18:11
*给定一个二维矩阵，计算其子矩形范围内元素的总和，该子矩阵的左上角为 (row1, col1) ，右下角为 (row2, col2)。
上图子矩阵左上角 (row1, col1) = (2, 1) ，右下角(row2, col2) = (4, 3)，该子矩形内元素的总和为 8。
示例:
给定 matrix = [
  [3, 0, 1, 4, 2],
  [5, 6, 3, 2, 1],
  [1, 2, 0, 1, 5],
  [4, 1, 0, 1, 7],
  [1, 0, 3, 0, 5]
]
sumRegion(2, 1, 4, 3) -> 8
sumRegion(1, 1, 2, 2) -> 11
sumRegion(1, 2, 2, 4) -> 12
*/
/**
 * 解题思路：  找规律，就是动态规划，每一个位置
 * sum[r1,c1,r2,c2] = sum[0,0,r2,c2]+sum[0,0,r1-1,c1-1]-sum[0,0,r1-1,c2]-sum[0,0,r2,c1-1]
 * 这里每一个位置区分一下  是否大于1 就可以了
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
class NumMatrix {
public:
    vector<vector<int>> sum;
    NumMatrix(vector<vector<int>>& a) {
        int m = a.size();
        if(m == 0)
            return;
        int n = a[0].size();
        vector<vector<int>> s(m, vector<int>(n, 0));
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(i-1>=0 && j-1>=0)
                    s[i][j] = a[i][j] + s[i-1][j] + s[i][j-1] - s[i-1][j-1];
                else if(i-1>=0)
                    s[i][j] = a[i][j] + s[i-1][j];
                else if(j-1>=0)
                    s[i][j] = a[i][j] + s[i][j-1];
                else
                    s[i][j] = a[i][j];
            }
        }
        sum = s;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                cout<<sum[i][j]<<" ";
            }
            cout<<endl;
        }
    }

    int sumRegion(int r1, int c1, int r2, int c2) {
        if(r1>=1 && c1>=1)
            return sum[r2][c2]+sum[r1-1][c1-1]-sum[r1-1][c2]-sum[r2][c1-1];
        else if(r1>=1)
            return sum[r2][c2]-sum[r1-1][c2];
        else if(c1>=1)
            return sum[r2][c2]-sum[r2][c1-1];
        else
            return sum[r2][c2];
    }
};
int main(){

    vector<vector<int>> v = {
            {3, 0, 1, 4, 2},
            {5, 6, 3, 2, 1},
            {1, 2, 0, 1, 5},
            {4, 1, 0, 1, 7},
            {1, 0, 3, 0, 5}
    };
    NumMatrix s(v);
    cout<<s.sumRegion(2,1,4,3)<<endl;
    return 0;
}



