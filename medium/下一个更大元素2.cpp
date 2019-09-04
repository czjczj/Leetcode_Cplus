/*
* Author:czj
* Time:  2019/9/3 08:00
*给定一个循环数组（最后一个元素的下一个元素是数组的第一个元素），输出每个元素的下一个更大元素。数字 x
的下一个更大的元素是按数组遍历顺序，这个数字之后的第一个比它更大的数，这意味着你应该循环地搜索它的下一个更大的数。
 如果不存在，则输出 -1。
示例 1:
输入: [1,2,1]
输出: [2,-1,2]
解释: 第一个 1 的下一个更大的数是 2；
数字 2 找不到下一个更大的数；
第二个 1 的下一个最大的数需要循环搜索，结果也是 2。
来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/next-greater-element-ii
*/
/**
 * 解题思路： 两个循环的暴力搜索方式，只需要判断好循环数组的下一个位置就好了
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
    vector<int> nextGreaterElements(vector<int>& a) {
        int n = a.size();
        vector<int> v(n,0);
        for(int i=0; i<n; i++){
            int len = 1;
            while(len < n){
                int nx = a[(i+len)%n];
                if(nx > a[i]){
                    v[i] = nx;
                    break;
                }
                len++;
            }
            if(len == n)
                v[i] = -1;
        }
        return v;
    }
};
int main(){
    Solution s;
    vector<int> v = {1,2,1};
    vector<int> b = s.nextGreaterElements(v);
    for (int i = 0; i < b.size(); ++i) {
        cout<<b[i]<<" ";
    }
    return 0;
}


