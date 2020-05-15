/*
Given K sorted arrays arranged in the form of a matrix. The task is to merge them. You need to complete mergeKArrays() function which takes 2 arguments, an arr[k][k] 2D Matrix containing k sorted arrays and an integer k denoting the number of sorted arrays. The function should return a pointer to the merged sorted arrays.

Input:
The first line of input contains the number of test cases, then T test cases follow. Each test case will contain an integer K denoting the number of sorted arrays(each with size K). Then in the next line contains all the elements of the array separated by space.

Output:
The output will be the sorted merged array.

User Task:
The task is to complete the function mergeKArrays() which takes two arguments and returns a pointer to the modified array.

Constraints:
1 <= T <= 50
1 <= K <= 100

Example:
Input:
1
3
1 2 3 4 5 6 7 8 9

Output:
1 2 3 4 5 6 7 8 9

Explanation:
Testcase 1:
Above test case has 3 sorted arrays of size 3, 3, 3
arr[][] = [[1, 2, 3],

             [4, 5, 6],

             [7, 8, 9]]
The merged list will be [1, 2, 3, 4, 5, 6, 7, 8, 9].


*/


#define lli long long int
#define pr pair<int,int>
int *mergeKArrays(int a[][N], int k)
{

    unordered_map<int,int> m;
    int f=k*k;
    int *arr=(int*)malloc(sizeof(int)*k*k);

    priority_queue<pr,vector<pr>, greater<pr> > pq;
    for(lli i=0;i<k;i++)
    {
        pq.push({a[i][m[i]],i});
        m[i]++;

    }

    lli i=0;

    while(!pq.empty())
    {
        pr p=pq.top();
        pq.pop();
        arr[i]=p.first;
        i++;
        if(m[p.second]<k)
        {
             pq.push({a[p.second][m[p.second]],p.second});
                m[p.second]++;
        }


    }

    return arr;

}
