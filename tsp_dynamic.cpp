#include<stdio.h>
#include<iostream>

using namespace std;
int arr[10][10],n,travelled[10],cost=0;

int least(int c)
{
    int nc=999,kmin, min =999;

    for(int i=0;i<n;i++)
    {
        if(arr[c][i]!=0 && travelled[i]==0)
        {
            if(arr[c][i]+arr[i][c]<min)
            {
                min=arr[i][0]+arr[c][i];
                kmin=arr[c][i];
                nc=i;
            }
        }
    }

    if(min!=999)
    {
        cost+=kmin;
    }

    return nc;
}
void mincost(int city)
{
    int ncity;
    travelled[city]=1;

    cout<<city+1<<"-->";
    ncity=least(city);

    if(ncity==999)
    {
        ncity=0;
        cout<<ncity+1;
        cost+=arr[city][ncity];
        return;
    }

    mincost(ncity);
}


int main()
{
    

    cout<<"Enter no of cities: ";
    cin>>n;

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>arr[i][j];

        }
        travelled[i]=0;
    }

    cout << "\n\nThe cost list is:";

    for (int i = 0; i < n; i++)
    {
        cout << "\n";

        for (int j = 0; j < n; j++)
            cout << "\t" << arr[i][j];
    }
    mincost(0);
    cout << "\n\nMinimum cost is " << cost;
}