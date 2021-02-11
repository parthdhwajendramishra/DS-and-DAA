#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class Graph
{
    int v,e;//Number of Verices and Edges
    public:
    Graph(int v,int e);
    void BFS(vector<vector<int>> &edges,int sv);
    void input();
};

Graph::Graph(int v,int e)
{
    this->v=v;
    this->e=e;
}

void Graph::input()
{
    //Taking a matrix of size v*v having all values zero
    vector<vector<int>> edges( v , vector<int> (v, 0));
    int sv;//source vertex

    for(int i=0;i<e;i++)
    {
       int f,s;
       cin>>f>>s;
       edges[f][s]=1;
       edges[s][f]=1;
    }
    cout<<"Enter the source vertex:";
    cin>>sv;
    BFS(edges,sv);
}

void Graph::BFS(vector<vector<int>> &edges,int sv)
{
    /*Creating an array having all false values
    to check that which edge is visited*/
    bool visited[v]={false};

    //A queue to push visited vertices
    queue<int> q;
    q.push(sv);

    //Marking visited vertex true
    visited[sv]=true;

    while(!q.empty())
    {
        int front=q.front();
        cout<<front<<" ";

        q.pop();

        for(int i=0;i<v;i++)
        {
            if(i==front)
              continue;
            
            //If vertex is coonected to another vertex and is not visited
            else if(edges[front][i]==1 && visited[i]==false)
            {
                q.push(i);//Push the vertex in queue 
                visited[i]=true;//Mark it true as visited
            }
        }
    }
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