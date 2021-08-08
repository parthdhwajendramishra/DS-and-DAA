#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Graph
{
    int v,e;
    public:
    Graph(int v,int e);
    void Prims(vector<vector<int>> &graph,int src);
    int min_distance(vector<int> &dist,vector<bool> &processed);
    void input();
};

Graph::Graph(int v,int e)
{
    this->v=v;
    this->e=e;
}

int Graph::min_distance(vector<int> &dist,vector<bool> &processed)
{
	int min=INT_MAX,min_index;
	
	for(int i=0;i<v;i++)
	{	
		//Minimum vertex which is not processed
		if(processed[i]==false && dist[i]<=min)
		{
			min=dist[i];
			min_index=i;
		}
			
	}
	return min_index;
}


void Graph::Prims(vector<vector<int>> &graph,int src)
{
	vector<int> dist(v,INT_MAX);
	vector<int> parent(v);
	vector<bool> processed(v,false);

    
    dist[src]=0;
    parent[src]=-1;
    for(int i=0;i<v-1;i++)
    {
        int u=min_distance(dist,processed);
        processed[u]=true;
        
        for(int j=0;j<v;j++)
        {
        	if(!processed[j] && graph[u][j] && dist[u]!=INT_MAX &&
        	   graph[u][j]<dist[j])
        	   {
        	   	dist[j]=graph[u][j];
        	   	parent[j]=u;
        }   	}
    }
    
    for(int i=0;i<v;i++)
    	cout<<dist[i]<<" ";
    
    cout<<endl;
    for(int i=0;i<v;i++)
    	cout<<parent[i]<<" ";

}

void Graph::input()
{
    //Taking a matrix of size v*v having all values zero
    vector<vector<int>> graph(v,vector<int>(v,0));

    
    int src;//source vertex

    for(int i=0;i<e;i++)
    {
        int f,s;
        cin>>f>>s;
        cin>>graph[f][s];
        graph[s][f]=graph[f][s];
    }

    
    cout<<"Enter the source vertex:";
    cin>>src;

    Prims(graph,src);
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
