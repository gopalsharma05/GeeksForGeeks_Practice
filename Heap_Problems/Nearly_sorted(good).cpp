/*

    problem->  Nearly_sorted(good).cpp



    Given an array of n elements, where each element is at most k away from its target position, you need to sort the array optimally.

Input:
The first line of input contains T denoting the number of testcases. T testcases follow. Each testcase contains two lines of input. The first line contains two elements n and k separated by a space. The second line contains n elements of array.

Output:
For each testcase, in a new line, print the sorted array.

Note: DO NOT use STL sort() function for this question.

Constraints:
1 <= T <= 50
1 <= n <= 106
1 <= k <= n
1 <= arri <= 107

Examples:
Input:
2
7 3
6 5 3 2 8 10 9
5 2
4 3 1 2 5
Output:
2 3 5 6 8 9 10
1 2 3 4 5

        */


// DYANMO123

#include<bits/stdc++.h>
using namespace std;
#define lli long long int

int main()
{
    lli t;
    cin>>t;
    while(t--)
    {

        lli n,k;
        cin>>n>>k;

        lli a[n];
        for(lli i=0;i<n;i++)
        {
            cin>>a[i];

        }

        priority_queue<lli,vector<lli> ,greater<lli> > pq;

        for(lli i=0;i<=k;i++)
        {
            pq.push(a[i]);

        }



        for(lli i=k+1;i<n;i++)
        {
            cout<<pq.top()<<" ";
            pq.pop();
            pq.push(a[i]);


        }

        while(!pq.empty())
        {

            cout<<pq.top()<<" ";
            pq.pop();


        }

        cout<<endl;


    }

}
