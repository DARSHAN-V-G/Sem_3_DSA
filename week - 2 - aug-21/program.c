#include<stdio.h>
#include<string.h>
int main(){
    FILE *f = fopen("E:\\c_files_banking\\details.txt","r");
    if(f==NULL){
        printf("error");
    }
    char name[20][30],pass[20][10],acc_no[20][10],balance[20][10];
    int size;
    char word[30];
    fscanf(f,"%d",&size);
    fgetc(f);
    for(int i=0;i<size;i++){
        fscanf(f,"%[^' ']s",name[i]);
        fgetc(f);
        fscanf(f,"%[^' ']s",pass[i]);
        fgetc(f);
        fscanf(f,"%[^' ']s",acc_no[i]);
        fgetc(f);
        fscanf(f,"%[^\n]s",balance[i]);
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
        scanf("%s",name[size]);
        for(int i=0;i<size;i++){
            if(strcmp(name[i],name[size])==0){
                printf("Username already exists!\n");
                goto name;
            }
        }
        printf("Password : ");
        scanf("%s",pass[size]);
        acc:
        printf("Account number : ");
        scanf("%s",acc_no[size]);
        for(int i=0;i<size;i++){
            if(strcmp(acc_no[i],acc_no[size])==0){
                printf("Account number already exists!");
                goto acc;
            }
        }
        printf("Account created with Zero balance.\n");
        strcpy(balance[size], "0.0");
        size++;
        goto branch;
        break;
    case 2:
        printf("Enter User name : ");
        scanf("%s",word);
        ptr=-1;
        for(int i=0;i<size;i++){
            if(strcmp(word,name[i])==0){
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
        if(strcmp(word,pass[ptr])!=0){
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
            if(temp > atof(balance[ptr])){
                printf("Insufficient Balance");
                goto repeat;
            }
            temp = atof(balance[ptr])-temp;
            sprintf(balance[ptr], "%f", temp);
            printf("Amount Debited Successfully !\n New Balance = %s",balance[ptr]);
            break;
        case 4:
            printf("Enter amount to be credited : ");
            scanf("%f",&temp);
            temp = atof(balance[ptr])+temp;
            sprintf(balance[ptr], "%f", temp);
            printf("Amount Debited Successfully !\n New Balance = %s",balance[ptr]);
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
    FILE *fi = fopen("E:\\c_files_banking\\details.txt","w");
    fprintf(fi,"%d\n",size);
    for(int i=0;i<size;i++){
        fprintf(fi,"%s %s %s %s\n",name[i],pass[i],acc_no[i],balance[i]);
    }
    return 0;
}