/*
* Author:czj
* Time:  2019/8/19 08:46
*
*/
/**
 * 解题思路首先一个字符串t重复N次后得到重复字符串s， 那么s = N * t，那么这样的重复字符串
 * 截取t后得到的字符串也是重复字符串。
然后得到s1 = s+s，现在的s1 = 2N * t，有2N个t组成。
现在把s1的前后减去一个字符，那么前后的两个t就不再作为重复子字符串而存在了，此时s1相当于(2N-2)*t，
 如果此时s1中依然能够找到s，说明s完全由t组成。

 */
#include <iostream>
using namespace std;
class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        return (s+s).substr(1,(s+s).length()-2).find(s) != -1;
    }
};
int main() {
    return 0;
}


