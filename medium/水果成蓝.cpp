/*
* Author:czj
* Time:  2019/8/20 10:18
*在一排树中，第 i 棵树产生 tree[i] 型的水果。
你可以从你选择的任何树开始，然后重复执行以下步骤：
把这棵树上的水果放进你的篮子里。如果你做不到，就停下来。
移动到当前树右侧的下一棵树。如果右边没有树，就停下来。
请注意，在选择一颗树后，你没有任何选择：你必须执行步骤 1，然后执行步骤 2，然后返回步骤 1，然后执行步骤 2，依此类推，直至停止。
你有两个篮子，每个篮子可以携带任何数量的水果，但你希望每个篮子只携带一种类型的水果。
用这个程序你能收集的水果总量是多少？
示例 1：
输入：[1,2,1]
输出：3
解释：我们可以收集 [1,2,1]。
*/
/**
 * 解题思路：  这一题的关键之处在于，我们从前先后的过程中，在遇到下一次遍历的时候，不是回到原来的位置加1处，
 * 例如：  3,3,3,1,2,1,1,2,3,3,4  就这一个序列而言
 *  1. 我们开始  3->3->3->1  这个时候的结果是4， 然后我们进行下一次的迭代，  这个迭代不是从 第二个3开始了，
 *     而是从  我们停止的位置 1，  向前数 到第一个不同与 1的位置
 *  2. 那么我们第二次遍历的位置是从  1->2->1->1->2  结果5。 这样子的
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
    int totalFruit(vector<int>& tree) {
        int cnt[2];
        int rtn = 0;
        int j = 0;
        for(int i=0; i<tree.size(); ){
            int num = 0;
            fill(cnt, cnt+2, -1);
            while(j<tree.size()){
                if(cnt[0]==-1){
                    cnt[0] = tree[j];
                    num++;
                }else if(tree[j] != cnt[0] && cnt[1]==-1){
                    cnt[1] = tree[j];
                    num++;
                }else{
                    if(tree[j]==cnt[0] || tree[j]==cnt[1]){
                        num++;
                    }else{
                        rtn = max(rtn, num);
                        num = 0;
                        break;
                    }
                }
                j++;
            }
            if(j==tree.size()){
                rtn = max(rtn, num);
                i++;
                int j = i;
            }else{
                j--;
                while(j>=0 && tree[j-1]==tree[j])
                    j--;
            }
        }
        return rtn;
    }
};
int main(){
    Solution s;
    vector<int> a = {3,3,3,1,2,1,1,2,3,3,4};
    cout<<s.totalFruit(a)<<endl;
    return 0;
}

