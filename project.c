#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void generate_bill(char name[], char date[])
{
  printf("\n");
  printf("\n");
  printf("-----------------------------GROCERY SHOP----------------------------- \n");
  printf("\n");
  printf("                 Sardar Singh Road, Near Bus Stand\n");
  printf("                      Bathinda, Punjab, 151001\n");
  printf("                   Ph: 98790- 78965, 98764- 90876\n");
  printf("\n");
  printf("\n");
  printf("DATE:\t%s", date);
  printf("\nCUSTOMER NAME:%s\t\n", name);
  printf("\n");
  printf("-------------------------------------------------------------------------------------- \n");
  printf("ITEM\t\tQUANTITY\t\tPRICE\t\tGST(percentage)\t\tTOTAL\n");
  printf("-------------------------------------------------------------------------------------- \n");
}

void generate_bill_body(int n, char item[][20], float price[], int quantity[], int gst[])
{
  for (int i = 0; i < n; i++)
  {
    printf("%s\t\t", item[i]);
    printf("%d\t\t\t", quantity[i]);
    printf("%.2f\t\t\t", price[i] * quantity[i]);
    printf("%d\t\t", gst[i]);
    printf("%.2f\t\t\t", price[i] * quantity[i] + price[i] * quantity[i] * gst[i] * 0.01);
    printf("\n");
  }
}

void generate_bill_footer(int n, float price[], int quantity[], int gst[], int method)
{
  printf("-------------------------------------------------------------------------------------- \n");
  float total = 0;
  for (int i = 0; i < n; i++)
  {
    total = total + price[i] * quantity[i] + price[i] * quantity[i] * gst[i] * 0.01;
  }

  printf("TOTAL: \t\t\t\t\t\t\t\t %.2f", total);
  printf("\n");
  printf("\n");
  printf("\n");

  printf("                                             NET TO PAY:%.2f\n", total);
  if (method == 1)
  {
    printf("PAYEMENT METHOD: CASH ");
  }
  if (method == 2)
  {
    printf("PAYMENT METHOD: ONLINE");
  }
  printf("\n");
  printf("\n");
  printf("\n");
  printf("\n");
  printf("==================     THANK YOU FOR SHOPPING WITH US  ==================\n");
  printf("                              PLEASE VISIT AGAIN");
  printf("\n");
  printf("\n");
}

void bill_save(FILE *fp, char name[], char date[], int n, char item[][20], float price[], int quantity[], int gst[])
{
  fprintf(fp, "%s", "DATE:\t");
  fputs(date, fp);
  fprintf(fp, "%s", "\nCUSTOMER NAME:\t");
  fputs(name, fp);
  fprintf(fp, "%s", "\n--------------------------------------------------------------------------------------\n ");
  fprintf(fp, "%s", "ITEM\t\tQUANTITY\t\tPRICE\t\tGST(percentage)\t\tTOTAL\n");
  fprintf(fp, "%s", "-------------------------------------------------------------------------------------- \n");

  for (int i = 0; i < n; i++)
  {
    fprintf(fp, "%s\t\t", item[i]);
    fprintf(fp, "%d\t\t", quantity[i]);
    fprintf(fp, "%.2f\t\t", price[i] * quantity[i]);
    fprintf(fp, "%d\t\t", gst[i]);
    fprintf(fp, "%.2f\n", price[i] * quantity[i] + price[i] * quantity[i] * gst[i] * 0.01);
  }
  float total = 0;
  for (int i = 0; i < n; i++)
  {
    total = total + price[i] * quantity[i] + price[i] * quantity[i] * gst[i] * 0.01;
  }
  fprintf(fp, "%s", "-------------------------------------------------------------------------------------- \n");
  fprintf(fp, "%s", "TOTAL: \t\t\t\t\t\t\t\t ");
  fprintf(fp, "%.2f\n", total);

  fprintf(fp, "%s", "\n");
  fprintf(fp, "%s", "\n");
}

