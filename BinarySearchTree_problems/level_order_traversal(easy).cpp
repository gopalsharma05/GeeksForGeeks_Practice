/*

problem=level_order_traversal

        Levelorder traversal means traversing through the tree level by level, from left to right.
You are given an array arr of size sizeOfArray. You need to create a BST using elements of the array. The BST is to be created using the elements in the order of their arrival.

Input:
The first line of input contains testcases number. Each testcase contains two lines of input. The first line contains size of the array. The second line contains elements of the array.

Output:
For each testcase, in a newline, print the levelorder traversal.

Your Task:
This is a function problem. You don't need to take any input. For this problem, your task is to complete
the levelorder function that prints preorder traversal of the BST. This function takes in root as parameter.

Constraints:
1 <= testcases <= 100
1 <= sizeOfArray <= 100
1 <= arri <= 100

Example:
Input:
2
5
5 2 3 7 8
3
30 10 20
Output:
5 2 7 3 8
30 10 20

Explanation:
Testcase 1: For the given tree
                            5
                        /         \
                      2           7
                         \            \
                          3            8
Level order traversal of the given tree will be 5 2 7 3 8.

        */


 void levelOrder(Node *root)
{
    if(root==NULL)
    return;

    queue<Node*> q;   // using queue to solve this
    q.push(root);       //pushing root
    while(!q.empty())
    {


        Node *p=q.front();
        q.pop();
        cout<<p->data<<" ";     // pushing front of the queue and pushing its left and right
        if(p->left)
        q.push(p->left);

        if(p->right)
        q.push(p->right);


    }

}
