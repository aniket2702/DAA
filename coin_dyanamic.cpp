#include<stdio.h>
#include<iostream>
#include <ctime>
#include <chrono>
using namespace std;


int minCoin(int a[10][100],int n,int A)
{
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=A;j++)
        {
            if(i==0 || j==0)
            {
                a[i][j]=0;
            }
            else if(i==1)
            {
                for(int k=0;k<=A;k++)
                {
                    a[i][k]=k;
                }
            }
            //copying upper element
            else if(i>j)
            {
                a[i][j]=a[i-1][j];
            }
            else{
                a[i][j]=min(a[i-1][j],a[i][j-i]+1);
            }
        }
    }
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=A;j++)
        {
            cout<<a[i][j]<<"   ";
        }
        cout<<endl;
    }
   return a[n][A]; 
}

int usedCoins(int n,int A,int a[10][100])
{
    int x[10];
    
    cout<<"\ncoins used are: "<<endl;
    for(int i=1;i<=n;i++)
    {
        if(x[i]==1)
        {
            cout<<i<<endl;
        }
        cout<<x[i];
    }
}



int main()
{
    int n,A,a[10][100],mini;
    cout<<"enter the number of denominations";
    cin>>n;
    cout<<"enter the amount: ";
    cin>>A;
    
    std::chrono::time_point<std::chrono::system_clock> start, end;
    start = std::chrono::system_clock::now();

    mini=minCoin(a,n,A);
    cout<<"minimum number of coins: "<<mini;
   
    end = std::chrono::system_clock::now();
    std::chrono::duration<double> elapsed_seconds = end - start;
    std::time_t end_time = std::chrono::system_clock::to_time_t(end);

    std::cout<< "\n\nTime taken " << elapsed_seconds.count() << "s\n";
    

return 0;
}