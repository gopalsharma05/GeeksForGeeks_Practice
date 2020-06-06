/*
    problem-> Subsets(good).cpp

    Given an array of integers that might contain duplicates, return all possible subsets.

Note:

        Elements in a subset must be in non-descending order.
        The solution set must not contain duplicate subsets.
        The subsets must be sorted lexicographically.

Input:
First line of input contains number of testcases T. For each testcase, there will be two line of input, first of which contains N and next contains N space seperated integers. Every test case has two lines. First line is N, size of array.

Output:
One line per test case, every subset enclosed in () and in every set intergers should be space seperated.(See example)

Constraints:
1 <= T <= 500
1 <= N <= 12
1 <= x <= 9

Example:
Input:
2
3
1 2 2
4
1 2 3 3

Output:
()(1)(1 2)(1 2 2)(2)(2 2)
()(1)(1 2)(1 2 3)(1 2 3 3)(1 3)(1 3 3)(2)(2 3)(2 3 3)(3)(3 3)

Explanation:
Testcase 1: Subsets are
[
[],
[1],
[1,2],
[1,2,2],
[2],
[2, 2]
]

        */


// approach  -->    Bit Masking

#include <bits/stdc++.h>
using namespace std;



// dynamo123


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

	   set< vector<int> > s;

	   for(int i=0;i<pow(2,n);i++)
	   {
	       vector<int> v;
	       for(int j=0;j<n;j++)
	       {
	           if(i &  (1<<j) )
	           v.push_back(a[j]);
	       }

	       s.insert(v);
	   }

	 for(auto x:s)
	 {
	     cout<<"(";
	     vector<int> v=x;
	     int n=v.size();
	     for(int i=0;i<v.size();i++)
	     {
	     cout<<v[i];
	     if(i!=n-1)
	     cout<<" ";
	     }

	     cout<<")";




	 }

	 cout<<endl;



	}
	return 0;
}
