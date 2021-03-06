/*

    problem->  Kadane's_Algorithm-2(good).cpp

    You are given an array arr of size sizeOfArr. You need to find the maximum-sum of the array provided that you cannot sum neighboring elements.

Input Format:
The first line of input contains a number T denoting the number of test cases. T test cases follow. Each testcase contains two lines of input. The first
 line contains the size of the array sizeOfArr. The next line contains elements of the array arr separated by spaces.

Output Format:
For each testcase, in a new line, print the maximum sum.

Your Task:
This is a function problem. You only need to complete the function maximumSum() that takes array and sizeOfArray and returns maximum-sum of the array
provided that you cannot sum neighboring elements.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(N).

Constraints:
1 <= T <= 100
1 <= sizeOfArr <= 103
-103 <= arri <= 103

Examples:
Input:
3
5
4 5 6 7 8
5
-9 -8 8 3 -4
5
-6 -5 -3 -1 -9

Output:
18
8
-1

Explanation:
Testcase1: The given elements are 4 5 6 7 8.
For 4, the maximum sum will be 4 as no element other than 4 from index 0 to 0
For 5, the maximum sum will be 5 as we cannot add 4 and 5(neighboring elements).
For 6, the maximum sum will be 10 as we can add 6 and 4.
For 7, the maximum sum will be 12 as we can add 7 and 5.
For 8, the maximum sum will be 18 as we can add 4 and 6 and 8.


            */


long long maximumSum(int a[], int n)
{
  int dp[n]={0};
  dp[0]=max(0,a[0]);
  dp[1]=max(dp[0],a[1]);
  for(int i=2;i<n;i++)
  {
      dp[i]=max(dp[i-2]+a[i],dp[i-1]);
  }

  if(*max_element(a,a+n)<0)
  return *max_element(a,a+n);
  else
  return dp[n-1];
}
