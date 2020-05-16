/*

problem=positive_negative_pair(easy)

    Given an array arr[] of N positive and negative integer pairs, may not be in sorted order. The task is to pair the positive and negative element in such a way that a positive element is paired with a negative element of same absolute value. If a pair element is not present for an element, then ignore it. The output should contain all pairs in increasing order of absolute values. To print a pair, positive value should be printed before its corresponding negative value.
Note: The elements in array are distinct.

Input:
First line of input contains number of testcases T. For each testcase, first line contains an integer N, number of elements in the array. Next line contains N space separated array elements.

Output:
For each testcase, print the pairs of positive and negative, sorted with positive numbers. If no such pair exists, print 0.

Constraints:
1 <= T <= 100
1 <= N <= 106
-106 <= arr[i] <= 106

Example:
Input:
2
8
1 3 6 -2 -1 -3 2 7
3
3 2 -3
Output:
1 -1 2 -2 3 -3
3 -3

Explanation:
Testcase 1: 1, 2 and 3 are present pairwirse postive and negative. 6 and 7 have no pair.
Testcase 2: 3 is the only element present pairwise positive and negative.

        */



 #include <bits/stdc++.h>
using namespace std;
#define lli long long int

int main() {
	//code

	lli t;
	cin>>t;
	while(t--)
	{
	    lli n;
	    cin>>n;
	    lli a[n];
	    map<lli,lli> m;
	    for(lli i=0;i<n;i++)
	    {
	        cin>>a[i];
	        m[a[i]]=1;
	    }

	    bool flag=false;

	    vector< pair<lli,lli> > v;
	    for(auto i=m.begin();i!=m.end();i++)
	    {
	        if(i->first<0)
	        {
	            if(m[abs(i->first)]!=0)
	            {
	               // cout<<abs(i->first)<<" "<<i->first<<" ";
	               v.push_back({abs(i->first),i->first});
	                flag=true;
	            }
	        }
	   }

	   if(flag==false)
	   cout<<"0";

	   else
	   {
	       sort(v.begin(),v.end());
	       for(lli i=0;i<v.size();i++)
	       cout<<v[i].first<<" "<<v[i].second<<" ";
	   }

	   cout<<endl;


	}
	return 0;
}
