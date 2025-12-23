#include <stdio.h>
#include <stdlib.h>

#define EMPTY -1   


void insert(int ht[], int m, int key) {
    int index = key % m;   
    int i = 0;

    
    while (ht[(index + i) % m] != EMPTY) {
        i++;
        if (i == m) {
            printf("Hash Table is full, cannot insert key %d\n", key);
            return;
        }
    }
    ht[(index + i) % m] = key;
}


int search(int ht[], int m, int key) {
    int index = key % m;
    int i = 0;

    while (ht[(index + i) % m] != EMPTY) {
        if (ht[(index + i) % m] == key)
            return (index + i) % m;  
        i++;
        if (i == m) break;
    }
    return -1;
}


void display(int ht[], int m) {
    printf("\nHash Table:\n");
    for (int i = 0; i < m; i++) {
        if (ht[i] == EMPTY)
            printf("HT[%d] : EMPTY\n", i);
        else
            printf("HT[%d] : %d\n", i, ht[i]);
    }
}

int main() {
    int m, n, key;

    printf("Enter size of Hash Table (m): ");
    scanf("%d", &m);

    int ht[m];
    for (int i = 0; i < m; i++)
        ht[i] = EMPTY;

    printf("Enter number of employee records (N): ");
    scanf("%d", &n);

    printf("Enter %d employee keys (4-digit integers):\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &key);
        insert(ht, m, key);
    }

    display(ht, m);

    
    printf("\nEnter key to search: ");
    scanf("%d", &key);
    int pos = search(ht, m, key);
    if (pos != -1)
        printf("Key %d found at location %d\n", key, pos);
    else
        printf("Key %d not found in Hash Table\n", key);

    return 0;
}
