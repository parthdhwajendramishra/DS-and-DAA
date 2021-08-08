#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class Graph
{
    int v,e;//Number of Vertices and Edges
    public:
    Graph(int v,int e);
    void BFS(vector<int> edges[],int sv);
    void input();
};

Graph::Graph(int v,int e)
{
    this->v=v;
    this->e=e;
}


void Graph::BFS(vector<int> edges[],int sv)
{
    /*Creating an array having all false values
    to check that which edge is visited*/
    bool visited[v]={false};

    //A queue to push visited vertices
    queue<int> q;
    q.push(sv);

    //Marking visited vertex true
    visited[sv]=true;

	vector<int>::iterator i;
   	while(!q.empty())
    {
        int front=q.front();
        cout<<front<<" ";

        q.pop();	
 
 	 for (i = edges[front].begin(); i != edges[front].end(); ++i)
            if (!visited[*i])
            	{
                	visited[*i] = true;
                	q.push(*i);
            	}
    }
}


void Graph::input()
{
   	vector<int> edges[v];
    int sv;//source vertex

    for(int i=0;i<e;i++)
    {
       int s,d;
       cin>>s>>d;
       edges[s].push_back(d);
    }
    cout<<"Enter the source vertex:";
    cin>>sv;
     
     BFS(edges,sv);
}



int main()
{
    int v,e;
    cout<<"Enter number of Vertices:";
    cin>>v;
    cout<<"Enter number of Edges:";
    cin>>e;

    Graph g(v,e);
    g.input();

    return 0;
}