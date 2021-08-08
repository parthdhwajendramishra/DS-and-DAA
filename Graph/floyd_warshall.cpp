#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Graph
{
    int v,e;
    public:
    Graph(int v,int e);
    void Floyd_Warshall(vector<vector<int>> &graph);
    void input();
    void print(vector<vector<int>> &graph);
};

Graph::Graph(int v,int e)
{
    this->v=v;
    this->e=e;
}

void Graph::print(vector<vector<int>> &graph)
{
	for(int i=0;i<v;i++)
    	{
    		for(int j=0;j<v;j++)
    			cout<<graph[i][j]<<" ";
    		cout<<endl;
    	}
}

void Graph::input()
{
    //Taking a matrix of size v*v 
    vector<vector<int>> graph(v,vector<int>(v));

 
    for(int i=0;i<v;i++)
    	for(int j=0;j<v;j++)
    	{
    		if(i==j)
    			graph[i][j]=0;
    		else
    			graph[i][j]=INT_MAX;
    	}
    
    
    for(int i=0;i<e;i++)
    {
        int f,s;
        cin>>f>>s; 
        cin>>graph[f][s];
    }
    print(graph);
    Floyd_Warshall(graph);
    print(graph);
}

void Graph::Floyd_Warshall(vector<vector<int>> &graph)
{
    for(int k=0;k<v;k++)
    {
    	for(int i=0;i<v;i++)
    	{
    		for(int j=0;j<v;j++)
    		{
    			if(graph[i][k]!=INT_MAX && graph[k][j]!=INT_MAX && graph[i][j]>(graph[i][k]+graph[k][j]))
    				graph[i][j]=graph[i][k]+graph[k][j];
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
