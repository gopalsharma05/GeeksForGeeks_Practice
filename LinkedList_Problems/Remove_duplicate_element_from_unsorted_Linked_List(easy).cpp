/*

    problem-> Remove_duplicate_element_from_unsorted_Linked_List(easy).cpp

    Given an unsorted linked list of N nodes. The task is to remove duplicate elements from this unsorted Linked List.
    When a value appears in multiple nodes, the node which appeared first should be  kept, all others duplicates are to be removed.

Input:
The first line of input contains the number of test cases T. For each test case, the first line of input contains a number of nodes in the linked list,
and the next line contains node data for N nodes.

Output:
For each test case, print the linked list with no repeating elements.

User Task:
You have to complete the method removeDuplicates() which takes 1 argument: the head of the linked list. You should not read any input from the
stdin/console. Your function should return a pointer to a linked list with no duplicate element.

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(N)

Constraints:
1 <= T <= 100
1 <= size of linked lists <= 104
1 <= numbers in list <= 104

Example:
Input:
2
4
5 2 2 4
5
2 2 2 2 2
Output:
5 2 4
2

Explanation:
Testcase 1: Given linked list elements are 5->2->2->4, in which 2 is repeated only. So, we will delete the extra repeated elements 2 from the linked list and the resultant linked list will contain 5->2->4.
Testcase 2: Given linked list elements are 2->2->2->2->2, in which 2 is repeated. So, we will delete the extra repeated elements 2 from the linked list and the resultant linked list will contain only 2.


            */



Node * removeDuplicates(Node *head)
{

    unordered_map<int,int> m;

        Node *r,*current=head,*prev;
        while(current!=NULL)
        {
            m[current->data]++;
            if(m[current->data]>1)
            {
                r=current;
                current=current->next;
                prev->next=current;
                delete(r);

            }
            else
            {

            prev=current;
            current=current->next;
            }
        }


        return head;


}
