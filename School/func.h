#ifndef FUNC_H_INCLUDED
#define FUNC_H_INCLUDED
#define size_materials 13



#define ANSI_COLOR_RED "\x1b[31m"
#define ANSI_COLOR_GREEN "\x1b[32m"
#define ANSI_COLOR_YELLOW "\x1b[33m"
#define ANSI_COLOR_BLUE "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN "\x1b[36m"
#define ANSI_COLOR_RESET "\x1b[0m"
#define ANSI_COLOR_WHITE "\x1b[47m"
#define COLOR_BOLD "\e[1m"
#define COLOR_OFF "\e[m"

#define AC_GREEN "\x1b[32m"

typedef struct{
char name[10];
unsigned char max_degree;
unsigned char mark;
unsigned char flag_choised;
}mat_t;

typedef struct {
char name[10];
unsigned char age;
char phone[12];
} person_t;

typedef struct{
char name[40];
unsigned char id;
unsigned char age;
int phone[11];
person_t father;
person_t mother;
unsigned char brothers_n;
person_t* brothers;
unsigned char mats_n;
mat_t* materials;
float percentage;
char grade[3];
} stu_t;
 extern stu_t arr[];
 extern mat_t mats[];
 extern short count_st;
 extern char buff;

/* function to get unsigned char number
/* if number>255 , 255 will stored
/* return 0 if issue occured , 1 if all alright */
int scanNum_u8(char* Pnum);
/* function to get string with limited size
/* return 0 if issue occcured , 1 if all alright */
int scan_string(char* str , int size);
int string_length(char* str);

/* return 0 if issue occured, 1 if all alright*/
int print_string(char* str);

// return 0 if invalid numberPhone, -1 if skip,1 if all alright
int scan_phone(char* ph);
void insert_materials(mat_t* Pmat,int size);

void add_student (stu_t* arr);

int search_student(void);

void copy_string(char* str1, char* str2);

void swap_students(stu_t* p_stu1, stu_t* p_stu2);
void sorting_names();
void sorting_grades();
void process_shape();
void print_school ();




#endif // FUNC_H_INCLUDED
