
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int count,count1,i=0,grade[100];
    cin>>count;
    count1=count;
    while(count)    {
        cin>>grade[i++];

        count--;
    }

    i=0;
    while(count1)   {
        if(grade[i]<38) goto down1;

        if(grade[i]%5==3) grade[i]+=2;
        if(grade[i]%5==4) grade[i]+=1;

        down1:
        cout<<grade[i++]<<endl;
        count1--;
    }
    return 0;
}
