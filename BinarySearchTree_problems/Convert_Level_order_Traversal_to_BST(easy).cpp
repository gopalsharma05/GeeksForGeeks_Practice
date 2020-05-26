/*


    problem=Convert_Level_order_Traversal_to_BST(easy).cpp

Given an array of size N containing level order traversal of a BST. The task is to complete the function constructBst(), that construct the BST (Binary Search Tree) from its given level order traversal.

Input:
First line of input contains number of testcases T. For each testcase, first line contains number of elements and next line contains n elements which is level order travesal of a BST.

Output:
For each test return the pointer to the root of the newly constructed BST.

User Task:
Your task is to complete the function constructBst() which has two arguments, first as the array containing level order traversal of BST and next argument as the length of array.

Constraints:
1 <= T <= 100
1 <= N <= 103

Example:
Input:
2
9
7 4 12 3 6 8 1 5 10
6
1 3 4 6 7 8

Output:
7 4 3 1 6 5 12 8 10
1 3 4 6 7 8

Explanation:
Testcase 1: After constructing BST, the preorder traversal of BST is 7 4 3 1 6 5 12 8 10

    */



// first very easy method is -> you have to just implement the insert function of BST and insert element of array one by one,that's all



Node * insert(Node *root,int key)
{
    if(!root)
    return new Node(key);

    if(key> root->data)
    {
        root->right=insert(root->right,key);
    }
    else if(key<root->data)
    root->left=insert(root->left,key);

    return root;

}

Node* constructBst(int a[], int n)
{

	Node *root=NULL;

	for(int i=0;i<n;i++)
	{
	    root=insert(root,a[i]);
	}

	return root;
}






