#include <iostream>
using namespace std;

class Node{
    private:
        int data;
        class Node *next;
        
    public:
        void set_data(int key);
        void set_next(class Node* new_node);
        
        int get_data();
        class Node* get_next();
        
        void insert_front(class Node** head, int new_data);
        void insert_after(class Node** head, int new_data, int after);
        void insert_last(class Node** head, int new_data);
        int delete_key(class Node** head, int target);
        
        void print(class Node** head);
};

void Node::set_data(int key){
    this->data = key;
}

void Node::set_next(class Node* new_node){
    this->next = new_node;
}

int Node::get_data(){
    return this->data;
}

class Node* Node::get_next(){
    return this->next;
}

void Node::insert_front(class Node** head, int new_data){
    class Node* new_node = new class Node;

    if(*head == NULL){
        cout << "Starting new list." << endl;
        new_node->set_data(new_data);
        new_node->set_next(*head);
    }else{
        cout << "Adding at the beginnig." << endl;
        new_node->set_data(new_data);
        new_node->set_next(*head);
    }
    
    *head = new_node;
}

void Node::insert_after(class Node** head, int new_data, int after){
    class Node* new_node = new class Node;
    class Node* temp = *head;
    
    while(temp != NULL && temp->get_data() != after){
        temp = temp->get_next();
        if(temp == NULL){
            cout << "Key was not found" << endl;
            return;
        }
    }
    cout << "Adding at after " << after << endl;
    new_node->set_data(new_data);
    new_node->set_next(temp->get_next());
    temp->set_next(new_node);

}

void Node::insert_last(class Node** head, int new_data){
    class Node* new_node = new class Node;

    if(*head == NULL){
        cout << "Starting new list." << endl;
        new_node->set_data(new_data);
        new_node->set_next(NULL);
        *head = new_node;
        return;
    }
    
    class Node* temp = *head;
    cout << "Adding at the end." << endl;
    while(temp->get_next() != NULL){
        temp = temp->get_next();
    }
    
    temp->set_next(new_node);
    new_node->set_data(new_data);
    new_node->set_next(NULL);
}

int Node::delete_key(class Node** head, int target){
    class Node* aux = *head;
    class Node* temp;
    int count = 0; 
    if((*head)->get_data() == target){
        *head = (*head)->get_next();
        cout << "The key was at the beginning" << endl;
        return 0;
    }
    while(aux->get_data() != target){
        temp = aux;
        aux = aux->get_next();
    }
    
    
}

void Node::print(class Node** head){
    
    if(*head == NULL){
        cout << "Empty list" << endl;
        return;
    }
    
    class Node* temp = *head;
    
    while(temp != NULL){
    cout << temp->get_data() << endl;
    temp = temp->get_next();
    }
}

int main(){
    class Node* head = new class Node;
    head = NULL;
 
    head->insert_front(&head, 5);
    head->insert_last(&head, 4);
    head->insert_front(&head, 3);
    head->insert_last(&head, 2);
    head->insert_front(&head, 1);
    
    head->print(&head);
    return 0;
}
https://thinkmobiles.com/blog/best-ar-sdk-review/
https://thinkmobiles.com/blog/best-vr-sdk/