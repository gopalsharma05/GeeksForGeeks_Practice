/*

    problem=floor_BST(good).cpp


    Given an array arr[] of N positive integers to be inserted into BST and a positive integer X. The task is to find floor of X in the BST.
Floor(X) is an element that is either equal to X or immediately smaller to X.

Input:
First line of input contains number of testcases T. For each testcase, first line of input contains number of elements to be inserted in BST, next line contains N elements.

Output:
For each testcase, print the greatest smaller element of X.

Your task:
You don't need to worry about the insert function, just complete the function floor() which should return floor of X.

Constraints:
1 <= T <= 100
1 <= N <= 105
1 <= arr[i] <= 106

Example:
Input:
2
5
1 2 3 4 5
4
6
7 8 3 4 1 9
3

Output:
4
3

Explanation:
Testcase 1: We find 4 in the BST to floor of 4 is 4.
Testcase 2: We find 3 in the BST to floor of 3 is 3.




    */




int floor(Node* root, int key)
{
	if (!root)
		return INT_MAX;

		int f=INT_MAX;

		while(root!=NULL)
		{
		    if(root->data==key)
		    return key;
		    else if(key>root->data)
		    {
		        f=root->data;
		        root=root->right;
		    }
		    else if(key<root->data)
		    {
		        root=root->left;
		    }



		}

		return f;



}
