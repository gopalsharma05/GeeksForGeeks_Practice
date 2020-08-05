/*

    problem-> minimum_jupms_to_reach_end(good).cpp


    Given an array of integers where each element represents the max number of steps that can be made forward from that element. The task is to find the
    minimum number of jumps to reach the end of the array (starting from the first element). If an element is 0, then cannot move through that element.

Input:
The first line contains an integer T, depicting total number of test cases.  Then following T lines contains a number n denoting the size of the array.
 Next line contains the sequence of integers a1, a2, ..., an.

Output:
For each testcase, in a new line, print the minimum number of jumps. If answer is not possible print "-1"(without quotes).

Your Task:
Complete the function minimumJump() which takes an array and N (number of elements) as input parameters and returns the answer.

Expected Time Complexity : O(N)
Expected Auxiliary Space: O(N)

Constraints:
1 ≤ T ≤ 100
1 ≤ N ≤ 107
0 <= ai <= 107

Example:
Input:
2
11
1 3 5 8 9 2 6 7 6 8 9
6
1 4 3 2 6 7
Output:
3
2

Explanation:
Testcase 1: First jump from 1st element, and we jump to 2nd element with value 3. Now, from here we jump to 5h element with value 9. and from here we will
jump to last.



                */







int minimumJumps(int a[], int n){

    if(n<=1)
    return 1;

    if(a[0]==0)
    return  -1;

    int maxmreachableindex=a[0],steps_to_reach_max_index=a[0],jumps=1;

    for(int i=1;i<n;i++)
    {
        if(i==n-1)
        return  jumps;


        steps_to_reach_max_index--;
        maxmreachableindex=max(i+a[i],maxmreachableindex);
        if(steps_to_reach_max_index==0)
        {
            if(i>=maxmreachableindex)
            return -1;

            jumps++;
            steps_to_reach_max_index=maxmreachableindex-i;


        }


    }

    return -1;


}
