
/**
  *  Universidad de Costa Rica
  *  ECCI
  *  CI0123 Proyecto integrador de redes y sistemas operativos
  *  2025-i
  *  Grupos: 1 y 3
  *
  *   SSL Socket class interface
  *
  * (Fedora version)
  *
 **/

#ifndef SSLSocket_h
#define SSLSocket_h

#include "VSocket.h"
#include <unistd.h>


class SSLSocket : public VSocket{

   public:
      SSLSocket( char* hostip,int port, bool IPv6 = false );				// Not possible to create with UDP, client constructor
      SSLSocket( char *, char *, bool = false );		// For server connections
      SSLSocket( int );
      ~SSLSocket();
      int Connect( const char *, int );
      int Connect( const char *, const char * );
      void ShowCerts();
      const char * GetCipher();
      size_t Read( void *, size_t );
      size_t Write( const void *, size_t );
      size_t Write( const char * );
   private:
      void Init( bool = false );		// Defaults to create a client context, true if server context needed
      void InitContext( bool );
      void LoadCertificates( const char *, const char * );

// Instance variables      
      void * SSLContext;				// SSL context
      void * SSLStruct;					// SSL BIO (Basic Input/Output)

};

#endif

