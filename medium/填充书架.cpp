/*
* Author:czj
* Time  :2019/09/16 14:24
* Email :zj_cheng@csu.edu.cn
*/
/**
附近的家居城促销，你买回了一直心仪的可调节书架，打算把自己的书都整理到新的书架上。
你把要摆放的书 books 都整理好，叠成一摞：从上往下，第 i 本书的厚度为 books[i][0]，高度为 books[i][1]。
按顺序 将这些书摆放到总宽度为 shelf_width 的书架上。
先选几本书放在书架上（它们的厚度之和小于等于书架的宽度 shelf_width），然后再建一层书架。重复这个过程，直到把所有的书都放在书架上。
需要注意的是，在上述过程的每个步骤中，摆放书的顺序与你整理好的顺序相同。 例如，如果这里有 5 本书，那么可能的一种摆放情况是：第一和第二
 本书放在第一层书架上，第三本书放在第二层书架上，第四和第五本书放在最后一层书架上。
每一层所摆放的书的最大高度就是这一层书架的层高，书架整体的高度为各层高之和。
以这种方式布置书架，返回书架整体可能的最小高度。

输入：books = [[1,1],[2,3],[2,3],[1,1],[1,1],[1,1],[1,2]], shelf_width = 4
输出：6
解释：
3 层书架的高度和为 1 + 3 + 2 = 6 。
第 2 本书不必放在第一层书架上。

链接：https://leetcode-cn.com/problems/filling-bookcase-shelves
 */
class Solution{
public:
    vector<vector<int>> b;
    int width = 0;
    int minHeightShelves(vector<vector<int>>& bb, int w) {
        int n = bb.size();
        b = bb;
        width = w;

        int res = dfs(0,0,0);
        return res;
    }
    //方法超时
    int dfs(int idx, int w, int max_h){
        if(idx == b.size()){
            return max_h;
        }
        int res = INT32_MAX;
        if(w+b[idx][0] <= width){
            int tmp = dfs(idx+1, w+b[idx][0],max(max_h, b[idx][1]));
            res = min(res, tmp);
        }
        int tmp = dfs(idx+1, b[idx][0], b[idx][1])+max_h;
        res = min(res, tmp);
        return res;
    }
};
int main() {
    Solution s;
    vector<vector<int>> b = {{1,1},{1,1},{1,1},{1,2},{2,3},{2,3},{1,1}};
    vector<vector<int>> bb = {{7,3},{8,7},{2,7},{2,5}};

    int shelf_width = 4;
    cout<<s.minHeightShelves(b,4);
    return 0;
}


