#include <stdio.h>
#include <stdbool.h>
#include "myBank.h"
#define _CRT_SECURE_NO_WARNINGS
int main()
{   
    bool continueprogram=true;
    while(continueprogram)
    {
        printf("\nPlease choose a transaction type:\n"
            " O-Open Account\n"
            " B-Balance Inquiry\n"
            " D-Deposit\n"
            " W-Withdrawal\n"
            " C-Close Account\n"
            " I-Interest\n"
            " P-Print\n"
            " E-Exit\n");

     char input;
        printf("Enter Your Transaction Type! \n");
        scanf(" %c",&input);
        switch (input)
        {
            case 'O':
            {
             double amount;
                printf("Enter initial deposit :\n");
                scanf("%lf",&amount);
                
                if(amount<0)
                  {
                      printf("Amount Most Be Bigger Than 0! \n");
                        break;
                    }
                Open_Account(amount);
                break;
          }
          case 'B':
          {
               int account_number;
              printf("Enter Account Number Please \n");
              scanf(" %d",&account_number);
              Balance( account_number);
             break;
         }
          case 'D':
          {
             double amount;
             int account_number;
             printf("Enter Account Number Please! \n");
             scanf(" %d",&account_number);
                printf("Please Enter Amount To Deposit \n");
             scanf (" %lf",&amount);
             Deposit( account_number, amount);
               break;
           }
           case 'W' :
           {
                double amount;
                int account_number;
                printf("Enter Account Number Please! \n");
               scanf(" %d",&account_number);
                printf("Please Enter Amount To Withdraw \n");
               scanf (" %lf",&amount);
               Pull_Money(account_number,amount);
                break;
           }
           case 'C':
           {
             int account_number;
               printf("Enter Account Number Please! \n");
              scanf(" %d",&account_number);
              Close_Account( account_number);
             break;
          }
            case 'I':
            {
            int interest_rate;
            printf("Enter interest rate: \n");
            scanf(" %d",&interest_rate);
            Add_Interest( interest_rate);
            break;
         }
          case 'P':
          {
              Print_All();
            break;
          }
          case 'E':
          {
              Close_All();
             continueprogram=false;
             return 0;
            }   
          default:
               printf("No such transaction action exist, Please try again\n");
                break;
      }
    }
    return 0;

}