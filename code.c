#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <conio.h>
#include <dos.h>

#define TEST
#undef TEST
#define SAFE
#undef SAFE

#define M 10
#define MAX(a,b) (((a) > (b))? (a) : (b))
#define MIN(a,b) (((a) < (b))? (a) : (b))
#define MAXN(a,b,c) MAX(a,MAX(b,c))
#define MINN(a,b,c) MIN(a,MIN(b,c))
#define STREQ(s1,s2) (strcmp((s1),(s2)) == 0)

#ifdef SAFE
enum months {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
struct Salary_Info
{
   int card_no;                   //Salary card number
   char name[20];                 //Employee name
   int month;                     //Month
   float init_salary;               //Initial salary
   float water_rate;
   float electric_rate;
   float tax;
   float final_salary;
};
#endif // SAFE

struct Salary_Info
{
   int card_no;                   //Salary card number
   char name[20];                 //Employee name
   int month;                     //Month
   float init_salary;               //Initial salary
   float water_rate;
   float electric_rate;
   float tax;
   float final_salary;
};            //each element in array SI[MAX] is a record of an employee salary information.

 typedef struct Salary_Info record;
 	record si[M];

void input (FILE *p, record x[]);

void list (FILE *p, record x[]);

void sort (FILE *p, record x[]);

void inquiry (FILE *p, record x[]);

void report (FILE *p, record x[]);

int niv;

 /* debut de la fonction main() */


 main()
 {



 	/* declaration des variables globales a main() */

 	FILE *fp;
 	int i, j;
 	char c;
 	long n;



 /* 1111111111111111111111111111111111111111111111111111111111111111111111111111 */

               /* En-tete generale */

 	printf("\n\n\t\t\t________________________\t\t\t");
 	printf("\n\t\t\tSalary Management System\t\t\t\n");
 	printf("\t\t\t________________________\t\t\t\n\n");

 /* 1111111111111111111111111111111111111111111111111111111111111111111111111111 */



 /* 2222222222222222222222222222222222222222222222222222222222222222222222222222 */

        /* Creation de la base de donnees, si inexistante */

 	if((fp = fopen("Salary_Info", "r")) == NULL)
 	{
	 	printf("No system database file. Press enter to create\n");

	 	scanf("%c", &c);

	 	if(c == 10)
	 	{
	 		fp = fopen("Salary_Info", "w");
	 		printf("Database has been created\n");
	 		fclose(fp);

	 	}
	 	else
	 	{
	 		exit(0);
	 	}

	 }

 /* 2222222222222222222222222222222222222222222222222222222222222222222222222222 */


/* 33333333333333333333333333333333333333333333333333333333333333333333333333333 */

				   /* choix des options */

    choix:

    system("cls");
 	printf("\n\n\t\t\t________________________\t\t\t");
 	printf("\n\t\t\tSalary Management System\t\t\t\n");
 	printf("\t\t\t________________________\t\t\t\n");
 	printf("\n\t\t\t\tMain Menu\t\t\t\n");
 	printf("\t\t\t\t_________\t\t\t\n\n");

 	printf("\n\n\t\t\tChoose an option please:\n\n");


 	printf("\t\t\t[1] Input data\n\t\t\t[2] List the records\n");
 	printf("\t\t\t[3] Sort the records\n\t\t\t[4] Search a record\n");
 	printf("\t\t\t[5] Report\n\t\t\t[6] Exit\n");

 	printf("\n\t\t\t\t:");
 	scanf("%d", &i);

 	switch(i)
 	{
	 	case 1: {
	 		    fp = fopen("Salary_Info", "a");
		        input(fp, si);
	 	        break;}

        case 2: {
		        fp = fopen("Salary_Info", "r");
				list(fp, si);
                break;}

        case 3: {
		        fp = fopen("Salary_Info", "r+");
				sort(fp, si);
                break;}

        case 4: {
		        fp = fopen("Salary_Info", "r");
				inquiry(fp, si);
                break;}

        case 5: {
		        fp = fopen("Salary_Info", "r");
				report(fp, si);
                break;}

        case 6:

               system("cls");
               printf("\n\n\t\t\t________________________\t\t\t");
               printf("\n\t\t\tSalary Management System\t\t\t\n");
               printf("\t\t\t________________________\t\t\t\n");
               printf("\n\t\t\t\tMain Menu\t\t\t\n");
               printf("\t\t\t\t_________\t\t\t\n\n\n\n\n");

               printf("\t\t   Thanks for using the application...\n\n\n\n");
               printf("\n\n\n\n\n\n\n");
               exit(0);

        default: printf("Enter a number between 1 and 6:\n");
                 break;

	 }

	 n = ftell(fp);
	 fclose(fp);

 	goto choix;

 	printf("\n");

 }

