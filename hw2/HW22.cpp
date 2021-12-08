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
    while (flag_menu)
    {
        Node head;
        int choice;
        cout<<"(1) Binary Searching Tree ."<<endl;
        cout<<"(2) Finnding Meaty ."<<endl;
        cout<<"(0) Escape and face to music next year ."<<endl;
        cin>>choice;
        if (choice == 1)
        {
            while (flag_menu2)
            {
                char Choice;
                cout<<"(I)nsert a number. "<<endl;
                cout<<"(D)elete a number. "<<endl;
                cout<<"(S)earch a number. "<<endl;
                cout<<"(P)rint 4 kind of orders. "<<endl;
                cout<<"(R)eturn . "<<endl;
                cin>>Choice;
                if ( (Choice == 'i') or (Choice == 'I'))
                {
                    int tmp;
                    cout<<"Enter numbers: ";
                    while (cin>>tmp)
                    {
                        if (tmp == -1)
                        {
                            break;
                        }else{
                            key_point += 1;
                            if (flag_tree == 0)
                            {
                                Node* tmp_node = new Node(tmp);
                                tmp_node->set_parent(&head);
                                head.set_LC(tmp_node);
                                flag_tree = 1;
                                cout<<"Number "<<tmp<<" is insert !";
                                continue;
                            }else{
                                Node* tmp_node = new Node(tmp);
                                head.get_LC()->insert(tmp_node);
                            }
                        }
                    }   
                }
                if( (Choice == 'D') or (Choice == 'd'))
                {
                    int tmp;
                    cout<<"Enter numbers: ";
                    while (cin>>tmp)
                    {
                        if (tmp == -1)
                        {
                            break;
                        }else{
                            if (flag_tree == 0)
                            {
                                cout<<"There is not tree in the system !"<<endl;
                            }else{
                                head.get_LC()->del(tmp);
                                key_point -= 1;
                                if( key_point == 0){
                                    flag_tree = 0;
                                }
                            }
                        }
                    } 
                }
                if( (Choice == 'S') or (Choice == 's'))
                {
                    int tmp;
                    cout<<"Enter numbers: ";
                    while (cin>>tmp)
                    {
                        if (tmp == -1)
                        {
                            break;
                        }else{
                            if (flag_tree == 0)
                            {
                                cout<<"There is not tree in the system !"<<endl;
                            }else{
                                head.get_LC()->search(tmp);
                            }
                        }
                    } 
                }
                if( (Choice == 'P') or (Choice == 'p'))
                {
                    if(flag_tree == 0){
                        cout<<"There is not tree in the system !"<<endl;
                    }else{
                        cout<<"The tree in prefix order : ";
                        head.get_LC()->prefix(); cout<<endl;
                        cout<<"The tree in infix order : ";
                        head.get_LC()->infix(); cout<<endl;
                        cout<<"The tree in postfix order : ";
                        head.get_LC()->postfix(); cout<<endl;
                    }
                }

                
                


            }
        }
        else{
            if (choice == 2)
            {
                /* code */
            }else{
                flag_menu = 0 ;
            }
        }
        
    }
    


    return 0;
}