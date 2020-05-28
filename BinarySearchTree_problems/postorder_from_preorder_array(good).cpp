/*
    problem- postorder_from_preorder_array(good).cpp

    Given an array arr[] of N nodes representing preorder traversal of BST. The task is to print its postorder traversal.

Input:
The first line of input contains an integer T denoting the number of test cases. The first line of each test case is N, the size of array. The second line of each test case contains N input as arr[i].

Output:
Postorder traversal of the given preorder traversal is printed.

Constraints:
1 <= T <= 100
1 <= N <= 103
1 <= arr[i] <= 104

Example:
Input:
3
5
40 30 35 80 100
8
40 30 32 35 80 90 100 120

Output:
35 30 100 80 40
35 32 30 120 100 90 80 40

*/


// I first create the bst from preorder then use postorder traversal

#include <bits/stdc++.h>
using namespace std;


struct Node{
    int data;
    Node* left,*right;

    Node(int k)
    {
        data=k;
        left=right=NULL;
    }
};


void preorder(Node *root)
{
    if(root==NULL)
    return ;

    preorder(root->left);
    preorder(root->right);
    cout<<root->data<<" ";
}

int main() {


	//code

	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    int a[n];
	    for(int i=0;i<n;i++)
	    cin>>a[i];

	   Node *root=new Node(a[0]);

	   stack<Node*> st;
	   st.push(root);


	   for(int i=1;i<n;i++)
	   {
	       Node *temp=NULL;
	       while(!st.empty() && a[i]>st.top()->data)
	       {
	           temp=st.top();
	           st.pop();
	       }

	       if(temp==NULL)
	       {
	           st.top()->left=new Node(a[i]);
	           st.push(st.top()->left);
	       }
	       else
	       {
	           temp->right=new Node(a[i]);
	           st.push(temp->right);
	       }
	   }


	   preorder(root);
	   cout<<endl;

	}
	return 0;
}
