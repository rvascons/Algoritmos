#include <iostream>

using namespace std;

class treeNode{
    private:
        int data;
        class treeNode* right;
        class treeNode* left;
    public:
        int getData();
        class treeNode* getRight();
        class treeNode* getLeft();
        void setData(int x);
        void setRight(class treeNode* x);
        void setLeft(class treeNode* x);
};

int treeNode::getData(){
    return data;
}

class treeNode* treeNode::getRight(){
    return right;
}

class treeNode* treeNode::getLeft(){
    return left;
}

void treeNode::setData(int x){
            data = x;
}

void treeNode::setRight(class treeNode* x){
            this->right = x;
}

void treeNode::setLeft(class treeNode* x){
            this->left = x;
}

void insert(class treeNode** root_ref, int x){
    class treeNode* new_node = new class treeNode;
    new_node->setData(x);
    new_node->setLeft(NULL);
    new_node->setRight(NULL);
    
    if(*root_ref == NULL){
        *root_ref = new_node;
        return;
    }else{
        class treeNode* temp = *root_ref;
        while(1){
            if( x < temp->getData()){
                if(temp->getLeft() == NULL){
                    temp->setLeft(new_node);
                    return;
                }
                temp = temp->getLeft();
            }else{
                if(temp->getRight() == NULL){
                    temp->setRight(new_node);
                    return;
                }
                temp = temp->getRight();
            }
        }
    }
}

void printPre(class treeNode* root_ref){
    if(root_ref == NULL)
        return;
    
    cout << root_ref->getData() << endl;
    printPre(root_ref->getLeft());
    printPre(root_ref->getRight());
}

void printIn(class treeNode* root_ref){
    if(root_ref == NULL)
        return;
        
    printIn(root_ref->getLeft());
    cout << root_ref->getData() << endl;
    printIn(root_ref->getRight());
}

void printPos(class treeNode* root_ref){
    if(root_ref == NULL)
        return;
        
    printPos(root_ref->getLeft());
    printPos(root_ref->getRight());
    cout << root_ref->getData() << endl;
}

int main(){
    class treeNode* root= NULL;

    return 0;
}