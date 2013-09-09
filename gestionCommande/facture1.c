#include<stdio.h>
#include<stdlib.h>


#include <stdio.h>
#include <stdlib.h>
   
        typedef struct clt
         {
                int code_client;
                char* nom;
                char* prenom;
                char* adresse;
         }c,c1;
      
         typedef struct cmd
         {
              struct clt code_client;  
                int qualite;
                float prixunit;
                
         } com;
   
       typedef struct fture
         {
               struct clt code_client;
               float montant;
         } fact;
        
              
         int main()
         {
              
              
               struct clt c,c1;
               struct cmd com;
               struct fture fact;
               c.code_client=1;
               c.nom="my name\n";
               system("pause");	
               return 0;
         }
