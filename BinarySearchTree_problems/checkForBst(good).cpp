/*

    problem-> checkForBst(good).cpp

    Given a binary tree. Check whether it is a BST or not.

Input:
The first line of input contains the number of test cases T. Each test case contains a string representing the tree as described below:

The values in the string are in the order of level order traversal of the tree where, numbers denote node values, and a character “N” denotes NULL child.


Output:
The function should return 1 if BST else return 0.

Your Task:
You don't need to read input or print anything. Your task is to complete the function isBST() which takes the root of the tree as a parameter and returns true if the given binary tree is BST, else returns false.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(Height of the BST).

Constraints:
1 <= T <= 10
0 <= Number of edges <= 100000

Example:
Input:
2
2 1 3
2 N 7 N 6 N 5 N 9 N 2 N 6
Output:
1
0

        */


// 1 approach can be stor inorder traversal in array and check its ascending order as inorder of BST is always sorted in ascending order ....here i ignore
// use of array and use a single variable to keep track for 2 adjacent element of inorder traversal

int val;
bool flag=false;
void inorder(Node *root)        // using inorder as it is alway sorted, maintain prev variable and compare current to prev which should be greater always
                                // for BST if at any moment it fails ,,,it means it is not BST
{
    if(!root)
    return ;

     inorder(root->left);


        if(root->data<=val)     // equal sign as duplicates are not allowed
        flag=false;


    val=root->data;

    inorder(root->right);

}
bool isBST(Node* root) {
    flag=true;
    val=-1;
    inorder(root);          // calling inorder function

    return flag;
}
