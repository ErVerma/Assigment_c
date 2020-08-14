#include<stdio.h>
#include<stdlib.h>
#include<string.h>
 
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
  struct queue *waitList;
  
};


struct queue
{
  char s_name[20];
  int pty;
};
void gotoCourse(char *sname);
void deleteNode(char *snamec);
void increase(struct queue* wl,int j,char* sname,int p);
void insertq(struct queue wlt[],char* sname,int p);
struct bst* createBST(struct bst *root,char *sname); 
struct bst *insert(struct bst *root,struct bst *node);
void transplant(struct bst* tree, struct bst* node,struct bst* scr);
struct bst* searchNode(struct bst *root,char *s_name);
void printReglist(char *code,int nos,int w);
int treeWalkN(struct bst *rnode);
int treeWalkN1(struct bst *rnode);
struct queue* waitListMain();
struct bst * treeMin(struct bst * node);
