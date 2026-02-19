#include<stdio.h>
#include "file.h"

void savedetailsToFile(AccountManagment *accountmanagment){
    FILE *fp;
    if((fp=fopen("details.csv","w"))==NULL)
    {
        fprintf(stderr,"file not found\n");
        return;
    }
    for(int i=0;i<accountmanagment->accountcount;i++){
        fprintf(fp,"%s,%s,%s\n",accountmanagment->accounts[i].account_num,accountmanagment->accounts[i].name,accountmanagment->accounts[i].balance);
    }
 fclose(fp);

}
void loaddetailsFromFile(AccountManagment *accountmanagment){
  
    FILE *fp;
    if((fp=fopen("details.csv","r"))==NULL)
    {
        fprintf(stderr,"file not found\n");
        return;
    }
    
    while(accountmanagment->accountcount < MAX_ACCOUNTS && (fscanf(fp,"%[^,],%[^,],%[^\r\n] ",accountmanagment->accounts[accountmanagment->accountcount].account_num,accountmanagment->accounts[accountmanagment->accountcount].name,accountmanagment->accounts[accountmanagment->accountcount].balance))==3){
        accountmanagment->accountcount++;
    }
    fclose(fp);
}
