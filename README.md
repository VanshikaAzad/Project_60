# Smart Electricity Billing and Theft Detection System

A modular C program that calculates monthly electricity bills for multiple customers and detects abnormal usage patterns that may indicate electricity theft.  
The project demonstrates the use of structures, arrays, functions, pointers, dynamic memory allocation, and multi-file compilation in C.

---

 Features

- Automatic Bill Calculation 
  Calculates electricity usage and total cost based on previous and current meter readings.

- Theft / Anomaly Detection  
  Flags customers with unusually high consumption (usage > 500 units).

- Multi-File Program Structure
  Organized into multiple C files:
  - `main.c`
  - `billing.c`
  - `record.h`

- Dynamic Memory Allocation  
  Handles multiple customers efficiently using `malloc()`.

- Monthly Report Generation 
  Displays:
  - Consumer ID  
  - Total usage  
  - Bill amount  
  - Anomaly status  
  - Total revenue  
  - Number of flagged anomalies  

---

-How It Works
1. User enters the number of customers.  
2. For each customer:
   - Consumer ID  
   - Previous and current meter readings  
   - Tariff rate per unit  
3. Program calculates:
   - Units consumed  
   - Total cost  
4. Anomaly detection function flags abnormal usage.  
5. A full monthly report is displayed.
Purpose of each file:
   
1. record.h — Header File
Purpose of this file:
Declares the structure used tostore customer data
Declares the function prototypes (the functions used in other files)
Allows main.c and billing.c to share the same data types and functions

What it contains:
Structure Record with:
consumer ID
meter readings
tariff
usage
total bill
anomaly flag

Function declarations:
computeBilling()
detectAnomaly()
generateReport()

In simple words:
 This file defines the “blueprint” of data and function names.

2. billing.c — Billing Logic + Anomaly Detection + Report Generator
Purpose of this file:
This file contains all the logic of the electricity billing system.

It does three jobs:
Calculate usage & bill
Detect unusual consumption
Generate a monthly report

Functions inside:
1️⃣ computeBilling(Record *r)

Calculates:
usage = curr_reading - prev_reading
cost  = usage × tariff
Fixes negative values and computes the bill.

2️⃣ detectAnomaly(Record *r)

Checks:
If usage > 500 units → anomaly = 1
Else → anomaly = 0

Flags unusual consumption which may indicate electricity theft.

3️⃣ generateReport(records, n)
Displays:
Consumer ID
Usage
Bill amount
Whether anomaly was detected
Total revenue collected
Total anomalies for the month

In simple words:

➡️ This file contains all the “brains” of the project — billing, anomaly detection, reporting.
