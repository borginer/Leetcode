package main

import "fmt"

func productExceptSelf(nums []int) []int {
	prefixProd := make([]int, len(nums))
	suffixProd := make([]int, len(nums))

	prefixProd[0] = 1
	for i := 1; i < len(nums); i++ {
		prefixProd[i] = prefixProd[i-1] * nums[i-1]
	}

	suffixProd[len(nums)-1] = 1
	for i := len(nums) - 2; i >= 0; i-- {
		suffixProd[i] = suffixProd[i+1] * nums[i+1]
	}

	ret := make([]int, len(nums))
	for i := range nums {
		ret[i] = suffixProd[i] * prefixProd[i]
	}

	return ret
}

func main() {
	fmt.Println(productExceptSelf([]int{1, 2, 3, 4}))
}
