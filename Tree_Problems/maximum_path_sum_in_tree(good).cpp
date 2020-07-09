/*
    problem-> maximum_path_sum_in_tree(good).cpp

    Given a binary tree, the task is to find the maximum path sum. The path may start and end at any node in the tree.

Input:
First line of input contains the number of test cases T. For each test case, there will be only a single line of input which is a string
representing the tree as described below:

The values in the string are in the order of level order traversal of the tree where, numbers denotes node values, and a character “N” denotes NULL child.



Output:
Print the maximum path sum in the binary tree.

User Task:
You don't need to take input or print anything. Your task is to complete the function findMaxSum() that takes root as input and returns max sum between
any two nodes in the given Binary Tree.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(Height of the Tree).

Constraints:
1 <= T <= 100
1 <= Number of nodes <= 103
1 <= |Data on node| <= 104

Example:
Input:
2
10 2 -25 20 1 3 4
10 2 5 N N N -2
Output:
32
17

Explanation:
Testcase 1: Path in the given tree goes like 10 , 2 , 20 which gives the max sum as 32.
Testcase 2: Path in the given tree goes like 2 , 10 , 5 which gives the max sum as 17.



        */




int maxsum;

int findsum(Node *root)
{
    if(root==NULL)
    return 0;

   int l=root->data+findsum(root->left);
   int r=root->data+findsum(root->right);

   int k=max(max(l,r),root->data);

   maxsum=max(maxsum,max(l+r-root->data,k));

   return k;




}



int findMaxSum(Node* root)
{
      maxsum=INT_MIN;
      int r=findsum(root);
      return maxsum;
}
