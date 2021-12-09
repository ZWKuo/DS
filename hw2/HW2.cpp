#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <queue>
#include <stack>
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
    Node* get_RC();
    Node();
    Node(int x);
    Node(Node* x);
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
    void level_order();
    void search(int x);
    Node* find();
    void del(int x);
    void insert_mute(Node *x);
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

Node::Node(Node* x){
    data = x->get_data();
    LC = x->get_LC();
    RC = x->get_RC();
    //parent = x->get_parent();
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

Node* Node::get_RC(){
    return RC;
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

void Node::insert_mute(Node *x)
{
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

void Node::level_order(){
    queue<Node*> q;
    Node* ref = this;
    q.push(ref);
    while ( !(q.empty()))
    {
        Node* tmp = q.front();
        q.pop();
        cout<<tmp->get_data()<<" ";
        if(tmp->get_LC() != NULL){
            q.push(tmp->get_LC());
        }
        if (tmp->get_RC() != NULL)
        {
            q.push(tmp->get_RC());
        }   
    }
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

void read_file(Node* head){
    int c = 0;
    string s;
    string filename = "bstmap.txt";
    fstream file(filename);
    if( !file ) 
    {   
        cout << "Error opening " << filename << " for input" << endl;   
        exit(-1);  
    }
    while (getline(file,s))
    {
        Node* tmp = new Node(stoi(s));
        if (c == 0)
        {
            tmp->set_parent(head);
            head->set_LC(tmp);
            c+=1;
        } else{
            head->get_LC()->insert_mute(tmp);
            c+=1;
        }
    }
}


void travel(Node* node , int x , stack<Node> *S){
    if (node->get_data() == x)
    {
        cout<<"CAPO GET THE SWORD !!"<<endl;
        S->push(*node);

    }
    
    if(node->get_data() < x)
     {  
        if(node->get_RC() == NULL){
            cout<<"NO SWORD ! "<<endl;
        }
        else{
            S->push(*node);
            travel(node->get_RC() , x , S);
        }
     }
    if(node->get_data() > x)
     {  
        if(node->get_LC() == NULL){
            cout<<"NO SWORD ! "<<endl;
        }
        else{
            S->push(*node);
            travel(node->get_LC() , x , S);
        }
     }
}

void travel_mute(Node* node , int x , stack<Node> *S){
    if (node->get_data() == x)
    {
        S->push(*node);
    }
    
    if(node->get_data() < x)
     {  
        if(node->get_RC() == NULL){
            cout<<"NO Meaty ! "<<endl;
        }
        else{
            S->push(*node);
            travel_mute(node->get_RC() , x , S);
        }
     }
    if(node->get_data() > x)
     {  
        if(node->get_LC() == NULL){
            cout<<"NO Meaty ! "<<endl;
        }
        else{
            S->push(*node);
            travel_mute(node->get_LC() , x , S);
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
        //Node head;
        //Node Meaty_head;
        int choice;
        cout<<"(1) Binary Searching Tree ."<<endl;
        cout<<"(2) Finnding Meaty ."<<endl;
        cout<<"(0) Escape and face to music next year ."<<endl;
        cin>>choice;
        if (choice == 1)
        {
            Node head;
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
                        cout<<"The tree in level order : ";
                        head.get_LC()->level_order(); cout<<endl;
                    }
                }
                if (Choice == 'R' or Choice == 'r')
                {
                    break;
                }
            }
        }else{
            if (choice == 2)
            {
                Node Meaty_head;
                int sword,Mesty;
                read_file(&Meaty_head);
                cout<<"Load file success . "<<endl;
                cout<<"Please input the sword location : ";
                cin>>sword;
                cout<<"Please input the Mesty location : ";
                cin>>Mesty;
                cout<<"Please input the broccoli traps' index[0~9] : ";
                int tmp;
                while (cin>>tmp)
                    {
                        if(tmp == -1){
                            break;
                        }
                        if (tmp<0 or tmp >9)
                        {
                            cout<<"Out of range , please input the number 0 ~ 9 ! "<<endl;
                            break;
                        }
                        
                        else{
                            Meaty_head.get_LC()->del(tmp);
                            }
                    }
                int cs = 0;
                int cm = 0;
                Node* record_sword = new Node[100];
                Node* record_M = new Node[100];
                stack<Node> S,T;
                travel(Meaty_head.get_LC() , sword , &S);
                travel_mute(Meaty_head.get_LC() ,Mesty , &T);
                Node c_point;
                while (!S.empty())
                {
                    Node tmp(S.top());
                    record_sword[cs] = tmp;
                    cs += 1;
                    S.pop();
                }

                int stop_flag = 1;
                while (!T.empty() and stop_flag)
                {
                    Node tmp(T.top());
                    record_M[cm] = tmp;
                    cm += 1;
                    T.pop();
                    for (int i = 0; i < cm; i++)
                    {
                        if(record_sword[i].get_data() == tmp.get_data()){
                            stop_flag = 0;
                            break;
                        }   
                    }
                }
                cout<<"Shortest path to find the Meaty is : "<<endl;
                for (int i = 0; i < cs; i++)
                {
                    cout<<record_sword[i].get_data()<<" -> ";
                }
                for (int i = cm-2; i >= 1; i--)
                {
                    cout<<record_M[i].get_data()<<" -> ";
                }
                cout<<record_M[0].get_data()<<endl;
                }
            else{
                cout<<"Have a nice day~"<<endl;
                break ;
            }
        }
    }
return 0;
}