/*

    problem-> mirror_tree(easy).cpp

    Given a Binary Tree, convert it into its mirror.
MirrorTree1

Input:
First line of input contains the number of test cases T. For each test case, there will be only a single line of input which is a string representing the tree as described below:

The values in the string are in the order of level order traversal of the tree where, numbers denotes node values, and a character “N” denotes NULL child.

For example:


For the above tree, the string will be: 1 2 3 N N 4 6 N 5 N N 7 N

Output:
For each testcase, in a new line, print inorder traversal of mirror tree.

Your Task:
You don't have to take any input. Just complete the function mirror() that takes node as paramter  and convert it into its mirror. The printing is done
by the driver code only.
Expected Time Complexity: O(N).
Expected Auxiliary Space: O(Height of the Tree).

Constraints:
1 <= T <= 100
1 <= Number of nodes <= 100
1 <= Data of a node <= 1000

Example:
Input:
2
1 3 2
10 20 30 40 60
Output:
2 1 3
30 10 60 20 40

Explanation:
Testcase1: The tree is
        1         (mirror)         1
     /     \         =>          /  \
   3       2                    2    3
The inorder of mirror is 2 1 3
Testcase2: The tree is
                           10                                    10
                        /        \           (mirror)         /     \
                     20         30            =>             30      20
                  /       \                                        /    \
               40       60                                        60    40
The inroder traversal of mirror is 30 10 60 20 40



        */

void mirror(Node* root)
{
     if(root==NULL)
     return ;

     Node *p=root->left;
     root->left=root->right;
     root->right=p;
      mirror(root->left);
      mirror(root->right);

}
