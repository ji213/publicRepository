/*
    Linked List Implementation v1.0
    Utilize Recursive functions
*/

#include <iostream>

// Initialize Node Struct
struct Node {
    int contents;
    Node *next;
    Node() : contents(0), next(nullptr) {}
    Node(int x) : contents(x), next(nullptr) {}
    Node(int x, Node *next) : contents(x), next(next) {}
};

// Implement solution class
class Solution {
public:
    Node* mergeTwoLists(Node* list1, Node* list2) {
        //std::cout << "mergeTwoLists function...\n";
        //std::cout << "List1: " << list1->contents;

        //std::cout << "List2: " << list2->contents;


        if(list1 == NULL){
            return list2;
        }
        if(list2 == NULL){
            return list1;
        }

        if(list1->contents <= list2->contents){
            list1->next = mergeTwoLists(list1->next, list2);
            return list1;
        }
        else {
            list2->next = mergeTwoLists(list1, list2 -> next);
            return list2;
        }
        
    }
};

int main(){
    // Init head node
    Node* head = new Node;
    // Init node contents
    head->contents = 100;
    // set head->next to null, meaning there is no node next in the chain
    head->next = nullptr;


    // init tail node
    Node* tail = new Node();
    tail->contents = 200;
    tail->next = nullptr;

    // now we link the head to the tail
    head->next = tail;

    // second node Head
    Node* secondHead = new Node;
    secondHead->contents = 50;
    secondHead->next = nullptr;

    // second node tail
    Node* secondTail = new Node;
    secondTail -> contents = 150;
    secondTail -> next = nullptr;

    // Connect second head to second tail, secondTail is the next node in that list
    secondHead -> next = secondTail;

    Solution s;

    Node* result = new Node();

    // call recursive merge function
    result = s.mergeTwoLists(head, secondHead);

    std::cout << "Result output: \n\n";
    while(result){
        // output results
        std::cout << result->contents << "\n";
        result = result->next;
    }


    //std::cout << "Contents: " << head->contents << "\n" << head->next->contents << "\n";

}