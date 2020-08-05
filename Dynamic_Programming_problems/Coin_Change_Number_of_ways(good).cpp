/*

    problem->  Coin_Change_Number_of_ways(good).cpp


    You have an infinite supply of coins, each having some value. Find out the number of ways to use the coins to sum-up to a certain required value.

Input Format:
The first line of input contains the number of test cases. The number of test cases follows. Each testcase contains three lines of input. The first line contains the value for which you need to make the change. The second line contains the size of the array. The third line contains the denominations of the coins.

Output Format:
For each testcase, in a new line, print the number of ways.

Your Task:
This is a function problem where you've to complete the funcion numberOfWays (). You are given an amount denoted by value. You are also given an array of
coins. The array contains the denominations of the given coins. You need to return the number of ways you can make the change for value using the coins of
given denominations. Also, keep in mind that you have an infinite supply of coins.

Expected Time Complexity: O(Number of Coins * Value).
Expected Auxiliary Space: O(Value).

Constraints:
1 <= T <= 100
1 <= value <= 103
1 <= numberOfCoins <= 103
1 <= coinsi <= 1000

Example:
Input:
2
4
3
1 2 3
10
4
2 5 3 6
Output:
4
5

Explanation:
Testcase1: We need to make the change for value = 4
The denominations are {1,2,3}
Change for 4 can be made:
1+1+1+1
1+1+2
1+3
2+2
So, as it is evident, we can do this in 4 ways.




            */




    int dp[1005][1005];
int find(int coins[],int n,int value)
{
   if(value==0)
   return 1;

   if(n==0)
   return 0;

   if(dp[n][value]!=-1)
   return dp[n][value];

   if(coins[n-1]>value)
   return dp[n][value]=find(coins,n-1,value);

   return dp[n][value]=find(coins,n,value-coins[n-1])+find(coins,n-1,value);



}

long long numberOfWays(int coins[],int n,int value)
{
    memset(dp,-1,sizeof(dp));
    return find(coins,n,value);
}