 /* Fin de la fonction main() */




 /* Fin de la fonction main() */

void input (FILE *p, record x[])
{

	int i, d, t;

	system("cls");
 	printf("\n\n\t\t\t________________________\t\t\t");
 	printf("\n\t\t\tSalary Management System\t\t\t\n");
 	printf("\t\t\t________________________\t\t\t\n\n");

 	printf("\t\tEnter the number of records you want to add:");
 	printf("\n\t\t\t\t");
 	scanf("%d", &d);
 	printf("\n\n");

 	for(i = niv; i < niv+d; i++)
	{

	system("cls");
 	printf("\n\n\t\t\t________________________\t\t\t");
 	printf("\n\t\t\tSalary Management System\t\t\t\n");
 	printf("\t\t\t_______Data_Input________\t\t\t\n\n");

	printf("\t\t\tInput employee information\n");

	printf("\t\t\tInput employee card Number:");
	printf("\n\t\t\t\t");
	fscanf(stdin, "%d", &x[i].card_no);


	printf("\t\t\tInput employee name:");
	printf("\n\t\t\t\t");
	fscanf(stdin, "%s", x[i].name);


	printf("\t\t\tInput month:");
	printf("\n\t\t\t\t");
	fscanf(stdin, "%d", &x[i].month);


	printf("\t\t\tInput employee initial salary:");
	printf("\n\t\t\t\t");
	fscanf(stdin, "%f", &x[i].init_salary);


	printf("\t\t\tInput water_Rate:");
	printf("\n\t\t\t\t");
	fscanf(stdin, "%f",&x[i].water_rate);


	printf("\t\t\tInput electric_Rate:\n");
	printf("\n\t\t\t\t");
	fscanf(stdin, "%f", &x[i].electric_rate);



	if(x[i].init_salary <= 800)
        x[i].tax = 0;

    else if (x[i].init_salary > 800 && x[i].init_salary <= 1400)
    x[i].tax = ( x[i].init_salary - 800)*5/100;

    else if (x[i].init_salary > 1400)
    x[i].tax= (x[i].init_salary - 1400) * 10 / 100;

    x[i].final_salary = x[i].init_salary - x[i].water_rate - x[i].electric_rate - x[i].tax;


		fprintf(p,"%d ", x[i].card_no);
	fprintf(p,"%s ", x[i].name);
	fprintf(p,"%d ", x[i].month);
	fprintf(p,"%f ", x[i].init_salary);
	fprintf(p,"%f ", x[i].water_rate);
	fprintf(p,"%f ", x[i].electric_rate);
	fprintf(p,"%f ", x[i].tax);
	fprintf(p,"%f ", x[i].final_salary);


	system("cls");
 	printf("\n\n\t\t\t________________________\t\t\t");
 	printf("\n\t\t\tSalary Management System\t\t\t\n");
 	printf("\t\t\t_______Data_Input________\t\t\t\n\n");

	printf("\t\tThe employee salary information have been successfully recorded");
	printf("\n");

	printf("\n");
	printf("\t\temployee card Number\t:");
	printf("%d", x[i].card_no);
	printf("\n");
	printf("\t\temployee name\t\t:");
	printf("%s", x[i].name);
	printf("\n");
	printf("\t\tmonth\t\t\t:");
	printf("%d", x[i].month);
	printf("\n");
	printf("\t\temployee initial salary\t:");
	printf("%0.3f", x[i].init_salary);
	printf("\n");
	printf("\t\twater_Rate\t\t:");
	printf("%0.2f", x[i].water_rate);
	printf("\n");
	printf("\t\telectric_Rate\t\t:");
	printf("%0.2f", x[i].electric_rate);
	printf("\n");
	printf("\t\ttax\t\t\t:");
	printf("%0.2f", x[i].tax);
	printf("\n");
	printf("\t\temployee final salary\t:");
	printf("%0.2f", x[i].final_salary);
	printf("\n\n");

	printf("Press any number to continue : ");
	scanf("%d", &t);

	system("cls");
	}
	fclose(p);
	niv  += d;
#ifdef TEST
    printf("%d", niv);
#endif

	system("cls");
 	printf("\n\n\t\t\t________________________\t\t\t");
 	printf("\n\t\t\tSalary Management System\t\t\t\n");
 	printf("\t\t\t_______Data_Input________\t\t\t\n\n");

	printf("\t\tPress any number to return to the main menu : ");
	scanf("%d", &d);

	return;

}


void list (FILE *p, record x[])
{
	system("cls");
 	printf("\n\n\t\t\t________________________\t\t\t");
 	printf("\n\t\t\tSalary Management System\t\t\t\n");
 	printf("\t\t\t______Records_List______\t\t\t\n\n");

	int i, d = 0, t, s;
	char u;
	t = 0;
    s = 1;

	printf("\n\n\t\t\t________________________\t\t\t");
 	printf("\n\t\t\tSalary Management System\t\t\t\n");
 	printf("\t\t\t__Records_List_page: %d__\t\t\t\n\n", s);
	for(i = t; i < t + 5; i++)
	{

	fscanf(p, "%d", &x[i].card_no);
	fscanf(p, "%s", x[i].name);
	fscanf(p, "%d", &x[i].month);
	fscanf(p, "%f", &x[i].init_salary);
	fscanf(p, "%f", &x[i].water_rate);
	fscanf(p, "%f", &x[i].electric_rate);
	fscanf(p, "%f", &x[i].tax);
    fscanf(p, "%f", &x[i].final_salary);


	printf("\n");
	printf("\t\temployee card Number\t:");
	printf("%05d", x[i].card_no);
	printf("\n");
	printf("\t\temployee name\t\t:");
	printf("%s", x[i].name);
	printf("\n");
	printf("\t\tmonth\t\t\t:");
	printf("%02d", x[i].month);
	printf("\n");
	printf("\t\temployee initial salary\t:");
	printf("%0.3f", x[i].init_salary);
	printf("\n");
	printf("\t\twater_Rate\t\t:");
	printf("%0.2f", x[i].water_rate);
	printf("\n");
	printf("\t\telectric_Rate\t\t:");
	printf("%0.2f", x[i].electric_rate);
	printf("\n");
	printf("\t\ttax\t\t\t:");
	printf("%0.2f", x[i].tax);
	printf("\n");
	printf("\t\temployee final salary\t:");
	printf("%0.2f", x[i].final_salary);
	printf("\n");
	printf("\n");
	printf("\n");
	}

	printf("\t\t\t[->] Print the next screen\n\t\t\t[<-] Print the previous screen\n");
	printf("\t \n");
	scanf("%c", &u);


	while((u == 60 || u == 62) && (t >= 0 && t <= M))
	{

	if(u == 62)
	{t += 5;
	s++;}
	else if(u == 60)
	{t -= 5;
	s--;}
	else;

	system("cls");
 	printf("\n\n\t\t\t________________________\t\t\t");
 	printf("\n\t\t\tSalary Management System\t\t\t\n");
 	printf("\t\t\t______Records_List______\t\t\t\n\n");
	printf("\n\n\t\t\t________________________\t\t\t");
 	printf("\n\t\t\tSalary Management System\t\t\t\n");
 	printf("\t\t\t__Records_List_page: %d__\t\t\t\n\n", s);
	for(i = t; i < t + 5; i++)
	{

	fscanf(p, "%d", &x[i].card_no);
	fscanf(p, "%s", x[i].name);
	fscanf(p, "%d", &x[i].month);
	fscanf(p, "%f", &x[i].init_salary);
	fscanf(p, "%f", &x[i].water_rate);
	fscanf(p, "%f", &x[i].electric_rate);
	fscanf(p, "%f", &x[i].tax);
    fscanf(p, "%f", &x[i].final_salary);


	printf("\n");
	printf("\t\temployee card Number\t:");
	printf("%d", x[i].card_no);
	printf("\n");
	printf("\t\temployee name\t\t:");
	printf("%s", x[i].name);
	printf("\n");
	printf("\t\tmonth\t\t\t:");
	printf("%d", x[i].month);
	printf("\n");
	printf("\t\temployee initial salary\t:");
	printf("%0.3f", x[i].init_salary);
	printf("\n");
	printf("\t\twater_Rate\t\t:");
	printf("%0.2f", x[i].water_rate);
	printf("\n");
	printf("\t\telectric_Rate\t\t:");
	printf("%0.2f", x[i].electric_rate);
	printf("\n");
	printf("\t\ttax\t\t\t:");
	printf("%0.2f", x[i].tax);
	printf("\n");
	printf("\t\temployee final salary\t:");
	printf("%0.2f", x[i].final_salary);
	printf("\n");
	printf("\n");
	printf("\n");
	}
	printf("\t\t\t[->] Print the next screen\n\t\t\t[<-] Print the previous screen\n");
	printf("\t \n");
	scanf("%c", &u);

	}

    printf("\t\tPress any number to return to the main menu : ");
	scanf("%d", &d);

	return;
	scanf("%d", &d);
	return;
}

void sort (FILE *p, record x[])
{
	system("cls");
 	printf("\n\n\t\t\t________________________\t\t\t");
 	printf("\n\t\t\tSalary Management System\t\t\t\n");
 	printf("\t\t\t_____Records_Sorting____\t\t\t\n\n");
	int b, e, f, tem, d = 0, h =0, max, min;
	char mm[10];
	struct Salary_Info temp[M];
	sort_sw:

	system("cls");
 	printf("\n\n\t\t\t________________________\t\t\t");
 	printf("\n\t\t\tSalary Management System\t\t\t\n");
 	printf("\t\t\t_____Records_Sorting____\t\t\t\n\n");
	printf("\t\t\t[1] Sorting by card number\n\t\t\t[2] Sorting by final salary amount\n");
 	printf("\t\t\t[3] Sorting by name\n\t\t\t[4] Exit\n");

	printf("\n\t\t\t\t:");
 	scanf("%d", &b);

 	switch(b)
 	{
	 	case 1:
		 	{
	for(b = 0; b < M; b++)
	{
    fscanf(p, "%d", &x[b].card_no);
    fscanf(p, "%s", x[b].name);
	fscanf(p, "%d", &x[b].month);
	fscanf(p, "%f", &x[b].init_salary);
	fscanf(p, "%f", &x[b].water_rate);
	fscanf(p, "%f", &x[b].electric_rate);
	fscanf(p, "%f", &x[b].tax);
    fscanf(p, "%f", &x[b].final_salary);

	temp[b].card_no = x[b].card_no;
	strcpy(temp[b].name, x[b].name);
	temp[b].month = x[b].month;
	temp[b].init_salary = x[b].init_salary;
	temp[b].water_rate = x[b].water_rate;
	temp[b].electric_rate = x[b].electric_rate;
	temp[b].tax = x[b].tax;
	temp[b].final_salary = x[b].final_salary;

	}
	max = min = temp[0].card_no;

	for(b = 0; b < M; b++)
	{
	max = MAX(max, temp[b].card_no);
	min = MIN(min, temp[b].card_no);
	}
#ifdef TEST
	printf("%d %d %d", max, min, temp[0].card_no);
	scanf("%d", &d);
#endif
	 		    for(e = 0; e < M; e++)
	 		    for(f = 0; f < M - 1; f++)
	 		    {
    		 		if(x[e-1].card_no > x[e].card_no)
    		 		{
		 		    	tem = temp[e-1].card_no;
            		    temp[e-1].card_no = temp[e].card_no;
            		    temp[e].card_no = tem;
			        }
    		 	}

		        list(p, x);
	 	        break;}

        case 2: {

	for(b = 0; b < M; b++)
	{
    fscanf(p, "%d", &x[b].card_no);
    fscanf(p, "%s", x[b].name);
	fscanf(p, "%d", &x[b].month);
	fscanf(p, "%f", &x[b].init_salary);
	fscanf(p, "%f", &x[b].water_rate);
	fscanf(p, "%f", &x[b].electric_rate);
	fscanf(p, "%f", &x[b].tax);
    fscanf(p, "%f", &x[b].final_salary);

	temp[b].card_no = x[b].card_no;
	strcpy(temp[b].name, x[b].name);
	temp[b].month = x[b].month;
	temp[b].init_salary = x[b].init_salary;
	temp[b].water_rate = x[b].water_rate;
	temp[b].electric_rate = x[b].electric_rate;
	temp[b].tax = x[b].tax;
	temp[b].final_salary = x[b].final_salary;

	}
	max = min = temp[0].card_no;

	for(b = 0; b < M; b++)
	{
	max = MAX(max, temp[b].card_no);
	min = MIN(min, temp[b].card_no);
	}
#ifdef TEST
	printf("%d %d %d", max, min, temp[0].card_no);
	scanf("%d", &d);
#endif
		        for(e = 0; e < M; e++)
		        {
		        b = e;

	 		    for(f = 0; f < M - 1; f++)
	 		    {
    		 		if(x[b].final_salary < x[f].final_salary)
    		 		{
			 		    	tem = b;
			 		    	b = f;
			 		    	f = tem;
			        }
    		 	}


		        }
		        list(p, x);

                break;}

        case 3: {

	for(b = 0; b < M; b++)
	{
    fscanf(p, "%d", &x[b].card_no);
    fscanf(p, "%s", x[b].name);
	fscanf(p, "%d", &x[b].month);
	fscanf(p, "%f", &x[b].init_salary);
	fscanf(p, "%f", &x[b].water_rate);
	fscanf(p, "%f", &x[b].electric_rate);
	fscanf(p, "%f", &x[b].tax);
    fscanf(p, "%f", &x[b].final_salary);

	temp[b].card_no = x[b].card_no;
	strcpy(temp[b].name, x[b].name);
	temp[b].month = x[b].month;
	temp[b].init_salary = x[b].init_salary;
	temp[b].water_rate = x[b].water_rate;
	temp[b].electric_rate = x[b].electric_rate;
	temp[b].tax = x[b].tax;
	temp[b].final_salary = x[b].final_salary;

	}
	max = min = temp[0].card_no;

	for(b = 0; b < M; b++)
	{
	max = MAX(max, temp[b].card_no);
	min = MIN(min, temp[b].card_no);
	}
#ifdef TEST
	printf("%d %d %d", max, min, temp[0].card_no);
	scanf("%d", &d);
#endif
                 for(e = 0; e < M; e++)
		        {

		        	b = e;
	 		    for(f = 0; f < M - 1; f++)
	 		    {

    		 		if(strcmp(temp[b].name, temp[f].name) > 0)
    		 		{
		 		    	   tem = b;
			 		    	b = f;
			 		    	f = tem;
			        }
    		 	}

				}

				list(p, x);

                break;}

        case 4: system("cls");
	            return;

        default: printf("Enter a number between 1 and 4:\n");
                 goto sort_sw;

	 }

}

void inquiry (FILE *p, record x[])
{
	int b, d = 0, t;
	char c[10];


	inq_sw:

	system("cls");
 	printf("\n\n\t\t\t________________________\t\t\t");
 	printf("\n\t\t\tSalary Management System\t\t\t\n");
 	printf("\t\t\t____Records_Inquiring___\t\t\t\n\n");
	printf("\t\t\t[1] Search by card number\n\t\t\t[2] Search by name\n");
 	printf("\t\t\t[3] Exit\n");

	printf("\n\t\t\t\t:");
 	scanf("%d", &b);

 	switch(b)
 	{
	 	case 1: {
		 printf("\t\tEnter the card number of the employee:\n\t\t\t\t");
		 scanf("%d", &d);

		 for(b = 0; b < M; b++)
		 {
	fscanf(p, "%d", &x[b].card_no);
    fscanf(p, "%s", x[b].name);
	fscanf(p, "%d", &x[b].month);
	fscanf(p, "%f", &x[b].init_salary);
	fscanf(p, "%f", &x[b].water_rate);
	fscanf(p, "%f", &x[b].electric_rate);
	fscanf(p, "%f", &x[b].tax);
    fscanf(p, "%f", &x[b].final_salary);

    if(x[b].card_no == d)
    {
    	printf("\n");
	printf("employee card Number\t:");
	printf("%d", x[b].card_no);
	printf("\n");
	printf("employee name\t\t:");
	printf("%s", x[b].name);
	printf("\n");
	printf("month\t\t\t:");
	printf("%d", x[b].month);
	printf("\n");
	printf("employee initial salary\t:");
	printf("%0.3f", x[b].init_salary);
	printf("\n");
	printf("water_Rate\t\t:");
	printf("%0.2f", x[b].water_rate);
	printf("\n");
	printf("electric_Rate\t\t:");
	printf("%0.2f", x[b].electric_rate);
	printf("\n");
	printf("tax\t\t\t:");
	printf("%0.2f", x[b].tax);
	printf("\n");
	printf("employee final salary\t:");
	printf("%0.2f", x[b].final_salary);
	printf("\n");
	printf("\n");
	printf("\n");

	printf("Enter a number to continue");
	scanf("%d", &t);
    }
 		}

	 	        break;}

        case 2: {
		 printf("\t\tEnter the name of the employee:\n\t\t\t\t");
		 scanf("%s", c);

		 for(b = 0; b < M; b++)
		 {
	fscanf(p, "%d", &x[b].card_no);
    fscanf(p, "%s", x[b].name);
	fscanf(p, "%d", &x[b].month);
	fscanf(p, "%f", &x[b].init_salary);
	fscanf(p, "%f", &x[b].water_rate);
	fscanf(p, "%f", &x[b].electric_rate);
	fscanf(p, "%f", &x[b].tax);
    fscanf(p, "%f", &x[b].final_salary);

    if(strcmp(x[b].name, c) == 0)
    {
    	printf("\n");
	printf("employee card Number\t:");
	printf("%d", x[b].card_no);
	printf("\n");
	printf("employee name\t\t:");
	printf("%s", x[b].name);
	printf("\n");
	printf("month\t\t\t:");
	printf("%d", x[b].month);
	printf("\n");
	printf("employee initial salary\t:");
	printf("%0.3f", x[b].init_salary);
	printf("\n");
	printf("water_Rate\t\t:");
	printf("%0.2f", x[b].water_rate);
	printf("\n");
	printf("electric_Rate\t\t:");
	printf("%0.2f", x[b].electric_rate);
	printf("\n");
	printf("tax\t\t\t:");
	printf("%0.2f", x[b].tax);
	printf("\n");
	printf("employee final salary\t:");
	printf("%0.2f", x[b].final_salary);
	printf("\n");
	printf("\n");
	printf("\n");

	printf("Enter a number to continue");
	scanf("%d", &d);
    }
 		}

                break;}

        case 3:
                system("cls");
                return;

        default: printf("Enter a number between 1 and 3:\n");


	 }

	goto inq_sw;

}

void report (FILE *p, record x[])
{
	int d, b;
	int ms, mf;
	char c;
	float sum = 0;

	system("cls");
 	printf("\n\n\t\t\t________________________\t\t\t");
 	printf("\n\t\t\tSalary Management System\t\t\t\n");
 	printf("\t\t\t_____Records_Report____\t\t\t\n\n");

 	printf("\t\tEnter the employee card number please:\n\t\t\t\t");
 	scanf("%d", &d);
 	printf("\t\tEnter the starting month please:\n\t\t\t\t");
 	scanf("%d", &ms);
 	printf("\t\tEnter the ending month please:\n\t\t\t\t");
 	scanf("%d", &mf);

 	for(b = 0; b < M; b++)
	{
	fscanf(p, "%d", &x[b].card_no);
    fscanf(p, "%s", x[b].name);
	fscanf(p, "%d", &x[b].month);
	fscanf(p, "%f", &x[b].init_salary);
	fscanf(p, "%f", &x[b].water_rate);
	fscanf(p, "%f", &x[b].electric_rate);
	fscanf(p, "%f", &x[b].tax);
    fscanf(p, "%f", &x[b].final_salary);}

    for(b = 0; b < M; b++)
    {
    	if(x[b].card_no == d)
    	{
	    	if(x[b].month >= ms && x[b].month <= mf)
	    	{
	    		sum += x[b].final_salary;
	    	}
	    }
    }
 	printf("\n\n");
 	printf("\t\tThe sum of final salary received by the employee\n");
	printf("\t\tfrom the month(s) %d to %d is %f\n\n", ms, mf, sum);

	printf("\t\tPress any number to return to the main menu : ");
	scanf("%d", &d);

	return;

}



































































/* kamazoun, 21 janvier 2016 , hangzhou, zhejiang, chine */
