/*

    problem-> Merge_K_sorted_linked_lists(easy).cpp


    Given K sorted linked lists of different sizes. The task is to merge them in such a way that after merging they will be a single sorted linked list.

Input:
First line of input contains number of testcases T. For each testcase, first line of input contains number of linked lists N and next line contains data of nodes of all K linked lists, with first element as M, the length of linked list and next M elements for the same linked list.

Output:
For each testcase, in a new line, print the merged linked list.

Your Task:
The task is to complete the function mergeKList() which merges the K given lists into a sorted one. The printing is done automatically by the driver code.

Expected Time Complexity: O(nk Logk)
Expected Auxiliary Space: O(k)

Constraints
1 <= T <= 50
1 <= N <= 103

Example:
Input:
2
4
3 1 2 3 2 4 5 2 5 6 2 7 8
3
2 1 3 3 4 5 6 1 8
Output:
1 2 3 4 5 5 6 7 8
1 3 4 5 6 8

Explanation :
Testcase 1: The test case has 4 sorted linked list of size 3, 2, 2, 2
1st    list     1 -> 2-> 3
2nd   list      4->5
3rd    list      5->6
4th    list      7->8
The merged list will be 1->2->3->4->5->5->6->7->8.
Testcase 2: The test case has 3 sorted linked list of size 2, 3, 1.
1st list 1 -> 3
2nd list 4 -> 5 -> 6
3rd list 8
The merged list will be 1->3->4->5->6->8.


        */


  Node * merge(Node *a, Node* b )
  {

      Node *ans,*t=NULL;

    while(a!=NULL  && b!=NULL)
    {
        if(a->data<b->data)
        {
            if(t==NULL)
            {
                t=a;
                a=a->next;
                ans=t;
            }
            else
            {
                t->next=a;
                a=a->next;
                t=t->next;
            }
        }
        else
        {
            if(t==NULL)
            {
                t=b;
                b=b->next;
                ans=t;
            }
            else
            {
                t->next=b;
                b=b->next;
                t=t->next;
            }
        }
    }

    while(a!=NULL)
    {
         t->next=a;
                a=a->next;
                t=t->next;
    }

     while(b!=NULL)
    {
         t->next=b;
                b=b->next;
                t=t->next;
    }

    return ans;


  }
Node * mergeKLists(Node *a[], int n)
{
    Node *r=a[0];
       for(int i=1;i<n;i++)
       {
           r=merge(r,a[i]);
       }

       return r;
}
