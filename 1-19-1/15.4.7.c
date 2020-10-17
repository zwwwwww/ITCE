/*
From:ITC
15
Control flow defects
15.4
Switches
15.4.7
empty switch statement
*/
                                                                                                            
void switch_007(){
    int i;
    scanf("%d ", &i);
    switch (i)              // empty switch statement
    {/*Tool should detect this line as error*/ /*ERROR:control flow error*/
    }
}
