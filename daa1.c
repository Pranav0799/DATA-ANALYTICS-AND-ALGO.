/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>

int a,d,v[20],w[20],k[20][20],g,h;
char f[20][20];
void print(int a,int d)
{
                if(a==0 || d==0)
                                return;
                if(f[a][d]=='k')
                {
                                print(a-1,d-1);
                                printf("%d \n",v[a-1]);
                }
                else if(f[a][d]=='x')
                                print(a-1,d);
                else
                                print(a,d-1);
}
void findlcs()
{
                for(a=0;a<=g;a++)
                                k[a][0]=0;
                for(a=0;a<=h;a++)
                                k[0][a]=0;


                for(a=1;a<=g;a++)
                                for(d=1;d<=h;d++)
                                {
                                                if(v[a-1]==w[d-1])
                                                {
                                                                k[a][d]=k[a-1][d-1]+1;
                                                                f[a][d]='k';
                                                }
                                                else if(k[a-1][d]>=k[a][d-1])
                                                {
                                                                k[a][d]=k[a-1][d];
                                                                f[a][d]='x';
                                                }
                                                else
                                                {
                                                                k[a][d]=k[a][d-1];
                                                                f[a][d]='y';
                                                }
                                }
}
//The variables above namely:k, x and y signifies diagonal, up and downward directions in the matrix
int main()
{
   scanf("%d %d",&g,&h);
   for(a=0;a<g;a++){
       scanf("%d",&v[a]);
   }
   printf("-1");
   for(d=0;d<h;d++){
       scanf("%d",&w[d]);
   }
   printf("-1");

   findlcs();
   printf("\n");
   printf(" \n%d\n",k[g][h]);   //This will give the length of the LCS

   print(g,h);  //This will print the LCS
   printf("-1");
    return 0;
}
