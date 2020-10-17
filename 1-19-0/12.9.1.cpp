/*
From:ITC
12
Input/Output defects
12.9
Wrong Printf Scanf
12.9.1
Direct output pointer
*/
#include<stdio.h>
using namespace std;
void Direct_output_pointer()
{
	int *a;
	*a=1;
	printf("%d",a);/*Tool should Not detect this line as error*/ /*ERROR:input/output error*/
}

