/*

        problem=Common_Nodes_in_BST(good).cpp

    Given two Binary Search Trees(without duplicates), you need to print the common nodes in them. In other words,
    find intersection of two BSTs.


Input:
The first line of input contains the number of test cases T. For each test case, there will be 2 lines of input. Each line will contain a string representing a tree as described below:

The values in the string are in the order of level order traversal of the tree where, numbers denote node values, and a character “N” denotes NULL child.

For example:

For the above tree, the string will be: 1 2 3 N N 4 6 N 5 N N 7 N

Output:
For each test case, in a new line, print the nodes common to both BSTs in sorted order.

Your Task:
This is a function problem. You only need to complete the function printCommon() that takes nodes of both BSTs as parameter.

Constraints:
1 <= T <= 400
1 <= N <= 103

Example:
Input:
2
5 1 10 0 4 7 N N N N N N 9
10 7 20 4 9
10 2 11 1 3
2 1 3
Output:
4 7 9 10
1 2 3

Explanation:
Testcase1: In the given two BSTs the common nodes are 4 7 9 and 10.
Testcase 2: In the given two BSTs the common nodes are  1 2 and 3.

        */


void inorder(Node *root,unordered_map<int,int> &m)  // using inorder traversal for sorted order
{
    if(root==NULL)
    return ;

    inorder(root->left,m);
    if(m[root->data]==1)      // checking if data is already in map then it is in common with the other tree
    cout<<root->data<<" ";
    else
    m[root->data]=1;
    inorder(root->right,m);
}

void printCommon(Node *root1, Node *root2)
{
     unordered_map<int,int> m;
     inorder(root1,m);
     inorder(root2,m);




}
