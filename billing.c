// billing.c

#include <stdio.h>
#include "record.h"

void computeBilling(Record *r) {
    r->usage = r->curr_reading - r->prev_reading;

    if (r->usage < 0)
        r->usage = 0;

    r->cost = r->usage * r->tariff;
}

int detectAnomaly(Record *r) {
    if (r->usage > 500)
        return 1;
    return 0;
}

void generateReport(Record *records, int n) {
    float total_revenue = 0;
    int anomalies = 0;

    printf("\n========== MONTHLY REPORT ==========\n");

    for (int i = 0; i < n; i++) {
        printf("\nConsumer ID: %d", records[i].consumer_id);
        printf("\nUsage: %d units", records[i].usage);
        printf("\nBill Amount: ₹%.2f", records[i].cost);

        if (records[i].anomaly_flag) {
            printf("  <-- ANOMALY DETECTED!");
            anomalies++;
        }

        total_revenue += records[i].cost;
        printf("\n-------------------------------------");
    }

    printf("\nTotal Revenue: ₹%.2f", total_revenue);
    printf("\nTotal Anomalies Detected: %d\n", anomalies);
}
