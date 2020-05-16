/*

    problem->subarrays_having_equal_number_of_0s_and_1s

    Given an array arr[] of size N containing 0s and 1s only. The task is to count the subarrays having equal number of 0s and 1s.

Input:
The first line of input contains an integer T denoting the number of test cases. Then T test cases follow. Each test case consists of two lines. First line of each test case contains an Integer N denoting size of array and the second line contains N space separated 0 and 1.

Output:
For each test case, print the count of required sub arrays in new line.

Constraints:
1 <= T <= 100
1 <= N <= 106
0 <= A[i] <= 1

Example:
Input:
2
7
1 0 0 1 0 1 1
5
1 1 1 1 0

Output:
8
1

Explanation:
Testcase 1: The index range for the 8 sub-arrays are:
(0, 1), (2, 3), (0, 3), (3, 4), (4, 5)
(2, 5), (0, 5), (1, 6)

    */


    #include <bits/stdc++.h>
using namespace std;
#define lli long long int

int main() {
	//code

	lli  t;
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
	        if(a[i]==0)
	        a[i]=-1;


	    }


	    lli sum=0,cnt=0;
	    for(lli i=0;i<n;i++)
	    {
	        sum+=a[i];

	        if(sum==0)
	        cnt++;

	        if(m[sum]!=0)
	        {
	            cnt+=m[sum];
	        }
	        m[sum]++;
	    }
	    cout<<cnt<<"\n";


	}
	return 0;
}
