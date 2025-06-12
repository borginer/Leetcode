package main

import "fmt"

func abs(n int) int {
	if n < 0 {
		return -n
	}
	return n
}

func maxAdjacentDistance(nums []int) int {
	maxDist := abs(nums[0] - nums[len(nums)-1])
	for i := 1; i < len(nums); i++ {
		dist := abs(nums[i] - nums[i-1])
		if dist > maxDist {
			maxDist = dist
		}
	}
	return maxDist
}

func main() {
	fmt.Println(maxAdjacentDistance([]int{1, 2, 4}))
	fmt.Println(maxAdjacentDistance([]int{-5, -10, -5}))
}
