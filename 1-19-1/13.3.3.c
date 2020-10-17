/*
From:ITC
13
"API defects
"
13.3
Obsolete function
13.3.3
Deprecated K&R syntax should not be used for function definition
*/

    int obsolete_function_003(a, b){// Noncompliant K&R C syntax
    int a; /*Tool should detect this line as error*/ /*ERROR:API error*/
    char* b;
}
