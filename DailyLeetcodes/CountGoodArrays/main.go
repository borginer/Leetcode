// https://leetcode.com/problems/count-the-number-of-arrays-with-k-matching-adjacent-elements/description/?envType=daily-question&envId=2025-06-17

package main

import (
	"fmt"
	"math/big"
)

const (
	modVal = 1000000007
)

func choose(k, n int64) *big.Int {
	if k < 0 || k > n {
		return big.NewInt(0)
	}

	res := big.NewInt(1)
	for i := int64(0); i < k; i++ {
		res.Mul(res, big.NewInt(n-i))
		res.Div(res, big.NewInt(i+1))
	}
	return res
}

func pow(a, b int) int64 {
	res := int64(1)
	for range b {
		res *= int64(a)
		if res > modVal {
			res %= modVal
		}
	}
	return res
}

func countGoodArrays(n int, m int, k int) int {
	cRes := new(big.Int).Mod(choose(int64(k), int64(n-1)), big.NewInt(modVal))
	c := int64(cRes.Int64())
	res := c * (int64(m) * pow(m-1, n-k-1) % modVal)
	return int(res % modVal)
}

func main() {
	fmt.Println(countGoodArrays(3, 2, 1))
	fmt.Println(countGoodArrays(4, 2, 2))
}
