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
int avionSize=0,n=0;
int searchid,op,op1;
char searchmodele[30];
aero_gestion idavion,modeleavion,capaciteavion,statusavion;


//__________________fonction ajout d'avion____________________//
void ajout(){
            printf("\n_______espace ajout d'avion__________\n");
            printf("\nentrer le nombre d'avion a ajoutee: ");
            scanf("%d",&nbravion);
             n = nbravion + avionSize;
             for(int i=avionSize; i<n;i++){
              
               idavion.flott[i].idAvion=i+100;
               int c;
               while ((c = getchar()) != '\n' && c != EOF);
               printf("entrer le modele d'avion %d:  ", i+1);
               fgets(modeleavion.flott[i].modele,sizeof(modeleavion.flott[i].modele),stdin);
               modeleavion.flott[i].modele[strcspn(modeleavion.flott[i].modele, "\n")]='\0';
               
               printf("entrer la capacite d'avion %d:  ", avionSize+1);
               scanf("%d", &capaciteavion.flott[i].capacite);
               strcpy(statusavion.flott[i].statut, "Disponible");
            }
            avionSize+=nbravion;
            printf("\nles avions sont ajoutee avec succes");
}
//__________________fonction affichage d'avion________________//
void affichage(){
            //4: Afficher la liste des avions
            printf("\n_______espace affichage des avions__________\n");
            for(int i=0; i<avionSize;i++){
                printf("avion: %d\n", i+1);
                printf("ID: %d     ",idavion.flott[i].idAvion);
                printf("modele: %s     ",modeleavion.flott[i].modele);
                printf("capacite: %d     ",capaciteavion.flott[i].capacite);
                printf("statut: %s", statusavion.flott[i].statut);
                printf("\n");
            }
}
//__________________fonction de modification__________________//
void modification(){
printf("les avions dans l'aeport: ");
affichage();
printf("entrer ID d'avion pour modifier ses informations: ");
            scanf("%d",&searchid);
            for(int i=0;i<avionSize;i++){
                  if(searchid==idavion.flott[i].idAvion){
                   do{
                     printf("tapper: \n1: pour modifier le modele d'avion\n2: pour modifier la capacite d'avion\n3: pour modifier le statut d'avion\nn:une autre nombre pour reviens au menu\n");
                     printf("votre option est: ");
                     scanf("%d", &op);
                      switch (op){
                        case 1:
                              printf("\nle modele actuelle est: %s\n",modeleavion.flott[i].modele);
                              printf("entrer le nouveau modele: ");
                              scanf(" %[^\n]%*c",modeleavion.flott[i].modele);
                              printf("le modele est modifiee avec succes\n");
                        break;
                        case 2:
                            printf("\nla capacite actuelle est: %d\n",capaciteavion.flott[i].capacite);
                            printf("entrer la nouvelle capacite: ");
                            scanf("%d", &capaciteavion.flott[i].capacite);
                            printf("la capacite est modifiee avec succes");
                        break;
                        case 3:
                             printf("\nle status actuelle est: %s\n",statusavion.flott[i].statut);
                             printf("\ntapper: \n1: pour Disponible\n2: pour En maintenance\n3: pour En vol\n");
                             scanf("%d", &op1);
                             switch (op1){
                                case 1:
                                strcpy(statusavion.flott[i].statut, "Disponible");
                                printf("la statut est modifiee avec succes");
                                break;
                                case 2:
                                strcpy(statusavion.flott[i].statut, "En maintenance");
                                printf("la statut est modifiee avec succes");
                                break;
                                case 3:
                                strcpy(statusavion.flott[i].statut, "En vol");
                                printf("la statut est modifiee avec succes");
                                break;
                                default:
                                printf("cette option n'est pas validee");
                             }
                        break;
                        default:
                     }
                   }while(op<4);

                  }
            }
}
//__________________fonction de supression____________________//
void supression(){
  printf("les avions dans l'aeport: ");
  affichage();
  printf("entrer ID d'avion pour supprimer: ");
               scanf("%d",&searchid); 
               for(int i=0;i<avionSize;i++){
                  if(searchid==idavion.flott[i].idAvion){
                      for(int j=i;j<avionSize;j++){
                          idavion.flott[j+1].idAvion=idavion.flott[j].idAvion;
                          capaciteavion.flott[j].capacite=capaciteavion.flott[j+1].capacite;
                          strcpy(modeleavion.flott[j].modele,modeleavion.flott[j+1].modele);
                          strcpy(statusavion.flott[j].statut,statusavion.flott[i+1].statut);
                      }
                      avionSize--;
                      printf("\nl'avion d'ID: %d est suprimee avec succes",idavion.flott[i].idAvion);
                  }
                  }
}
//__________________rcherche par ID___________________________//
void recherche_ID(){
        printf("entrer ID d'avion: ");
        scanf("%d",&searchid); 
        for(int i=0;i<avionSize;i++){
              if(searchid==idavion.flott[i].idAvion){
               printf("ID: %d     ",idavion.flott[i].idAvion);
               printf("modele: %s     ",modeleavion.flott[i].modele);
               printf("capacite: %d     ",capaciteavion.flott[i].capacite);
               printf("statut: %s", statusavion.flott[i].statut);
              }
            }      
}
//__________________rcherche par modele_______________________//
void recherche_modele(){
                 printf("entrer le modele d'avion:   ");
                scanf(" %[^\n]%*c",&searchmodele);
                for(int i=0;i<avionSize;i++){
                   if(strcasecmp(searchmodele,modeleavion.flott[i].modele)==0){
                     printf("ID: %d     ",idavion.flott[i].idAvion);
                     printf("modele: %s     ",modeleavion.flott[i].modele);
                     printf("capacite: %d     ",capaciteavion.flott[i].capacite);
                     printf("statut: %s", statusavion.flott[i].statut);
                }
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
             //2: Modifier un avion (modele, capacite, statut
            modification();
          break;
          case 3:
              //3: Supprimer un avion
              supression();
        break;        
        case 4:
               //4: Afficher la liste des avions
               affichage();
        break;
        case 5:
               //5: Rechercher un avion (par id ou par modele)
               printf("tapper:\n1: pour recherche par ID\n2:pour recherche par modele");
               printf("votre option est: ");
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
        break;
        case 6:
             //6: Trier les avions (par capacite, par modele alphabetique,)
               printf("tapper:\n1: tri par capacite\n2: tri par modele alphabetique");
               printf("votre option est: ");
               scanf("%d",&op1);
               switch (op1){
               case 1:
                 //tri_capacite();  
                 int sto=0;
                 int count=0;
                 for(int i=0;i<avionSize;i++){
                      count=i;
                      for(int j=avionSize;j!=0;j++){
                            sto=capaciteavion.flott[i-1].capacite;
                            capaciteavion.flott[i-1].capacite=capaciteavion.flott[i].capacite;
                            capaciteavion.flott[i].capacite=sto;

                      }
                  



                 }







               break;
               case 2:
               recherche_modele();
               break;
               default:
               printf("optin n'est pas validee");
               break;
        break;
        break;
        // case 7:
        // //7: exit
        // break;
      }
    }
    }while(option!=7); 

    return 0;
}