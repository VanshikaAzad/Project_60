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

  