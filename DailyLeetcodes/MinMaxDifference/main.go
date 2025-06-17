package main

import (
	"fmt"
)

func minMaxDifference(num int) int {
	var digits []int
	for num > 0 {
		digits = append(digits, num%10)
		num /= 10
	}
	minReplace, maxReplace := -1, -1
	for i := len(digits) - 1; i >= 0; i-- {
		if digits[i] != 9 && maxReplace == -1 {
			maxReplace = digits[i]
		}
		if digits[i] != 0 && minReplace == -1 {
			minReplace = digits[i]
		}
	}
	minVal, maxVal := 0, 0
	mul := 1
	for _, dig := range digits {
		if dig != minReplace {
			minVal += mul * dig
		}
		if dig != maxReplace {
			maxVal += mul * dig
		} else {
			maxVal += mul * 9
		}
		mul *= 10
	}
	return maxVal - minVal
}

func main() {
	fmt.Println(minMaxDifference(11891))
}
