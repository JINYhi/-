
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

- **Makefile**을 생성해 분할컴파일을 진행했습니다. 
- **make clean** 사용 시 *.o 및 ㅁ.exe **파일들을 삭제**하게 하였습니다.
- make [이름]을 입력하면 자동으로 관련 파일을 찾아 **오브젝트 파일을 자동으로 생성**하도록 했고, **그 뒤 실행**되게 했습니다.

#### 3-1. 참고
      - https://velog.io/@hidaehyunlee/Makefile-%EB%A7%8C%EB%93%A4%EA%B8%B0	 
      - https://ndb796.tistory.com/381
      - https://losskatsu.github.io/programming/c-make/#%EB%A7%A4%ED%81%AC%EB%A1%9C-%EC%82%AC%EC%9A%A91


---
## 2. 업로드 과정
![image](https://user-images.githubusercontent.com/96537605/155955358-5f8bf025-ce6d-4b25-8ff9-8edde2086b08.png)

- 열심히 글 써서 업로드 ,,



---



## 3. 시뮬레이터 소개
### 1. 목록
![image](https://user-images.githubusercontent.com/96537605/155955926-23ea9ac7-a1d9-43fd-9b38-051cee2ad3fd.png)
- 처음 실행했을때 나오는 목록에서는 0 : 종료, 1 : 연결리스트, 2: 스택, 3: 큐, 4: 우선순위큐, 5: 정렬, 6: 이진탐색트리, 7: AVL트리, 8: 해쉬테이블 시뮬레이터가 있다.
- 제일 밑 화살표에서 원하는 시뮬레이터의 번호를 입력하면, 그 시뮬레이터가 실행된다.


### 2. 시뮬레이터 실행 시
![image](https://user-images.githubusercontent.com/96537605/155956486-21b932b6-db10-4180-a16d-11ac365edd63.png)
- 예시로 1번, 연결리스트 **시뮬레이터를 실행**시켰다.
- Makefile 설정대로, **연결리스트 관련 파일들을 gcc 컴파일 시켜주고 [./LinkedList]가 자동으로 실행된다.**


![image](https://user-images.githubusercontent.com/96537605/155956829-d19ee3e3-bb6f-4900-85ec-5495b6f8d765.png)

- 원하는 만큼 시뮬레이션을 돌린 뒤 연결리스트 **시뮬레이터를 종료시키면,** 연결리스트와 **관련되어 생성된 파일들이 자동으로 삭제된다.**
- 
