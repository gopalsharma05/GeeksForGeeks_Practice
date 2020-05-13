/*

    Given an array of N distinct elements A[ ]. The task is to find the minimum number of swaps required to sort the array. Your are required to complete the function which returns an integer denoting the minimum number of swaps, required to sort the array.

Input:
The first line of input contains an integer T denoting the no of test cases . Then T test cases follow . Each test case contains an integer N denoting the no of element of the array A[ ]. In the next line are N space separated values of the array A[ ] .

Output:
For each test case in a new line output will be an integer denoting  minimum umber of swaps that are  required to sort the array.

Constraints:
1 <= T <= 100
1 <= N <= 103
1 <= A[] <= 104


User Task:
Your task is to complete minSwaps() which should return number of swaps required to make the array elements sorted.

Example(To be used only for expected output):
Input:
2
4
4 3 2 1
5
1 5 4 3 2

Output:
2
2

Explanation:
Testcase 1: We need two swaps, swap 1 with 4 and 3 with 2 to make it sorted.


    */


    int minSwaps(int a[], int n){

    unordered_map<int ,int> m;
    int b[n];
    for(int i=0;i<n;i++)
    {
        m[a[i]]=i;
        b[i]=a[i];
    }

    sort(b,b+n);     // sorting the array b
    int cnt=0;
    for(int i=0;i<n;i++)
    {
        if(a[i]!=b[i])      // checking that either the element is already at the right position
        {
            int ind=m[b[i]];    // if not...checking where is the element position which is should be at i, and swapping the elements
            swap(a[i],a[ind]);
            m[a[i]]=i;
            m[a[ind]]=ind;
            cnt++;
        }
    }

    return cnt;

}




// another approach ....graph based approach ....find the cycle then add the size of cycle -1 to your answer

/*




int minSwaps(int a[], int n){

    unordered_map<int ,int> m;
    int b[n];
    for(int i=0;i<n;i++)
    {
        b[i]=a[i];
    }

    sort(b,b+n);
    int cnt=0;
    for(int i=0;i<n;i++)
    {
        m[b[i]]=i;
    }

    int vis[n]={0},ans=0;

    for(int i=0;i<n;i++)
    {
        if(a[i]!=b[i]  ||  vis[i]==0)
        {
            vis[i]=1;
            int j=m[a[i]];
            int cnt=0;
          while(vis[j]!=1)       // it is for checking cycle..like in our 1st test case ...0->3->0 and 1->2->1...so in both count
                                    // increases 1 time ....we add the count to aour ans
          {

              vis[j]=1;
              j=m[a[j]];
              cnt++;
          }
          ans+=cnt;


        }
    }

    return ans;

}

    */
