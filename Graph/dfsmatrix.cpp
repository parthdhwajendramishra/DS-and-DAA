#include <iostream>
#include <vector>
using namespace std;

class Graph
{
    int v,e;
    public:
    Graph(int v,int e);
    void DFS(vector<vector<int>> &edges,int sv,vector<int> &visited);
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
    vector<vector<int>> edges(v,vector<int>(v,0));
    int sv;//source vertex

    for(int i=0;i<e;i++)
    {
        int f,s;
        cin>>f>>s;
        edges[f][s]=1;
        edges[s][f]=1;
    }

    /*Creating an vector having all false values
    to check that which edge is visited*/
    vector<int> visited(v,0);
    cout<<"Enter the source vertex:";
    cin>>sv;

    DFS(edges,sv,visited);
}

void Graph::DFS(vector<vector<int>> &edges,int sv,vector<int> &visited)
{
    //Marking visited vertex true
    visited[sv]=true;
    cout<<sv<<" ";

    for(int i=0;i<v;i++)
    {
        if(i==sv)
            continue;
         //If vertex is coonected to another vertex and is not visited
        else if(edges[sv][i]==1 && visited[i]==false)
            DFS(edges,i,visited);
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