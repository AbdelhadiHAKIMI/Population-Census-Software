#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <ctype.h>


 struct newinfovoid
 {

    char name[25];
    char familyname[25];
    int age;
    char address[25];
    int phonenumber;
    char wilaya[25];
    char email[25];
 }account[100];

void newaccount(int N);
void emptyarrays(int n);
void search(int n);
void searchbyname(int n);
int verification(int N);
void searchbyphone(int N);
void searchbymail(int N);
void displayall(int N);
void update(int N);
void deletes(int N);


int main()
{
    system("color 02");
    char choice[1];
    int n=100,i,N=1;
    char qna,yn;
    emptyarrays(n);
    menu:
    printf("\t\t\t\t-----------------------hello-----------------------\n");
    printf("\t\t\t\t-     Enter a number that matching your need      -\n");
    printf("\t\t\t\t- 1-create a new account.                         -\n");
    printf("\t\t\t\t- 2-Search for an availabale accout               -\n");
    printf("\t\t\t\t- 3-Edit account                                  -\n");
    printf("\t\t\t\t- 4-Display all users                             -\n");
    printf("\t\t\t\t- 5-Delete an account                             -\n");
    printf("\t\t\t\t- 6-Exit                                          -\n");
    printf("\t\t\t\t---------------------------------------------------\n");
    scanf("%s",&choice[1]);
    system("cls");
    switch (choice[1])
    {
    case '1':
    first: newaccount(N); N++;
  question:  printf("wanna enter another user?(y/n).");
    scanf(" %c",&qna);
    tolower(qna);
    if(qna=='y')
{
    sleep(2);
system("cls");
goto first;
}
else if(qna=='n'){
    sleep(2);
system("cls");
goto menu;}
    break;

    case '2':
        second: search(N);
    printf("wanna try again (y/n)");
    scanf(" %c",&yn);
    tolower(yn);
      if (yn=='y'){
            system("cls");
      goto second;
      }
      if (yn=='n'){
            system("cls");
        goto menu;
      }
    break;
    case '3':
        third: update(N);
    printf("wanna try again (y/n)");
    scanf(" %c",&yn);
    tolower(yn);
      if (yn=='y'){
            system("cls");
      goto third;
      }
      if (yn=='n'){
            system("cls");
        goto menu;
      }

        break;
    case '4':printf("User|\t\t\t|name|\t\t\t|family name|\n");
        displayall(N);
        sleep(2);
        printf("\n\n\n\n\n\nType 'M' to go to the menu:");
        scanf(" %c",&yn);
        toupper(yn);
        if(yn=='M'){
                system("cls");
            goto menu;
        }
        break;
    case '5':deletes(N);
    printf("The Account has been deleted");
    sleep(2);
    system("cls");
    goto menu;
    break;
    case '6':
        break;
    default: goto menu;
    }

    return 0;
}

