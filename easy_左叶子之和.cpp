/*
* Author:czj
* Time:  2019/8/16 11:23
*
*/
#include <iostream>
using namespace std;
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        if(root == NULL) return 0;
        int res = 0;
        TreeNode r = *root;
        if(r.left != NULL && (*(r.left)).left == NULL && (*(r.left)).right == NULL){
            res += (*(r.left)).val;
        }
        return sumOfLeftLeaves(r.left) + sumOfLeftLeaves(r.right) + res;
    }
};
int main() {

    return 0;
}


