#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include <conio.h>
#include <time.h>


//declaration des structures
typedef struct{
 	int jour,annee,mois;

 }Date;

 typedef struct {
 	char Nom[20],Prenom[20],Adressse[50],NumAbonnement[40],NumConteur[30],IdClient[20],Mot_pass[30],Cartier[12],residence[12];
 	Date d1;
 }Client;
 typedef struct{
 	char IdClient[20],Num_Facture[20];
 	float Montant, Consommation;
 	Date sortie,Limite;
 }Facture;

 //Carte bancaire
  typedef struct {
     char nom_p[20],prenom_p[20];
     int Num_carte,Num_verif;
 }carte_bancaire;
// Fin declaration des structure***>>> declaration des v globales:


 Client V;
//declaration des fichier
FILE *fp,*fp1,*fp3,*fpm,*fp4,*fp5,*fp6;
// fin declaration des fichie
Facture F1,Res;




//all fct about Client
//<<<<<<<<<<<fcts de base
//>>>>
int RechercherClient22(){

	Client C1;
    int tr=0;
    fp=fopen("Clients.txt","a+");
    if (fp==NULL){
        printf("ERREUR\n");
        exit(1);
    }
    else{

    do{
    printf("Entrer l'ID de Client :       ");
    scanf("%s",Res.IdClient);
    }while(Res.IdClient<0);

    while(!feof(fp))
    {
        fscanf(fp,"%s   %s   %s    %s    %s   %s    %s\n",&C1.Nom,&C1.Prenom,&C1.Adressse,&C1.NumAbonnement,&C1.NumConteur,&C1.IdClient,&C1.Mot_pass);
        if(strcmp(C1.IdClient,Res.IdClient)==0)
        {
            tr=1;
            break;
        }
    }
    fclose(fp);
    if(tr==0){
        firstrow();
        midtext();
    printf("\t\t Le client n'existe pas!!!!!\n");
    lastrow();
    }

}
return tr;
}
//>>>>> fin
//chercher client22: sans affichage
int RechercherClient22_nonaffi(){

	Client C1;
    int tr=0;
    fp=fopen("Clients.txt","a+");
    if (fp==NULL){
        printf("ERREUR\n");
        exit(1);
    }

    printf("\n\n\t\t VEUILLEZ SAISIR L\'ID :  ");
    scanf("%s",Res.IdClient);
    printf("\n");


    while(!feof(fp))
    {
        fscanf(fp,"%s   %s   %s    %s    %s   %s    %s\n",&C1.Nom,&C1.Prenom,&C1.Adressse,&C1.NumAbonnement,&C1.NumConteur,&C1.IdClient,&C1.Mot_pass);
        if(strcmp(C1.IdClient,Res.IdClient)==0)
        {
            tr=1;
            break;
        }
    }
    fclose(fp);

return tr;

}
//fin chercher client22: sans affichage
//<<<<<<<<<<<<<



//fonction ajout d'un client mode francais
void AjouterClient()
{

	Client C1;
    int n,tr=0;
    midrowssec();
   printf("\n\n\t\t");
    n=RechercherClient22_nonaffi();

    if(n==1){
        firstrow();
        midtext();
        printf("\t\tle client sous ce ID existe deja !!");
         lastrow();
    }
    else{

    fp=fopen("Clients.txt","a+");//<<<<<<
    if (fp==NULL){
        printf("Impossible d'ouvrir le fichier des clients \n");
        exit(1);
    }
         midrowssec();printf("\n\n\t\tSaisir le Nom : ");
        scanf("%s", C1.Nom);
        midrowssec();
        printf("\n\n\t\tSaisir le Prenom : ");
        scanf("%s", C1.Prenom);
        midrowssec();
        printf("\n\n\t\tSaisir la Ville de Client : ");
       scanf("%s",C1.Adressse);
       fp1=fopen("AdresseComp.txt","a+");

    if (fp1==NULL){
        printf("Impossible d'ouvrir le fichier des adresses \n");
        exit(1);
    }
       midrowssec();
       printf("\n\n\t\tSaisir le Quartier : ");
       scanf("%s",C1.Cartier);
       midrowssec();
       do{
       printf("\n\n\t\tSaisir le numero de Residence : ");
       scanf("%s",C1.residence);
       }while(C1.residence[0]=='-');
       fprintf(fp1,"%s  %s  %s  %s  \n",Res.IdClient,C1.Adressse,C1.Cartier,C1.residence);

       fclose(fp1);//<<<<<<<<<
       midrowssec();
       do{
        printf("\n\nEntrez le num%cro d'abonnement compos%c de 1 caractere et 7 chiffres exemple ( M1234567):  ",130,130);
        scanf("%s",C1.NumAbonnement);
        }while(strlen(C1.NumAbonnement)!=8 ||C1.NumAbonnement[0]<'A' || C1.NumAbonnement[0]>'Z' );
        midrowssec();
        do{
        printf("\n\nSaisir le Num%cro de Contour Compos%c de 1 Caractere et 7 chiffres exemple( M1234567 ):  ",130,130);
        scanf("%s", C1.NumConteur);
        }while(strlen(C1.NumConteur)!=8 ||C1.NumConteur[0]<'A' || C1.NumConteur[0]>'Z' );
        midrowssec();
        do{
       printf("\n\n\tSaisir Un mot de passe de 6 chifrre au Client:  ");
       scanf("%s", C1.Mot_pass);
       }while(strlen(C1.Mot_pass)!=6);
        fprintf(fp,"%s   %s   %s    %s    %s   %s   %s\n",C1.Nom,C1.Prenom,C1.Adressse,C1.NumAbonnement,C1.NumConteur,Res.IdClient,C1.Mot_pass);

          fclose(fp);//<<<<<<<<<<
     fp3=fopen("ID_and_Passowrd.txt","a+");//<<<<<
    if (fp3==NULL){
        printf("Impossible d'ouvrir le fichier \n");
        exit(1);
    }
    fprintf(fp3,"%s  %s  \n",Res.IdClient,C1.Mot_pass);
    fclose(fp3);//<<<<<<<<<<<<<
    firstrow();
    midtext();
    printf("\t\t\t enregistrement avec succ%ces",130);
    lastrow();
    }

}
//fin fct ajouter Client mode francais

//fonction affichage fichies des clients mode francais
//fct affichage des clients mode francais

