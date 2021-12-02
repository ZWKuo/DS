#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

class Node
{
private:
    int data;
    Node * LC;
    Node * RC;
    Node * parent;

public:
    Node();
    Node(int x);
    ~Node();
    void insert(Node *x);
    void prefix();
    int get_data();
    int get_parent();
    void set(int x);
    void set_parent(Node *x);
    void set_LC(Node* x);
    void set_RC(Node* x);
    void infix();
    void postfix();
    void search(int x);
    Node* find();
    void del(int x);
};

Node::Node()
{ 
    LC = NULL;
    RC = NULL;
    parent = NULL;
}

Node::Node(int x){
    data = x;
    LC = NULL;
    RC = NULL;
    parent = NULL;
}

void Node::set(int x){
    data = x;
    LC = NULL;
    RC = NULL;
    parent = NULL;
}

void Node::set_parent(Node *x){
    this->parent = x;
}

void Node::set_LC(Node *x){
    LC = x;
}

void Node::set_RC(Node *x){
    RC = x;
}

Node::~Node()
{
}

int Node::get_data()
{
    return data;
}

int Node::get_parent()
{
    return parent->get_data();
}

void Node::insert(Node *x)
{
    if (x->get_data() == data)
    {
        cout<< "Number "<< data << "is already exist !" <<endl;
    }
    if (x->get_data() < data)
    {
        if(LC == NULL)
        {
            x->set_parent(this);
            LC = x;
               
        }
        else{
            LC->insert(x);
        }
    }
    if (x->get_data() > data)
    {
        if(RC == NULL)
        {
            x->set_parent(this);
            RC = x;   
        }
        else{
            RC->insert(x);  
        }
    }    
}
void Node::prefix()
{ 
    cout<< data<<" ";
     if(LC != NULL)
     {   
        LC->prefix();
     }
    if(RC != NULL)
    {
        RC->prefix();
    }
}

void Node::infix(){
     if(LC != NULL)
     {   
        LC->infix();
     }
    cout<< data<<" ";
    if(RC != NULL)
    {
        RC->infix();
    }  
}

void Node::postfix(){
     if(LC != NULL)
     {   
        LC->postfix();
     }
    if(RC != NULL)
    {
        RC->postfix();
    }  
    cout<< data<<" " ;
}

void Node::search(int x){
    if (x == data)
    {
        cout<<"Yo~bro~ "<< x <<" is found !"<<endl;
    }
    
    if(x < data)
     {  
        if(LC == NULL){
            cout<<x<<" is not in the tree ! ";
        }
        else{
            LC->search(x);
        }
     }
    if(x > data)
     {  
        if(RC == NULL){
            cout<<x<<" is not in the tree ! ";
        }
        else{
            RC->search(x);
        }
     }
}

Node* Node::find()
{ 
    if (LC != NULL)
    {
        return LC->find();
    }
    else{
        if(RC == NULL){
        return this;
        }
        else{
            Node * tmp = parent;
            tmp->set_parent(RC);
            return this;
        }
    }
}

void Node::del(int x){
    if(data == x){
        if(LC == NULL)
        { 
            if(RC == NULL){
                if(parent->get_data() > x)
                {
                    parent->set_LC(NULL);
                }else{
                    parent->set_RC(NULL);
                }
                //delete this;
                cout<<"Number "<<x<<" is deleted !"<<endl;
            }
            else{ // RC != NULL
                Node *p = RC->find();
                if(parent->get_data()>x)
                {
                    parent->set_LC(p);
                }else{
                    parent->set_RC(p);
                }
                p->set_parent(parent);
                //delete this;
                cout<<"Number "<<x<<" is deleted !"<<endl;
                }
        }
        else{  //LC!=NULL
            if(RC != NULL)
            {
                Node* p = RC->find();
                if(parent->get_data() > x)
                {
                    parent->set_LC(p);
                }else{
                    parent->set_RC(p);
                }
                p->set_parent(parent);
                p->set_LC(LC);
                LC->set_parent(p);
                //delete this;
                cout<<"Number "<<x<<" is deleted !"<<endl;
            }
            else{ //RC == NULL
                LC->set_parent(parent);
                if(parent->get_data() > x)
                {
                    parent->set_LC(LC);
                }else{
                    parent->set_RC(NULL);
                }
                //delete this;
                cout<<"Number "<<x<<" is deleted !"<<endl;
            }
        }
    }
    else
    {
        if(x < data){
            if (LC == NULL)
            {
                cout<<"Number "<<x<<" is not exist !";
            }else{
                LC->del(x);
                }
        }else{
            if(RC == NULL){
                cout<<"Number "<<x<<" is not exist !";
                }else{
                    RC->del(x);
                }
        }
    }
}
    


int main()
{
    Node A,a,b,c,d;
    A.set(100);
    a.set(1);
    b.set(17);
    c.set(160);
    d.set(110);
    A.insert(&a);
    A.insert(&b);
    A.insert(&c);
    A.insert(&d);
    A.prefix();
    cout<<endl;
    A.infix();
    cout<<endl;
    A.postfix();
    cout<<endl;
    A.search(160);
    cout<<endl;
    Node* p = A.find();
    A.del(1);
    A.prefix();

    return 0;
}