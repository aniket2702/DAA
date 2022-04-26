#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int minSubArray(int nums[],int n) {
        int sum=0;
        int minimum=INT_MAX;
        for(int i=0;i<n;i++)
        {
            if(sum>0)
            {
                sum=nums[i];
            }
            else
            {
            	sum+=nums[i];
			}
			minimum=min(minimum,sum);
        }
        return minimum;
}

int main()
{
	int arr[] = {3, -4, 2, -3, -1, 7, -5};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Smallest sum: "
         << minSubArray(arr, n);
}
