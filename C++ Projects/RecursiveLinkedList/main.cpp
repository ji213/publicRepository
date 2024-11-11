/*
    Linked List Implementation v1.2
    Utilize Recursive functions

    -- Added function to swap pairs, however it hasn't passed testing yet so it is not implemented
    -- simplified language to make links easier to understand
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

    Node* swapPairs(Node* head) {

        // This method hasnt passed testing yet
        if(head == NULL || head->next == NULL){
            return head;
        }

        Node* temp = head->next;
        head->next = swapPairs(temp->next);
        temp->next = head;

        return temp;

        
    }
};

int main(){
    // Init head node
    Node* node1 = new Node();
    // Init node contents
    node1->contents = 1;
    // set head->next to null, meaning there is no node next in the chain
    node1->next = nullptr;


    // init tail node
    Node* node2 = new Node();
    node2->contents = 2;
    node2->next = nullptr;

    // now we link the head to the tail

    // second node Head
    Node* node3 = new Node();
    node3->contents = 3;
    node3->next = nullptr;

    // second node tail
    Node* node4 = new Node();
    node4 -> contents = 4;
    node4 -> next = nullptr;

    // Connect second head to second tail, secondTail is the next node in that list
    // secondHead -> next = secondTail;
    // link nodes here
    node1->next = node2;
    node3->next = node4;



    Solution s;

    Node* result = new Node();

    // call recursive merge function
    //result = s.mergeTwoLists(node1, node3);

    /* std::cout << "Input before result function node1: \n\n";
    while(node1){
        //output results
        std::cout << node1->contents << "\n";
        node1 = node1->next;
    }

    std::cout << "Input before result function node3: \n\n";
    while(node3){
        //output results
        std::cout << node3->contents << "\n";
        node3 = node3->next;
    }

    */

    //result = s.swapPairs(node1);
    result = s.mergeTwoLists(node1, node3);

    std::cout << "Result output: \n\n";
    while(result){
        // output results
        std::cout << result->contents << "\n";
        result = result->next;
    }


    //std::cout << "Contents: " << head->contents << "\n" << head->next->contents << "\n";

}