#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>



typedef struct {
int idAvion;
char modele[100];
int capacite;
char statut[30];
}avion_gestion;


typedef struct {
char aeroName[100];
int nbrAvion;
avion_gestion flott[100];
}aero_gestion;


//______________________variables globale____________________//
int nbravion;
int avionSize=0,n=0;
int searchid,op,op1;
char searchmodele[30];
int disponibleSize=0;
int en_maintenanceSize=0;
int en_volSize=0;
aero_gestion aero;



//__________________fonction ajout d'avion____________________//
void ajout(){
            printf("\n\033[1;34m+++_______espace ajout d'avion__________+++\033[0m\n");
            printf("entrer le nombre d'avion a ajoutee: ");
            scanf("%d",&nbravion);
             n = nbravion + avionSize;
             for(int i=avionSize; i<n;i++){
              
               aero.flott[i].idAvion=i+100;
               int c;
               while ((c = getchar()) != '\n' && c != EOF);
               printf("\nentrer le modele d'avion %d:  ", i+1);
               fgets(aero.flott[i].modele,sizeof(aero.flott[i].modele),stdin);
               aero.flott[i].modele[strcspn(aero.flott[i].modele, "\n")]='\0';
               do{
               printf("entrer la capacite d'avion %d:  ", avionSize+1);
               scanf("%d", &aero.flott[i].capacite);
               strcpy(aero.flott[i].statut, "Disponible");
               }while(aero.flott[i].capacite<1);
            }
            avionSize+=nbravion;
            printf("\nles avions sont ajoutee avec succes\n");
}
//__________________fonction affichage d'avion________________//
void affichage(){
            for(int i=0; i<avionSize;i++){
                printf("avion: %d\n", i+1);
                printf("| ID: %d     ",aero.flott[i].idAvion);
                printf("| modele: %s     ",aero.flott[i].modele);
                printf("| capacite: %d     ",aero.flott[i].capacite);
                printf("| statut: %s", aero.flott[i].statut);
                printf("\n");
            }
}
//__________________fonction de modification__________________//
void modification(){
printf("les avions dans l'aeport: ");
affichage();
printf("\nentrer ID d'avion pour modifier ses informations: ");
            scanf("%d",&searchid);
            for(int i=0;i<avionSize;i++){
                  if(searchid==aero.flott[i].idAvion){
                   do{
                     printf("\ntapper: \n1: pour modifier le modele d'avion\n2: pour modifier la capacite d'avion\n3: pour modifier le statut d'avion\nn:une autre nombre pour reviens au menu\n");
                     printf("\nvotre option est: ");
                     scanf("%d", &op);
                      switch (op){
                        case 1:
                              printf("\nle modele actuelle est: %s\n",aero.flott[i].modele);
                              printf("entrer le nouveau modele: ");
                              scanf(" %[^\n]%*c",aero.flott[i].modele);
                              printf("le modele est modifiee avec succes\n");
                        break;
                        case 2:
                            printf("\nla capacite actuelle est: %d\n",aero.flott[i].capacite);
                            printf("entrer la nouvelle capacite: ");
                            scanf("%d", &aero.flott[i].capacite);
                            printf("la capacite est modifiee avec succes");
                        break;
                        case 3:
                             printf("\nle status actuelle est: %s\n",aero.flott[i].statut);
                             printf("\ntapper: \n1: pour Disponible\n2: pour En maintenance\n3: pour En vol\n");
                             printf("\nvotre option est: ");
                             scanf("%d", &op1);
                             switch (op1){
                                case 1:
                                strcpy(aero.flott[i].statut, "Disponible");
                                printf("\nla statut est modifiee avec succes");
                                break;
                                case 2:
                                strcpy(aero.flott[i].statut, "En maintenance");
                                printf("\nla statut est modifiee avec succes");
                                break;
                                case 3:
                                strcpy(aero.flott[i].statut, "En vol");
                                printf("\nla statut est modifiee avec succes");
                                break;
                                default:
                                printf("\ncette option n'est pas validee");
                             }
                        break;
                     }
                   }while(op<4);
                  }
                  }
            }
