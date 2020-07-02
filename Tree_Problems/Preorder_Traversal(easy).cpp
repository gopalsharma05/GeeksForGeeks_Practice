/*

    problem-> Preorder_Traversal(easy).cpp

    // BOTH SOLUTION ARE AVAILABE HERE....RECURSION AND ITERATIVE

Given a binary tree, print preorder traversal of it.
For example: preorder traversal of below tree is "1 10 5 39"

        1
     /     \
   10     39
  /
5

Input:
The first line of input contains the number of test cases T. For every test case, the first line of input contains two space-separated integers, denoting node values for which we want to find LCA,  and the second line will contain a string representing the tree as described below:

The values in the string are in the order of level order traversal of the tree where, numbers denote node values, and a character “N” denotes NULL child.

For example:


For the above tree, the string will be: 1 2 3 N N 4 6 N 5 N N 7 N

Output:
The function should print preorder traversal.

User Task:
Since this is a functional problem you don't have to worry about input, you just have to complete the function preorder() that takes the root node of the tree as input and returns an array containing the preorder traversal of the tree.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(N).

Constraints:
1 <= T <= 200
1 <= Number of nodes <= 104
1 <= Data of a node <= 105

Example:
Input:
2
1 4 N 4 2
6 3 2 N 1 2
Output:
1 4 4 2
6 3 1 2 2

Explanation:
Testcase 1: There are 4 nodes in the tree. it looks like:

                                      1
                                     /
                                  4
                                /    \
                             4       2
 Its Preorder is 1 4 4 2
Testcase 2: In the similar way for the given input its preorder traversal will be 6 3 1 2 2 .


        */


#define pb push_back
void IterPreorder(Node* root,vector<int> &v)    // it is recursion solution
{
    if(!root)
    return ;
    // cout<<root->data;
    v.pb(root->data);
    IterPreorder(root->left,v);
    IterPreorder(root->right,v);
}
vector <int> preorder(Node* root)
{
  vector<int> v;

//   IterPreorder(root,v);   // with recursion

//iterative approach (below is ITERATIVE SOLUTION USING STACK)

stack<Node*> st;

st.push(root);
while(!st.empty())
{
    Node *p=st.top();
    st.pop();
    v.pb(p->data);
    if(p->right)
    st.push(p->right);
    if(p->left)
    st.push(p->left);
}

  return v;


}