void afficheLesclientLi()
{

    Client C1;
    C1.Nom[0]=EOF;
    int test=0;
    fp=fopen("Clients.txt","a+");
     if(fp==NULL){
        printf("Echec d'overture :\n\n");
        exit(1);
 }
       printf("\n\n----------------------------------les Clients-----------------------------------------\n\n");
       firstrow();
      while(!feof(fp)){
        fscanf(fp,"%s   %s   %s    %s    %s   %s    %s\n",&C1.Nom,&C1.Prenom,&C1.Adressse,&C1.NumAbonnement,&C1.NumConteur,&C1.IdClient,&C1.Mot_pass);
       if(C1.Nom[0]!=EOF){
            test=1;
       midtext();
       printf("\n\t\t\tNom                 :  %s    \n\t\t\tPrenom              :  %s    \n\t\t\tadresse             :  %s   \n\t\t\tNum%cro d'abenement  :  %s     \n\t\t\tNumero de conteur   :  %s       \n\t\t\tId de client        :  %s     \n\t\t\tMot de passe        :  %s\n",C1.Nom,C1.Prenom,C1.Adressse,130,C1.NumAbonnement,C1.NumConteur,C1.IdClient,C1.Mot_pass);
        midrows();

    }
      }

   fclose(fp);
   if(test==0)
    printf("\n\n\t\t\t\t\t(VIDE)\n");
   lastrow();


}
//fin fct affichage des clients mode francais
//fonction de modification d'info de client mode francais
void ModifficationInfoClient(){

    Client C1;
	char tempville[20];
    int  n;
   midrowssec();
   printf("\n\n\t\t");
    n=RechercherClient22();
    if(n==1){
    fp=fopen("Clients.txt","a+");
    if (fp==NULL){
        printf("Impossible d'ouvrir le fichier \n");
        exit(1);
    }

    fpm=fopen("tempC.txt","w");
    if (fpm==NULL){
        printf("Impossible d'ouvrir le fichier \n");
        exit(1);
      }

    	while(fscanf(fp,"%s   %s   %s    %s    %s   %s   %s\n",&C1.Nom,&C1.Prenom,&C1.Adressse,&C1.NumAbonnement,&C1.NumConteur,&C1.IdClient,&C1.Mot_pass)==7)
    	{
    		if(strcmp(Res.IdClient,C1.IdClient)==0)
    {

    	midrowssec();
    	printf("\n\n\t\tEntrer le nouveau Nom:       ");
    	scanf("%s", C1.Nom);
        midrowssec();
        printf("\n\n\t\tEntrer le Prenom     :       ");
        scanf("%s", C1.Prenom);
        midrowssec();
        printf("\n\n\t\tEntrer la ville      :       ");
        scanf("%s", C1.Adressse);
        strcpy(tempville,C1.Adressse);
       midrowssec();
     do{
        printf("\n\nEntrer le Numero d'Abonemment Compose de Un Caractere et 7 chifrre (exemple : M1234567)  : ");
        scanf("%s",C1.NumAbonnement);
         }while(strlen(C1.NumAbonnement)!=8 || C1.NumAbonnement[0]<'A' || C1.NumAbonnement[0]>'Z');
         midrowssec();
    do{
        printf("\n\nSaisir le Numero de Contour Compose de 1 Caractere et 7 chiffres (exemple : M1234567)  : ");
        scanf("%s", C1.NumConteur);
      }while(strlen(C1.NumConteur)!=8 || C1.NumConteur[0]<'A' || C1.NumConteur[0]>'Z');
      midrowssec();
       }
       fprintf(fpm,"%s   %s   %s    %s    %s   %s   %s\n",C1.Nom,C1.Prenom,C1.Adressse,C1.NumAbonnement,C1.NumConteur,C1.IdClient,C1.Mot_pass);

		}
		fclose(fp);
		fclose(fpm);
		remove("Clients.txt");
		rename("tempC.txt","Clients.txt");
		fp1=fopen("AdresseComp.txt","a+");
        if(fp1==NULL){
         printf("Impossible d'ouvrir le fichier  ");
        exit(1);
        }
        fp3=fopen("tempA.txt","w");
        if (fp3==NULL){
        printf("Impossible d'ouvrir le fichier \n");
        exit(1);
        }
        while(fscanf(fp1,"%s  %s  %s  %s  \n",C1.IdClient,C1.Adressse,C1.Cartier,C1.residence)==4){
            if(strcmp(Res.IdClient,C1.IdClient)==0)
    		{
    		    printf("\n\n\t\tDonner le nom du quartier                 :       ");
    		    scanf("%s",C1.Cartier);
    		    midrowssec();
    		    printf("\n\n\t\tDonner le numero de residence:       ");
    		    scanf("%s",C1.residence);
    		    fprintf(fp3,"%s  %s  %s  %s  \n",C1.IdClient,tempville,C1.Cartier,C1.residence);
    		}
    		else
            fprintf(fp3,"%s  %s  %s  %s  \n",C1.IdClient,C1.Adressse,C1.Cartier,C1.residence);


        }
        fclose(fp1);
        fclose(fp3);
        remove("AdresseComp.txt");
        rename("tempA.txt","AdresseComp.txt");


		firstrow();
		midtext();
    printf("\t\t Modofication effectu%ce avec succ%ces",130,130);
    lastrow();
	}
}
//fin de fonction de modification

//fonction de recherche d'un client mode francais

	void RechercherClient(){

	Client C1;
    int tr=0;
    fp=fopen("Clients.txt","a+");
    if (fp==NULL){
        printf("Impossible d'ouvrir le fichier \n");
        exit(1);
    }


    firstrow();
    midtext();
    printf("\n\n\t\tEntrer l'Id de Client    :  ");
    scanf("%s",Res.IdClient);
     lastrow();

    while(!feof(fp))
    {
        fscanf(fp,"%s   %s   %s    %s    %s   %s    %s\n",&C1.Nom,&C1.Prenom,&C1.Adressse,&C1.NumAbonnement,&C1.NumConteur,&C1.IdClient,&C1.Mot_pass);
        if(strcmp(C1.IdClient,Res.IdClient)==0)
        {
            tr=1;
            break;
        }
    }
    fclose(fp);
    if(tr==1){
    midrows();
    printf("\n\t\t\tNom                 :  %s    \n\t\t\tPrenom              :  %s    \n\t\t\tadresse             :  %s   \n\t\t\tNum%cro d'abenement  :  %s     \n\t\t\tNumero de conteur   :  %s       \n\t\t\tId de client        :  %s     \n\t\t\tMot de passe        :  %s\n",C1.Nom,C1.Prenom,C1.Adressse,130,C1.NumAbonnement,C1.NumConteur,C1.IdClient,C1.Mot_pass);
    }
    else{
    firstrow();
    midtext();
    printf("\t\tCe client n'existe pas!!!!!\n");
    lastrow();
    }


}
// fiin fonction de recherche d'un client mode fr

//fonction suprimer client mode francais

void SuprimerClient(){

    Client C1;
	char Id[20];
    int n,tr=0;
    firstrow();
    printf("\n\n\t\t\t");
    n=RechercherClient22();
    if(n==1){
    fp=fopen("Clients.txt","a+");
    if (fp==NULL){
        printf("Impossible d'ouvrir le fichier \n");
        exit(1);
    }
 fpm=fopen("temp.txt","w");
 if (fpm==NULL){
        printf("Impossible d'ouvrir le fichier \n");
        exit(1);
    }

    		while(fscanf(fp,"%s   %s   %s    %s    %s   %s   %s\n",&C1.Nom,&C1.Prenom,&C1.Adressse,&C1.NumAbonnement,&C1.NumConteur,&C1.IdClient,&C1.Mot_pass)==7)
    	{
    		if(strcmp(Res.IdClient,C1.IdClient)!=0)
    			   fprintf(fpm,"%s   %s   %s    %s    %s   %s   %s\n",C1.Nom,C1.Prenom,C1.Adressse,C1.NumAbonnement,C1.NumConteur,C1.IdClient,C1.Mot_pass);
            }

    		fclose(fp);
    		fclose(fpm);
		remove("Clients.txt");
		rename("temp.txt","Clients.txt");
		 fp4=fopen("AdresseComp.txt","a+");
    if (fp4==NULL){
        printf("Impossible d'ouvrir le fichier \n");
        exit(1);
    }
 fpm=fopen("temp.txt","w");
 if (fpm==NULL){
        printf("Impossible d'ouvrir le fichier \n");
        exit(1);
    }
    		while(fscanf(fp4,"%s  %s  %s  %s  \n",&C1.IdClient,&C1.Adressse,&C1.Cartier,&C1.residence)==4)
    	{
    		if(strcmp(Res.IdClient,C1.IdClient)!=0)
    			   fprintf(fpm,"%s  %s  %s  %s  \n",C1.IdClient,C1.Adressse,C1.Cartier,C1.residence);
        }

    		fclose(fp4);
    		fclose(fpm);
		remove("AdresseComp.txt");
		rename("temp.txt","AdresseComp.txt");
		 fp5=fopen("ID_and_Passowrd.txt","a+");
		  fpm=fopen("temp.txt","w");
    if (fp5==NULL){
        printf("Impossible d'ouvrir le fichier \n");
        exit(1);
    }
    if (fpm==NULL){
        printf("Impossible d'ouvrir le fichier \n");
        exit(1);
    }

    while(!feof(fp5)){

             fscanf(fp5,"%s  %s  \n",C1.IdClient,C1.Mot_pass);
             if(strcmp(Res.IdClient,C1.IdClient)!=0)
                fprintf(fpm,"%s  %s  \n",C1.IdClient,C1.Mot_pass);

    }
    fclose(fp5);
    fclose(fpm);
		remove("ID_and_Passowrd.txt");
		rename("temp.txt","ID_and_Passowrd.txt");

    firstrow();
    midtext();
    printf("\t  Modification effectu%ce avec succ%cs !",130,138);
   lastrow();
 }
}

// fin fonction suprimer client


  // fin fonction affichage fichies des clients

void afficheId_Adresse()
{   int test=0;
    Client C1;
    C1.IdClient[0]=EOF;
    fp6=fopen("AdresseComp.txt","a+");
     if(fp6==NULL){
        printf("Echec d'overture :\n\n");
        exit(1);
 }
        printf("\tLes adresses des Clients sont:\n");
        firstrow();
      while(!feof(fp6)){
            fscanf(fp6,"%s  %s  %s  %s  \n",C1.IdClient,C1.Adressse,C1.Cartier,C1.residence);
            if(C1.IdClient[0]!=EOF){
            test=1;
            midtext();
            printf("\t\tl\'Id:%s \n \t\t\tVille:%s   \n \t\t\tCartier:%s \n\t\t\tResidence:%s",C1.IdClient,C1.Adressse,C1.Cartier,C1.residence);
            midrows();
            }
    }
   fclose(fp6);
   if(test==0)
        printf("\n\n\t\t\t\t\t(VIDE)\n");
     lastrow();

}




void afficheId_mdp()
{   int test=0;
    Client C1;
    C1.IdClient[0]=EOF;

    fp6=fopen("ID_and_Passowrd.txt","a+");
     if(fp6==NULL){
        printf("Echec d'overture :\n\n");
        exit(1);
 }
       printf("\n\n------------------------------lES Ids et les Mots de passe----------------------\n\n");
       firstrow();
      while(!feof(fp6)){
    fscanf(fp6,"%s  %s  \n",C1.IdClient,C1.Mot_pass);
    if(C1.IdClient[0]!=EOF){
            test=1;
     midtext();
     printf("L\'Id :%s  Mot_de_pass:%s",C1.IdClient,C1.Mot_pass);
     midrows();
    }
   }

   fclose(fp6);
   if(test==0)
   printf("\n\n\t\t\t\t\t(VIDE)\n");
   lastrow();

}

