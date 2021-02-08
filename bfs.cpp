#include <iostream>
#include <list>
using namespace std;


class Graph
{
	int v;//Number of vertices
 	list<int> *adj;//A list of double dimension
 	
	public:
	Graph(int v);
	void addEdge(int v,int w);
	void BFS(int s);
};

//Initializing all values 
Graph::Graph(int v)
{
	this->v=v;
	adj= new list<int>[v];
}

//Function to add edge
void Graph::addEdge(int v,int w )
{
	adj[v].push_back(w);
}

//Traversing graph by BFS
void Graph::BFS(int s)
{
 //Creating a boolean Array of all visited vertices
 //Initialize all with false as we haven't visited anyone
 bool visited[v]={false};
 list<int> queue;
 
 //Making source vertex true as we visit it first
 visited[s]=true;
 
 //Pushing visited vertex in queue
 queue.push_back(s);
 
 list<int>::iterator i;
 
 while(!queue.empty())
 {
 	//Taking out front value from queue
 	s=queue.front();
 	
 	//Printing value 
 	cout<<s<<" ";
 	
 	//Removing visited vertex from queue
 	queue.pop_front();
 	
 	for(i=adj[s].begin();i!=adj[s].end();++i)
 	{
 		if(!visited[*i])//Checking if vertex is not visited
 		{
 			visited[*i]=true;//Mark it true as visited
 			queue.push_back(*i);//Pushing visited vertex in queue
 		}
 	}
 }
}


int main()
{
	Graph g(4);//Creating object of class Graph
	
	//Adding all edges
	g.addEdge(0,1);
	g.addEdge(0,2);
	g.addEdge(1,2);
	g.addEdge(2,0);
	g.addEdge(2,3);
	g.addEdge(3,3);
	
	cout<<"BFS = ";
	g.BFS(2);
	
	return 0;
}


