 /*

Counting Sort
Given a string S consisting of lowercase latin letters, arrange all its letters in lexographical order using Counting Sort.

Input:
The first line of the input contains T denoting number of testcases.Then T test cases follow. Each testcase contains positive integer N denoting the length of string.The last line of input contains the string S.

Output:
For each testcase, in a new line, output the sorted string.

Your Task:
This is a function problem. You only need to complete the function countSort() that takes char array as parameter. The printing is done by driver code.

Constraints:
1 <= T <= 105
1 <= N <= 105

Example:
Input:
2
5
edsab
13
geeksforgeeks
Output:
abdes
eeeefggkkorss

Explanation:
Testcase 1: In lexicographical order , string will be abdes.
Testcase 2: In lexicographical order , string will be eeeefggkkorss.
 */

void countSort(char s[])
{

    unordered_map<char,int> m;
    int size=0;
    for(int i=0;s[i]!='\0';i++)
    {
        m[s[i]]++;          // counting the frequency of the characters in character array
        //cout<<s[i];
        size++;

    }

    char ch='b';
    while(ch<=122)
    {
        m[ch]+=m[ch-1];        // summing the frequecy of elements
        ch++;
    }

     char a[size+1];
     for(int i=0;i<size;i++)   // again storing the element in sorted in new array
     {
         a[m[s[i]]]=s[i];
         m[s[i]]--;
     }

     for(int i=1;i<=size;i++)
     {
         s[i-1]=a[i];         // putting sorted array element back in given array
     }


}
