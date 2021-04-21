#include <iostream>
#include <map>
#include <cstring>
using namespace std;


int count_anagram(string text,string word)
{
	int k=word.size();//k is window size
	int i=0,j=0,ans=0;

	
	//Creating map of word
	map<char,int> m;
	for(int i=0;i<k;i++)
		 m[word[i]]++;
	
	//Counts all distinct elements in map
	int count=m.size();
	
	
	while(j<text.size())
	{
		auto itr = m.find(text[j]);
		if(itr!= m.end())//If a charcter is present in map
		{
			//Decrease the count of charcter from map m
			 m[text[j]]--;
			 
			 //Decrease count if all chracters are used
			 if(itr->second==0)
			 	count--;
		}
		
		//If window size is not reached
		if(j-i+1<k)
			j++;
		
		else if(j-i+1==k)
		{
			//count=0 shows that all elements are used completely
			if(count==0)
			{
				ans++;
			}
			
			//Calculation to increase i
			itr = m.find(text[i]);
			if(itr!=m.end())//if character at starting of window is present in map
			{
				m[text[i]]++;//Increase count of that charcter in map m
				
				if(itr->second==1)
					count++;	
			}
			//Increasing window size
			i++;
			j++;		
		}
		
	}
	return ans;
		
}


int main()
{
	string text,word;
	cout<<"Enter Text:";
	cin>>text;
	
	cout<<"Enter Word:";
	cin>>word;
	
	cout<<count_anagram(text,word);
}

