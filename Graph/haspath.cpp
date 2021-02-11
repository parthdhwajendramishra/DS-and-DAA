/*Write a code to check that wheather a path between two vertex exist or not*/
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Graph
{
    int v,e;//Number of Verices and Edges
    public:
    Graph(int v,int e);
    bool BFS_FindPath(vector<vector<int>> &edges,int sv,int dv);  
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
    int sv,dv;

    for(int i=0;i<e;i++)
    {
        int f,s;
        cin>>f>>s;
        edges[f][s]=1;
        edges[s][f]=1;
    }

    cout<<"Enter the Source vertex:";
    cin>>sv;

    cout<<"Enter the Destination vertex:";
    cin>>dv;

    if(BFS_FindPath(edges,sv,dv))
       cout<<"Path Exist";
    else
        cout<<"Path Does Not Exist";
}

bool Graph::BFS_FindPath(vector<vector<int>> &edges,int sv,int dv)
{
    /*Creating an vector having all false values
    to check that which edge is visited*/
    vector<int> visited(v,false);
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

                //Check if visited vertex is equal to destination vertex
                if(i==dv)
                  return true;
            }
        }
    }
    
    return false;
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