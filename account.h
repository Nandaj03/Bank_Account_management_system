#ifndef ACCOUNT_H
#define ACCOUNT_H

#define MAX_ACCOUNTS 100

typedef struct {
    char account_num[20];
    char name[20];
    char balance[100];
}Account;
    
typedef struct{
    Account accounts[100];
    int accountcount;
}AccountManagment;

void initialize(AccountManagment *accountmanagment);
void createAccount(AccountManagment *accountmanagment);
void Deposit_money(AccountManagment *accountmanagment);
void Withdraw_money(AccountManagment *accountmanagment);
void Balance(AccountManagment *accountmanagment);
void closeAccount(AccountManagment *accountmanagment);
long long generate_Account_num();

#endif