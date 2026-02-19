#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include<time.h>
#include "account.h"
#include "file.h"

void initialize(AccountManagment *accountmanagment){
    accountmanagment->accountcount=0;
    //populateAddressBook(addressBook);
    
    // Load contacts from file during initialization (After files)
    loaddetailsFromFile(accountmanagment);
}

void saveAndExit(AccountManagment *accountmanagment) {
    savedetailsToFile(accountmanagment); // Save contacts to file
    exit(EXIT_SUCCESS); // Exit the program
}



void createAccount(AccountManagment *accountmanagment){
    char id[20],name[20],balance[100];
     printf("Enter the name:");
    scanf(" %[^\n]",name);
    strcpy(accountmanagment->accounts[accountmanagment->accountcount].name,name);

    int age;
    printf("enter the age:");
    scanf(" %d",&age);

    if(age>=18){
       long long int num=generate_Account_num();
        sprintf(id,"%lld",num);
        strcpy(accountmanagment->accounts[accountmanagment->accountcount].account_num,id);

    printf("enter the amount you want to deposit:");
    scanf(" %[^\n]",balance);

    strcpy(accountmanagment->accounts[accountmanagment->accountcount].balance,balance);
    accountmanagment->accountcount++;
    printf("\nAccount created succesfully ✅\n");
    
    printf("------------------------------------------------------------------\n");
    printf("%-20s %-20s %-20s\n","ACCOUNT NUMBER","NAME","BALANCE");
    printf("------------------------------------------------------------------\n");
    printf("%-20s %-20s %-20s\n",id,name,balance);
    printf("------------------------------------------------------------------\n");
    printf("Please note the account number\n\n");
    }
    else{
        printf("you are under 18, so you cannot create account\n");
        return;
    }

}

long long generate_Account_num(){
    srand(time(NULL));
    long long int num=0;
    num=rand()%9+1;
    for(int i=0;i<9;i++){
        num=num*10+rand()%10;
    }
    return num;
}

void Deposit_money(AccountManagment *accountmanagment){
    char str1[20];
    int temp,count=0;
    printf("Enter the Account number:");
    scanf(" %[^\n]",str1);
    printf("\n-----------------------------------------------------------------\n");
    printf("%s. %s \t  %s  \t%s \n","sl.no","Account number","name","balance");
    printf("-----------------------------------------------------------------\n");
    for(int i=0;i<accountmanagment->accountcount;i++){
        if(strcmp(str1,accountmanagment->accounts[i].account_num)==0){
            printf("%d.%s \t  %s  \t%s \n",i,accountmanagment->accounts[i].account_num,accountmanagment->accounts[i].name,accountmanagment->accounts[i].balance);
            temp=i;
            count=1;
        }
    }
    if(count==0){
        printf("No account found\n");
        printf("-----------------------------------------------------------------\n");
        return;
    }
    printf("-----------------------------------------------------------------\n");

    printf("Confirm this account (Y|y)\n");
    char ch;
    scanf(" %c",&ch);
    if(ch=='Y'||ch=='y'){
        printf("Enter the amount you want to deposit:");
        int num1,num2,sum=0;
        scanf("%d",&num1);
        sscanf(accountmanagment->accounts[temp].balance,"%d",&num2);
        sum=num1+num2;
        char str2[100];
        sprintf(accountmanagment->accounts[temp].balance,"%d",sum);

    }

}
void Withdraw_money(AccountManagment *accountmanagment){

    printf("Enter the account number:");
    char str1[100];
    scanf(" %[^\n]",str1);
    printf("Enter the amount to withdraw:");
    int money,count=0,temp;
    scanf("%d",&money);
    for(int i=0;i<accountmanagment->accountcount;i++)
    {
        if((strcmp(accountmanagment->accounts[i].account_num,str1))==0)
        {
            int num;
            sscanf(accountmanagment->accounts[i].balance,"%d",&num);
            int sum=num-money;
            if(sum<0)
            {
                printf("Insufficient money\n");
                return;
            }
            sprintf(accountmanagment->accounts[i].balance,"%d",sum);
            count=1;
            temp=i;
        }
    }
    if(count==0)
    {
        printf("No account found\n");
        return;
    }
    printf("Your balance is %s\n",accountmanagment->accounts[temp].balance);
}
void Balance(AccountManagment *accountmanagment){

    printf("Enter the account number\n");
    char str[100];
    scanf(" %[^\n]",str);
    for(int i=0;i<accountmanagment->accountcount;i++)
    {
        if(strcmp(accountmanagment->accounts[i].account_num,str)==0)
        {
            printf("Account balance is:%s\n",accountmanagment->accounts[i].balance);
        }
    }
}
void closeAccount(AccountManagment *accountmanagment){

    char str1[20];
    int temp,count=0;
    printf("Enter the Account number:");
    scanf(" %[^\n]",str1);
    printf("\n-----------------------------------------------------------------\n");
    printf("%s. %s \t  %s  \t%s \n","sl.no","Account number","name","balance");
    printf("-----------------------------------------------------------------\n");
    for(int i=0;i<accountmanagment->accountcount;i++){
        if(strcmp(str1,accountmanagment->accounts[i].account_num)==0){
            printf("%d.%s \t  %s  \t%s \n",i,accountmanagment->accounts[i].account_num,accountmanagment->accounts[i].name,accountmanagment->accounts[i].balance);
            temp=i;
            count=1;
        }
    }
    if(count==0){
        printf("No account found\n");
        printf("-----------------------------------------------------------------\n");
        return;
    }
    printf("-----------------------------------------------------------------\n");

    printf("Confirm this account (Y|y)\n");
    char ch;
    scanf(" %c",&ch);
    if(ch=='Y' || ch=='y')
    {
        for(int i=temp;i<accountmanagment->accountcount;i++){
            accountmanagment->accounts[i]=accountmanagment->accounts[i+1];
        }
        accountmanagment->accountcount--;
    }

}
