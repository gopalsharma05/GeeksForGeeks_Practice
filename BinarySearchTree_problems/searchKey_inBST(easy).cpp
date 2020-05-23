/*

    problem=searchKey_inBST

    Given a Binary Search Tree (BST), you need to find if a particular node(data) is present in the BST or not. If present print 1, else print 0.
Note: The BST does not insert duplicates.

Input:
The first line of the input contains an integer 'T' denoting the number of test cases. Then 'T' test cases follow. Each test case consists of three lines. Description of  test cases is as follows:
The First line of each test case contains an integer 'N' which denotes the no of nodes to be inserted in the BST.
The Second line of each test case contains 'N' space separated values denoting the values of the BST.
In the third line is an integer x denoting the node to be searched for.

Output:
The output for each test case will be 1 if the node is present in the BST else 0.

Your Task:
This is a function problem. you don't have to read any input. Your task is to complete the
function search() which returns true if the node with value x is present in the BST else returns false.

Constraints:
1 <= T <= 100
1 <= N <= 100

Example:
Input:
2
7
2 81 87 42 66 90 45
87
4
6 7 9 8
11
Output:
1
0

Explanation:
Testcase 1: As 87 is present in the given nodes , so the output will be 1.
Testcase 2: As 11 is not present in the given nodes , so the output will be 0


        */




bool search(Node* root, int x)
{
    while(root!=NULL)
    {
        if(root->data==x)
        return true;
        else if(x<root->data)
        root=root->left;
        else
        root=root->right;

    }

    return false;
}
