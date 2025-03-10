import math
import sys

class Node:
    def __init__(self, parent):
        self.parent = parent
        self.child_left = None
        self.child_right = None
        self.name = ""
        self.decided = False

def main():
    numEntries = len(sys.argv) - 1
    if numEntries <= 0:
        print("no entries provided\n")
        return 1
    numRounds = math.ceil(math.log2(numEntries))
    numLeaves = math.ceil(math.pow(2, numRounds))

    root = Node(None)
    current = root

    currLeaves = 0
    currDepth = 0

    while currLeaves < numLeaves:
        if currDepth == numRounds:
            if currLeaves < numEntries:
                current.name = sys.argv[1+currLeaves]
                print(f"set leaf {currLeaves} name to {current.name}\n")
            currLeaves+=1
            current.decided = True
            current = current.parent
            currDepth-=1
        elif currDepth > numRounds:
            print("delved too deep. crashing\n")
            return 1
        elif currDepth < 0:
            print("flew too close to the sun. crashing\n")
            return 1
        else:
            if current.child_left == None:
                newNode = Node(current)
                current.child_left = newNode
                current = newNode
                currDepth+=1
            elif current.child_right == None:
                newNode = Node(current)
                current.child_right = newNode
                current = newNode
                currDepth+=1
            else:
                current = current.parent
                currDepth-=1

    current = root
    while root.decided == False:
        if current.child_left.decided == False:
            current = current.child_left
        elif current.child_right.decided == False:
            current = current.child_right
        else:
            choice = ""
            while choice != 'a' and choice != 'b':
                choice = input(f"A {current.child_left.name} vs B {current.child_right.name}\n")
            if choice == 'a':
                current.name = current.child_left.name
            elif choice == 'b':
                current.name = current.child_right.name
            current.decided = True
            print(f"round winner: {current.name}")
            current = current.parent
    
    print(f"grand winner {root.name}")

    return 0

if __name__ == "__main__":
    sys.exit(main())
