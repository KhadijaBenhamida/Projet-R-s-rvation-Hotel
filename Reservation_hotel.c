#include <stdio.h> 
#include <stdlib.h> 
#include <ctype.h> 
#include <conio.h> 
#include <string.h> 
#include <time.h> 
 
#define NUM 5    //Pour le Max de l'Id d'un client 
#define PH 13    //Pour le Max du numéro de téléphone 
#define MIN 30   //Pour le nom et le prénom du client 
#define MAX 51   //Pour l'adresse du client 
#define JOUR 3   //Pour la durée 
#define N 30     //Pour la nationalité 
#define MAXC 100 //Pour le nombre Maximal des chambres 
 
void ajouter();  // une fonction pour l'ajout des informations des clients 
void modifier(); // une fonction qui permet de modifier les informations d'un client 
void supprimer();// une fonction pour supprimer les informations d'un client 
void afficher(); // une fonction pour afficher la liste des clients par ordre alphabétique 
void rech_nom(); // une fonction pour la recherche par nom 
void rech_id();  // une fonction qui fait la recherche selon l'id 
void chercher(); // une fonction qui fait la recherche selon l'id ou le nom 
void verse(struct Client tb[],int *n);// une fonction qui met les enresgistrements dans un tableau de stucture 
void trie();     // une fonction qui trie les infos par noms et les affiche par odre alphabétique 
void trieI();    // une fonction qui trie et affiche les infos selon l'id 
 
 
/*les fonctions d'aide pour vérifier que les infornmations saisies sont correctes */ 
void ver_nom(char *,int);    //Pour vérifier le nom et le prénom 
void ver_add(char *,int);    //Pour vérifier l'addresse 
void ver_jours(char *,int);  //Pour le maximun un nombre de 2 chiffres ou 1 
void ver_phone(char *,int);  //Pour vérifier le numéro de téléphone 
int compare (const void * a, const void * b); // Une fonction d'aide pour le trie 
 
 
 struct Client                //Pour récuperer les informations des clients 
{ 
 int id;                // id 4 entiers 
 char nom[MIN];            // Nom et Prénom du client 
    char nationalite[N];   // Nationalité du client 
 char addresse[MAX];       // Adresse du client 
 char phone[PH];           // Numéro de téléphone max:13 entiers 
 char jours[JOUR];       // Durée 
 
}C; 
// la fonctions main () 
 
