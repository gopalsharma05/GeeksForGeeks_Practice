/*

    problem- merge_2_BSTs(good).cpp

    Given two BST, Return elements of both BSTs in sorted form.

Input Format:
The first line of input contains the number of test cases T. For each test case, there will be two lines of input. First of which is a string representing the tree as described below:

The values in the string are in the order of level order traversal of the tree where, numbers denote node values, and a character “N” denotes NULL child.


Second-line is a string which represents a BST in the same format as described above.

Output Format:
For each test case, in a new line, print the elements of both BSTs in sorted form.

Your Task:
You don't need to read input or print anything. Your task is to complete the function merge() which takes roots of both the BSTs as its input and returns an array of integers denoting the node values of both the BSTs in a sorted order.

Expected Time Complexity: O(M+N) where M and N are the sizes if the two BSTs.
Expected Auxiliary Space: O(Height of BST1 + Height of BST2).

Constraints:
1 <= T <= 10
1 <= Number of Nodes <= 100000

Example:
Input:
2
5 3 6 2 4
2 1 3 N N N 7 6
12 9 N 6 11
8 5 10 2

Output:
1 2 2 3 3 4 5 6 6 7
2 5 6 8 9 10 11 12



        */



#define pb push_back
vector<int> merge(Node *root1, Node *root2)
{

    stack<Node*> s1,s2;



        while(root1!=NULL)
        {
            s1.push(root1);
            root1=root1->left;

        }



        while(root2!=NULL)
        {
            s2.push(root2);
            root2=root2->left;

        }



    vector<int> v;

    while(!s1.empty() || !s2.empty() )
    {
        root1=NULL;
        root2=NULL;

        if(!s1.empty())
        root1=s1.top();

        if(!s2.empty())
        root2=s2.top();


        if(root1==NULL)
        {
            v.pb(root2->data);
            s2.pop();
        }
        else if(root2==NULL)
       {
            v.pb(root1->data);
            s1.pop();
       }
        else if(root1->data<=root2->data)
        {
            v.pb(root1->data);
            s1.pop();
            root2=NULL;
        }
        else
        {
            v.pb(root2->data);
            s2.pop();
            root1=NULL;
        }

        if(root1  &&  root1->right)
        {
               root1=root1->right;

            while(root1!=NULL)
            {
                s1.push(root1);
                root1=root1->left;

            }
        }

        if(root2  &&  root2->right)
        {
                root2=root2->right;
            while(root2!=NULL)
            {
                s2.push(root2);
                root2=root2->left;

            }
        }
    }

    return v;


}
