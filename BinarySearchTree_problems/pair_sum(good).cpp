/*

        problem=pair_sum(good).cpp

    Given an array arr[] of N elements to be inserted into BST and a number X. The task is to check if any pair exists in BST or not whose sum is equal to X.

Input:
First line of input contains number of testcases T. For each testcase, first line of input contains number of elements to be inserted into BST. Next line contains elements to be inserted into BST and last line contains X.

Output:
For each testcase, print "1" (without quotes) if pair with sum X exists in BST, else print "0" (without quotes).

Your Task:
No need to worry about the insert function in BST, just write your code for the boolean function findPair() to check if a pair with given sum X exists in BST or not. The function returns true or false.

Constraints:
1 <= T <= 100
1 <= N <= 105
1 <= arr[i] <= 105

Example:
Input:
2
5
8 5 1 3 9
4
6
0 1 2 7 8 3
6
Output:
1
0

Explanation:
Testcase 1: For the given input, there exist a pair whose sum is, i.e, (3,1).
Testcase 2: For the given input , there exists no such pair whose sum is 6.

    */



unordered_map<int,int> m;   // global map to stored the element of tree
bool flag=false;

void inorder(Node *root,int sum,unordered_map<int,int> &m)
{
    if(root==NULL)
    return ;

    inorder(root->left,sum,m);

    if(m[sum-root->data]==1)        // checking if sum -element is already present in map or not
    {
        flag=true;

    }

    else
    m[root->data]=1;                //pushing element in hash map

    inorder(root->right,sum,m);     //



}

bool findPair(Node* root, int sum) {

    m.clear();
    flag=false;
    inorder(root,sum,m);
    return flag;

}



