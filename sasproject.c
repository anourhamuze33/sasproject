#include <stdio.h>
#include <string.h>
typedef struct {
int idAvion;
char modele[100];
int capacite;
char statut[30];
}avion_gestion;

typedef struct {
char airoName[100];
int nbravion;
avion_gestion flott[100];
char Idavion_dis[100];
}aero_gestion;


//______________________variables globale____________________//
int nbravion;
aero_gestion idavion,modeleavion,capaciteavion,statusavion;


//__________________fonction ajout d'avion___________________//
void ajout(){
            printf("\n_______espace ajout d'avion__________\n");
            printf("\nentrer le nombre d'avion a ajoutee: ");
            scanf("%d",&nbravion);
            for(int i=0; i<nbravion;i++){
               idavion.flott[i].idAvion=i+100;
               int c;
               while ((c = getchar()) != '\n' && c != EOF);
               printf("entrer le modele d'avion %d:  ", i+1);
               fgets(modeleavion.flott[i].modele,sizeof(modeleavion.flott[i].modele),stdin);
               modeleavion.flott[i].modele[strcspn(modeleavion.flott[i].modele, "\n")]='\0';
               
               printf("entrer la capacite d'avion %d:  ", i+1);
               scanf("%d", &capaciteavion.flott[i].capacite);
               strcpy(statusavion.flott[i].statut, "Disponible");
            }
            printf("\nles avions sont ajoutee avec succes");
}
//__________________fonctio affichage d'avion________________//
void affichage(){
            //4: Afficher la liste des avions
            printf("\n_______espace affichage des avions__________\n");
            for(int i=0; i<nbravion;i++){
                printf("avion: %d\n", i+1);
                printf("ID: %d     ",idavion.flott[i].idAvion);
                printf("modele: %s     ",modeleavion.flott[i].modele);
                printf("capacite: %d     ",capaciteavion.flott[i].capacite);
                printf("statut: %s", statusavion.flott[i].statut);
                printf("\n");
            }



}






int main(){
    //variables utilusee
    aero_gestion airo_name;
    int option;
   

            printf("entrer le nom de aeroport: ");
            fgets(airo_name.airoName,sizeof(airo_name.airoName),stdin);
            airo_name.airoName[strcspn(airo_name.airoName, "\n")] = '\0';
    
            printf("________________bienvenu dans l'aeroport %s ________________",airo_name.airoName);
    do{    
            printf("\n_________menu_________\ntapper:\n");
            printf("1: Ajouter un avion (ou plusieurs)\n");
            printf("2: Modifier un avion (modele, capacite, statut)\n");
            printf("3: Supprimer un avion\n");
            printf("4: Afficher la liste des avions\n");
            printf("5: Rechercher un avion (par id ou par modele)\n");
            printf("6: Trier les avions (par capacite, par modele alphabetique,)\n");
            printf("7: exit\n");
            printf("votre choix est: ");
            scanf("%d",&option);
             
      switch(option){
        case 1:
            //1: Ajouter un avion (ou plusieurs)
               ajout();
         break;
         case 2:
             //2: Modifier un avion (modele, capacite, statut)
            int searchid,op,op1;
            printf("entrer ID d'avion pour modifier ses informations: ");
            scanf("%d",&searchid);
            for(int i=0;i<nbravion;i++){
                  if(searchid==idavion.flott[i].idAvion){
                   do{
                     printf("tapper: \n1: pour modifier le modele d'avion\n2: pour modifier la capacite d'avion\n3: pour modifier le statut d'avion\n");
                     printf("votre option est: ");
                     scanf("%d", &op);
                      switch (op){
                        case 1:
                              fgets(modeleavion.flott[searchid].modele, sizeof(modeleavion.flott[searchid].modele), stdin);
                              modeleavion.flott[searchid].modele[strcspn(modeleavion.flott[searchid].modele, "\n")]='\0';
                              getchar();
                              printf("le modele est modifiee avec succes");
                        break;
                        case 2:
                            scanf("%d", &capaciteavion.flott[searchid].capacite);
                            printf("la capacite est modifiee avec succes");
                        break;
                        case 3:
                             printf("tapper: \n1: pour Disponible\n2: pour En maintenance\n3: pour En vol\n");
                             scanf("%d", &op1);
                             switch (op1){
                                case 1:
                                strcpy(statusavion.flott[searchid].statut, "Disponible");
                                printf("la statut est modifiee avec succes");
                                break;
                                case 2:
                                strcpy(statusavion.flott[searchid].statut, "En maintenance");
                                printf("la statut est modifiee avec succes");
                                break;
                                case 3:
                                strcpy(statusavion.flott[searchid].statut, "En vol");
                                printf("la statut est modifiee avec succes");
                                break;
                                default:
                                printf("cette option n'est pas validee");
                             }
                        break;
                        default:
                     }
                   }while(op!=3);

                  }
            }
            




         break;
         // case 3:
         // //3: Supprimer un avion
         // break;
        case 4:
            //4: Afficher la liste des avions
                 affichage();
        break;
        




        // break;
        // case 5:
        // //5: Rechercher un avion (par id ou par modele)
        // break;
        // case 6:
        // //6: Trier les avions (par capacite, par modele alphabetique,)
        // break;
        // case 7:
        // //7: exit
        // break;
      }
    }while(option!=7); 

    return 0;
}