/*
* Author:czj
* Time:  2019/8/18 10:00
*/
/**
 * 解题思路：可以看做固定数量容器在固定容量下的 填充问题， 动态规划
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
bool cmp(int a, int b){
    return a>b;
}
class Solution {
public:
    //方法一： 自己的方法
    bool makesquare(vector<int>& a) {
        int sum = 0;
        int tong[4];
        fill(tong,tong+4,0);
        for(int i=0; i<a.size(); i++){
            sum += a[i];
        }
        int t = sum/4;
        if(sum%4 != 0)
            return false;
        sort(a.begin(), a.end(), cmp);
        if(a[0] > t)
            return false;
        map<string, bool> dp;
        return dfs(0, t, a, tong); //idx, target
    }
    //方法二：别人想到的方法
    bool makesquare2(vector<int>& a) {
        if(nums.size()<4)   return false;
        int sum=accumulate(nums.begin(),nums.end(),0);
        if(sum%4)   return false;                               //余数不为零一定不能构成

        sort(nums.begin(),nums.end(),greater<int>());           //升序排序，贪心选择长的构建边
        for(int i=0;i<3;++i)                                    //只需判断是否构建出3条长为sum/4的边长
        {
            if(!dfs2(nums,sum/4))    return false;
        }
        return true;
    }
}
bool dfs2(vector<int>& a, int sum){
    if(sum == 0) return true;
    for(int i=0; i<a.size(); i++){
        if(a[i] > sum) return false;  //因为是按照降序排列的
        if(a[i] > 0){
            a[i] = -a[i];  //将数据进行标记，判断该数据是否已经使用过
            if(dfs2(a, sum-abs(a[i])))
                return true;
//                a[i] = -a[i];
        }
    }
    return false;
}

bool dfs(int idx, int t, vector<int>& a, int* tong){
    if(idx == a.size()){
        for(int i=0; i<4; i++){
            if(tong[i] != t)
                return  false;
        }
        return true;
    }
    bool flag = false;
    //判断使用那个 tong  装
    for(int i=0; i<4; i++){
        if(tong[i] + a[idx] <= t){
            tong[i] += a[idx];
            flag |= dfs(idx+1, t, a, tong);  //我自己的这里应该是一判断到 flag 为true 就停止就可以了，没有必要继续向下
            if(flag)
                return true;
            tong[i] -= a[idx];
        }
    }
    return flag;
}
};
int main(){
    Solution s;
    vector<int> v = {1,1,2,2,2};
    cout<<s.makesquare2(v)<<endl;
    return 0;
}