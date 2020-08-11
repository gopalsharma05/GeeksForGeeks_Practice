/*

        problem-> peak_element(good).cpp




        Given an array A of N integers. The task is to find a peak element in A in  O( log N ) .


An array element is peak if it is not smaller than its neighbours. For corner elements, consider only one neighbour.

Example 1:

Input:
N = 3
A[] = {1,2,3}
Output: 2
Explanation: In the given array,
3 is the peak element as it is
greater than its neighbour.
Example 2:

Input:
N = 2
A[] = {3,4}
Output: 1
Explanation: 4 is the peak element
as it is greater than its neighbour
elements.
Your Task:
You don't have to read input or print anything. Just complete the provided function peakElement() and return a valid index with respect to 0 based indexing.
Note 1: Multiple peak element may be possible, in that case return any of the valid index .
Note 2: If you click on Compile and Test the output will be 1 if the index that you return is correct. Otherwise output will be 0.

Expected Time Complexity: O(log N).
Expected Auxiliary Space: O(1).

Constraints:
1 <= N <= 105
1 <= A[] <= 106


        */



#define lli long long int
int peakElement(int a[], int n)
{

    if(n==1||a[0]>a[1])
    return 0;

    if(a[n-1]>a[n-2])
    return n-1;

    int l=0,r=n-1;

    while(l<=r)
    {
        int mid=l+(r-l)/2;

        if(a[mid]>a[mid-1] && a[mid]>a[mid+1])
        return mid;
        else if(a[mid]<a[mid+1] && mid<n-1)
        l=mid+1;
        else
        r=mid-1;

    }



}
