/*

    problem-> Flatten_tree(good).cpp


    Given a binary tree, flatten it to a linked list in-place.

Example :
Given


         1
        / \
       2   5
      / \   \
     3   4   6
The flattened tree should look like:

   1
    \
     2
      \
       3
        \
         4
          \
           5
            \
             6
Note that the left child of all nodes should be NULL.





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
 TreeNode *rohit=NULL,*ans=NULL,*head=NULL;
 void preo(TreeNode *root)
 {
     if(root==NULL)
     return ;

     preo(root->right);
     preo(root->left);
     if(rohit==NULL)
     {
          rohit =root;

     }
     else
     {
         head=root;
         head->right=rohit;
         head->left=NULL;
         rohit=head;
     }

 }
TreeNode* Solution::flatten(TreeNode* root) {

if(root==NULL || (root->left==NULL &&  root->right==NULL))
return root;
rohit=NULL;
ans=NULL;
head=NULL;
preo(root);
return head;



}
