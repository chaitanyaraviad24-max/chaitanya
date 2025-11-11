#include <stdio.h>
void hanoi(int n, char from, char topeg, char aux) {
    if (n == 1) {
        printf("Move disk 1 from rod %c to rod %c\n", from, topeg);
        return;
    }
    hanoi(n - 1, from, aux, topeg);
    printf("Move disk %d from rod %c to rod %c\n", n, from, topeg);
    hanoi(n - 1, aux, topeg, from);
}

int main() {
    int n;
    printf("Enter the number of disks: ");
    scanf("%d", &n);
    hanoi(n, 'A', 'C', 'B');
    return 0;
}
