package main

import "fmt"

func main() {
	var i int
	var n int
	fmt.Scan(&n)
	v := make([]int, n+1)
	v[1] = 1
	//fmt.Println(v)
	for i = 1; i < n; i++ {
		v[i+1] = (v[i]) + (v[i-1])
		fmt.Print(v[i], " ")
	}
}
