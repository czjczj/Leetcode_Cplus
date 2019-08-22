/*
* Author:czj
* Time:  2019/8/19 09:46
*给定一个整数序列：a1, a2, ..., an，一个132模式的子序列 ai, aj, ak 被定义为：当 i < j < k 时，ai < ak < aj。
 * 设计一个算法，当给定有 n 个数字的序列时，验
 * 证这个序列中是否含有132模式的子序列。
注意：n 的值小于15000。
示例1:
输入: [1, 2, 3, 4]
解释: 序列中不存在132模式的子序列。
示例 2:
输入: [3, 1, 4, 2]
输出: True
解释: 序列中有 1 个132模式的子序列： [1, 4, 2].
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
    /**
     * 网上题解的另外一种方法，感觉自己是一个sb,....。因为是求解一个存在的问题。
     * 所以  我们可以设定求解的过程，给定其中的三个模式   i, j, k
     * i的开始： 使得i尽可能的小，  从左到右第一个不持续增大的数字，比如  3,2,1,5 则取1
     * j的开始： 使得i+1后面，  从左到右的第一个不持续减小的数字， 比如  1,2,3,4,3  则取4
     * z的开始： 从 j+1 后面开始，  找到满足条件的 即可返回 true
     */
    bool find132pattern(vector<int>& a) {
        int i = 0;
        int j = 0;
        int k = 0;
        int n = a.size();
        while(i<n-2){
            while(i<n-2 && a[i]>a[i+1]){
                i++;
            }
            j = i+1;
            while(j<n-1 && a[j]<a[j+1]){
                j++;
            }
            k = j+1;
            while(k<n){
                if(a[i]<a[k] && a[k]<a[j])
                    return true;
                k++;
            }
            i = j+1;
        }
        return false;
    }

    /**
     * 自己的方法， LeetCode 提示 heap_overflow 本地可以运行，不知道为什么
     */
    bool find132pattern1(vector<int>& a) {
        return dfs1(-1,-1,0,a);
    }
    bool dfs1(int a, int b, int idx, vector<int>& s){

        if(a!=-1 && b!=-1 && (a<s[idx] && s[idx]<b && idx<s.size()))
            return true;
        if(idx >= s.size())
            return false;
        bool flag = false;

        if(dfs1(s[idx], 0, idx+1, s))
            return true;
        if(dfs1(a, s[idx], idx+1, s))
            return true;
        return dfs1(a, b, idx+1, s);
    }
};
int main(){
    Solution s;
    vector<int> a = {3,5,0,3,4};
    vector<int> b = {1,2,3,4};
    cout<<s.find132pattern(b)<<endl;
    return 0;
}

