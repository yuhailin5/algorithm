/*
 * @Description: 字符串相关操作
 * @Author: 天涯过客
 * @Date: 2025-03-26 18:37:30
 */
package main

import (
	"fmt"
	"unicode/utf8"
)

func getNext(s string) []int {
	n := utf8.RuneCountInString(s)
	next := make([]int, n)
	j := 0
	next[0] = j
	for i := 1; i < n; i++ {
		for j > 0 && s[i] != s[j] {
			j = next[j-1]
		}

		if s[i] == s[j] {
			j += 1
		}
		next[i] = j
	}
	return next
}

func getNextval(s string, next []int) []int {
	n := utf8.RuneCountInString(s)
	nextval := make([]int, n)
	i := 0
	for i < n {
		if s[i] == s[next[i]] {
			nextval[i] = next[next[i]]
		} else {
			nextval[i] = next[i]
		}
		i += 1
	}
	return nextval
}

func main() {

	s := "aabaab"
	next := getNext(s)
	nextval := getNextval(s, next)
	n := len(next)
	i := 0
	for i < n {
		fmt.Print(nextval[i], " ")
		i += 1
	}

}
