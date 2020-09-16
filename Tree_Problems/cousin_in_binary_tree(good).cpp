/*

    problem-> cousin_in_binary_tree(good).cpp


    Given a Binary Tree A consisting of N nodes.

You need to find all the cousins of node B.

NOTE:

Siblings should not be considered as cousins.
Try to do it in single traversal.
You can assume that Node B is there in the tree A.
Order doesn't matter in the output.


Problem Constraints
1 <= N <= 105

1 <= B <= N



Input Format
First Argument represents the root of binary tree A.

Second Argument is an integer B denoting the node number.



Output Format
Return an integer array denoting the cousins of node B.

NOTE: Order doesn't matter.



Example Input
Input 1:

 A =

           1
         /   \
        2     3
       / \   / \
      4   5 6   7


B = 5

Input 2:

 A =
            1
          /   \
         2     3
        / \ .   \
       4   5 .   6


B = 1




Example Output
Output 1:

 [6, 7]
Output 2:

 []




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
vector<int> Solution::solve(TreeNode* root, int k) {

    vector<int> ans;
    if(root==NULL || (root->left==NULL && root->right==NULL))
    return ans;

    queue<TreeNode *> q;
    q.push(root);
    q.push(NULL);
    bool child=false,par=false;
    while(q.size()>1)
    {
        TreeNode *p=q.front();
        q.pop();
        if(child && p)
        ans.push_back(p->val);
        if(p==NULL)
        {
               if(child)
               break;
               if(par==true)
               {
                   child=true;
                   q.push(NULL);
                   continue;

               }

               if(child)
               break;
               q.push(NULL);


        }
        else
        {
            if((p->left&&p->left->val==k)||(p->right&&p->right->val==k))
            {
                par=true;
                continue;
            }
            else
            {
                if(p->left)
                q.push(p->left);
                if(p->right)
                q.push(p->right);
            }
        }
    }

    return ans;


}
