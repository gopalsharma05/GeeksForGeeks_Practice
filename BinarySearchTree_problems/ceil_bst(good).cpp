/*

    problem=ceil_bst(good).cpp


    Given an array arr[] of N positive integers to be inserted into BST and a number X. The task it to find Ceil of X.
Ceil(X) is a number that is either equal to X or is immediately greater than X.

Input:
First line of input contains number of testcases T. For each testcase, first line of input contains number of elements in the BST, i.e N. Next line contains N elements to be inserted into BST and last line contains X.

Output:
For each testcase, print the smallest element in BST which is larger than X.

Your task:
No need to worry about insert function in BST. Just complete the function findCeil() to implement ceil in BST.

Constraints:
1 <= T <= 100
1 <= N <= 105
1 <= arr[i] <= 105

Example:
Input:
2
5
5 7 1 2 3
3
6
10 5 11 4 7 8
6

Output:
5
7

Explanation:
Testcase 1: We find 3 in BST, so ceil of 3 is 3.




        */



int findCeil(Node* root, int key)
{
    // Base case
    if (root == NULL)
        return -1;

    int ans=-1;

    while(root!=NULL)
    {
        if(key==root->data)
        return key;
        else if(root->data<key)
        {
            root=root->right;

        }
        else if(root->data>key)
        {
            ans=root->data;
            root=root->left;
        }
    }

    return ans;




}
