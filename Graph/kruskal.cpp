#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct node
{
	int parent;
	int rank;
};

struct Edge
{
	int src;
	int dst;
	int wt;
};

vector<node> dsuf;
vector<Edge> mst;

bool comparator(Edge a,Edge b)
{
	return a.wt<b.wt;
}

int find(int v)
{
	if(dsuf[v].parent==-1)
		return v;
	return dsuf[v].parent=find(dsuf[v].parent);
}

void union_op(int fromP,int toP)
{
	if(dsuf[fromP].rank>dsuf[toP].rank)
		dsuf[toP].parent=fromP;
	else if(dsuf[fromP].rank<dsuf[toP].rank)
		dsuf[toP].parent=fromP;
	else
	{
		dsuf[fromP].parent=toP;
		dsuf[toP].rank+=1;
	}
}

void printMST()
{
	cout<<"MST formed is\n";
	for(auto p: mst)
		cout<<"src: "<<p.src<<"  dst: "<<p.dst<<"  wt: "<<p.wt<<"\n";
}

void kruskal(vector<Edge> &edge_List,int v,int e)
{
	sort(edge_List.begin(),edge_List.end(),comparator);
	int i=0,j=0;
	
	while(i<v-1 && j<e)
	{
		int fromP=find(edge_List[j].src);
		int toP=find(edge_List[j].dst);
		
		if(fromP==toP)
		{
			++j;
			continue;
		}
		
		union_op(fromP,toP);
		mst.push_back(edge_List[j]);
		i++;
	}
}

int main()
{
	int v,e;
	cin>>v>>e;
	dsuf.resize(v);
	for(int i=0;i<v;i++)
	{
		dsuf[i].parent=-1;
		dsuf[i].rank=0;
	}
	
	vector<Edge> edge_List;
	
	Edge tmp;
	
	for(int i=0;i<e;i++)
	{
		int from,to,wt;
		cin>>from>>to>>wt;
		tmp.src=from;
		tmp.dst=to;
		tmp.wt=wt;
		edge_List.push_back(tmp);
	}
	
	kruskal(edge_List,v,e);
	printMST();
}
