/*
From:ITC
11
STL defects
11.15
"Invalid pointer
"
11.15.1
Pointer to the reference
*/
void Pointer_to_the_reference(int *p)
{
        int & *q=p;/*Tool should detect this line as error*/ /*ERROR:STL error*/
}