#include <stdio.h>
#include <stdlib.h>
#include<conio.h>
#include "func.h"
#define size_m 5

int main()
{
    int index,searched,j;
    system("cls");
    printf(ANSI_COLOR_CYAN"welcome to students data structure in AL AMEER NASSAR School\n\n");
    for(index=0; index<4; index++)
    {
        sleep(1);
        printf(" *");
    }

    while(1)
    {
        system("cls");
        printf(ANSI_COLOR_CYAN"Each of these letters indicates a specific request:\n");
        printf("'n' ------> add new student\n");
        printf("'a' ------> print all students according to the letters of the alphabet\n");
        printf("'p' ------> print all students according to their grades\n");
        printf("'s' ------> search for specific student \n"ANSI_COLOR_RESET);
        printf(ANSI_COLOR_YELLOW"enter request character:"ANSI_COLOR_RESET);
        scanf(" %c",&buff);
        if(buff=='n' || buff=='N' ) //add student
        {
            system("cls");
            printf(ANSI_COLOR_CYAN"process of adding new student\n\n"ANSI_COLOR_RESET);
            add_student(&arr[count_st]);
            count_st++;
            printf(ANSI_COLOR_CYAN"\n save process:"ANSI_COLOR_RESET);
            for(index=0; index<3; index++)
            {
                sleep(1);
                printf(ANSI_COLOR_CYAN" *"ANSI_COLOR_RESET);
            }
        }
        else if (buff=='s' || buff=='S' ) //search for specific student, then processing on it
        {
            system("cls");
            printf(ANSI_COLOR_CYAN"Searching process\n"ANSI_COLOR_RESET);
            searched=(search_student()-1); // as (id=index+1)
            if(searched == -2)
            {
                printf(ANSI_COLOR_RED"not exist\n"ANSI_COLOR_RESET);
                printf(ANSI_COLOR_RED"returning to homepage"ANSI_COLOR_RESET);
                for(index=0; index<2; index++)
                {
                    sleep(1);
                    printf(ANSI_COLOR_CYAN" *"ANSI_COLOR_RESET);
                }
            }
            else
            {
                while(1) //processing on current student
                {
                    system("cls");
                    print_student(&arr[searched]);
                    printf(ANSI_COLOR_CYAN"'d' ------> delete this student\n");
                    printf("'r' ------> re_Insert the subjects to this student  \n");
                    printf("'m' ------> to edit the marks for this student\n");
                    printf("'c' ------> to call this student\n");
                    printf("'h' ------> return to Homepage \n\n"ANSI_COLOR_RESET);
                    printf(ANSI_COLOR_YELLOW"enter request character:"ANSI_COLOR_RESET);
                    scanf(" %c",&buff);
                    if(buff=='d' || buff=='D' ) //delete current student
                    {
                        system("cls");
                        printf(ANSI_COLOR_CYAN"process of deleting this student\n\n"ANSI_COLOR_RESET);
                        delete_student(searched);
                        for(index=0; index<3; index++)
                        {
                            sleep(1);
                            printf(ANSI_COLOR_CYAN" *"ANSI_COLOR_RESET);
                        }
                        break;
                    }
                    else if(buff=='r' || buff=='R' ) //Re_inserting subjects to current student
                    {
                        system("cls");
                        print_student(&arr[searched]);
                        printf(ANSI_COLOR_CYAN"process of Re_inserting subjects to this student\n\n"ANSI_COLOR_RESET);
                        free(arr[searched].materials);
                        printf(ANSI_COLOR_YELLOW"plz insert no.of subjects:"ANSI_COLOR_RESET);
                        while((scanNum_u8(&(arr[searched].mats_n))==0) || ((arr[searched].mats_n)>size_materials))
                        {
                            printf(ANSI_COLOR_RED"enter valid number(max=%d subject):"ANSI_COLOR_RESET,size_materials);
                        }
                        if(arr[searched].mats_n>0)
                        {
                            arr[searched].materials=(mat_t*)malloc((arr[searched].mats_n)*sizeof(mat_t));
                            printf(ANSI_COLOR_YELLOW"choose from these subjects:\n"ANSI_COLOR_RESET);
                            printf(ANSI_COLOR_BLUE"(ARABIC-ENGLISH-MATH-FRENCH-HISTORY-GEOGRAOHY-BIOLOGY-CHEMISRY-Differential-ALGEBRA-DRAWING-MUSIC)\n"ANSI_COLOR_RESET);
                            insert_materials(arr[searched].materials,arr[searched].mats_n);
                        }
                        arr[searched].percentage=0;
                    }
                    else if(buff=='m' || buff=='M' ) //to edit all marks of student's subjects
                    {
                        system("cls");
                        print_student(&arr[searched]);
                        printf(ANSI_COLOR_CYAN"process of re_inserting the marks to this student\n\n"ANSI_COLOR_RESET);
                        add_marks(&arr[searched]);
                        printf(ANSI_COLOR_CYAN"process done\n"ANSI_COLOR_RESET);
                        for(index=0; index<3; index++)
                        {
                            sleep(1);
                            printf(" *");
                        }
                    }
                    else if(buff=='c' || buff=='C' ) //to call  current student
                    {
                        while(1)
                        {
                            if(arr[searched].phone[0]=='s' || arr[searched].phone[0]=='S' )
                            {
                                printf(ANSI_COLOR_CYAN"phone not exist\nReturning to main page:"ANSI_COLOR_RESET);
                                for(index=0; index<3; index++)
                                {
                                    sleep(1);
                                    printf(ANSI_COLOR_CYAN" *"ANSI_COLOR_RESET);
                                }
                                break;
                            }
                            for(j=0; j<4; j++)
                            {
                                system("cls");
                                printf(ANSI_COLOR_CYAN"student:%s    "ANSI_COLOR_RESET,arr[searched].name);
                                printf(ANSI_COLOR_CYAN"call %s    "ANSI_COLOR_RESET,arr[searched].phone);
                                for(index=0; index<3; index++)
                                {
                                    sleep(1);
                                    printf(ANSI_COLOR_CYAN" ."ANSI_COLOR_RESET);
                                }
                            }
                            printf(ANSI_COLOR_CYAN"     NO Answer !!\n"ANSI_COLOR_RESET);
                            printf(ANSI_COLOR_YELLOW"enter 'c' ------> to call again \nor enter 'h' ------> to return to Homepage:"ANSI_COLOR_RESET);
                            scanf(" %c",&buff);
                            if(buff=='h' || buff=='H' )
                            {
                                break;
                            }
                            else if(buff=='c' || buff=='C' )
                            {

                            }
                            else
                            {

                            }
                        }
                    }
                    else
                    {
                        break;
                    }
                }
            }
        }
        if(buff=='p' || buff=='P' ) //print all school according to the letters of the alphabet
        {
            while(1)
            {
                system("cls");
                sorting_grades();
                print_school();
                printf(ANSI_COLOR_YELLOW"enter 'h' ------> to return to Homepage:"ANSI_COLOR_RESET);
                scanf(" %c",&buff);
                if(buff=='h' || buff=='H' )
                {
                    break;
                }
                else
                {

                }
            }
        }
        if(buff=='a' || buff=='A' ) //print all school according to  grades
        {
            while(1)
            {
                system("cls");
                sorting_names();
                print_school();
                printf(ANSI_COLOR_YELLOW"enter 'h' ------> return to Homepage:"ANSI_COLOR_RESET);
                scanf(" %c",&buff);
                if(buff=='h' || buff=='H' )
                {
                    break;
                }
                else
                {

                }
            }
        }
    }
    return 0;
}


































/*   printf("welcome to students data structure in AL AMEER NASSAR School\n");
   printf("enter any key to skip:\n");
   while(1)
   {
       if(kbhit())
       {
           system("cls");
           break;
       }
   }
   scanf("%c",&buff);
    system("cls");
    while(1)
    {
        printf("welcome to students data structure in AL AMEER NASSAR School\n");
        printf("\nenter 'a' to add student, 'd' to delete student, 's' to print all school,'m' to manage then print all school:");
        fflush(stdin);
        scanf(" %c",&buff);
        if(buff=='a')
        {
            sleep(3);
            add_student(&arr[count_st]);
           // add_marks(&arr[count_st]);
            system("cls");
        }
        else if(buff=='d')
        {
            delete_student(search_student());
            system("cls");
        }
        else if(buff=='s')
        {
            system("cls");
            print_school();
        }
        else if(buff=='m')
        {
            system("cls");
            sorting_grades();
            print_school();
        }
        else
        {
            printf("enter valid input.\n");
        }
    } */
