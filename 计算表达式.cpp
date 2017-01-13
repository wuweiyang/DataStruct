#include<iostream>
using namespace std;

class calc{
enum Type{DATA,ADD,SUB,MULTI,DIV,OPAREN,CPAREN,EOL};

struct node {
Type type;
int data;
node  *lchild,*rchild;
node(Type t,int d=0,node *lc=NULL,node *rc=NULL){
type = t;data = d;lchild = lc;rchild = rc;
}
};
node *root;
node *create(char * &s);
Type getToken(char * &s,int &value);
int result(node *t);
public :
    calc(char *s){root =create(s);}
    int result(){if(root==NULL)return 0;return result(root);}
};

calc::node *calc::create(char *&s){
node *p,*root =NULL;
Type returnType;
int value;
while(*s!='\0'){
    returnType = getToken(s,value);
    switch(returnType){
        case DATA:
        case OPAREN:
        if(returnType==DATA)p= new node(DATA,value);
        else p=create(s);
        if(root==NULL)root = p;
        else if(root->rchild==NULL)root->rchild=p;
        else root->rchild->rchild=p;
        break;
        case CPAREN:
        case EOL:
        case ADD:
        case SUB:
        root = new node(returnType,0,root);
        break;
        case MULTI:
        case DIV:
        if(root->type==DATA||root->type==MULTI||root->type==DIV)
            root=new node(returnType,0,root);
        else root->rchild=new node(returnType,0,root->rchild);
    }
}
return root;
}

calc::Type calc::getToken(char * &s,int &data){
char type;
while(*s==' ')s++;
if(*s>='0'&&*s<='9'){data=data*10+*s-'0';++s;}
return DATA;
if(*s=='\0')return EOL;
type = *s;++s;
switch(type){
case '+':return ADD;
case '-':return SUB;
case '*':return MULTI;
case '/':return DIV;
case '(':return OPAREN;
case ')':return CPAREN;
default: return EOL;
}
}
int calc::result(node *t){
int num1,num2;
if(t->type==DATA)return t->data;
num1 = result(t->lchild);
num2 = result(t->rchild);
switch(t->type){
case ADD:t->data=num1+num2;break;
case SUB:t->data=num1-num2;break;
case MULTI:t->data= num1*num2;break;
case DIV:t->data = num1/num2;break;
}
return t->data;
}
int main()
{
    calc exp("1+0");
    cout<<exp.result()<<endl;
    return 0;
}
