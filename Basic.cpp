#include <iostream>
using namespace std;

class Node {
    private:
        int data;
        class Node* next;
    public:
        int getData();
        class Node* getNext();
        void setData(int x);
        void setNext(class Node* x);
};

int Node::getData(){
            return data;
}

class Node* Node::getNext(){
            return next;
}

void Node::setData(int x){
            this->data = x;
}

void Node::setNext(class Node* x){
            this->next = x;
}

void print(class Node* head){ 
    while(head != NULL){
        cout << head->getData() << endl;
        head = head->getNext();
    }
}

void addBegin(int x, class Node** head_ref){
    class Node* temp = NULL;
    temp = new class Node;

    temp->setData(x);
    temp->setNext(*head_ref);

    *head_ref = temp;
}

void addLast(int x, class Node** head_ref){
    class Node* new_node = new class Node;
    class Node* last = *head_ref;

    new_node->setData(x);
    new_node->setNext(NULL);

    if(*head_ref == NULL){
        *head_ref = new_node;
        return;
    }

    while(last->getNext() != NULL){
        last = last->getNext();
    }

    last->setNext(new_node);
    return;
}

void addAfterNode(int x, class Node** head_ref){
    if(*head_ref == NULL){
        cout << "Error : The given node can't be NULL." << endl;
        return;
    }
    class Node* new_node = new class Node;

    new_node->setData(x);
    new_node->setNext((*head_ref)->getNext());
    (*head_ref)->setNext(new_node);
}

void deleteKey(int target, class Node** head_ref){
    class Node* temp = *head_ref, *prev;
    if(temp != NULL && temp->getData() == target){
        *head_ref = temp->getNext();
        delete(temp);
        return;
    }
    while(temp->getData() != target){
        prev = temp;
        temp = temp->getNext();
        if( temp == NULL)
            return;
    }
    prev->setNext(temp->getNext());
    delete(temp);

    return;
}

int deletePos(int pos, class Node** head_ref){
    class Node* temp = *head_ref;
    class Node* prev;
    int target;
    if(pos == 0){
        target = temp->getData();
        temp = temp->getNext();
        *head_ref = temp;
        return target;
    }
    for(int i = 0; i != pos; i++){
        if(temp == NULL){
            cout << "The list don't reach this position" << endl;
            cout << "Returning 0" << endl;
            return 0;
        }
        prev = temp;
        temp = temp->getNext();
    }
    target = temp->getData();
    prev->setNext(temp->getNext());
    //delete(temp);
    
    return target;
}

int deleteLast(class Node** head_ref){
    class Node* temp = *head_ref;
    class Node* prev; 
    int target;
    while(temp->getNext() != NULL){
        prev = temp;
        temp = temp->getNext();
    }
    target = temp->getData();
    prev->setNext(NULL);
    //delete(temp);
    //temp = NULL;
    return target;
}

int deleteFirst(class Node** head_ref){
    class Node* temp = (*head_ref)->getNext();
    int target = (*head_ref)->getData();
    *head_ref = temp;
    delete(temp);
    return target;
}

int top(class Node* head_ref){
    class Node * temp = head_ref;
    int target;
    if(temp == NULL){
        cout << "Empty." << endl;
    }
    while(temp->getNext() != NULL){
        temp = temp->getNext();
    }
    target = temp->getData();
    //delete(temp);
    return target;
}

int main(){
    class Node* head = NULL;

    addBegin(5, &head);
    addLast(1, &head);
    addLast(2, &head);
    addLast(3, &head);
    addLast(4, &head);

    cout << "Oque esta no topo eh : " << top(head) << endl;

    print(head);

    cout << "O numero que estava na posicao zero era " << deleteFirst(&head) << endl;

    cout << "O numero que estava na ultima posicao era " << deleteLast(&head) << endl;
    
    print(head);
    
    deleteKey(2, &head);
    
    cout << "O numero 2 foi deletado" << endl;

    print(head);
    return 0;
}