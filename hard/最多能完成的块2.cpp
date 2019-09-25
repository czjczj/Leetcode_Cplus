/*
* Author:czj
* Time  :2019/09/23 14:51
* Email :zj_cheng@csu.edu.cn
这个问题和“最多能完成排序的块”相似，但给定数组中的元素可以重复，输入数组最大长度为2000，其中的元素最大为10**8。
arr是一个可能包含重复元素的整数数组，我们将这个数组分割成几个“块”，并将这些块分别进行排序。之后再连接起来，使得
连接的结果和按升序排序后的原数组相同。
我们最多能将数组分成多少块？
示例 1:
输入: arr = [5,4,3,2,1]
输出: 1
解释:
将数组分成2块或者更多块，都无法得到所需的结果。
例如，分成 [5, 4], [3, 2, 1] 的结果是 [4, 5, 1, 2, 3]，这不是有序的数组。
链接：https://leetcode-cn.com/problems/max-chunks-to-make-sorted-ii
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
     * 方法2： 排序的时间复杂度为 O(n)
     * 考虑给定数组 a [4,1,3,2,6,5]
     * 排序后的数组 b [1 2 3 4 5 6]
     * 考虑下这个问题的本质：
     * 假设当前遍历到的位置为 i, 那么也就是说如果 a[0...i]数组中的最大值
     * 如果小于或者等于 a[i+1...end]的最小值的话，那么就可以形成一个块了。
     *
     * 解题思路：浪费一下空间
     */
    int maxChunksToSorted3(vector<int>& a) {

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