void emptyarrays(int n){
for(int i=0;i<n;i++){
    strcpy(account[i].name,"name");
    strcpy(account[i].familyname,"secondname");
    account[i].age=0;
    account[i].phonenumber=0;
    strcpy(account[i].address,"address");
    strcpy(account[i].wilaya,"wilaya");
    strcpy(account[i].email,"email");
}}
void newaccount(int N){
    char temp[25];
for(int i=0;i<N;i++){

if(strcmpi(account[i].name,"name")==0){
        start:
 name1: printf("enter your name (type 'exit' to discard) :\t");
 scanf("%s",&account[i].name);
for(int j=0;j<strlen(account[i].name);j++){
    if (isalpha(account[i].name[j])==0){
            printf("\t\t\t\t\tOnly alpha are allowed");
    sleep(1);
            system("cls");
     goto name1;
    }
}
if(strcmpi(account[i].name,"exit")==0){
      strcpy(account[i].name,"name");
    break;

}
family1: printf("enter your family name (type 'exit' to discard) :\t");
 scanf("%s",&account[i].familyname);
 for(int j=0;j<strlen(account[i].familyname);j++){
    if (isalpha(account[i].familyname[j])==0){
            printf("\t\t\t\t\tOnly alpha are allowed");
    sleep(1);
            system("cls");
     goto family1;
    }
}
if(strcmpi(account[i].familyname,"exit")==0){
     strcpy(account[i].name,"name");
    strcpy(account[i].familyname,"secondname");
    break;

}
 age1: printf("enter your age:\t");
 scanf("%d",&account[i].age);
 if((account[i].age)>105 || (account[i].age)<10){
        printf("\t\t\t\t\tAge limit is from 10 to 105");
    sleep(1);
 system("cls");
    goto age1;
 }
 number: printf("enter your phone number :\t");
 scanf("%d",&account[i].phonenumber);
 if(verification(account[i].phonenumber)!=9){
     printf("\t\t\t\t\tphone number must include 9 numbers with no 0 at the start");
    sleep(2);
 system("cls");
    goto number;
 }
 int cp=0;
 for (int j=0;j<N;j++){
 if(account[i].phonenumber==account[j].phonenumber){
        cp++;}}
        if(cp>1){
    printf("\t\t\t\t\t\t\t\nThis Phone is already been used");
    sleep(2);
    system("cls");
    goto number;
        }

 printf("enter your address (type 'exit' to discard):\t");
 scanf("%s",account[i].address);
 if(strcmpi(account[i].address,"exit")==0){
      strcpy(account[i].name,"name");
    strcpy(account[i].familyname,"secondname");
    account[i].age=0;
    account[i].phonenumber=0;
    strcpy(account[i].address,"address");
    break;
}
 wilaya: printf("enter your wilaya (type 'exit' to discard):\t");
 scanf("%s",&account[i].wilaya);
 for(int j=0;j<strlen(account[i].wilaya);j++){
    if (isalpha(account[i].wilaya[j])==0){
        printf("\t\t\t\t\tOnly alpha is allowed");
    sleep(1);
            system("cls");
     goto wilaya;
    }
}
if(strcmpi(account[i].wilaya,"exit")==0){
     strcpy(account[i].name,"name");
    strcpy(account[i].familyname,"secondname");
    account[i].age=0;
    account[i].phonenumber=0;
    strcpy(account[i].address,"address");
    strcpy(account[i].wilaya,"wilaya");
    break;
}
mail: printf("enter your email (type 'exit' to discard):\t");
 scanf("%s",&account[i].email);
 cp=0;
for (int j=0;j<N;j++){
 if(strcmpi(account[i].email,account[j].email)==0){
        cp++;}}
        if(cp>1){
    printf("\t\t\t\t\t\t\t\nThis Email is already been used");
    sleep(2);
    system("cls");
    goto mail;
        }
        if(strcmpi(account[i].email,"exit")==0){
             strcpy(account[i].name,"disname");
    strcpy(account[i].familyname,"secondname");
    account[i].age=0;
    account[i].phonenumber=0;
    strcpy(account[i].address,"address");
    strcpy(account[i].wilaya,"wilaya");
    strcpy(account[i].email,"email");
    break;
}

}

}
}


void search(N){
    int search;
    char searchname[25],searchsurename[25];
    printf("\t\t\t\t-----------------------hello-----------------------\n");
    printf("\t\t\t\t-     Enter a number that matching your need      -\n");
    printf("\t\t\t\t- 1-Search using name and family name             -\n");
    printf("\t\t\t\t- 2-Search using phone number                     -\n");
    printf("\t\t\t\t- 3-Search using email                            -\n");
    printf("\t\t\t\t- 4- Exit to menu                                 -\n");
    printf("\t\t\t\t---------------------------------------------------\n");
scanf("%d",&search);
system("cls");
switch(search){
case 1: searchbyname(N);
break;
case 2:searchbyphone(N);
break;
case 3:searchbymail(N);
    break;
case 4: break;


}}

