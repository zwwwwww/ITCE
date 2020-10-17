/*
From:ITC
2
Dynamic memory defects
2.2
Dynamic buffer overrun
 2.2.18
index
*/

void dynamic_buffer_overrun_018()
{
	int *buf = (int *)calloc(5, sizeof(int));
	int indexes[4] = {3, 4, 5, 6};
	int index = 1;
	if (buf != NULL)
	{
		*(buf + indexes[index]) = 1; /*Tool should Not detect this line as error*/ /*No ERROR:Buffer overrun*/
		free(buf);
	}
}
