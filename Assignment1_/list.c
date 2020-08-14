
#include"list.h"




//Delete Start
int delete(char *l_name,char *l_code,struct course *sub,int n,struct student *slist,struct student *temp)
{
//struct student *slist,*temp=NULL;

struct student *hdr,*trgt,*nxt,*prv;
int i;
 for(i=0;i<n;i++)
 {
  if(!strcmp(l_code,&(sub[i].c_code)))
    {//search name delete
      printf("\n Course searched");
      hdr=sub[i].regList;
       //CASE 1
          if(hdr==NULL)
            {
             printf("\n No Student registered for Given Course");
                
                 return 0;
            }
       //CASE 2
            else if(hdr->next==NULL)
              {
                  //printf("\nxxxxxxxxxxxxxxxxxxxxx");
                  printf("%s",(hdr->s_name));
                     if(!strcmp(hdr->s_name,l_name))
                   {   trgt=hdr;
                       hdr=NULL;
                       free(trgt);
                       sub[i].regList=hdr;
                       return 1;
                    }
                   else
                     {  printf("\nGiven Student Not Registered for given Course");
                     return 0;
                    }

               }
           //case 3
                   else
                       {//first element
                           if(!strcmp(hdr->s_name,l_name))
                               { 
                                  trgt=hdr;
                                  hdr=hdr->next;
                                 // free(trgt);
                                   trgt=NULL;
                                     sub[i].regList=hdr;
                                     return 1;
                                }
                                 trgt=hdr;
                               while(strcmp(trgt->s_name,l_name)&&trgt->next!=NULL)
                                    {   prv=trgt;
                                        trgt=trgt->next;
                                            //printf("\nxxxxxxxxxxx2node");
                                        if(trgt->next==NULL)
                                           { 
                                               if(!strcmp(trgt->s_name,l_name))
                                                  {// printf("\nxxxxxxxxxxxlastnode");
                                                    prv->next=NULL;
                                                     free(trgt);
                                                       sub[i].regList=hdr;
                                                       return 1;
                                                   }
                                                else
                                                   { printf("\n Given Student is not Registered for given Course");
                                                      sub[i].regList=hdr;
                                                       return 0;
                                                   }
                                            }
                                         else
                                            {
                                              nxt=trgt->next;
                                              }
                                    }
                                     free(trgt);
                                     prv->next=nxt;
                          sub[i].regList=hdr;
                           return 1;
                        } 
                        

       
      
     }

  }
printf("\n Course not found");
return 0;
}
//END
//...............
//INSERT START
struct student* insert(struct course *sub,int n,struct student *slist,struct student *temp)
{
 int ch;
 //char choice;
struct student* snode = (struct student*) malloc(sizeof(struct student));

snode->next=NULL; 
 printf("\n Enter Name of Student to register");
 scanf("%s",snode->s_name);
  
 printf("CHECKING %s",&(snode->s_name));
//INSERTION SORT
/*
int sort;
printf("\n***********1");
sort=strcmp(snode->s_name[0],temp->s_name[0]);
if(sort>0)
{ printf("\n %s > %s",snode->s_name[0],temp->s_name);
}
else if(sort<=0);
{printf("\n***********2");
 printf("\n %s < %s",snode->s_name[0],temp->s_name);
}*/
//SAME
snode->next=temp;

  //printf("\nnext data %u",snode->next);
 temp=snode;
 printf("\n Do you want to Register More Students(1/n)");
 scanf("%d",&ch);
 if(ch==1)
  {  
   slist = insert(sub,n,slist,temp);
  }
  
   else
    { 
      slist=temp;
        temp=NULL;
        
       
    // printf("\n####################%s",slist->s_name);
  }
   return slist;
}
//END
//..............................................................................
//GET NAME
void getName(char *code,struct course *sub,int n)
{
  //printf("\n getName1");
 struct student *s,*p;
  int i;
 // printf("\n getName2");
 
  for(i=0;i<n;i++)
  {
   //printf("\n getName3");
    int k;
   //printf("%s\t%s",&(sub[i].c_code),code);
    //printf("%d",strcmp(code,&(sub[i].c_code)));
   k=strcmp(code,&(sub[i].c_code));
  // printf("\n %d**************8",k);
      // printf("\n 56666666666666666666666666666666666");      
       s=sub[i].regList;
       //printf("%d",s);
//printf("\n 56666666666666666666666666666666666");
    if(k==0)
     { 
      // printf("\n getName4");
      
       s=sub[i].regList;
       printf("%d",s);
        while(s->next!=NULL)
         {
          // printf("\n %u getName5",s->next);
        
        printf("\n%s",s->s_name);
        s=s->next;  
         }
        // printf("\n getName5");
        printf("\n%s",s->s_name);
     }  
       // printf("\n getName6");
  }
}
//END
