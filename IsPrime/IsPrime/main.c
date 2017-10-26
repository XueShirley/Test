//
//  main.c
//  IsPrime
//
//  Created by Shirley Xue on 2017/10/2.
//  Copyright © 2017年 Shirley Xue. All rights reserved.
//

#include <stdio.h>

void isPrime(int number) {
    int flag = 1;
    
    if (number < 2) {
        flag = 0;
    }
    else {
        for (int i = 2; i*i <= number; i++) {
            if (number % i == 0) {
                flag = 0;
            }
        }
    }
    
    if (flag == 0) {
        printf("%d 不是一个素数。\n",number);
    }
    else {
        printf("%d 是一个素数。\n",number);
    }
}
void test(void) {
    printf("测试数为：2、4、7、25、89。\n\n");
    isPrime(2);
    isPrime(4);
    isPrime(7);
    isPrime(25);
    isPrime(89);
}
int main(int argc, const char * argv[]) {
    test();
    return 0;
}