int main(){ 
 char choix; 
 int i; 
 time_t t; 
 time(&t); 
 system("cls"); 
 system("color 1F"); 
 printf("\t\t*************************************************\n"); 
 printf("\t\t*                                               *\n"); 
 printf("\t\t*       ------------------                      *\n"); 
 printf("\t\t*        SOYEZ LE BIENVENUE                     *\n"); 
 printf("\t\t*       --------------------                    *\n"); 
 printf("\t\t*                                               *\n"); 
 printf("\t\t*                                               *\n"); 
 printf("\t\t*************************************************\n\n\n"); 
 
for(i=0;i<80;i++) 
  printf("-"); 
     printf("\nDate: : %s",ctime(&t)); 
     for(i=0;i<80;i++) 
  printf("-"); 
 printf(" \n Appuyer pour continue:"); 
 getch(); 
    system("cls"); 
 while (1)  // une boucle infinie qui s'arrête avec un break 
 { 
  system("color F1"); 
  system("cls"); 
   for(i=0;i<80;i++) 
  printf("-"); 
  printf("\n"); 
  printf("   **************************  |MENU|  ************************* \n"); 
  for(i=0;i<80;i++) 
  printf("-"); 
  printf("\n"); 
  printf("\t\t *Tappez votre choix dans le menu s\'il vous plait*:"); 
  printf("\n\n"); 
  printf(" \n Entrer 1 -> Reserver une chambre"); 
  printf("\n------------------------"); 
  printf(" \n Entrer 2 -> Afficher tous les clients inscrits"); 
  printf("\n----------------------------------"); 
  printf(" \n Entrer 3 -> Supprimer une reservation"); 
  printf("\n-----------------------------------"); 
  printf(" \n Entrer 4 -> Recherher une reservation"); 
  printf("\n-----------------------------------"); 
  printf(" \n Entrer 5 -> Modifier un enregistrement"); 
  printf("\n-----------------------"); 
  printf(" \n Entrer 6 -> Quitter"); 
  printf("\n-----------------"); 
  printf("\n"); 
  for(i=0;i<80;i++) 
  printf("-"); 
     printf("\nDate : %s",ctime(&t)); 
     for(i=0;i<80;i++)
       printf("-"); 
 
  choix=getche(); 
  choix=toupper(choix); 
  switch(choix) 
  { 
   case '1': 
    ajouter(); 
    break; 
   case '2': 
    afficher(); 
    break; 
   case '3': 
    supprimer(); 
    break; 
   case '4': 
    chercher(); 
    break; 
   case '5': 
    modifier(); 
    break; 
   case '6': 
    system("cls"); 
    printf("\n\n\t *****MERCI*****"); 
    printf("\n\tD\' AVOIR FAIT CONFIANCE A NOTRE SERVICE"); 
    exit(0); 
    break; 
   default: 
    system("cls"); 
    printf("Choix INVALID !"); 
    printf("\nAppuyer pour continuer"); 
    getch(); 
  } 
 } 
    return 0; 
} 
// Fonction pour ajouter une réservavtion ou plusieurs : 
void ajouter(){ 
    FILE *f=NULL; 
    FILE *f1 =NULL; 
    int ent,i=0; 
    char choix; 
 
    f1=fopen("id.txt","r");// un fichier qui contient les ids à chaque fois on incrémente l'id pour donner le donner à l'utilisateur 
    if(f1!=NULL){ 
        fscanf(f1,"%d",&ent); 
    } 
    fclose(f1); 
    f = fopen("personne.txt","a"); 
 
 
    if(f !=NULL){ 
        do 
        {   system("cls"); // On demande au client de saisir ses propres infos 
            printf("\nEntrer votre nom complet: "); 
            ver_nom(C.nom,MAX); 
            printf("\nEnter votre nationalite: "); 
            ver_nom(C.nationalite,N); 
            printf("\nEntrer votre address: "); 
            ver_add(C.addresse,MAX); 
            printf("\nEntrer votre numero de telephone: "); 
            ver_phone(C.phone,PH); 
            printf("\nEntrer le nombre de jours que vous desirez rester (DUREE): "); 
            ver_jours(C.jours,JOUR); 
            C.id =ent; // On donne au client l'id qui se trouve dans le fichier 
            fprintf(f,"%d,%s,%s,%s,%s,%s\n",C.id,C.nom,C.nationalite,C.addresse,C.phone,C.jours); // On enregistre les infos dans le fichier 
   printf("\n\nChambre reservee avec succes!!"); 
   printf("\n\nVotre Id est: %d",ent); 
            printf("\nVoulez-vous continuer![O/N]\n"); 
            ent++;  // On incrémente ent pour donner au prochain client un id different 
            choix =toupper(getche());  // On prend la saisie du client et le convertit en majuscule 
        } while (choix !='N'); 
        f1=fopen("id.txt","w"); 
        if(f1!=NULL){ 
            fprintf(f1,"%d",ent); 
        } 
        fclose(f1); 
        fclose(f); 
    } 
 
} 
//Fonction de recherche : 
void chercher(){ 
 char choix; 
 system("cls"); 
 printf(" \n Entrez 1 -> Pour faire une recherche selon le nom\n"); 
    printf("\n------------------------"); 
 printf(" \n Entrez 2 -> Pour faire une recherche selon l'id\n"); 
    choix=toupper(getche()); 
 switch (choix) 
 { 
 case '1': 
  rech_nom(); 
  break; 
 case '2': 
     rech_id(); 
     break; 
 default: 
  printf("\nSAISIE INVALIDE !"); 
  printf("\nAppuyez pour continue"); 
  getch(); 
  break; 
 } 
 
} 
//Fonction de l'affichage : 
void afficher(){ 
 char choix; 
 system("cls"); 
 printf(" \n Entrer 1 -> Pour Afficher selon l'odre alphabetique"); 
    printf("\n-------------------------------------------------"); 
 printf(" \n Enter 2  -> Pour Afficher selon l'odre de l'id\n"); 
    choix=getche(); 
 switch (choix) 
 { 
 case '1': 
  trie(); 
  break; 
 case '2': 
     trieI(); 
     break; 
 default: 
  printf("\n SAISIE INVALIDE !"); 
  printf("\nAppuyez pour continue"); 
  getch(); 
 } 
 getch(); 
} 
//Fonction de  modification : 
void modifier(){ 
 FILE *f=NULL; 
 struct Client t[MAXC]; 
 int tmp; 
 int i,n,j; 
 int ok=0; 
 verse(t,&n); 
 printf("\nEntrer L'id du client que vous voulez modifier:\n"); 
 scanf("%d",&tmp); 
 system("cls"); 
  for(i=0;i<n;i++){ // on supprime le client d'abord pour l'ajouter vers la fin pour pouvoir lui cree un nouveau id 
  if(t[i].id==tmp){ 
   ok=1; 
   for(j=i+1;j<n;j++){ 
    t[j-1].id=t[j].id; 
    strcpy(t[j-1].nom,t[j].nom); 
    strcpy(t[j-1].nationalite,t[j].nationalite); 
    strcpy(t[j-1].addresse,t[j].addresse); 
    strcpy(t[j-1].phone,t[j].phone); 
    strcpy(t[j-1].jours,t[j].jours); 
 
   } 
   n--; 
   i--; 
 
  } 
 } 
 
 if(ok==1){
printf("\nEntrer votre nom complet: "); 
            ver_nom(t[n].nom,MAX); 
            printf("\nEnter votre nationalite: "); 
            ver_nom(t[n].nationalite,N); 
            printf("\nEntrer votre address: "); 
            ver_add(t[n].addresse,MAX); 
            printf("\nEntrer votre numero de telephone: "); 
            ver_phone(t[n].phone,PH); 
            printf("\nEntrer le nombre de jours que vous desirez rester (DUREE): "); 
            ver_jours(t[n].jours,JOUR); 
   t[n].id = t[n-1].id +1; 
 
       f=fopen("personne.txt","w"); 
    if(f!=NULL){ 
       for(i=0;i<=n;i++){ 
        fprintf(f,"%d,%s,%s,%s,%s,%s",t[i].id,t[i].nom,t[i].nationalite,t[i].addresse,t[i].phone,t[i].jours); 
       } 
  } 
     fclose(f); 
 
  printf("\nVos informations ont ete modifies avec succes !\n"); 
  printf("Votre nouveau id est: %d",t[n].id); 
 
 }else 
 { 
  printf("\nId du client introuvable !!\n"); 
 } 
 getch(); 
 
} 
//Fonction de suppression : 
void supprimer(){ 
 FILE *f=NULL; 
 struct Client t[MAXC]; 
 int n,i,j; 
 int ok=0; 
 int tmp; 
 verse(t,&n); 
 printf("\nEntrer l'identifiant du client a supprimer :\n"); 
 scanf("%d",&tmp); 
 system("cls"); 
 for(i=0;i<n;i++){ 
  if(t[i].id==tmp){ 
                ok =1; 
   for(j=i+1;j<n;j++){ 
    t[j-1].id=t[j].id; 
    strcpy(t[j-1].nom,t[j].nom); 
    strcpy(t[j-1].nationalite,t[j].nationalite); 
    strcpy(t[j-1].addresse,t[j].addresse); 
    strcpy(t[j-1].phone,t[j].phone); 
    strcpy(t[j-1].jours,t[j].jours); 
 
   } 
   i--; 
   n--; 
 
  } 
 } 
 if(ok==1){ 
        f=fopen("personne.txt","w"); 
 if(f!=NULL){ 
  for(i=0;i<n;i++){ 
   fprintf(f,"%d,%s,%s,%s,%s,%s",t[i].id,t[i].nom,t[i].nationalite,t[i].addresse,t[i].phone,t[i].jours); 
  } 
 } 
 fclose(f); 
 printf("\nVos informations ont ete supprimes avec succes !"); 
 }else{ 
     printf("Desole! Saisie introuvable !"); 
 
 } 
 getch(); 
 
 
} 
 
 
void verse(struct Client record[],int *n){ 
        FILE * file; 
        char line[1000]; 
  char nom[30]; 
        char *item; 
        int count = 0; 
        file = fopen("personne.txt","r"); 
 
        while (fgets(line,1000,file)) { //On lit tous le fichier ligne par ligne avec fgets 
 
                item = strtok(line,","); //strtok() est une fonction qui sépare une chaine selon le delimiteur donne. ici: "," 
                record[count].id = atoi(item); // atoi est une fonction qui prend un string qui est un entier et le convertit en entier 
                item = strtok(NULL,","); 
                strcpy(record[count].nom,item); 
                item = strtok(NULL,","); 
                strcpy(record[count].nationalite,item); 
    item = strtok(NULL,","); 
                strcpy(record[count].addresse,item); 
    item = strtok(NULL,","); 
                strcpy(record[count].phone,item); 
    item = strtok(NULL,","); 
                strcpy(record[count].jours,item); 
                count++; 
  } 
  *n=count; 
        fclose(file); 
} 
 
