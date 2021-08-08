#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Graph
{
  
  public:
  int v,e,id,sccCount;
  Graph(int v,int e);
  void DFS(vector<int> graph[],int sv,vector<bool> &onStack,vector<int> &ids,vector<int> &low,stack<int> &s);
  void Scc(vector<int> graph[],vector<bool> &onStack,vector<int> &ids,vector<int> &low,stack<int> &s);
  void input();
};


void Graph::DFS(vector<int> graph[],int sv,vector<bool> &onStack,vector<int> &ids,vector<int> &low,stack<int> &s)
{
  s.push(sv);
  onStack[sv]=true;
  ids[sv]=low[sv]=id++;

  vector<int>::iterator i;

  //Visitin all neighbours of Source Vertex
  for(i=graph[sv].begin();i!=graph[sv].end();i++)
  {
    //If its' neighbour is not visited
    if(!ids[*i])
      DFS(graph,*i,onStack,ids,low,s);

	//If a node is already on stack
    if(onStack[*i])
      low[sv]=min(low[sv],low[*i]);
  }

  //To check if we are at start of a strongly connected component
  if(ids[sv]==low[sv])
  {
  	//Removing all nodes of component from stack
    while(!s.empty())
    {
      int node=s.top();
      onStack[node]=false;
      
      //Marking low link value with same smalest id 
      low[node]=ids[sv];
      
      //Stop popping stack once we reach start of th SCC
      if(node==sv)
        break;
        
      s.pop();
    }
    //Increasing SCC Count
    sccCount++;
  }
}


void Graph::Scc(vector<int> graph[],vector<bool> &onStack,vector<int> &ids,vector<int> &low,stack<int> &s)
{
  for(int i=0;i<v;i++)
    if(ids[i]==0)
      DFS(graph,i,onStack,ids,low,s);

}


void Graph::input()
{
  vector<int> graph[v];
  vector<bool> onStack(v,false);

  vector<int> ids(v,0);
  vector<int> low(v,0);

  stack<int> s;
  
  //Adding edges in the graph
  cout<<"Enter Source and Destination Vertex"<<endl;
  cout<<"Source------>Destination"<<endl;
  for(int i=0;i<e;i++)
  {
    int source,destination;
    cin>>source>>destination;
    graph[source].push_back(destination);
  }
  Scc(graph,onStack,ids,low,s);
}


Graph::Graph(int v,int e)
{
  this->v=v;
  this->e=e;
  this->id=0;
  this->sccCount=0;
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

    cout<<"Scc Count="<<g.sccCount;

    return 0;
}
