#include <iostream>
#include <vector>
using namespace std;

class Graph
{
	int v,e;
	public:
	Graph(int v,int e);
	void DFS(vector<int> graph[],int sv,vector<bool> &visited);
	void input();
};


void Graph::DFS(vector<int> graph[],int sv,vector<bool> &visited)
{
	visited[sv]=true;
	cout<<sv<<" ";

	vector<int>::iterator i;

	//Visiting all neighbours of Source Vertex
	for(i=graph[sv].begin();i!=graph[sv].end();i++)
	{
		//If its' neighbour is not visited
		if(!visited[*i])
			DFS(graph,*i,visited);
	}
}


void Graph::input()
{
	vector<int> graph[v];
	vector<bool> visited(v,false);
	
	//Adding edges in the graph
	cout<<"Enter Source and Destination Vertex"<<endl;
	cout<<"Source------>Destination"<<endl;
	for(int i=0;i<e;i++)
	{
		int source,destination;
		cin>>source>>destination;
		graph[source].push_back(destination);
	}

	int sv;
	cout<<"Enter Source Vertex:";
	cin>>sv;

	cout<<"DFS is ";
	DFS(graph,sv,visited);
}


Graph::Graph(int v,int e)
{
	this->v=v;
	this->e=e;
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
