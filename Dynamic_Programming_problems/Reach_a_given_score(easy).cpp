/*
    problem->  Reach_a_given_score(easy).cpp


    Consider a game where a player can score 3 or 5 or 10 points in a move. Given a total score n, find the number of distinct combinations to reach the
    given score.

Input:
The first line of input contains an integer T denoting the number of test cases. T test cases follow. The first line of each test case is n.

Output:
For each test case, print the number of ways/combinations to reach the given score in a new line.

User Task:
Complete count() function which takes N as an argument and returns the number of ways/combinations to reach the given score.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(N).

Constraints:
1 ≤ T ≤ 100
1 ≤ n ≤ 1000

Example:
Input:
3
8
20
13
Output:
1
4
2

Explanation:
Testcase 1:when n = 8 , { 3, 5 } and {5, 3} are the two possible permutations but these represent the same cobmination. Hence output is 1.
Testcase 2: When n = 20 , {10,10} , {5,5,5,5} , {10,5,5} and {3,3,3,3,3,5} are different possible permutations . Hence output will be 4.
Testcase 3: When n = 13 , {10,3} and {5,5,3} are different possible permutations. Hence the output will be 2.

        */




ll count(ll n) {

   int a[3]={3,5,10};
   int dp[n+1]={0};
   dp[0]=1;

   for(int i=0;i<3;i++)
   {
       for(int j=a[i];j<=n;j++)
       {
           dp[j]+=dp[j-a[i]];
       }
   }

   return dp[n];



}
