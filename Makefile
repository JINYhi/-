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