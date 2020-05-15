/*
    Given two arrays A1[] and A2[] of size N and M respectively. The task is to sort A1 in such a way that the relative order among the elements will be same as those in A2. For the elements not present in A2, append them at last in sorted order. It is also given that the number of elements in A2[] are smaller than or equal to number of elements in A1[] and A2[] has all distinct elements.
Note: Expected time complexity is O(N log(N)).

Input:
First line of input contains number of testcases. For each testcase, first line of input contains length of arrays N and M and next two line contains N and M elements respectively.

Output:
Print the relatively sorted array.

Constraints:
1 ≤ T ≤ 100
1 ≤ N,M  ≤ 106
1 ≤ A1[], A2[] <= 106

Example:
Input:
2
11 4
2 1 2 5 7 1 9 3 6 8 8
2 1 8 3
8 4
2 6 7 5 2 6 8 4
2 6 4 5
Output:
2 2 1 1 8 8 3 5 6 7 9
2 2 6 6 4 5 7 8

Explanation:
Testcase 1: After sorting the resulted output is 2 2 1 1 8 8 3 5 6 7 9.
Testcase 2: After sorting the resulted output is 2 2 6 6 4 5 7 8.

*/


/*
    LOGIC-->

1. Build unordered map of array a with each element count.
2. Scan a 2nd array lookup in map & print that element by its count.
3. sort array a and print the remaining array elements

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
	    lli n,g;
	    cin>>n>>g;
	    lli a[n],b[g];
	    unordered_map<lli,lli> m;
	    for(lli i=0;i<n;i++)
	    {
	        cin>>a[i];
	        m[a[i]]++;
	    }
	    for(lli i=0;i<g;i++)
	    {
	        cin>>b[i];
	        while(m[b[i]]!=0)
	        {
	            cout<<b[i]<<" ";
	            m[b[i]]--;
	        }
	    }

	    sort(a,a+n);
	    for(lli i=0;i<n;i++)
        {
            if(m[a[i]]!=0)
            {
                while(m[a[i]]!=0)
                {
                    cout<<a[i]<<" ";
                    m[a[i]]--;
                }
            }
        }

	    cout<<endl;

	}


	return 0;


}




