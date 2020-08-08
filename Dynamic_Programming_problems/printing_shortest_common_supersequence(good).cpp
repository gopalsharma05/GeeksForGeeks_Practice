/*

    problem-> printing_shortest_common_supersequence(good).cpp



    problem_link  -> https://leetcode.com/problems/shortest-common-supersequence/




    Given two strings str1 and str2, return the shortest string that has both str1 and str2 as subsequences.  If multiple answers exist, you may return any
    of them.

(A string S is a subsequence of string T if deleting some number of characters from T (possibly 0, and the characters are chosen anywhere from T) results in
 the string S.)



Example 1:

Input: str1 = "abac", str2 = "cab"
Output: "cabac"
Explanation:
str1 = "abac" is a subsequence of "cabac" because we can delete the first "c".
str2 = "cab" is a subsequence of "cabac" because we can delete the last "ac".
The answer provided is the shortest such string that satisfies these properties.


Note:

1 <= str1.length, str2.length <= 1000
str1 and str2 consist of lowercase English letters.


            */




class Solution {
public:
    string shortestCommonSupersequence(string a, string b) {

        int n=a.length(),m=b.length();

        int dp[n+1][m+1];

        // making LCS matrix
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=m;j++)
            {
                if(i==0  || j==0)
                {
                    dp[i][j]=0;
                }
                else if(a[i-1]==b[j-1])
                    dp[i][j]=1+dp[i-1][j-1];
                else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }

        int i=n,j=m;
        string s="";
        while(i>0 && j>0)
        {
            if(a[i-1]==b[j-1])   // if element are same, it means they are part of LCS, so
                                    // so add only one of them.
            {
                s+=a[i-1];
                i--;
                j--;
            }
            else
            {
                if(dp[i][j]==dp[i-1][j])
                {
                    s+=a[i-1];
                    i--;
                }
                else
                {
                    s+=b[j-1];
                    j--;
                }
            }
        }


        while(i>0)
        {
            s+=a[i-1];
            i--;
        }

        while(j>0)
        {
            s+=b[j-1];
            j--;
        }

        reverse(s.begin(),s.end());
        return s;




    }
};
