#define MODERN
#define INCL_BASE
#define INCL_DOS

#include <os2.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <process.h>
#include <fcntl.h>
#include <sys\types.h>
#include <sys\stat.h>
#include <macros.h>


#define PAGESIZE 4096L

void main( argc, argv )
int argc;
char **argv;
{
  void *baseptr;
  register char * ptr;
  register char * bptr;
  register ULONG n;
  ULONG physmem_resmem[2];


  DosQuerySysInfo(QSV_TOTPHYSMEM, QSV_TOTRESMEM,
                  &physmem_resmem, sizeof(physmem_resmem));

  if( argc == 2 )
  {
    /* round up to 4K page */
    n = ( 1024L * atoi( argv[1] ) + 4095 ) & 0xFFFFF000;
    if( n == 0 )
    {
      puts("Usage: allocmem [# of K]\n" ); exit(1);
    }
  }
  else
  {
    n = physmem_resmem[0] - physmem_resmem[1];

  }

  printf( "Physical Memory %ld K  Resident Memory %ld K  Allocating %ld K\n",
           physmem_resmem[0] / 1024L, physmem_resmem[1] / 1024L, n / 1024L );

  DosAllocMem( &baseptr, n, PAG_COMMIT | PAG_WRITE );
  bptr = baseptr;

  ptr = bptr + n - PAGESIZE;
  do
  {
    *ptr = 0; ptr -=PAGESIZE; DosSleep(0);
  }
  while( ptr >= bptr );

  exit(0);
}
