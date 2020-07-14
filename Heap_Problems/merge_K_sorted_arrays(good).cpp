/*

    problem-> merge_K_sorted_arrays(good).cpp
    Given K sorted arrays arranged in the form of a matrix of size K*K. The task is to merge them into one sorted array.

Input:
The first line of input contains the number of test cases, then T test cases follow. Each test case will contain an integer K denoting the number of sorted arrays(each with size K). Then in the next line contains all the elements of the array separated by space.

Output:
The output will be the sorted merged array.

User Task:
You need to complete mergeKArrays() function which takes 2 arguments, an arr[k][k] 2D Matrix containing k sorted arrays and an integer k denoting the number of sorted arrays. The function should return a pointer to the merged sorted arrays.

Expected Time Complexity: O(nk Logk)
Expected Auxiliary Space: O(k)

Note: This space is required for returning the resulted sorted array, other work should be done in O(K) Auxiliary Space.

Constraints:
1 <= T <= 50
1 <= K <= 100

Example:
Input:
2
3
1 2 3 4 5 6 7 8 9
4
1 2 3 4 2 2 3 4 5 5 6 6 7 8 9 9

Output:
1 2 3 4 5 6 7 8 9
1 2 2 2 3 3 4 4 5 5 6 6 7 8 9 9

Explanation:
Testcase 1:
Above test case has 3 sorted arrays of size 3, 3, 3
arr[][] = [[1, 2, 3],

             [4, 5, 6],

             [7, 8, 9]]
The merged list will be [1, 2, 3, 4, 5, 6, 7, 8, 9].
Testcase 2:
Above test case has 4 sorted arrays of size 4, 4, 4, 4
arr[][] = [[1, 2, 2, 2],

             [3, 3, 4, 4],

             [5, 5, 6, 6]

             [7, 8, 9, 9 ]]
The merged list will be [1, 2, 2, 2, 3, 3, 4, 4, 5, 5, 6, 6, 7, 8, 9, 9 ].

        */


#define lli long long int
#define pr pair<lli,lli>
#define pb push_back

int *mergeKArrays(int a[][N], int k)
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);

    int *ans=(int *)malloc(sizeof(int)*(k*k));
    int j=0;
    priority_queue<pr,vector<pr>,greater<pr> > pq;
    unordered_map<lli,lli> m;

    for(lli i=0;i<k;i++)
    {
        pq.push({a[i][0],i});
        m[i]++;;

    }

    while(!pq.empty())
    {
        pr p=pq.top();
        pq.pop();

        ans[j++]=p.first;
        if(m[p.second]<k)
        {
            pq.push({a[p.second][m[p.second]],p.second});
            m[p.second]++;
        }

    }

   return ans;




}
