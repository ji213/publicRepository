/*
    Singly Linked List v1.0
    Program to visualize linked lists
    
*/

#include<iostream>

class Node{
    public:
        int key;
        int data;
        Node* next;

        Node(){
            key = 0;
            data = 0;
            next = NULL;
        }

        Node(int k, int d){
            key = k;
            data = d;
        }
};

class SinglyLinkedList{
    public:
        Node* head;

        SinglyLinkedList(){
            head=NULL;
        }
        SinglyLinkedList(Node *n){
            head = n;
        }

        // Check if a node exists

        Node* nodeExists(int k){
            Node* temp = NULL;

            Node* ptr = head;

            while(ptr != NULL){
                if(ptr->key==k){
                    temp=ptr;
                }
                ptr= ptr-> next;
            }

            return temp;
        }

        // Append a node to the list

        void appendNode(Node *n){
            if(nodeExists(n->key) !=NULL){
                std::cout << "Node already exists with key value : " << n->key <<". Append another node with a different key value\n";
            }
            else{
                if(head==NULL){
                    head = n;
                    std::cout << "Node Appended\n";
                }
                else{
                    Node* ptr = head;
                    while(ptr->next!=NULL){
                        ptr = ptr->next;
                    }

                    ptr->next = n;
                    std::cout << "Node Appended\n";
                }
            }

        }

        // Prepend Node - Attach a node at the start
        void prependNode(Node* n){
            if(nodeExists(n->key)!=NULL){
                std::cout << "Node Already Exists with key value : " << n->key << ". Append anotger node with different key value\n";

            }
            else{
                n->next=head;
                head=n;
                std::cout << "Node prepended\n";
            }
        }

        // Insert a node after a particular node in the list
        void insertNodeAfter(int k, Node *n){
            Node* ptr = nodeExists(k);
            if(ptr==NULL){
                std::cout << "No node exists with key value: " << k << "\n";
            }
            else{
                if(nodeExists(n->key)!= NULL){
                    std::cout << "Node already exists with key value : " << n->key <<". Append another node with different Key value\n";
                }
                else {
                    n->next = ptr->next;
                    ptr->next = n;
                    std::cout << "Node inserted\n";                  
                }
            }
        }

        //Delete node by unique key
        void deleteNodeByKey(int k){
            if(head==NULL){
                std::cout << "Single linked list already empty, cant delete\n";
            }
            else if (head != NULL){
                if(head->key==k){
                    head = head->next;
                    std::cout << "Node UNLINKED with keys value : " << k << "\n";
                }
                else {
                    Node* temp = NULL;
                    Node* prevptr = head;
                    Node* currentptr = head->next;
                    while(currentptr!=NULL){
                        if(currentptr->key==k){
                            temp = currentptr;
                            currentptr = NULL;
                        }
                        else{
                            prevptr = prevptr->next;
                            currentptr = currentptr->next;
                        }
                    }
                    if(temp!=NULL){
                        prevptr->next = temp->next;
                        std::cout<< "Node unlinked with keys value :  " <<k<<"\n";
                    }
                    else{
                        std::cout << "Node doesn't exist with key value : " << k << "\n";
                    }
                }
            }
        }

        void updateNodebyKey(int k, int d){
            Node* ptr = nodeExists(k);
            if(ptr!=NULL){
                ptr->data=d;
                std::cout << "Node data updated successfully\n";
            }
            else{
                std::cout << "Node doesnt exist with key value: " << k << "\n";
            }
        }

        void printList(){
            if(head==NULL){
                std::cout << "No nodes in Singly linked list";
            }
            else{
                std::cout << "\n" << "Linked list values: ";
                Node* temp = head;

                while(temp != NULL){
                    std::cout << "(" << temp->key << "," << temp->data << ") --> ";
                    temp = temp->next;
                }
            }
        }

};




int main(){
    SinglyLinkedList s;
    int option;
    int key1, k1, data1;
    do{
        std::cout << "\nWhat operation do you want to perform? Select corresponding number, or enter 0 to exit \n";
        std::cout << "1. appendNode()\n";
        std::cout << "2. prependNode()\n";
        std::cout << "3. insertNodeAfter()\n";
        std::cout << "4. deleteNodebyKey()\n";
        std::cout << "5. updateNodeByKey()\n";
        std::cout << "6. print()\n";
        std::cout << "7. Clear screen\n\n";

        std::cin >> option;
        Node* n1 = new Node();

        switch(option){
            case 0:
                break;
            case 1:
                std::cout << "Append node operation \nEnter key and data of the node to be appended\n";
                std::cin >> key1;
                std::cin >> data1;
                n1->key=key1;
                n1->data = data1;
                s.appendNode(n1);
                //cout<<n1.key<<" =" <<n1.data << "\n";
                break;
            case 2:
                std::cout << "Prepend node operation \nEnter key & data of the node to be prepended\n";
                std::cin >> key1;
                std::cin >> data1;
                n1->key = key1;
                n1->data = data1;
                s.prependNode(n1);
                break;
            case 3:
                std::cout << "Insert node after operation \n Enter key of existing node after which you ant to insert this new node: \n";
                std::cin >> k1;
                std::cout << "Enter key and data of the new node first: \n";
                std::cin >> key1;
                std::cin >> data1;
                n1->key = key1;
                n1->data = data1;

                s.insertNodeAfter(k1, n1);
                break;
            case 4: 
                std::cout << "Delete node by key operation - \nEnter key of the node to be deleted: \n";
                std::cin >> k1;
                s.deleteNodeByKey(k1);
                break;
            case 5:
                std::cout << "Update node by key operation - \nEnter key and new data to be updated: \n";
                std::cin >> key1;
                std::cin >> data1;
                s.updateNodebyKey(key1, data1);

                break;
            case 6:
                s.printList();

                break;
            case 7:
                system("cls");
                break;
            default:
                std::cout << "Enter correct option number please : \n";
        }

    }while(option != 0);


    return 0;
}