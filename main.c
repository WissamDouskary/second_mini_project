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
    if( c >= MAX_CONTACT){
        printf("la liste de contacts est pleine !");
        return;
    }

    printf("ajouter ton nom :");
    scanf("%s",contacts[c].nom);
    printf("ajouter ton numero de telephone :");
    scanf("%s",contacts[c].num);
    printf("ajouter ton adresse email :");
    scanf("%s",contacts[c].email);
    c++;
}
// 4.afficher tous les contacts
void tous_Contacts(){
    if(c <= 0){
        printf("aucun contact disponible ! ");
    }
    else{
        printf("\n Les Contacts sont : \n");
        for(int i = 0 ; i < c; i++){
            printf("-----------------------------------");
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
    printf("tapez le nom que vous souhaitez supprimer : ");
    scanf("%s",Person);
    int suppr = 0;
    for (int i = 0 ; i < c ; i++){
        if(strcmp(Person,contacts[i].nom)==0)
            break;
    }
    if(suppr == 1){
        printf("le nom du contact n'a pas ete trouve ! \n");
    }else{
    for(int i = 0 ; i < c ;i++ ){
        strcpy(contacts[i].nom , contacts[i+1].nom);
        strcpy(contacts[i].num , contacts[i+1].num);
        strcpy(contacts[i].email , contacts[i+1].email);
        printf("le contact est supprimer ! \n");
        break;
    }


    }
    c--;
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
        printf("6. Quitter \n");
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
                printf("end !\n");
                break;
            default:
                printf("Option invalide !\n");
                break;
        }
    } while (choice != 0);


    return 0;
}
