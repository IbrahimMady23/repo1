#include <stdio.h>
#include <stdlib.h>
#include<conio.h>
#include "func.h"
char buff;
stu_t arr[1000];
short count_st=0;
/* array contain all available materials*/
mat_t mats[size_materials]=
{
    {"ARABIC",150,0,0},
    {"ENGLISH",150,0,0},
    {"SCIENCE",150,0,0},
    {"MATH",150,0,0},
    {"FRENCH",150,0,0},
    {"HISTORY",150,0,0},
    {"GEOGRAOHY",150,0,0},
    {"BIOLOGY",150,0,0},
    {"CHEMISRY",150,0,0},
    {"Differential",150,0,0},
    {"ALGEBRA",150,0,0},
    {"DRAWING",150,0,0},
    {"MUSIC",150,0,0}
};



/* function to scan number to max of 4 digits
/* return 1 if all is right , 0 if error  */
int scanNum_u8(char* Pnum)
{
    unsigned int ret=0;
    char i;
    char buffer[5];
    fflush(stdin);
    scanf("%c",&buffer[0]);
    i=0;
    while( buffer[i]!='\n' )
    {
        if(buffer[i]<'0' || buffer[i]>'9' || i>3)
        {
            return 0;
        }
        else
        {
            ret=ret*10+(buffer[i]-'0');
            i++;
            scanf("%c",&buffer[i]);
        }
    }
    *Pnum=ret;
    return 1;
}
/* return no.of characters in string(without null)*/
int string_length(char* str)
{
    unsigned char i;
    for(i=0; str[i]; i++)
    {

    }
    return i;
}
/* get string with limited length from user
 /* return 0 if address pass is null , 1 if all is right */
int scan_string(char* str, int size)
{
    int i=0;
    if(str==0)
    {
        return 0;
    }
    else
    {
        fflush(stdin);
        scanf("%c",&str[i]);
        while(str[i]!='\n'  && (i<size))
        {
            i++;
            scanf("%c",&str[i]);
        }
        str[i]='\0';

    }
    return 1;
}
/* copy string 1 in string 2*/
void copy_string(char* str1, char* str2)
{
    unsigned char i;
    for(i=0; str1[i]; i++)
    {
        str2[i]=str1[i];
    }
    str2[i]='\0';
}
/* get phone number from user
/* return -1 if there is no phone, 0 if input is not number , 1 if all is right */
int scan_phone(char* ph)
{
    int i=0,j=0;
    fflush(stdin);
    scan_string(ph,11);
    if(ph[0]=='s' || ph[0]=='S')
    {
        return -1;
    }
    for(i=0; i<11; i++)
    {
        if((ph[i]>='0') && (ph[i]<='9'))
        {
            //do nothing
        }
        else
        {
            return 0; //invalid input
        }
    }
    return 1;
}
/* print string
/* return 0 if address passed is null , 1 if all is right */
int print_string(char* str)
{
    int i=0;
    if(str==0)
    {
        return 0;
    }
    else
    {
        for(i=0; str[i]; i++)
        {
            printf("%c",str[i]);
        }
    }
    return 1;
}



//function to compare two given strings
//return 1 if 1st string is greater as ASCII table
//return 2 if 2nd string is greater as ASCII table
//return 0 if two strings are equal
int compare_strings(char* str1, char* str2)
{
    int i=0,j=0;
    for(i=0,j=0; str1[i] || str2[j]; i++,j++)
    {
        while(str1[i]==' ')
        {
            i++;
        }
        while(str2[j]==' ')
        {
            j++;
        }

        if((str1[i]>='A' && str1[i]<='Z') && (str2[j]>='a' && str2[j]<='z'))
        {
            if(str1[i]+('a'-'A')>str2[j])
            {
                return 1;
            }
            else if(str1[i]+('a'-'A')<str2[j])
            {
                return 2;
            }
            else
            {

            }
        }
        else if((str1[i]>='a' && str1[i]<='z') && (str2[j]>='A' && str2[j]<='Z'))
        {
            if(str1[i]>str2[j]+('a'-'A'))
            {
                return 1;
            }
            else if(str1[i]<str2[j]+('a'-'A'))
            {
                return 2;
            }
            else
            {

            }

        }
        else
        {
            if(str1[i]>str2[j])
            {
                return 1;
            }
            else if(str1[i]<str2[j])
            {
                return 2;
            }
            else
            {

            }

        }
    }
    return 0;
}

