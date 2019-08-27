/*
* Author:czj
* Time:  2019/8/23 08:14
*冬季已经来临。 你的任务是设计一个有固定加热半径的供暖器向所有房屋供暖。
现在，给出位于一条水平线上的房屋和供暖器的位置，找到可以覆盖所有房屋的最小加热半径。
所以，你的输入将会是房屋和供暖器的位置。你将输出供暖器的最小加热半径。
给出的房屋和供暖器的数目是非负数且不会超过 25000。
给出的房屋和供暖器的位置均是非负数且不会超过10^9。
只要房屋位于供暖器的半径内(包括在边缘上)，它就可以得到供暖。
所有供暖器都遵循你的半径标准，加热的半径也一样。
示例 1:
输入: [1,2,3],[2]
输出: 1
解释: 仅在位置2上有一个供暖器。如果我们将加热半径设为1，那么所有房屋就都能得到供暖。
*/
#include <iostream>
#include <string>
#include <algorithm>
#include <stack>
#include <vector>
#include <cmath>
#include <set>
#include <map>
#define MAX_VALUE 1e9
using namespace std;
class Solution {
public:
    /**
     * 方法1： 遍历的寻找每一个房子的上下边界,
     * 这里的 p=0 放在外面和不放在外面区别是很大的，不放在外面的话就会超时
     * 放在外面的原因 例如
     * house:  1 3 5 7 9 10 11
     * heats     3   7   10
     * 这里如果说 house 房间从小到大遍历的话   如果前面有一个数字  已经访问到 p=7了，  那么对于该house
     * 后面的数字而言，重新开始的位置p将不是0，  而是从 p=7 开始
     */
    int findRadius2(vector<int>& a, vector<int>& b) {
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        int rtn = 0;
        int len = b.size();
        int p = 0;
        for(int i=0; i<a.size(); i++){

            while(p<len){
                if(b[p] < a[i]){
                    p++;
                }else{
                    break;
                }
            }
            int k1 = MAX_VALUE;
            if(p<len)
                k1 = min(k1,b[p]-a[i]);
            if(p>0)
                k1 = min(k1,a[i]-b[p-1]);
            rtn = max(k1,rtn);
        }
        return rtn;
    }
    /**
     * 方法2： 二分查找
     */
    int findRadius(vector<int>& a, vector<int>& b) {
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        int rtn = 0;
        int p = 0;
        for(int i=0; i<a.size(); i++){
            int idx = a[i];
            int t = binarySearch(b,p,b.size()-1,idx);
            if(b[t]==idx){
                rtn = max(0,rtn);
                p = t;
            }
            else{
                int m = 1e9;
                m = min(m, abs(idx-b[t]));
                if(t-1<b.size())
                    m = min(m, abs(idx-b[t-1]));
                rtn = max(m, rtn);
            }
        }
        return rtn;
    }
    int binarySearch(vector<int> v, int s, int e, int t){
        while(s<=e){
            int idx = (e+s)/2;
            int mid = v[idx];
            if(mid == t)
                return idx;
            else if(mid > t){
                e = idx-1;
            }else{
                s = idx+1;
            }
        }
        return s;
    }
};
int main(){
    Solution s;
    vector<int> a = {1,2,3};
    vector<int> b = {2};
    cout<<s.findRadius(a, b);
    return 0;
}

