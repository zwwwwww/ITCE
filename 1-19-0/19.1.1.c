/*
From:ITC
19
AssertionError
19.1
unreachable return
19.1.1
*
*/

#define NDEBUG

int main( void )
{
       FILE *fp;
    
       fp = fopen( "test.txt", "w" );
       assert( fp );                           
       fclose( fp );
    
       fp = fopen( "noexitfile.txt", "r" );
       assert( fp );                           
       fclose( fp );                          
       return 0;
}