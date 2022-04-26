#include<iostream>
#include<chrono>
using namespace std;
using namespace std::chrono;
int main()
{
	int st[10],ft[10],count=0;
	int n;
	cout<<"\nEnter number of persons= ";
	cin>>n;
	
	for(int i=0;i<n;i++)
	{
		cout<<"\nEnter start time of person "<<i+1<<" = ";
		cin>>st[i];
		cout<<"\nEnter finish time of person "<<i+1<<" = ";
		cin>>ft[i];
	}
	
	auto start1=high_resolution_clock::now();
	int temp,temp2;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n-i-1;j++)
		{
			if(ft[j] > ft[j+1])
			{
				temp=ft[j];
				ft[j]=ft[j+1];
				ft[j+1]=temp;
				
				temp2=st[j];
				st[j]=st[j+1];
				st[j+1]=temp2;
			}
		}
	}
	
	cout<<"\n\nAfter sorting: "<<endl;
	for(int i=0;i<n;i++)
	{
		cout<<st[i]<<" - "<<ft[i]<<endl;
	}
	int start=ft[0];
	for(int i=1;i<n;i++)
	{
		if(st[i] >= start)
		{
			start=ft[i];
			count++;
		}
	}
	auto stop1=high_resolution_clock::now();
	auto duration=duration_cast<nanoseconds>(start1-stop1);
	cout<<"\nMinimum cabs required= "<<count;
	cout<<"\nTime take in nanoseconds= "<<duration.count();
}
