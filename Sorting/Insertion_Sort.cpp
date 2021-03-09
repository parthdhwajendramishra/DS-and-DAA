#include <iostream>
using namespace std;

void print(int a[],int n)
{
 for(int i=0;i<n;i++)
    cout<<a[i]<<" ";
}

void Insertion_Sort(int a[],int n)
{
	int key;
	for(int i=1;i<n;i++)
	{
		key=a[i];
		int j=i-1;
		
		while(j>=0 && key<a[j])
		{
			a[j+1]=a[j];
			j--;
		}
		a[j+1]=key;
	}
}

int main()
{
 int n;
 cout<<"Enter the size of Array:";
 cin>>n;
 
 int a[n];
 cout<<"Enter the values in Array"<<endl;
 
 for(int i=0;i<n;i++)
    cin>>a[i];
    
 Insertion_Sort(a,n);
 print(a,n);
    
 return 0;
}
