/*

Module: Algorithm and Design

Name: Daniel Wu
Student ID: 21460524
Assignment Due: 22nd April

Programme Description:

A pharmaceutical company manufactures 3 lines of products from its factory in Dublin.  
The production line is sophisticated and audited to the highest quality standards.  
Each production line is staffed by a production teams each consisting of a number of employees.  
Each employee is certified to work on 1 or more lines and there are 4 production teamss in total.

Working in the company's IT department, you have been given access to 4 separate 
lists detailing teams membership and a separate list of certifications earned by each employee.
You have been asked to provide the following information :-

a)	combine the teams lists  to produce a report of all employees in surname order
b)	a list of the employees certified to work on all 3 lines
c)	a routine to search for a specific worker by surname.

Your IT Department is determined to be as efficient as possible and has decided on the following standards for the project:-

1.	You should use the merge sort for sorting 
2.	Improve the efficiency of the merge sort by using another elementary sort to decrease the number of leaves in its execution tree.
3.	Explore any method to improve the execution of the elementary sort by using a searching algorithm you're familiar with.
4.	You should report on the time complexity of each algorithm you use in meeting requirements (a)-(c).

*/

// ---Header File---
#include <stdio.h> 
#include <stdlib.h>
#include <string.h>

// ---Array Signatures---
#define NAME 12 // For Name and Surname
#define EMPLOYEES 20 // Total Employees
#define IDENTIFICATION 12 // ID NUMBER
 

// ---Structure Signatures---

// Employee Details
struct details 
{

    char name[NAME];
    char surname[NAME];
    char ID[IDENTIFICATION];
    int cert;

};

// All Teams
struct team
{
    
    struct details person[EMPLOYEES]; // Nested Array Structure

};


// ---Function Signatures---
void display(struct team *); // Displaying Full list of Everything
void workline(struct team *); // Displaying people with 3 certifications
void mergeSort(char a[][NAME], int size); // Merge sort
void mergeRecursion(char a[][NAME], int l, int r); // Recursion
void mergeArrays(char a[][NAME], int l, int m, int r); // Later part of Merge sort
void linear(struct team *); // Linear Search




// ---Main Body---
int main(void)
{

    int menu = 1; 
    int menuLOOP = 0;
    int option; // Choose option for Cases
    char surnames[][NAME] = {"Havertz", "Mount", "Pulisic", "Rudiger", "Silva", "James", "Azpilicueta", "Christensen", "Kovacic", "Ziyech",
    "Broja", "Gilmour", "Vale", "Livramento", "Ferreira", "Drogba", "Terry", "Ivanovic", "Essien", "Nascimento"};
    int size = 20;
    
    
    

    do
    {

        do
        {


            // Menu
            printf("\n1 - Display Lists and Teams"); // Option 1
            printf("\n2 - Display Surnames"); // Option 2
            printf("\n3 - (b)Employees Certified to Work on 3 Lines"); // Option 3
            printf("\n4 - (a)Sort Surnames"); // Option 4
            printf("\n5 - (c)Search by Surname"); // Option 5
            printf("\n6 - End Program\n"); // Option 6
            scanf("\n%d", &option); // User Input

            // Start of menu
            switch (option) // Switch Statement
            {

                case 1: // Option 1
                {

                    struct team teams; 
                    
                    display(&teams);

                    break; // Break is used to stop the case

                } // end case

                case 2: // Option 2
                {

                    for(int i = 0; i < EMPLOYEES; i++)
                    {

                        printf("\n%s\n", surnames[i]);

                    }

                    break;

                }

                case 3: // Option 3
                {

                    struct team information;

                    workline(&information);

                    break;

                }

                case 4: // Option 4
                {

                    mergeSort(surnames, size);

                    for(int i = 0; i < size; i++)
                    {

                        printf("\n%s\n",surnames[i]);

                    }

                    break; // Break is used to stop the case

                } // end case

                case 5: // Option 5
                {

                    struct team search;

                    linear(&search);
                  
                    break; // Break is used to stop the case

                } // end case 

                case 6: // Option 6
                {

                    printf("\nYou have Ended the Program\n");
                    
                    return 0;

                    break; // Break is used to stop the case

                } // end case

            } // End Switch


        } while (menu = 1); // End do
        
        

    } while (menuLOOP = 1); // End do
    

    return 0;

} // End 0f Main

