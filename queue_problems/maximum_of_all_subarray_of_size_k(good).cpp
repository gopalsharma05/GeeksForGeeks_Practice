/*

    problem-> maximum_of_all_subarray_of_size_k(good).cpp


    Given an array A and an integer K. Find the maximum for each and every contiguous subarray of size K.

Input:
The first line of input contains an integer T denoting the number of test cases. The first line of each test case contains a single integer N denoting the
 size of array and the size of subarray K. The second line contains N space-separated integers A1, A2, ..., AN denoting the elements of the array.

Output:
Print the maximum for every subarray of size k.

Constraints:
1 ≤ T ≤ 200
1 ≤ N ≤ 107
1 ≤ K ≤ N
0 ≤ A[i] <= 107

Example:
Input:
2
9 3
1 2 3 1 4 5 2 3 6
10 4
8 5 10 7 9 4 15 12 90 13

Output:
3 3 4 5 5 5 6
10 10 10 15 15 90 90

Explanation:
Testcase 1: Starting from first subarray of size k = 3, we have 3 as maximum. Moving the window forward, maximum element are as 3, 4, 5, 5, 5 and 6.




                */



#include <bits/stdc++.h>
using namespace std;

int main() {

	int t;
	cin>>t;
	while(t--)
	{
	    int n,k;
	    cin>>n>>k;
	    int a[n];
	    for(int i=0;i<n;i++)
	    {
	       cin>>a[i];
	    }

	   deque<int> dq;

	   for(int i=0;i<k;i++)
	   {
	       while(!dq.empty()&&a[i]>=a[dq.back()])
	       dq.pop_back();

	       dq.push_back(i);


	   }


	   for(int i=k;i<n;i++)
	   {
	       cout<<a[dq.front()]<<" ";
	       while(!dq.empty() &&dq.front()<=i-k)
	       dq.pop_front();

	       while(!dq.empty() && a[i]>=a[dq.back()])
	       {
	           dq.pop_back();
	       }

	       dq.push_back(i);


	   }

	   cout<<a[dq.front()]<<" ";
	   cout<<endl;

	}

	return 0;
}
