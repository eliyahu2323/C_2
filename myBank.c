#include "myBank.h"
#include <stdio.h>
double arr[ROWS][COLS] = { {0},{0} };
void Open_Account(double x) {
	
	for (int i=0; i< COLS; i++) {
		if (arr[0][i] == 0) {
			arr[0][i] = 1;
			arr[1][i] = x;
			printf("The new account created and the account number is: : %d\n", FIRST + i);
			return;

		}
	}
	printf("The bank is full\n");
}

void Balance(int account_number) {
	if (account_number - FIRST > 90 || account_number - FIRST < 0) {
		printf("The Account number is not Found\n");
	}
	if (arr[0][account_number - FIRST] == 1) {
		printf("The Balance Inquiry Of This Account: %d is: %.2lf\n ", account_number, arr[1][account_number - FIRST]);
	}
	else {
		printf("This account closed\n");
	}
}

void Deposit(int account_number, double Amount) {
	if (account_number - FIRST > 90 || account_number - FIRST < 0) {
		printf("The Account number is not Found\n");
		return;
	}

	if (arr[0][account_number - FIRST] == 1) {
		arr[1][account_number - FIRST] = arr[1][account_number - FIRST] + Amount;
		printf("The New Balance is : %d   Is: %.2lf \n", account_number, arr[1][account_number - FIRST]);

		return;
	}
	else {
		printf("This account closed\n");
	}

}

void Pull_Money(int account_number, double Amount) {
	if (account_number - FIRST > 90 || account_number - FIRST < 0) {
		printf("The Account number is not Found\n");
		return;
	}
	if (arr[0][account_number - FIRST] == 1) {
		if (arr[1][account_number - FIRST] - Amount >=0) {
			arr[1][account_number - FIRST] = arr[1][account_number - FIRST] - Amount;
			printf("The New Balance is : %d   Is: %.2lf \n", account_number, arr[1][account_number - FIRST]);
			return;
		}
		else {
			printf("There is not enough money in the account \n");
			return;
		}
	}
	else {
		printf("This account closed\n");
	}
}

void Close_Account(int account_number) {
	if (account_number - FIRST > 90 || account_number - FIRST < 0) {
		printf("The Account number is not Found!!\n");
		return;
	}
	if (arr[0][account_number - FIRST] == 1) {
		arr[0][account_number - FIRST] = 0;
		arr[1][account_number - FIRST] = 0;
		printf("This Account is closed\n");
		return;
	}
	else {
		printf("This Account Is Close\n");
	}
}

void Add_Interest(int interest_rate) {
	if (interest_rate <= 0) {
		printf("The interest rate cannot be negative\n");
		return;
	}
	for (int i = 0; i < COLS; i++) {
		if (arr[0][i] == 1) {
			arr[1][i] += arr[1][i] * ((double)interest_rate / 100);
		}
	}
}

void Print_All() {
	for (int i = 0; i < COLS; i++) {
		if (arr[0][i] == 1) {
			printf("Acount Number Is : %d \n  Balance Is :%.2f\n", FIRST + i, arr[1][i]);
		}
	}
}

void Close_All() {

	for (int i = 0; i < COLS; i++) {
		if (arr[0][i] == 1)
		{
			arr[0][i] = 0;
			arr[1][i] = 0;
		}
	}
	
	printf("All The Accounts Are Closed\n");

}





