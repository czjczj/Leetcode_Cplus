/*
* Author:czj
* Time:  2019/8/15 09:03
*给定平面上 n 对不同的点，“回旋镖” 是由点表示的元组 (i, j, k) ，其中 i 和 j 之间的距离和 i 和 k 之间的距离相等（需要考虑元组的顺序）。
    找到所有回旋镖的数量。你可以假设 n 最大为 500，所有点的坐标在闭区间 [-10000, 10000] 中。
    示例:
    输入:
    [[0,0],[1,0],[2,0]]
    输出:
    2
    解释:
    两个回旋镖为 [[1,0],[0,0],[2,0]] 和 [[1,0],[2,0],[0,0]]
*/
#include <iostream>
#include <string>
#include <algorithm>
#include <stack>
#include <vector>
#include <cmath>
using namespace std;
/**
 * 解题思路： 这道题目虽然是一道简单题目，但是确实思考的地方还是有很多，
 * 1. 直观的想法，计算出每两个点之间的距离（使用 距离的平方保存 ）。
 * 2. 在1的基础上直观的想法是，做一个三重循环， O(n^3) 超了
 * 改 2。 外层循环做按照每个顶点计算。比如  按照 下标为 1 的节点的话，那么
 * 从1号点出发，   由1计算到其到其他点的距离为  0 2 2 4 4 4 ....
 * 第一个0为其到自己的距离，那么   2重复两次  cnt+= 2*C(2,2)  4重复三次  cnt += 2*C(2,3)  C(n,m) 表示从
 * m个数字中排列组合算出n个
 */
class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& b) {
        int len = b.size();
        int cnt = 0;
        int a[len][len];
        fill(a[0],a[0]+len*len,0);
        for(int i=0; i<len; i++){
            for(int j=0; j<len; j++){
                a[i][j] = pow(b[i][0]-b[j][0],2)+pow(b[i][1]-b[j][1],2);
            }
        }

        for(int i=0; i<len; i++){
            sort(a[i],a[i]+len);
            int same_num_c = 0;
            int same_num = 0;
            int j=1;
            for(; j<len; j++){
                if(same_num==a[i][j])
                    same_num_c++;
                else {
                    cnt += same_num_c * (same_num_c - 1);
                    same_num_c = 1;
                    same_num = a[i][j];
                }
            }
            if(a[i][j-1] == same_num)
                cnt += same_num_c * (same_num_c - 1);
        }
        return cnt;
    }
};
int main(){
    Solution s;
    vector<vector<int>> v = {{0,0},{1,0},{2,0}};

    int a = s.numberOfBoomerangs(v);
    cout<<a<<endl;
    return 0;
}