//rechercher une facture pour l'ajouter


int RechercherFacture_test(){
char NF[20];
	int tr=0;
	fp1=fopen("Factures.txt","a+");
    if(fp1==NULL){
        printf("Impossible d'ouvrir le fichier \n");
        exit(1);
    }
    printf("entrer le Numero de facture :\n");
    scanf("%s",NF);
    strcpy(Res.Num_Facture,NF);
    while(!feof(fp1)){
    	fscanf(fp1,"%s  %s  %f  %f  %d  %d  %d  %d  %d  %d\n",F1.Num_Facture,F1.IdClient,&F1.Montant,&F1.Consommation,&F1.Limite.jour,&F1.Limite.mois,&F1.Limite.annee,&F1.sortie.jour,&F1.sortie.mois,&F1.sortie.annee);
    	if(strcmp(NF,F1.Num_Facture)==0 && strcmp(Res.IdClient,F1.IdClient)==0){
            tr=1;
            printf("cette facture existe deja !!!! :\n");
    		printf("Numero de facture:%s\n",F1.Num_Facture);
    		printf("Id de Client:%s\n",F1.IdClient);
    		printf("Montant:%.2f\n",F1.Montant);
    		printf("Consommation:%.2f\n",F1.Consommation);
    		printf("Date de Sortie:%d %d %d\n",F1.sortie.jour,F1.sortie.mois,F1.sortie.annee);
    		printf("Date de Limite:%d %d %d\n",F1.Limite.jour,F1.Limite.mois,F1.Limite.annee);
    		break;
		}

	}

fclose(fp1);
  return tr;
}


//recherche Facture 3 modes*********<<<


 int RechercherFacture(int test){
	int n,tr=0;

    n=RechercherClient22();
    if(n==1){
       tr=1;
            fp1=fopen("Factures.txt","a+");
        if(fp1==NULL){
        printf("Impossible d'ouvrir le fichier \n");
        exit(1);
         }
         midrowssec();
        do{
        printf("\n\n\t\tEntrer le num%cro de facture:  ",130);
        scanf("%s",Res.Num_Facture);
        }while(Res.Num_Facture<0);
    while(!feof(fp1)){

    	fscanf(fp1,"%s  %s  %f  %f  %d  %d  %d  %d  %d  %d\n",F1.Num_Facture,F1.IdClient,&F1.Montant,&F1.Consommation,&F1.Limite.jour,&F1.Limite.mois,&F1.Limite.annee,&F1.sortie.jour,&F1.sortie.mois,&F1.sortie.annee);
    	if((strcmp(Res.IdClient,F1.IdClient)==0 )&& (strcmp(Res.Num_Facture,F1.Num_Facture)==0)){
            tr=2;
            if(test!=2){
            if(test==1){
                    firstrow();
                    midtext();
          printf("\t\tCette facture %cxiste d%cja !!\n",130,130);
          lastrow();


            }
            printf("\t\tNum%cro de facture:%s\n",130,F1.Num_Facture);
    		printf("\t\tId de Client:%s\n",F1.IdClient);
    		printf("\t\tMontant:%f\n",F1.Montant);
    		printf("\t\tConsommation:%f\n",F1.Consommation);
    		printf("\t\tDate de Sortie: %d / %d / %d\n",F1.sortie.jour,F1.sortie.mois,F1.sortie.annee);
    		printf("\t\tDate de Limite: %d / %d / %d\n",F1.Limite.jour,F1.Limite.mois,F1.Limite.annee);
            }
    	break;

    	}
    }
    if(tr==1 && test!=1){
    firstrow();
    midtext();
    printf("\t\tcette facture n\'existe pas pour ce client !!");
    lastrow();
    }

fclose(fp1);

  } return tr;
   }

//fin recherche Facture 3 modes

//fct ajouter Facture

void AjouterFacture2(){
 int n=1;
      midrowssec();
      printf("\n\n\t\t");
      n=RechercherFacture(1);  // fct specifique!!
         if(n==1)
        {
           fp1=fopen("Factures.txt","a+");
           if(fp1==NULL){
            printf(" erreur d ouverture fichier factures!!");
           }

           else{
                midrowssec();
                do{
            printf("\n\n\t\tEntrer le Montant mensuel en DH :  ");
            scanf("%f",&F1.Montant);
                }while(F1.Montant<0);
            midrowssec();
            do{
            printf("\n\n\t\tEntrer la Consommation mensuelle en kWh:  ");
            scanf("%f",&F1.Consommation);
            }while(F1.Consommation<0);
            midrowssec();
            do{
            printf("\n\n\t\tEntrer La Date Limite: J/M/A:  \n");
            printf("\t\tjour : ");
            scanf("%d",&F1.Limite.jour);
            printf("\t\tmois : ");
            scanf("%d",&F1.Limite.mois);
            printf("\t\tann%ce : ",130);
            scanf("%d",&F1.Limite.annee);
            }while(F1.Limite.jour<0||F1.Limite.mois<0||F1.Limite.annee<0);
            midrowssec();
            do{
            printf("\n\n\t\tEntrer La Date de Sortie: J/M/A:  \n");
             printf("\t\tjour : ");
            scanf("%d",&F1.sortie.jour);
            printf("\t\tmois : ");
            scanf("%d",&F1.sortie.mois);
            printf("\t\tann%ce : ",130);
            scanf("%d",&F1.sortie.annee);
            }while(F1.sortie.jour<0||F1.sortie.mois<0||F1.sortie.annee<0);
            midrowssec();
            fprintf(fp1,"%s  %s  %f  %f  %d  %d  %d  %d  %d  %d\n",Res.Num_Facture,Res.IdClient,F1.Montant,F1.Consommation,F1.Limite.jour,F1.Limite.mois,F1.Limite.annee,F1.sortie.jour,F1.sortie.mois,F1.sortie.annee);
            fclose(fp1);


            firstrow();
            midtext();
            printf("\t\t\tl\'ajout a %ct%c effectu%c avec succ%cs.",130,130,130,138);
            lastrow();


            }
       }

}
// fin fct ajouter Facture


//fct aficher facture

void afficherFactures()
{ int test=0;
Res.Num_Facture[0]=EOF;
    fp6=fopen("Factures.txt","a+");
     if(fp6==NULL){
        printf("Impossible d'ouvrir le fichier :\n\n");
        exit(1);
 }
       printf("\n\n------------------------------Les Factures qui existent sont:----------------------\n\n");
      firstrow();
      while(!feof(fp6)){

            fscanf(fp6,"%s  %s  %f  %f  %d  %d  %d  %d  %d  %d\n",&Res.Num_Facture,&Res.IdClient,&Res.Montant,&Res.Consommation,&Res.Limite.jour,&Res.Limite.mois,&Res.Limite.annee,&Res.sortie.jour,&Res.sortie.mois,&Res.sortie.annee);
            if(Res.Num_Facture[0]!=EOF){
                    test=1;
            midtext();
             printf("\n\t\t\tNumero de Facture :    %s\n\t\t\tId de client :    %s\n\t\t\t Montant:     %f DH\n\t\t\t Consomation  :    %f(Kwh)\n\t\t\tDate limite de payemen de facture :  %d/%d/%d\n \t\t\tDate de sorite de facture :   %d/%d/%d\n",Res.Num_Facture,Res.IdClient,Res.Montant,Res.Consommation,Res.Limite.jour,Res.Limite.mois,Res.Limite.annee,Res.sortie.jour,Res.sortie.mois,Res.sortie.annee);
            midrows();


      }
      }
      if(test==0)
        printf("\n\n\t\t\t\t\t(VIDE)\n");
         lastrow();
   fclose(fp6);

}
// fin fct aficher facture


int payes_ou_nonaffich(){
    Facture F2;
   int tr=0;
   fp3=fopen("Factures_payées.txt","a+");
   if(fp3==NULL){
    printf("erreur d ouverture fichier Factures_payées");
   exit(1);
   }
   while(!feof(fp3)){
    fscanf(fp3,"%s  %s  %f  %f  %d  %d  %d  %d  %d  %d\n",&F2.Num_Facture,&F2.IdClient,&F2.Montant,&F2.Consommation,&F2.Limite.jour,&F2.Limite.mois,&F2.Limite.annee,&F2.sortie.jour,&F2.sortie.mois,&F2.sortie.annee);
    if(strcmp(Res.IdClient,F2.IdClient)==0 && strcmp(Res.Num_Facture,F2.Num_Facture)==0){
     tr=1;
      break;
    }

} fclose(fp3);
if(tr==1){
    firstrow();
    midtext();
     printf("\n\t\t\tcette facture est deja  pay%c",130);
    lastrow();
}


return tr;
}


