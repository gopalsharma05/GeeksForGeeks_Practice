/*

    problem-> square_root_using_binary_search(easy).cpp


    Given an integer x. The task is to find the square root of x. If x is not a perfect square, then return floor(√x).

Example 1:

Input:
x = 5
Output: 2
Explanation: Since, 5 is not perfect
square, so floor of square_root of
5 is 2.
Example 2:

Input:
x = 4
Output: 2
Explanation: Since, 4 is a perfect
square, so its square root is 2.
Your Task:
The task is to complete the function floorSqrt() which should return the square root of given number x.

Expected Time Complexity: O(log N).
Expected Auxiliary Space: O(1).

Constraints:
1 ≤ x ≤ 107


                */




long long int floorSqrt(long long int x)
{
    if(x==1)
    return 1;
    if(x==0)
    return 0;

     long long l=0,r=x-1,ans;
     while(l<=r)
     {
         long long mid=l+(r-l)/2;
        if(mid*mid==x)
        return mid;
        else if(mid*mid>x)
        r=mid-1;
        else
        {
            ans=mid;
            l=mid+1;
        }
     }

    return ans;
}
