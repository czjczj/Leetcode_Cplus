#include <iostream>
#include <string>
#include <queue>
using namespace std;
class Solution {
public:
    int firstUniqChar(string s) {
        if(s.length() == 0)
            return -1;
        int a[26];
        fill(a,a+26,0);
        int b = s.length();
        for(int i=s.length()-1; i>=0; i--){
            a[s[i]-'a'] += 1;
        }
        for(int i=s.length()-1; i>=0; i--){
            if(a[s[i]-'a'] == 1)
                b = i;
        }
        if(b == s.length())
            return -1;
        return b;
    }
};
//int a[9664][9664];
int main(){
    Solution s;
    int a = s.firstUniqChar("loveleetcode");
    cout<<a<<endl;
    return 0;
}
