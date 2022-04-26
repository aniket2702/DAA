#include <bits/stdc++.h>
#include<chrono>
using namespace std;
using namespace std::chrono;


int travllingSalesmanProblem(int V,int graph[][4], int s)
{
	// store all vertex apart from source vertex
	vector<int> vertex;
	for (int i = 0; i < V; i++)
		if (i != s)
			vertex.push_back(i);

	// store minimum weight Hamiltonian Cycle.
	int min_path = INT_MAX;
	do {

		// store current Path weight(cost)
		int current_pathweight = 0;

		// compute current path weight
		int k = s;
		for (int i = 0; i < vertex.size(); i++) {
			current_pathweight += graph[k][vertex[i]];
			k = vertex[i];
		}
		current_pathweight += graph[k][s];

		// update minimum
		min_path = min(min_path, current_pathweight);

	} while (
		next_permutation(vertex.begin(), vertex.end()));

	return min_path;
}

int main()
{
	// matrix representation of graph
// 	int graph[][V] = { { 0, 10, 15, 20 },
// 					{ 10, 0, 35, 25 },
// 					{ 15, 35, 0, 30 },
// 					{ 20, 25, 30, 0 } };
    int V;
    cout<<"\nEnter number of  vertices= ";
    cin>> V;
    int graph[V][4];
    for(int i=0;i<V;i++)
    {
        for(int j=0;j<V;j++)
        {
            cout<<"\nEnter distance between "<<i<<" and "<<j<<" = ";
            cin>>graph[i][j];
        }
    }
	int s = 0;
	auto start = high_resolution_clock::now();
	cout << "Minimum distance= "<<travllingSalesmanProblem(V,graph,s) << endl;
	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(stop - start);

    cout << "\n\n\n\nTime taken by function: "<< duration.count() << " microseconds" << endl;
	return 0;
}

