#include<stdio.h>
#include<string.h>
struct People
{
    char fname[20];
    char lname[20];
    char number[20];
    char email_id[40];
    char address[40];
};
FILE *ptr,*ptr2;
void create_contact()
{
    struct People contact;
    system("cls");
    fflush(stdin);
    printf("First Name= ");
    gets(contact.fname);
    printf("Last Name= ");
    gets(contact.lname);

    printf("Mobile Number= ");
    gets(contact.number);
    while(strlen(contact.number) !=11)
    {
        printf("Enter 11 digit number= ");
        gets(contact.number);
    }
    printf("E-mail Address= ");
    gets(contact.email_id);
    printf("Address(Area)= ");
    gets(contact.address);

    ptr=fopen("Phone_Management.txt","a");
    fprintf(ptr,"%s\n",contact.fname);
    fprintf(ptr,"%s\n",contact.lname);
    fprintf(ptr,"%s\n",contact.number);
    fprintf(ptr,"%s\n",contact.email_id);
    fprintf(ptr,"%s\n\n",contact.address);
    fclose(ptr);
    system("cls");
    main();
}
void search_name()
{
    struct People contact_temp[100];
    char name1[20];
    int i,y,flag=0;
    printf("First Name: ");
    fflush(stdin);
    gets(name1);
    ptr2=fopen("Phone_Management.txt","r");
    for(i=0;i<60;i++)
    {
        fscanf(ptr2,"%s",contact_temp[i].fname);
        fscanf(ptr2,"%s",contact_temp[i].lname);
        fscanf(ptr2,"%s",contact_temp[i].number);
        fscanf(ptr2,"%s",contact_temp[i].email_id);
        fscanf(ptr2,"%s",contact_temp[i].address);
        fflush(stdin);
        }
        for(i=0;i<60;i++)
        {
            y=strcmp(contact_temp[i].fname,name1);
            if(y==0)
            {
                printf("\n\nFirst Name: %s\n",contact_temp[i].fname);
                printf("Second Name: %s\n",contact_temp[i].lname);
                printf("Mobile Number: %s\n",contact_temp[i].number);
                printf("E-mail: %s\n",contact_temp[i].email_id);
                printf("Address: %s\n",contact_temp[i].address);
                flag=1;
            }
        }
        if(flag==0)
                printf("\nCONTACT NOT FOUND");
        printf("\n\nEnter any digit to go to the Main Menu=");
        scanf("%d",&y);
        system("cls");
        main();

        fclose(ptr2);
}
void search_number()
{
    struct People contact_temp[100];
    char number1[20];
    int i,y,flag=0;
    printf("Mobile Number: ");
    fflush(stdin);
    gets(number1);
    ptr2=fopen("Phone_Management.txt","r");
    for(i=0;i<60;i++)
    {
        fscanf(ptr2,"%s",contact_temp[i].fname);
        fscanf(ptr2,"%s",contact_temp[i].lname);
        fscanf(ptr2,"%s",contact_temp[i].number);
        fscanf(ptr2,"%s",contact_temp[i].email_id);
        fscanf(ptr2,"%s",contact_temp[i].address);
        fflush(stdin);
        }
        for(i=0;i<60;i++)
        {
            y=strcmp(contact_temp[i].number,number1);
            if(y==0)
            {
                printf("\n\nFirst Name: %s\n",contact_temp[i].fname);
                printf("Second Name: %s\n",contact_temp[i].lname);
                printf("Mobile Number: %s\n",contact_temp[i].number);
                printf("E-mail: %s\n",contact_temp[i].email_id);
                printf("Address: %s\n",contact_temp[i].address);
                flag=1;
            }
        }
        if(flag==0)
                printf("\nCONTACT NOT FOUND");
        printf("\n\nEnter any digit to go to the Main Menu=");
        scanf("%d",&y);
        system("cls");
        main();
        fclose(ptr2);
}
void view_all_contact()
{
    int y;
    system("cls");
    ptr=fopen("Phone_Management.txt","r");
    char view[1000];
    while(!feof(ptr))
    {
        fgets(view,1000,ptr);
        puts(view);
    }
    fclose(ptr);
    printf("Enter any digit to go to the Main Menu=");
    scanf("%d",&y);
    system("cls");
    main();
}
void exit_()
{
    exit(0);
}
void help()
{
    int x;
    system("cls");
    printf("Pressing 1, you can Create a New Contact.\n\n");
    printf("Pressing 2, you can Search the Contact you have Saved Before,\n");
    printf("You can Search any contact By Name or By Number.\n\n");
    printf("Pressing 3, you can View the Contact List.\n\n");
    printf("Pressing 4, you can Exit the Program.\n");
    printf("\n\nEnter any digit to go to the Main Menu=");
    scanf("%d",&x);
    main();
}
int main()
{
    system("color e1");
    struct People contact,contact_temp[100];
    printf("\n\t\tC O N T A C T  M A N A G E M E N T\n\n");
    printf("x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x\n\n");
    printf("\t\t(1) Create Contact\n");
    printf("\t\t(2) Search Contact\n");
    printf("\t\t(3) View All Contact\n");
    printf("\t\t(4) Exit\n");
    printf("\t\t(5) Help?\n");

    int n,x;

    printf("\nCHOICE= ");
    scanf("%d",&n);

    switch(n)
    {
        case 1:
            create_contact();
            break;
        case 2:
            system("cls");
            printf("(1) Search By First Name\n");
            printf("(2) Search By Number\n");
            scanf("%d",&x);
            system("cls");
            switch(x)
            {
            case (1):
                search_name();
                break;
            case (2):
                search_number();
                break;
            default:
                printf("Enter correctly");
                main();
                break;
            }
            break;
        case 3:
            view_all_contact();
            break;
        case 4:
            exit_();
            break;
        case 5:
            help();
            break;
        default:
            printf("Enter Correctly");
            system("cls");
            main();
            break;
       }
}

