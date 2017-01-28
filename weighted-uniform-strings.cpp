#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;



int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    string str;
    getline(cin,str);
    int ln=str.length();
    int n,c,val,itr=0,sstr[100],i=0,cont=0;
   
    while(ln) {   
        val=str[itr]-96;
        //cout<<val<<endl;
        sstr[i++]=val;
        cont=2;
        while(val==(str[itr+1]-96)){
            //cout<<val*cont<<endl;
            sstr[i++]=val*cont;
            cont++;
            itr++;
            ln--;
        }
        itr++;
        ln--;
    }    
    
    
    cin>>c;
    while(c)    {
        cin>>n;
        bool exist=find(begin(sstr),end(sstr),n)!=end(sstr);
        
        if(exist)   {
            cout<<"Yes"<<endl;
        }
        else    {
            cout<<"No"<<endl;
        }
       c--;
    }
    return 0;
}

