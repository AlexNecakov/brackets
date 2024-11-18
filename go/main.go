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
	numEntries := float64(len(os.Args[1:]))
	if numEntries <= 0 {
		fmt.Println("no entries provided\n")
		os.Exit(1)
	}
	numRounds := math.Ceil(math.Log2(numEntries))
	numLeaves := math.Ceil(math.Pow(2, numRounds))

	rootNode := createNode(nil)
	current := &rootNode

	currLeaves := 0
	currDepth := 0

    // make the btree
    while currLeaves < numLeaves {
        // leaf
        if currDepth == numRounds {
            if currLeaves < numEntries {
                setNamecurrent, argv[1 + currLeaves]
                printf"set leaf %i name to %s\n", currLeaves, current->name
            }
            currLeaves++
            current->decided = 1
            current = current->parent
            currDepth--
        }
        // too deep
        else if currDepth > numRounds {
            printf"delved too deep. crashing\n"
            return 1
        } else if currDepth < 0 {
            printf"flew too close to the sun. crashing\n"
            return 1
        }
        // non leaf
        else {
            if current->child_left == NULL {
                node *newNode = createNodecurrent
                current->child_left = newNode
                current = newNode
                currDepth++
            } else if current->child_right == NULL {
                node *newNode = createNodecurrent
                current->child_right = newNode
                current = newNode
                currDepth++
            } else {
                current = current->parent
                currDepth--
            }
        }
    }


}
