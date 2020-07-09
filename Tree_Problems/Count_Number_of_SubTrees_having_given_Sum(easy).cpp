/*

    problem-> Count_Number_of_SubTrees_having_given_Sum(easy).cpp

    Given a binary tree and an integer X. Your task is to complete the function countSubtreesWithSumX() that returns the count of the number of subtress having total node’s data sum equal to the value X.
Example: For the tree given below:

              5
            /    \
        -10     3
        /    \    /  \
      9     8  -4 7

Subtree with sum 7:
             -10
            /      \
          9        8

and one node 7.

Input:
First line of input contains the number of test cases T. For each test case, there will be only a single line of input which is a string representing the
tree as described below:

The values in the string are in the order of level order traversal of the tree where, numbers denotes node values, and a character “N” denotes NULL child.

Output:
For each test case count the number of subtrees with given sum.

Your Task:
You don't need to read input or print anything. Your task is to complete the function countSubtreesWithSumX() which takes the root node and an integer X
 as inputs and returns the number of subtrees of the given Binary Tree having sum exactly equal to X.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(Height of the Tree).

Constraints:
1 <= T <= 100
1 <= N <= 103
-103 <= Node Value <= 103

Example:
Input:
2
5 -10 3 9 8 -4 7
7
1 2 3
5
Output:
2
0

Explanation:
Testcase 1: Subtrees with sum 7 are [9, 8, -10] and [7] (refer the example in the problem description).
Testcase 2: No subtree has sum equal to 5.

        */


int cnt=0;
int findsum(Node *root,int sum)
{
    if(root==NULL)
    return 0;

    int lt=root->data+findsum(root->left,sum);
    int rt=root->data+findsum(root->right,sum);

    if(sum==lt+rt-root->data)
    cnt++;

    return lt+rt-root->data;



}

int countSubtreesWithSumX(Node* root, int X)
{
	  cnt=0;
	  findsum(root,X);

	  return cnt;
}
