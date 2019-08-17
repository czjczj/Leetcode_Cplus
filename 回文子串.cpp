/*
* Author:czj
* Time:  2019/8/17 13:07
*给定一个字符串，你的任务是计算这个字符串中有多少个回文子串。
具有不同开始位置或结束位置的子串，即使是由相同的字符组成，也会被计为是不同的子串。
示例 1:
输入: "abc"
输出: 3
解释: 三个回文子串: "a", "b", "c".
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
    //解法1： 哨兵法， 从当前位置向左右两个方向 扩散，  因为回文子串要保证其内部也是回文的
    //这个时候需要判断两种情况， n为偶数或者奇数的情况。
    int countSubstrings(string s) {
        int result = 0;
        for(int i=0;i<len;i++)
        {
            for(int j=i,k=i;j<len&&k>=0;j++,k--)
            {
                if(s[j]==s[k])
                    result++;
                else
                    break;
            }
            for(int j=i+1,k=i;j<len&&k>=0;j++,k--)
            {
                if(s[j]==s[k])
                    result++;
                else
                    break;
            }
        }
        return result;
    }
    //方法二： 暴力破解，两个for循环分别对应，start的下标和 end的下标然后判断 该子串是否是回文串
    int countSubstrings2(string s) {
        int cnt = 0,  len = s.length();
        for (int i = 0; i < len; i++) {
            for (int j = i; j < len; j++) {
                bool equals = true;
                int ni = i, nj = j;
                while (ni <= nj) {
                    if (s[ni++] != s[nj--]) {
                        equals = false;
                        break;
                    }
                }
                if (equals) cnt++;
            }
        }
        return cnt;
    }
};
int main(){
    Solution s;
    cout<<s.countSubstrings("aaa")<<endl;
    return 0;
}

