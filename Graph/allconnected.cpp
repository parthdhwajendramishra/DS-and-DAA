#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Graph
{
    int v,e;
    public:
    Graph(int v,int e);
    void BFS(vector<vector<int>> &edges,int sv,vector<int> &visited);
    bool Connected(vector<int> &visited);
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

    /*Creating an vector having all false values
    to check that which edge is visited*/
    vector<int> visited(v,false);

    for(int i=0;i<e;i++)
    {
        int f,s;
        cin>>f>>s;
        edges[f][s]=1;
        edges[s][f]=1;
    }

    BFS(edges,0,visited);

    if(Connected(visited))
       cout<<"Connected";
    else
        cout<<"Not Connected";

}

void Graph::BFS(vector<vector<int>> &edges,int sv,vector<int> &visited)
{
    queue<int> q;
    q.push(sv);

    visited[sv]=true;
    while (!q.empty())
    {
        int front=q.front();
        q.pop();

        for(int i=0;i<v;i++)
        {
            if(i==front)
                continue;
            else if(edges[front][i]==1 && visited[i]==false)
            {
                q.push(i);
                visited[i]=true;
            }
        }

        
    }
    
}


bool Graph::Connected(vector<int> &visited)
{

    for(int i=0;i<v;i++)
        if(visited[i]==false)
            return false;

    return true;
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