'''
Description: 
Author: 天涯过客
Date: 2025-02-08 01:55:57
'''
import threading


turn = 0

flag = [False, False]

def thread01():
    global turn
    global flag
    flag[0] = True
    turn = 1
    while flag[1] and turn == 1:
        print("thread02占用资源")
    print("thread01使用资源中")
    flag[0] = False

def thread02():
    global turn
    global flag
    flag[1] = True
    turn = 0
    while flag[0] and turn == 0:
        print("thread01占用资源")
    print("thread02使用资源中")
    flag[1] = False


# peterson 算法测试
def main():
    t1 = threading.Thread(target=thread01)
    t2 = threading.Thread(target=thread02)
    t1.start()
    t2.start()
    t1.join()
    t2.join()

if __name__ == '__main__':
    main()