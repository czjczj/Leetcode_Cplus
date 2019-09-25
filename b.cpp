#include <iostream>
#include <map>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;
class Solution {
public:
    string removeKdigits(string a, int k) {
        stack<char> s;
        string res = "";
        for(int i=0; i<a.size();i++){
            if(k==0)
                break;
            if(s.empty() || s.top()<a[i]){
                s.push(a[i]);
            }else{
                while(k>0 && s.top()>=a[i] && !s.empty()){
                    k--;
                    s.pop();
                }
                i--;
            }
        }
        cout<<s.size()<<" ";
        int flag = 0;
        for(int i=0; i<s.size(); i++){
            res = s.top() + res;
            s.pop();
        }
        string r = "";
        for(int i=0; i<res.size(); i++){
            if(res[i]=='0' && flag==0){
                continue;
            }else{
                flag = 1;
                r = r+res[i];
            }
        }
        return r;
    }
};
int main() {
    Solution s;
    vector<int> a = {1,0,2,3,4};
    string res = s.removeKdigits("1432219",3);
    cout<<res;
    return 0;
}


