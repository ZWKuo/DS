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
    int flag;

public:
    void set_flag(int x);
    Node* get_LC();
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
    flag = 0;
}

Node::Node(int x){
    data = x;
    LC = NULL;
    RC = NULL;
    parent = NULL;
    flag = 0;
}

void Node::set_flag(int x){
    flag = x;
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

Node* Node::get_LC(){
    return LC;
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
        cout<< "Number "<< data << " is already exist !" <<endl;
    }
    if (x->get_data() < data)
    {
        if(LC == NULL)
        {
            x->set_parent(this);
            LC = x;
            cout<<"Number "<<x->get_data()<<" is insert !"<<endl;
               
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
            cout<<"Number "<<x->get_data()<<" is insert !"<<endl;
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
            cout<<x<<" is not in the tree ! "<<endl;
        }
        else{
            LC->search(x);
        }
     }
    if(x > data)
     {  
        if(RC == NULL){
            cout<<x<<" is not in the tree ! "<<endl;
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
            if(this->get_data() > parent->get_data()){
            Node * tmp = parent;
            tmp->set_RC(RC); // set_parent(RC)
            return this;
            }else{
                 Node * tmp = parent;
                tmp->set_LC(RC); // set_parent(RC)
                return this;
            }
        }
    }
}

void Node::del(int x){
    if(data == x){
        if(LC == NULL)
        { 
            if(RC == NULL){
                if(flag == 0){
                    if(parent->get_data() > x)
                    {
                        parent->set_LC(NULL);
                    }else{
                        parent->set_RC(NULL);
                    }
                }else{
                    parent->set_LC(NULL);
                }
                //delete this;
                cout<<"Number "<<x<<" is deleted !"<<endl;
                
                
            }
            else{ // RC != NULL
                Node *p = RC->find();
                if(flag == 0 ){
                    if(parent->get_data()>x)
                    {
                        parent->set_LC(p);
                    }else{
                        parent->set_RC(p);
                    }
                }else{
                    parent->set_LC(p);
                    p->set_flag(1);
                }
                p->set_parent(parent);
                p->set_LC(LC);
                p->set_RC(RC);
                RC->set_parent(p);
                
                
                
                cout<<"Number "<<x<<" is deleted !"<<endl;
            }

                
        }
        else{  //LC!=NULL
            if(RC != NULL)
            {
                Node* p = RC->find();
                if(flag == 0){
                    if(parent->get_data() > x)
                    {
                        parent->set_LC(p);
                    }else{
                        parent->set_RC(p);
                    }
                }else{
                    parent->set_LC(p);
                    p->set_flag(1);
                }
                p->set_parent(parent);
                p->set_LC(LC);
                p->set_RC(RC);
                RC->set_parent(p);
                LC->set_parent(p);
                //delete this;
                
                cout<<"Number "<<x<<" is deleted !"<<endl;
            }
            else{ //RC == NULL
                LC->set_parent(parent);
                if(flag == 0){
                    if(parent->get_data() > x)
                    {
                        parent->set_LC(LC);
                    }else{
                        parent->set_RC(LC);
                    }
                }else{
                    parent->set_LC(LC);
                }
                
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
    
int flag_menu = 1 ;
int flag_menu2 = 1 ;
int flag_tree = 0 ;
int key_point = 0;
int main()
{

    Node head;
    Node a(5);
    a.set_flag(1);
    a.set_parent(&head);
    Node b(3);
    Node c(4);
    Node d(7);
    Node e(10);
    Node f(9);
    Node g(8);
    Node h(2);

    
    head.set_LC(&a);
    a.insert(&b);
    a.insert(&c);
    a.insert(&d);
    a.insert(&e);
    a.insert(&f);
    a.insert(&g);
    a.insert(&h);


    head.get_LC()->prefix();
    head.get_LC()->del(5);
    head.get_LC()->prefix();
    return 0;
}