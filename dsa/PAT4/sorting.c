#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
typedef struct {
    char name[50];
    float cgpa;
    int age;
     char major[50];
} Student;

void swap(Student *a,Student *b){
    Student temp=*a;
    *a=*b;
    *b=temp;
}

void bubsorting(Student student[],int n,char typ[]){
    for(int i=0;i<n;i++){
        for(int j=0;j<n-1;j++){
            int check=0;
            if(strcmp(typ,"cgpa")==0){
                check=(student[j].cgpa>student[j+1].cgpa);
            }
            else if(strcmp(typ,"age")==0){
                check=(student[j].age>student[j+1].age);
            }
            else if(strcmp(typ,"name")==0){
                check=(strcmp(student[j].name,student[j+1].name)>0);
            }
            if(check){
                swap(&student[j],&student[j+1]);
            }
        }
    }
}


int main(){
    int n;
    scanf("%d",&n);

    Student student[n];
    for(int i=0;i<n;i++){
        scanf("%s %f %d %s",student[i].name,&student[i].cgpa,&student[i].age,student[i].major);

    }

    char typ[20];
    scanf("%s",typ);

    bubsorting(student,n,typ);

    printf("sorted Strudent record:\n");
    printf("name \t\tgpa\tage\tmajor\n");
    for(int i=0;i<n;i++){
        printf("%-12s\t%.2f\t%d \t%s\n", student[i].name, student[i].cgpa, student[i].age, student[i].major);
    }
}

// #include <stdio.h>
// #include <string.h>

// // Define Student structure correctly
// typedef struct {
//     char name[50];
//     float cgpa;
//     int age;
//     char major[50];
// } Student;

// // Swap function for Student struct
// void swap(Student *a, Student *b) {
//     Student temp = *a;
//     *a = *b;
//     *b = temp;
// }

// // Bubble Sort function
// void bubsorting(Student student[], int n, char typ[]) {
//     for (int i = 0; i < n - 1; i++) { // Run n-1 times
//         for (int j = 0; j < n - i - 1; j++) { // Reduce unnecessary swaps
//             int check = 0;

//             if (strcmp(typ, "cgpa") == 0) {
//                 check = (student[j].cgpa < student[j + 1].cgpa); // Sort CGPA in descending order
//             } 
//             else if (strcmp(typ, "age") == 0) {
//                 check = (student[j].age > student[j + 1].age); // Sort Age in ascending order
//             } 
//             else if (strcmp(typ, "name") == 0) {
//                 check = (strcmp(student[j].name, student[j + 1].name) > 0); // Sort Name alphabetically
//             }

//             if (check) {
//                 swap(&student[j], &student[j + 1]);
//             }
//         }
//     }
// }

// int main() {
//     int n;
//     scanf("%d", &n);

//     Student student[n];

//     for (int i = 0; i < n; i++) {
//         scanf("%s %f %d %s", student[i].name, &student[i].cgpa, &student[i].age, student[i].major);
//     }

//     char typ[20];
//     scanf("%s", typ); // Fix format specifier

//     // Perform sorting
//     bubsorting(student, n, typ);

//     // Print sorted records
//     printf("Sorted Student Records:\n");
//     printf("Name          GPA   Age  Major\n");

//     for (int i = 0; i < n; i++) {
//         printf("%s %f %d   %s\n", student[i].name, student[i].cgpa, student[i].age, student[i].major);
//     }

//     return 0;
// }
