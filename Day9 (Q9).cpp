// A secret system stores code names in forward order. To display them in mirror format, you must transform the given code name so that its characters appear in the opposite order.
#include <stdio.h>
#include <string.h>

int main() {
    // 1. Fix: Create an array (buffer) to store the string.
    // 'char code[100]' can hold up to 99 characters + 1 null terminator.
    char code[100]; 

    printf("Enter code name: "); 

    // 2. Fix: Use %s to read a word. 
    // Do NOT use '&' with 'code' here because 'code' is already an array/address.
    if (scanf("%s", code) != 1) {
        return 1; 
    }

    int len = strlen(code);
    
    // 3. Mirror logic: Swap characters from both ends
    for (int i = 0, j = len - 1; i < j; i++, j--) {
        char temp = code[i];
        code[i] = code[j];
        code[j] = temp;
    }

    printf("Mirrored: %s\n", code);

    return 0;
}
