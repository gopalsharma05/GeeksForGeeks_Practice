/*

    problem->LRU_Cache(good).cpp


    The task is to design and implement methods of an LRU cache. The class has two methods get() and set() which are defined as follows.
get(x)   : Returns the value of the key x if the key exists in the cache otherwise returns -1.
set(x,y) : inserts the value if the key x is not already present. If the cache reaches its capacity it should invalidate the least recently used item
 before inserting the new item.
In the constructor of the class the size of the cache should be intitialized.

Example 1:

Input:
N = 2
Q = 2
Queries = SET 1 2 GET 1
Output: 2
Explanation: Cache Size = 2
SET 1 2 GET 1
SET 1 2 : 1 -> 2
GET 1 : Print the value corresponding
to Key 1, ie 2.
Example 2:

Input:
N = 2
Q = 7
Queries = SET 1 2 SET 2 3 SET 1 5
SET 4 5 SET 6 7 GET 4 GET 1
Output: 5 -1
Explanation: Cache Size = 2
SET 1 2 SET 2 3 SET 1 5 SET 4 5
SET 6 7 GET 4 GET 1
SET 1 2 : 1 -> 2
SET 2 3 : 1 -> 2, 2 -> 3 (the most
recently used one is kept at the
rightmost position)
SET 1 5 : 2 -> 3, 1 -> 5
SET 4 5 : 1 -> 5, 4 -> 5 (Cache size
is 2, hence we delete the least
recently used key-value pair)
SET 6 7 : 4 -> 5, 6 -> 7
GET 4 : Prints 5
GET 1 : No key-value pair having
key = 1. Hence prints -1.
Your Task:
You only need to complete the provided functions get() and set().

Expected Time Complexity: O(1) for both get() and set().
Expected Auxiliary Space: O(1) for both get() and set(). (though, you may use extra space for cache storage and implementation purposes).

Constraints:
1 <= N <= 1000
1 <= Q <= 100000
1 <= x, y <= 1000





                */




class LRUCache
{
private:
int size=0;
unordered_map<int,list<pair<int,int> > :: iterator> m;
list<pair<int,int> > dll;

public:

    LRUCache(int cap)
    {
        size=cap;
    }

     int get(int key)
    {
        if(m.find(key)!=m.end())
        {
            auto it=m[key];
            int val=it->second;
            dll.erase(it);
            dll.push_front({key,val});
            m[key]=dll.begin();
            return val;


        }
        else
        return -1;
    }

     void set(int key, int value)
    {
        if(m.find(key)==m.end())
        {
            if(dll.size()==size)
            {
                auto p=dll.back();
                dll.pop_back();
                m.erase(p.first);

                dll.push_front({key,value});
                 m[key]=dll.begin();




            }
            else
            {
                 dll.push_front({key,value});
                 m[key]=dll.begin();

            }
        }
        else
        {

            auto it=m[key];
            dll.erase(it);
            m.erase(key);
            dll.push_front({key,value});
            m[key]=dll.begin();


        }

    }
};
