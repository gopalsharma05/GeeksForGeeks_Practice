/*

        problem->  k_largest_elements(easy).cpp

        Given an array of N positive integers, print k largest elements from the array.  The output elements should be printed in decreasing order.

Input:
The first line of input contains an integer T denoting the number of test cases. The first line of each test case is N and k, N is the size of array and K is the largest elements to be returned. The second line of each test case contains N input C[i].

Output:
Print the k largest element in descending order.

Constraints:
1 ≤ T ≤ 100
1 ≤ N ≤ 100
K ≤ N
1 ≤ C[i] ≤ 1000

Example:
Input:
2
5 2
12 5 787 1 23
7 3
1 23 12 9 30 2 50

Output:
787 23
50 30 23

Explanation:
Testcase 1: 1st largest element in the array is 787 and second largest is 23.
Testcase 2: 3 Largest element in the array are 50, 30 and 23.

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
	    lli n,k;
	    cin>>n>>k;
	    lli a[n];
	    for(int i=0;i<n;i++)
	    {
	        cin>>a[i];
	    }


        priority_queue<int,vector<int>,greater<int> > pq;
        for(int i=0;i<k;i++)
        pq.push(a[i]);

        for(int i=k;i<n;i++)
        {
            if(a[i]>pq.top())
            {
                pq.pop();
                pq.push(a[i]);

            }
        }
        vector<int> v;
        while(!pq.empty())
        {
            v.push_back(pq.top());
            pq.pop();

        }

        for(int i=v.size()-1;i>=0;i--)
        cout<<v[i]<<" ";

        cout<<"\n";

	}
	return 0;
}
