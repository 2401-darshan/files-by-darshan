#include <stdio.h>
#include <string.h>

void main() {
    char str[100];
    char *ptr1, *ptr2;
    int flag = 1;

    printf("Enter a string: ");
    scanf("%s", str);

    ptr1 = str;
    ptr2 = str + strlen(str) - 1; 

    while (ptr1 < ptr2) {
        if (*ptr1 != *ptr2) {
            flag = 0;
            break;
        }
        ptr1++;
        ptr2--;
    }

    if(flag) {
        printf("The string is a palindrome.\n", str);
    } else {
        printf("The string is not a palindrome.\n", str);
	}
}

