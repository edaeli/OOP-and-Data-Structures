#include <iostream>
#include <string>
#include <array>
#include <vector>


struct ListNode {
    int data;
    ListNode* next;
    
    explicit ListNode(int val) : data(val), next(nullptr) {}
};



ForwardList& operator=(const ForwardList &other){
    if(!(other.head)){
        return *this
    }

    while(head){
        Node* tmp = head;
        head = head->next;
        delete tmp;
    }

    head = new Node(other.head->data);
    Node *curr = head;
    Node *othercurr = other.head->next;
    while(othercurr){
        curr->next = new Node(othercurr->data);
    }

int main(){





    return 0;
}
