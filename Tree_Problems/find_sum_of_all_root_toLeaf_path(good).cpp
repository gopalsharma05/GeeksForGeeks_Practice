/*

        problem-> find_sum_of_all_root_toLeaf_path(good).cpp

        Given a binary tree containing digits from 0-9 only, each root-to-leaf path could represent a number.

An example is the root-to-leaf path 1->2->3 which represents the number 123.

Find the total sum of all root-to-leaf numbers % 1003.

Example :

    1
   / \
  2   3
The root-to-leaf path 1->2 represents the number 12.
The root-to-leaf path 1->3 represents the number 13.

Return the sum = (12 + 13) % 1003 = 25 % 1003 = 25.


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
int find(TreeNode *root,int sum)
{
     if(root==NULL)
     return sum;
    sum=(sum*10+root->val)%1003;
    if((root->left==NULL && root->right==NULL))
    {
        return sum;
    }

    if(!root->left)
    return find(root->right,sum);
    if(!root->right)
    return find(root->left,sum);

    return (find(root->left,sum)+find(root->right,sum))%1003;



}
int Solution::sumNumbers(TreeNode* root) {


   return find(root,0);


}
