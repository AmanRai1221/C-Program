#include<stdio.h>

int main()
{
    int month;
    printf("Enter month number(1-4): \n");
    printf("June\n");
    printf("July\n");
    printf("August\n");
    printf("September\n");
    scanf("%d", &month);

    switch (month)
    {
    case 1:
        printf("Admission Start of all Courses");
        break;
    case 2:
        printf("College open soon");
        break;
    case 3:
        printf("College open soon");
        break;
    case 4:
        printf("Classes Started in first week");
        break;
    default:
        printf("Classes are Running");
        break;
    }
    return 0;
}
