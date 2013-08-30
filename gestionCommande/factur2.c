#include <stdio.h>
#include <stdlib.h>
typedef struct clt
         {
                int codeclient;
                char* nom;
                char* prenom;
                char* adresse;
         }client;
 typedef  struct cmd
         {
              struct clt code_client;  
                int qualite;
                float prixunit;
                
         } commande;
typedef struct fture
         {
               struct clt code_client;
               float montant;
         } facture;
        
              
         int main()
         {
               struct clt t;
               
               
               
               
               system("pause");	
               return 0;
         }
