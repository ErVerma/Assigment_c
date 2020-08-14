#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct course
{

 char c_code[10];
 char c_name[10];
  int c_credit;
   struct student* regList;
  
};
struct student
{
 char s_name[20];
 struct student *next;
};
int delete(char *l_name,char *l_code,struct course *sub,int n,struct student *slist,struct student *temp);
struct student* insert(struct course sub[10],int n,struct student *slist,struct student *temp);
void getName(char *code,struct course *sub,int n);
