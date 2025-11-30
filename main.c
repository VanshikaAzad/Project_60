// main.c

#include <stdio.h>
#include <stdlib.h>
#include "record.h"

int main() {
    int n;

    printf("Enter number of customers: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Invalid number of customers!");
        return 0;
    }

    Record *records = (Record*) malloc(n * sizeof(Record));

    for (int i = 0; i < n; i++) {
        printf("\n--- Enter details for Customer %d ---\n", i + 1);

        printf("Consumer ID: ");
        scanf("%d", &records[i].consumer_id);

        printf("Previous Reading: ");
        scanf("%d", &records[i].prev_reading);

        printf("Current Reading: ");
        scanf("%d", &records[i].curr_reading);

        printf("Tariff rate (₹ per unit): ");
        scanf("%f", &records[i].tariff);

        computeBilling(&records[i]);
        records[i].anomaly_flag = detectAnomaly(&records[i]);
    }

    generateReport(records, n);
    free(records);

    return 0;
}

        