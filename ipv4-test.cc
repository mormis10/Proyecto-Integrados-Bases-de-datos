/*
 *  Ejemplo de sockets con IPv4
 *
 */

#include <stdio.h>
#include <string.h>

#include "VSocket.h"
#include "Socket.h"

int main( int argc, char * argv[] ) {
   const char * os = "http://os.ecci.ucr.ac.cr/";
   const char * osi = "10.84.166.62";
   const char * ose = "163.178.104.62";
   const char * whale = (char *) "GET /aArt/index.php?disk=Disk-01&fig=whale-1.txt\r\nHTTP/v1.1\r\nhost: redes.ecci\r\n\r\n";

   VSocket * s;	
   char a[512];

   s = new Socket( 's' );
   printf("Ven bailalo, ay ven bailalo\n");
   s->MakeConnection( ose, 80 );
   printf("ZANNDUNGUEA\n");
   s->Write( whale );
   s->Read( a, 512 );
   printf( "%s\n", a);

}

