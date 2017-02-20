#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<cstdlib>
using namespace std;

struct node {
int data;
int state;
node(){state=0;}
};
node *array;
int size;

void init(){


}

bool insert(const int x){
int initPos,pos;
initPos = pos = key(x)%size;
do {
    if(array[pos].state!=1){
        array[pos].data = x;
        array[pos].state = 1;
        return true;
    }
    if(array[pos].state==1&&array[pos].data==x){
        return true;
        pos = (pos+1)%size;

    }
}while(pos!=initPos);
return false;
}

bool remove(const int x){
int initpos,pos;
initpos = pos =  key(x)%size;
do {
    if(array[pos].state==0)return false;
    if(array[pos].state == 1&&array[pos].data == x)
    {

        array[pos].state = 2;
        return true;
    }
    pos=(pos+1)%size;

}while(pos!=initpos);
return false;
}

bool find(const int x){
int initpos ,pos;
initpos = pos = key(x)%size;
do{
    if(array[pos].state==0)return false;
    if(array[pos].state==1&&array[pos].data==x)return true;
    pos = (pos+1)%size;

}while(pos!=initpos);
return false;
}

void rehash(){
node *tmp = array;
array = new node[size];
for(int i=0;i<size;i++){
    if(tmp[i].state==1)insert(tmp[i].data);
}
delete [] tmp;
}
int main()
{


    return 0;
}
