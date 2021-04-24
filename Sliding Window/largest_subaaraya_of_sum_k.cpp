#include <iostream>
#include <vector>
using namespace std;


int Largest_Subarray(vector<int> &arr,int k)
{
	int sum=0,i=0,j=0,maximum=0;
	
	while(j<arr.size())
	{
		sum=sum+arr[j];
		
		if(sum>k)
		{
			sum=sum-arr[i];
			i++;
		}
		
		else if(sum==k)
			maximum=max(maximum,j-i+1);
		
		j++;
	}
 return maximum;
}

int main()
{
	int n,k;
	
	cout<<"Enter Size Of Array:";
	cin>>n;
	
	vector<int> arr(n);
	for(int i=0;i<n;i++)
		cin>>arr[i];
	
	cout<<"Enter the sum";
	cin>>k;
	
	cout<<Largest_Subarray(arr,k);
	
	return 0;
}