/* function to get subjects from user
/* (take address of pointer which refer to subjects in student struct, no.of subjects)
/* function handle case if input sub not exist , and case if sub chosen before */
void insert_materials(mat_t* Pmat,int size)
{
    unsigned char i=0,j=0,flag_exist=0;
    for(i=0; i<size; i++)
    {
        printf(ANSI_COLOR_YELLOW"subject %d:"ANSI_COLOR_RESET,i+1);
        scan_string(&(Pmat[i].name),10);
        flag_exist=0;
        for(j=0; j<size_materials; j++)
        {
            if(compare_strings(&Pmat[i],&mats[j])==0)
            {
                if(((mats+j)->flag_choised)==1)
                {
                    printf(ANSI_COLOR_RED"it's chosen before. insert another\n"ANSI_COLOR_RESET);
                    flag_exist++;
                    i--;
                    break;
                }
                else if(((mats+j)->flag_choised)==0)
                {
                    ((mats+j)->flag_choised)=1;
                    Pmat[i]=mats[j];
                    flag_exist++;
                    break;
                }
            }
        }
        if(flag_exist==0) //input subject is not exist in standard subjects
        {
            printf(ANSI_COLOR_RED"plz insert correct subject.\n"ANSI_COLOR_RESET);
            i--;
        }
    }
    // to back all subs not chosen again
    for(i=0;i<size_materials;i++)
    {
        mats[i].flag_choised=0;
    }
}

