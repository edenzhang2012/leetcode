/*
输入某二叉树的前序遍历和中序遍历的结果，请重建出该二叉树。假设输入的前序遍历和中序遍历
的结果中都不含重复的数字。例如输入前序遍历序列{1,2,4,7,3,5,6,8}和中序遍历序列
{4,7,2,1,5,3,8,6}，则重建二叉树并返回。
*/

#include <iostream>
#include <vector>
#include <assert.h>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

TreeNode* rebuild(std::vector<int> &pre, std::vector<int> &vin, int p_start, int p_end, int v_start, int v_end){
    int i = 0;
    
    if(!pre.size() || !vin.size())
        return NULL;

    if(pre.size() != vin.size()){
        return NULL;
    }

    TreeNode* root = new TreeNode(pre[p_start]);
    assert(root);

    for(i=v_start; i<=v_end; i++){
        if(vin[i] == pre[p_start])
            break;
    }
    if(i == v_end + 1){
        assert(0 == "not get here");
    }

    root->left = rebuild(pre, vin, p_start + 1, i, v_start, i - 1);
    root->right = rebuild(pre, vin, i + 1, p_end, i + 1, v_end);

    return root;
}

TreeNode* reConstructBinaryTree(std::vector<int> pre,std::vector<int> vin) {
    return rebuild(pre, vin, 0, pre.size(), 0, vin.size());
}

int main(){
    std::vector<int> pre = {1,2,4,7,3,5,6,8};
    std::vector<int> vin = {4,7,2,1,5,3,8,6};
    reConstructBinaryTree(pre, vin);

    return 0;
}