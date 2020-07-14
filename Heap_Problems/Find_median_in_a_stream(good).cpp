/*

    problem->  Find_median_in_a_stream(good).cpp

    Given an input stream of N integers. The task is to insert these numbers into a new stream and find the median of the stream formed by each insertion of X to the new stream.

Input:
The first line of input contains an integer N denoting the number of elements in the stream. Then the next N lines contains integer x denoting the number to be inserted into the stream.
Output:
For each element added to the stream print the floor of the new median in a new line.

Constraints:
1 <= N <= 106
1 <= x <= 106

Example:
Input:
4
5
15
1
3
Output:
5
10
5
4

Explanation:
Testcase 1:
Flow in stream : 5, 15, 1, 3
5 goes to stream --> median 5 (5)
15 goes to stream --> median 10 (5, 15)
1 goes to stream --> median 5 (5, 15, 1)
3 goes to stream --> median 4 (5, 15, 1, 3)



        */


// APPROACH->


 #include<bits/stdc++.h>
 using namespace std;
 #define lli long long int
 int main()
 {


    lli n;
    cin>>n;
    lli a[n];
    for(lli i=0;i<n;i++)
    {
        cin>>a[i];
    }

    priority_queue<lli> maxm_heap;
    priority_queue<lli,vector<lli>,greater<lli> > minm_heap;

    maxm_heap.push(a[0]);
    cout<<a[0]<<"\n";
    for(lli i=1;i<n;i++)
    {

        if(a[i]<maxm_heap.top())
        {
            maxm_heap.push(a[i]);
        }
        else
        {
            minm_heap.push(a[i]);
        }

        if(abs(minm_heap.size()-maxm_heap.size())>1)
        {
            if(minm_heap.size()>maxm_heap.size())
            {
                maxm_heap.push(minm_heap.top());
                minm_heap.pop();
            }
            else
            {
                minm_heap.push(maxm_heap.top());
                maxm_heap.pop();
            }
        }

            if(minm_heap.size()==maxm_heap.size())
            {
                cout<<(minm_heap.top()+maxm_heap.top())/2<<"\n";

            }
            else if(minm_heap.size()>maxm_heap.size())
            {
                cout<<minm_heap.top()<<"\n";
            }
            else
            {
                cout<<maxm_heap.top()<<"\n";
            }






    }



 }