void trie(){ 
 struct Client tab[MAXC]; // On definit un tableau de type Client 
 int n; 
 int i; 
 verse(tab,&n);  // On verse tous les données du fichier dans le tableau 
 qsort(tab,n,sizeof(Client),compare); // on utilise la fonction qsort pour trier le fichier par ordre alphabétique 
 for(i=0;i<n;i++){ 
  printf("ID: %d\nNom: %s\nNationalite:%s\nAddresse:%s\nNumero:%s\nDuree:%s\n",tab[i].id,tab[i].nom,tab[i].nationalite,tab[i].addresse,tab[i].phone,tab[i].jours); 
 
 } 
 getch(); 
} 
 
 
void rech_nom() 
{ 
    struct Client tab[MAXC]; 
 char nom[MIN]; 
 int i,n; 
 int ok=0; 
 verse(tab,&n); 
 printf("\nEntrer le nom que vous voulez chercher :\n"); 
 ver_nom(nom,MIN); 
 for(i=0;i<n;i++){ 
  if(strcmp(nom,tab[i].nom) ==0){ 
   ok =1; 
   break; // Quand on trouve le nom on arrête la boucle 
  } 
 
 } 
 
 if(ok==1){ 
  printf("\n Voici les donnees trouvees :\n"); 
  printf("ID: %d\nNom: %s\nNationalite:%s\nAddresse:%s\nNumero:%s\nDuree:%s\n",tab[i].id,tab[i].nom,tab[i].nationalite,tab[i].addresse,tab[i].phone,tab[i].jours); 
 }else{ 
  printf("Desole! Recherche Introuvale !\n"); 
 } 
 getch(); 
 
}
// la fonction de recherche par id 
void rech_id(){ 
 struct Client tab[MAXC]; 
 int i,n; 
 int id; 
 int ok =0; 
 verse(tab,&n); 
 printf("\nEntrer l'id du client que vous souhaiter chercher\n"); 
 scanf("%d",&n); 
 for(i=0;i<n;i++){ 
  if(tab[i].id==id){ 
   ok =1; 
   break; // quand on trouve le nom on arrete la boucle 
  } 
 
 } 
 
 if(ok==1){ 
  printf("voici les resultats cherhcer\n"); 
  printf("ID: %d\nNom: %s\nNationalite:%s\nAddresse:%s\nNumero:%s\nDuree:%s\n",tab[i].id,tab[i].nom,tab[i].nationalite,tab[i].addresse,tab[i].phone,tab[i].jours); 
 }else{ 
  printf("Desole! Recherche Intouvable !\n"); 
 } 
 getch(); 
} 
 
