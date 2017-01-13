#include<iostream>
#include<queue>
using namespace std;
template <class Type>
class binaryTree {
private:
    struct Node{
    Node *left,*right;
    Type data;
    Node():left(NULL),right(NULL){}
    Node(Type item,Node *L = NULL ,Node *R=NULL):data(item),left(L),right(R){}
    ~Node(){}
    };
    Node *root;
public:
    binaryTree():root(NULL){}//����һ�ſյĶ�����
    binaryTree(const Type &value){root=new Node(value);}
    ~binaryTree(){clear();}
    Type getRoot()const {return root->data;}
    Type getLeft()const {return root->left->data;}
    Type getRight() const {return root->right->data;}

    void makeTree(const Type &x,binaryTree &lt,binaryTree &rt){
    root=new Node(x,lt.root,rt.root);
    lt.root = NULL;
    rt.root = NULL;
    }
    void delLeft(){
    binaryTree tmp = root->left;
    root->left = NULL;
    tmp.clear();
    }
    void delRight(){
    binaryTree tmp=root->right;
    root->right = NULL;
    tmp.clear();
    }
    bool isEmpty()const {
    return root ==NULL;
    }
    void clear(){
    if(root!=NULL)clear(root);root=NULL;
    }
    int size() const {return size(root);}
    int height() const {return height(root);}

    void preOrder()const {
    if(root!=NULL){
        cout<<"\nǰ�����";
        preOrder(root);
    }
    }
    void postOrder() const {
    if(root!=NULL){
    cout<<"\n�������";
    postOrder(root);
    }
    }
    void midOrder()const {
    if(root!=NULL){
        cout<<"\n�������";
        midOrder(root);
    }
    }
    void createTree(Type flag);
private:
    int height(Node *t)const {
    if(t==NULL)return 0;
    else {
        int lt = height(t->left),rt=height(t->right);
        return 1+(lt>rt?lt:rt);
    }
    }
    void clear(Node *t) const{
    if(t->left!=NULL)clear(t->left);
    if(t->right!=NULL)clear(t->right);
    delete t;
    }
    int size(Node *t)const{
    if(t==NULL)return 0;
    return 1+size(t->left)+size(t->right);
    }
    void preOrder(Node *t)const {
    if(t!=NULL){
        cout<<t->data<<" ";
        preOrder(t->left);
        preOrder(t->right);
    }
    }

    void postOrder(Node *t)const {
    if(t!=NULL){
        postOrder(t->left);
        postOrder(t->right);
        cout<<t->data<<" ";
    }
    }
   void midOrder(Node *t)const {
   if(t!=NULL){
    midOrder(t->left);
    cout<<t->data<<" ";
    midOrder(t->right);
   }
   }
};
template <class Type>
void binaryTree<Type>::createTree(Type flag){
queue<Node *>que;
Node *tmp;
Type x,ldata,rdata;
cout<<"\n������ڵ�";
cin>>x;
root=new Node(x);
que.push(root);
while(!que.empty()){
    tmp=que.front();
    que.pop();
    cout<<"\n����"<<tmp->data<<"����������";
    cin>>ldata>>rdata;
    if(ldata!=flag)que.push(tmp->left=new Node(ldata));
    if(rdata!=flag)que.push(tmp->right=new Node(rdata));
}
}

int main(){
binaryTree<char> tree,tree1('M'),tree2;
tree.createTree('@');
cout<<"�߶�:"<<tree.height()<<endl;
cout<<"��ģ:"<<tree.size()<<endl;
tree.preOrder();
tree.midOrder();
tree.postOrder();
tree2.makeTree('Y',tree,tree1);
cout<<endl;
cout<<"�߶�:"<<tree2.height()<<endl;
cout<<"��ģ:"<<tree2.size()<<endl;
tree2.preOrder();
tree2.midOrder();
tree2.postOrder();
return 0;
}




























