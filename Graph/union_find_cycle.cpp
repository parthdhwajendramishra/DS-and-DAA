#include <iostream>
#include <vector>
using namespace std;

vector<int> dsuf;

int find(int v)
{
	if(dsuf[v]==-1)
		return v;
	return find(dsuf[v]);
}

void union_op(int fromP,int toP)
{
	fromP=find(fromP);
	toP=find(toP);
	dsuf[fromP]=toP;
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
	
	dsuf.resize(v,-1);
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
	for(int i=0;i<v;i++)
		cout<<dsuf[i]<<" ";
	
	return 0;
}
