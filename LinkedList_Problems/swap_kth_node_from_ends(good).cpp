/*
        problem->  swap_kth_node_from_ends(good).cpp


        Swap Kth nodes from ends
Given a singly linked list of size N, and an integer K. You need to swap the Kth node from beginning and Kth node from the end in the linked list.
Note: You need to swap the nodes through the links and not changing the content of the nodes.

Input:
The first line of input contains the number of testcases T. The first line of every test-case contains N, number of nodes in a linked list, and K, the
nodes to be swapped, and the second line contains the elements of the linked list.

Output:
For each test case, if the nodes are swapped correctly, the output will be 1, else 0.

User Task:
The task is to complete the function swapkthnode(), which has arguments head, num(no of nodes), and K, and it should return a new head. The validation is
done internally by the driver code to ensure that the swapping is done by changing references/pointers only.  A correct code would always cause output as
1.

Expected Time Complexity: O(n)
Expected Auxillary space Complexity: O(1)

Constraints:
1 <= T <= 100
1 <= N <= 103
1 <= K <= 103

Example:
Input:
3
4 1
1 2 3 4
5 3
1 2 3 4 5
4 4
1 2 3 4
Output:
1
1
1

Explanation:
Testcase 1: Here K = 1, hence after swapping the 1st node from the beginning and end the new list will be 4 2 3 1.
Testcase 2: Here k = 3, hence after swapping the 3rd node from the beginning and end the new list will be 1 2 3 4 5.
Testcase 3: Here k = 4, hence after swapping the 4th node from the beginning and end the new list will be 4 2 3 1.


            */


Node *swapkthnode(Node* head, int num, int k)
{

    if(k>num)
    return head;
   Node *aprev=NULL,*a=head,*bprev=NULL,*b=head;
   for(int i=0;i<num-k;i++)
   {

       bprev=b;
       b=b->next;
   }

    for(int i=0;i<k-1;i++)
    {
        aprev=a;
        a=a->next;
    }

    if(a==b)
    return head;

    if(aprev==NULL)
    {
        b->next=a->next;
        a->next=NULL;
        bprev->next=a;

        return b;



    }

    if(bprev==NULL)
    {
        a->next=b->next;
        b->next=NULL;
        aprev->next=b;

        return a;
    }

    else
    {

        bprev->next=a;
        aprev->next=b;

        Node *t=a->next;
        a->next=b->next;
        b->next=t;


        return head;


    }



}
