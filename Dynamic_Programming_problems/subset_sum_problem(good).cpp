/*
    problem-> subset_sum_problem(good).cpp`


    Given a set of numbers, check whether it can be partitioned into two subsets such that the sum of elements in both subsets is same or not.

Input:
The first line contains an integer 'T' denoting the total number of test cases. Each test case consists of two lines. First-line contains 'N',
representing the number of elements in the set and the second line contains the elements of the set.

Output:
For each test case, print YES if the partition is possible, otherwise print NO.

User Task:
You don't need to read input or print output, taking inputs and printing is done by the driver code. Your task is to complete the findPartition()
function which takes an array a[] and N as input parameter and return true if the given set can be partitioned into two subsets such that the sum of
elements in both subsets is equal, else return false.

Expected Time Complexity: O(N*S).
Expected Auxiliary Space: O(S) where S is the sum of the given Array.

Constraints:
1 <= T <= 100
1 <= N <= 100
0 <= arr[i] <= 1000

Example:
Input:
2
4
1 5 11 5
3
1 3 5
Output:
YES
NO

Explanation:
Testcase 1: There exists two subsets such that {1, 5, 5} and {11}.

        */

 int dp[105][100005];
int find(int a[],int n,int sum)
{
    if(sum==0)
    return true;
    if(n==0||sum<0)
    {
        return false;
    
    }
    if(dp[n][sum]!=-1)
    return dp[n][sum];
    if(a[n-1]>sum)
    return dp[n][sum]=find(a,n-1,sum);
    
    return dp[n][sum]=(find(a,n-1,sum-a[n-1])||find(a,n-1,sum));
    
}

class Solution{
public:
    int equalPartition(int N, int arr[])
    {
         memset(dp,-1,sizeof(dp));
         int sum=0;
         for(int i=0;i<N;i++)
         sum+=arr[i];
         if(sum%2==1)
         return false;
         else
         return find(arr,N,sum/2);
    }
};
