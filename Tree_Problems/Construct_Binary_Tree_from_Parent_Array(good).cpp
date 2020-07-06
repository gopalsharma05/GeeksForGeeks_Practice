/*
    problem->  Construct_Binary_Tree_from_Parent_Array(good).cpp

    Given an array of size N that represents a Tree in such a way that array indexes are values in tree nodes and array values give the parent node of that particular index (or node). The value of the root node index would always be -1 as there is no parent for root. Construct the standard linked representation of Binary Tree from this array representation.

Input:
The first line of the input contains an integer 'T' denoting the number of test cases. Then 'T' test cases follow. Each test case consists of two lines. The first line of each test case contains an integer N denoting the size of the tree array. The second line of each test case consists of 'N' space-separated integers denoting the elements of the array.

Output:
The Output will be the sorted level order traversal of the tree.

User Task:
The task is to complete the function createTree() which takes 2 arguments(tree array and N) and returns the root node of the tree constructed.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(N).

Constraints:
1 <= T <= 1000
1 <= N <= 103

Example:
Input:
2
7
-1 0 0 1 1 3 5
5
-1 0 0 2 2
Output:
0 1 2 3 4 5 6
0 1 2 3 4

Explanation:
Testcase 1: For the array parent[] = {-1, 0, 0, 1, 1, 3, 5}; the tree generated will have a sturcture like

         0
       /   \
      1     2
     / \
    3   4
   /
  5
/
6
Testcase 2: For the array parent[] = {-1 0 0 2 2}; the tree generated will have a sturcture like
                  0
               /      \
             1        2
          /      \
        3        4



            */




#define pb push_back
Node *createTree(int a[], int n)
{
    if(n==0)
    return NULL;

      vector<Node*> v;

    int r;
    for(int i=0;i<n;i++)
    {
        Node *t=new Node(i);
        v.pb(t);
    }

    for(int i=0;i<n;i++)
    {
        if(a[i]==-1)
        {
            r=i;
        }
        else if(v[a[i]]->left==NULL)
        v[a[i]]->left=v[i];
        else if(v[a[i]]->right==NULL)
        v[a[i]]->right=v[i];

    }



    return v[r];




}