/* take all data about student and handle all cases with incorrect input*/
void add_student (stu_t* arr)
{
    int i=0;
    if(arr==0)
    {
        printf(ANSI_COLOR_RED"Sorry,Technical error\n"ANSI_COLOR_RESET);
    }
    else if(count_st==1000)
    {
        printf(ANSI_COLOR_RED"Sorry,school is complete\n"ANSI_COLOR_RESET);
    }
    else
    {
        printf(ANSI_COLOR_YELLOW"full name:"ANSI_COLOR_RESET);
        scan_string(arr->name,40);
        arr->id=count_st+1;
        printf(ANSI_COLOR_YELLOW"age:"ANSI_COLOR_RESET);
        while((scanNum_u8(&(arr->age))==0) || ((arr->age)>120) )
        {
            printf(ANSI_COLOR_RED"enter valid age:"ANSI_COLOR_RESET);
        }
        printf(ANSI_COLOR_YELLOW"phone('s' for skip):"ANSI_COLOR_RESET);
        while(scan_phone(arr->phone)==0)
        {
            printf(ANSI_COLOR_RED"plz valid phone number:"ANSI_COLOR_RESET);
        }
        printf(ANSI_COLOR_YELLOW"          info about father          \nname:"ANSI_COLOR_RESET);
        scan_string(arr->father.name,10);
        printf(ANSI_COLOR_YELLOW"age:"ANSI_COLOR_RESET);
        while((scanNum_u8(&(arr->father.age))==0)|| ((arr->father.age)>120) )
        {
            printf(ANSI_COLOR_RED"enter valid age:"ANSI_COLOR_RESET);
        }
        printf(ANSI_COLOR_YELLOW"phone('s' for skip):"ANSI_COLOR_RESET);
        while(scan_phone(arr->father.phone)==0)
        {
            printf(ANSI_COLOR_RED"plz valid number:"ANSI_COLOR_RESET);
        }
        printf(ANSI_COLOR_YELLOW"          info about mother          \nname:"ANSI_COLOR_RESET);
        scan_string(arr->mother.name,10);
        printf(ANSI_COLOR_YELLOW"age:"ANSI_COLOR_RESET);
        while((scanNum_u8(&(arr->mother.age))==0) || ((arr->mother.age)>120))
        {
            printf(ANSI_COLOR_RED"enter valid age:"ANSI_COLOR_RESET);
        }
        printf(ANSI_COLOR_YELLOW"phone('s' for skip):"ANSI_COLOR_RESET);
        while(scan_phone(arr->mother.phone)==0)
        {
            printf(ANSI_COLOR_RED"plz valid number:"ANSI_COLOR_RESET);
        }
        printf(ANSI_COLOR_YELLOW"          info about brothers          \n"ANSI_COLOR_RESET);
        printf(ANSI_COLOR_YELLOW"No.of brothers:"ANSI_COLOR_RESET);
        while((scanNum_u8(&(arr->brothers_n))==0) || ((arr->brothers_n)>20))
        {
            printf(ANSI_COLOR_RED"enter valid number:"ANSI_COLOR_RESET);
        }
        if(arr->brothers_n>0)
        {
            arr->brothers=(person_t*)malloc((arr->brothers_n)*sizeof(person_t));
            for(i=0; i<arr->brothers_n; i++)
            {
                printf(ANSI_COLOR_YELLOW"          brother (%d)          \n"ANSI_COLOR_RESET,i+1);
                printf(ANSI_COLOR_YELLOW"name:"ANSI_COLOR_RESET);
                scan_string(((arr->brothers)+i)->name,10);
                printf(ANSI_COLOR_YELLOW"age:"ANSI_COLOR_RESET);
                while((scanNum_u8(&(((arr->brothers)+i)->age))==0) || ((((arr->brothers)+i)->age)>120))
                {
                    printf(ANSI_COLOR_RED"enter valid age:"ANSI_COLOR_RESET);
                }
                printf(ANSI_COLOR_YELLOW"phone('s' for skip):"ANSI_COLOR_RESET);
                while(scan_phone(((arr->brothers)+i)->phone)==0)
                {
                    printf(ANSI_COLOR_RED"plz valid number:"ANSI_COLOR_RESET);
                }
            }
        }
        printf(ANSI_COLOR_YELLOW"          info about subjects          \nNo.of subjects:"ANSI_COLOR_RESET);
        while((scanNum_u8(&(arr->mats_n))==0) || ((arr->mats_n)>size_materials))
        {
            printf(ANSI_COLOR_RED"enter valid number(max=%d subject):"ANSI_COLOR_RESET,size_materials);
        }
        if(arr->mats_n>0)
        {
            arr->materials=(mat_t*)malloc((arr->mats_n)*sizeof(mat_t));
            printf(ANSI_COLOR_YELLOW"choose from these subjects:\n"ANSI_COLOR_RESET);
            printf(ANSI_COLOR_BLUE"(ARABIC-ENGLISH-MATH-FRENCH-HISTORY-GEOGRAOHY-BIOLOGY-CHEMISRY-Differential-ALGEBRA-DRAWING-MUSIC)\n"ANSI_COLOR_RESET);
            insert_materials(arr->materials,arr->mats_n);
        }
        else
        {

        }
    }
}




/* function to edit student's marks which initially are zeros
/* and update its percentage and grade */
void add_marks(stu_t* arr)
{
    int i=0,sum=0,max;
    if((arr->mats_n)>0)
    {
        for(i=0; i<arr->mats_n; i++)
        {
            printf(ANSI_COLOR_YELLOW"mark in ("ANSI_COLOR_BLUE);
            print_string(((arr->materials)+i)->name);
            printf(ANSI_COLOR_YELLOW"):"ANSI_COLOR_RESET);
            while((scanNum_u8(&(((arr->materials)+i)->mark))==0) || ((((arr->materials)+i)->mark)>(((arr->materials)+i)->max_degree)))
            {
                printf(ANSI_COLOR_RED"enter valid mark:"ANSI_COLOR_RESET);
            }
            sum+=(((arr->materials)+i)->mark);
        }
        max=(arr->materials->max_degree)*(arr->mats_n);
        arr->percentage=((float)sum/(float)max)*100;
        if((arr->percentage)> 90)
        {
            copy_string("A+",arr->grade);
        }
        else if((arr->percentage)> 85)
        {
            copy_string("A",arr->grade);
        }
        else if((arr->percentage)> 80)
        {
            copy_string("B+",arr->grade);
        }
        else if((arr->percentage)> 75)
        {
            copy_string("B",arr->grade);
        }
        else if((arr->percentage)> 65)
        {
            copy_string("c+",arr->grade);
        }
        else if((arr->percentage)> 50)
        {
            copy_string("c",arr->grade);
        }
        else
        {
            copy_string("c",arr->grade);
        }
        for(i=0; i<size_materials; i++)
        {
            mats[i].flag_choised=0;
        }

    }
}




