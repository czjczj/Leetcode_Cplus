/*
* Author:czj
* Time:  2019/8/20 09:24
*在二维空间中有许多球形的气球。对于每个气球，提供的输入是水平方向上，气球直径的开始和结束坐标。由于它是
水平的，所以y坐标并不重要，因此只要知道开始和结束的x坐标就足够了。开始坐标总是小于结束坐标。平面内最多存在104个气球。
一支弓箭可以沿着x轴从不同点完全垂直地射出。在坐标x处射出一支箭，若有一个气球的直径的开始和结束坐标为 xstart，xend，
 且满足  xstart ≤ x ≤ xend，则该气球会被引爆。可以射出的弓箭的数量没有限制。 弓箭一旦被射出之后，可以无限地前进。我们想
 找到使得所有气球全部被引爆，所需的弓箭的最小数量。
Example:
输入:
[[10,16], [2,8], [1,6], [7,12]]
输出:
2
解释:
对于该样例，我们可以在x = 6（射爆[2,8],[1,6]两个气球）和 x = 11（射爆另外两个气球）。
*/
/**
 * 解题思路：  这题需要很好的观察力，
 * 1.第一个能够想到的是：  按照每个 pair 第一个下标位置和第二个下标的升序排列
 * 2.第二个使用到堆栈。  判断会加一的情况。   例如
 *      1---------6
 *       2----------8
 *    如上图，我们是无法现在需要将  箭 加 1的， 此时两个位置由重叠[2,6]
 *      1---------6
 *       2----------8
 *                 7-------12
 *     这个时候 前两个位置的重叠 【2，6】和当前的插入[7,12]没有了重叠， 这个时候 箭 需要加1
 * 3.同样的按照这样我们继续向下判断，最后返回 箭+1；
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
bool cmp(pair<int, int> a, pair<int, int> b){
    if(a.first == b.first)
        return a.second<b.second;
    return a.first<b.first;
}
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& p) {
        if(p.size() == 0)
            return 0;
        vector<pair<int, int>> pairs;
        for(int i=0; i<p.size(); i++){
            pair<int, int> tmp(p[i][0], p[i][1]);
            pairs.push_back(tmp);
        }
        sort(pairs.begin(), pairs.end(), cmp);
//        cout<<pairs[0].first<<pairs[0].second<<endl;
        stack<pair<int, int>> s;
        int cnt = 0;
        vector<pair<int, int>>::iterator it = pairs.begin();
        for(int i=0; i<pairs.size(); i++){
            if(s.empty())
                s.push(pairs[i]);
            pair<int, int> t = s.top(); s.pop();
            if(pairs[i].first > t.second){
                cnt++;
                s.push(pairs[i]);
            }
            else
                s.push(make_pair(pairs[i].first, min(pairs[i].second, t.second)));
        }
        return cnt+1;
    }
};
int main(){
    Solution s;
    vector<vector<int>> v = {{10,16}, {2,8}, {1,6}, {7,12}};
    cout<<s.findMinArrowShots(v)<<endl;
    return 0;
}