void ValiderPaiement(){
    time_t t;            //le temp du paiement
    struct tm *datt;

    int n,n1,tr=0;
    char valid[30];
    midrowssec();
    printf("\n\n\t\t");
    n=RechercherFacture(2);
    if(n==2){
    n1=payes_ou_nonaffich();
        if(n1==0){

fp=fopen("Factures.txt","a+");
    if(fp==NULL){
        printf("Impossible d'ouvrir le fichier \n");
        exit(1);
}
fp1=fopen("Factures_payées.txt","a+");
if(fp1==NULL){
    printf("Impossible d'ouvrir le fichier \n");
    exit(1);
}
while(!feof(fp)){
    fscanf(fp,"%s  %s  %f  %f  %d  %d  %d  %d  %d  %d\n",F1.Num_Facture,F1.IdClient,&F1.Montant,&F1.Consommation,&F1.Limite.jour,&F1.Limite.mois,&F1.Limite.annee,&F1.sortie.jour,&F1.sortie.mois,&F1.sortie.annee);
    if(strcmp(Res.Num_Facture,F1.Num_Facture)==0 && strcmp(Res.IdClient,F1.IdClient)==0){
    fprintf(fp1,"%s  %s  %f  %f  %d  %d  %d  %d  %d  %d\n",F1.Num_Facture,F1.IdClient,F1.Montant,F1.Consommation,F1.Limite.jour,F1.Limite.mois,F1.Limite.annee,F1.sortie.jour,F1.sortie.mois,F1.sortie.annee);
    break;
    }
}
 fclose(fp1);
 fclose(fp);
 strcpy(valid,Res.IdClient);
 strcat(valid,"__");
 strcat(valid,Res.Num_Facture);
 strcat(valid,".txt");
 fp3=fopen(valid,"w");
 if(fp3==NULL){
    printf("erreur");
    exit(1);
 }
 time(&t);
 datt=localtime(&t);
 fprintf(fp3,"\n\n\t\t-----------------------------------------------\n");
 fprintf(fp3,    "\t\t|              Recu de paiment                 \n");
 fprintf(fp3,    "\t\t|                                              \n");
 fprintf(fp3,    "\t\t| * ID client           :   %s                 \n",F1.IdClient);
 fprintf(fp3,    "\t\t| * Facture numero     :   %s                \n",F1.Num_Facture);
 fprintf(fp3,    "\t\t| * Consommation (Kwh)  :  %.3f               \n",F1.Consommation);
 fprintf(fp3,    "\t\t| * Date de sortie      :   %d/%d/%d           \n",F1.sortie.jour,F1.sortie.mois,F1.sortie.annee);
 fprintf(fp3,    "\t\t| *Date limite          :   %d/%d/%d          \n",F1.Limite.jour,F1.Limite.mois,F1.Limite.annee);
 fprintf(fp3,    "\t\t|         *************************            \n");
 fprintf(fp3,    "\t\t|                                              \n");
 fprintf(fp3,    "\t\t|                 paye le %d/%d/%d            \n",(*datt).tm_mday,(*datt).tm_mon +1,(*datt).tm_year+1900 );
 fprintf(fp3,   "\t\t|                                              \n");
 fprintf(fp3,   "\t\t|                 a     %d:%d:%d                     \n",(*datt).tm_hour,(*datt).tm_min,(*datt).tm_sec);
 fprintf(fp3,   "\t\t|                                              \n");
 fprintf(fp3,   "\t\t|                                              \n");
 fprintf(fp3,"\t\t-----------------------------------------------\n");

fclose(fp3);
 firstrow();
 midtext();
     printf("\t\tPaiement valid%ce\n",130);
    lastrow();
     }
   }
 }

//fct modifier

void  ModifierFacture(){
    int test=0,tr=0,n;
    midrowssec();
    printf("\n\n\t\t");
    n=RechercherFacture(2);

    if(n==2){
    fp1=fopen("Factures.txt","a+");
    if (fp1==NULL){
        printf("Impossible d'ouvrir le fichier \n");
        exit(1);
    }
 	fp3=fopen("nvFactures.txt","w");
 	if(fp3==NULL){
        printf("Impossible d'ouvrir le fichier \n");
        exit(1);
    }
   	while(!feof(fp1))
    {
        fscanf(fp1,"%s  %s  %f  %f  %d  %d  %d  %d  %d  %d\n",F1.Num_Facture,F1.IdClient,&F1.Montant,&F1.Consommation,&F1.Limite.jour,&F1.Limite.mois,&F1.Limite.annee,&F1.sortie.jour,&F1.sortie.mois,&F1.sortie.annee);
        if(strcmp(Res.IdClient,F1.IdClient)==0 && strcmp(Res.Num_Facture,F1.Num_Facture)==0){
            midrowssec();
                do{
            printf("\n\n\t\tDonner le nouveau montant mensuel :  ");
            scanf("%f",&F1.Montant);
                }while(F1.Montant<0);
            midrowssec();
            do{
            printf("\n\n\t\tDonner la nouvelle consommation mensuelle:  ");
            scanf("%f",&F1.Consommation);
            }while(F1.Consommation<0);
             midrowssec();
            do{
            printf("\n\n\t\tDonner la nouvelle date limite de payement:  \n");
            printf("\t\tjour : ");
            scanf("%d",&F1.Limite.jour);
            printf("\t\tmois : ");
            scanf("%d",&F1.Limite.mois);
            printf("\t\tann%ce : ",130);
            scanf("%d",&F1.Limite.annee);
            }while(F1.Limite.jour<0||F1.Limite.mois<0||F1.Limite.annee<0);
            printf("\n");
             midrowssec();
             do{
            printf("\n\n\t\tDonner la nouvelle date de sortie de Facture:  \n");
            printf("\t\tjour : ");
            scanf("%d",&F1.sortie.jour);
            printf("\t\tmois : ");
            scanf("%d",&F1.sortie.mois);
            printf("\t\tann%ce : ",130);
            scanf("%d",&F1.sortie.annee);
            }while(F1.sortie.jour<0||F1.sortie.mois<0||F1.sortie.annee<0);
            printf("\n");
            midrowssec();

        }
        fprintf(fp3,"%s  %s  %f  %f  %d  %d  %d  %d  %d  %d\n",F1.Num_Facture,F1.IdClient,F1.Montant,F1.Consommation,F1.Limite.jour,F1.Limite.mois,F1.Limite.annee,F1.sortie.jour,F1.sortie.mois,F1.sortie.annee);

    }
   	fclose(fp1);
   	fclose(fp3);
   	remove("Factures.txt");
   	rename("nvFactures.txt","Factures.txt");


		firstrow();midtext();
    printf("\t\t Modification effectu%ce avec succ%ces",130,130);
    lastrow();

  }
 }
//fin fct modifier facture


//sup facture

void SupprimerFacture(){
    int n;
    midrowssec();
    printf("\n\n\t\t");
    n=RechercherFacture(2);
    if(n==2){

    fp1=fopen("Factures.txt","a+");
    if(fp1==NULL){
        printf("Impossible d'ouvrir le fichier \n");
        exit(1);
    }
 	fp3=fopen("temp.txt","w");
 	if (fp3==NULL){
        printf("Impossible d'ouvrir le fichier \n");
        exit(1);
    }
    while(!feof(fp1))
    	{
    		fscanf(fp1,"%s  %s  %f  %f  %d  %d  %d  %d  %d  %d\n",F1.Num_Facture,F1.IdClient,&F1.Montant,&F1.Consommation,&F1.Limite.jour,&F1.Limite.mois,&F1.Limite.annee,&F1.sortie.jour,&F1.sortie.mois,&F1.sortie.annee);
    		if(strcmp(Res.IdClient,F1.IdClient)!=0 || strcmp(Res.Num_Facture,F1.Num_Facture)!=0)

            fprintf(fp3,"%s  %s  %f  %f  %d  %d  %d  %d  %d  %d\n",F1.Num_Facture,F1.IdClient,F1.Montant,F1.Consommation,F1.Limite.jour,F1.Limite.mois,F1.Limite.annee,F1.sortie.jour,F1.sortie.mois,F1.sortie.annee);


        }


    fclose(fp1);
    fclose(fp3);
	remove("Factures.txt");
	rename("temp.txt","Factures.txt");

    firstrow();
    midtext();
    printf("\t\t Modification effectu%ce avec succ%ces",130,130);
    lastrow();

    }

}
//fin fct


//fonction afficher factures payees

