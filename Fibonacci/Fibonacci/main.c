//
//  main.c
//  Fibonacci
//
//  Created by Shirley Xue on 2017/10/2.
//  Copyright © 2017年 Shirley Xue. All rights reserved.
//

#include <stdio.h>

void fibonacci(void) {
    int amount;
    int fib1 = 0, fib2 = 1, fib3;
    
    printf("How many elements do you want?\n");
    scanf("%d",&amount);
    printf("Fibonacci sequence:\n");
    
    if (amount < 1) {
        printf("Wrong input.");
    }
    else if (amount == 1) {
        printf("%d \n", fib1);
    }
    else if (amount == 2) {
        printf("%d %d \n", fib1, fib2);
    }
    else {
        printf("%d %d ", fib1, fib2);
        for (int count = 3; count <= amount; count ++) {
            fib3 = fib1 + fib2;
            printf("%d ", fib3);
            fib1 = fib2;
            fib2 = fib3;
            
            if (count % 5 == 0) {
                printf("\n");
            }
        }
        printf("\n");
    }
}

int main(int argc, const char * argv[]) {
    fibonacci();
    return 0;
}
