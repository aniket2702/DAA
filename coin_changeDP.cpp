#include<bits/stdc++.h>
using namespace std;
	
int main()
{
		int size;
		cout<<"Enter the size : ";
		cin>>size;
		int arr[size];
		for(int i = 0;i<size;i++)
		{
			cin>>arr[i];
		}
		sort(arr,arr+size);
		int cost;
		cout<<"Enter the cost you want : ";
		cin>>cost;
		int dp[size][cost+1];
		// cout<<sizeof(dp)<<endl;
		memset(dp,0,sizeof(dp));
		for(int i = 0;i<size;i++)
		{
			dp[i][0] = 0;
		}
		for(int i  = 1;i<=cost;i++)
		{
			if(arr[0]>i)
			{
				dp[0][i] = INT_MAX;
			}
			else
			{
				if(i%arr[0]==0)
				{
					dp[0][i] = i/arr[0];	
				}
				else
				{
					dp[0][i] = INT_MAX;
				}
			}
		}
		
		for(int i  = 1;i<size;i++)
		{
			for(int j = 1;j<=cost;j++)
			{
				dp[i][j] = dp[i-1][j];
				if(arr[i]<=j)
				{
					if(dp[i-1][j-(arr[i]*(j/arr[i]))]!=INT_MAX)
					{
						dp[i][j] = min(dp[i][j],  j/arr[i] + dp[i-1][j-(arr[i]*(j/arr[i]))]);
					}
				}
			}
		}
		
		for(int i = 0;i<size;i++)
		{
			for(int j = 0;j<=cost;j++)
			{
				if(j==0)
				{
					cout<<arr[i]<<"      ";
				}
				else
				{
					cout<<dp[i][j]<<" ";
				}
				
			}
			cout<<endl;
		}
		
		cout<<"Minimum number of coins required are :  "<<dp[size-1][cost]<<endl;
	return 0;
}
