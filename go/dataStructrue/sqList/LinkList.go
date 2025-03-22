/*
 * @Description: 不带头节点链表
 * @Author: 天涯过客
 * @Date: 2025-03-22 21:20:13
 */
package main

import (
	"fmt"
)

// 定义节点
type Node struct {
	data int
	next *Node
}

// 创建节点
func createNode(e int) *Node {
	p := new(Node)
	p.data = e
	p.next = nil
	return p
}

// 打印链表
func printList(head *Node) {
	for head != nil {
		fmt.Println(head.data)
		head = head.next
	}
}

/*
 * @Description: 获取链表长度
 * @param {Node} head
 * @return {int}
 */
func getElem(head *Node, i int) *Node {
	p := head
	if i < 0 {
		return nil
	}
	j := 0
	for p != nil && j < i {
		p = p.next
		j++
	}
	if j == i && p != nil {
		return p
	}
	return nil
}

// 获取元素为e的位置
func locateElem(head *Node, e int) int {
	p := head
	i := 0
	for p != nil {
		if p.data == e {
			return i
		}
		p = p.next
		i++
	}
	return -1
}

// 获取链表长度
func length(head *Node) int {
	p := head
	cnt := 0
	for p != nil {
		cnt++
		p = p.next
	}
	return cnt
}

// 插入元素
func listInsert(head *Node, i int, e int) bool {
	if i < 0 {
		return false
	}
	added := createNode(e)
	if added == nil {
		return false
	}
	p := head
	j := 0
	for p != nil && j < i {
		p = p.next
		j++
	}
	if j == i && p != nil {
		added.next = p.next
		p.next = added
		return true
	}
	return false
}

// 删除元素
func listDelete(head *Node, i int) bool {
	if i < 0 {
		return false
	}
	p := head
	j := 0
	for p != nil && j < i {
		p = p.next
		j++
	}
	if j == i && p != nil {
		p.next = p.next.next
		return true
	}
	return false
}

func listEmpty(head *Node) bool {
	return head == nil
}

func test() {
	head := createNode(1)
	listInsert(head, 0, 2)
	listInsert(head, 1, 3)
	listInsert(head, 2, 4)
	printList(head)
	fmt.Println(length(head))
	listDelete(head, 1)
	printList(head)
	fmt.Println(length(head))
	fmt.Println(locateElem(head, 3))
	fmt.Println(getElem(head, 1).data)
}

func main() {
	test()
}