void afficherFacturesPayees()
{
    int test=0;
     Res.Num_Facture[0]=EOF;
    fp1=fopen("Factures_payées.txt","a+");
    if(fp1==NULL)
        printf("Echec d'ouverture :\n\n");

   else{
       printf("\n\n------------------------------les Factures Pay%ces-----------------------\n\n",130);
         firstrow();
      while(!feof(fp1)){
            fscanf(fp1,"%s  %s  %f  %f  %d  %d  %d  %d  %d  %d\n",&Res.Num_Facture,&Res.IdClient,&F1.Montant,&F1.Consommation,&F1.Limite.jour,&F1.Limite.mois,&F1.Limite.annee,&F1.sortie.jour,&F1.sortie.mois,&F1.sortie.annee);
            if(Res.Num_Facture[0]!=EOF){
            test=1;
            midtext();
            printf("\n\t\t\tNumero de Facture :    %s\n\t\t\tId de client :    %s\n\t\t\t Montant:     %f DH\n\t\t\t Consomation en :    %f(W)\n\t\t\tDate limite de payemen de facture :  %d/%d/%d\n \t\t\tDate de sorite de facture :   %d/%d/%d\n",Res.Num_Facture,Res.IdClient,F1.Montant,F1.Consommation,F1.Limite.jour,F1.Limite.mois,F1.Limite.annee,F1.sortie.jour,F1.sortie.mois,F1.sortie.annee);
            midrows();
            }

    }
    if(test==0)
     printf("\n\n\t\t\t\t\t(VIDE)\n");
     lastrow();
     fclose(fp1);
 }

}

//fonction modifier les informations

void Mod_mes_informations(){

    Client C1;
	char tempville[20];
    fp=fopen("Clients.txt","a+");
    if (fp==NULL){
        printf("Impossible d'ouvrir le fichier \n");
        exit(1);
    }

    fpm=fopen("tempC.txt","w");
    if (fpm==NULL){
        printf("Impossible d'ouvrir le fichier \n");
        exit(1);
      }

    	while(fscanf(fp,"%s   %s   %s    %s    %s   %s   %s\n",&C1.Nom,&C1.Prenom,&C1.Adressse,&C1.NumAbonnement,&C1.NumConteur,&C1.IdClient,&C1.Mot_pass)==7)
    	{
    		if(strcmp(V.IdClient,C1.IdClient)==0)
    {
         midrowssec();
    	printf("\n\n\t\tEntrer le nouveau Nom : ");
    	scanf("%s", C1.Nom);
    	midrowssec();
        printf("\n\n\t\tEntrer le Pr%cnom : ",130);
        scanf("%s", C1.Prenom);
        midrowssec();
        printf("\n\n\t\tEntrer la ville : ");
        scanf("%s", C1.Adressse);
        strcpy(tempville,C1.Adressse);
        midrowssec();

     do{
        printf("\n\nEntrer le Num%cro d'Abonemment Compose de Un Caract%cre et 7 chiffre (exemple:M1234567): ",130,138);
        scanf("%s",C1.NumAbonnement);
         }while(strlen(C1.NumAbonnement)!=8 || C1.NumAbonnement[0]<'A' || C1.NumAbonnement[0]>'Z');midrowssec();
    do{
        printf("\n\nSaisir le Num%cro de Contour Compose de 1 Caract%cre et 7 chiffres (exemple:M1234567): ",130,138);
        scanf("%s", C1.NumConteur);
      }while(strlen(C1.NumConteur)!=8 || C1.NumConteur[0]<'A' || C1.NumConteur[0]>'Z');
       }
       fprintf(fpm,"%s   %s   %s    %s    %s   %s   %s\n",C1.Nom,C1.Prenom,C1.Adressse,C1.NumAbonnement,C1.NumConteur,C1.IdClient,C1.Mot_pass);

		}
		fclose(fp);fclose(fpm);
		remove("Clients.txt");
		rename("tempC.txt","Clients.txt");
		fp1=fopen("AdresseComp.txt","a+");
        if(fp1==NULL){
         printf("Impossible d'ouvrir le fichier \n");
        exit(1);
        }
        fp3=fopen("tempA.txt","w");
        if (fp3==NULL){
        printf("Impossible d'ouvrir le fichier \n");
        exit(1);
        }
        while(fscanf(fp1,"%s  %s  %s  %s  \n",C1.IdClient,C1.Adressse,C1.Cartier,C1.residence)==4){
            if(strcmp(V.IdClient,C1.IdClient)==0)
    		{   midrowssec();
    		    printf("\n\n\t\tDonner le nom du quartier: ");
    		    scanf("%s",C1.Cartier);
    		    midrowssec();
    		    do{
    		    printf("\n\n\t\tDonner le numero de residence: ");
    		    scanf("%s",C1.residence);
    		    }while(C1.residence[0]=='-');
    		    fprintf(fp3,"%s  %s  %s  %s  \n",C1.IdClient,tempville,C1.Cartier,C1.residence);
    		}
    		else
            fprintf(fp3,"%s  %s  %s  %s  \n",C1.IdClient,C1.Adressse,C1.Cartier,C1.residence);


        }
        fclose(fp1);fclose(fp3);
        remove("AdresseComp.txt");
        rename("tempA.txt","AdresseComp.txt");
        fp6=fopen("ID_and_Passowrd.txt","a+");
       if(fp6==NULL){
        printf("Echec d'overture :\n\n");
        exit(1);
       }
       fp3=fopen("tempI.txt","w");
        if (fp3==NULL){
        printf("Impossible d'ouvrir le fichier \n");
        exit(1);
        }
        while(!feof(fp6)){
        fscanf(fp6,"%s  %s  \n",C1.IdClient,C1.Mot_pass);
        if(strcmp(C1.IdClient,V.IdClient)==0){
                midrowssec();
                do{
            printf("\n\n\t\tEntrer le nouveau mot de passe (compos%c de 6 chiffres): ",130);
             scanf("%s",C1.Mot_pass);
            }while(strlen(C1.Mot_pass)!=6);
        }
         fprintf(fp3,"%s  %s  \n",C1.IdClient,C1.Mot_pass);

        }
        fclose(fp6);
        fclose(fp3);
        remove("ID_and_Passowrd.txt");
        rename("tempI.txt","ID_and_Passowrd.txt");
       	firstrow();
       	midtext();
        printf("\t\t Modification effectu%ce avec succ%ces",130,130);
        lastrow();

        printf("\n\n\n\t\t\tPress any Key to continue");
        getch();

 }
//fonction afficher facture

void MaFacture(){


    int test=0,i=1;
    fp1=fopen("Factures.txt","a+");
     if(fp1==NULL){
        printf("Echec d'ouverture !!!!!!\n\n");
        exit(1);
 }
      while(!feof(fp1))
    {
        fscanf(fp1,"%s  %s  %f  %f  %d  %d  %d  %d  %d  %d\n",&F1.Num_Facture,&F1.IdClient,&F1.Montant,&F1.Consommation,&F1.Limite.jour,&F1.Limite.mois,&F1.Limite.annee,&F1.sortie.jour,&F1.sortie.mois,&F1.sortie.annee);
        if(strcmp(F1.IdClient,V.IdClient)==0){
        test=1;
       printf("\n\n**************************************votre facture d\'electricite %d *************************************************\n",i);
       printf("                                                                                                                    \n");
       printf(" Numero_Facture |  Id_Client  |  Montant(en DH)  |  Consommation(en KWh)  |  Date_sortie     |  Date_Limite         \n");
       printf(" %s               %s               %.3f               %.3f                    %d/%d/%d             %d/%d/%d       \n\n",F1.Num_Facture,F1.IdClient,F1.Montant,F1.Consommation,F1.sortie.jour,F1.sortie.mois,F1.sortie.annee,F1.Limite.jour,F1.Limite.mois,F1.Limite.annee);
       i++;
 }
 }
    fclose(fp1);
    if(test==0){
    printf("\n\n********************************votre facture d\'electricite ******************************************\n\t\t");
    firstrow();
    printf("\n\n\t\t\t\t\t(VIDE)\n");
    lastrow();
    }
    printf("\n\n\t\t\t  press any Key to continue...");
    getch();

}

//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

int aide_chercherfac(){
   int tr=0;
   fp1=fopen("Factures.txt","a+");
   if(fp1==NULL){
    printf("erreur");
    exit(1);
   }
   printf("\n\n\t\tDonner le num%cro du facture a pay%ces :\t\t",130,130);
   scanf("%s",Res.Num_Facture);

   while(!feof(fp1)){
    fscanf(fp1,"%s  %s  %f  %f  %d  %d  %d  %d  %d  %d\n",&F1.Num_Facture,&F1.IdClient,&F1.Montant,&F1.Consommation,&F1.Limite.jour,&F1.Limite.mois,&F1.Limite.annee,&F1.sortie.jour,&F1.sortie.mois,&F1.sortie.annee);

    if(strcmp(V.IdClient,F1.IdClient)==0 && strcmp(Res.Num_Facture,F1.Num_Facture)==0){
     tr=1;
      break;
    }
}

fclose(fp1);

return tr;
}


