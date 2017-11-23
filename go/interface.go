/**
 * Golang test
 *
 *
 * Jun@Shanghai 2017/12/05
 */

package main

import (
	"fmt"
)

type animal interface {
	printInfo()
}

type cat int

func (c cat)printInfo() {
	fmt.Println("This is a cat")
}

func invoke(a animal) {
	a.printInfo()
}

func main() {
	var c cat
	invoke(c)
}
