#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Graph
{
	int v,e;
	public:
	Graph(int v,int e);
	void DFS1(int sv,vector<int> graph[],vector<bool> &visited,stack<int> &callstack);
	void reverse(vector<int> graph[],vector<int> rev_graph[]);
	void DFS2(int sv,vector<int> rev_graph[],vector<bool> &visited);
	void input();
};

void Graph::DFS1(int sv,vector<int> graph[],vector<bool> &visited,stack<int> &callstack)
{
	visited[sv]=true;
	vector<int>::iterator i;

	//Visiting all neighbours of Source Vertex
	for(i=graph[sv].begin();i!=graph[sv].end();i++)
	{
		//If its' neighbour is not visited
		if(!visited[*i])
			DFS1(*i,graph,visited,callstack);
	}
	callstack.push(sv);
}

void Graph::reverse(vector<int> graph[],vector<int> rev_graph[])
{
	for(int i=0;i<v;i++)	
		for(auto j=graph[i].begin();j!=graph[i].end();j++)
				rev_graph[*j].push_back(i);
}

void Graph::DFS2(int sv,vector<int> rev_graph[],vector<bool> &visited)
{
	visited[sv]=true;
	vector<int>::iterator i;
	cout<<sv<<" ";
	
	//Visiting all neighbours of Source Vertex
	for(i=rev_graph[sv].begin();i!=rev_graph[sv].end();i++)
	{
		//If its' neighbour is not visited
		if(!visited[*i])
			DFS2(*i,rev_graph,visited);
	}
}


void Graph::input()
{
	vector<int> graph[v];
	vector<int> rev_graph[v];
	
	vector<bool> visited(v,false);
	stack<int> callstack;
	
	//Adding edges in the graph
	cout<<"Enter Source and Destination Vertex"<<endl;
	cout<<"Source------>Destination"<<endl;
	for(int i=0;i<e;i++)
	{
		int source,destination;
		cin>>source>>destination;
		graph[source].push_back(destination);
	}


	
	
	//Calling First DFS
	for(int i=0;i<v;++i)
		if(!visited[i])
			DFS1(i,graph,visited,callstack);
	
	//Reversing the Graph			
	reverse(graph,rev_graph);
	
	for(int i=0;i<v;++i)
		visited[i] = false;
	
	//Calling Second DFS
	while(!callstack.empty())
	{
		int curr=callstack.top();
		callstack.pop();
		
		if(visited[curr]==false)
			{
				DFS2(curr,rev_graph,visited);
				cout<<endl;
			}
	}
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
