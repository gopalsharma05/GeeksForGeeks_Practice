
/*

    probelm-> longest_palindromic_subsequence_using_memoization(good).cpp



    problem--link-- >  https://leetcode.com/problems/longest-palindromic-subsequence/




    APPROACH->
        If the characters matches
		- Then we have gained a palindrome length of 2

	-    If the characters does not match
		- We have two choices
			- We can move the 'start' pointer to the right by 1 index or move the 'end' pointer to the left by 1 index and return max of them






            */





// below solution is using memoization
int dp[1005][1005];
int LPS(int l, int r, String s) {
        if (l == r) return 1;
        if (l > r) return 0;
        if (dp[l][r] != -1) return dp[l][r];

        if (s[l] == s[r]) {
            return dp[l][r] = LPS(l + 1, r - 1, s) + 2;

        } else {
         return dp[l][r] =max(LPS(l + 1, r, s), LPS(l, r - 1, s));

        }
    }


int findLPS(string s)
{
    memset(dp,-1,sizeof(dp));

    int l=0,r=s.length()-1;

    return LPS(l,r,s);



}
