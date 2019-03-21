#include <iostream>
using namespace std;

class Node {
    private:
        int data;
        class Node* next;
        class Node* prev;
    public:
        int getData();
        class Node* getNext();
        class Node* getPrev();
        void setData(int x);
        void setNext(class Node* x);
        void setPrev(class Node* x);
};

int Node::getData(){
            return data;
}

class Node* Node::getNext(){
            return next;
}

class Node* Node::getPrev(){
            return prev;
}

void Node::setData(int x){
            this->data = x;
}

void Node::setNext(class Node* x){
            this->next = x;
}

void Node::setPrev(class Node* x){
            this->prev = x;
}

void print(class Node* head){
    class Node* temp = head->getNext();
    while(temp->getNext() != NULL){
        cout << temp->getData() << endl;
        temp = temp->getNext();
    }
}

void init(class Node** head_ref, class Node** last_ref){
    class Node* head = new class Node;
    class Node* last = new class Node;
    
    last->setData(-1);
    last->setNext(NULL);

    head->setData(-1);
    head->setPrev(NULL);
    
    last->setPrev(head);
    head->setNext(last);
    
    *head_ref = head;
    *last_ref = last;
    
}

void addBegin(int x, class Node** head_ref, class Node** last_ref){
    class Node* temp = NULL;
    class Node* aux = (*head_ref)->getNext();
    temp = new class Node;

    temp->setData(x);
    temp->setNext(aux);
    temp->setPrev(*head_ref);

    (*head_ref)->setNext(temp);
    aux->setPrev(temp);
}

void addLast(int x, class Node** head_ref,  class Node** last_ref){
    class Node* temp = NULL;
    class Node* aux = (*last_ref)->getPrev();
    temp = new class Node;
    
    temp->setData(x);
    temp->setNext(*last_ref);
    temp->setPrev(aux);
    
    (*last_ref)->setPrev(temp);
    aux->setNext(temp);
}

int deleteFirst(class Node** head_ref,  class Node** last_ref){
    if((*head_ref)->getNext() != NULL && (*head_ref)->getNext() != (*last_ref)){
        class Node* temp = (*head_ref)->getNext();
        int target = temp->getData();
        if(temp->getNext() != NULL){
        (*head_ref)->setNext(temp->getNext());
        temp->getNext()->setPrev(*head_ref);
        }
        delete(temp);
        temp = NULL;
        return target;
    }
}

int deleteLast(class Node** last_ref, class Node** head_ref){
    if((*last_ref)->getPrev() != NULL && (*last_ref)->getPrev() != (*head_ref)){
        class Node* temp = (*last_ref)->getPrev();
        int target = temp->getData();
        if(temp->getPrev() != NULL){
        (*last_ref)->setPrev(temp->getPrev());
        temp->getPrev()->setNext(*last_ref);
        }
        delete(temp);
        temp = NULL;
        return target;
    }
}



int main(){
    class Node* head = NULL;
    class Node* last = NULL;

    init(&head, &last);
    
    addBegin(5,&head,&last);
    addBegin(4,&head,&last);
    addBegin(3,&head,&last);
    addBegin(2,&head,&last);
    addLast(6, &head,&last);
    addBegin(1,&head,&last);
    addLast(7, &head,&last);
   
    deleteFirst(&head, &last);
    deleteLast( &last, &head);
    
    print(head);
    
    return 0;
}