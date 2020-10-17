/*
From:ITC
13
"API defects
"
13.3
Obsolete function
13.3.4
GNU extensions should not be used
*/
                                                                                                   
struct S {
    int f;
};
struct S s[] = {
  [0] = {/*Tool should Not detect this line as error*/ /*ERROR:API error*/
    .f = 0
  }
};

int obsolete_function_004() {
    int p;
    scanf("%d ", &p);
    switch (p) {
    case 0:/*Tool should Not detect this line as error*/ /*ERROR:API error*/
    case 1:
        do_the_thing();
        break;
    case 2:
        //...
    }

    return p ? p : 0;/*Tool should Not detect this line as error*/ /*ERROR:API error*/
}
