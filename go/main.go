package main

import (
	"fmt"
	"math"
	"os"
)

type node struct {
	decided     bool
	name        string
	parent      *node
	child_left  *node
	child_right *node
}

func createNode(parent *node) node {
	if parent == nil {
		newNode := node{decided: false, name: ""}
		return newNode
	} else {
		newNode := node{decided: false, name: "", parent: parent}
		return newNode
	}
}

func main() {
	numEntries := len(os.Args[1:])
	if numEntries <= 0 {
		fmt.Println("no entries provided")
		os.Exit(1)
	}
	numRounds := int(math.Ceil(math.Log2(float64(numEntries))))
	numLeaves := int(math.Ceil(math.Pow(2, float64(numRounds))))

	rootNode := createNode(nil)
	current := &rootNode

	currLeaves := 0
	currDepth := 0

	// make the btree
	for currLeaves < numLeaves {
		// leaf
		if currDepth == numRounds {
			if currLeaves < numEntries {
				current.name = string(os.Args[1+currLeaves])
				fmt.Printf("set leaf %d name to %s\n", currLeaves, current.name)
			}
			currLeaves++
			current.decided = true
			current = current.parent
			currDepth--
		} else if currDepth > numRounds {
			fmt.Println("delved too deep. crashing")
			os.Exit(1)
		} else if currDepth < 0 {
			fmt.Println("flew too close to the sun. crashing")
			os.Exit(1)
		} else {
			if current.child_left == nil {
				newNode := createNode(current)
				current.child_left = &newNode
				current = &newNode
				currDepth++
			} else if current.child_right == nil {
				newNode := createNode(current)
				current.child_right = &newNode
				current = &newNode
				currDepth++
			} else {
				current = current.parent
				currDepth--
			}
		}
	}

}