int payes_ou_non(){
    Facture F2;
   int tr=0;
   fp3=fopen("Factures_payées.txt","a+");
   if(fp3==NULL){
    printf("erreur d ouverture fichier Factures_payées");
   exit(1);
   }
   while(!feof(fp3)){
    fscanf(fp3,"%s  %s  %f  %f  %d  %d  %d  %d  %d  %d\n",&F2.Num_Facture,&F2.IdClient,&F2.Montant,&F2.Consommation,&F2.Limite.jour,&F2.Limite.mois,&F2.Limite.annee,&F2.sortie.jour,&F2.sortie.mois,&F2.sortie.annee);
    if(strcmp(V.IdClient,F2.IdClient)==0 && strcmp(Res.Num_Facture,F2.Num_Facture)==0){
     tr=1;
      break;
    }

} fclose(fp3);

return tr;


}


//fonction payer facture
void Payer_ma_facture(){

     time_t t;   //pour aff du temps
     struct tm *datt;

     char valid[30];
     char confirmation[5];
     carte_bancaire B1;
     Client C1;
     int n1,n;
     n=aide_chercherfac();
     n1=payes_ou_non();
     if(n==1){
            if(n1==0){
       printf("\n\n**************************************votre facture d\'electricite *************************************************\n");
       printf("                                                                                                                    \n");
       printf(" Numero_Facture |  Id_Client  |  Montant(en DH)  |  Consommation(en KWh)  |  Date_sortie     |  Date_Limite         \n");
       printf(" %s               %s               %.3f               %.3f                    %d/%d/%d             %d/%d/%d       \n\n",F1.Num_Facture,F1.IdClient,F1.Montant,F1.Consommation,F1.sortie.jour,F1.sortie.mois,F1.sortie.annee,F1.Limite.jour,F1.Limite.mois,F1.Limite.annee);

     printf("\n\n****************************************** PAIEMENT PAR UN COMPTE BANCAIRE *****************************************\n\n");

      printf("\n\n\t\t\t\tle total a payer est : %.3f DH\n\n\n",F1.Montant);
      printf("-->>>S'il vous plait entrez les informations suivantes :\n\n");
      printf("\n\n\t\tle nom du porteur de la carte    :\t");
      scanf("%s",&B1.nom_p);
      printf("\n\n\t\tle prenom du porteur de la carte :\t");
      scanf("%s",&B1.prenom_p);
      do{
      printf("\n\n\t\tle numero de carte de paiement   :\t");
      scanf("%d",&B1.Num_carte);
      }while(B1.Num_carte<=0);
      do{
      printf("\n\n\t\tle code de verification          :\t");
      scanf("%d",&B1.Num_verif);
      }while(B1.Num_verif);
      printf("\n\n\t\tconfirmer le payement?(oui ou non)!!!!!!!!!!     :\t");
      scanf("%s",&confirmation);
      if(strcmp(confirmation,"oui")==0 || strcmp(confirmation,"OUI")==0){

   //************************************************************************  deb facture

 strcpy(valid,F1.IdClient);
 strcat(valid,"__");
 strcat(valid,F1.Num_Facture);
 strcat(valid,".txt");
 fp3=fopen(valid,"w");
 if(fp3==NULL){
    printf("erreur");
    exit(1);
 }
 time(&t);
 datt=localtime(&t);
 fprintf(fp3,"\n\n\t\t-----------------------------------------------\n");
 fprintf(fp3,    "\t\t|              Recu de paiment                 \n");
 fprintf(fp3,    "\t\t|                                              \n");
 fprintf(fp3,    "\t\t| * ID client           :   %s                 \n",F1.IdClient);
 fprintf(fp3,    "\t\t| * Facture numero     :   %s                \n",F1.Num_Facture);
 fprintf(fp3,    "\t\t| * Consommation (Kwh)  :  %.3f               \n",F1.Consommation);
 fprintf(fp3,    "\t\t| * Date de sortie      :   %d/%d/%d           \n",F1.sortie.jour,F1.sortie.mois,F1.sortie.annee);
 fprintf(fp3,    "\t\t| *Date limite          :   %d/%d/%d          \n",F1.Limite.jour,F1.Limite.mois,F1.Limite.annee);
 fprintf(fp3,    "\t\t|         *************************            \n");
 fprintf(fp3,    "\t\t|                                              \n");
 fprintf(fp3,    "\t\t|                 paye le %d/%d/%d            \n",(*datt).tm_mday,(*datt).tm_mon +1,(*datt).tm_year+1900  );
 fprintf(fp3,   "\t\t|                                              \n");
 fprintf(fp3,   "\t\t|                 a     %d:%d:%d                     \n",(*datt).tm_hour,(*datt).tm_min,(*datt).tm_sec);
 fprintf(fp3,   "\t\t|                                              \n");
 fprintf(fp3,   "\t\t|                                              \n");
 fprintf(fp3,"\t\t-----------------------------------------------\n");

fclose(fp3);

  //****************************************** fiin facture


        firstrow();
        midtext();
        printf("\t\tVotre paiement a %ct%c effectu%ce avec succes\n\n",130,130,130);
        lastrow();

        fp3=fopen("Factures_payées.txt","a");
        if(fp3==NULL){
            printf("erreur!");
            exit(1);
        }
        fprintf(fp3,"%s  %s  %f  %f  %d  %d  %d  %d  %d  %d\n",F1.Num_Facture,F1.IdClient,F1.Montant,F1.Consommation,F1.Limite.jour,F1.Limite.mois,F1.Limite.annee,F1.sortie.jour,F1.sortie.mois,F1.sortie.annee);
        fclose(fp3);
       }
    }
      else{
        firstrow();
        midtext();
        printf("\t\t Cette facture est deja pay%c!!!\n",130);
      lastrow();
      }
    }
    else{ firstrow();midtext();
        printf("\t\t cette facture n\'existe pas!!!\n");
        lastrow();
    }
    printf("\n\n\n\n\n\t\t\t\tpress any Key to continue...");
    getch();


 }
 void aff_mesfactures_payees(){
     int tr=0;

     fp=fopen("Factures_payées.txt","a+");
     if(fp==NULL){
            printf("erreur!");
            exit(1);
        }
        while(!feof(fp)){
    fscanf(fp,"%s  %s  %f  %f  %d  %d  %d  %d  %d  %d\n",&F1.Num_Facture,&F1.IdClient,&F1.Montant,&F1.Consommation,&F1.Limite.jour,&F1.Limite.mois,&F1.Limite.annee,&F1.sortie.jour,&F1.sortie.mois,&F1.sortie.annee);
    if(strcmp(V.IdClient,F1.IdClient)==0 ){
       printf("\n\n************************************** Factures d\'%clectricite pay%ces *************************************************\n",130,130);
       printf("                                                                                                                    \n");
       printf(" Numero_Facture |  Id_Client  |  Montant(en DH)  |  Consommation(en KWh)  |  Date_sortie     |  Date_Limite         \n");
       printf(" %s               %s               %.3f               %.3f                    %d/%d/%d             %d/%d/%d       \n\n",F1.Num_Facture,F1.IdClient,F1.Montant,F1.Consommation,F1.sortie.jour,F1.sortie.mois,F1.sortie.annee,F1.Limite.jour,F1.Limite.mois,F1.Limite.annee);
     tr=1;

    }
}
    fclose(fp);
       if(tr==0){
       firstrow();
       printf("\n\n\t\t\t\t\t(VIDE)\n");
       lastrow();
       }
       printf("\n\n\t\t\t  press any Key to continue...");
       getch();
}

 //>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

//menu

 void menu(){
  int choix2;

  do{

                    system("cls");
                  printf("\n\n\n");
                    printf("                                       ******************************************** \n");
                    printf("                                       |                  BIENVENUE               |\n");
                    printf("                                       |                                          |\n");
                    printf("                                       | 1---> Mes factures                       |\n");
                    printf("                                       | 2---> Payer ma facture                   |\n");
                    printf("                                       | 3---> Modifer mes informations           |\n");
                    printf("                                       | 4---> afficher mes factures pay%ces       |\n",130);
                    printf("                                       | 0---> Deconnexion                        |\n");
                    printf("                                       |                                          |\n");
                    printf("                                       ********************************************\n");
                    printf("\n\n\t\t\tEntrez votre choix :\t ");
                    scanf("%d",&choix2);
                    system("cls");
                    switch(choix2){
                        case 1 :
                                MaFacture();
                                break;
                        case 2 :
                                 Payer_ma_facture();
                                 break;
                        case 3 :
                                 Mod_mes_informations();
                                 break;
                        case 4 :
                                aff_mesfactures_payees();
                                break;
                    }
                   }while(choix2!=0);


}
//fonction login
int Login2(){

	Client C1;
    int tr=0;
    fp=fopen("Clients.txt","a+");
    if (fp==NULL){
        printf("Impossible d'ouvrir le fichier \n");
        exit(1);
    }
    firstrow();
    printf("\n\n\t\tEntrez votre ID           :\t");
    scanf("%s",V.IdClient);
    midrows();
    printf("\n\n\t\tEntrez votre mot de passe :\t");
    scanf("%s",V.Mot_pass);


    while(!feof(fp))
    {
        fscanf(fp,"%s   %s   %s    %s    %s   %s    %s\n",&C1.Nom,&C1.Prenom,&C1.Adressse,&C1.NumAbonnement,&C1.NumConteur,&C1.IdClient,&C1.Mot_pass);
        if(strcmp(C1.IdClient,V.IdClient)==0&&strcmp(C1.Mot_pass,V.Mot_pass)==0)
        {
            tr=1;
            break;
        }
    }
    fclose(fp);
    system("cls");

return tr;
}


