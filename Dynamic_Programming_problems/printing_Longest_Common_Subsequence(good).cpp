/*

    problem-> printing_Longest_Common_Subsequence(good).cpp


    problem--link  --->  https://www.hackerrank.com/challenges/dynamic-programming-classics-the-longest-common-subsequence/problem


    A subsequence is a sequence that can be derived from another sequence by deleting some elements without changing the order of the remaining elements.
    Longest common subsequence (LCS) of 2 sequences is a subsequence, with maximal length, which is common to both the sequences.

Given two sequences of integers,  and , find the longest common subsequence and print it as a line of space-separated integers. If there are multiple common
subsequences with the same maximum length, print any one of them.

In case multiple solutions exist, print any of them. It is guaranteed that at least one non-empty common subsequence will exist



        Input Format

The first line contains two space separated integers  and , the sizes of sequences  and .
The next line contains  space-separated integers .
The next line contains  space-separated integers .

Constraints





Constraints



Output Format

Print the longest common subsequence as a series of space-separated integers on one line. In case of multiple valid answers, print any one of them.

Sample Input

5 6
1 2 3 4 1
3 4 1 2 1 3
Sample Output

1 2 3
Explanation

There is no common subsequence with length larger than 3. And "1 2 3", "1 2 1", "3 4 1" are all correct answers.



            */

#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;

    int a[n],b[m];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];

    }

    for(int i=0;i<m;i++)
    {
        cin>>b[i];

    }

    int dp[n+1][m+1];

    // creating the LCS matrix

    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=m;j++)
        {
            if(i==0 || j==0)
            dp[i][j]=0;

            else if(a[i-1]==b[j-1])
            {
                dp[i][j]=1+dp[i-1][j-1];
            }
            else
            {
                dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
            }


        }
    }

    vector<int> v;

    int i=n,j=m;
    while(i>0 && j>0)
    {
        if(a[i-1]==b[j-1])
        {
            v.push_back(a[i-1]);
            i=i-1;
            j=j-1;
        }
        else
        {
            if(dp[i][j]==dp[i-1][j])
            {
                i=i-1;

            }
            else {
            j=j-1;
            }
        }
    }

    reverse(v.begin(),v.end());

    for(int i=0;i<v.size();i++)
    cout<<v[i]<<" ";




}
