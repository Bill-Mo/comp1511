//zID is z5305298
#include <stdio.h>

int isLeapYear(int year);
int main (void) {
	int startYear, finishYear, year;
	printf("Enter start year: ");
	int result1 = scanf("%d", &startYear);
	if (result1 == 1) {
		printf("Enter finish year: ");
		int result2 = scanf("%d", &finishYear);
		year = startYear;
		if (result1 == 1 && result2 == 1 && startYear <= finishYear) {
			printf("The leap years between %d and %d are:", startYear, finishYear);
			while (year <= finishYear) {
				if (isLeapYear(year) == 1) {
					printf(" %d", year);
					year ++;
				} else {
					year ++;
				}
			}
		} else {
			printf("Invalid input");
		}
	} else {
		printf("Invalid input");
	}
	printf("\n");
	return 0;
}

int isLeapYear(int year) {
	int result;
	if ((year % 4 == 0 && year % 100 != 0) || (year % 100 == 0 && year % 400 == 0)) {
		result = 1;
	} else {
		result = 0;
	}
	return result;
}
