#include <stdio.h>
#define MAX 50
struct Package {
    int id;
    float value, weight, ratio, fraction;
};
struct Package p[MAX];
int n;
float capacity;
void enter() {
    int i;
    printf("Enter number of packages: ");
    scanf("%d", &n);
    for(i = 0; i < n; i++) {
        p[i].id = i + 1;
        printf("Package %d - Value Weight: ", i + 1);
        scanf("%f %f", &p[i].value, &p[i].weight);
        p[i].ratio = p[i].value / p[i].weight;
    }
    printf("Enter vehicle capacity: ");
    scanf("%f", &capacity);
}
void display() {
    int i;
    printf("\nID\tValue\tWeight\tRatio\n");
    for(i = 0; i < n; i++)
        printf("%d\t%.2f\t%.2f\t%.2f\n",
               p[i].id, p[i].value, p[i].weight, p[i].ratio);
}
void ratio() {
    int i;
    for(i = 0; i < n; i++)
        p[i].ratio = p[i].value / p[i].weight;
    printf("\nRatios calculated successfully.\n");
    display();
}
void merge(int l, int m, int r) {
    struct Package t[MAX];
    int i = l, j = m + 1, k = l;
    while(i <= m && j <= r) {
        if(p[i].ratio >= p[j].ratio)
            t[k++] = p[i++];
        else
            t[k++] = p[j++];
    }
    while(i <= m)
        t[k++] = p[i++];
    while(j <= r)
        t[k++] = p[j++];
    for(i = l; i <= r; i++)
        p[i] = t[i];
}
void mergeSort(int l, int r) {
    int m;
    if(l < r) {
        m = (l + r) / 2;
        mergeSort(l, m);
        mergeSort(m + 1, r);
        merge(l, m, r);
    }
}
void sort() {
    mergeSort(0, n - 1);
    printf("\nPackages sorted by decreasing ratio.\n");
    display();
}
void knapsack() {
    int i;
    float rem = capacity, totalW = 0, totalV = 0;
    mergeSort(0, n - 1);
    for(i = 0; i < n; i++) {
        if(rem >= p[i].weight)
            p[i].fraction = 1;
        else if(rem > 0)
            p[i].fraction = rem / p[i].weight;
        else
            p[i].fraction = 0;
        rem -= p[i].weight * p[i].fraction;
        totalW += p[i].weight * p[i].fraction;
        totalV += p[i].value * p[i].fraction;
    }
    printf("\nTotal Weight Used = %.2f", totalW);
    printf("\nMaximum Value = %.2f\n", totalV);
}
void selected() {
    int i;
    knapsack();
    printf("\nSelected Packages\n");
    printf("ID\tFraction\tWeight\tValue\n");
    for(i = 0; i < n; i++)
        if(p[i].fraction > 0)
            printf("%d\t%.2f\t\t%.2f\t%.2f\n",
                   p[i].id, p[i].fraction,
                   p[i].weight * p[i].fraction,
                   p[i].value * p[i].fraction);
}
int main() {
    int ch;
    do {
        printf("\n===== SMART DELIVERY PLANNING =====\n");
        printf("1. Enter Package Details\n");
        printf("2. Display Package Details\n");
        printf("3. Calculate Value/Weight Ratio\n");
        printf("4. Sort Packages by Ratio\n");
        printf("5. Find Maximum Value\n");
        printf("6. Display Selected Packages\n");
        printf("7. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &ch);
        switch(ch) {
            case 1: enter(); break;
            case 2: display(); break;
            case 3: ratio(); break;
            case 4: sort(); break;
            case 5: knapsack(); break;
            case 6: selected(); break;
            case 7: printf("Exiting...\n"); break;
            default: printf("Invalid choice!\n");
        }
    } while(ch != 7);
    return 0;
}
