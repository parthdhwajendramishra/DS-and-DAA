#include <iostream>
#include <vector>
using namespace std;

class Graph
{
	int v,e;
	public:
	Graph(int v,int e);
	bool isCyclic(vector<int> graph[]);
	bool cyclic_Util(int sv,vector<int> graph[],vector<bool> &visited,int parent);
	
	void input();
};


bool Graph::cyclic_Util(int sv,vector<int> graph[],vector<bool> &visited,int parent)
	{
		visited[sv]=true;	
		for(auto i=graph[sv].begin();i!=graph[sv].end();i++)
			{	
				if(!visited[*i])
				{
					if(cyclic_Util(*i,graph,visited,sv))
						return true;
				}
				
				else if(*i!=parent)
					return true;
			
			}
		return false;
}



bool Graph::isCyclic(vector<int> graph[])
{
	vector<bool> visited(v,false);
	for (int u = 0; u < v; u++)
    {  
        if (!visited[u])
          if (cyclic_Util(u, graph,visited, -1))
             return true;
    }
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
		graph[destination].push_back(source);
		
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
