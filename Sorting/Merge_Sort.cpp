#include <iostream>
using namespace std;


void print(int a[],int n)
{
 for(int i=0;i<n;i++)
    cout<<a[i]<<" ";
}

void Merge(int a[],int l,int mid,int r)
{
	int x=mid-l+1;
	int y=r-mid;
	int p[x],q[y];
	
	for(int i=0;i<x;i++)
		p[i]=a[l+i];
		
	for(int i=0;i<y;i++)
		q[i]=a[mid+1+i];
		
	int i=0,j=0,k=l;
	
	while(i<x && j<y)
	{
		if(p[i]<=q[j])
			a[k++]=p[i++];
		
		else
			a[k++]=q[j++];
	}
	
	while(i<x)
		a[k++]=p[i++];
		
	while(j<y)
		a[k++]=q[j++];
}



void Merge_Sort(int a[],int l,int r)
{
	if(l<r)
	{
		int mid=l+ (r-l)/2;
		Merge_Sort(a,l,mid);
		Merge_Sort(a,mid+1,r);
		
		Merge(a,l,mid,r);
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
    
 Merge_Sort(a,0,n-1);
 print(a,n);
    
 return 0;
}
