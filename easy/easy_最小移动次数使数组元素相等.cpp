/*
* Author:czj
* Time:  2019/8/21 08:59
*给定一个长度为 n 的非空整数数组，找到让数组所有元素相等的最小移动次数。每次移动可以使 n - 1 个元素增加 1。
示例:
输入:
[1,2,3]
输出:
3
解释:
只需要3次移动（注意每次移动会增加两个元素的值）：
[1,2,3]  =>  [2,3,3]  =>  [3,4,3]  =>  [4,4,4]
*/
/**
 * n-1个元素加1， 相当于最大值元素减去1， 这样推导下去就是，不断的让最大的元素减去1，直到其与
 * 最小值相等就可以了  return 数组的和 - 数组中最小的值*数组的长度
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
    int minMoves(vector<int>& a) {
        int m = *max_element(a.begin(), a.end());//求一个数组的最小值
        int n = *min_element(a.begin(), a.end());
        long sum = 0;
        for(int i=0; i<a.size(); i++)
            sum += a[i];
        return sum-n*a.size();
    }
};
int main(){
    Solution s;
    vector<int> a = {1,1,2147483647};
//    int res = *max_element(a.begin(), a.end());
    cout<<s.minMoves(a)<<endl;
    return 0;
}

