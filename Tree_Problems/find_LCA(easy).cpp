/*

        problem-> find_LCA(easy).cpp
        Find the lowest common ancestor in an unordered binary tree given two values in the tree.

 Lowest common ancestor : the lowest common ancestor (LCA) of two nodes v and w in a tree or directed acyclic graph (DAG) is the lowest (i.e. deepest)
 node that has both v and w as descendants.
Example :


        _______3______
       /              \
    ___5__          ___1__
   /      \        /      \
   6      _2_     0        8
         /   \
         7    4
For the above tree, the LCA of nodes 5 and 1 is 3.

 LCA = Lowest common ancestor
Please note that LCA for nodes 5 and 4 is 5.

You are given 2 values. Find the lowest common ancestor of the two nodes represented by val1 and val2
No guarantee that val1 and val2 exist in the tree. If one value doesn’t exist in the tree then return -1.
There are no duplicate values.
You can use extra memory, helper functions, and can modify the node struct but, you can’t add a parent pointer.




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


 int findlca(TreeNode *root,int a,int b)
 {
     if(root==NULL)
     return -1;

     if(root->val==a || root->val==b)
     return root->val;
     int lt=findlca(root->left,a,b);
     int rt=findlca(root->right,a,b);
     if(lt!=-1 && rt!=-1)
     return root->val;

     if(lt==-1)
     return rt;
     if(rt==-1)
     return lt;
 }

bool find(TreeNode *root,int n)
{

       if(root==NULL)
    return false;
    if(root->val==n)
    return true;



    return (find(root->left,n)||find(root->right,n));

}
int Solution::lca(TreeNode* root, int b, int c) {

   if(!find(root,b)||!find(root,c))
   return -1;
   int ans=findlca(root,b,c);

   return ans;


}
