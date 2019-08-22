/*
* Author:czj
* Time:  2019/8/20 08:38
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
     * 我的方法会超过内存限制
     */
    string licenseKeyFormatting(string S, int K) {
        string s = "";
        for(int i=0; i<S.length(); i++){
            if(S[i]=='-')
                continue;
            if(S[i]>='a' && S[i]<='z'){
                s += (char)('A'+(S[i]-'a'));
                continue;
            }
            s += S[i];
        }
        string rtn = "";
        string tmp = "";
        for(int i=s.length()-1 ; i>=0; i--){
            if(tmp.length() >= K){
                if(rtn.length() != 0)
                    rtn = tmp+"-"+rtn;
                else
                    rtn = tmp;
                tmp = "";
            }
            tmp = s[i]+tmp;
        }
        if(tmp.length() != 0)
            if(rtn != "")
                rtn = tmp+"-"+rtn;
            else
                rtn = tmp;
        return rtn;
    }
    /**
     * 方法二： 别人的方法
     */
    string licenseKeyFormatting2(string S, int K) {
        int num = K- (S.size() - count(S.begin(), S.end(), '-')) % K;
        string rst = "";
        for (auto c : S)
        {
            if (c == '-') continue;
            if (num == 0 && rst != "") rst += '-';

            rst += toupper(c);
            num = (num + 1) % K;
        }
        return rst;
    }
};
int main(){
    Solution s;
    string S = "-";
    int K = 2;
    cout<<s.licenseKeyFormatting2(S, K)<<endl;
    return 0;
}


