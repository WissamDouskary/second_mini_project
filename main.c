#include <stdio.h>
#include <stdlib.h>

#define MAX_CONTACT 100
#define MAX 100

typedef struct {
    char nom[MAX];
    char num[MAX];
    char email[MAX];
}Contact;
    int c=0;
    Contact contacts[MAX_CONTACT];
//1. ajouter un contact
void addContact(){
    int multi;
    printf("tapez le nombre de contacts que vous souhaitez ajouter : ");
    scanf("%d",&multi);
    if( multi + c >= MAX_CONTACT){
        printf("la liste de contacts est pleine !");
        return;
    }
    for(int i=0 ; i < multi ; i++){
    printf("ajouter le nom pour Contact %d :",i+1);
    scanf("%s",contacts[c].nom);
    printf("ajouter le numero de telephone pour Contact %d :",i+1);
    scanf("%s",contacts[c].num);
    printf("ajouter le adresse email pour Contact %d :",i+1);
    scanf("%s",contacts[c].email);
    c++;
    }
}
// 4.afficher tous les contacts
void tous_Contacts(){
    if(c <= 0){
        printf("aucun contact disponible ! ");
    }
    else{
        printf("\n Les Contacts sont : \n");
        for(int i = 0 ; i < c; i++){
            printf("-----------------------------------\n");
            printf("Le nom du contact %d : %s \n" ,i+1 ,contacts[i].nom);
            printf("Le numero de telephone du contact %d : %s \n",i+1,contacts[i].num );
            printf("L'adresse email du contacts %d : %s \n",i+1, &contacts[i].email);
        }
    }
}
//2. modifier un contact
void Modifier_Contact(){
        char name[100];
        printf("ajouter le nom de contact dont vous souhaitez modifier les information :");
        scanf("%s", name);
        for(int i = 0 ; i < c ; i++){
        if(strcmp(name,contacts[i].nom)==0){
            printf("tapez le nom que vous souhaitez : \n");
            scanf("%s",contacts[i].nom);
            printf("le nom est changer ! \n");
            printf("tapez le numero du telephone que vous souhaitez : \n");
            scanf("%s",contacts[i].num);
            printf("Le numero du telephone est changer ! \n");
            printf("tapez l'adresse email que vous souhaitez : \n");
            scanf("%s",contacts[i].email);
            printf("L'adresse email est changer ! ");

            }else {
            printf("le nom est ne disponible pas !\n" );
            }
        break;
    }
return;
}
//3. Supprimer un Contact
void Suppr_contact() {
    char Person[100];
    char confirmation[3];
    int suppr = 0;
    int i;
    int j;
    printf("Tapez le nom que vous souhaitez supprimer : ");
    scanf("%s", Person);
    for (i = 0; i < c; i++) {
        if (strcmp(Person, contacts[i].nom) == 0) {
            suppr = 1;
            break;
        }
    }

    if (suppr == 0) {
        printf("Le nom du contact n'a pas ete trouver ! \n");
    } else {
        printf("Etes vous sur de vouloir supprimer le contact '%s' ? (oui/non) : ", Person);
        scanf("%s", confirmation);

    if (strcmp(confirmation, "oui") == 0) {
        for (j = i; j < c - 1; j++) {
            strcpy(contacts[j].nom, contacts[j + 1].nom);
            strcpy(contacts[j].num, contacts[j + 1].num);
            strcpy(contacts[j].email, contacts[j + 1].email);
            }
            strcpy(contacts[c - 1].nom, "");
            strcpy(contacts[c - 1].num, "");
            strcpy(contacts[c - 1].email, "");

            c--;
            printf("Le contact a ete supprime ! \n");
        } else {
            printf("Suppression annulee.\n");
        }
    }
    return;
}
// 5 .rechercher un Contact :
void Recherch_Contact(){
    char rech[100];
    printf("ecrire le nom pour rechercher: ");
    scanf("%s",rech);

    int trouve = 0;


    for(int i = 0 ; i < c ; i++ ){
        if(strcmp(rech,contacts[i].nom)==0){
            printf("-----------------------------\n");
            printf("le contact est trouver : \n");
            printf("\nle nom de contact : %s \n" , contacts[i].nom);
            printf("le numero de telephone de contact : %s \n",contacts[i].num);
            printf("l'adress email de contact : %s \n",contacts[i].email);
            printf("-----------------------------\n");
            trouve = 1;
            break;
        }

    }
        if(trouve==0){
            printf("Aucun contact disponible avec ce nom ! \n");

        }

}
// 6 .tri(caming soon hh)
//void TriParInsertion(){
    //printf("les contact est tri par insertion \n");
    //for(int i = 1 ; i < c ; i++){
       // int tmp = contacts[c].nom;
       // int j = i - 1;
        //while(tmp < )
    //}
//}

int main() {
    //Contact contacts[MAX_CONTACT];
    //int max_contacts = 0;
    int choice;

    do {
        printf("\nMenu:====================\n");
        printf("1. Ajouter un contact \n");
        printf("2. Modifier un Contact \n");
        printf("3. Supprimer un Contact \n");
        printf("4. Afficher Tous les Contacts \n");
        printf("5. Rechercher un Contact \n");
        printf("6. Tri Par Insertion \n");
        printf("7. Quitter \n");
        printf("======================== \n");
        printf("Choisissez une option : ");
        scanf("%d", &choice);

    switch (choice) {
            case 1:
                addContact();
                break;
            case 2:
                Modifier_Contact();
                break;
            case 3:
                Suppr_contact();
                break;
            case 4:
                tous_Contacts();
                break;
            case 5:
                Recherch_Contact();
                break;
            case 6:
                //TriParInsertion();
                break;
            case 7:
                printf("end !\n");
                break;
            default:
                printf("Option invalide !\n");
                break;
        }
    } while (choice != 0);


    return 0;
}
