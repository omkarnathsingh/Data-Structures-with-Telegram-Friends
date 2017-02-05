#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    long int n,m,a,b,k,large=0,i,x=0;
    cin>>n>>m;
    long int *arr=new long int[n+1]();
    
    
   for(i=0;i<m;i++)
    {
        cin>>a>>b>>k;
        arr[a]+=k;
        if((b+1)<=n) arr[b+1]-=k;
    }

    for(i=1;i<=n;i++)
    {
       x=x+arr[i];
       if(large<x) large=x;

    }

        
    cout<<large;
    return 0;
}
/*
Sample Input

5 3
1 2 100
2 5 100
3 4 100
Sample Output

200
Explanation

After first update list will be 100 100 0 0 0. 
After second update list will be 100 200 100 100 100.
After third update list will be 100 200 200 200 100.
So the required answer will be 200.

*/
