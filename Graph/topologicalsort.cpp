#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Graph
{
	int v,e;
	public:
	Graph(int v,int e);
	void input();
	void TopologicalSort(vector<int> graph[],vector<int> &indegree);

};

Graph::Graph(int v,int e)
{
	this->v=v;
	this->e=e;
}




void Graph::TopologicalSort(vector<int> graph[],vector<int> &indegree)
{
	queue<int> q;
	for(int i=0;i<v;i++)
		if(indegree[i]==0)
			q.push(i);
			
	while(!q.empty())
	{
		int front=q.front();
		q.pop();
		cout<<front<<" ";
		
		for(auto i=graph[front].begin();i!=graph[front].end();i++)
		{
			indegree[*i]--;
			if(indegree[*i]==0)
				q.push(*i);
		}
	}
}

void Graph::input()
{
   	vector<int> graph[v];
   	vector<int> indegree(v,0);
    for(int i=0;i<e;i++)
    {
       int s,d;
       cin>>s>>d;
       graph[s].push_back(d);
       indegree[d]++;
       
    }    
     TopologicalSort(graph,indegree);
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
