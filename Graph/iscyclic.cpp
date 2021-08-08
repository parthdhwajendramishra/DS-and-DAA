#include <iostream>
#include <vector>
using namespace std;

class Graph
{
	int v,e;
	public:
	Graph(int v,int e);
	bool isCyclic(vector<int> graph[]);
	bool cyclic_Util(int sv,vector<int> graph[],vector<bool> &visited,vector<bool> &recStack);
	
	void input();
};


bool Graph::cyclic_Util(int sv,vector<int> graph[],vector<bool> &visited,vector<bool> &recStack)
	{
		if(visited[sv]==false)
		{
			visited[sv]=true;
			recStack[sv]=true;
			
			for(auto i=graph[sv].begin();i!=graph[sv].end();i++)
				{	
					if(!visited[*i] && cyclic_Util(*i,graph,visited,recStack))
						return true;
					else if(recStack[*i])
						return true;
			
				}
		}
	recStack[sv]=false;
	return false;
}



bool Graph::isCyclic(vector<int> graph[])
{
	vector<bool> visited(v,false);
	vector<bool> recStack(v,false);

	vector<int>::iterator i;

	for(int i=0;i<v;i++)
		if(cyclic_Util(i,graph,visited,recStack))
			return true;
	
	return false;
	
}


void Graph::input()
{
	vector<int> graph[v];
	
	
	//Adding edges in the graph
	cout<<"Enter Source and Destination Vertex"<<endl;
	cout<<"Source------>Destination"<<endl;
	for(int i=0;i<e;i++)
	{
		int source,destination;
		cin>>source>>destination;
		graph[source].push_back(destination);
		
	}


	cout<<isCyclic(graph);
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
