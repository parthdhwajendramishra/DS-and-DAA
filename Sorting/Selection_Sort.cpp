#include <iostream>
using namespace std;


void print(int a[],int n)
{
 for(int i=0;i<n;i++)
    cout<<a[i]<<" ";
}


void Selection_Sort(int a[],int n)
{
	int min,pos;
	for(int i=0;i<n-1;i++)
	{
		min=a[i];
		pos=i;
		for(int j=i+1;j<n;j++)
		{
			if(min>a[j])
			{
				min=a[j];
				pos=j;
			}
		}
		
		if(pos!=i)
		{
			a[pos]=a[i];
			a[i]=min;
		}
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
    
 Selection_Sort(a,n);
 print(a,n);
    
 return 0;
}

/*
Time Complexity
1.Best Case:O(n^2)
2.Average Case:O(n^2)
3.Worst Case:O(n^2)


Space Complexity:O(1)

Number of Swaps
1.Best Case: N
2.Average Case:N
3.Worst Case:N

Number of Comparisons
1.Best Case:O(n*(n+1)/2)
2.Average Case:O(n*(n+1)/2)
3.Worst Case:O(n*(n+1)/2)
*/