/* to print all data about student struct which it's address passed */
void print_student (stu_t* arr)
{
    unsigned char i;
    printf(ANSI_COLOR_YELLOW"name:"ANSI_COLOR_BLUE);
    print_string(arr->name);
    printf(ANSI_COLOR_YELLOW"\nid:"ANSI_COLOR_BLUE);
    printf("%d\n",arr->id);
    printf(ANSI_COLOR_YELLOW"age="ANSI_COLOR_BLUE);
    printf("%d\n",arr->age);
    printf(ANSI_COLOR_YELLOW"phone:"ANSI_COLOR_BLUE);
    if(arr->phone[0]=='s')
    {
        printf(ANSI_COLOR_BLUE"00000000000");
    }
    else
    {
       print_string(arr->phone);
    }
    printf(ANSI_COLOR_YELLOW"\n          father:          \n");
    printf(ANSI_COLOR_YELLOW"name:"ANSI_COLOR_BLUE);
    print_string(arr->father.name);
    printf(ANSI_COLOR_YELLOW"\nage:"ANSI_COLOR_BLUE);
    printf("%d\n",arr->father.age);
    printf(ANSI_COLOR_YELLOW"phone:"ANSI_COLOR_BLUE);
    if(arr->father.phone[0]=='s')
    {
        printf(ANSI_COLOR_BLUE"00000000000");
    }
    else
    {
       print_string(arr->father.phone);
    }
    printf(ANSI_COLOR_YELLOW"\n          mother:          \n");
    printf(ANSI_COLOR_YELLOW"name:"ANSI_COLOR_BLUE);
    print_string(arr->mother.name);
    printf(ANSI_COLOR_YELLOW"\nage:"ANSI_COLOR_BLUE);
    printf("%d\n",arr->mother.age);
    printf(ANSI_COLOR_YELLOW"phone:"ANSI_COLOR_BLUE);
     if(arr->mother.phone[0]=='s')
    {
        printf(ANSI_COLOR_BLUE"00000000000");
    }
    else
    {
       print_string(arr->mother.phone);
    }
    printf(ANSI_COLOR_YELLOW"\n          brothers:%d          \n",(arr->brothers_n));
    if((arr->brothers_n)==0)
    {
        printf(ANSI_COLOR_BLUE"there are no brothers\n"ANSI_COLOR_RESET);
    }
    else
    {
        for(i=0; i<(arr->brothers_n); i++)
        {
            printf(ANSI_COLOR_YELLOW".......................................\n");
            printf(ANSI_COLOR_YELLOW"name:"ANSI_COLOR_BLUE);
            print_string(((arr->brothers)+i)->name);
            printf(ANSI_COLOR_YELLOW"\nage="ANSI_COLOR_BLUE);
            printf("%d\n",((arr->brothers)+i)->age);
            printf(ANSI_COLOR_YELLOW"phone:"ANSI_COLOR_BLUE);
            print_string(((arr->brothers)+i)->phone);
            printf("\n");
        }
    }
    printf("\n");
    printf(ANSI_COLOR_YELLOW"          subjects:%d          \n",(arr->mats_n));
    if((arr->mats_n)==0)
    {
        printf(ANSI_COLOR_BLUE"there is no subjects\n"ANSI_COLOR_RESET);
    }
    else
    {
        for(i=0; i<(arr->mats_n); i++)
        {
            printf(ANSI_COLOR_YELLOW".......................................\n");
            printf(ANSI_COLOR_YELLOW"subject:"ANSI_COLOR_BLUE);
            print_string(((arr->materials)+i)->name);
            printf(ANSI_COLOR_YELLOW"\nmax degree="ANSI_COLOR_BLUE);
            printf("%d",((arr->materials)+i)->max_degree);
            printf(ANSI_COLOR_YELLOW"\nmark="ANSI_COLOR_BLUE);
            printf("%d\n",((arr->materials)+i)->mark);
        }
    }
    printf("\n\n");
    printf(ANSI_COLOR_YELLOW"percentage for all subjects="ANSI_COLOR_BLUE);
    printf("%0.1f %%\n",arr->percentage);
    printf(ANSI_COLOR_YELLOW"grade="ANSI_COLOR_BLUE);
    print_string(arr->grade);
    printf(ANSI_COLOR_YELLOW" \n===============================================================================================\n"ANSI_COLOR_RESET);
}
/* search for student by his index or by his name
/* return -1 if not exist , index of student if exist */
int search_student(void)
{
    int index,i;
    char name[40];
    printf(ANSI_COLOR_CYAN"enter\n 'i'-----> to search by id \n 'n'-----> to search by name \n 'i'or'n':"ANSI_COLOR_RESET);
    while (1)
    {
        scanf(" %c",&buff);
        if(buff=='i' || buff== 'I')
        {
            printf(ANSI_COLOR_YELLOW"index:"ANSI_COLOR_RESET);
            fflush(stdin);
            scanf("%d",&index);
            if(index<=0 || index>count_st)
            {
                return -1;
            }
            return index;
        }
        else if(buff== 'n' || buff== 'N' )
        {
            printf(ANSI_COLOR_YELLOW"full name:"ANSI_COLOR_RESET);
            fflush(stdin);
            scan_string(name,40);
            for(i=0; i<=count_st; i++)
            {
                if(compare_strings(name,(arr+i)->name)==0) //check if this name exist
                {
                    return i+1;
                }
            }
            return -1;
        }
        else
        {
            printf(ANSI_COLOR_RED"Plz choose name or id:"ANSI_COLOR_RESET);
        }
    }
}

