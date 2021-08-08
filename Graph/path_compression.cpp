#include <iostream>
#include <vector>
using namespace std;

struct node
{
	int parent;
	int rank;
};

vector<node> dsuf;

int find(int v)
{
	if(dsuf[v].parent==-1)
		return v;
	return dsuf[v].parent=find(dsuf[v].parent);
}

void union_op(int fromP,int toP)
{
	if(dsuf[fromP].rank> dsuf[toP].rank)
		dsuf[toP].parent = fromP;
	else if(dsuf[fromP].rank< dsuf[toP].rank)
		dsuf[fromP].parent=toP;
	else
	{
		dsuf[fromP].parent=toP;
		dsuf[toP].rank+=1;
	}
}


bool isCyclic(vector<pair<int,int>>& edge_List)
{
	for(auto p:edge_List)
	{
		int fromP =find(p.first);
		int toP=find(p.second);
		
		if(fromP==toP)
			return true;
		
		union_op(fromP,toP);
	}
	return false;
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
	vector<pair<int,int>> edge_List;
	
	for(int i=0;i<e;i++)
	{
		int from,to;
		cin>>from>>to;
		edge_List.push_back({from,to});
	}
	
	if(isCyclic(edge_List))
		cout<<"True";
	else
		cout<<"False";
	
	cout<<endl;
	//for(int i=0;i<v;i++)
		//cout<<dsuf[i]<<" ";
	
	return 0;
}
