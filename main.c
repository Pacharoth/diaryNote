#include <stdio.h>
#include <string.h>
#include "Menu1.h"
#include "processing1.h"

int main(){
    //declare variable 
    int choice;
    int choose;
    char buffer;
    char topic[100];
    char name;

loadfile();



    while(1){ 
        
        MenuDisplay();
        printf("Choice :");
        scanf("%d",&choice);
        
        if(choice==1){
            createDiary();
        }else if(choice ==2){
            showAllDiary();
            
        }else if(choice==3){
            showAllDiary();
            scanf("%c",&buffer);
           
            searchByTitle();
        }else if(choice==4){
            showAllDiary();
            choiceMenu();
            printf("Choose:");
            scanf("%d",&choose);
            if(choose==1){
                scanf("%c",&buffer);
            printf("Search Title:");
            scanf("%s",topic);
            updateTitle(topic);
            }else if(choose==2)
            {
                showAllDiary();
                scanf("%c",&buffer);
            printf("Search Title:");
            scanf("%s",topic);
            updateNote(topic);
            }
            

        }else if (choice==5)
        {
            anotherDate();
        }else if (choice==6)
        {
            showAllDiary();
            scanf("%c",&buffer);
            printf("Search Title:");
            scanf("%s",topic);
            deleteDiary(topic);
        }
        else if (choice==7){
           writeInFile();
            printf("Exit the porgram.\n");
            break;
        }
        
    }
    
}