/*
 * @Description: leetcode 59 螺旋矩阵II
 * @Author: 天涯过客
 * @Date: 2025-01-20 20:37:40
 */
package main

import (
	"fmt"
)

func generateMatrix(n int) [][]int {
	ans := make([][]int, n)
	for i := 0; i < n; i++ {
		ans[i] = make([]int, n)
	}
	left, right, top, bottom := 0, n-1, 0, n-1
	cur := 1

	for cur <= n*n {
		//上
		for i := left; i <= right; i++ {
			ans[top][i] = cur
			cur++
		}
		top++
		//右
		for i := top; i <= bottom; i++ {
			ans[i][right] = cur
			cur++
		}
		right--
		//下
		for i := right; i >= left; i-- {
			ans[bottom][i] = cur
			cur++
		}
		bottom--
		//左
		for i := bottom; i >= top; i-- {
			ans[i][left] = cur
			cur++
		}
		left++
	}
	return ans
}

func main() {
	ans := generateMatrix(3)
	fmt.Println(ans)
	fmt.Println("hello world")
}
