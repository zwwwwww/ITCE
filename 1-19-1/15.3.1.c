/*
From:ITC
15
Control flow defects
15.3
Likely infinite loops
15.3.1
loops condition may be immortal
*/
void Likely_infinite_loops()
{
        int a=1;
        int flag=10;
        while(flag<100)
        {
              a++;
              flag--;/*Tool should detect this line as error*/ /*ERROR:control flow error*/
        }
}