//fonction sign up

void SignUp(){
     char passer[5];
     Client C1;
     int n;
     n=RechercherClient22_nonaffi();
     if(n==1)
        printf("\n\n\t\t>>>>>>>>>>>>>>>>vous avez d%cj%c un compte sous ce identifiant<<<<<<<<<<<<<<<\n\n\n",130,133);
     else{
     fp1=fopen("Clients.txt","a+");//<<<<<<
     if(fp1==NULL){
        printf("impossible d ouvrir le fichier des clients");
        exit(1);
        }
      printf("\n\n\t\t-->>>S'il vous plait entrez les informations suivantes :\n\n");
      midrowssec();
      printf("\n\n\t\tVotre Nom                  :\t");
      scanf("%s",&C1.Nom);
      midrowssec();
      printf("\n\n\t\tVotre Pr%cnom               :\t",130);
      scanf("%s",&C1.Prenom);
      midrowssec();
      printf("\n\n\t\tVotre ville                :\t");
      scanf("%s",&C1.Adressse);
      midrowssec();
      printf("\n\n\t\tVotre Quartier                :\t");
      scanf("%s",&C1.Cartier);
      midrowssec();
      do{
      printf("\n\n\t\tle num%cro de Votre Residence               :\t",130);
      scanf("%s",&C1.residence);
      }while(C1.residence[0]=='-');
      midrowssec();
      do{
        printf("\n\n Entrez le num%cro d'abonnement compos%c de 1 caract%cre et 7 chiffres (exemple :M1234567): ",130,130,138);
        scanf("%s",C1.NumAbonnement);
        }while(strlen(C1.NumAbonnement)!=8 ||C1.NumAbonnement[0]<'A' || C1.NumAbonnement[0]>'Z' );midrowssec();
        do{
        printf("\n\n Saisir le Numero de Contour Compos%c de 1 Caractere et 7 chiffres (exemple :M1234567): ",130);
        scanf("%s", C1.NumConteur);
        }while(strlen(C1.NumConteur)!=8 ||C1.NumConteur[0]<'A' || C1.NumConteur[0]>'Z' );midrowssec();
        do{
       printf("\n\n\t\tSaisir Un mot de passe de 6 chifrres :   ");
       scanf("%s", C1.Mot_pass);
       }while(strlen(C1.Mot_pass)!=6);

    fprintf(fp1,"%s   %s   %s    %s    %s   %s   %s\n",C1.Nom,C1.Prenom,C1.Adressse,C1.NumAbonnement,C1.NumConteur,Res.IdClient,C1.Mot_pass);
    fclose(fp1);

     fp3=fopen("AdresseComp.txt","a+");//<<<<
    if (fp3==NULL){
        printf("Impossible d'ouvrir le fichier des adresses \n");
        exit(1);
    }

        fprintf(fp3,"%s  %s  %s  %s  \n",Res.IdClient,C1.Adressse,C1.Cartier,C1.residence);
        fclose(fp3);
        fp4=fopen("ID_and_Passowrd.txt","a");//<<<<
        if(fp4==NULL){
            printf("impossible d ouvrir le fichier des mots de passe");
            exit(1);
        }
        fprintf(fp4,"%s  %s  \n",Res.IdClient,C1.Mot_pass);
        fclose(fp4);

       firstrow();
       midtext();
    printf("\t\t\t enregistrement avec succ%ces",130);
    lastrow();

}
      printf("\n\n\t\t\t\t press any Key to continue...");
        getch();
        system("cls");

}




//menuuu init

void menuA(){

char QR[5],Mdp[25];
int op,tr,choix,Code;

do{
printf("\n\n\n");
       firstrow();
        midtext();
        printf("\t\t\tVeuillez s'Identifier:\n");
        midtext();
        printf("\t\t\tA-Administrateur\n");
        midtext();
        printf("\t\t\tC-Client\n");
        lastrow();
        printf("\n\t");
        scanf("%s",&QR);
        system("cls");
        }while(strcmp(QR,"A")!=0&&strcmp(QR,"a")!=0&&strcmp(QR,"C")!=0&&strcmp(QR,"c")!=0);
         if(strcmp(QR,"A")==0||strcmp(QR,"a")==0){
             do{
                printf("\n\n");
                firstrow();
                midtext();
                printf("\n\n");
                printf("\t\t\t\tESPACE ADMINISTRATEUR\n");
                printf("\n");
                printf("\t\t\t\tSaisir votre ID:");
                scanf("%d",&Code);
                printf("\n");
                printf("\t\t\t\tSaisir votre mot de passe:");
                scanf("%s",Mdp);

                system("cls");

             }while(Code!=1212 || strcmp(Mdp,"ENSAS")!=0);
             do {
                    do{
                system("cls");
                printf("\n\n\n");
        firstrow();
        midtext();
        printf("\t\t\tEffectuez votre choix:\n");
        midtext();
        printf("\t\t\t1-Gestion des Clients\n");
        midtext();
        printf("\t\t\t2-Gestion des Factures\n");
        midtext();
        printf("\t\t\t3-Deconnexion\n");
        lastrow();
        printf("\n\t");
            scanf("%d",&op);
        system("cls");
        }while(op!=1 && op!=2 && op!=3);
        switch(op){
                 case 1:
                        do{

                printf("\n\n\n");

                  printf("   \t\t       | GESTION DES CLIENTS |    : " );

                firstrow();
               midtext(); printf("->1) Ajouter un Client .                                              %c             ",186);
                midrows();
                midtext(); printf("->2) Consulter la base des Clients.                                   %c          "    ,186);
                 midrows();
               midtext() ; printf("->3) Modifier Les informations d'un Client  .                         %c              ",186);
                 midrows();
               midtext();  printf("->4) Rechercher un Client .                                           %c           ",186);
                 midrows();
               midtext();  printf("->5)  Supprimer un Client .                                           %c     ",186);
               midrows();
               midtext() ;  printf("->6) Consulter les Adresses des Clients                               %c      ",186);
                midrows();
               midtext()  ;printf("->7) Consulter Les Ids et Les Mots de passe des Clients               %c     ",186);
               midrows();
              midtext();printf("->8) Retour                                                           %c",186);
               	lastrow();
                printf("\n \t\Veuillez Saisir votre choix:\t ");scanf("%d",&choix);


                system("cls");
                switch(choix){
                case 1 :
                        AjouterClient() ;
                        break;
                case 2 :
                        afficheLesclientLi();
                         break;
                case 3 :
                        ModifficationInfoClient();
                        break;
                case 4 :
                        RechercherClient();
                        break;
                case 5 :
                        SuprimerClient();
                        break;
                case 6:
                       afficheId_Adresse();
                       break;
                case 7:
                       afficheId_mdp();
                        break;

                default: if(choix!=8)
                    printf("\n\n\t\t\t\t------choix indisponible------");

                }
            }while(choix!=8);
            break;


             case 2:
                do {


                printf("\n\n\n");

                printf("                           | GESTION DES FACTURES   |\n" );
                 firstrow();
               midtext();   printf("->1) Ajouter une Facture                                              %c             ",186);
               midrows();
                midtext();printf("->2) Consulter la base des Factures.)                                 %c               ",186);
                midrows();
               midtext(); printf("->3) Modifier une Facture.                                            %c             ",186);
               midrows();
                midtext();printf("->4) Valider le payement  d'une Facture  .                            %c               ",186);
                midrows();
                midtext();printf("->5) Rechercher une Facture.                                          %c               ",186);
                midrows();
               midtext();
               printf("->6) Supprimer une facture    .                                       %c                   ",186);
               midrows();
               midtext();
               printf("->7) Consulter les Facture Pay%ces                                     %c                     ",130,186);
               midrows();
               midtext();
               printf("->8) Retour                                                           %c                 ",186);
              lastrow();
                  printf("\n\t\Veuillez Saisir votre choix:\t ");scanf("%d",&choix);
                 system("cls");
                switch(choix){
                case 1:
                        AjouterFacture2();
                        break;
                case 2 :
                         afficherFactures() ;
                         break;
                case 3 :
                        ModifierFacture();
                        break;
                case 4 :
                         ValiderPaiement();
                        break;
                case 5:
                        RechercherFacture(0);
                        break;
                case 6:
                       SupprimerFacture();
                        break;
                case 7:
                        afficherFacturesPayees();
                        break;

                default : if(choix!=8)
                       printf("\n\n\t\t\t\t------choix indisponible------");
              }

         }while(choix!=8);
          break;

           case 3:
                 menuA();
                 break;
         }
    }while(1);
 }//finA*********

          if(strcmp(QR,"C")==0||strcmp(QR,"c")==0){
                         do{

            printf("\n\n\n");

            printf("                      **                  BIENVENUE             **\n");
            firstrow();
            midtext(); printf(" 1---> Authentification                                               %c             ",186);
            midrows();
           midtext();  printf(" 2---> Se connecter                                                   %c             ",186);
           midrows();
           midtext();  printf(" 3---> Retour menu                                                   %c             ",186);
           lastrow();
            printf(" \n\t\tentre votre choix :\t ");
            scanf("%d",&choix);
             system("cls");
            switch(choix){

            case 1:
                   printf("\nBonjour, nous sommes ravis de vous compter parmi nos nouveaux clients\n");
                   printf("    Pour creer un compte, Suivez les etapes requises ci dessous:\n\n");
                   SignUp();
                   break;
            case 2:
                   tr=Login2();
                   if(tr==1)
                    menu();
                  else{
                     firstrow();
                        midtext();
                        printf("\n\t\t-->>>Votre ID ou Mot de passe incorrect !!!!!!!!!!!! ");
                        lastrow();
                    }

             case 3:
                    menuA();
                    break;
				}

      }while(choix!=0);

    }
 }










