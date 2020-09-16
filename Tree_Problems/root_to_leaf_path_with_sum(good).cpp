/*

    problem-> root_to_leaf_path_with_sum(good).cpp

    Given a binary tree and a sum, find all root-to-leaf paths where each path’s sum equals the given sum.

For example:
Given the below binary tree and sum = 22,

              5
             / \
            4   8
           /   / \
          11  13  4
         /  \    / \
        7    2  5   1
return

[
   [5,4,11,2],
   [5,8,4,5]
]


                    */






/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<vector<int> > ans;
void find(TreeNode *root,int k,vector<int> v)
{
    if(root==NULL)
    return ;
    if(root->left==NULL && root->right==NULL&&k==root->val)
    {
        v.push_back(root->val);
        ans.push_back(v);
        return ;
    }
    v.push_back(root->val);
    find(root->left,k-root->val,v);
    find(root->right,k-root->val,v);
    v.pop_back();



}
vector<vector<int> > Solution::pathSum(TreeNode* root, int s) {


    ans.clear();
    vector<int> v;
    find(root,s,v);
    return ans;

}
