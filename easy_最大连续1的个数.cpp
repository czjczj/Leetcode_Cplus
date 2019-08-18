/*
* Author:czj
* Time:  2019/8/18 09:23
*
*/
#include <iostream>
#include <string>
#include <algorithm>
#include <stack>
#include <vector>
#include <cmath>
#include <set>
using namespace std;
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& a) {
        int rtn = 0;
        int cnt = 0;
        for(int i=0; i<a.size(); i++){
            if(a[i] == 1){
                cnt++;
            }else{
                rtn = max(rtn, cnt);
                cnt = 0;
            }
        }
        rtn = max(rtn, cnt);
        return rtn;
    }
};
int main(){
    Solution s;
    cout<<s.countSubstrings("aaa")<<endl;
    return 0;
}

