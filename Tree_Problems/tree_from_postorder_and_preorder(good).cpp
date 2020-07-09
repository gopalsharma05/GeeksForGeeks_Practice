/*

    problem-> tree_from_postorder_and_preorder(good).cpp


    Given inorder and postorder traversals of a Binary Tree in the arrays in[] and post[] respectively. The task is to construct the binary tree from these traversals.
For example, if given inorder and postorder traversals are {4, 8, 2, 5, 1, 6, 3, 7} and {8, 4, 5, 2, 6, 7, 3, 1}  respectively, then your function should construct below tree.

          1
       /      \
     2        3
   /    \     /   \
  4     5   6    7
    \
      8

Input:
First line of input contains number of testcases T. For each testcase, first line of input contains number of nodes in the tree, and next two lines contains inorder and postorder respectively.

Output:
For each testcase, print the preorder traversal of tree.

Your Task:
Complete the function buildTree() which takes the inorder, postorder traversals and the number of nodes in the tree as inputs and returns the root node of the newly constructed Binary Tree.

Expected Time Complexity: O(N2).
Expected Auxiliary Space: O(N).

Constraints:
1 <= T <= 100
1 <= N <= 103
1 <= in[i], post[i] <= 103

Example:
Input:
2
8
4 8 2 5 1 6 3 7
8 4 5 2 6 7 3 1
5
9 5 2 3 4
5 9 3 4 2
Output:
1 2 4 8 5 3 6 7
2 9 5 4 3

Explanation:
Testcase 1: For the given postorder and inorder traversal of tree the  resultant binary tree will be
          1
       /      \
     2        3
   /    \     /   \
  4     5   6    7
    \
      8
Testcase 2: For the given postorder and inorder traversal of tree the  resultant binary tree will be
               2
          /           \
        9            5
      /     \
    4      3

        */


*/


//DYNAMO123

Node* maketree(int in[],int post[],int start,int end,int &ind,unordered_map<int,int> &m)
{
    if(start>end)
    return NULL;

    int c=post[ind];
    Node *r=new Node(post[ind]);
    ind--;

    if(start==end)
    return r;

    int index=m[c];




     r->right=maketree(in,post,index+1,end,ind,m);
      r->left=maketree(in,post,start,index-1,ind,m);





    return r;


}
Node *buildTree(int in[], int post[], int n) {

    if(n==0)
    return NULL;

    unordered_map<int,int> m;
    for(int i=0;i<n;i++)
    m[in[i]]=i;

    int start=0,end=n-1,ind=n-1;
    Node *root=maketree(in,post,start,end,ind,m);
    return root;




}
