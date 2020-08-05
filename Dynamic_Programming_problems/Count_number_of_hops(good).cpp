/*

    problem-> Count_number_of_hops(good).cpp


    A frog jumps either 1, 2 or 3 steps to go to top. In how many ways can it reach the top.

Input:
The first line of input contains an integer T denoting the number of test cases. T testcases follow. Each testcase contains one line of input N denoting
the total number of steps.

Output:
For each testcase, in a new line, print the number of ways to reach the top.

Constraints:
1 ≤ T ≤ 100
1 ≤ N ≤ 50

Example:
Input:
2
1
5
Output:
1
13


            */

// APPROACH-->  TRY SOME EXAMPLE,,,YOU WILL FIND PATTERN LIKE FIBONACCI , BUT OF THREEE NUMBER.....so you have to just print nth number for this pattern

#include <bits/stdc++.h>
using namespace std;
#define  lli long long int


int main() {
	//code
    lli t;
    cin>>t;
      int a[100];
        a[0]=1;
        a[1]=1;
        a[2]=2;

        for(int i=3;i<100;i++)
        a[i]=a[i-1]+a[i-2]+a[i-3];





    while(t--)
    {

        lli n;
        cin>>n;
        cout<<a[n]<<"\n";

    }
	return 0;
}
