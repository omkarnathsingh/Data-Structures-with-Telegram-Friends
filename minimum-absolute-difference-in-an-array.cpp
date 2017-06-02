#include <bits/stdc++.h>
using namespace std;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
     int n,i=0;
    cin>>n;
    int arr[20];

    while(n){
      cin>>arr[i];
      i++;
      n--;
    }
    int diff = INT_MAX;

    // Find the min diff by comparing difference
    // of all possible pairs in given array
    for (i=0; i<n-1; i++)
       for (int j=i+1; j<n; j++)
           if (abs(arr[i] - arr[j]) < diff)
                 diff = abs(arr[i] - arr[j]);

   cout <<diff;
    return 0;
}