// ---Start of Functions---

void display(struct team *teams)
{

    // -------- teams 1 --------

    printf("\nTeam 1\n");

    strcpy(teams->person[0].name, "Kai");
    strcpy(teams->person[0].surname, "Havertz");
    strcpy(teams->person[0].ID, "2 9 2 0 2 1");
    teams->person[0].cert = 3;
    
    printf("\nName: %s", teams->person[0].name);
    printf("\nSurname: %s", teams->person[0].surname);
    printf("\nID: %s", teams->person[0].ID);
    printf("\nCertification: %d\n", teams->person[0].cert);

    strcpy(teams->person[1].name, "Mason");
    strcpy(teams->person[1].surname, "Mount");
    strcpy(teams->person[1].ID, "1 9 7 0 2 7");
    teams->person[1].cert = 2;
    
    printf("\nName: %s", teams->person[1].name);
    printf("\nSurname: %s", teams->person[1].surname);
    printf("\nID: %s", teams->person[1].ID);
    printf("\nCertification: %d\n", teams->person[1].cert);

    strcpy(teams->person[2].name, "Christian");
    strcpy(teams->person[2].surname, "Pulisic");
    strcpy(teams->person[2].ID, "1 0 2 7 5 6");
    teams->person[2].cert = 1;
    
    printf("\nName: %s", teams->person[2].name);
    printf("\nSurname: %s", teams->person[2].surname);
    printf("\nID: %s", teams->person[2].ID);
    printf("\nCertification: %d\n", teams->person[2].cert);

    strcpy(teams->person[3].name, "Antonio");
    strcpy(teams->person[3].surname, "Rudiger");
    strcpy(teams->person[3].ID, "2 1 7 8 5 0");
    teams->person[3].cert = 2;
    
    printf("\nName: %s", teams->person[3].name);
    printf("\nSurname: %s", teams->person[3].surname);
    printf("\nID: %s", teams->person[3].ID);
    printf("\nCertification: %d\n", teams->person[3].cert);
    
    strcpy(teams->person[4].name, "Thiago");
    strcpy(teams->person[4].surname, "Silva");
    strcpy(teams->person[4].ID, "6 7 3 4 9 1");
    teams->person[4].cert = 3;
    
    printf("\nName: %s", teams->person[4].name);
    printf("\nSurname: %s", teams->person[4].surname);
    printf("\nID: %s", teams->person[4].ID);
    printf("\nCertification: %d\n", teams->person[4].cert);

    // -------- teams 2 --------

    printf("\nTeam 2\n");

    strcpy(teams->person[5].name, "Reece");
    strcpy(teams->person[5].surname, "James");
    strcpy(teams->person[5].ID, "5 3 7 1 5 3");
    teams->person[5].cert = 2;
    
    printf("\nName: %s", teams->person[5].name);
    printf("\nSurname: %s", teams->person[5].surname);
    printf("\nID: %s", teams->person[5].ID);
    printf("\nCertification: %d\n", teams->person[5].cert);

    strcpy(teams->person[6].name, "Caesar");
    strcpy(teams->person[6].surname, "Azpilicueta");
    strcpy(teams->person[6].ID, "3 6 3 7 3 7");
    teams->person[6].cert = 1;
    
    printf("\nName: %s", teams->person[6].name);
    printf("\nSurname: %s", teams->person[6].surname);
    printf("\nID: %s", teams->person[6].ID);
    printf("\nCertification: %d\n", teams->person[6].cert);

    strcpy(teams->person[7].name, "Andreas");
    strcpy(teams->person[7].surname, "Christensen");
    strcpy(teams->person[7].ID, "2 7 9 4 7 3");
    teams->person[7].cert = 2;
    
    printf("\nName: %s", teams->person[7].name);
    printf("\nSurname: %s", teams->person[7].surname);
    printf("\nID: %s", teams->person[7].ID);
    printf("\nCertification: %d\n", teams->person[7].cert);

    strcpy(teams->person[8].name, "Matteo");
    strcpy(teams->person[8].surname, "Kovacic");
    strcpy(teams->person[8].ID, "7 8 3 7 2 8");
    teams->person[8].cert = 3;
    
    printf("\nName: %s", teams->person[8].name);
    printf("\nSurname: %s", teams->person[8].surname);
    printf("\nID: %s", teams->person[8].ID);
    printf("\nCertification: %d\n", teams->person[8].cert);
    
    strcpy(teams->person[9].name, "Hakim");
    strcpy(teams->person[9].surname, "Ziyech");
    strcpy(teams->person[9].ID, "2 2 7 0 1 6");
    teams->person[9].cert = 3;
    
    printf("\nName: %s", teams->person[9].name);
    printf("\nSurname: %s", teams->person[9].surname);
    printf("\nID: %s", teams->person[9].ID);
    printf("\nCertification: %d\n", teams->person[9].cert);

    // -------- teams 3 --------

    printf("\nTeam 3\n");

    strcpy(teams->person[10].name, "Armando");
    strcpy(teams->person[10].surname, "Broja");
    strcpy(teams->person[10].ID, "9 0 3 7 2 7");
    teams->person[10].cert = 1;
    
    printf("\nName: %s", teams->person[10].name);
    printf("\nSurname: %s", teams->person[10].surname);
    printf("\nID: %s", teams->person[10].ID);
    printf("\nCertification: %d\n", teams->person[10].cert);

    strcpy(teams->person[11].name, "Billy");
    strcpy(teams->person[11].surname, "Gilmour");
    strcpy(teams->person[11].ID, "4 7 2 0 8 3");
    teams->person[11].cert = 2;
    
    printf("\nName: %s", teams->person[11].name);
    printf("\nSurname: %s", teams->person[11].surname);
    printf("\nID: %s", teams->person[11].ID);
    printf("\nCertification: %d\n", teams->person[11].cert);

    strcpy(teams->person[12].name, "Harvey");
    strcpy(teams->person[12].surname, "Vale");
    strcpy(teams->person[12].ID, "8 3 7 3 7 8");
    teams->person[12].cert = 1;
    
    printf("\nName: %s", teams->person[12].name);
    printf("\nSurname: %s", teams->person[12].surname);
    printf("\nID: %s", teams->person[12].ID);
    printf("\nCertification: %d\n", teams->person[12].cert);

    strcpy(teams->person[13].name, "Tino");
    strcpy(teams->person[13].surname, "Livramento");
    strcpy(teams->person[13].ID, "6 3 8 1 7 4");
    teams->person[13].cert = 2;
    
    printf("\nName: %s", teams->person[13].name);
    printf("\nSurname: %s", teams->person[13].surname);
    printf("\nID: %s", teams->person[13].ID);
    printf("\nCertification: %d\n", teams->person[13].cert);
    
    strcpy(teams->person[14].name, "Paulo");
    strcpy(teams->person[14].surname, "Ferreira");
    strcpy(teams->person[14].ID, "2 4 7 5 9 4");
    teams->person[14].cert = 3;
    
    printf("\nName: %s", teams->person[14].name);
    printf("\nSurname: %s", teams->person[14].surname);
    printf("\nID: %s", teams->person[14].ID);
    printf("\nCertification: %d\n", teams->person[14].cert);

    // -------- teams 4 --------

    printf("\nTeam 4\n");

    strcpy(teams->person[15].name, "Didier");
    strcpy(teams->person[15].surname, "Drogba");
    strcpy(teams->person[15].ID, "1 8 3 9 5 0");
    teams->person[15].cert = 3;
    
    printf("\nName: %s", teams->person[15].name);
    printf("\nSurname: %s", teams->person[15].surname);
    printf("\nID: %s", teams->person[15].ID);
    printf("\nCertification: %d\n", teams->person[15].cert);

    strcpy(teams->person[16].name, "John");
    strcpy(teams->person[16].surname, "Terry");
    strcpy(teams->person[16].ID, "4 7 3 7 3 5");
    teams->person[16].cert = 3;
    
    printf("\nName: %s", teams->person[16].name);
    printf("\nSurname: %s", teams->person[16].surname);
    printf("\nID: %s", teams->person[16].ID);
    printf("\nCertification: %d\n", teams->person[16].cert);

    strcpy(teams->person[17].name, "Branislav");
    strcpy(teams->person[17].surname, "Ivanovic");
    strcpy(teams->person[17].ID, "6 3 7 7 3 1");
    teams->person[17].cert = 1;
    
    printf("\nName: %s", teams->person[17].name);
    printf("\nSurname: %s", teams->person[17].surname);
    printf("\nID: %s", teams->person[17].ID);
    printf("\nCertification: %d\n", teams->person[17].cert);

    strcpy(teams->person[18].name, "Michael");
    strcpy(teams->person[18].surname, "Essien");
    strcpy(teams->person[18].ID, "4 2 6 2 7 4");
    teams->person[18].cert = 2;
    
    printf("\nName: %s", teams->person[18].name);
    printf("\nSurname: %s", teams->person[18].surname);
    printf("\nID: %s", teams->person[18].ID);
    printf("\nCertification: %d\n", teams->person[18].cert);
    
    strcpy(teams->person[19].name, "Ramires");
    strcpy(teams->person[19].surname, "Nascimento");
    strcpy(teams->person[19].ID, "6 3 7 3 8 3");
    teams->person[19].cert = 2;
    
    printf("\nName: %s", teams->person[19].name);
    printf("\nSurname: %s", teams->person[19].surname);
    printf("\nID: %s", teams->person[19].ID);
    printf("\nCertification: %d\n", teams->person[19].cert);


} // End Function

