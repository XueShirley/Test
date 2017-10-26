//
//  main.c
//  LinkedList
//
//  Created by Shirley Xue on 2017/10/2.
//  Copyright © 2017年 Shirley Xue. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h> //含exit(0)、malloc函数


typedef struct Node{
    int data;
    struct Node *next;
}Node,*LinkList;

LinkList initList(void);
LinkList addNode(LinkList head);
LinkList alterNode(LinkList head, int order);
LinkList deleteNode(LinkList head, int order);
void display(LinkList head);
int menu(void);

//主函数
int main(int argc, const char * argv[]) {
    
    int menuNumber, order;
    LinkList head = NULL;
    
    while(1) {
        menuNumber = menu();
        switch (menuNumber) {
            case 1://创建链表
                printf("输入要创建的结点（以“-999”为结束指令）：\n");
                head = initList();
                printf("完成创建！\n");
                break;
            case 2://增加结点
                printf("输入要增加的结点（以“-999”为结束指令）：\n");
                head = addNode(head);
                printf("完成增加！\n");
                break;
            case 3://修改结点
                printf("请输入要修改的是第几个结点：\n");
                scanf("%d", &order);
                head = alterNode(head, order);
                break;
            case 4://删除结点
                printf("请输入要删除的是第几个结点：\n");
                scanf("%d", &order);
                head = deleteNode(head, order);
                break;
            case 5://显示链表
                display(head);
                break;
            case 0:
                exit(0);
                break;
            default:
                printf("输入错误.\n");
                break;
        }
    }
    return 0;
}
//创建链表
LinkList initList() {
    LinkList head = (LinkList)malloc(sizeof(Node));
    if (!head) {
        printf("分配失败！");
        exit(0);
    }
    
    LinkList pNode = head;
    int data;
    
    scanf("%d", &data);
    while (data != -999) {
        LinkList newNode = (LinkList)malloc(sizeof(Node));
        if (!newNode) {
            printf("分配失败！");
            exit(0);
        }
        else {
            newNode->data = data;
            newNode->next = NULL;
            pNode->next = newNode;
            pNode = pNode->next;
            scanf("%d", &data);
        }
    }
    return head;
}
//增加结点
LinkList addNode(LinkList head) {
    LinkList newList = initList();
    LinkList pNode = head;
    
    while (pNode->next) {
        pNode = pNode->next;
    }
    
    pNode->next = newList->next;
    
    return head;
}
//修改结点
LinkList alterNode(LinkList head, int order) {
    LinkList alterNode = head;
    int data;
    printf("请输入新的值：\n");
    scanf("%d",&data);
    
    for (int i = 0; i<order; i++) {
        alterNode = alterNode->next;
    }
    alterNode->data = data;
    
    return head;
}
//删除结点
LinkList deleteNode(LinkList head, int order) {
    LinkList pNode = head;
    LinkList deleteNode = NULL;
    
    for (int i = 0; i<order-1; i++) {
        pNode = pNode->next;
    }
    deleteNode = pNode->next;
    pNode->next = deleteNode->next;
    free(deleteNode);
    
    return head;
}
//显示链表
void display(LinkList head) {
    LinkList pNode = head;
    int i = 1;
    while ((pNode = pNode->next) != NULL) {
        printf("->第%d个结点：\t%p\t%d\n", i, pNode, pNode->data);    //用 %p 打印指针的地址
        i++;
    }
}
//菜单
int menu(void) {
    int menuNumber;
    
    printf("               链表\n");
    printf("----------------------------------\n");
    printf("1.创建链表\t\t5.显示链表\t0.退出\n");
    printf("2.增加结点\t3.修改结点\t4.删除结点\n");
    printf("----------------------------------\n");
    printf("请选择:\n");
    scanf("%d",&menuNumber);
    
    return menuNumber;
}
