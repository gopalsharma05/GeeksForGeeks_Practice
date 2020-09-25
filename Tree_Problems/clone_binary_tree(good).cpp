/*

    problem-> clone_binary_tree(good).cpp

    Given a special binary tree having random pointers along with the usual left and right pointers. Clone the given tree.


Input:

Output: 1
Explanation: The tree was cloned successfully.

Your Task:
No need to read input or print anything. Complete the function cloneTree() which takes root of the given tree as input parameter and returns the root of the
 cloned tree.

Note: The output is 1 if the tree is cloned successfully. Otherwise output is 0.


Expected Time Complexity: O(N).
Expected Auxiliary Space: O(N).


Constraints:
1 <=Number of nodes<= 100
1 <=Data of a node<= 1000



                    */



Node * clonetree(Node *root,unordered_map<Node*,Node*> &m)
{

    if(root==NULL)
    return NULL;

    Node *nn=new Node(root->data);
    m[nn]=root;
    nn->left=clonetree(root->left,m);
    nn->right=clonetree(root->right,m);

    return nn;

}

void setrandom(Node *root,unordered_map<Node*,Node*> &m)
{
    if(root==NULL)
    return ;

    root->random=m[root]->random;
    setrandom(root->left,m);
    setrandom(root->right,m);

}


Node* cloneTree(Node* root)
{
   unordered_map<Node*,Node*> m;
   Node *cl=clonetree(root,m);
   setrandom(cl,m);

   return cl;


}
