#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct details{
    char name[30];
    char pass[10];
    char acc_no[10];
    char balance[10];
}details;
int main(){
    FILE *f = fopen("E:\\c_files_banking\\details.txt","r");
    if(f==NULL){
        printf("error");
    }
    int size;
    char word[30];
    fscanf(f,"%d",&size);
    fgetc(f);
    details *det = (details*)malloc(sizeof(details)*(size+1));
    for(int i=0;i<size;i++){
        fscanf(f,"%[^' ']s",det[i].name);
        fgetc(f);
        fscanf(f,"%[^' ']s",det[i].pass);
        fgetc(f);
        fscanf(f,"%[^' ']s",det[i].acc_no);
        fgetc(f);
        fscanf(f,"%[^\n]s",det[i].balance);
        fgetc(f);
    }
    branch :
    printf("1.New User - Register\n2.Existing user - Login\n3.Exit\n");
    int choice;
    int ptr;
    scanf("%d",&choice);
    switch (choice)
    {
    case 1:
        name : 
        printf("Username : ");
        scanf("%s",det[size].name);
        for(int i=0;i<size;i++){
            if(strcmp(det[i].name,det[size].name)==0){
                printf("Username already exists!\n");
                goto name;
            }
        }
        printf("Password : ");
        scanf("%s",det[size].pass);
        acc:
        printf("Account number : ");
        scanf("%s",det[size].acc_no);
        for(int i=0;i<size;i++){
            if(strcmp(det[i].acc_no,det[size].acc_no)==0){
                printf("Account number already exists!");
                goto acc;
            }
        }
        printf("Account created with Zero balance.\n");
        strcpy(det[size].balance, "0.0");
        size++;
        ptr=size;
        goto repeat;
        break;
    case 2:
        printf("Enter User name : ");
        scanf("%s",word);
        ptr=-1;
        for(int i=0;i<size;i++){
            if(strcmp(word,det[i].name)==0){
                ptr=i;
                break;
            }
        }
        if(ptr==-1){
            printf("Invalid username .");
            break;
        }
        printf("Enter Password : ");
        scanf("%s",word);
        if(strcmp(word,det[ptr].pass)!=0){
            printf("Invalid Password");
            break;
        }
        printf("Login Successful !\n");
        repeat:
        printf("3.Debit\n4.Credit\n5.Log out\n");
        int c;
        float temp;
        scanf("%d",&c);
        switch (c)
        {
        case 3:
            printf("Enter amount to be debited : ");
            scanf("%f",&temp);
            if(temp > atof(det[ptr].balance)){
                printf("Insufficient Balance\n");
                goto repeat;
            }
            temp = atof(det[ptr].balance)-temp;
            sprintf(det[ptr].balance, "%f", temp);
            printf("Amount Debited Successfully !\n New Balance = %s",det[ptr].balance);
            break;
        case 4:
            printf("Enter amount to be credited : ");
            scanf("%f",&temp);
            temp = atof(det[ptr].balance)+temp;
            sprintf(det[ptr].balance, "%f", temp);
            printf("Amount Debited Successfully !\n New Balance = %s",det[ptr].balance);
            break;
        case 5:
            printf("Logging out...!\n");
            goto branch;
        default:
            printf("Invalid option.");
            goto repeat;
            break;
        }
    case 3:
    break;
    default:
        printf("Invalid  Choice.");
        goto branch;
        break;
    }

fclose(f);
FILE *fi = fopen("E:\\c_files_banking\\details.txt", "w");
if (fi == NULL) {
    printf("Error opening file for writing\n");
    return 1;
}
fprintf(fi, "%d\n", size);
for (int i = 0; i < size; i++) {
    fprintf(fi, "%s %s %s %s\n", det[i].name, det[i].pass, det[i].acc_no, det[i].balance);
}
fclose(fi);
return 0;
}