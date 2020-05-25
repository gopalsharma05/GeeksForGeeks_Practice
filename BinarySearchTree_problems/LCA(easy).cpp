/*
   probelem= LCA(easy).cpp

You don't need to read input or print anything. Your task is to complete the function LCA() which takes the root Node of the BST and two integer values n1 and n2 as inputs and returns the Lowest Common Ancestor of the Nodes with values n1 and n2 in the given BST.

Expected Time Complexity: O(Height of the BST).
Expected Auxiliary Space: O(Height of the BST).

Constraints:
1 <= T <= 100
1 <= N <= 104

Example:
Input:
2
5 4 6 3 N N 7 N N N 8
7 8
2 1 3
1 3
Output:
7
2

        */



        Node* LCA(Node *root, int n1, int n2)
{
   while(root!=NULL)
   {
       if((root->data==n1 ||  root->data==n2) ||(min(n1,n2)<root->data && root->data<(max(n1,n2))))
       return root;
       else if(n1<root->data && n2<root->data)
       {
           root=root->left;
       }
       else if(n1>root->data && n2>root->data)
       root=root->right;
   }
   return root;



}
