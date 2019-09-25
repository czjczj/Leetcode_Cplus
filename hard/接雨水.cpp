/*
* Author:czj
* Time  :2019/09/23 10:32
* Email :zj_cheng@csu.edu.cn
*/
#include <iostream>
#include <map>
#include <vector>
#include <queue>
#include <stack>
/**
 * 阶梯思路，单调递减栈：
 * 1.为什么是单调递减栈？
 *   因为通过观察我们可以发现，当出现一个 右边一个值大于左边值的时候，
 *   那么就就可能出现一个水哇 例如  3 2 4  4>2 左边可能形成水哇
 *   维持一个单调递减的栈
 * 2.当出现压入栈的元素大于栈顶元素（即不再单调递减的时候的操作）
 *   依照当前元素为右边的时候，左边的元素个数至少为2个才可以形成水哇，
 *   因此需要出栈两次进行分析，相当于找到左边第一大于  这个水哇的数字，
 *   计算左右边界的最小值 min(left, right)-水哇高度  在乘以水哇长度就可以了。
 */
using namespace std;
class Solution {
public:
    int trap(vector<int>& h) {
        stack<int> s;
        int res = 0;
        for(int i=0; i<h.size(); i++){
            if(s.empty() || h[s.top()]>=h[i]){
                s.push(i);
            }else{
                int mid = s.top(); s.pop();
                if(s.empty()){
                    i--;
                    continue;
                }
                int left = s.top();
                res += (min(h[left],h[i])-h[mid])*(i-left-1);
                i--;
            }
        }
        return res;
    }
};
int main() {
    Solution s;
    vector<int> a = {0,1,0,2,1,0,1,3,2,1,2,1};
    int res = s.trap(a);
    cout<<res;
    return 0;
}


