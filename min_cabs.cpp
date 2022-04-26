#include <cstring> 
#include <iostream> 
#include <algorithm> 
#include <climits>
#include <chrono> 
#include <bits/stdc++.h> 
using namespace std;
using namespace std::chrono;
int main()
{ 
	int n; 
	cin>>n;
	vector<pair<int,int>> arr; 
	for(int i = 0 ; i<n;i++)
	{ 
		int start,end; 
		cin>>start>>end; 
		arr.push_back({start,end});
	}
	sort(arr.begin(),arr.end());
	int req = 0; 
	int tot = n;
	int k = 1;
	auto start = high_resolution_clock::now();
	while(tot>0)
	{
		cout<<"\nCab"<<k<<endl; 
		int i = 0; int start = INT_MIN; 
		while(i<n)
		{
			if(arr[i].first!=INT_MAX && start<=arr[i].first)
			{ 
				cout<<arr[i].first<<" - "<<arr[i].second<<endl;
				start = arr[i].second; 
				arr[i].first=INT_MAX;
				tot-=1; 
			} 
			i+=1;
		} 
		k+=1; 
		req+=1;
	}
	cout<<"\nMinimum Numbers of Cabs Required -> "<<req<<endl;
	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<nanoseconds>(stop - start);
	cout << "\n\nTime Taken : " << duration.count() << " nanoseconds" << endl;
//	for(int i=0;i<arr.size();i++)
//	{
//		cout<<arr[i].first<<" - "<<arr[i].second;
//	}
	return 0;
}
