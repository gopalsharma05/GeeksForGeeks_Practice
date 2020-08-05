/*

    problem-> Coin_Change-Minimum_number_of_coins(good).cpp


    You are given an amount denoted by value. You are also given an array of coins. The array contains the denominations of the give coins. You need to
    find the minimum number of coins to make the change for value using the coins of given denominations. Also, keep in mind that you have infinite supply
     of the coins. If making the change is not possible then print "Not Possible"


Input Format:
The first line of input contains number of testcases. Number of testcases follow. Each testcase contains three line of input. The first line contains
value for which you need to make the change. The second line contains size of the array. The third line contains the denominations of the coins.

Output Format:
For each testcase, in a new line, print the minimum number of coins required.

Your Task:
This is a function problem. The input is already taken by the driver code.  You only need to complete the function minimumNumberOfCoins() that take array
of coins, size of array, and value as parameters. You need to return the minimum number of coins required. If it is not possible to make the exact value
out of the given coin denominations, return -1.

Expected Time Complexity: O(N*V).
Expected Auxiliary Space: O(V)

Constraints:
1 <= T <= 100
1 <= value <= 103
1 <= numberOfCoins <= 103
1 <= coinsi <= 1000

Example:
Input:
2
5
3
3 6 3
10
4
2 5 3 6
Output:
Not Possible
2

Explanation:
Testcase1: We need to make the change for value = 5
The denominations are {3,6,3}
It is certain that we cannot make 5 using any of these coins.
Testcase2: We need to make the change for value = 10
The denominations are {2,5,3,6}
We can use two 5 coins to make 10. So minimum coins are 2.



        */



int dp[1005][1005];
int find(int coins[],int n,int val)
{
    if(n==0)
    return INT_MAX-1;       // INT_MAX-1 because, if we add 1 to INT_MAX ,,, it will become negative ...so for safety purpose we use INT_MAX-1

      if(val==0)
      return 0;

      if(dp[n][val]!=-1)
      return dp[n][val];



    if(coins[n-1]>val)
    return dp[n][val]=find(coins,n-1,val);

    return dp[n][val]=min(1+find(coins,n,val-coins[n-1]),find(coins,n-1,val));
}

//Complete this function
long long minimumNumberOfCoins(int coins[],int n,int val)
{
    memset(dp,-1,sizeof(dp));
     int g=find(coins,n,val);
     if(g==INT_MAX-1)
     return -1;

     else
     return g;
}
