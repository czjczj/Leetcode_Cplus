/*
* Author:czj
* Time:  2019/8/29 08:33
*如果序列 X_1, X_2, ..., X_n 满足下列条件，就说它是 斐波那契式 的：
n >= 3
对于所有 i + 2 <= n，都有 X_i + X_{i+1} = X_{i+2}
给定一个严格递增的正整数数组形成序列，找到 A 中最长的斐波那契式的子序列的长度。如果一个不存在，返回  0 。
示例 1：
输入: [1,2,3,4,5,6,7,8]
输出: 5
解释:
最长的斐波那契式子序列为：[1,2,3,5,8]
来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/length-of-longest-fibonacci-subsequence
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

    /**
     * 暴力的方法： 时间复杂度 n^2Log(n)  每次递归的遍历两个首元素
     * 依照此元素判断产生的值大小。
     */
    int lenLongestFibSubseq(vector<int>& a) {
        int n = a.size();
        int r = 2;
        if(n<3) {
            return 0;
        }
        for(int i=0; i<n-2; i++){
            for(int j=i+1; j<n-1; j++){
                int l = a[i];
                int m = a[j];
                int len = 2;
                while(true){
                    int t = l+m;
                    int idx = binary_search(a.begin(), a.end(), t);
                    if(idx == 0)
                        break;
                    l = m;
                    m = t;
                    len++;
                }
                r = max(r, len);
            }
        }
        if(r == 2)
            return 0;
        return r;
    }
};
int main(){
    vector<int> a = {1,3,7,11,12,14,18};
    Solution s;
    cout<<s.lenLongestFibSubseq(a);
    return 0;
}

