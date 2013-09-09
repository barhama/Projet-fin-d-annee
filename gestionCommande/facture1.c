#include<stdio.h>
#include<stdlib.h>
typedef struct clt
 {
        int code_client;
        char nom[25];
        char prenom[25];
        char adresse[100];
 }client;
 typedef struct cmd
         {
            client client;
            int quantite;
            float prixunitaire;
         } commande;
typedef struct fture
     {
           client client;
           float montant;
     } facture;

//les commandes seront enregist�es  comme donn�es binaires(Brutes)
void ajout(FILE*com, commande *x){// ici la commande x sera �crit sur le "commandes.dat"
       //pour ajouter une commande d'un client
        com=fopen("commandes.dat", "ab");//mode Ajout en fin de fichier un contenu binaire
        // fwrite sera used pour ecrire sur le fichier
        fclose(com);//on ferme
     }

//fontionc pour trier
int trier(FILE*com){
      int cpt=0,i=0,lect=0,permutation=1,permut=1;
      commande x;
  // "rb+" lecture-ecriture flux binaire sur le fichier commandes.d
      com=fopen("commandes.dat", "rb+");

      while(!feof(com)){
       //pour connaitre le nombre d'�l�ments ie le nombre de bons de commande
         lect=fread(&x,sizeof(commande),1,com);
         if(lect==1)cpt++;
       }
  //on replace le curseur au debut du fichier(� la position 1ier "z�ro" � partir du d�but(2ieme "z�ro"))
       fseek(com,0,0);
  //on creer maintenant un tableau de commande de taille cpt-1=nbre d'eltm
       commande tab[cpt],tmp;
       for (i=0; i<cpt; i++){
      //on lit �l�ment par �l�ment et on stock dans le tableau
           fread(&x,sizeof(commande),1,com);
           tab[i]=x;
      }
  //il faut maintenant permuter le tableau tab
  /*

  si un tri est fait on met permutation=1




  */

//on replace le cursur au d�but pour r��crir le fichier avec le tableau trier.
     fseek(com,0,0);
  //si le fichier fichier n'�tait pas tri� on le fait.
     if(permutation==0){
        //mettre le code
     }
//on ferme le flux du fichier et on lib�re les pointers.
     fclose(com);

  /* si si permutation=0  n'�tait pas tri�
   si permutation=1 il l'�tait d�ja*/
     return permutation;

 }



void facturation1(FILE* com,FILE* fact){
// pour faire une facture par bon il suffit de prendre les bons un � un pour faire un facteur et l'�crire dans fact
        commande c;
        int lect=0;
        facture f;
        int cpt=0,v=0;
        com=fopen("commandes.dat", "rb");
        fact=fopen("factures1.dat", "wb");
        //on recup�re les bon un � un

        while(!feof(com)){
          //on fait les facture une a une en �crivant sur le fichier factures1.dat
          lect=fread(&c,sizeof(commande),1,com);//lecture d'un bloc de taille commande
          if(lect==1){//si le bloc lu est un bon
                  /*
                  il faut ecrire sur facturation

                  */
                  v=1;//pour verifier qu'on a bel et bien �crit ne serait-ce qu'une facture ie le fichier commande n'est pas vide
          }
       }
       fclose(com);
       fclose(fact);
       if(v==0)printf("\t\t Fichier de commande vide Veillez enregistrer une commande");

    }
int nbclient(FILE* com){
    int cpt=0,lect=0;
    commande x,x1;
    trier(com);
    // "rb+" lecture-ecriture flux binaire sur le fichier commandes.d
    com=fopen("commandes.dat", "rb");
    while(!feof(com)){
       lect=fread(&x,sizeof(commande),1,com);
       //comme le fichier est trier �a nous facillite la t�che on compare toujours avec l'�l�ment pr�c�dent x1 . s'il sont diff�rent et lect==1 ; cpt=cpt+1
       if(x1.client.code_client!=x.client.code_client && lect==1)cpt++;
       x1=x;
    }
    //on ferme les flux
    fclose(com);
    //on retourne le nombre de client
    return cpt;

}

int affich1(FILE*com,FILE*fact){
    //cette fonction ne sera appel�e qu'apr�s avoir �tabli le premier fichier de facturation
   commande x;int trouve=0,i=1;facture f;
   com=fopen("commandes.dat", "rb");//mode lesture
   fact=fopen("factures1.dat", "rb");//mod lecture
   while(!feof(com)){
        trouve=fread(&x,sizeof(commande),1,com);
         fread(&f,sizeof(facture),1,fact);
     //comme les 2 fichier ont m�me taille on synchronise les affichages
     if(trouve==1){
         printf("Bon:    %d \n",i);
         printf("Code Client :%s ",x.client.code_client);
         printf("Prenom :%s ",x.client.prenom);
         printf("Nom :%s \n",x.client.nom);
         printf("Quantite:%d ",x.quantite);
         printf("Prix unitaire %fFCFA \n",x.prixunitaire);
         printf("Facture:%d ",i);
         printf("Code client:%d ",f.client.code_client);
         printf("Montant:%fFCFA \n",f.montant);
         printf("\n-----------------------------------------------------------------------\n");
         i++;
     }

   }
   fclose(com);
   fclose(fact);
   return(trouve);
}

int main()
         {


               client c;
               commande com;
               facture fact;
               c.code_client=1;
               printf("entrer le nom du client\n");
               fgets(c.nom, 25, stdin);
               printf("entrer le Prenom du client\n");
               fgets(c.prenom, 25, stdin);
               printf("\n----------------------------------------------\n");

               printf("le code du client est %d\n",c.code_client);
               printf("son nom est %s\n", c.nom);
               printf("son prenom est %s\n", c.prenom);



               system("pause");
               return 0;
         }
