class ListNode:
    def __init__(self, key=-1, val = -1, next = None):
        self.key = key
        self.val = val
        self.next = next

class HashMap:

    def __init__(self):
        # initialize list of Nodes, range of 1000
        # if we use a key > 1000, it will be stored as next node for hash key that matches
        # example: key = 1100 ... hash key = 1100 % 1000 = 100
        # so key of 1100 will be stored as next node to key 100
        
        self.map = [ListNode() for i in range(1000)]
    
    def hash(self, key):
        #garuntees we use key of 0 - 999
        #len = 1000 (see above)
        # exmple: hash(key) where key = 1200... return 200
        return key % len(self.map)
        

    def put(self, key: int, value: int) -> None:
        #example: put(1100, 2)
        # set cur = self.map[self.hash(1100)] = self.map[100]
        cur = self.map[self.hash(key)]
        # start while loop to look for next node to cur...
        while cur.next:
            # if cur.next exists
            if cur.next.key == key:
                # if the key of next matches input value key
                #set val of cur.next to input value
                cur.next.val = value
                return
            # traverse to next node
            cur = cur.next
        
        # add new node if we couldnt find node with matching key
        cur.next = ListNode(key, value)
        

    def get(self, key: int) -> int:
        #example : get(1100)
        
        # cur = self.map[self.hash(1100)].next = self.map[100]
        # set cur pointer to next node to cur.
        cur = self.map[self.hash(key)].next
        while cur:
            # while cur exists
            # if cur key matches input key
            if cur.key == key:
                return cur.val
            # if we hit this line, key didnt match, iterate to next node
            cur = cur.next
        return -1

        

    def remove(self, key: int) -> None:
        # example: remove(1100)
        # cur = self.map[self.hash(1100)] = self.map[100]
        cur = self.map[self.hash(key)]
        # while cur pointer and next node exist
        while cur and cur.next:
            # if the next pointer key matches input
            if cur.next.key == key:
                #if true, this is what we remove
                # set cur.next to the next node after
                cur.next = cur.next.next
                # no actual deletion from memory needed, just return
                print("Node successfully removed.\n")
                return
            # traverse list
            cur = cur.next