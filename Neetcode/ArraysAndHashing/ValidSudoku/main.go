package main

import (
	"unicode"
)

func isValidSudoku(board [][]byte) bool {
	rowBitMap, colBitMap := 0, 0

	for j := range board {
		for i := range board[0] {
			if unicode.IsDigit(rune(board[j][i])) {
				num := int(board[j][i] - '0')
				if rowBitMap&(1<<num) != 0 {
					return false
				} else {
					rowBitMap |= 1 << num
				}
			}
			if unicode.IsDigit(rune(board[i][j])) {
				num := int(board[i][j] - '0')
				if colBitMap&(1<<num) != 0 {
					return false
				} else {
					colBitMap |= 1 << num
				}
			}

		}
		rowBitMap, colBitMap = 0, 0
	}

	squareBitMap := 0

	for cy := 0; cy < len(board); cy += 3 {
		for cx := 0; cx < len(board); cx += 3 {
			for j := range 3 {
				for i := range 3 {
					b := board[cy+j][cx+i]
					if unicode.IsDigit(rune(b)) {
						num := int(b - '0')
						if squareBitMap&(1<<num) != 0 {
							return false
						} else {
							squareBitMap |= 1 << num
						}
					}
				}
			}
			squareBitMap = 0
		}
	}

	return true
}
