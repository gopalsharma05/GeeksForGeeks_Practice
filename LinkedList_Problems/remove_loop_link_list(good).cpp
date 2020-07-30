/*


    problem-> remove_loop_link_list(good).cpp




    You are given a linked list of N nodes. The task is to remove the loop from the linked list, if present.

Input:
First line of input contains number of testcases T. T testcases follow. For each testcase, first line of input contains length N of the linked list and
next line contains N data of the linked list. The third line contains the position of the node(from head) to which the last node will get connected. If it
 is 0 then there is no loop.

Output:
For each testcase, in a new line, 1 will be printed if loop is removed and the list still has all N nodes connected to it, else 0 will be printed.

User Task:
Your task is to complete the function removeLoop(). The only argument of the function is head pointer of the linked list. Do not print anything. Simply
remove the loop in the list (if present) without disconnecting any nodes from the list.

Expected time complexity : O(n)

Expected auxiliary space : O(1)

Constraints:
1 <= T <= 102
1 <= N <= 104

Example:
Input:
2
3
1 3 4
2
4
1 8 3 4
0
Output:
1
1

Explanation:
Testcase 1: In the first test case N = 3.The linked list with nodes N = 3 is given. Here, x = 2 which means last node is connected with xth node of linked list. Therefore, there exists a loop.
Testcase 2: N = 4 and x = 0, which means lastNode->next = NULL, thus the Linked list does not contains any loop.


            */






void removeLoop(Node* head)
{

    Node *slow=head,*fast=head;
    bool cycle =false;
    while(fast!=NULL && fast->next!=NULL)
    {
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast)
        {
            cycle=true;
            break;
        }

    }

    if(cycle)
    {

       fast=fast->next;
       int n=1;
       while(fast!=slow)
       {
           n++;            // finding the size of the loop
           fast=fast->next;
       }

       fast=head;
       slow=head;

       for(int i=0;i<n-1;i++)
       fast=fast->next;          // making fast pointer n position ahead

       while(fast->next!=slow)
       {
           fast=fast->next;
           slow=slow->next;
       }
       fast->next=NULL;


    }



}
