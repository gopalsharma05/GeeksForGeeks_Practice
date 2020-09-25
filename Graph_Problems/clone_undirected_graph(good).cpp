/*
    problem-> clone_undirected_graph(good).cpp



    Clone an undirected graph. Each node in the graph contains a label and a list of its neighbors.





                        */



UndirectedGraphNode *Solution::cloneGraph(UndirectedGraphNode *node) {

    unordered_map<UndirectedGraphNode*,UndirectedGraphNode*> m;
    queue<UndirectedGraphNode*> q;

     UndirectedGraphNode *temp=new UndirectedGraphNode(node->label);
     q.push(node);


    m[node]=temp;

    while(!q.empty())
    {
        UndirectedGraphNode *p=q.front();
        q.pop();

        UndirectedGraphNode *r=m[p];
        vector<UndirectedGraphNode *> v=p->neighbors;

        for(auto x:v)
        {
            if(m.find(x)==m.end())
            {
                 UndirectedGraphNode *g= new UndirectedGraphNode(x->label);
               r->neighbors.push_back(g);
               m[x]=g;
               q.push(x);
            }
            else
            {
                r->neighbors.push_back(m[x]);
            }
        }


    }

    return temp;




}
