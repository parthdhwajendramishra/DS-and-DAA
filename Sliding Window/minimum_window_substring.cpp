#include <iostream>
#include <map>
#include <climits>
#include <cstring>
using namespace std;


int minimum_window_substr(string s,string t)
{
	int i=0,j=0,minimum=INT_MAX;

	
	//Creating map of t
	map<char,int> m;
	
	for(int i=0;i<t.size();i++)
		 m[t[i]]++;
	
	//Counts all distinct elements in map
	int count=m.size();
	
	while(j<s.size())
	{
		auto itr = m.find(s[j]);
		if(itr!= m.end())//If a charcter is present in map
		{
			//Decrease the count of charcter from map m
			 m[s[j]]--;
			 
			 //Decrease count if all chracters are used
			 if(itr->second==0)
			 	count--;
		}
		
		if(count==0)//count=0 shows that all elements are used completely		
		{	
			//Calculation to increase i
			while(count==0)
			{
				minimum=min(minimum,j-i+1);
				itr = m.find(s[i]);
				if(itr!=m.end())//if character at starting of window is present in map
				{
					m[s[i]]++;//Increase count of that charcter in map m
					if(itr->second==1)
						count++;	
				}
				i++;
			}
		}
		j++;	
	}
	return minimum;	
}


int main()
{
	string s,t;
	cout<<"Enter String:";
	cin>>s;
	
	cout<<"Enter Window String:";
	cin>>t;
	

	cout<<minimum_window_substr(s,t);
}

