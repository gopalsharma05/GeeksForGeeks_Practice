/*

    problem-> Binary_Tree_to_DLL(good).cpp


    Given a Binary Tree (BT), convert it to a Doubly Linked List(DLL) In-Place. The left and right pointers in nodes are to be used as previous and
    next pointers respectively in converted DLL. The order of nodes in DLL must be same as Inorder of the given Binary Tree. The first node of Inorder traversal (leftmost node in BT) must be the head node of the DLL.

TreeToList

Input:
The first line of input contains the number of test cases T. For each test case, there will be only a single line of input which is a string representing
the tree as described below:

The values in the string are in the order of level order traversal of the tree where, numbers denote node values, and a character “N” denotes NULL child.

For example:

For the above tree, the string will be: 1 2 3 N N 4 6 N 5 N N 7 N

Output:
For each test case, in a new line, print front to end and back to end traversals of DLL.

Your Task:
You don't have to take input. Complete the function bToDLL() that takes root node of the tree as a parameter and returns the head of DLL .
The driver code prints the DLL both ways.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(H).
Note: H is the height of the tree and this space is used implicitly for recursion stack.

Constraints:
1 <= T <= 100
1 <= Number of nodes <= 1000
1 <= Data of a node <= 1000

Example:
Input:
2
1 3 2
10 20 30 40 60
Output:
3 1 2
2 1 3
40 20 60 10 30
30 10 60 20 40

Explanation:
Testcase1: The tree is
        1
     /      \
   3       2
So, DLL would be 3<=>1<=>2
Testcase2: The tree is
                           10
                        /        \
                     20         30
                  /       \
               40       60
So, DLL would be 40<=>20<=>60<=>10<=>30




        */






Node *prev1=NULL,*head=NULL;

void makedll(Node *root)
{
    if(root==NULL)
    return ;

    makedll(root->left);
    if(prev1==NULL)
    {
        prev1=root;
        head=prev1;
        head->left=NULL;

    }
    else
    {
       prev1->right=root;
       root->left=prev1;
       prev1=root;
    }
    makedll(root->right);

}
Node * bToDLL(Node *root)
{
    prev1=NULL;
    head=NULL;
    makedll(root);

    return head;

}

