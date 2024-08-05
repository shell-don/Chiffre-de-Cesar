#include <stdio.h>
#include <wchar.h>    
#include <locale.h>   

#define MAX_UNICODE 0x3134F          
#define DECALAGE 2
#define MAX_MESSAGE_LENGTH 100

typedef struct { wchar_t caracter ; wchar_t cipher_caracter ; } Mapping ;


int main () {

   setlocale(LC_ALL, "") ;

   wchar_t Caracter[MAX_UNICODE], Cipher_Caracter[MAX_UNICODE], Message[MAX_MESSAGE_LENGTH] ;
   Mapping Alphabet[MAX_UNICODE] ;
   int Choice ;
   
   printf("Voulez-vous Chiffrer (1) ou Déchiffrer (2) ?\n") ;
   scanf("%d", &Choice) ;
   // Vider le tampon d'entrée après scanf
   getchar();

   if (Choice == 1) {

      // établissement des deux tableau et leurs lien
      for (int i = 0 ; i < MAX_UNICODE ; i++) {
         wchar_t wc = i ;                           
         Caracter[i] = wc ; Cipher_Caracter[i] = wc+DECALAGE ;    
         Alphabet[i].caracter = Caracter[i] ;
         Alphabet[i].cipher_caracter = Cipher_Caracter[i] ; 
      } 

      printf("Entrez le Message à Chiffrer : \n") ;
      fgetws(Message, sizeof(Message), stdin) ;                   
   
      // modification du Message par la valeur décalé
      for (int i = 0; Message[i] != '\0' && i < MAX_MESSAGE_LENGTH; i++) {
         for (int j = 0; j < MAX_UNICODE; j++) {
            if (Message[i] == Caracter[j]) {Message[i] = Alphabet[j].cipher_caracter ; break ;}
         }
         wprintf(L"%lc", Message[i]) ;
      }
   return 0 ;
   }              

   if (Choice == 2) { 

      // établissement des deux tableau et leurs lien
      for (int i = 0 ; i < MAX_UNICODE ; i++) {
         wchar_t wc = i ;                           
         Caracter[i] = wc ; Cipher_Caracter[i] = wc-DECALAGE ;    
         Alphabet[i].caracter = Caracter[i] ;
         Alphabet[i].cipher_caracter = Cipher_Caracter[i] ; 
      } 

      printf("Entrez le Message à Déchiffrer : \n") ;
      fgetws(Message, sizeof(Message), stdin) ;                    
   
      // déchiffrement
      for (int i = 0; Message[i] != '\0' && i < MAX_MESSAGE_LENGTH; i++) {
         for (int j = 0; j < MAX_UNICODE; j++) {
            if (Message[i] == Caracter[j]) {Message[i] = Alphabet[j].cipher_caracter ; break ;}
         }
         wprintf(L"%lc", Message[i]) ;
      }
   return 0 ;
   }
return 1 ;    
} 

// Contact : 
// rkicuuqwocvjkuBiockn0eqo 
