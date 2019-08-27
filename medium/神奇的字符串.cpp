/*
* Author:czj
* Time:  2019/8/24 08:44
* 神奇的字符串 S 只包含 '1' 和 '2'，并遵守以下规则：
    字符串 S 是神奇的，因为串联字符 '1' 和 '2' 的连续出现次数会生成字符串 S 本身。
    字符串 S 的前几个元素如下：S = “1221121221221121122 ......”
    如果我们将 S 中连续的 1 和 2 进行分组，它将变成：
    1 22 11 2 1 22 1 22 11 2 11 22 ......
    并且每个组中 '1' 或 '2' 的出现次数分别是：
    1 2 2 1 1 2 1 2 2 1 2 2 ......
    你可以看到上面的出现次数就是 S 本身。
    给定一个整数 N 作为输入，返回神奇字符串 S 中前 N 个数字中的 '1' 的数目。
    注意：N 不会超过 100,000。
    示例：
    输入：6
    输出：3
    解释：神奇字符串 S 的前 6 个元素是 “12211”，它包含三个 1，因此返回 3。
*/
/**
 * 不断按照 b 数组中的值，在 a 数组后面进行扩充，然后移动下标，扩充 b 数组的值
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
    int magicalString(int n) {
        vector<int> a;
        vector<int> b;
        a.push_back(1);
        b.push_back(1);
        int i = 1;
        while(i < n){
            if(b[b.size()-1] == 1){
                if(a[a.size()-1] == 1)
                    a.push_back(2);
                else
                    a.push_back(1);
                b.push_back(a[i]);
                i++;
            }else {
                if (a[a.size() - 1] == 1) {
                    a.push_back(1);
                    a.push_back(2);
                } else {
                    a.push_back(2);
                    a.push_back(1);
                }
                b.push_back(a[i]);
                i++;
            }
        }
        int cnt = 0;
        for(int k=0; k<n; k++){
            if(b[k]==1)
                cnt++;
        }
        return cnt;
    }
};
int main(){
    Solution s;
    cout<<s.magicalString(6)<<endl;
    return 0;
}



