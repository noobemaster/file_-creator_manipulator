#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char clean[]="",filename[50],extention[10]=".txt";
int Exit;
void file_txt(){strcat(filename,extention);}
void cleaner(char input[]){;
    char *p=strtok (input,"_"),*s;
    while (p!= NULL){
        strcat(clean,p);strcat(clean," ");
        p = strtok (NULL, "_");
    }
    s=clean;
    while ((s=strstr(s,"\\n"))!= NULL){
        *s++='\n';
        memmove(s,s+1,strlen(s));
    }
}
void read(){
    FILE *fp;
    char buff[250];
    fp = fopen(filename, "r");
    if(!fp){printf("\tfile does not exist!!!!\a\n");return;}
    fgets(buff, sizeof(buff) , fp);
    while(!feof(fp)){
        printf("\t%s", buff);
        fgets(buff, 250 , fp);
    }
    fclose(fp);
}
void write(){
    strcat(clean,"\n");
    FILE *fp;
    fp=fopen(filename, "w");
    fprintf(fp,"%s",clean);
    fclose(fp);
    strcpy(clean,"");

}
void append(){
    strcat(clean,"\n");
    FILE *fp;
    fp=fopen(filename, "a");
     if(!fp){printf("file does not exist!!!!\a\n");return;}
    fprintf(fp,clean);
    fclose(fp);
    strcpy(clean,"");

}
void exe(){
    printf("--Inside %s--\n",filename);
    int Choice;
    char doc[10000],name[20];
    printf("1.CREATE AND WRITE THE FILE\n2.READ THE FILE\n3.ADD TO THE FILE\n");
    printf("Choose action: ");scanf("%d",&Choice);
    switch(Choice){
        case 1:
            printf("|||To put a space between words use underscore(_) and to add new line use (\\n)|||\n\n");
            printf("\tEnter your data:\n\t");scanf("%s",&doc);
            cleaner(doc);write();
            break;
        case 2:
            printf("\topened %s\n\n",filename);
            read();
            break;
        case 3:
            printf("|||To put a space between words use underscore(_) and to add new line use (\\n)|||\n\n");
            printf("\tEnter your data:\n\t");scanf("%s",&doc);
            cleaner(doc);append();
            break;
        default:
            printf("\n\t!!!!!%d is out of range!!!!");exe();
    }
    printf("\t->to exit %s enter 0 ",filename);scanf("%d",&Exit);
    if(Exit==0)return;
    exe();
}
int main(){
    char name[200],edit,ext[12];
    printf("--------------WELCOME TO TERMINAL EDITOR-------------------------\n");
    printf("****The default file type is a text file(.txt)\n****The file will be stored where the source code was compiled\n");
    printf("****In this case it is in %s\n****Enter y to change these settings and N to continue: ",__FILE__);scanf("%s",&edit);
    if(edit=='y'){
        printf(" **Enter the full path of to the document including file name and extention e.g %s\n  ***Enter yours: ",__FILE__);scanf("%s",&filename);
        exe();
    }
    else{
        printf("    Name your file: ");scanf("%s",&filename);
        printf("    Enter an extention starting with a dot e.g .txt(to use default enter n): ");scanf("%s",&ext);
        if(strcmp(ext,"n"))strcpy(extention,ext);
        file_txt();
        exe();
    }
    printf("->to exit editor enter 0 ");scanf("%d",&Exit);
    if(Exit==0)return 0;
    main();
}
