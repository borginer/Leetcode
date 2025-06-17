package main

import (
	"fmt"
	"sort"
)

func absDiff(a, b int) int {
	return max(a, b) - min(a, b)
}

func minimizeMax(nums []int, p int) int {
	sort.Ints(nums)
	left, right := 0, nums[len(nums)-1]-nums[0]
	for left < right {
		mid, pairs := left+(right-left)/2, 0
		for i := 1; i < len(nums); i++ {
			if mid >= nums[i]-nums[i-1] {
				pairs++
				i++
			}
		}
		if pairs >= p {
			right = mid
		} else {
			left = mid + 1
		}
	}
	return left
}

func main() {
	nums := []int{3, 3, 5, 1, 0, 5, 6, 6}
	fmt.Println(minimizeMax(nums, 4))
}
