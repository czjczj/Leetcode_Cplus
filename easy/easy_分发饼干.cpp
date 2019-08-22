/*
* Author:czj
* Time:  2019/8/22 13:21
* 假设你是一位很棒的家长，想要给你的孩子们一些小饼干。但是，每个孩子最多只能给一块饼干。对每个孩子 i ，都有一个胃口值 gi ，
* 这是能让孩子们满足胃口的饼干的最小尺寸；并且每块饼干 j ，都有一个尺寸 sj 。如果 sj >= gi ，我们可以将这个饼干 j 分配
* 给孩子 i ，这个孩子会得到满足。你的目标是尽可能满足越多数量的孩子，并输出这个最大数值。
    注意：
    你可以假设胃口值为正。
    一个小朋友最多只能拥有一块饼干。
    示例 1:
    输入: [1,2,3], [1,1]
    输出: 1
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
int cmp(int a, int b){ return a>b;}
/**
 * 贪心思想：用尽量小的饼干去满足小需求的孩子
 */
class Solution {
public:
    int findContentChildren(vector<int>& s, vector<int>& g) {
        sort(g.begin(), g.end(), cmp);
        sort(s.begin(), s.end(), cmp);
        int cnt = 0;
        int j = 0;
        for(int i=0; i<g.size(); i++){
            int flag = false;
            for(; j<s.size(); j++){
                if(g[i] >= s[j]){
                    cnt++;
                    flag = true;
                    j++;
                    break;
                }
            }
            if(!flag)
                break;
        }
        return cnt;
    }
};
int main(){
    Solution s;
    vector<int> a = {10,9,8,7};
    vector<int> b = {5,6,7,8};
    cout<<s.findContentChildren(a, b);
    return 0;
}

