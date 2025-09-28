#include<stdio.h>
#include<string.h>

struct cell {
    char dir;
    int val;
};

int max(int a, int b) {
    return (a > b) ? a : b;
}

// LRS function
void LRS(struct cell cost[100][100], int m, char A[m]) {
    int i, j;

    // Initialize first row and column
    for(i = 0; i < m; i++) {
        cost[i][0].val = 0;
        cost[i][0].dir = 'H';
    }
    for(j = 0; j < m; j++) {
        cost[0][j].val = 0;
        cost[0][j].dir = 'H';
    }

    for(i = 1; i < m; i++) {
        for(j = 1; j < m; j++) {
            if(A[i-1] == A[j-1] && i != j) { // key condition for LRS
                cost[i][j].val = cost[i-1][j-1].val + 1;
                cost[i][j].dir = 'D';
            } else {
                if(cost[i-1][j].val >= cost[i][j-1].val) {
                    cost[i][j].val = cost[i-1][j].val;
                    cost[i][j].dir = 'U';
                } else {
                    cost[i][j].val = cost[i][j-1].val;
                    cost[i][j].dir = 'L';
                }
            }
        }
    }
}

// Print LRS
void print_LRS(struct cell cost[100][100], char A[], int i, int j) {
    if(i == 0 || j == 0)
        return;
    
    if(cost[i][j].dir == 'D') {
        print_LRS(cost, A, i-1, j-1);
        printf("%c", A[i-1]);
    } else if(cost[i][j].dir == 'U') {
        print_LRS(cost, A, i-1, j);
    } else {
        print_LRS(cost, A, i, j-1);
    }
}

int main() {
    struct cell cost[100][100];
    char S[50];
    int m;

    printf("Enter String: ");
    scanf("%s", S);

    m = strlen(S) + 1;

    LRS(cost, m, S);

    printf("\nCost matrix:\n");
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < m; j++) {
            printf("%d/%c  ", cost[i][j].val, cost[i][j].dir);
        }
        printf("\n");
    }

    printf("\nLongest Repeating Subsequence:\n");
    print_LRS(cost, S, m-1, m-1);
    printf("\nLength of LRS: %d\n", cost[m-1][m-1].val);

    return 0;
}

//AABCBDC

