//Write a code to check that whether a graph is Bipartite or not

#include <iostream>
#include <vector>
using namespace std;

class Graph
{
    int v,e;
    public:
    Graph(int v,int e);
    bool DFS_Bipartite(vector<vector<int>> &edges,int sv,vector<int> &color);
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

    /*Takinga a vector of coloures and asssigning it -1
     which means it is not yet coloured */
    vector<int>color(v,-1);

    /*We will use 2 colours to color the graph 
      let us assume 1-Red and 0-Blue because
      chromatic number of a Bipartite Graph must be 2*/
     

    color[0]=1;/*We are taking source vertex as 0
                so colour it with Red(i.e. 1)*/

    for(int i=0;i<e;i++)
    {
        int f,s;
        cin>>f>>s;
        edges[f][s]=1;
    }

    if(DFS_Bipartite(edges,0,color))
        cout<<"Bipartite\n";
    else
        cout<<"Not Bipartite\n";

}

bool Graph::DFS_Bipartite(vector<vector<int>> &edges,int sv,vector<int> &color)
{
    for(int i=0;i<v;i++)
    {
        
        //Checking for self-loop
        if(edges[sv][sv]==1)
            return false;

        //If Vertex is not coloured
        else if(edges[sv][i]==1 && color[i]==-1)
        {
            
                 color[i] = 1 - color[sv]; 
                 DFS_Bipartite(edges,i,color);
            }
        //To check if neighbour of any vertex is of same color
        else if (edges[sv][i]==1 && color[i] == color[sv]) 
            return false; 
        }
            
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