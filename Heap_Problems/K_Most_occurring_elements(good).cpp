/*
    problem-> K_Most_occurring_elements(good).cpp

    Given an array arr[] of N integers in which elements may be repeating several times. Also, a positive number K is given and the task is to find sum of total frequencies of K most occurring elements

Note: The value of K is guaranteed to be less than or equal to the number of distinct elements in arr.

Input:
First line of input contains number of testcases T. For each testcase, first line of input contains the size of array N, and next line contains N positive integers. The last line contains K.

Output:
For each testcase, print the sum of total frequencies of K most occurring elements in the given array.

Constraints:
1 <= T <= 100
1 <= K <= N
1 <= N <= 107
1 <= arr[i] <= 106

Example:
Input:
2
8
3 1 4 4 5 2 6 1
2
8
3 3 3 4 1 1 6 1
2

Output:
4
6

Explanation:
Testcase 1: Since, 4 and 1 are 2 most occurring elements in the array with their frequencies as 2, 2. So total frequency is 2 + 2 = 4.

Testcase 2: Since, 3 and 1 are most occurring elements in the array with frequencies 3, 3 respectively. So, total frequency is 6.



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
	    unordered_map<lli,lli> m;
	    for(lli i=0;i<n;i++)
	    {
	        cin>>a[i];
	        m[a[i]]++;


	    }

	    lli k;
	    cin>>k;


	    lli cnt=0,ans=0;

	    priority_queue<lli,vector<lli>, greater<lli> > pq;

	    unordered_map<lli,lli> :: iterator itr;

	    for(itr=m.begin();itr!=m.end();itr++)
	    {
	        pq.push(itr->second);
	        cnt++;
	        if(cnt==k)
	        break;

	    }
	    if(itr!=m.end())
	    {
	    itr++;
	    while(itr!=m.end())
	    {

	        if(itr->second>pq.top())
	        {
	            pq.pop();
	            pq.push(itr->second);

	        }
	        itr++;

	    }
	    }

	    while(!pq.empty())
	    {
	        ans+=pq.top();
	        pq.pop();
	    }


	    cout<<ans<<"\n";



	}
	return 0;
}
