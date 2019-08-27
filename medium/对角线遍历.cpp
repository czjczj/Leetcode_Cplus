/*
* Author:czj
* Time:  2019/8/27 14:25
*给定一个含有 M x N 个元素的矩阵（M 行，N 列），请以对角线遍历的顺序返回这个矩阵中的所有元素，对角线遍历如下图所示。s
输入:
[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]
*/
/**
 * 按照规律写：  注意上半角 和 下半角是不一样的
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
    vector<int> findDiagonalOrder(vector<vector<int>>& a) {
        int i=0;
        int j=0;
        int m = a.size();
        int n = a[0].size();
        vector<int> v;
        int k = 0;
        while(!(i==m-1 && j==n-1)){
            if(k%2 == 0){
                while(i>=0 && j<n){
                    v.push_back(a[i][j]);
                    i--;
                    j++;
                }
                if(j>=n){
                    i+=2;
                    j--;
                }else{
                    i++;
                }
            }else{
                while(i<m && j>=0){
                    v.push_back(a[i][j]);
                    i++;
                    j--;
                }
                if(i>=m){
                    i--;
                    j+=2;
                }else{
                    j++;
                }
            }
            k++;
        }
        v.push_back(a[m-1][n-1]);
        return v;
    }
};
int main(){
    Solution s;
    vector<vector<int>> v = {
            {1,2,3},
            {4,5,6}
    };
    vector<int> a = s.findDiagonalOrder(v);
    for(int i=0; i<a.size(); i++){
        cout<<a[i]<<" ";
    }
    return 0;
}

