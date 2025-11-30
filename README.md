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

