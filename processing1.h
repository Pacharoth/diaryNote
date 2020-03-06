#include <stdbool.h>
#include<time.h>
#include <string.h>
#include<stdlib.h>
#include <stdio.h>

// time_t t = time(NULL);
// struct tm tm = *localtime(&t);
struct date{
    int day,month,year;
};
struct Diary{
    char note[1500];
    char title[100];
    struct date dat;
};

struct Diary diary[100];
int n=0;
//create the diary note
//create loadfile

void loadfile(){

    int day,month,year;
  FILE *file;
    
    //display menu
    file=fopen("diary.txt","r");
    while (fscanf(file,"%s %d %d %d %s",diary[n].title,&diary[n].dat.day,&diary[n].dat.month,&diary[n].dat.year,diary[n].note)!=EOF)
        {
        n++;
    }   
}
void createDiary(){
    //declare variable
    struct Diary di;
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
  
    int day,month,year;
    char buffer;
    
    //processing 
    // FILE *file;
    scanf("%c",&buffer);
    printf("Title: ");
    scanf("%s",diary[n].title);
    printf("Note: ");
    scanf("%s",diary[n].note);
    diary[n].dat.day=tm.tm_mday;
    diary[n].dat.month=tm.tm_mon+1;
    diary[n].dat.year=tm.tm_year+1900;
    n=n+1;
           

    
}
//show all the information
void showAllDiary(){
    printf("\t\tNo|Title|Date|Note\n\n");
    for (int i = 0; i <n; i++)
    {
        //printf("%dTitle:%s \t\tDate:%d-%d-%d \nNote:\n%s\n",i+1,diary[i].title,diary[i].dat.day,diary[i].dat.month,diary[i].dat.year,diary[i].note);
        printf("%d|%s|%d-%d-%d|%s\n",i+1,diary[i].title,diary[i].dat.day,diary[i].dat.month,diary[i].dat.year,diary[i].note);

        // printf("Title:%s\nNote:\n%s\n",diary[i].title,diary[i].note);
    }
    
}
//search title
void searchByTitle(){
    int p=0;
    char topic[100];
     printf("Search Title:");
            scanf("%s",topic);
    for(int i=0;i<n;i++){
        printf("\t\tNo|Title|Date|Note\n\n");
       
        
        if(strcmp(diary[i].title,topic)==0){
           p=1; 
            //printf("%dTitle:%s \t\tDate:%d-%d-%d \nNote:\n%s\n",i+1,diary[i].title,diary[i].dat.day,diary[i].dat.month,diary[i].dat.year,diary[i].note);
        printf("%d|%s|%d-%d-%d|%s\n",i+1,diary[i].title,diary[i].dat.day,diary[i].dat.month,diary[i].dat.year,diary[i].note);

        }    
    }
    if (p==0)
    {
        printf("No result.\n");
    }
    
}
//search by date
void searchByDate(int day,int month,int year){

    for (int i = 0; i <n; i++)
    {
        if(diary[i].dat.day==day||diary[i].dat.month==month||diary[i].dat.year==year){
            //printf("Title:%s \t\tDate:%d-%d-%d \nNote:\n%s\n",diary[i].title,diary[i].dat.day,diary[i].dat.month,diary[i].dat.year,diary[i].note);
        printf("%d|%s|%d-%d-%d|%s\n",i+1,diary[i].title,diary[i].dat.day,diary[i].dat.month,diary[i].dat.year,diary[i].note);
            
        }
    }
    
}
//Update title
void updateTitle(char titl[100]){
    char chanTopic[100];
    char buffer;
    int f=0;
    
    for (int i = 0; i <n; i++)
    {
        if (strcmp(diary[i].title,titl)==0)
        {
           f=1; 
           
            printf("New Title:");
            scanf("%s",chanTopic);
            strcpy(diary[i].title,chanTopic);
        }
        
    }
    if(f==0){
        printf("Note not found!\n");
    }
    
}
//Update Note
void updateNote(char titl[100]){
    char chanNote[100];
    char buffer;
    int f=0;
     
    for (int i = 0; i <n; i++)
    {
        if (strcmp(diary[i].title,titl)==0)
        {
         
            printf("New Note:");
            scanf("%s",chanNote);
            strcpy(diary[i].note,chanNote);
        }
        
    }if(f==0){
        printf("Note not found!\n");
    }
    
    
}  
//Show all diary from date to another date
void showallDate(){
    for (int i = 0; i <n; i++){
        if(diary[i].dat.day)
       // printf("Title:%s \t\tDate:%d-%d-%d \nNote:\n%s\n",diary[i].title,diary[i].dat.day,diary[i].dat.month,diary[i].dat.year,diary[i].note);
        printf("%d|%s|%d-%d-%d|%s\n",i+1,diary[i].title,diary[i].dat.day,diary[i].dat.month,diary[i].dat.year,diary[i].note);
        
    }
}
struct abc
{
    char a[100],b[100],c[100];
};
struct abc abc[100];

