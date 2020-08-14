#include<stdio.h>
#include<stdlib.h>
 struct bst* createBST(struct bst *root,char *sname); 
struct bst *insert(struct bst *root,struct bst *node);
void transplant(struct bst* tree, struct bst* node,struct bst* scr);
struct bst* searchNode(struct bst *root,char *s_name);
void printReglist(char *code,int nos,int w);
int treeWalkN(struct bst *rnode);
int treeWalkN1(struct bst *rnode);
struct bst * treeMin(struct bst * node);
struct bst
{
 struct bst *lchild;
 char s_name[10];
 struct bst *pnode;
 struct bst *rchild;
 
}; 


struct course
{
  char c_code[10];
  char c_name[10];
  int  c_credit;
  struct bst *regList;
  
};

//GLOBAL VARIABLES.....................................................................
int n,i,ch,nos,w;
char cde[10];
int count=0;

struct bst *root;
struct course sub[5];
//.........................................................................................
//MAIN START
int main()
{
char sname[10],s_name[10];

int l;
l=1;
char code[10];
int k;
struct bst *root;
root=NULL;
n=addCourse();
printf("%d  Courses Added",n);


while(l==1)
{
printf("\n Enter Your choice");
printf("\n Press 1 to Show Available Course");
printf("\n Press 2 to Register Student to Course");
printf("\n Press 3 to Show name of students in Ascending order");
printf("\n Press 4 to Show name of students in Descending order");
printf("\n Press 5 to Deregister Student from Course");
printf("\n Press 6 to get Top or Bottom n students");
scanf("%d",&ch);

/*struct bst rnode;
rnode.lchild=NULL;
rnode.rchild=NULL;
rnode.pnode=NULL;

root=rnode;*/

   switch(ch)
    {
      case 1: for(i=0;i<n;i++)
                {
                  printf("\n %s\t%s\t%d",sub[i].c_code,sub[i].c_name,sub[i].c_credit);
            
                }
              break;
      case 2: 
              printf("\n Enter Course code to which Student is to be register");
              scanf("%s",code);
              for(i=0;i<n;i++)
                  {
                    if(!strcmp(&sub[i].c_code,code))
                       {
                         root=sub[i].regList;
                          
                          sub[i].regList=createBST(root,sname);
                           printf("%u************",sub[i].regList);;
                        }
                       
                   } 
              
              break;
      case 3: 
                   printf("\n Enter Course code to get registered Students");
                   scanf("%s",code);
                   for(i=0;i<n;i++)
                    {
                          if(!strcmp(&sub[i].c_code,code))
                             {
                              root=sub[i].regList;
                               //printf("\n%u###############",root);
                          
                               printRegListAsc(root);
                              }
                    }
                  break;
      case 4:
                    printf("\n Enter Course code to get registered Students");
                    scanf("%s",code);
                    for(i=0;i<n;i++)
                    {
                          if(!strcmp(&sub[i].c_code,code))
                             {
                              root=sub[i].regList;
                               //printf("\n%u###############",root);
                          
                               printRegListDesc(root);
                                }
                    }
             
                    break;
      case 5:   printf("\n Enter Course code from which Student is to be deregister");
                scanf("%s",code);
                struct bst *node;
                for(i=0;i<n;i++)
                  {
                    if(!strcmp(&sub[i].c_code,code))
                       {
                         root=sub[i].regList;
                          printf("%u************",sub[i].regList);
                          printf("\n Enter Name of Student");
                          scanf("%s",s_name);
                          
                          node=searchNode(root,s_name);
                             if(node==NULL)
                                { 
                                  printf("\nNAME NOT FOUND");
           
                                }
                           else
                                {
                                 delete(root,node);
                                 }
                           
                        }
                       
                   } 
                  break;
      case 6: 
               printf("\n Enter Course code from where Students name to be fetch");
                scanf("%s",cde);
                
              printf("\n Enter number of students to get");
              scanf("%d",&nos);
              printf("\n Enter 0 for top %d students or 1 for bottom %d students",nos,nos);
              scanf("%d",&w);
              printRegListN(cde,nos,w);
              break;             
      default : printf("\n UC"); 
    }
  printf("\n press 1 for more");
  scanf("%d",&l);
  }
return 0;
}//main
//END
//...................................................................
//printRegList Start
void printRegListN(char *code,int nos,int w)
{
 struct bst *rnode;
                for(i=0;i<n;i++)
                  {
                    if(!strcmp(&sub[i].c_code,code))
                       {
                         rnode=sub[i].regList;
                        }
                  }
   if(w==1)
    {treeWalkN1(rnode);
    }
   else
    {treeWalkN(rnode);
    }
         
}
//End
//TREE WALK
int treeWalkN(struct bst *rnode)
{
    
   //printf("\n %d",nos);
  if(nos>0&&rnode!=NULL)
    {
      nos--;
    
     treeWalkN(rnode->lchild);
 // printf("\n count= %d nos=%d",count,nos);
 
     printf("\n %s",rnode->s_name);
  
     treeWalkN(rnode->rchild);
    }
}

