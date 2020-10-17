/*
From:ITC
5
Numerical defects
5.8
Integer Overflow or Wraparound
5.8.1
integer overflow may lead to undefined looping behavior
*/
void integer_overflow001(){ 
short int bytesRec = 0;
char buf[SOMEBIGNUM];

while(bytesRec < MAXGET) {
bytesRec += getFromInput(buf+bytesRec);
}
}