//delete diary
void deleteDiary(char titl[100]){
    int f=0;
    
    for (int i = 0; i <n; i++)
    {



        if(strcmp(diary[i].title,titl)==0){
            f=1;
        strcpy(diary[i].title,"");
        strcpy(diary[i].note,"");
       

        printf("Note deleted.\n");
        }
    }
    if(f==0){
        printf("Cant found.\n");
    }
    
}
//write date
void anotherDate(){
    int f=0;
    int day,month,year;
    printf("\t\tChecking from create day to another day");
   printf("Enter another day month year by space:");

    scanf("%d %d %d",&day,&month,&year);
   for (int  i = 0; i < n; i++)
   {
       if (year>diary[i].dat.year)
       {
           f=0;
         printf("Title:%s \t\tDate:%d-%d-%d \nNote:\n%s\n",diary[i].title,diary[i].dat.day,diary[i].dat.month,diary[i].dat.year,diary[i].note);
       }else if (year==diary[i].dat.year)
       { 
           f=0;
           if (month>diary[i].dat.month)
           {
               f=0;
                printf("Title:%s \t\tDate:%d-%d-%d \nNote:\n%s\n",diary[i].title,diary[i].dat.day,diary[i].dat.month,diary[i].dat.year,diary[i].note);
           }else if (month==diary[i].dat.month)
           {
               f=0;
               if (day>=diary[i].dat.day)
               {
                   f=0;
                 printf("Title:%s \t\tDate:%d-%d-%d \nNote:\n%s\n",diary[i].title,diary[i].dat.day,diary[i].dat.month,diary[i].dat.year,diary[i].note);
               }else if(day<diary[i].dat.day)
               {    
                   f=1;
               }
           }else if(month<diary[i].dat.month)
           {
               f=1;
           }
           
       }else if(year<diary[i].dat.year)
       {
           f=1;
       }
       
       
   }
   if (f!=0)
   {
       printf("Empty.\n");
   }
   
     
   
}
//Write in file

void writeInFile(){
    FILE *file;
    file =fopen("diary.txt","w");
    for (int i = 0; i <n; i++)
    {
        if (strcmp(diary[i].title,"")==0&&strcmp(diary[i].note,"")==0)
        {
            fprintf(file,"%s %s",diary[i].title,diary[i].note);
        }else
        {
            fprintf(file,"%s %d %d %d %s\n",diary[i].title,diary[i].dat.day,diary[i].dat.month,diary[i].dat.year,diary[i].note);
        }
        
        
               
    }
    
}
void loadFILE(){

    char title[1000];
    char n1[100];
   char i;
   int p;
    char day[100],month[100],year[100];
  FILE *file;
    
    //display menu
    file=fopen("diary.txt","r");
   while(fgets(title,sizeof(title),file)!=NULL){
      for ( i = 0; i<strlen(title); i++)
      {
          day[i]=title[i];
        if (day[i]=='/')
        {
            break;

        }
      }
      printf("%s",day);

      for ( i = 0; i<strlen(title); i++)
      {
          n1[i]=title[i];
        if (n1[i]=='\n')
        {
            break;

        }
      }
      printf("%s",n1);

       for ( i = 0; i<strlen(title); i++)
      {
          n1[i]=title[i];
        if (n1[i]=='-')
        {
            break;

        }
      }
      printf("%s",n1);

       for ( i = 0; i<strlen(title); i++)
      {
          n1[i]=title[i];
        if (n1[i]=='*')
        {
            break;

        }
      }
      printf("%s",n1);

      for ( i = 0; i<strlen(title); i++)
      {
          n1[i]=title[i];
        if (n1[i]=='|')
        {
            break;

        }
      }
      printf("%s",n1);
        
        // for (int p = 0; p < strlen(title); i++)
        // {
        //     day[i]=title[i];
        // }
        // printf("%s",day);
        
   }
        

   
   
}