int treeWalkN1(struct bst *rnode)
{
   
   //printf("\n %s",rnode->s_name);
    if(nos>0&&rnode!=NULL)
    {
     nos--;
      treeWalkN1(rnode->rchild);

 // printf("\n count= %d nos=%d",count,nos);
 
     printf("\n %s",rnode->s_name);
  
      treeWalkN1(rnode->lchild);
    }
}
//END
//...................................................................
//DELETE START
void delete(struct bst *root,struct bst *node)
{
 struct bst *min;
   if(node->lchild==NULL)
        transplant(root,node,node->rchild);
   else if(node->rchild==NULL)
         transplant(root,node,node->lchild);
   else
   { 
          min=treeMin(node->rchild);
              if(min->pnode!=node)
                   { 
                     transplant(root,min,min->rchild);
                      min->rchild=node->rchild;
                      min->rchild->pnode=min;
                   }   
          transplant(root,node,min);
           min->lchild=node->lchild;
           min->lchild->pnode=min;
   
   }
    

}
//END
//......................................................................
//transplant Start
void transplant(struct bst* tree, struct bst* node,struct bst* scr)
{
    if(node->pnode==NULL)
    {
     //root=scr;
     sub[i].regList=scr;
    }
    else if(node==node->pnode->lchild)
     {
      node->pnode->lchild=scr;
     }
     else
      node->pnode->rchild=scr;
     if(scr!=NULL)
       {
        scr->pnode=node->pnode;
       }
}
//end
//...................................................................
//TREE MIN
struct bst * treeMin(struct bst * node)
{
 while(node->lchild!=NULL)
  {
    node=node->lchild;
  }
 return node;
}
//end
//....................................................................
//SEARCH NODE START
struct bst* searchNode(struct bst *root,char *s_name)
 {
   if(strcmp(root->s_name,s_name)==0||root==NULL)
   { return root;
    }
  if(strcmp(root->s_name,s_name)>0)
   return searchNode(root->lchild,s_name);
  else if(strcmp(root->s_name,s_name)<0)
   return searchNode(root->rchild,s_name);
 }
//END
//...................................................................
//DESCTREEWALK START
void printRegListDesc(struct bst *root)
{
 treeWalkDesc(root);
}
void treeWalkDesc(struct bst *root)
 {
  if(root==NULL)
   {
    printf("\n");
   }
   else
          {
            treeWalkDesc(root->rchild);
             printf("%s",root->s_name);
             treeWalkDesc(root->lchild);
              //printf("%s",root->s_name);
                
              
          }
 }
//END
//TREEWALK START
void printRegListAsc(struct bst *root)
{
 treeWalk(root);
}
void treeWalk(struct bst *root)
 {
  if(root==NULL)
   {
    printf("\n");
   }
   else
          {
            treeWalk(root->lchild);
             printf("%s",root->s_name);
             treeWalk(root->rchild);
              //printf("%s",root->s_name);
                
              
          }
 }
//END
//........................................................
//insert start
struct bst* createBST(struct bst *root,char *sname)
{

int ch;
ch=1;

while(ch==1)
{
 struct bst *node=(struct bst*)malloc(sizeof(struct bst));
 printf("\n Enter Name of Student");
 scanf("%s",node->s_name);
 node->lchild=NULL;
 node->rchild=NULL;
 node->pnode=NULL;
//INSERT CALLING
root=insert(root,node);
printf("\n 1 for more");
scanf("%d",&ch);
 
}//while
 
return root;
}
//END
//........................................................
//insert start
struct bst *insert(struct bst *root,struct bst *node)
 {
      if(root==NULL)
       {
          root=node;
          
       }
      else
      {//0 
             if(strcmp(root->s_name,node->s_name)<0)
             {//1
               if(root->rchild==NULL)
                 {
                  root->rchild=node;
                  node->pnode=root;
                   printf("\n ..................parent %s",root->s_name);
                 }
               else
                {
                 insert(root->rchild,node);
                }
               
             }//1
            else
             {//2
                    if(root->lchild==NULL)
                       {
                            root->lchild=node;
                            node->pnode=root;
                            printf("\n ..............parent %s",root->s_name);
                       }
                    else
                       {
                            insert(root->lchild,node);
                       }
               
                
              }//2
      }//0
 
return root; 
}

//END
//...........................................................
//ADD COURSE START
int addCourse()
{
    printf("\n Enter Number of Courses Available");
    scanf("%d",&n);
    for(i=0;i<n;i++)
      {
        printf("\n Enter Course %d code",i+1);
        scanf("%s",&(sub[i].c_code));
        printf("\n Enter Course %d Name",i+1);
        scanf("%s",&(sub[i].c_name));
        printf("\n Enter Course %d credit",i+1);
        scanf("%d",&(sub[i].c_credit));
        sub[i].regList=NULL;
      }
 return n;
}
//END
//........................................................

