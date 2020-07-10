/*


    problem->  Maximum_sum_of_Non-adjacent_nodes(good).cpp


    Given a binary tree with a value associated with each node, we need to choose a subset of these nodes such that sum of chosen nodes is maximum under a constraint that no two chosen node in subset should be directly connected that is, if we have taken a node in our sum then we can’t take its any children in consideration and vice versa.



Input:
First line of input contains the number of test cases T. For each test case, there will be only a single line of input which is a string representing
the tree as described below:

The values in the string are in the order of level order traversal of the tree where, numbers denotes node values, and a character “N” denotes NULL child.

For example:


For the above tree, the string will be: 1 2 3 N N 4 6 N 5 N N 7 N

Output:
For each test case prints the maximum sum such that no two nodes are adjacent.

Constraints:
1 <= T <= 100
1 <= N <= 1000

Your Task:
You don't need to read input or print anything. You just have to complete function getMaxSum() which accepts root node of the tree as parameter and
returns the maximum sum as described.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(Height of the Tree).

Example:
Input:
2
11 1 2
1 2 3 4 N 5 6
Output:
11
16

Explanation:
Testcase 1: The maximum sum is sum of node 11.
Testcase 2: The maximum sum is sum of nodes 1 4 5 6 , i.e 16. These nodes are non adjacent.


            */

int ans;
int find(Node* root)
{
    if(root==NULL)
    return 0;

    int rt,lt;
    if(root->left)
    {
        lt=root->data+find(root->left->left)+find(root->left->right);
    }
    else
    lt=root->data;


    if(root->right)
    {
        rt=root->data+find(root->right->left)+find(root->right->right);
    }
    else
    rt=root->data;

    int r=find(root->left)+find(root->right);

    ans=max(lt+rt-root->data,r);

    return ans;



}
int getMaxSum(Node *root)
{

    if(root==NULL)
    return 0;

    ans=0;
    find(root);
    return ans;
}
