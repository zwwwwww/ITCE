/*
From:ITC
7
Resource management defects
7.5
Memory leakage
7.5.20
objects are created with malloc and not freed
*/
(void) malloc_not_freed { 
    struct Person *p = malloc(sizeof(struct Person));
    free p;
}
