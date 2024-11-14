# HashMap Implementation v1.0

from my_class import ListNode, HashMap



def main():
    print("HashMap Implementation \n")
    testHash = HashMap()
    option_dict = {1: 'Put', 2: 'Get', 3: 'Remove'}
    option = int(input("\nSelect an option: \n1. Put\n2. Get\n3. Remove\n Enter 0 to exit\n"))
    print("You chose option: ", option)
    
    while True:
        match option:
            case 1:
                # put
                print("Put option selected\n")
                inputkey = int(input("\nEnter key vaue: "))
                inputval = int(input("\nEnter value: "))
                testHash.put(inputkey, inputval)
            case 2:
                # get
                print("Get option selected\n")
                inputkey = int(input("Enter key to obain value from: "))
                result = testHash.get(inputkey)
                if(result == -1):
                    print("No value found")
                else:
                    print("\n Value: ", result)
            case 3:
                #remove
                print("Remove option selected\n")
                inputkey = int(input("Enter key to remove: "))
                testHash.remove(inputkey)
            case _:
                print("Invalid entry... please try again")
                
        option = int(input("\nSelect an option: \n1. Put\n2. Get\n3. Remove\n Enter 0 to exit\n"))
        if(option <= 0):
            break
                
    
    
if __name__ == "__main__":
    main()