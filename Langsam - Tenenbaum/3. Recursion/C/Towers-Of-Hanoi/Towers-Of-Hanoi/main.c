//
//  main.c
//  Towers-Of-Hanoi
//
//  Created by Shiva Somapur on 06/10/21.
//

#include <stdio.h>

void towers(int, char, char, char);

int main(int argc, const char * argv[]) {
    int n;
    printf("Started program\nEnter n: ");
    scanf("%d", &n);
    towers(n, 'A', 'C', 'B');
    return 0;
}

void towers(int n, char frompeg, char topeg, char auxpeg) {
    // If there is only one disk left, move the disk and return
    if (n == 1) {
        printf("Move disk 1 from peg %c to peg %c\n", frompeg, topeg);
        return;
    }
    // Move top n-1 disks from A to B using C as auxiliary
    towers(n-1, frompeg, auxpeg, topeg);
    // Move the last disk from A to C
    printf("Move disk %d from peg %c to peg %c\n", n, frompeg, topeg);
    // Move n-1 disks from B to C using A as auxiliary
    towers(n-1, auxpeg, topeg, frompeg);
}
