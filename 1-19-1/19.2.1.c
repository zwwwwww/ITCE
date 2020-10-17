/*
From:ITC
19
AssertionError
19.2
no assertion
19.2.1
*
*/

struct my{
  char* x;
  int y;
};
int main(void){
  struct my *t = malloc(sizeof(struct my));
  t->x = malloc(10*sizeof(char));
  t->x=""123"";
  t->y=1;
  free(t);
  return 1;
}
