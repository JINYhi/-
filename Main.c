#include <stdio.h>
#include <stdlib.h>

int main(){

    int n;
    
    while(1)
    {
        //system("make clean");
        printf("\n\n<<menu>>\n0 : ����\n1 : LinkedList(���Ḯ��Ʈ)\n2 : Stack(����)\n3 : Queue(ť)\n4 : Priority Queue(�켱���� ť)\n5 : Sorting(����)\n6 : BinarySerchTree(����Ž��Ʈ��)\n7 : AVLTree(AVLƮ��)\n8 : HashTable(���Ḯ��Ʈ�� Ȱ���� �ؽ����̺�)\n->");
        scanf("%d", &n);
        if(n == 0)
        {
            printf("\n<<end>>");
            break;
        }

        if(n==1) // ���Ḯ��Ʈ
        {
            printf("\n<<LinkedList(���Ḯ��Ʈ)>>\n");
            system("make LinkedList");
               
        }

        if(n==2) // ����
        {
            printf("\n<<Stack(����)>>\n");
            system("make Stack");
        }

        if(n==3) // ť
        {
            printf("\n<<Queue(ť)>>\n");
            system("make Queue");
        }
        
        if(n==4) // �켱���� ť
        {
            printf("\n<<Priority Queue(�켱���� ť)>>\n");
            system("make PriorityQueue");
        }

        if(n==5) // ���� �ɸ� �ð� ����ϱ�
        {
            printf("\n<<Sorting(����)>>\n");
            system("make Sorting");
        }

        if(n==6) // ���� Ž�� Ʈ��
        {
            printf("\n<<BinarySerchTree(����Ž��Ʈ��)>>\n");
            system("make BinarySerchTree");
        }

        if(n==7) // AVLƮ��
        {
            printf("\n<<AVLTree(AVLƮ��)>>\n");
            system("make AVLTree");
        }

        if(n==8) // ���Ḯ��Ʈ�� Ȱ���� �ؽ����̺�
        {
            printf("\n<<HashTable(�ؽ����̺�)>>\n");
            system("make HashTable");
        }

        system("make clean");
    }

    return 0;
}