//__________________fonction de supression____________________//
void supression(){
  printf("les avions dans l'aeport: \n");
  affichage();
  printf("\nentrer ID d'avion pour supprimer: ");
               scanf("%d",&searchid); 
               for(int i=0;i<avionSize;i++){
                  if(searchid==aero.flott[i].idAvion){
                      for(int j=i;j<avionSize;j++){
                          aero.flott[j+1].idAvion=aero.flott[j].idAvion;
                          aero.flott[j].capacite=aero.flott[j+1].capacite;
                          strcpy(aero.flott[j].modele,aero.flott[j+1].modele);
                          strcpy(aero.flott[j].statut,aero.flott[i+1].statut);
                      }
                      avionSize--;
                      printf("\nl'avion d'ID: %d est suprimee avec succes",aero.flott[i].idAvion);
                  }
                  }
}
//__________________fonction rcherche par ID__________________//
void recherche_ID(){
        printf("entrer ID d'avion: ");
        scanf("%d",&searchid); 
        for(int i=0;i<avionSize;i++){
              if(searchid==aero.flott[i].idAvion){
               printf("avion:  ");
               printf("| ID: %d     ",aero.flott[i].idAvion);
               printf("| modele: %s     ",aero.flott[i].modele);
               printf("| capacite: %d     ",aero.flott[i].capacite);
               printf("| statut: %s", aero.flott[i].statut);
              }
            }      
}
//__________________fonction rcherche par modele______________//
void recherche_modele(){
                 printf("entrer le modele d'avion:   ");
                scanf(" %[^\n]%*c",&searchmodele);
                for(int i=0;i<avionSize;i++){
                   if(strcasecmp(searchmodele,aero.flott[i].modele)==0){
                     printf("avion:  ");
                     printf("| ID: %d     ",aero.flott[i].idAvion);
                     printf("| modele: %s     ",aero.flott[i].modele);
                     printf("| capacite: %d     ",aero.flott[i].capacite);
                     printf("| statut: %s", aero.flott[i].statut);
                }
              } 
}
//__________________fonction tri par capacite_________________//
void tri_capacite(){
avion_gestion sto;
                  for(int i=0;i<avionSize;i++){
                       for(int j=0;j<avionSize-i-1;j++){
                           if(aero.flott[j].capacite>aero.flott[j+1].capacite){
                             sto=aero.flott[j];
                             aero.flott[j]=aero.flott[j+1];
                             aero.flott[j+1]=sto;
                            }
                        }
                   }
                   affichage();
}
//________________fonction tri par capacite___________________//
void tri_modele(){
                  avion_gestion sto;
                  for(int i=0;i<avionSize;i++){
                       for(int j=0;j<avionSize-i-1;j++){
                           if(strcasecmp(aero.flott[j+1].modele,aero.flott[j].modele)<0){
                             sto=aero.flott[j];
                             aero.flott[j]=aero.flott[j+1];
                             aero.flott[j+1]=sto;
                            }
                        }
                   }
                   affichage();
}
//________fonction statistiques selon le statut_______________//
void statistique_statut(){
                for(int i=0;i<avionSize;i++){
                   if(strcmp(aero.flott[i].statut,"Disponible")==0){
                      disponibleSize++;
                   }
                   else if(strcmp(aero.flott[i].statut,"En maintenance")==0){
                      en_maintenanceSize++;
                   }
                   else if(strcmp(aero.flott[i].statut,"En vol")==0){
                      en_volSize++;
                   }
                }
                printf("\nle nombre des avions Disponible est: %d\n",disponibleSize);
                printf("le nombre des avions En maintenance est: %d\n",en_maintenanceSize);
                printf("le nombre des avions En vol est: %d\n",en_volSize);

}
//________fonction l'avion de max capacite____________________//
void maxcapacite(){
  int capacite_initial=aero.flott[0].capacite;
  int r=0;
for(int i=0;i<avionSize;i++){
  if(capacite_initial<aero.flott[i].capacite){
    capacite_initial = aero.flott[i].capacite;
    r=i;
  }
}
printf("\nl'avion ayant la plus grande (max) capacite est: l'avion: ");
printf("| ID: %d   ", aero.flott[r].idAvion);
printf("| modele: %s  ", aero.flott[r].modele);
printf("| statut: %s   ", aero.flott[r].statut);
printf("| capacite : %d   ", aero.flott[r].capacite);
}
//________fonction l'avion de min capacite____________________//
void mincapacite(){
  int capacite_initial=aero.flott[0].capacite;
  int r=0;
for(int i=0;i<avionSize;i++){
  if(capacite_initial>aero.flott[i].capacite){
    capacite_initial = aero.flott[i].capacite;
    r=i;
  }
}
printf("\nl'avion ayant la plus petite (min) capacite est: l'avion: ");
printf("| ID: %d   ", aero.flott[r].idAvion);
printf("| modele: %s   ", aero.flott[r].modele);
printf("| statut: %s   ", aero.flott[r].statut);
printf("| capacite : %d   ", aero.flott[r].capacite);
}




