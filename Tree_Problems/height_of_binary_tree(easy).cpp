/*
    problem-> height_of_binary_tree(easy).cpp

    Given a binary tree, find its height.

Input:
First line of input contains the number of test cases T. For each test case, there will be only one single line of input which is a string representing the tree as described below:

The values in the string are in the order of level order traversal of the tree where, numbers denote node values, and a character �N� denotes NULL child.

For example:

For the above tree, the string will be: 1 2 3 N N 4 6 N 5 N N 7 N

Output:
For each testcase, in a new line, print the height of tree.

Your Task:
You don't need to read input or print anything. Your task is to complete the function height() that takes root Node of the Tree as input and returns the Height of the Tree. If the Tree is empty, return 0.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(1).

Constraints:
1 <= T <= 100
1 <= Number of nodes <= 105
1 <= Data of a node <= 105
Sum of N over all testcases doesn't exceed 105

Example:
Sample Input:
3
1 2 3
2 N 1 3 N
10 20 30 40 60 N N

Sample Output:
2
3
3

Explanation:
Testcase1: The tree is
        1
     /      \
   2        3
So, the height would be 2.

Testcase2: The tree is
                           2
                              \
                               1
                              /
                          3
So, height would be 3.



        */



int height(Node* root)
{
    if(root==NULL)
    return 0;

    int lh=height(root->left)+1;
    int rh=height(root->right)+1;
    return max(lh,rh);

}
