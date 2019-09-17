/*
* Author:czj
* Time  :2019/09/16 14:25
* Email :zj_cheng@csu.edu.cn
*/
#include <iostream>
#include <vector>
#include <map>
using namespace std;
class Solution {
public:
    bool checkSubarraySum(vector<int>& a, int k) {
        int n = a.size();
        vector<int> sum(n,0);
        int s = 0;
        for(int i=0; i<n; i++){
            s += a[i];
            sum[i] = s;
        }
        map<int, int> m;
        for(int i=0; i<n; i++){
            int tmp = sum[i];
            if(k!=0)
                tmp = sum[i]%k;
            if(m.count(tmp) != 0 && i-m[tmp]>=1)
                return true;
            m[tmp] = i;
        }
        return false;
    }
};
int main() {
    Solution s;
    vector<int> v = {0,0};
    int k = 0;
    cout<<s.checkSubarraySum(v,k);
    return 0;
}


