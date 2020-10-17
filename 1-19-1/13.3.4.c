/*
From:ITC
13
API defects

13.3
Obsolete function
13.3.4
GNU extensions should not be used
*/
                                                                                                                
struct S {
    int f;
};
struct S s[] = { /*Tool should detect this line as error*/ /*ERROR:API error*/
  [0] { // Noncompliant
    f: 0 // Noncompliant
  }
};
int obsolete_function_004() {
    int p;
    scanf("%d", &p);
    switch (p) {
    case 0 ... 1: // Noncompliant   /*Tool should detect this line as error*/ /*ERROR:API error*/
        do_the_thing();
        break;
    case 2:
        //...
    }

    return p ? : 0; // Noncompliant   /*Tool should detect this line as error*/ /*ERROR:API error*/
}
