/*
From:ITC

Dynamic memory defects
2.7
Buffer Copy without Checking Size of Input
2.7.1
asks the user to enter their last name and then attempts to store the value entered in the last_name array.
*/

void memory_buffer_001()
{
    char last_name[20];
    printf(" Enter your last name : ");
    scanf(" % s ", last_name);
}
