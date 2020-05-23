/*

    problem=insert_in_BST

    Your Task:
You don't need to read input or print anything. Your task is to complete the function insert() which takes
the root of the BST and a Key as inputs and returns the root of the BST after inserting the Key value into it.

Expected Time Complexity: O(Height of the BST).
Expected Auxiliary Space: O(Height of the BST).

Constraints:
1 <= T <= 10
1 <= N <= 100000
1 <= K <= 1000000

Example:
Input:
2
2 1 3
4
2 1 3 N N N 6 4
1
Output:
1 2 3 4
1 2 3 4 6

        */


Node* insert(Node* root, int key)
{

    if(root==NULL)
    {
        Node *r=new Node(key);
        return r;
    }

    if(key>root->data)
    {
        root->right=insert(root->right,key);
    }
    else if(key<root->data)
    root->left=insert(root->left,key);


    return root;


}
