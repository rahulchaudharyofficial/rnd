#include "struct.h"

int main(int argc, char const *argv[])
{
    typedef struct Student {
        int r_no;
        char name[20];
        char course[20];
        float fees;
    } student_t;

    printf("size of student = %lu\n", sizeof(student_t));
    return EXIT_SUCCESS;
}