void workline(struct team *information)
{

    for(register int i = 0; i < EMPLOYEES; i++)
    {

        if(information->person[i].cert == 3)
        {

            printf("\n");
            printf("\nName: %s", information->person[i].name);
            printf("\nSurname: %s", information->person[i].surname);
            printf("\nID: %s", information->person[i].ID);
            printf("\nCertification: %d\n", information->person[i].cert);
                
        } // End if 

    } //  End for

} // End Function


// ---Merge Sort---

void mergeSort(char a[][NAME], int size)
{

    mergeRecursion(a, 0, size - 1); // Calls Merge Recusion with values

}

void mergeRecursion(char a[][NAME], int l, int r)
{

    if(l < r)
    {

        int m = l + (r - l) / 2; // Divides Array

        mergeRecursion(a, l, m); // Calls Merge Recusion
        mergeRecursion(a, m + 1, r); // Calls Merge Recusion
        mergeArrays(a, l, m, r); // Calls Merge Arrays

    }

}

// Final part of merging Arrays back together to form the original array again
void mergeArrays(char a[][NAME], int l, int m, int r)
{
    int i = 0, j = 0, k = 0;
    int leftside = m - l + 1;
    int rightside = r - m;
    
    // Use of Malloc to create temporary arrays
    char **tempLeft = malloc(sizeof(char *) * leftside); 
    char **tempRight = malloc(sizeof(char *) * rightside);


    // Copy Data
    for(int i = 0; i < leftside; i++)
    {

        //tempLeft[i] = a[l + i];
        tempLeft[i] = malloc( sizeof(a[l + i]));
        strcpy(tempLeft[i] , a[l + i]);

    }

    for(int j = 0; j < rightside; j++)
    {

        //tempRight[i] = a[m + 1 + i];
       tempRight[j] = malloc( sizeof(a[m + j + 1])); 
       strcpy(tempRight[j] ,a[m + j + 1]);

    }

    i = 0; 
    j = 0; 
    k = l; 

    while (i < leftside && j < rightside) 
    {
        if (strcmp(tempLeft[i], tempRight[j]) < 0) 
        {
            strcpy(a[k], tempLeft[i]);
            i++;
        }
        else 
        {
            strcpy(a[k], tempRight[j]);
            j++;
        }
        k++;
    }

    while (i < leftside) 
    {

        strcpy(a[k], tempLeft[i]);
        i++;
        k++;

    }

    while (j < rightside) 
    {

        strcpy(a[k], tempRight[j]);
        j++;
        k++;

    }
}

// ---Search Algorithm---

void linear(struct team *search)
{

    char empSearch[EMPLOYEES];
    int status = 1; // Keeps Loop running until Surname Found

    printf("\nEnter Surname you want to find\n");
    scanf("%s", empSearch);

    for(int i=0; i < EMPLOYEES; i++)
    {

        if(strcmp(empSearch, search->person[i].surname)  == 0)
        {
                 
            printf("\nName: %s", search->person[i].name);
            printf("\nSurname: %s", search->person[i].surname);
            printf("\nID: %s", search->person[i].surname);
            printf("\nCertification: %d\n", search->person[i].cert);
            status = 1;

            break;
                           
        }

        else
        {
            status = 0;

        }
                
    } 

    if(status == 0)
    {

        printf("\nSurname Not Found");

    }

}








