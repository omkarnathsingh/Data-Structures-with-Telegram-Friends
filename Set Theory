/*
Author: Omkar Nath Singh

#DS Day 1, 
Problem Statement: 
In Second year Computer Engineering class of M students, set A of students play cricket and set B of students play badminton. Write program to find and display-
i. Set of students who play either cricket or badminton or both
ii. Set of students who play both cricket and badminton
iii. Set of students who play only cricket
iv. Set of students who play only badminton
v. Number of students who play neither cricket nor badminton.
(Note- While realizing the set duplicate entries are to avoided)
*/

#include<iostream>

#define M 20

using namespace std;

class SEComp    {
private:        
        int setA[M],setB[M],c1,c2;
        
protected: 
        int ifexists(int t[],int l)      {
                int max=0;
        for(int a=0;t[a]!=0;a++)
                max++;
                          
                
        for(int i=0;i<max;i++)
                if(t[i]==l) return 1;
        return 0;
        }
        void eitherorboth();
        void both();
        void onlyCricket();
        void onlyBadminton();
        void neithernor();
        
public:
        void getData();
        void showData();
};

int main()      {
        int choice;
        SEComp obj;
        obj.getData();
        while(1)        {
        obj.showData();
        }
        return 0;
}

void SEComp::getData()  {
        cout<<"Enter count who play Cricket: ";
        cin>>c1;
        cout<<"Enter rollno who play Cricket: ";
        for(int i=0;i<c1;i++)        cin>>setA[i];
        
        cout<<"Enter count who play Badminton: ";
        cin>>c2;
        cout<<"Enter rollno who play Badminton: ";
        for(int i=0;i<c2;i++)        cin>>setB[i];
        
}

void SEComp::showData() {
        int choice,r;
       cout<<"\n\n\n Result Set types "
           <<"\n 1. Set of students who play either cricket or badminton or both"
           <<"\n 2. Set of students who play both cricket and badminton"
           <<"\n 3. Set of students who play only cricket"
           <<"\n 4. Set of students who play only badminton"
           <<"\n 5. Number of students who play neither cricket nor badminton"
           <<"\n 6. Exit"
           <<"\n Enter your choice: ";
       
       cin>>choice;
       switch(choice)   {
                case 1: eitherorboth();  break;
                case 2: both();          break;
                case 3: onlyCricket();   break;
                case 4: onlyBadminton(); break;
                case 5: neithernor();    break;
                case 6: exit(0);
                default: "Invalid choice entered !!! ";
       }
}


void SEComp::onlyCricket()      {
        int rs[M],i,r=0;
        
        for(i=0; i<c1; i++,r++)
                rs[r]=setA[i];
                
               
        for(i=0; i<c1; i++)     {
                if(ifexists(setB,rs[i]))      {
                        rs[i]=0;
                }
        }
        
        cout<<"\n Set of students with only Cricket: \n";
        for(i=0; i<c1; i++)     {
                if(rs[i]!=0)    cout<<rs[i]<<"\t";
        }
}

void SEComp::onlyBadminton()      {
        int rs[M],i,r=0;
        
        for(i=0; i<c2; i++,r++)
                rs[r]=setB[i];
                
               
        for(i=0; i<c2; i++)     {
                if(ifexists(setA,rs[i]))      {
                        rs[i]=0;
                }
        }
        
        cout<<"\n Set of students with only Badminton: \n";
        for(i=0; i<c2; i++)     {
                if(rs[i]!=0)    cout<<rs[i]<<"\t";
        }
                
        
}

void SEComp::both()     {
        int rs[M],i,r=0;
        
        for(i=0; i<c1; i++,r++)
                rs[r]=setA[i];
                
               
        for(i=0; i<c1; i++)     {
                if(!ifexists(setB,rs[i]))      {
                        rs[i]=0;
                }
        }
        
        cout<<"\n Set of students with both Cricket and Badminton: \n";
        for(i=0; i<c1; i++)     {
                if(rs[i]!=0)    cout<<rs[i]<<"\t";
        }
}

void SEComp::eitherorboth()     {
        int rs[M],i,r=0;
        
        for(i=0; i<c1; i++,r++)
                rs[r]=setA[i];
                
        r--;       
        for(i=0; i<c2; i++,r++)     {
                if(!ifexists(rs,setB[i]))      {
                        rs[r]=setB[i];
                }
        }
        
        cout<<"\n Set of students with either Cricket or Badminton or both: \n";
        for(i=0; i<r; i++)     {
                if(rs[i]!=0)    cout<<rs[i]<<"\t";
        }
}

void SEComp::neithernor()       {
        int count=M-c1-c2;
        
        int rs[M],i,r=0;
        
        for(i=0; i<c1; i++,r++)
                rs[r]=setA[i];
                
               
        for(i=0; i<c1; i++)     {
                if(!ifexists(setB,rs[i]))      {
                        rs[i]=0;
                }
        }
        
        for(i=0; rs[i]!=0; i++)     {
                count++;
        }
        
        cout<<"\n Count of students with neither Cricket nor Badminton : "<<count;
}

