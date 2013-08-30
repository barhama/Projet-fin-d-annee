#include <stdio.h>
#include <stdlib.h>
         struct clt
         {
                int codeclient;
                char* nom;
                char* prenom;
                char* adresse;
         }client;
         struct cmd
         {
              struct clt code_client;  
                int qualite;
                float prixunit;
                
         } commande;
        struct fture
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
