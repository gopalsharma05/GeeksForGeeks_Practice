/*
    problem-> maximum_difference_between_node_and_its_ancesstor(good).cpp


    Given a Binary Tree, you need to find the maximum value which you can get by subtracting the value of node B from the value of node A, where A and B are two nodes of the binary tree and A is an ancestor of B.

Input:
The first line of input contains the number of test cases T. For each test case, there will be only a single line of input which is a string representing the tree as described below:

The values in the string are in the order of level order traversal of the tree where, numbers denote node values, and a character “N” denotes NULL child.


Output:
The function should return an integer denoting the maximum difference.

User Task:
The task is to complete the function maxDiff() which finds the maximum difference between the node and its ancestor.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(H).
Note: H is the height of the tree.

Constraints:
1 <= T <= 30
1 <= Number of edges <= 104
0 <= Data of a node <= 105

Example:
Input:
2
5 2 1
1 2 3 N N N 7
Output:
4
-1

Explanation:
Testcase 1:

             5
           /    \
         2      1
The maximum difference we can get is 4, which is bewteen 5 and 1.

Testcase 2:

             1
           /    \
         2      3
                   \
                    7
The maximum difference we can get is -1, which is between 1 and 2.

    */






int maxmdiff;
int finddifference(Node *root)
{
    if(root->left==NULL && root->right==NULL)
    return root->data;

    int a,b;
    if(root->left)
    a=finddifference(root->left);
    else
    a=INT_MAX;

    if(root->right)
    b= finddifference(root->right);
    else
    b=INT_MAX;


    int minm=min(a,b);
    maxmdiff=max(maxmdiff,root->data-minm);

    return min(minm,root->data);   // remember to considering the root->data also as minm value i.e
                                    // dont return minm , return min(minm,root->data);







}

int maxDiff(Node* root)
{
    maxmdiff=INT_MIN;

    int r=finddifference(root);
    // cout<<maxmdiff<<"\n";
    return maxmdiff;

}
