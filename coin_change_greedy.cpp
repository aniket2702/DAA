#include <iostream>
#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n,cost;
    cout<<"\nEnter number of coins= ";
    cin>>n;
    int coins[n+1];
    int ans[n];
    int size=0;
    for(int i=0;i<n;i++)
    {
        cout<<"\nEnter value of coin= ";
        cin>>coins[i];
    }
    cout<<"\nEnter desired amount= ";
    cin>>cost;
    
    sort(coins,coins+n);
    for(int i=n-1;i>=0;i--)
    {
        if(cost >= coins[i])
        {
            cost-=coins[i];
            ans[size]=coins[i];
            size++;
        }
    }
    if(cost==0)
    {
        for(int i=0;i<size;i++)
        {
            cout<<"\ncoin= "<<ans[i];
        }
        cout<<"\nMinimum coins required= "<<size;
    }
    else
    {
        cout<<"\nNot found";
    }
}
