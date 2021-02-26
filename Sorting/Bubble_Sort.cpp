#include <iostream>
using namespace std;


void print(int a[],int n)
{
 for(int i=0;i<n;i++)
    cout<<a[i]<<" ";
}


void Bubble_Sort(int a[],int n)
{
	int flag=0;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n-i-1;j++)
		{
			if(a[j]>a[j+1])
			{
				int t=a[j];
				a[j]=a[j+1];
				a[j+1]=t;
				flag=1;
			}
		}
		if(flag==0)
			break;
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
    
 Bubble_Sort(a,n);
 print(a,n);
    
 return 0;
}

/*
Time Complexity
1.Best Case:O(n^2)
2.Average Case:O(n^2)
3.Worst Case:O(n^2)

Number of Swaps
1.Best Case:0
2.Average Case:N^2
3.Worst Case:n*(n-1)/2

Number of Comparisons
1.Best Case:O(n^2)
2.Average Case:O(n^2)
3.Worst Case:O(n^2)
*/






