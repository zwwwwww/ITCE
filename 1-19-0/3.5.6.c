/*
From:ITC
3
Inappropriate code
3.5
Return value of function never checked
3.5.6
Function called in a while loop
*/

float (*function_return_value_unchecked_006_func_001())[4]
{
	float(*p)[4];
	int i, j;
	float arr[4][4];
	p = (float(*)[])calloc(1, sizeof(arr));
	if (p != NULL)
	{
		memset(p, 1.00, 16);
	}
	if (p != NULL)
	{
		for (i = 0; i < 4; i++)
		{
			for (j = 0; j < 4; j++)
			{
				*(p[i] + j) += (i + j);
			}
		}
	}
	return p;
}

void function_return_value_unchecked_006()
{
	float(*ptr)[4];
	int i = 10, j;
	while (i > 0)
	{
		ptr = function_return_value_unchecked_006_func_001(); /*Tool should not detect this line as error*/ /*No ERROR:Return value of function never checked*/
		for (j = 0; j < 4; j++)
		{
			if (*(ptr[j]) > 0)
			{
				*(ptr[j] + 1) += i;
			}
		}
		free(ptr);
		i--;
	}
}
