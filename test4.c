#include <stdio.h>
#include <stdlib.h>

struct student{
    int kor;
    int math;
    int eng;
};

int main()
{
    struct student kim;
    struct student hwang;
    struct student people[100];
    int arrsize;
    scanf("%d", &arrsize);

    struct student *pKim = malloc(sizeof(struct student) * arrsize);
    struct student ppeople[arrsize];

    people[0].kor = 1;
    people[99].eng = 3;

    kim.kor = 100;
    kim.math = 80;
    kim.eng = 50;
    
    printf("kor = %d\n", kim.kor);
    printf("math = %d\n", kim.math);
    printf("eng = %d\n", kim.eng);
    
    return 0;
}
