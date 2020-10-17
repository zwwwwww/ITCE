/*
From:ITC
7
Resource management defects
7.5
Memory leakage
7.5.14
 Using two double pointers to the same value within the same function
*/
      
void memory_leak_0014 ()
{
    float * fptr;
    float **fp1 = &fptr;
    float **fp2 = &fptr;
    fptr = NULL;
    {
        float * fptr = *fp1;
        fptr = (float *)calloc(10, sizeof(float)); /*Tool should not detect  this line as error*/ /*No ERROR:Memory Leakage */
        if(fptr!=NULL)
        {
           *(fptr+3) = 50.5;
           *fp1 = fptr;
        }
    }
    {
        float * fptr = *fp2;
        free(fptr);
    }
}
