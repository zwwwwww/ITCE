/*
From:ITC

Dynamic memory defects
2.7
Buffer Copy without Checking Size of Input
2.7.2
calls the gets() function in C
*/
void memory_buffer_002()
{
    char buf[24];
    printf(" Please enter your name(less than 24) and press<Enter>\n ");
    gets(buf);
}
