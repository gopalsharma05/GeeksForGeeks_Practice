/*

    problem-> maxm_width_of_tree(easy).cpp

    Given a Binary Tree, find the maximum width of it. Maximum width is defined as the maximum number of nodes in any level.
For example, maximum width of following tree is 4 as there are 4 nodes at 3rd level.

          1
       /     \
     2        3
   /    \    /    \
  4    5   6    7
    \
      8

Input:

First line of input contains the number of test cases T. For each test case, there will be only a single line of input which is a string representing the tree as described below:

The values in the string are in the order of level order traversal of the tree where, numbers denotes node values, and a character “N” denotes NULL child.

For example:

For the above tree, the string will be: 1 2 3 N N 4 6 N 5 N N 7 N

Output:
For each testcase, in a new line, print the maximum width.

Your Task:
You don't have to read any input. Just complete the function getMaxWidth() that takes node as parameter and returns the maximum width. The printing is done by the driver code.
Expected Time Complexity: O(N).
Expected Auxiliary Space: O(N).

Constraints:
1 <= T <= 100
1 <= edges <= 1000
1 <= nodes values <= 105

Example:
Input:
2
1 2 3
10 20 30 40 60
Output:
2
2

Explanation:
Testcase1: The tree is
        1
     /      \
   2       3
The second level has 2 nodes and hence the width is 2.
Testcase2: The tree is
                           10
                        /        \
                     20         30
                  /       \
               40       60
Both second and third level have 2 nodes and hence max width is 2.


        */

   // DYNAMO 123

int getMaxWidth(Node* root)
{


   if(root==NULL)
   return 0;
   queue<Node*> q;
   q.push(root);
   int maxm=1,cnt=0;
   while(!q.empty())
   {
       int size=q.size();
       cnt=0;

       for(int i=0;i<size;i++)
       {
           Node *p=q.front();
           q.pop();
           if(p->left)
           {
               cnt++;
               q.push(p->left);
           }

            if(p->right)
           {
               cnt++;
               q.push(p->right);
           }

       }

       maxm=max(cnt,maxm);
   }

   return maxm;
}

