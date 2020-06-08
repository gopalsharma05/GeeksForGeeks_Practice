/*

    problem  -->  Combination_Sum_Part2(good).cpp

Given an array of integers A and a sum B, find all unique combinations in A where the sum is equal to B.

ach number in A may only be used once in the combination.

Note:
   All numbers will be positive integers.
   Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
   The combinations themselves must be sorted in ascending order.
   If there is no combination possible the print "Empty" (without qoutes).
Example,
Given A = 10,1,2,7,6,1,5 and B(sum) 8,

A solution set is:

[1, 7]
[1, 2, 5]
[2, 6]
[1, 1, 6]

Input:
First is T , no of test cases. 1<=T<=500
Every test case has three lines.
First line is N, size of array. 1<=N<=12
Second line contains N space seperated integers(x). 1<=x<=9.
Third line is the sum B. 1<=B<=30.

Output:
One line per test case, every subset enclosed in () and in every set intergers should be space seperated.(See example)

Example:
Input:
2
7
10 1 2 7 6 1 5
8
5
8 1 8 6 8
12

Output:
(1 1 6)(1 2 5)(1 7)(2 6)
Empty


*/


#include <bits/stdc++.h>
using namespace std;

void backtrack(int a[],int n,int sum,set<vector<int> > &s,vector<int> v,int i)
{
    if(sum==0)
    {
        s.insert(v);
        return ;
    }

    if(i>=n ||  sum<0 || a[i]>sum)
    return ;

    v.push_back(a[i]);
    backtrack(a,n,sum-a[i],s,v,i+1);
    v.pop_back();
    backtrack(a,n,sum,s,v,i+1);
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

	    sort(a,a+n);

	    set<vector<int> > s;
	    vector<int> v;

	    int sum;
	    cin>>sum;

	    backtrack(a,n,sum,s,v,0);


	    if(s.size())
	    {
            for(auto x:s)
            {
                vector<int> v=x;
                cout<<"(";
                int n=v.size();
                for(int i=0;i<n;i++)
                {

                    cout<<v[i];
                    if(i!=n-1)
                    cout<<" ";

                }

                cout<<")";




            }


            cout<<"\n";
	    }
	    else
	    {
	        cout<<"Empty\n";
	    }


	}
	return 0;
}