/* function to delete student , take only index of it */
void delete_student(unsigned char student_index) //take student index //decrease no.of students by one
{
    unsigned char i;
    for(i=student_index; i<(count_st-1); i++)
    {
        arr[i]=arr[i+1];
    }
    count_st--; //decrease no.of students
}
/* function to swap to students
/* take address of them */
void swap_students(stu_t* p_stu1, stu_t* p_stu2)
{
    stu_t temp;
    temp=*p_stu1;
    *p_stu1=*p_stu2;
    *p_stu2=temp;
}


/* sorting the student according to the letters of the alphabet
/* using selection mechanism */
void sorting_names()
{
    int i,j,max_i=0,last=count_st-1;
    for(i=0; i<count_st; i++)
    {
        max_i=0;
        for(j=0; j<=last; j++)
        {
            if(compare_strings(arr[j].name,arr[max_i].name)==1)
            {
                max_i=j;
            }
        }
        swap_students(&arr[max_i],&arr[last]);
        last--;
    }
}

/* sorting the student according to their grades
/* using selection mechanism */
void sorting_grades()
{
    int i,j,max_i=0,last=count_st-1;
    for(i=0; i<count_st; i++)
    {
        max_i=0;
        for(j=0; j<=last; j++)
        {
            if(arr[max_i].percentage>arr[j].percentage)
            {
                max_i=j;
            }
        }
        swap_students(&arr[max_i],&arr[last]);
        last--;
    }
}
/* function to print all students in school */
void print_school ()
{
    int i;
    printf(ANSI_COLOR_YELLOW"%40s    %4s    %s\n"ANSI_COLOR_RESET,"Name","id","percentage");
    for(i=0;i<count_st;i++)
    {
        printf(ANSI_COLOR_BLUE"%40s"ANSI_COLOR_RESET,arr[i].name);
        printf(ANSI_COLOR_GREEN"    %4d    "ANSI_COLOR_RESET,arr[i].id);
        printf(ANSI_COLOR_MAGENTA"%.2f %%\n"ANSI_COLOR_RESET,arr[i].percentage);
    }
        printf("\n==========================================================================================\n");
}







