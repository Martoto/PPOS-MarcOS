#include <stdio.h>
#include <stdlib.h>
#include "ppos.h"

// operating system check
#if defined(_WIN32) || (!defined(__unix__) && !defined(__unix) && (!defined(__APPLE__) || !defined(__MACH__)))
#warning Este codigo foi planejado para ambientes UNIX (LInux, *BSD, MacOS). A compilacao e execucao em outros ambientes e responsabilidade do usuario.
#endif

task_t Pang, Peng, Ping, Pong, Pung ;

void Body (void * arg)
{
   int i,j ;

   for (i=0; i<10; i++)
   {
      printf ("%s %d\n", (char *) arg, i) ;
      for (j=0; j<10000000; j++) ;
   }
   printf ("%s FIM\n", (char *) arg) ;
   task_exit (0) ;
}

int main (int argc, char *argv[])
{
   printf ("Main INICIO\n");

   ppos_init () ;

   task_create (&Pang, Body, "    Pang") ;
   task_create (&Peng, Body, "        Peng") ;
   task_create (&Ping, Body, "            Ping") ;
   task_create (&Pong, Body, "                Pong") ;
   task_create (&Pung, Body, "                    Pung") ;

   task_join(&Pang);
   task_join(&Peng);
   task_join(&Ping);
   task_join(&Pong);
   task_join(&Pung);

   printf ("Main FIM\n");
   exit (0);
}
