#include <iostream>
#include <climits>
#include <vector>
using namespace std;

class Graph
{
	int v,e;
	public:
	Graph(int v,int e);
	void Bellman_Ford(vector<pair<int,pair <int,int>>> graph,int sv);
	
	
	void input();
};

void Graph::Bellman_Ford(vector<pair<int,pair <int,int>>> graph,int sv)
{
	vector<int> dist(v,INT_MAX);
	vector<int> parent(v);
	
	
	dist[sv]=0;
	parent[sv]=-1;
	
	for(int i=0;i<v-1;i++)
	{
		bool updated=false;
        for (auto j = 0; j<e; j++) 
        {
        	int u=graph[j].first;
        	int v=graph[j].second.first;
        	int wt=graph[j].second.second;
        	
        	
        	
        	if(dist[u]!=INT_MAX && dist[u]+wt<dist[v])
        	{
        		dist[v]=dist[u]+wt;
        		parent[v]=u;
        		updated=true;
        	}
        }
        if(updated==false)
        	break;
	}
	
	for(int i=0;i<v;i++)
		cout<<dist[i]<<" ";
}






void Graph::input()
{
	vector<pair<int,pair <int,int>>> graph;
	
	vector<pair<int,int>> edges;
	
	
	//Adding edges in the graph
	cout<<"Enter Source and Destination Vertex and Weight"<<endl;
	cout<<"Source------>Destination------>Weight"<<endl;
	for(int i=0;i<e;i++)
	{
		int src,dest,wt;
		cin>>src>>dest>>wt;
		graph.push_back(make_pair(src,(make_pair(dest,wt))));	
	}
	
	int sv;
	cout<<"Enter source vertex";
	cin>>sv;

	Bellman_Ford(graph,sv);
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
