/*

    problem-> Shortest_Common_Supersequence(good).cpp


    Given two strings X and Y of lengths m and n respectively, find the length of the smallest string which has both, X and Y as its sub-sequences.
Note: X and Y can have both uppercase and lowercase letters.

Input:
The first line of input contains an integer T denoting the number of test cases. Each test case contains two space-separated strings X and Y.

Output:
For each testcase, in a new line, print the length of the required string.

Your Task:
Complete shortestCommonSupersequence() function that takes X, Y, m, and n as arguments and returns the length of the required string.

Expected Time Complexity: O(Length(X) * Length(Y)).
Expected Auxiliary Space: O(Length(X) * Length(Y)).

Constraints:
1 <= T <= 100
1<= |X|, |Y| <= 100

Example:
Input:
2
abcd xycd
efgh jghi

Output:
6
6

Explanation:
Testcase1: Shortest Common Supersequence would be abxycd which is of length 6 and has both the strings as its subsequences.
Testcase2: Shortest Common Supersequence would be ejfghi which is of length 6 and has both the strings as its subsequences.


            */


     // APPROACH->    M+N-LCS(string a,string b) ,,,where M AND N ARE LENGTH OF string a and  string b,.... LCS means longest common subsequence



int shortestCommonSupersequence(char* a, char* b, int n, int m) {

    int dp[n+1][m+1];
    for(int i=0;i<=n;i++)
    for(int j=0;j<=m;j++)
    if(i==0 ||  j==0)
    dp[i][j]=0;

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(a[i-1]==b[j-1])
            dp[i][j]=1+dp[i-1][j-1];
            else
            dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    }

    return m+n-dp[n][m];   //dp[n][m] contains the LCS of both string



}