void searchbyname(int N){
    char searchname[25];
    char searchsurname[25];
     int firstchoice,cp=0;

    printf("Enter name of the user you want to search for:\n");
    scanf("%s",&searchname);
    printf("Enter family name of the user you want to search for:\n");
    scanf("%s",&searchsurname);
    for(int i=0;i<N;i++){
     if((strcmpi(account[i].name,searchname)==0) && (strcmpi(account[i].familyname,searchsurname)==0)){
            cp++;
                printf("\t\t\t\t\tUser has been found!!!\n");
                sleep(2);
                system("cls");
    printf("\t\t\t\t-----------------------hello-----------------------\n");
    printf("\t\t\t\t-     Enter a number that matching your need      -\n");
    printf("\t\t\t\t- 1-Search for age                                -\n");
    printf("\t\t\t\t- 2-Search for phone number                       -\n");
    printf("\t\t\t\t- 3-Search for address and email                  -\n");
    printf("\t\t\t\t- 4-Search for everything                         -\n");
    printf("\t\t\t\t- 5- Exit to menu                                 -\n");
    printf("\t\t\t\t---------------------------------------------------\n");

    scanf("%d",&firstchoice);
      system("cls");
      switch(firstchoice){

  case 1:
   printf("User:%s %s\n",account[i].name,account[i].familyname);
    printf("age:%d\n",account[i].age);
    sleep(2);

 break;
  case 2:
     printf("User:%s %s\n",account[i].name,account[i].familyname);
    printf("Phone Number :%d\n",account[i].phonenumber);
sleep(2);
    break;
  case 3:
    printf("User:%s %s\n",account[i].name,account[i].familyname);
    printf(" Email  :%s\n",account[i].email);
    printf("Address:%s\n",account[i].address);
sleep(2);
    break;

  case 4:
    printf("User:%s %s\n",account[i].name,account[i].familyname);
    printf("Age:%d\n",account[i].age);
    printf("User Phone Number is :%d\n",account[i].phonenumber);
    printf("Address:%s\n",account[i].address);
    printf("Wilaya:%s\n",account[i].wilaya);
    printf("User Email is :%s\n",account[i].email);
    Sleep(2);
    break;
  case 5:
    break;
      }
      }
    }
    if (cp==0){
        printf("\t\t\t\t\tThe user Doesn't Exist");
      sleep(2);
      system("cls");
    }
    if(cp>1){
        printf("\t\t\t\t\tThere more then one account with this infos\n");
        printf("\t\t\t\t\tChoose a different way of searching\n");
        sleep(2);
        system("cls");

    }
}
void searchbyphone(int N){
    int searchphone;
     int firstchoice;
     int cp=0;

    printf("Enter Phone number of the user you want to search for:\n");
    scanf("%d",&searchphone);
    for(int i=0;i<N;i++){
     if(account[i].phonenumber==searchphone){
            cp++;
                printf("\t\t\tUser has been found!!!\n");
                sleep(2);
                system("cls");
    printf("\t\t\t\t-----------------------hello-----------------------\n");
    printf("\t\t\t\t-     Enter a number that matching your need      -\n");
    printf("\t\t\t\t- 1-Search for age                                -\n");
    printf("\t\t\t\t- 2-Search for Name and family name               -\n");
    printf("\t\t\t\t- 3-Search for address and email                  -\n");
    printf("\t\t\t\t- 4-Search for everything                         -\n");
    printf("\t\t\t\t---------------------------------------------------\n");

    scanf("%d",&firstchoice);
      system("cls");
      switch(firstchoice){

  case 1:
      printf("User :%d\n",account[i].phonenumber);
    printf("age:%d\n",account[i].age);
    sleep(2);

 break;
  case 2:
      printf("User:%d\n",account[i].phonenumber);
     printf("User name and family name :%s %s\n",account[i].name,account[i].familyname);
sleep(2);
    break;
  case 3:
      printf("User:%d\n",account[i].phonenumber);
    printf(" Email  :%s",account[i].email);
    printf("Address:%s\n",account[i].address);
sleep(2);
    break;

  case 4:
    printf("User:%d\n",account[i].phonenumber);
    printf("User name and family name :%s %s\n",account[i].name,account[i].familyname);
    printf("Age:%d\n",account[i].age);
    printf("Address:%s\n",account[i].address);
    printf("Wilaya:%s\n",account[i].wilaya);
    printf("User Email is :%s\n",account[i].email);
    Sleep(2);
      }
      }
    }
    if (cp==0){
        printf("\t\t\t\t\tThe user Doesn't Exist");
      Sleep(2);
      system("cls");
    }
}
int verification(int N){
   int cp=0;
while(N!=0){
    N/=10;
    cp++;
} return cp;
}
void searchbymail(int N){
char searchmail[25];
     int firstchoice,cp=0;
    printf("Enter Email of the user you want to search for:\n");
    scanf("%s",&searchmail);
    for(int i=0;i<N;i++){
     if((strcmpi(account[i].email,searchmail)==0)){
            cp++;
                printf("\t\t\tUser has been found!!!\n");
                sleep(2);
                system("cls");
    printf("\t\t\t\t-----------------------hello-----------------------\n");
    printf("\t\t\t\t-     Enter a number that matching your need      -\n");
    printf("\t\t\t\t- 1-Search for age                                -\n");
    printf("\t\t\t\t- 2-Search for phone number                       -\n");
    printf("\t\t\t\t- 3-Search for name and family name               -\n");
    printf("\t\t\t\t- 4-Search for everything                         -\n");
    printf("\t\t\t\t---------------------------------------------------\n");

    scanf("%d",&firstchoice);
      system("cls");
      switch(firstchoice){

  case 1:
      printf("User :%s\n",account[i].email);
    printf("age:%d\n",account[i].age);
    sleep(2);

 break;
  case 2:
      printf("User :%s\n",account[i].email);
    printf("Phone Number :%d",account[i].phonenumber);
sleep(2);
    break;
  case 3:
      printf("User :%s\n",account[i].email);
    printf("User name nd family name:%s %s\n",account[i].name,account[i].familyname);
sleep(2);
    break;

  case 4:
      printf("User :%s\n",account[i].email);
    printf("User name nd family name:%s %s\n",account[i].name,account[i].familyname);
    printf("Age:%d\n",account[i].age);
    printf("User Phone Number is :%d\n",account[i].phonenumber);
    printf("Address:%s\n",account[i].address);
    printf("Wilaya:%s\n",account[i].wilaya);

    Sleep(2);
      }
      }

      }
      if (cp==0){
        printf("\t\t\t\t\tThe user Doesn't Exist");
      sleep(2);
      system("cls");
    }
    }
