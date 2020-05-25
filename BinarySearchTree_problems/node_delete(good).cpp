/*
    problem=node_delete(good).cpp

    Given a Binary Search Tree (BST) and a node value. Delete the node with the given value from the BST.
    If no node with value x exists, then do not make any change.

Input:
The first line of input contains the number of test cases T. For each test case, there will two lines.
First line of input is a string representing the tree as described below:

The values in the string are in the order of level order traversal of the tree where, numbers denote node values,
and a character “N” denotes NULL child.


Output:
For each test case in a new line, print the inorder traversal of the modified BST.

Your Task:
You don't need to read input or print anything. Your task is to complete the function deleteNode() which
takes two arguments. The first being the root of the tree, and an integer 'X' denoting the node value to be deleted from the BST. Return the root of the BST after deleting the node with value X. Do not make any update if there's no node with value X present in the BST.

Expected Time Complexity: O(Height of the BST).
Expected Auxiliary Space: O(Height of the BST).

Constraints:
1 <= T <= 10
1 <= N <= 100000

Example:
Input:
2
2 1 3 N N N N
12
1 N 2 N 8 5 11 4 7 9 12
9
Output:
1 2 3
1 2 4 5 7 8 11 12

        */


        Node * findSuccessor(Node *root)
{
    if(root==NULL)
    return root;

    root=root->right;
    while(root->left!=NULL)
    root=root->left;

    return root;
}

Node *deleteNode(Node *root,  int x)
{
    if(root==NULL)
    return root;

    if(x>root->data)
    {
        root->right=deleteNode(root->right,x);
        return root;
    }
    else if(x<root->data)
    {
        root->left=deleteNode(root->left,x);
        return root;
    }
    else
    {
        if(root->left==NULL)
        {
            Node *temp=root;
            root=root->right;
            delete(temp);
            return root;
        }
        else if(root->right==NULL)
        {
            Node *temp=root;
            root=root->left;
            delete(temp);
            return root;
        }
        else
        {
            Node *r=findSuccessor(root);

            root->data=r->data;
            // cout<<r->data<<" "<<root->data;
            root->right=deleteNode(root->right,r->data);




        }


    }
}
