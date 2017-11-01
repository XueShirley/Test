//
//  main.c
//  BinaryTree
//
//  Created by Shirley Xue on 2017/10/26.
//  Copyright © 2017年 Shirley Xue. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

typedef struct BinaryTree {
    char data;
    struct BinaryTree *left, *right;
}Node, *Pointer;

Pointer initTree(Pointer root);
void display(Pointer root);
Pointer exchange(Pointer root);
void mirror(Pointer root);
//void test(Pointer root);

int main(int argc, const char * argv[]) {
    Pointer root = NULL;
//    int i = 0;
    
    printf("请按照 前序遍历：根节点->左子树->右子树 的规则输入结点。\n");
    printf("空结点输入'*'\n以“#”为结束标识\n");
    
    root = initTree(root);
    
    printf("原二叉树：\n");
    display(root);
    printf("\n其镜像二叉树：\n");
    mirror(root);
    printf("\n   ");
    return 0;
}

Pointer initTree(Pointer root){//前序遍历创建二叉树
    char data;
    scanf("%c",&data);
    getchar();
    
    if (data == '*') {
        root = NULL;
    }
    else {
        root = malloc(sizeof(Node));
        root->data = data;
        root->left = initTree(root->left);//为什么要写root->left = ，才能复制过来
        root->right = initTree(root->right);
    }
    return root;
}

void display(Pointer root) {
    if (root == NULL) {
        return ;
    }
    printf("\t%c", root->data);
    display(root->left);
    display(root->right);
}
Pointer exchange(Pointer root) {
    if (root == NULL) {
        return root;
    }
    Pointer temp;
    temp = root->left;
    root->left = root->right;
    root->right =temp;
    
    exchange(root->left);
    exchange(root->right);
    
    return root;
}
void mirror(Pointer root)  {
    root = exchange(root);
    display(root);
}
