/*
* Author:czj
* Time  :2019/09/18 09:47
* Email :zj_cheng@csu.edu.cn
给定 n 个非负整数，用来表示柱状图中各个柱子的高度。每个柱子彼此相邻，且宽度为 1 。
求在该柱状图中，能够勾勒出来的矩形的最大面积。
以上是柱状图的示例，其中每个柱子的宽度为 1，给定的高度为 [2,1,5,6,2,3]。
图中阴影部分为所能勾勒出的最大矩形面积，其面积为 10 个单位。
输入: [2,1,5,6,2,3]
输出: 10
链接：https://leetcode-cn.com/problems/largest-rectangle-in-histogram
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
     * 后面所有的问题求解都考虑这样一个问题数组 ：   2 1 5 6 2 3
     * 形成的图形：
     *          6
     *        5 ×
     *        × ×
     *        × ×   3
     *    2   × × 2 ×
     *    × 1 × × × ×
     *    × × × × × ×
     *
     * 解题思路： 递增的按照不断优化的思路
     */
    /**
     * TLE
     * 暴力破解的方式， 枚举起点和终点。
     */
    int largestRectangleArea1(vector<int>& a) {
        int n = a.size();
        int res = 0;
        for(int i=0; i<n; i++){
            int m = a[i];
            for(int j=i; j<n; j++){
                m = min(m,a[j]);
                res = max(res, (j-i+1)*m);
            }
        }
        return res;
    }
    /**
     *  AC
     * 考虑暴力求解的时候其实有许多的位置是不需要重复求解一遍的
     *  考虑一个递增的序列中  1 5 6 ，我们只需要计算 局部峰值 6 形成的矩阵，因为6在向前不断计算的过程中
     *  形成的矩阵包括了 1,5 形成的矩阵。 且其在形成矩阵的宽度上一定要比前面的长。那么问题优化为只需要处理峰值就可以了
     *  具体说名：
     *  1 5 6  峰值为6   1形成矩阵 1 1x2 1x3  5形成 1x2 5 5x2   6形成 1x3 5x2 6
     */
    int largestRectangleArea2(vector<int>& a){
        int n = a.size();
        int res = 0;
        for(int i=0; i<n; i++){
            if(i+1<n && a[i]<=a[i+1])
                continue;
            int hei = a[i];
            for(int j=i; j>=0; j--){
                hei = min(hei, a[j]);
                res = max(res, (i-j+1)*hei);
            }
        }
        return res;
    }
    /**
     * 单调栈处理该问题：
     * 1.递增栈，维护一个递增的序列，当遇到小于栈顶的元素的时候开始处理
     * 2.递减栈，当遇到大于栈顶的元素的时候开始处理
     * 这里求解局部最大值，使用单调递增栈
     * 增大了 空间， 时间复杂度降到了 O(n)
     */
    int largestRectangleArea(vector<int>& a){
        int res = 0;
        stack<int> s;
        a.push_back(0);
        for(int i=0; i<a.size(); i++){
            if(s.empty() || a[s.top()] <= a[i]){
                s.push(i);
            }else{
                int cur = s.top(); s.pop();//注意现在的这个 cur 和 s.top() 已经不同了
                //注意这里在 弹出了 cur 以后， s.top() 已经不同了，
                //为什么需要判断 s.empty()  这种情况： 2 3 4 1
                //当我们压入栈到 1 的时候，会将前面的元素都弹出，但是这个时候是有一个情况， 4x1
                //即以 1 为高度，宽为4 是需要我们计算的
                res = max(res, a[cur] * (s.empty() ? i : (i - s.top() - 1)));
                --i;
            }
        }
        return res;
    }
};
int main() {
    Solution s;
    vector<int> a = {2,3,1};
    int res = s.largestRectangleArea(a);
    cout<<res;
    return 0;
}




