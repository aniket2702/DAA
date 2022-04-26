#include<iostream>
#include<bits/stdc++.h>
#include<algorithm>
#include<vector>
#include<chrono>
using namespace std;
using namespace std::chrono;


int main()
{
	int i,flag=0,key;
	int mid,low,high;
	vector<int> values(10000);
	cout<<"\n\t\t\t\t BINARY SEARCH ITERATIVE";
	auto f = []() -> int { return rand() % 10000; };

	// Fill up the vector
	generate(values.begin(), values.end(), f);
	sort(values.begin(), values.end());
	for(i=0;i<values.size();i++)
	{
            cout<<values[i]<<" ";
	}
	// Get starting timepoint
	auto start = high_resolution_clock::now();

	cout<<"\nEnter search key= ";
	cin>>key;
	low=0;
	high=values.size()-1;


	while(low<=high)
	{
		mid=low + (high-low)/2;
		if(values[mid]==key)
		{
			cout<<"\nElement found at position "<<mid;
			flag=1;
			break;
		}
		else if(values[mid] < key)
			low=mid+1;
		else
			high=mid-1;

	}
	if(flag==0)
		cout<<"\nElement not found";

    auto stop = high_resolution_clock::now();

	// Get duration. Substart timepoints to
	// get durarion. To cast it to proper unit
	// use duration cast method
	auto duration = duration_cast<milliseconds>(stop - start);

	cout << "\nTime taken by function: "
	<< duration.count() << " milliseconds" << endl;

	return 0;

}

