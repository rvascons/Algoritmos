#include <iostream>
using namespace std;
class Node{
    private:
        int data;
        int newTime;
        int lastTime;
        class Node* next;
    public:
        int getData();
        int getLast();
        int getNew();
        class Node* getNext();
        void setData(int x);
        void setNewTime(int x);
        void setLastTime(int x);
        void setNext(class Node* x);
};
int Node::getData(){
            return data;
}
int Node::getLast(){
            return lastTime;
}
int Node::getNew(){
            return newTime;
}
class Node* Node::getNext(){
            return next;
}
void Node::setData(int x){
            this->data = x;
}
void Node::setNewTime(int x){
            this->newTime = x;
}
void Node::setLastTime(int x){
            this->lastTime = x;
}
void Node::setNext(class Node* x){
            this->next = x;
}

int main(){
    return 0;
}