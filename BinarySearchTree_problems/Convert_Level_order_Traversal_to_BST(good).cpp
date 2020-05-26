/*


    problem=Convert_Level_order_Traversal_to_BST(good).cpp

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



//  thit method use other struct nodedetails , maintain min max range for everynode so that we can decide where to put node to maintain BST
// this min max range also used to check if the tree is BST or not

struct NodeDetails
{
	Node *ptr;
	int min, max;
};

Node* constructBst(int arr[], int n)
{
    // base case
	if (n == 0)return NULL;
	Node *root;

	queue<NodeDetails> q;

	int i=0;
	NodeDetails newNode;
	newNode.ptr = new Node(arr[i++]);
	newNode.min = INT_MIN;
	newNode.max = INT_MAX;
	q.push(newNode);
	root = newNode.ptr;

	// using the method of level order traversal to construct BST
	// queue has been used to store the elements from array and construct BST
	while (i != n)
	{
		NodeDetails temp = q.front();
		q.pop();
		if (i < n && (arr[i] < temp.ptr->data && arr[i] > temp.min))
		{
			newNode.ptr = new Node(arr[i++]);
			newNode.min = temp.min;
			newNode.max = temp.ptr->data;
			q.push(newNode);
			temp.ptr->left = newNode.ptr;
		}
		if (i < n && (arr[i] > temp.ptr->data && arr[i] < temp.max))
		{
			newNode.ptr = new Node(arr[i++]);
			newNode.min = temp.ptr->data;
			newNode.max = temp.max;
			q.push(newNode);
			temp.ptr->right = newNode.ptr;
		}
	}
	return root;
}
