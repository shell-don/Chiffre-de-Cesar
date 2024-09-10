// Code écrit par : Ocvjku"Rkicuuqw
// Contact : rkicuuqwocvjkuBiockn0eqo 

#include <stdio.h>
#include <stdlib.h>
#include <wctype.h>
#include <wchar.h>
#include <locale.h>

#define DECALAGE 2

int main(void) {
	
	setlocale(LC_ALL, "") ;

	size_t buffer_size = 1024 ;
	char Choice[3] ;

	printf("Voulez-vous chiffrer (1) ou déchiffrer (2) ?\n") ;
	fgets(Choice, 3, stdin) ;

	if (*(&Choice[0]) != '1' && *(&Choice[0]) != '2') {
        	printf("Choix invalide.\n");
        	return 1 ; 
    	}	

	wchar_t* buffer = (wchar_t*)(calloc(buffer_size, sizeof(wchar_t))) ;
	if (buffer == NULL) {
        	fprintf(stderr, "Erreur d'allocation de mémoire pour le tampon\n") ;
        	return 1 ; 
	}
        
	fprintf(stdout, "Entrez le message : \n") ;

        if (fgetws(buffer, buffer_size, stdin) == NULL) {
        	fprintf(stderr, "Erreur de lecture de l'entrée\n") ;
        	free(buffer) ;  // Libérer le tampon alloué dynamiquement
        	return 1 ;
	}

	size_t size_message = wcslen(buffer) ; //ne compte pas le \0 de fin
	wchar_t* message = (wchar_t*)(calloc(size_message + 1, sizeof(wchar_t))) ;
	if (buffer == NULL) {
        	fprintf(stderr, "Erreur d'allocation de mémoire pour le tampon du message\n") ;
        	free(buffer) ;
		return 1 ; 
	}

	wcscpy(message, buffer) ;
	free(buffer) ;

	wchar_t* cipher_message = (wchar_t*)(calloc(size_message + 1, sizeof(wchar_t))) ; 
	if (cipher_message == NULL) {
		fprintf(stderr, "Erreur d'allocation de mémoir pour le tampon cipher message\n") ;
		free(message) ;
		return 1 ;
	}

	if (*(&Choice[0]) == '1') {

	// Chiffrement
	for (int i = 0 ; i < size_message ; i++) {
		cipher_message[i] = (wchar_t)((((unsigned long long)message[i]) + DECALAGE)%0x10FFFF) ;
	} 
	
	// Affichage
	fwprintf(stdout, L"%ls", cipher_message) ;

	free(message) ;
	free(cipher_message) ;
	
	return 0 ;
	}

	if (*(&Choice[0]) == '2') {	

	// Déhiffrement
	for (int i = 0 ; i < size_message ; i++) {
		cipher_message[i] = (wchar_t)((((unsigned long long)message[i]) - DECALAGE)%0x10FFFF) ;
	} 
	
	// Affichage
	fwprintf(stdout, L"%ls", cipher_message) ;

	free(message) ;
	free(cipher_message) ;
	
	return 0 ;
	}

	return 1 ;

}

