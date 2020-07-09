/*
    problem->  Serialize_and_Deserialize_Binary_Tree(good).cpp

    Serialization is to store a tree in an array so that it can be later restored and Deserialization is reading tree back from the array. Now your task
    is to complete the function serialize which stores the tree into an array A[ ] and deSerialize which deserializes the array to tree and returns it.
Note: The structure of tree must be maintained.

Input:
First line of input contains the number of test cases T. For each test case, there will be only a single line of input which is a string representing
the tree as described below:

The values in the string are in the order of level order traversal of the tree where, numbers denotes node values, and a character “N” denotes NULL child.



Output:
The output in the expected output will be the inorder traversal of the returned tree.

Your Task:
The task is to complete two function serialize which takes the root node of the tree as input andstores the tree into an array and deSerialize which
deserializes the array to the original tree and returns the root of it.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(N).

Constraints:
1 <= T <= 100
1 <= Number of nodes <= 1000
1 <= Data of a node <= 1000

Example:
Input:
2
1 2 3
10 20 30 40 60
Output:
2 1 3
40 20 60 10 30

Explanation:
Testcase 1: Given tree is
                           1
                       /         \
                     2           3
Hence , the given output is 2 1 3.
Testcase 2: Given tree is
                         10
                       /       \
                     20      30
                  /        \
                40      60
Hence, the given output is 40 20 60 10 30.






            */

void serialize(Node *root,vector<int> &v)
{
    if(root==NULL)
    return ;

    queue<Node*> q;
    q.push(root);
    v.push_back(root->data);
    while(!q.empty())
    {
        Node *temp=q.front();
        q.pop();

        //v.push_back(temp->data);

        if(temp->left)
        {
            q.push(temp->left);
        v.push_back(temp->left->data);
        }
        else
        v.push_back(-2);


        if(temp->right)
        {
            q.push(temp->right);
            v.push_back(temp->right->data);
        }
        else
        v.push_back(-2);



    }

}

/*this function deserializes
 the serialized vector A*/
Node * deSerialize(vector<int> &v)
{
   Node *root;
   root=new Node(v[0]);
//   for(int i=0;i<v.size();i++)
//   cout<<v[i]<<"  ";

//   cout<<endl;
   queue<Node*> q;
   q.push(root);
   int i=1;
   while(i<v.size())
   {
       Node *temp=q.front();
       q.pop();

       if(temp->left==NULL)
       {
           if(v[i]!=-2)
           {
               temp->left=new Node(v[i]);
                q.push(temp->left);
           }
           else
           temp->left==NULL;

           i++;

           if(i>=v.size())
           break;


       }

       if(temp->right==NULL)
       {
           if(v[i]!=-2)
           {
               temp->right=new Node(v[i]);
               q.push(temp->right);
           }
           else
           temp->right=NULL;
           i++;


           if(i>=v.size())
           break;

       }

   }

   return root;

}
