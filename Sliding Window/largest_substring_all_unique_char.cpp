#include <iostream>
#include <cstring>
#include <climits>
#include <map>
using namespace std;

int largest_substring(string s)
{
	map<char,int>m;
	int i=0,j=0,maximum=INT_MIN;
	
	while(j<s.size())
	{
		m[s[j]]++;
		
		if(m.size()==j-i+1)
			maximum=max(maximum,j-i+1);
		
		else if(m.size()<j-i+1)
		{	
			//Deleting keys from map and incresing i
			while(m.size()<j-i+1)
			{
				m[s[i]]--;
				
				if(m[s[i]]==0)
					m.erase(s[i]);
				
				i++;
			}
		}
		j++;
		
	}
	return maximum;
}


int main()
{
	string s;
	int k;
	cout<<"Enter String:";
	cin>>s;
	
	
	cout<<largest_substring(s);
	return 0;
}
