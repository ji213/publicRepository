/*
    Shopping Cart Application v1.1

    ToDo:
        Add error handling for all user input
        user input validation
        Adding space to itemName string seems to cause infinite glitch loop

*/

#include <iostream>
#include <string>

struct Item {
    std::string name;
    double price;
    int quantity;
    Item* next;
};

class Cart {
    private:
        Item* head;
    
    public:
        Cart() : head(nullptr){}

        // add item to the shopping cart
        void addItem (std::string inputname, double inputprice, int inputquantity){
            // Add Item to Cart
            Item* newItem = new Item;

            // init members
            newItem->name = inputname;
            newItem->price = inputprice;
            newItem->quantity = inputquantity;

            newItem->next = head;
            head = newItem;
        }

        // remove item from cart
        void removeItem(std::string inputname){
            // Init pointer, set current to starting item in cart
            Item* currentptr = head;
            Item* prevptr = nullptr;

            while (currentptr != nullptr){
                if(currentptr->name == inputname){
                    // If the name of current item matches...
                    if(prevptr == nullptr){
                        // if the prevptr is null, then the matching item is the first in the list
                        // set the head to the next item in the list prior to deleting
                        head = currentptr->next;
                    }
                    else{
                        // If prevptr is not null, then it exists
                        // set the next item from prevptr to be the next item to currentptr
                        prevptr->next = currentptr->next;
                    }

                    // delete this item once it is delinked from list
                    delete currentptr;
                    std::cout << "Item " << inputname << " removed!\n\n";
                    return;
                }


                prevptr = currentptr;
                currentptr = currentptr->next;
            }

            //If we reach this block then the item wasnt found
            std::cout << "Item not found! " << std::endl;
        }

        //display cart contents
        void displayCart(){
            Item* currentptr = head;
            double total = 0.0;

            std::cout << "\n\nCart: " << std::endl;
            while (currentptr != nullptr){
                std::cout << "Product: " << currentptr->name;
                std::cout << " Quantity: " << currentptr->quantity;
                std::cout << " Price: " << currentptr->price << std::endl;

                total += currentptr->price * currentptr->quantity;
                currentptr = currentptr->next;

            }

            std::cout << "Total: $ " << total << std::endl;
        }

        //Clear cart
        void clearCart(){
            Item* currentptr = head;
            while(currentptr != nullptr){
                head = currentptr->next;

                delete currentptr;
                currentptr = head;
            }
        }
};


int main(){
    int useroption = 2;

    std::string itemName;
    std::string itemtoremove;
    double itemPrice;
    int itemQuantity;

    Cart userCart;

    std::cout << "SHOPPING CART APPLICATION...\n\n";

    while(useroption > 0){
        std::cout << "\n\nPlease select an action..\n 1. Add item to cart\n 2. Display Cart\n 3. Remove item from cart\n 4. Empty Cart\n Enter 0 to exit \n";

        std::cin >> useroption;
        switch(useroption){
            case 0:
                std::cout << "Exiting cart.... \n";
                break;
            case 1:
                // Add items to cart
                std::cout << "Item: ";
                std::cin >> itemName;
                std::cout << "Price: ";
                std::cin >> itemPrice;
                std::cout << "Quantity: ";
                std::cin >> itemQuantity;

                std::cout << "Adding item to cart...\n";
                userCart.addItem(itemName, itemPrice, itemQuantity);
                break;
            case 2:
                // Display cart
                userCart.displayCart();
                break;
            case 3:
                //Remove item from cart
                std::cout << "What item would you like to remove? ";
                std::cin >> itemtoremove;
                userCart.removeItem(itemtoremove);
                break;
            case 4:
                // Clear Cart
                userCart.clearCart();
                break;
            default:
                std::cout << "Error! Please enter valid input";
                break;
        }

    }
    

    std::cout << "Thank you for participating!\n\n";

}