void trieI(){ 
 struct Client tab[MAXC]; 
 int n; 
 int i,j; 
 verse(tab,&n); 
 for(i=0;i<n;i++){ 
  printf("ID: %d\nNom: %s\nNationalite:%s\nAddresse:%s\nNumero:%s\nDuree:%s\n",tab[i].id,tab[i].nom,tab[i].nationalite,tab[i].addresse,tab[i].phone,tab[i].jours); 
 
 } 
 getch(); 
 
} 
 
 
int compare (const void * a, const void * b) 
{ 
 struct Client * pA = (struct Client  *) a; 
 struct Client * pB =(struct Client *) b; 
  return (strcmp(pA->nom, pB->nom)); 
 
} 
 
 
void ver_phone(char *ph, int taille) 
{ 
 int p=0; 
 char ch; 
 
 do 
 { 
  ch=getch(); 
 
  if( (ch>='0' && ch<='9')&& (p<taille-1) ) 
  { 
   *ph=ch; // si On reçcoit un nombre correct on l'affecte au pointeur 
   ph++;  // On incrémente le pointeur 
   p++; 
   printf("%c",ch); // On affiche la valeur entrée pour que l'utilisteur voit ce qui'il écrit 
  }else if( (ch==8)&&(p>0) ) // si l'utilisateur appuye sur Effacer (backspace button) 
   { 
                printf("%c%c%c",8,32,8); //On affiche l'espace 
    p--; // On décrémente p 
    ph--; // On décrémente le pointeur 
   } 
 
 }while(ch!=13 || p<taille-1); // On continue jusqu'il donne la taille exacte du numéro demandée 
 
 *ph='\0'; // Fin de la chaîne de caractère 
 
} 
void ver_nom(char *p, int taille) 
{ 
 int j=0; 
 char cj; 
 
 do 
 { 
 
  cj=toupper(getch()); // On convertit la saisie en majuscule pour faciliter la comparaison 
 
  if(((cj>='a' && cj<='z')||(cj>='A' && cj<='Z')||(cj==' ')) && (j<taille-1)) 
  { 
   *p++=cj; 
   j++; 
   printf("%c",cj); 
  }else if(cj==8 && j>0) 
   { 
               printf("%c%c%c",8,32,8); 
    j--; p--; 
   } 
 
 }while(cj!=13); 
 
 *p='\0'; 
} 
void ver_add(char *p, int taille) 
{ 
 int l=0; 
 char ad; 
 
 do 
 { 
 
  ad=toupper(getch()); 
 
  if(((ad>='a' && ad<='z')||(ad>='A' && ad<='Z')||(ad==' ')||(ad=='-')||(ad==',')||(ad=='/')||(ad=='.')||(ad>='0' && ad<='9')) && (l<taille-1)) 
  { 
   *p++=ad; 
   l++; 
   printf("%c",ad); 
  } 
 
  else 
 
   if( (ad==8)&&(l>0) ) 
   { 
            printf("%c%c%c",8,32,8); 
    l--; p--; 
   } 
 
 }while(ad!=13); 
 
   *p='\0'; 
} 
void ver_jours(char *p, int taille) 
{ 
 int i=0; 
 char ch; 
 
 do 
 { 
  ch=getch(); 
 
  if( (ch>='0' && ch<='9') && (i<taille-1) ) 
  { 
   *p=ch; 
   p++; 
   i++; 
   printf("%c",ch); 
  } 
  else 
   if(ch==8 && i>0) 
   { 
    printf("%c%c%c",8,32,8); 
 
    i--; 
    p--; 
   } 
 
 }while(ch!=13 || i<taille-1); 
 
 *p='\0'; 
 
}