void displayall(int N){
for(int i=0;i<N;i++){

    printf("%d   |\t\t\t|%s|\t\t\t| %s|\n",i+1,account[i].name,account[i].familyname);



}
}
void update(int N){

 char searchname[25];
    char searchsurname[25];
    int searchphone;
     int firstchoice,cp=0;

    printf("Enter name of the user you want to update:\n");
    scanf("%s",&searchname);
    printf("Enter family name of the user you want to update\n");
    scanf("%s",&searchsurname);
    printf("Enter phone number of the user you want to update\n");
    scanf("%d",&searchphone);
    for(int i=0;i<N;i++){
     if((strcmpi(account[i].name,searchname)==0) && (strcmpi(account[i].familyname,searchsurname)==0)&& account[i].phonenumber==searchphone){
    cp++;
      printf("\t\t\t\t\tUser has been found!!!\n");
                sleep(2);
                system("cls");
    printf("\t\t\t\t-----------------------hello-----------------------\n");
    printf("\t\t\t\t-     Enter a number that matching your need      -\n");
    printf("\t\t\t\t- 1-Update  age                                   -\n");
    printf("\t\t\t\t- 2-Update  phone number                          -\n");
    printf("\t\t\t\t- 3-Update  email                                 -\n");
    printf("\t\t\t\t- 4-Update  address                               -\n");
    printf("\t\t\t\t- 5-Update  Name                                  -\n");
    printf("\t\t\t\t- 6-Update  Family name                           -\n");
    printf("\t\t\t\t---------------------------------------------------\n");

    scanf("%d",&firstchoice);
      system("cls");
      switch(firstchoice){

  case 1:
         age1: printf("Enter  new age :");
          scanf("%d",&account[i].age);
         if((account[i].age)>105 || (account[i].age)<10){
        system("cls");
        goto age1;
    }
    sleep(2);

 break;
  case 2:   number: printf("enter your new phone number :\t");
            scanf("%d",&account[i].phonenumber);
            if(verification(account[i].phonenumber)!=10){
            system("cls");
            goto number;
            }

sleep(2);
    break;
        case 3: printf("enter your email:\t");
 scanf("%s",&account[i].email);

sleep(2);
    break;
    case 4:printf("enter your address:\t");
 scanf("%s",account[i].address);
  break;
  case 5:name1: printf("enter your name:\t");
 scanf("%s",&account[i].name);
for(int j=0;j<strlen(account[i].name);j++){
    if (isalpha(account[i].name[j])==0){
            system("cls");
     goto name1;
    }
}
    break;
    case 6:family1: printf("enter your family name:\t");
 scanf("%s",&account[i].familyname);
 for(int j=0;j<strlen(account[i].familyname);j++){
    if (isalpha(account[i].familyname[j])==0){
            system("cls");
     goto family1;
    }
    break;

 }
      }


      }

    }
      if (cp==0){
        printf("\t\t\t\t\tThe user Doesn't Exist");
      sleep(2);
      system("cls");
    }

 }
void deletes(int N){
 char searchname[25];
    char searchsurname[25];
    int searchphone;
     int i,cp=0;

    printf("Enter name of the account you want to delete:\n");
    scanf("%s",&searchname);
    printf("Enter family name of the account you want to delete\n");
    scanf("%s",&searchsurname);
    printf("Enter phone number of the account you want to delete\n");
    scanf("%d",&searchphone);
     for(i=0;i<N;i++){
     if((strcmpi(account[i].name,searchname)==0) && (strcmpi(account[i].familyname,searchsurname)==0)&&account[i].phonenumber==searchphone){
            cp++;
        printf("\t\t\t\t\tUser has been found!!!\n");
                sleep(2);
                system("cls");
        strcpy(account[i].name,"delname");
    strcpy(account[i].familyname,"secondname");
    account[i].age=0;
    account[i].phonenumber=0;
    strcpy(account[i].address,"address");
    strcpy(account[i].wilaya,"wilaya");
    strcpy(account[i].email,"email");
                }
     }
      if (cp==0){
        printf("\t\t\t\t\tThe user Doesn't Exist");
      sleep(2);
      system("cls");
    }

}








