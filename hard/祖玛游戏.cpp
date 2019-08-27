/*
* Author:czj
* Time:  2019/8/24 09:09
*回忆一下祖玛游戏。现在桌上有一串球，颜色有红色(R)，黄色(Y)，蓝色(B)，绿色(G)，还有白色(W)。 现在你手里也有几个球。

每一次，你可以从手里的球选一个，然后把这个球插入到一串球中的某个位置上（包括最左端，最右端）。接着，如果有出现三个或者三个以上颜色相同的球相连的话，就把它们移除掉。重复这一步骤直到桌上所有的球都被移除。

找到插入并可以移除掉桌上所有球所需的最少的球数。如果不能移除桌上所有的球，输出 -1 。

示例:
输入: "WRRBBW", "RB"
输出: -1
解释: WRRBBW -> WRR[R]BBW -> WBBW -> WBB[B]W -> WW （翻译者标注：手上球已经用完，桌上还剩两个球无法消除，返回-1）
*/
#include <iostream>
#include <string>
#include <algorithm>
#include <stack>
#include <vector>
#include <cmath>
#include <set>
#include <map>
/**
 * 解题思路：
 * 1.  统计hand 中  每个字符的剩余次数
 * 2.  遍历 board  去除里面连续的 3个及以上字符
 * 3.  遍历 board 递归调用里面的两个连续字符
 */
using namespace std;
#define INT_MAX 100000
class Solution {
public:
    int findMinStep(string board, string hand) {
        int res = INT_MAX;
        map<char, int> m;
        for (char c : hand) ++m[c];
        res = helper(board, m);
        return res == INT_MAX ? -1 : res;
    }
    int helper(string board, map<char, int>& m) {
        board = removeConsecutive(board);
        if (board.empty()) return 0;
        int cnt = INT_MAX, j = 0;
        for (int i = 0; i <= board.size(); ++i) {
            if (i < board.size() && board[i] == board[j]) continue;
            int need = 3 - (i - j);
            if (m[board[j]] >= need) {
                m[board[j]] -= need;
                int t = helper(board.substr(0, j) + board.substr(i), m);
                if (t != INT_MAX) cnt = min(cnt, t + need);
                m[board[j]] += need;
            }
            j = i;
        }
        return cnt;
    }
    string removeConsecutive(string board) {
        for (int i = 0, j = 0; i <= board.size(); ++i) {
            if (i < board.size() && board[i] == board[j]) continue;
            if (i - j >= 3) return removeConsecutive(board.substr(0, j) + board.substr(i));
            else j = i;
        }
        return board;
    }
};
int main(){
    Solution s;
    cout<<s.findMinStep("WRRBBW", "RB")<<endl;
    return 0;
}




