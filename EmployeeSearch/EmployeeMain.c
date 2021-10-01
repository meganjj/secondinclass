//Compile using the following command: gcc EmployeeMain.c EmployeeTable.c EmployeeOne.c

//gcc employeeMain.c employeeTable.c employeeTwo.c

#include <string.h>
#include <stdlib.h>
#include "Employee.h"
int main(void){
    //defined in employeeSearchOne.c
    PtrToEmployee searchEmployeeByNumber(const Employee table[], int sizeTable, long numberToFind);
    PtrToEmployee searchEmployeeByName(const Employee table[], int sizeTable, char * nameToFind);
    PtrToEmployee searchEmployeeByPhone(PtrToConstEmployee ptr, int tableSize, char * targetPhone);
    PtrToEmployee searchEmployeeBySalary(PtrToConstEmployee ptr, int tableSize, double targetSalary);

    //defined in employeeTable.c
    extern Employee EmployeeTable[];    
    extern const int EmployeeTableEntries;     

    PtrToEmployee matchPtr;  //Declaration
    matchPtr = searchEmployeeByNumber(EmployeeTable, EmployeeTableEntries, 1045);

    //Example not found
    if (matchPtr != NULL)
        printf("Employee ID 1045 is in record %ld\n", matchPtr - EmployeeTable);
    else
        printf("Employee ID is NOT found in the record\n");

    //Example found
    matchPtr = searchEmployeeByName(EmployeeTable, EmployeeTableEntries, "Tony Bobcat");
    if (matchPtr != NULL)
        printf("Employee Tony Bobcat is in record %ld\n", matchPtr - EmployeeTable);
    else
        printf("Employee Tony Bobcat is NOT found in the record\n");
    

    //Example found for phone
    matchPtr = searchEmployeeByPhone(EmployeeTable, EmployeeTableEntries, "213-555-1212");
    if (matchPtr != NULL)
        printf("Phone number 213-555-1212 is in record %ld\n", matchPtr - EmployeeTable);
    else
        printf("Phone number 213-555-1212 is NOT found in the record\n");
    //Example not found for phone
    matchPtr = searchEmployeeByPhone(EmployeeTable, EmployeeTableEntries, "213-840-1234");
    if (matchPtr != NULL)
        printf("Phone number 213-840-1234 is in record %ld\n", matchPtr - EmployeeTable);
    else
        printf("Phone number 213-840-1234 is NOT found in the record\n");
    
    //Example found for salary
    matchPtr = searchEmployeeBySalary(EmployeeTable, EmployeeTableEntries, 8.78);
    if (matchPtr != NULL)
        printf("Employee salary $8.78 is in record %ld\n", matchPtr - EmployeeTable);
    else
        printf("Employee salary $8.78 is NOT found in the record\n");
    //Example not found for salary
    matchPtr = searchEmployeeBySalary(EmployeeTable, EmployeeTableEntries, 6.50);
    if (matchPtr != NULL)
        printf("Employee salary $6.50 is in record %ld\n", matchPtr - EmployeeTable);
    else
        printf("Employee salary $6.50 is NOT found in the record\n");

    return EXIT_SUCCESS;
}
