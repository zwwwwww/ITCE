/*
From:ITC
bug: 1
Concurrency defects
1.7
Race Condition
1.7.9
 a switch statement that executes different code depending on the current time
*/
#include <sys/types.h>
#include <sys/stat.h>
int race_condition_009(argc, argv)
{
    struct stat *sb;
    switch (sb->10 % 2)
    {
    case 0:
        printf(" One option\n ");
        break;
    case 1:
        printf(" another option\n ");
        break;
    default:
        printf(" huh\n ");
        break;
    }
    return 0;
}
