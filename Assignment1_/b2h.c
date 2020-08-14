#include"list.h"

//struct student* insert();
struct course sub[10];
int n;
struct student *slist=NULL,*temp=NULL;
//.........................................................................................
//MAIN START
int main()
{ 
 int i,j;
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
  //printf("\n Enter List");
   // printf("%s,%s",slist,temp);

//INSERT METHOD CALLING
   sub[i].regList=insert(sub,n,slist,temp);
   //printf("%d*************************",sub[i].regList);
   }
   char code[10];
  printf("\n Enter Course code to get Registered Students");
  scanf("%s",code);
  //printf("\nChecking name %s",(sub[0].regList).s_name);
  //printf("\nChecking name %s",(sub[0].regList).s_name);
//Show LINK LIST DATA
//int nr;   
//nr=getName(code,sub,n);CHANGEDstudent
//printf("\n InGETNAMEmanin");
 getName(code,sub,n);
//DELET NODE
char l_name[20],l_code[10];
printf("\nEnter   Name of Student to de-register");
 scanf("%s",l_name);
printf("\nCourse Code");
  scanf("%s",l_code);
int k;
k=delete(l_name,l_code,sub,n,slist,temp);
printf("%d record updated",k);
printf("\n Updated List");
getName(l_code,sub,n);

return 0;
}
//END
//........................................................

