/*
* Author:czj
* Time  :2019/09/23 11:28
* Email :zj_cheng@csu.edu.cn
* 数组arr是[0, 1, ..., arr.length - 1]的一种排列，我们将这个数组分割成几个“块”，并将这些块分别进行排序。
之后再连接起来，使得连接的结果和按升序排序后的原数组相同。
我们最多能将数组分成多少块？
示例 1:
输入: arr = [4,3,2,1,0]
输出: 1
解释:
将数组分成2块或者更多块，都无法得到所需的结果。
例如，分成 [4, 3], [2, 1, 0] 的结果是 [3, 4, 0, 1, 2]，这不是有序的数组。
链接：https://leetcode-cn.com/problems/max-chunks-to-make-sorted
*/
#include <iostream>
#include <map>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;
class Solution {
public:
    /**
     * 方法3： 排序的时间复杂度为 O(n)
     * 理解一下：保存一个单调递增的栈，当出现 a[i]<s[s.top()]
     * 表示该元素会影响前面的块，  保存curMax=s.top（即为当前块中的最大元素）
     * 当 s为空的时候，或者s.top()>a[i]的时候，在重新将元素压会到栈中去。
     */
    int maxChunksToSorted3(vector<int>& arr) {
        stack<int> st;
        for (int i = 0; i < arr.size(); ++i) {
            if (st.empty() || st.top() <= arr[i]) {
                st.push(arr[i]);
            } else {
                int curMax = st.top(); st.pop();
                while (!st.empty() && st.top() > arr[i]) st.pop();
                st.push(curMax);
            }
        }
        return st.size();
    }
    /**
     * 方法2： 排序的时间复杂度为 O(n)
     * 考虑给定数组 a [4,1,3,2,6,5]
     * 排序后的数组 b [1 2 3 4 5 6]
     * 考虑下这个问题的本质：
     * 假设当前遍历到的位置为 i, 那么也就是说如果 a[0...i]数组中的最大值
     * 如果小于或者等于 a[i+1...end]的最小值的话，那么就可以形成一个块了。
     *
     * 解题思路：浪费一下空间
     */
    int maxChunksToSorted2(vector<int>& a) {
        vector<int> b(a.size(),0);
        vector<int> c(a.size(),0);
        int n_min = INT32_MAX;
        int n_max = INT8_MIN;
        for(int i=0; i<a.size(); i++){
            if(a[i]>n_max){
                n_max = a[i];
            }
            b[i] = n_max;
        }
        for(int i=a.size()-1; i>=0; i--){
            c[i] = n_min;
            if(a[i]<n_min){
                n_min = a[i];
            }
        }
//        for(int i=0; i<a.size(); i++){
//            cout<<b[i]<<" ";
//        }
//        cout<<endl;
//        for(int i=0; i<a.size(); i++){
//            cout<<c[i]<<" ";
//        }
//        cout<<endl;
        int res = 0;
        for(int i=0; i<a.size(); i++){
            if(b[i] <= c[i])
                res++;
        }
        return res;
    }

    /**
     * 方法1： 排序的时间复杂度为 nlog(n)
     * 考虑给定数组 a [4,1,3,2,6,5]
     * 排序后的数组 b [1 2 3 4 5 6]
     * 即如果  a[0...i] = b[0...i] 那么 就可以形成一个块
     */
    int maxChunksToSorted1(vector<int>& a) {
        vector<int> b = a;
        int res = 0;
        sort(b.begin(), b.end());
        int s1 = 0;
        int s2 = 0;
        for (int i = 0; i < a.size(); i++) {
            s1 += a[i];
            s2 += b[i];
            if (s1 == s2)
                res++;
        }
        return res;
    }
};
int main() {
    Solution s;
    vector<int> a = {1,0,2,3,4};
    int res = s.maxChunksToSorted2(a);
    cout<<res;
    return 0;
}




