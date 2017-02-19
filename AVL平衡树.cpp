#include<iostream>
#include<cstring>
#include<cstdio>
#include<cstdlib>
using namespace std;

struct avlNode{
int data;
avlNode *left;
avlNode *right;
int height;
avlNode(const int &x,avlNode *lt,avlNode *rt,int h=0):data(x),left(lt),right(rt),height(h){}
};
avlNode *root;
bool find(int x,avlNode *t){
if(t==NULL)return false;
if(x<t->data)return find(x,t->left);
else if(x>t->data)return find(x,t->right);
else return true;
}
int height(avlNode *t){
return t==NULL?-1:t->height;
}
void LL(avlNode *&t){
avlNode *t1 = t->left;
t->left = t1->right;
t1->right = t;
t->height = max(height(t->left),height(t->right))+1;
t1->height = max(height(t1->left),height(t))+1;
t=t1;
}


void LR(avlNode *&t){
    RR(t->left);
    LL(t);
}


void RR(avlNode *&t){
avlNode *t1 = t->right;
t->right = t1->left;
t1->left = t;
t->height = max(height(t->left),height(t->right))+1;
t1->height = max(height(t),height(t1->right))+1;
t=t1;
}

void RL(avlNode *&t){
LL(t->left);
RR(t);
}
void insert(int x,avlNode *&t){
if(t==NULL)
    t=new avlNode(x,NULL,NULL);
else if(x<t->data){
insert(x,t->left);
if(height(t->left)-height(t->right)==2)
    if(x<t->left->data)LL(t)else LR(t);
}
else if(x>t->data){
    insert(x,t->right);
    if(height(t->right)-height(t->left)==2)
        if(t->right->data<x)RR(t);else RL(t);
}
t->height = max(height(t->left),height(t->height))+1;
}


int main(){


return 0;
}
