#include<iostream>
#include<queue>
using namespace std;

// BFS function..
void BFS(int **edges,int n,int sv,bool *visited)
{
	queue<int>q;
	q.push(sv);
	visited[sv]=true;
	
	while(!q.empty())
	{
		int front = q.front();
		cout<<front<<" ";
		
		q.pop();
		
		for(int i=0;i<n;i++)
		{
			if(i==front)
				continue;
			if(edges[front][i]==1 && visited[i]==false){
				q.push(i);	
				visited[i]=true;
			}
		}	
	}	
}

int main()
{
	// Number of edges and vertices.
	int v,e;
	cin>>v>>e;
	
	// Adjacency matrix - initialize it with 0.
	int **edges = new int*[v];
	for(int i=0;i<v;i++)
	{
		edges[i] = new int[v];
		for(int j=0;j<v;j++)
			edges[i][j]=0;
	}
	
	// taking edges from user and add in adjacency matrix.
	for(int i=0;i<e;i++)
	{
		int f,s;
		cin>>f>>s;
		edges[f][s]=1;
		edges[s][f]=1;
	}
	
	// visited array.
	bool *visited = new bool[v];
	
	for(int i=0;i<v;i++)
		visited[i]=false;
	
	// This is for traversing all the nodes in graph [connected or disconnted]
	for(int i=0;i<v;i++)
		if(!visited)
			BFS(edges,v,i,visited);
	
	// Memory Deallocation
	for(int i=0;i<v;i++)
		delete[] edges[i];
	delete[] edges;
	delete[] visited;
	
	return 0;
}
