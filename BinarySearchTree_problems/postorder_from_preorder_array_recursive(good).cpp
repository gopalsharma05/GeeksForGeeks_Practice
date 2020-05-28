/*
    problem- postorder_from_preorder_array_recursive(good).cpp

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




void postorder(a,&s,min,max,n)
{
    if(s==n ||  a[s]<min || a[s]>max)
    return ;

    int curr=a[s++];
    postorder(a,s,min,curr,n);
    postorder(a,s,curr,max,n);
    cout<<curr<" ";
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

	    int s=0;
	    post(a,s,INT_MIN,INT_MAX,n);

	}
	return 0;
}