int main(){
    //variables utilusee
    int option;
   

            printf("entrer le nom de aeroport: ");
            fgets(aero.aeroName,sizeof(aero.aeroName),stdin);
            aero.aeroName[strcspn(aero.aeroName, "\n")] = '\0';
    
            printf("\n\n\033[1;32m______------bienvenu dans l'aeroport: %s------______\033[0m\n",aero.aeroName);
    do{
            
            printf("\n\033[1;34m\n            _________============menu============_________\033[0m\n");
            printf("+_tapper:_______________________________________________________+\n");
            printf("| 1: Ajouter un avion (ou plusieurs)                            |\n");
            printf("| 2: information sur l'aeroport                                 |\n");
            printf("| 3: Modifier un avion (modele, capacite, statut)               |\n");
            printf("| 4: Supprimer un avion                                         |\n");
            printf("| 5: Afficher la liste des avions                               |\n");
            printf("| 6: Rechercher un avion (par id ou par modele)                 |\n");
            printf("| 7: Trier les avions (par capacite, par modele alphabetique,)  |\n");
            printf("| 8: statistiques                                               |\n");
            printf("| 9: Le coefficient d'occupation                                |\n");
            printf("| 10: pour exit le program                                      |\n");
            printf("|_______________________________________________________________|\n");
            printf("\n\033[1;32mvotre choix est: \033[0m");
            scanf("%d",&option);
             
      switch(option){
        case 1:
               ajout();
         break;
         case 2:
              printf("\n\033[1;34m+++_______espace informations d'aeroport__________+++\033[0m\n");
              printf("\nNome de l'aeroport: %s\n",aero.aeroName);
              aero.nbrAvion=avionSize;
              printf("le nombre des avions est: %d\n",aero.nbrAvion);
              affichage();

         break;
         case 3:
              printf("\n\033[1;34m+++_______espace modification des avions__________+++\033[0m\n");
              modification();
          break;
          case 4:
              printf("\n\033[1;34m+++_______espace supression des avions__________+++\033[0m\n");
              supression();
        break;        
        case 5:
               printf("\n\033[1;34m+++_______espace affichage des avions__________+++\033[0m\n");
               affichage();
        break;
        case 6:
               printf("\n\033[1;34m+++_______espace recherche par ID ou par modele__________+++\033[0m\n");
               printf("tapper:\n1: pour recherche par ID\n2:pour recherche par modele");
               printf("\nvotre option est: ");
               scanf("%d",&op1);
               switch (op1){
               case 1:
                 recherche_ID();   
               break;
               case 2:
                 recherche_modele();
               break;
               default:
               printf("optin n'est pas validee");
               break;
               }
        break;
        case 7:
               printf("\n\033[1;34m+++_______espace Trie des avions__________+++\033[0m\n");
               printf("tapper:\n1: tri par capacite\n2: tri par modele alphabetique\n");
               printf("votre option est: ");
               scanf("%d",&op1);
               
              switch (op1){
                case 1:
                tri_capacite();
                break;
                case 2:
                tri_modele();
                break;
                default:
                printf("optin n'est pas validee");
                break;
              }
        break;

        case 8:
                printf("\n\033[1;34m+++_______espace statistiques d'qeroport__________+++\033[0m\n");
                printf("le nombre totale des avions dans le parc est: %d", avionSize);
                statistique_statut();
                //nbr total des flott
                int sumflott=0;
                for(int i=0;i<avionSize;i++){
                    sumflott+=aero.flott[i].capacite;
                 }
                printf("\nla Capacite totale de la flotte est: %d\n", sumflott);

                maxcapacite();

                mincapacite();
        break;        
        case 9:
          int coeff_occupation;
          coeff_occupation=(disponibleSize/avionSize)*100;
          printf("\nLe coefficient d'occupation du parc est: %d", coeff_occupation);
          printf("\nle pourcentage d'avions disponibles dans l'aeroport est: %d%%",coeff_occupation);
        break; 
        case 10:
        exit(0);
        break;
        default:
        printf("cette option est non validee veiller choisir from (1-9)");
        break;
      }
    }while(option<=10); 

    return 0;
}