void firstrow(){
	int i ;
	printf("\n\t%c",201);
    for( i=0;i<70;i++)
    	printf("%c",205);
    	printf("%c",187);
}
void lastrow(){
	int i ;
	printf("\n\t%c",200);
    for( i=0;i<70;i++)
    	printf("%c",205);
    	printf("%c",188);
}
void midtext(){
	int i ;
	printf("\n\t%c",186);
}
void midrows(){
	int i ;
	printf("\n\t%c",204);
    for( i=0;i<70;i++)
    	printf("%c",205);
    	printf("%c",185);
}
void midrowssec(){
	int i ;

    for( i=0;i<100;i++)
    	printf("%c",205);

}



int main(){

int op,tr,choix,Code;
char Mdp[23],QR[6],af[50];



    printf("\n\n");
    //printf("\t\t        ----------------------------------------------FACTURATION D'ELECTRICITE----------------------------------------------\n");
    printf("\t\t\tBIENVENU A VOTRE APPLICATION DE FACTURATION D'ELECTRICITE \n");
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\tPress any Key to continue");
    printf("\n\n\n\n\t\t\t\tveuillez utiliser le caractere \"_\" au lieu d\'espace");
    getch();
    system("cls");

        do{

        printf("\n\n\n");
        firstrow();
        midtext();
        printf("\t\t\tVeuillez s'Identifier:\n");
        midtext();
        printf("\t\t\tA-Administrateur\n");
        midtext();
        printf("\t\t\tC-Client\n");
        lastrow();
        printf("\n\t");
        scanf("%s",&QR);
        system("cls");
        }while(strcmp(QR,"A")!=0&&strcmp(QR,"a")!=0&&strcmp(QR,"C")!=0&&strcmp(QR,"c")!=0);

         if(strcmp(QR,"A")==0||strcmp(QR,"a")==0){
             do{
                printf("\n\n");
                firstrow();
                midtext();
                printf("\n\n");
                printf("\t\t\t\tESPACE ADMINISTRATEUR\n");
                printf("\n");
                printf("\t\t\t\tSaisir votre ID:");
                scanf("%d",&Code);
                printf("\n");
                printf("\t\t\t\tSaisir votre mot de passe:");
                scanf("%s",Mdp);

                system("cls");

             }while(Code!=1212 || (strcmp(Mdp,"ENSAS")!=0));
             do{
                    do{
                system("cls");
        printf("\n\n\n");
        firstrow();
        midtext();
        printf("\t\t\tEffectuez votre choix:\n");
        midtext();
        printf("\t\t\t1-Gestion des Clients\n");
        midtext();
        printf("\t\t\t2-Gestion des Factures\n");
        midtext();
        printf("\t\t\t3-Deconnexion");
        lastrow();
        printf("\n\t");
            scanf("%d",&op);
        system("cls");
         }while(op!=1 && op!=2 && op!=3);
         switch(op){

                case 1:
                        do{

                printf("\n\n\n");

                  printf("   \t\t       | GESTION DES CLIENTS |    : " );

                firstrow();
               midtext(); printf("->1) Ajouter un Client .                                              %c             ",186);
                midrows();
                midtext(); printf("->2) Consulter la base des Clients.                                   %c            ",186);
                 midrows();
               midtext() ; printf("->3) Modifier Les informations d'un Client  .                         %c             ",186);
                 midrows();
               midtext();  printf("->4) Rechercher un Client .                                           %c             ",186);
                 midrows();
               midtext();  printf("->5)  Supprimer un Client .                                           %c             ",186);
               midrows();
               midtext() ;  printf("->6) Consulter les Adresses des Clients                               %c            ",186);
                midrows();
               midtext()  ;printf("->7) Consulter Les Ids et Les Mots de passe des Clients               %c             ",186);
               midrows();
              midtext();printf("->8) Retour                                                           %c                ",186);
               	lastrow();
                printf("\n \t\Veuillez Saisir votre choix:\t ");
                scanf("%d",&choix);


                system("cls");
                switch(choix){
                case 1 :
                       AjouterClient() ;
                       break;
                case 2 :
                        afficheLesclientLi();
                        break;
                case 3 :
                        ModifficationInfoClient();
                        break;
                case 4 :
                        RechercherClient();
                        break;
                case 5 :
                        SuprimerClient();
                        break;
                case 6:
                       afficheId_Adresse();
                       break;
                case 7:
                       afficheId_mdp();
                        break;

                default :
                         if(choix!=8)
                         printf("\n\n\t\t\t\t------choix indisponible-------");

                }
            }while(choix!=8);
              break;


          case 2:
                do {
//Menu de administrateur

                printf("\n\n\n");

                printf("                           | GESTION DES FACTURES   |\n" );
                 firstrow();
               midtext();   printf("->1) Ajouter une Facture                                              %c             ",186);
               midrows();
                midtext();printf("->2) Consulter la base des Factures                                   %c               ",186);
                midrows();
               midtext(); printf("->3) Modifier une Facture                                             %c             ",186);
               midrows();
                midtext();printf("->4) Valider le payement  d'une Facture                               %c               ",186);
                midrows();
                midtext();printf("->5) Rechercher une Facture                                           %c               ",186);
                midrows();
            midtext();printf("->6) Supprimer une facture                                            %c                   ",186);
            midrows();
         midtext();printf("->7) Consulter les Facture Payees                                     %c                     ",186);
         midrows();
          midtext();printf("->8) Retour                                                           %c                 ",186);
              lastrow();
                  printf("\n\t\Veuillez Saisir votre choix:\t ");
                  scanf("%d",&choix);
                 system("cls");
                switch(choix){

                case 1:
                        AjouterFacture2();
                        break;
                case 2 :
                        afficherFactures() ;
                        break;
                case 3 :
                        ModifierFacture();
                        break;
                case 4 :
                        ValiderPaiement();
                         break;
                case 5:
                        midrowssec();
                        printf("\n\n\t\t");
                        RechercherFacture(0);
                        break;

                case 6:
                       SupprimerFacture();
                       break;
                case 7:
                       afficherFacturesPayees();
                       break;

                default :
                    if(choix!=8)
                    printf("\n\n\t\t\t\t------choix indisponible------");

                }

         }while(choix!=8);
          break;

       case 3:
              menuA();
              break;
        }

    }while(1);

} //FINNNNNN AAAAAAAA<<<<<<<<<<<<<<<<<<

          if(strcmp(QR,"C")==0||strcmp(QR,"c")==0){
        do{


            printf("\n\n\n");

            printf("                      **                  BIENVENUE             **\n");
            firstrow();
            midtext(); printf(" 1---> Authentification                                               %c             ",186);
            midrows();
           midtext();  printf(" 2---> Connexion                                                      %c             ",186);
           midrows();
           midtext();  printf(" 3---> Retour au menu                                                 %c             ",186);
           lastrow();
            printf(" \n\t\tentrer votre choix :\t ");
            scanf("%d",&choix);

            system("cls");

            switch(choix){

            case 1:
                    printf("\n\t\tBonjour, nous sommes ravis de vous compter parmi nos nouveaux clients\n");
                    printf("    \t\tPour creer un compte, Suivez les etapes requises ci dessous:\n\n\n");
                    SignUp();break;
            case 2:
                   tr=Login2();
                   if(tr==1)
                    menu();
                    else{
                        firstrow();
                        midtext();
                        printf("\n\t\t-->>>Votre ID ou Mot de passe incorrect !!!!!!!!!!!! ");
                        lastrow();
                    }
                     break;
            case 3:
                    menuA();
					break;
            default :  printf("\n\n\t\t\t\t------choix indisponible------");
                         break;

      }
      }while(1);

          }







  return 0;
}
