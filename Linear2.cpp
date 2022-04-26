#include<iostream>
#include<algorithm>
#include<vector>
#include<chrono>
using namespace std;
using namespace std::chrono;
int main()
{
	vector<int> values(1000);
    int key,i,flag=0;
	// Generate Random values
	cout<<"\n\t\t\t\t LINEAR SEARCH";
	auto f = []() -> int { return rand() % 1000; };

	// Fill up the vector
	generate(values.begin(), values.end(), f);
	for(i=0;i<values.size();i++)
	{
            cout<<values[i]<<" ";
	}
	// Get starting timepoint
	auto start = high_resolution_clock::now();
    cout<<"\nEnter search key= ";
    cin>>key;
	for(i=0;i<values.size();i++)
	{
		if(values[i]==key)
		{
			cout<<"\nElement found at position "<<i;
			flag=1;
		}

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

