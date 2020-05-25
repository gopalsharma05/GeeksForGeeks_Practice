/*

    problem=BST_elements_in_range(easy).cpp

    You don't need to read input or print anything. Your task is to complete the function printNearNodes() which takes the root Node of the BST and the range elements low and high as inputs and returns an array that contains the BST elements in the given range low to high (inclusive) in non-decreasing order.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(N).

Constraints:
1 <= T <= 100
1 <= N <= 104
1 <= l < h < 105

Example:
Input:
2
17 4 18 2 9
4 24
16 7 20 1 10
13 23
Output:
4 9 17 18
16 20

    */




void inorder(Node *root,int l,int h,vector<int> &v)
{
    if(root==NULL)
    {
        return ;
    }

    inorder(root->left,l,h,v);
    if(root->data<=h && root->data>=l)
    v.push_back(root->data);
    inorder(root->right,l,h,v);

}
vector<int> printNearNodes(Node *root, int l, int h)
{
   vector<int> v;

   inorder(root,l,h,v);
   return v;
}
