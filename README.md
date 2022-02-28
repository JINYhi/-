
# __자료구조 스터디 시뮬레이터 구현__

2주 - 8주간 스터디를 하면서 구현해 봤던 시뮬레이터를 한번에 모아서 구현해보았습니다.

## 1. 시뮬레이터 조건

### 1. 콘솔 창에서 메뉴 선택하기
![image](https://user-images.githubusercontent.com/96537605/155952115-5ea636b9-46b3-4d3d-a66a-121adb52e456.png)

- 사진의 보기와 같이 메뉴에 나와있는 **번호를 입력**하면 그 번호에 대한 시뮬레이터가 실행됩니다.



### 2. 분할 컴파일 활용
![image](https://user-images.githubusercontent.com/96537605/155952952-59ed5575-68ed-49fa-99f0-9d9cc855a7d7.png)
![image](https://user-images.githubusercontent.com/96537605/155952973-9edde369-a833-4929-ad1a-345573f2bb68.png)
![image](https://user-images.githubusercontent.com/96537605/155952986-8061f385-dcd6-4bb7-ac6e-566e2fec2971.png)
![image](https://user-images.githubusercontent.com/96537605/155953001-7060392a-ad46-47e1-9a03-2bc7f5d40098.png)

- 사진과 같이 분할 컴파일을 활용했습니다. Main함수를 포함하여 총 **33개의 파일이 사용**되었습니다.


### 3. Makefile 생성 및 사용
```
CC = gcc


LinkedList : LinkedList.o LinkedListMain.o
	$(CC) -o $@ $^
	./LinkedList

Stack : ListBaseStack.o ListBaseStackMain.o
	$(CC) -o $@ $^
	./Stack

Queue : ListBaseQueue.o ListBaseQueueMain.o
	$(CC) -o $@ $^
	./Queue

PriorityQueue : PriorityQueue.o UsefulHeap.o PriorityQueueMain.o
	$(CC) -o $@ $^
	./PriorityQueue

Sorting : SortingMain.o
	$(CC) -o $@ $^
	./Sorting

BinarySerchTree : BinarySerchTreeMain.o
	$(CC) -o $@ $^
	./BinarySerchTree

AVLTree : AVLRebalance.o BinarySearchTree3.o BinaryTree3.o AVLTreeMain.o
	$(CC) -o $@ $^
	./AVLTree

HashTable : DLinkedList.o Person.o Slot2.h Table2.o HashTableMain.o
	$(CC) -o $@ $^
	./HashTable

clean:
	del *.o LinkedList.exe Stack.exe Queue.exe PriorityQueue.exe Sorting.exe BinarySerchTree.exe AVLTree.exe HashTable.exe
```

- Makefile을 생성해 사용했습니다. 
- make clean 사용 시 *.o 및 ㅁ.exe 파일들을 삭제하게 하였습니다.
- make [이름]을 입력하면 자동으로 관련 파일을 찾아 오브젝트 파일을 자동으로 생성하도록 했고, 그 뒤 실행되게 했습니다.

