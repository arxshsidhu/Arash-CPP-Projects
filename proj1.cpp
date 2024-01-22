#include <iostream>
#include <cmath> // -> for rounding up 'ceil' function
using namespace std;

int main() {
   
    /* 
        request user input for maximum data
        request user input for billing cycle days
        request user input for data used so far
        calculate average daily usage from days passed
        calculate expected data usage from avg daily * total billing
        calculate daily data allowance without exceeding max data cap 
        convert GB inputs to KB via shift operands
        The rest of my documentation is line-by-line
    */

// Initialize

    double maxData;
    int totalBilling;
    double dataUsed;
    int daysPassed;

// User Data Input module

    cout << "Maximum Data: "; 
    cin >> maxData;
    cout << "Total Billing Cycle Days: ";
    cin >> totalBilling;
    cout << "data used so far: ";
    cin >> dataUsed;
    cout << "Amount of days passed: ";
    cin >> daysPassed;
    
// Math module

    double averageDailyLimit = static_cast<double>(dataUsed / daysPassed); // -> First I need to figure out his average data usage, dataUsed / totalBilling 
    double remainingDataLimit = static_cast<double>(maxData - dataUsed); // -> Now I need to calculate remaining data limit
    double totalExpectedUsage = static_cast<double>(averageDailyLimit / totalBilling); // -> How much they are estimated to use if they continue at that rate. 
    int daysRemaining = static_cast<double>(totalBilling - daysPassed); // -> Calculates how many days are reamaining
    double nonExceedLim = static_cast<double>(remainingDataLimit / daysRemaining); // -> Calculates how much data they can use per day without exceeding their total limit remaining
    double expectedUsage = static_cast<double>(averageDailyLimit * totalBilling); // -> Calculate the expected usage if user continues at calcuated rate
    double GBtoKB = static_cast<int>(ceil(averageDailyLimit * (1<< 10))); // -> converts the GB amount to KB

// printing module

    cout << "Your average daily data usage: " << averageDailyLimit << "GB.\n";
    cout << "Expected data usage at current rate: " << expectedUsage << "GB.\n";
    cout << "Your remaining data limit: " << remainingDataLimit << "GB.\n";
    cout << "How much data usable per day until billing reset: " << nonExceedLim << "GB.\n";
    cout << "Your average data usage in KB is: " << GBtoKB << "KB.\n";
    return 0;
}

// I have to print: 
    /*
1. AVERAGE DAILY DATA USAGE
2. TOTAL EXPECTED USAGE AT CURRENT RATE
3. HOW MUCH DATA USABLE PER DAY TO NOT GO OVER LIMIT
    */
