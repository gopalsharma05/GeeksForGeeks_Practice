/*

    problem --> Combination_Sum(good).cpp

   Given an array of integers A and a sum B, find all unique combinations in A where the sum is equal to B. The same repeated number may be chosen from A unlimited number of times.

Note:
        1. All numbers will be positive integers.
        2. Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
        3. The combinations themselves must be sorted in ascending order.

Input:
First line of input contains number of testcases T. For each testcase, there will be three lines of input, first of which contains N, size of array. Next line contains N space seperated integers, and the last line contains B.

Output:
For each testcase, print the sets enclosing a backet "(" and ")". No space between two sets. If no set can be formed with the given set, then print "Empty" (without quotes).

Constraints:
1 <= T <= 500
1 <= N <= 12
1 <= A[i] <= 9
1 <= B <= 30

Example:
Input:
3
4
7 2 6 5
16
11
6 5 7 1 8 2 9 9 7 7 9
6
4
2 4 6 8
8

Output:
(2 2 2 2 2 2 2 2)(2 2 2 2 2 6)(2 2 2 5 5)(2 2 5 7)(2 2 6 6)(2 7 7)(5 5 6)
(1 1 1 1 1 1)(1 1 1 1 2)(1 1 2 2)(1 5)(2 2 2)(6)
(2, 2, 2, 2)(2, 2, 4)(2, 6)(4, 4)(8)

Explanation:
Testcase 1: Required sets with sum equal to B (8) are as follows:
[2, 2, 2, 2]
[2, 2, 4]
[2, 6]
[4, 4]
[8]
]

        */


#include <bits/stdc++.h>
using namespace std;


void backtrack(int a[],int n,int sum,vector<int> v,set< vector<int> > &s,int i )
{
    if(sum==0)
    {
        s.insert(v);
        return ;
    }

    if(sum<0  || i>=n || a[i]>sum)
    return ;



    v.push_back(a[i]);
    backtrack(a,n,sum-a[i],v,s,i);
    v.pop_back();

    backtrack(a,n,sum,v,s,i+1);

}


int main() {
	//code
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    int a[n],k=0;
	    unordered_map<int,int> m;
	    for(int i=0;i<n;i++)
	    {
	        cin>>a[i];
	        m[a[i]]++;
	        if(m[a[i]]==1)
	        a[k++]=a[i];

	    }

	    int sum;
	    cin>>sum;

	    sort(a,a+k);
	    set<vector<int> > s;
	    vector<int> v;



	    backtrack(a,k,sum,v,s,0);

	    if(s.size()==0)
	    cout<<"Empty\n";
	    else
	    {

	    for(auto x:s)
	    {
	        vector<int> v=x;
	        cout<<"(";
	        for(int i=0;i<v.size();i++)
	        {
	            cout<<v[i];
	            if(i!=v.size()-1)
	            cout<<" ";

	        }

	        cout<<")";

	    }

	    cout<<endl;
	    }


	}

	return 0;
}
