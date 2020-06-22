/*

    problem -> Frequencies_of_Limited_Range_Array_Elements(good).easy

    Given an array A[] of N positive integers which can contain integers from 1 to N where elements can be repeated or can be absent from the array.
    Your task is to count frequency of all elements from 1 to N.





            Note:  EXPECTED TIME COMPLEXITY IS O(N) WITH O(1) EXTRA SPACE.






Input:
First line of input contains an integer T denoting the number of test cases. For each test case, first line contains an integer N denoting the size of array. The second line contains N space-separated integers A1, A2, ..., AN denoting the elements of the array.

Output:
For each test case, output N space-separated integers denoting the frequency of each element from 1 to N.

Constraints:
1 ≤ T ≤ 100
1 ≤ N ≤ 106
1 <= A[i] <= 106

Example:
Input:
2
5
2 3 2 3 5
4
3 3 3 3

Output:
0 2 2 0 1
0 0 4 0

Explanation:
Testcase 1: Counting frequencies of each array elements, we have:
1 occurring 0 times.
2 occurring 2 times.
3 occurring 2 times.
4 occurring 0 times.
5 occurring 1 time.





            */











#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int a[n+1];
        for(int i=1;i<=n;i++)
        cin>>a[i];

        for(int i=1;i<=n;i++)
        {
            a[a[i]%(n+1)]=a[a[i]%(n+1)]+(n+1);
        }

        for(int i=1;i<=n;i++)
        {
            cout<<a[i]/(n+1)<<" ";
        }

        cout<<endl;

    }
}
