#include"queue.h"
/*#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//void increase(struct queue* wl,int j,int p);
//void insert(struct queue *waitList,char sname);
struct queue
{
  char s_name[20];
  int pty;
};*/
//GLOABAL VARIABLE
int i,maxLimit=20;
i=-1;

struct queue waitList[20];
//MAIN START

struct queue* waitListMain()
{
int ch,cont,p;
cont=1;
char sname[20];
//printf("\n Enter MAX LIMIT");
//scanf("%d",maxLimit);

while(cont==1)
{
printf("\n Enter 1 for Insert" );
printf("\n Enter 2 for Exctract Max" );
printf("\n Enter 3 for Decrease Key Max");
printf("\n Enter 4 for Change Course of Student in Waiting List");

scanf("%d",&ch);
int index,dkey;
char *nfd[20],snamec[20];
    switch(ch)
    {
      case 1:  
            printf("\n Enter Name of Student");
            scanf("%s",sname);
             printf("\n Enter Priority for Node");
              scanf("%d",&p);
              // printf("\n insert call priority=%d",p);
           // printf("calling insert  %s %u",sname,waitList);
          
            insertq(waitList,sname,p);
            break;
      case 2: printf("\n Maximum Priority Element");
                 extractMax(waitList);
             
              break;
      case 3: printf("\n Enter Name of Student to perform Decrease Key");
              scanf("%s",nfd);
              printf("\n Enter priority to Change");
              scanf("%d",&dkey);
              for(index=0;index<i;index++)
               {
                 if(!strcmp(waitList[index].s_name,nfd))
                   { 
                    decreaseKey(waitList,index,dkey);
                    }
               }
               break;
      case 4:
              printf("\n Enter Name of Student to change course code");
              scanf("%s",snamec);
              deleteNode(snamec);
              gotoCourse(snamec);
              break;
               
      default :   
            printf("\nuc");
                    
    }
  printf("\n Press 1 for continue operation in waitlist");
  scanf("%d",&cont);
}
return waitList;
}
//MAIN WaitList END

//........................................................................
//Delete Start
void deleteNode(char *snamec)
{
 int index;
  for(index=0;index<=i;index++)
    {
      if(!strcmp(waitList[index].s_name,snamec))
       {
          increase(waitList,index,snamec,maxLimit);
           extractMax(waitList);
       }
    }
    
}
//End
//.........................................................................
//Decrease KEY
void decreaseKey(struct queue* wl,int ix,int dkey)
 {
  // printf("\n Decrease Key UC");
    if(dkey>wl[ix].pty)
       {
          printf("\n Decrease key atmost %d",wl[ix].pty);
        }
    else
       {
         wl[ix].pty=dkey;
         maxHeapify(wl,ix);
        }
   
 }
//END
//........................................................................
//INSERT START
void insertq(struct queue wl[],char* sname,int p)
{
 i=i+1;
   //strcpy(waitList[i].s_name,NULL);
    
   wl[i].pty=-1;
  // printf("\n insert method 1%s %u",sname,waitList);
    
    
 increase(wl,i,sname,p);

 
}
//END
//.........................................................................
//INCREASE 
void increase(struct queue wl[],int j,char* sname,int p)
{ int parent;
   //printf("\n increase fun");
  char tname[20];
  int tpty;
 if(p<wl[j].pty)
    {printf("\n ERROR");}
  else
   {strcpy(&wl[j].s_name,sname);
   wl[j].pty=p;
   
   //printf("increased");
   }
    parent=prnt(j);
   while(i>1&&wl[parent].pty<wl[j].pty)
    { 
      tpty=wl[parent].pty;
      strcpy(tname,wl[parent].s_name);
      wl[parent].pty=wl[j].pty;
      strcpy(wl[parent].s_name,wl[j].s_name);
      wl[j].pty=tpty; 
      strcpy(wl[j].s_name,tname);
      j=prnt(j);
           
    }
}
//END
//Find Parent
int prnt(int k)
{
 if(k>1&&k<maxLimit)
   {
    return k/2;
    }
  else
   return -1;
}
//End
//Extract MAx
void extractMax(struct queue* wl)
{
 if(i<1)
   printf("\n Underflow");
 else
  {
   printf("Name %s priority %d MAX",wl[1].s_name,wl[1].pty);
   strcpy(wl[1].s_name,wl[i].s_name);
     wl[1].pty=wl[i].pty;
    i=i-1;
     maxHeapify(wl,1);
  }
}
//END
//................................
//HEAPIFY START
void maxHeapify(struct queue* wl,int j)
{
 int l,r,lrg,tpty;
 char tname[20];
   l=2*j+1;
   r=2*j+2;
   if(l<=i&&wl[l].pty>wl[j].pty)
     {
       lrg=l;
      }
    else {lrg=j;}
    if(r<=i&&wl[r].pty>wl[lrg].pty)
      {lrg=r;}
    if(lrg!=j)
       {
           tpty=wl[j].pty;
           strcpy(tname,wl[j].s_name);
           wl[j].pty=wl[lrg].pty;
           strcpy(wl[j].s_name,wl[lrg].s_name);
           wl[lrg].pty=tpty; 
           strcpy(wl[lrg].s_name,tname);
           maxHeapify(wl,lrg);

       }
}
//END
