#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;
void print_matrix(int);
void print_com(int);
int check(int);
void random();
   char a[3][3]={' ',' ',' ',' ',' ',' ',' ',' ',' '};
   int x,randomnum;

int main() {
      x=0;
     print_matrix(x);
       cout<<"\n\n";
      cin>>x;
      cout<<endl<<endl;
      print_matrix(x);
     for(int i=0;i<4;i++)
     { random();
      cin>>x;
      cout<<endl<<endl;
      print_matrix(x);	
	 }
}

void print_matrix(int x)
{  if(x==0){
     for(int i=0;i<3;i++)
   { 
       for(int j=0;j<3;j++)
   { 
      { cout<<a[i][j];
       if(j<2)
       cout<<"|";}
   }
   if(i<2)
   cout<<"\n-----\n";
   }
}
       else
       {
           switch(x)
           {
               case 7:a[0][0]='X';
               break;
               case 8:a[0][1]='X';
               break;
               case 9:a[0][2]='X';
               break;
               case 4:a[1][0]='X';
               break;
               case 5:a[1][1]='X';
               break;
               case 6:a[1][2]='X';
               break;
               case 1:a[2][0]='X';
               break;
               case 2:a[2][1]='X';
               break;
                case 3:a[2][2]='X';
               break;
               
           }
               for(int i=0;i<3;i++)
   { 
       for(int j=0;j<3;j++)
   { 
      { cout<<a[i][j];
       if(j<2)
       cout<<"|";}
   }
   if(i<2)
   cout<<"\n-----\n";
   }  cout<<endl<<endl<<"-----------------------------"<<endl<<endl;
       }
}

void print_com(int x)
{  
           switch(x)
           {
               case 7:a[0][0]='O';
               break;
               case 8:a[0][1]='O';
               break;
               case 9:a[0][2]='O';
               break;
               case 4:a[1][0]='O';
               break;
               case 5:a[1][1]='O';
               break;
               case 6:a[1][2]='O';
               break;
               case 1:a[2][0]='O';
               break;
               case 2:a[2][1]='O';
               break;
                case 3:a[2][2]='O';
               break;
               
           }
               for(int i=0;i<3;i++)
   { 
       for(int j=0;j<3;j++)
   { 
      { cout<<a[i][j];
       if(j<2)
       cout<<"|";}
   }
   if(i<2)
   cout<<"\n-----\n";
   }    cout<<endl<<endl<<"-----------------------------"<<endl<<endl;
       }
      
 int check(int x)
{  
           switch(x)
           {
               case 7:if((a[0][0])==' ')
               return 0;
               else return 1;
             //  break;
               case 8:if((a[0][1])==' ')
                return 0;
               else return 1;
              // break;
               case 9:if((a[0][2])==' ')
                return 0;
               else return 1;
              // break;
               case 4:if((a[1][0])==' ')
                return 0;
               else return 1;
              // break;
               case 5:if((a[1][1])==' ')
                return 0;
               else return 1;
              // break;
               case 6:if((a[1][2])==' ')
                return 0;
               else return 1;
              // break;
               case 1:if((a[2][0])==' ')
                return 0;
               else return 1;
               //break;
               case 2:if((a[2][1])==' ')
                return 0;
               else return 1;
              // break;
                case 3:if((a[2][2])==' ')
                 return 0;
               else return 1;
              // break;
               
           }
}

   void random()
   { int c;
   	srand((unsigned) time(0));
   	do{
	   randomnum=(1+rand()%9);
	   c= check(randomnum);
	    } while(c!=0);
   	print_com(randomnum);
   }
   
    

