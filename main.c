#include<stdio.h>
#include "account.h"
#include "file.h"
int main()
{
   int choice;
   AccountManagment accountmanagment;
   initialize(&accountmanagment);
   printf("Display menu:\n");
   
   do{
   printf("1.Create\n2.Deposit\n3.Withdraw\n4.Balance\n5.close Account\n6.Exit\n");
   printf("Enter the choice:\n");
   scanf("%d",&choice);
   
   switch(choice)
   {
    case 1:
        fprintf(stdout,"Create Account Menu:\n");
        createAccount(&accountmanagment);
        break;
    case 2:
        fprintf(stdout,"Deposit Menu:\n");
        Deposit_money(&accountmanagment);
        break;
    case 3:
        fprintf(stdout,"WithDraw Menu:\n");
        Withdraw_money(&accountmanagment);
        break;
    case 4:
        fprintf(stdout,"Balance Menu:\n");
        Balance(&accountmanagment);
        break;
    case 5:
        fprintf(stdout,"Close Account Menu:\n");
        closeAccount(&accountmanagment);
        break;
    case 6:
        fprintf(stdout,"Exiting....\n");
        savedetailsToFile(&accountmanagment);
        break;
    default :
        fprintf(stdout,"Invalid Input\n");
        break;

   } 
}while(choice!=6);
}