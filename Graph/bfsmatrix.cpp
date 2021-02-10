#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class Graph
{
    int v;
    int e;
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
    vector<vector<int>> edges( v , vector<int> (v, 0));
    int sv;

    for(int i=0;i<e;i++)
    {
       int f,s;
       cin>>f;
       cin>>s;
       edges[f][s]=1;
       edges[s][f]=1;
    }
    cout<<"Enter the source vertex:";
    cin>>sv;
    BFS(edges,sv);
}

void Graph::BFS(vector<vector<int>> &edges,int sv)
{
    bool visited[v]={false};
    queue<int> q;
    q.push(sv);
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
            else if(edges[front][i]==1 && visited[i]==false)
            {
                q.push(i);
                visited[i]=true;
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