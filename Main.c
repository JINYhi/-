#include <stdio.h>
#include <stdlib.h>

int main(){

    int n;
    
    while(1)
    {
        //system("make clean");
        printf("\n\n<<menu>>\n0 : 종료\n1 : LinkedList(연결리스트)\n2 : Stack(스택)\n3 : Queue(큐)\n4 : Priority Queue(우선순위 큐)\n5 : Sorting(정렬)\n6 : BinarySerchTree(이진탐색트리)\n7 : AVLTree(AVL트리)\n8 : HashTable(연결리스트를 활용한 해쉬테이블)\n->");
        scanf("%d", &n);
        if(n == 0)
        {
            printf("\n<<end>>");
            break;
        }

        if(n==1) // 연결리스트
        {
            printf("\n<<LinkedList(연결리스트)>>\n");
            system("make LinkedList");
               
        }

        if(n==2) // 스택
        {
            printf("\n<<Stack(스택)>>\n");
            system("make Stack");
        }

        if(n==3) // 큐
        {
            printf("\n<<Queue(큐)>>\n");
            system("make Queue");
        }
        
        if(n==4) // 우선순위 큐
        {
            printf("\n<<Priority Queue(우선순위 큐)>>\n");
            system("make PriorityQueue");
        }

        if(n==5) // 정렬 걸린 시간 계산하기
        {
            printf("\n<<Sorting(정렬)>>\n");
            system("make Sorting");
        }

        if(n==6) // 이진 탐색 트리
        {
            printf("\n<<BinarySerchTree(이진탐색트리)>>\n");
            system("make BinarySerchTree");
        }

        if(n==7) // AVL트리
        {
            printf("\n<<AVLTree(AVL트리)>>\n");
            system("make AVLTree");
        }

        if(n==8) // 연결리스트를 활용한 해쉬테이블
        {
            printf("\n<<HashTable(해쉬테이블)>>\n");
            system("make HashTable");
        }

        system("make clean");
    }

    return 0;
}