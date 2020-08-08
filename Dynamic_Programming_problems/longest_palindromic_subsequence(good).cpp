/*

    probelm-> longest_palindromic_subsequence(good).cpp



    problem--link-- >  https://leetcode.com/problems/longest-palindromic-subsequence/





            */


      // APPROACH -> JUST FIND THE LCS(STRING, REVERSE(STRING))


int LPS(string a,string b, int n)
{
    int dp[n+1][n+1];
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=n;j++)
        {
            if(i==0 || j==0)
                dp[i][j]=0;
            else if(a[i-1]==b[j-1])
            {
                dp[i][j]=1+dp[i-1][j-1];
            }
            else
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    }

    return dp[n][n];
}

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n=s.length();
        string a=s;
        reverse(s.begin(),s.end());

        return LPS(a,s,n);

    }
};
