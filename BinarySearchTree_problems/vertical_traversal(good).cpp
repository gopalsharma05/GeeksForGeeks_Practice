/*

    problem=vertical_traversal(good).cpp

You are given a binary tree for which you have to print its vertical order traversal. your task is to complete the function verticalOrder
which takes one argument the root of the binary tree and prints the node of the binary tree in vertical order as shown below.
If there are multiple nodes passing through a vertical line, then they should be printed as they appear in level order traversal.

Note: This question is tagged as BST because to solve the questions efficiently, we need to use an ordered map (map in C++ and TreeMap in Java).
 The ordered maps are mainly implemented using self-balancing-BST.

Input Format:
First line of input contains the number of test cases T. For each test case, there will be only a single line of input which is a string representing
the tree as described below:

The values in the string are in the order of level order traversal of the tree where, numbers denotes node values, and a character “N”
denotes NULL child.



Output Format:
For each testcase, the vertical order traversal of the tree is to be printed. The nodes' data are to be separated by spaces.

Your Task:
This is a function problem. Your task is to just complete the verticalOrder() function and you don't have to take any input or output.
 The newline is automatically appended by the driver code.

Constraints:
1 <= T <= 100
1 <= Number of nodes <= 5000

Example:
Input:
3
2 N 3 4 N
1 2 3 4 5 N 6
3 1 5 N 2 4 7 N N N N 6
Output:
2 4 3
4 2 1 5 3 6
1 3 2 4 5 6 7
Explanation:
Testcase1:
         2
           \
            3
            /
         4
As it is evident from the above diagram that during vertical traversal 2, 4 will come first, then 3. So output is 2 1 5 3
Testcase2:
             1
           /     \
         2       3
      /     \        \
    4       5       6
As it is evident from the above diagram that during vertical traversal 4 will come first, then 2, then 1,5, then 3 and then 6. So the output is 4 2 1 5 3 6.


        */



// code is

void verticalOrder(Node *root)
{

    queue<pair<Node*,int> > q;
    q.push({root,0});
    map<int,vector<int> > m;
    m[0].push_back(root->data);
    while(!q.empty())
    {
        pair<Node*,int> p=q.front();
        q.pop();
        int l=p.second;
        Node* nod=p.first;
        if(nod->left)
        {
            m[l-1].push_back(nod->left->data);
            q.push({nod->left,l-1});
        }

        if(nod->right)
        {
             m[l+1].push_back(nod->right->data);
            q.push({nod->right,l+1});
        }



    }

    for(auto itr=m.begin();itr!=m.end();itr++)
    {
        for(int i=0;i<m[itr->first].size();i++)
        {
            cout<<m[itr->first][i]<<" ";
        }
    }



}
