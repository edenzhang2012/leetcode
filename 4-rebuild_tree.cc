/*
输入某二叉树的前序遍历和中序遍历的结果，请重建出该二叉树。假设输入的前序遍历和中序遍历
的结果中都不含重复的数字。例如输入前序遍历序列{1,2,4,7,3,5,6,8}和中序遍历序列
{4,7,2,1,5,3,8,6}，则重建二叉树并返回。
*/

#include <iostream>
#include <vector>
#include <stack>
#include <assert.h>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

TreeNode* p_m_rebuild(std::vector<int> &pre, std::vector<int> &vin, int p_start, 
    int p_end, int v_start, int v_end){

    // std::cout << "p_start " << p_start << " p_end " << p_end << " v_start " 
    //     << v_start << " v_end " << v_end << std::endl;
    int i = 0;
    
    if(!pre.size() || !vin.size())
        return NULL;

    if(pre.size() != vin.size()){
        return NULL;
    }

    if(p_start >= p_end || v_start >= v_end){
        return NULL;
    }

    TreeNode* root = new TreeNode(pre[p_start]);
    assert(root);

    for(i=v_start; i<v_end; i++){
        // std::cout << " vin[" << i << "] " << vin[i] << " pre[" << p_start << "] " 
        //     << pre[p_start] << std::endl;
        if(vin[i] == pre[p_start])
            break;
    }
    if(i == v_end){
        assert(0 == "not get here");
    }else{
        // std::cout << " i " << i << std::endl;
    }

    root->left = p_m_rebuild(pre, vin, p_start+1, p_start+1+(i-v_start), v_start, i);
    root->right = p_m_rebuild(pre, vin, p_start+1+(i-v_start), p_end, i + 1, v_end);

    return root;
}

TreeNode* s_m_rebuild(std::vector<int> &suf, std::vector<int> &vin, int s_start, 
    int s_end, int v_start, int v_end){

    std::cout << "s_start " << s_start << " s_end " << s_end << " v_start " 
        << v_start << " v_end " << v_end << std::endl;
    int i = 0;
    
    if(!suf.size() || !vin.size())
        return NULL;

    if(suf.size() != suf.size()){
        return NULL;
    }

    if(s_start >= s_end || v_start >= v_end){
        return NULL;
    }

    TreeNode* root = new TreeNode(suf[s_end - 1]);
    assert(root);

    for(i=v_start; i<v_end; i++){
        std::cout << " vin[" << i << "] " << vin[i] << " suf[" << s_end - 1 << "] " 
            << suf[s_end-1] << std::endl;
        if(vin[i] == suf[s_end - 1])
            break;
    }
    if(i == v_end){
        assert(0 == "not get here");
    }else{
        std::cout << " i " << i << std::endl;
    }

    root->left = s_m_rebuild(suf, vin, s_start, i, v_start, i);
    root->right = s_m_rebuild(suf, vin, i, s_end-1, i + 1, v_end);

    return root;
}

void precycle(TreeNode *root){
    if(NULL == root)
        return;
    
    std::cout << root->val << " ";

    if(root->left)
        precycle(root->left);
    if(root->right)
        precycle(root->right);
}

void middlecycle(TreeNode *root){
    if(NULL == root)
        return;

    if(root->left)
        middlecycle(root->left);
    std::cout << root->val << " ";
    if(root->right)
        middlecycle(root->right);
}

void sufcycle(TreeNode *root){
    if(NULL == root)
        return;

    if(root->left)
        sufcycle(root->left);
    if(root->right)
        sufcycle(root->right);
    std::cout << root->val << " ";
}

/*
二叉树的非递归遍历可以借助栈来实现，好像也只有这一种方案
*/
void precycle1(TreeNode *root){
    std::stack<TreeNode *> node_stack;
    TreeNode *current = NULL;

    if(NULL == root)
        return;
    
    current = root;
    //边遍历边打印，并存入栈中，以后需要借助这些根节点(所有节点都可看作根节点)进入右子树
    while(current || !node_stack.empty()){
        while(current){
            node_stack.push(current);
            std::cout << current->val << " ";
            current = current->left;
        }

        //当p为空时，说明已经到达左子树最下边，这时需要出栈了
        if(!node_stack.empty()){
            current = node_stack.top();
            node_stack.pop();
            current = current->right;
        }
    }
}

void middlecycle1(TreeNode *root){
    std::stack<TreeNode *> node_stack;
    TreeNode *current = NULL;

    if(NULL == root)
        return;
    
    current = root;
    //一直遍历到左子树最下边，边遍历边保存根节点到栈中
    while(current || !node_stack.empty()){
        while(current){
            node_stack.push(current);
            // std::cout << current->val << " ";
            current = current->left;
        }

        //当p为空时，说明根和左子树都遍历完了，该进入右子树了
        if(!node_stack.empty()){
            current = node_stack.top();
            node_stack.pop();
            std::cout << current->val << " ";
            //进入右子树，开始新的一轮左子树遍历(这是递归的自我实现)
            current = current->right;
        }
    }
}

//后序遍历的难点在于：需要判断上次访问的节点是位于左子树，还是右子树
void sufcycle1(TreeNode *root){
    std::stack<TreeNode *> node_stack;
    //current 本次访问节点  pre是上次访问节点
    TreeNode *current = NULL, *pre = NULL;

    if(NULL == root)
        return;
    
    current = root;
    //先把current移动到左子树最下边
    while (current){
        node_stack.push(current);
        current = current->left;
    }

    while (!node_stack.empty())
    {
        //走到这里，current都是空，并已经遍历到左子树底端(看成扩充二叉树，则空，亦是某棵树的左孩子)
        current = node_stack.top();
        node_stack.pop();
        //一个根节点被访问的前提是：无右子树或右子树已被访问过
        if (current->right == NULL || current->right == pre)
        {
            std::cout << current->val << " ";
            //修改最近被访问的节点
            pre = current;
        }
        /*这里的else语句可换成带条件的else if:
        else if (current->left == pre)//若左子树刚被访问过，则需先进入右子树(根节点需再次入栈)
        因为：上面的条件没通过就一定是下面的条件满足。仔细想想！
        */
        else
        {
            //根节点再次入栈
            node_stack.push(current);
            //进入右子树，且可肯定右子树一定不为空
            current = current->right;
            //继续走到右子树里的左子树一直到底部
            while (current)
            {
                node_stack.push(current);
                current = current->left;
            }
        }
    }
}

int main(){
    std::vector<int> pre = {1,2,4,7,3,5,6,8};
    std::vector<int> vin = {4,7,2,1,5,3,8,6};
	std::vector<int> suf = {7,4,2,5,8,6,3,1};
    // TreeNode * root = p_m_rebuild(pre, vin, 0, pre.size(), 0, vin.size());
    TreeNode * root = s_m_rebuild(suf, vin, 0, suf.size(), 0, vin.size());

    // precycle(root);
    // std::cout << std::endl;

    // middlecycle(root);
    // std::cout << std::endl;

    // sufcycle(root);
    // std::cout << std::endl;

    precycle1(root);
    std::cout << std::endl;

    middlecycle1(root);
    std::cout << std::endl;

    sufcycle1(root);
    std::cout << std::endl;
    return 0;
}