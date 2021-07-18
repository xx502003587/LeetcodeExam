package main

import "fmt"

func twoSum(nums []int, target int) []int {
	numbers := make(map[int]bool)
	index := make(map[int]int)

	for idx, num := range nums {
		numbers[num] = true
		index[num] = idx
	}

	for idx, num := range nums {
		if numbers[target-num] && index[target-num] != idx {
			return []int{idx, index[target-num]}
		}
	}
	return []int{}
}

func main() {
	fmt.Print(twoSum([]int{2,7,11,15}, 9))
}