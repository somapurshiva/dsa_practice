//
//  main.c
//  Prefix-To-Postfix
//
//  Created by Shiva Somapur on 08/10/21.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define TRUE 1
#define FALSE 0
#define MAXLENGTH 80

void substr(char str1[], int startIdx, unsigned long length, char str2[]) {
    int i, j;
    for (i = startIdx, j = 0; j < length; i++, j++) {
        str2[j] = str1[i];
    }
    str2[j] = '\0';
}

// Function find, finds the length of the longest prefix expression contained within the input string that starts at the beginning of the string
int find(char str[]) {
    char temp[MAXLENGTH];
    unsigned long length;
    int m, n;
    
    if ((length = strlen(str)) == 0)
        return 0;
    if (isalpha(str[0]) != FALSE)
        // First character is a letter. That letter itself is the initial substring.
        return 1;
    // Else find the first operand
    if (strlen(str) < 2)
        return 0;
    substr(str, 1, length - 1, temp);
    m = find(temp);
    if (m == 0 || strlen(str) == m)
        // No valid prefix operand or no second operand found
        return 0;
    substr(str, m+1, length-m-1, temp);
    n = find(temp);
    if (n == 0)
        return 0;
    return m + n + 1;
}

int findNonRecursive(char str[]) {
    unsigned long length;
    if ((length = strlen(str)) == 0)
        return 0;
    if (isalpha(str[0]) != FALSE)
        // First character is a letter. That letter itself is the initial substring.
        return 1;
    // Else find the first operand
    if (strlen(str) < 2)
        return 0;
    if (isalpha(str[1]) != FALSE) {
        if (isalpha(str[2]) != FALSE)
            return 3;
    }
    return 0;
}

// function convert, converts the passed prefix string into a postfix string
void convert (char prefix[], char postfix[]) {
    char opnd1[MAXLENGTH], opnd2[MAXLENGTH];
    char post1[MAXLENGTH], post2[MAXLENGTH];
    char temp[MAXLENGTH];
    char op[2], c;
    unsigned long length;
    int m, n;
    
    // Base case - prefix just contains a single letter
    if ((length = strlen(prefix)) == 1) {
        if (isalpha(prefix[0])) {
            // Prefix string is a single letter
            postfix[0] = prefix[0];
            postfix[1] = '\0';
            return;
        }
        printf("\nIllegal prefix string\n");
        exit(1);
    }
    // Reached here - Prefix string is longer than a single character. Extract the operator and the two operand lengths
    op[0] = prefix[0];
    op[1] = '\0';
    // Find length of first operand
    substr(prefix, 1, length - 1, temp);
    m = find(temp);
    printf("m val = %d\n", m);
    // Find length of second operand
    substr(prefix, m + 1, length - m - 1, temp);
    n = find(temp);
    printf("n val = %d\n", n);
    // If the operator isn't valid or either of operands is absent or total length of string is not equal to length of operands and operator, its an error
    c = op[0];
    if ((c != '+' && c != '-' && c != '*' && c != '/') || m == 0 || n == 0 || (m + n + 1 != length)) {
        printf("\nIllegal prefix string\n");
        exit(1);
    }
    // Generate operands
    substr(prefix, 1, m, opnd1);
    substr(prefix, m + 1, n, opnd2);
    // Convert the operands to postfix
    printf("Operand 1 = %s\n", opnd1);
    printf("Operand 2 = %s\n", opnd2);
    convert(opnd1, post1);
    convert(opnd2, post2);
    // Concatenate the opnd1, opnd2 and operator
    strcat(post1, post2);
    strcat(post1, op);
    substr(post1, 0, length, postfix);
    printf("Postfix val = %s\n", postfix);
}

int main(int argc, const char * argv[]) {
//    char str1[MAXLENGTH], str2[MAXLENGTH];
    char prefix[MAXLENGTH], postfix[MAXLENGTH];
//    printf("enter Str1: ");
//    scanf("%s", str1);
////    substr(str1, 3, 4, str2);
////    printf("%s\n", str2);
//    printf("Longest Prefix length = %d\n", find(str1));
    printf("Enter the prefix string: ");
    scanf("%s", prefix);
    convert(prefix, postfix);
    printf("\nConverted to postfix: %s\n", postfix);
    return 0;
}
