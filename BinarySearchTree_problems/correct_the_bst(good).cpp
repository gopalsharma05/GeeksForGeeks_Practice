/*

    problem=correct_the_bst(good).cpp

    Two of the nodes of a Binary Search Tree (BST) are swapped. Fix (or correct) the BST.

Input Format:
First line consists of T test cases. First line of every test case consists of N, denoting number of elements in BST. Second line of every test case consists 3*N elements 2 integers and a character

Note: It is guaranteed than the given input will form BST ,except for 2 nodes that will be wrong.

Output Format:
For each testcase, in a new line, print either 0 or 1.

Your Task:
You don't need to take any input. Just complete the function correctBst() that takes node as parameter. The corrected BST will then be checked internally.

Constraints:
1 <= T <= 100
1 <= N <= 100

Example:
Input:
2
4
10 5 L 10 8 R  5 2 L 5 20 R
5
8 3 L 8 10 R 3 1 L 3 6 R 6 7 R

Output:
1
0

        */



Node *first=NULL;
Node *second=NULL;


void inorder2(Node *root, Node *&prev)
{
    if(root==NULL)
    return ;


    inorder2(root->left,prev);

    if(prev!=NULL &&  root->data < prev->data  )
    {
        if(first==NULL)
        first=prev;

        second=root;
    }
    prev=root;


    inorder2(root->right,prev);


}



struct Node *correctBST( struct Node* root )
{

    Node *prev=NULL;
    first=NULL;
    second=NULL;
    inorder2(root,prev);


        if(first  && second)      // here i just swapped the data not the node and code worked
        {
            int t=first->data;
            first->data=second->data;
            second->data=t;
        }





    return root;


}
