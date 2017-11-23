/**
 * Golang test
 *
 *
 * Jun@Shanghai 2017/12/05
 */

package main

import (
	"fmt"
	"sort"
)

func main() {
	words := make(map[int]string)
	words[0] = "Hello world"
	words[1] = "Ni hao"
	words[2] = "....."
	var orders []int

	for order := range words {
		orders = append(orders, order)
	}

	sort.Ints(orders)

	fmt.Println(words)
	for _, which := range orders {
		fmt.Println(which, words[which])
	}
}