int main()
{
  int method;
  char name[30], date[20];
  int quantity[50];
  float price[50];
  fflush(stdin);
  int choice;
  FILE *fp = NULL;
  char save_bill;
  char pass[3],ch;
  printf("\t\t\tPlease enter the password:\n");
  for (int i = 0; i < 3; i++)
  {
    ch = getch();
  pass[i] = ch;
  ch = '*' ;
  printf("%c",ch);
  }

  if (pass[0] == 'r' && pass[1] == 'r' && pass[2] == 'r')
  {
    system("cls");
    printf("\t\t\t\t\t------------------- SHOP------------------- \n");

    printf("\n");
    printf("\t\t\t\t\t================== MAIN PAGE ================== ");
    printf("\n\t\t\t1. Generate Invoice\n");
    printf("\t\t\t2. Show all Invoice(cash/ online)\n");
    printf("\t\t\t3. Show all Invoice(credit)\n");
    printf("\t\t\t4. Search\n ");
    printf("\t\t\t5. Delete\n");
    printf("\t\t\t6. Exit\n");
    printf("\t\t\tPlease select your choice:\t");
    scanf("\t\t\t%d", &choice);
    char item[50][20];
    int n, gst[50], total[50];
    system("cls");

    char exit = 'n';
    if (choice == 1)
    {
      while (exit == 'n')
      {
        printf("\t\t\tEnter date\t");
        scanf("\n\t\t\t%[^\n]", &date);
        printf("\t\t\tCustomer Name:\t");
        scanf("\n\t\t\t%[^\n]", &name);
        printf("\t\t\tEnter The Number of Items:\t");
        scanf("\t\t%d", &n);

        char items[n][20];
        int money;
        printf("\t\t\tEnter The Items:\n");

        for (int i = 0; i < n; i++)
        {
          printf("\t\t\tPlease Enter Item %d:\t", i + 1);
          scanf("\n\t\t\t%[^\n]", &item[i]);
          printf("\t\t\tPlease Enter the Quantity in standard units (piece/pkts/weight):\t");
          scanf("\t\t\t%d", &quantity[i]);
          printf("\t\t\tPlease Enter price for Unit quantity:\t");
          scanf("\t\t%f", &price[i]);
          printf("\t\t\tPlease enter the gst percentage :\t");
          scanf("\t\t%d", &gst[i]);
        }
        printf("\t\t\tEnter the method of payment:\n");
        printf("\t\t\t1. Cash\n");
        printf("\t\t\t2. online\n ");
        printf("\t\t\t3. Credit\n");
        scanf("\t\t\t%d", &method);
        generate_bill(name, date);

        generate_bill_body(n, item, price, quantity, gst);
        generate_bill_footer(n, price, quantity, gst, method);
        printf("\n\t\t\tDo you want to save the bill(y/n):\t");
        scanf("\n\t\t\t%c", &save_bill);

    FILE *fp2;
        if (save_bill == 'y')
        {
          if (method == 1 || method == 2)
          {
              
            fp = fopen("cash.txt", "a+");
            fp2 = fopen(name, "a+");
            
            bill_save(fp, name, date, n, item, price, quantity, gst);
            if (method == 1)
            {
              fprintf(fp, "\t\t%s", "PAYEMENT METHOD: CASH\n ");
            }
            if (method == 2)
            {
              fprintf(fp, "\t\t%s", "PAYMENT METHOD: ONLINE\n");
            }
            fprintf(fp, "\t\t\t%s", "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n");
            fprintf(fp, "\t\t\t%s", "\n");
            fprintf(fp, "\t\t\t%s", "\n");

            bill_save(fp2, name, date, n, item, price, quantity, gst);
            if (method == 1)
            {
              fprintf(fp2, "\t\t\t%s", "PAYEMENT METHOD: CASH\n ");
            }
            if (method == 2)
            {
              fprintf(fp2, "\t\t\t%s", "PAYMENT METHOD: ONLINE\n");
            }
            fprintf(fp2, "\t\t\t%s", "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n");
            fprintf(fp2, "\t\t\t%s", "\n");
            fprintf(fp2, "\t\t\t%s", "\n");
            fclose(fp);
            fclose(fp2);
          }
        }
        if (method == 3)
        {
          fp = fopen("credit.txt", "a+");
          fp2 = fopen(name, "a+");
          bill_save(fp, name, date, n, item, price, quantity, gst);
          fprintf(fp, "\t\t\t%s", "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n");
          fprintf(fp, "\t\t\t%s", "\n");
          fprintf(fp, "\t\t\t%s", "\n");

          bill_save(fp2, name, date, n, item, price, quantity, gst);
          fprintf(fp2, "\t\t\t%s", "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n");
          fprintf(fp2, "\t\t\t%s", "\n");
          fprintf(fp2, "\t\t\t%s", "\n");
          fclose(fp);
          fclose(fp2);
        }

        printf("\t\t\texit? (y/n)\n");
        scanf("\n\t\t%c:", &exit);
        system("cls");
      }
    }

    char str[1000000];

    if (choice == 2)
    {
      fp = fopen("cash.txt", "r");
      printf("\t\t******************** Your Previous CASH Invoice ******************** \n");
      if (fp == NULL)
      {
        printf("\t\t\tno data");
      }
      while (!feof(fp)) // feof = file end of file , predefined in stdio.h
      {
        fgets(str, 10000, fp);
        printf("\t\t\t%s", str);
      }
    }
    
    if (choice == 3)
    {
      fp = fopen("credit.txt", "r");
      printf("\t******************** Your Previous CREDIT Invoice ******************** \n");
      if (fp == NULL)
      {
        printf("\t\t\tno data");
      }
      while (!feof(fp)) // feof = file end of file , predefined in stdio.h
      {
        fgets(str, 10000, fp);
        printf("\t\t\t%s", str);
      }
    }
    char search[20];

if (choice == 4)
{printf("\t\t\tEnter the name to be searched:");
  scanf("\n\t\t%[^\n]", &search);
  system("cls");
  fp = fopen(search, "r");
  
 if (fp == NULL)
      {
        printf("\t\t\tno data");
      }
      while (!feof(fp)) 
      {
        fgets(str, 10000, fp);
        printf("\t\t\t%s", str);
      }

fclose(fp);
}
char delete[20];
if (choice == 5)
{
  printf("\t\t\tWho's data do you want to delete?");
   scanf("\n\t\t\t%[^\n]", &delete);
   remove(delete);
   printf("\t\t\tThe data has been succesfully deleted\n");
}

   if (choice == 6)
     {
       return 0;
     }

    if (choice > 6)
    {
      printf("\t\t\tEnter valid choice");
    }
  }
  else
  {
    printf("\t\txxxxxxxxxx WRONG PASSWORD xxxxxxxxxx");
  }
  

  return 0;
}