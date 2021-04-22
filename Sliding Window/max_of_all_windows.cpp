#include <iostream>
#include <list>
#include <vector>
using namespace std;


vector<int> maximum(vector<int> &arr,int k)
{
	int i=0,j=0;
	vector<int> ans;
	list<int> l;
	
	while(j<arr.size())
	{
		while(l.size()>0 && l.back()<arr[j])
		{
			l.pop_back();
		}
		l.push_back(arr[j]);
		
		if(j-i+1<k)
			j++;
		
		else if(j-i+1==k)
		{
			//Storing answer
			ans.push_back(l.front());
			
			//Calculation before updating i
			if(l.front()==arr[i])
				l.pop_front();
				
			i++;
			j++;
		}
		
	}
	return ans;
}


int main()
{
	int n,k;
	
	cout<<"Enter Size Of Array:";
	cin>>n;
	
	vector<int> arr(n);
	for(int i=0;i<n;i++)
		cin>>arr[i];
	
	cout<<"Enter Size Of Window";
	cin>>k;
	
	vector<int> ans=maximum(arr,k);
	for(int i=0;i<ans.size();i++)
		cout<<ans[i]<<" ";
	
	return 0;
}


