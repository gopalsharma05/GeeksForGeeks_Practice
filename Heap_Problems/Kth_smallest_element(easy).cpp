/*

    problem-> Kth_smallest_element(easy).cpp

Given an array arr[] of N positive integers and a number K. The task is to find the kth smallest element in the array.

Input:
First line of input contains number of testcases. For each testcase, there will be a single line of input containing number of elements in the array and K. Next line contains N elements.

Output:
For each testcase, there will be a single line of output containing the kth smallest element in the array.

Constraints:
1 <= T <= 100
1 <= N <= 106
1 <= arr[i] <= 106
1 <= K <= N

Example:
Input:
2
5 3
3 5 4 2 9
5 5
4 3 7 6 5

Output:
4
7

Explanation:
Testcase 1: Third smallest element in the array is 4.
Testcase 2: Fifth smallest element in the array is 7.


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


        priority_queue<int > pq;
        for(int i=0;i<k;i++)
        pq.push(a[i]);

        for(int i=k;i<n;i++)
        {
            if(a[i]<pq.top())
            {
                pq.pop();
                pq.push(a[i]);

            }
        }
        cout<<pq.top()<<"\n";

	}
	return 0;
}
