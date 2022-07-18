package main

import "fmt"

func OrderVector(v [10]int) {
	var i, j, aux int
	for i = 0; i < 10; i++ {
		for j = 0; j < 10; j++ {
			if v[i] > v[j] {
				aux = v[j]
				v[j] = v[i]
				v[i] = aux
			}
		}
	}
}

func main() {
	var (
		vector [10]int
		i      int
	)
	for i = 0; i < 10; i++ {
		fmt.Scan(&vector[i])
	}
	var j, aux int
	for i = 0; i < 10; i++ {
		for j = 9; j > i; j-- {
			if vector[i] > vector[j] {
				aux = vector[j]
				vector[j] = vector[i]
				vector[i] = aux
			}
		}
	}
	fmt.Printf("\nOrdened Vector:\n")
	for i = 0; i < 10; i++ {
		fmt.Printf("%d ", vector[i])
	}
}
