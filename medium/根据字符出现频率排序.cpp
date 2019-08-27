/*
* Author:czj
* Time:  2019/8/27 09:36
*   给定一个字符串，请将字符串里的字符按照出现的频率降序排列。
    示例 1:
    输入:
    "tree"
    输出:
    "eert"
    解释:
    'e'出现两次，'r'和't'都只出现一次。
    因此'e'必须出现在'r'和't'之前。此外，"eetr"也是一个有效的答案。
*/
/**
 * 解题思路： 用map 保存下每一个元素出现的次数，进行排序，输出
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
bool cmp(const pair<char, int>& p1, const pair<char, int>& p2){
    return p1.second > p2.second;
}
class Solution {
public:
    string frequencySort(string s) {
        map<char, int> m;
        vector<pair<char,int>> arr;
        for(auto c:s){
            m[c]++;
        }
        for(map<char, int>::iterator it=m.begin(); it!=m.end(); it++){
            arr.push_back(make_pair(it->first, it->second));
        }
        sort(arr.begin(), arr.end(), cmp);
        string r = "";
        for(int i=0; i<arr.size(); i++){
            pair<char, int> tmp = arr[i];
            char c = tmp.first;
            int num = tmp.second;
            for(int k=0; k<num; k++){
                r += c;
            }
        }
        return r;
    }
};
int main(){
    Solution s;
    cout<<s.frequencySort("Aabb")<<endl;
    return 0;
}


