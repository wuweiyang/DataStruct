#include<iostream>
#include<cstring>
#include<cstdio>
#include<cstdlib>
using namespace std;
struct BinaryNode{
int data;
BinaryNode *left;
BinaryNode *right;
BinaryNode(const int & x,BinaryNode *lt,BinaryNode *rt):data(x),left(lt),right(rt){}

};

bool find(const int x,BinaryNode *t){
if(t==NULL)return false;
else if(x<t->data)return find(x,t->left);
else if(x>t->data)return find(x,t->right);
else return true;
}

void insert(int x,BinaryNode * &t){
if(t==NULL)
{
    t= new BinaryNode(x,NULL,NULL);
}
else if(x<t->data)
    insert(x,t->left);
else if(t->data<x)
    insert(x,t->right);
}

void remove(int x,BinaryNode *&t){
if(t==NULL)return;
if(x<t->data)remove(x,t->left);
else if(x>t->data)remove(x,t->right);
else if(t->left!=NULL&&t->right!=NULL){
    BinaryNode *tmp = t->right;
    while(tmp->left!=NULL)tmp=tmp->left;
    t->data = tmp->data;
    remove(t->data,t->right);
}
else {
    BinaryNode *oldNode = t;
    t=(t->left!=NULL)?t->left:t->right;
    delete oldNode;
}
}
int main(){
BinaryNode *root = NULL;
int a[] = {10,8,6,21,87,56,4,0,11,3,22,7,5,34,1,2,9};
for(int i=0;i<17;i++)insert(a[i],root);
if(find(2,root))cout<<1<<endl;
 else cout<<0<<endl;
return 0;
}
