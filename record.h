#ifndef RECORD_H
#define RECORD_H

typedef struct {
    int consumer_id;
    int prev_reading;
    int curr_reading;
    float tariff;
    int usage;
    float cost;
    int anomaly_flag;
} Record;

void computeBilling(Record *r);
int detectAnomaly(Record *r);
void generateReport(Record *records, int n);

#endif