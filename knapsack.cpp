#include <bits/stdc++.h>
using namespace std;


int max(int a, int b) { return (a > b) ? a : b; }

int knapSack(int W, int wt[], int val[], int n)
{

	// Base Case
	if (n == 0 || W == 0)
		return 0;

	
	if (wt[n - 1] > W)
		return knapSack(W, wt, val, n - 1);

	
	else
	{
	    	int pick= val[n-1] + knapSack(W - wt[n - 1],wt, val, n - 1);
    		int not_pick=knapSack(W, wt, val, n - 1);
            return max(pick,not_pick);
	}
	
}

// Driver code
int main()
{
	int n,W;
	cout<<"\nEnter number of items= ";
	cin>>n;
	int val[n],wt[n];
	for(int i=0;i<n;i++)
	{
	    cout<<"\nEnter weight= ";
	    cin>>wt[i];
	    cout<<"\nEnter value= ";
	    cin>>val[i];
	}
// 	int val[] = { 60, 100, 120 };
// 	int wt[] = { 10, 20, 30 };
// 	int W = 50;
    cout<<"\nEnter knapsack capacity= ";
    cin>>W;
	cout << knapSack(W, wt, val, n);
	return 0;
}



