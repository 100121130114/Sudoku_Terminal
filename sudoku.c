#include <stdio.h>
#include <stdlib.h>
#include "libloc.h"
#include <stdbool.h>
#include <time.h>

int main(){
 srand(time(NULL));
 //var conf
 int tbm=16;
 int tbmr=0;
 bool mas[tbm*tbm];
 char cp[6]={' ','|','-','.','M','M'};
 int pm=500;
 //var save
 int res[tbm*tbm];
 int map[tbm*tbm];
 int seedb[tbm*tbm];
 bool usn[tbm][tbm+tbm+(int)(tbm*tbm/tbm)];
 //redefine the vars
 #define use(c,a,b) usn[c][a*tbm+b]
 #define maps(a,b) map[a*tbm+b]
 #define masc(a,b) mas[a*tbm+b]
 #define resu(a,b) res[a*tbm+b]
 #define seed(a,b) seedb[a*tbm+b]

 //first conf
 unsigned int tbmr2[3];
 rcpf(tbmr2,(float)tbm,2,0,0,2);
 tbmr=tbmr2[0]/tbmr2[2];
 printf("%d\n",tbmr);
 for(int a=0;a<tbm;a++){
  for(int b=0;b<tbm+tbm+(int)(tbm*tbm/tbm);b++){
   usn[a][b]=0;
  }
 }
 for(int a=0;a<tbm*tbm;a++){
  map[a]=0;
  res[a]=0;
  int b=rand()%1000;
  if(b<pm){
   mas[a]=1;
  }else{
   mas[a]=0;
  }
  seedb[a]=(int)(rand()%tbm);
 }
 printf("Generando mapa!\n");
 //generait the map of sudoku
 int ss=0;
 for(int long z=0;true;z++){
  //generait
  for(int a=0;a<tbm;a++){
   for(int b=0;b<tbm;b++){
    int d=0;
    //#define e (int)((a/rcpf_d(tbm,2,0,0,0))*rcpf_d(tbm,2,0,0,0)+(b/rcpf_d(tbm,2,0,0,0)))
    #define e (int)((a/tbmr)*tbmr+(int)(b/tbmr))
    for(int c=0;c<tbm;c++){
     if(((!(use(c,0,a)))&&(!(use(c,1,b))))&&(!(use(c,2,e)))){
      maps(a,b)=c+1;
      if(d>=seed(a,b)){
       break;
      }
      d++;
     }
    }
    use(maps(a,b)-1,0,a)=1;
    use(maps(a,b)-1,1,b)=1;
    use(maps(a,b)-1,2,e)=1;
   }
  }
  /*
  //print
  for(int a=0;a<tbm;a++){
   for(int b=0;b<tbm;b++){
    printf("%d",maps(a,b));
   }
   printf("\n");
  }
  printf("\n");*/
  //verificacion
  bool det=0;
  for(int a=0;a<tbm*tbm;a++){
   if(map[a]==0){det=1;break;}
  }
  if(!(det)){
   break;
  }else{
   for(int a=0;a<tbm;a++){
    for(int b=0;b<tbm+tbm+(int)(tbm*tbm/tbm);b++){
     usn[a][b]=0;
    }
   }
   for(int a=0;a<tbm*tbm;a++){
    map[a]=0;
    seedb[a]=(int)(rand()%tbm);
   }
  }
  ss++;
 }
 
 printf("Mapa generado!. Nivel N*%d\n",pm);
 while(true){
  //print resultado
  for(int b=0;b<tbm+tbm+1;b++){
   if((bool)((tbm+tbm+1)%2) ? b==(int)((tbm+tbm+1)/2) : (b>=(int)((tbm+tbm+1)/2)-1)&&(b<=(int)((tbm+tbm+1)/2))){
    printf("%c",cp[5]);
   }else{
    printf("%c",cp[2]);
   }
  }
  printf("\n");
  for(int a=0;a<tbm;a++){
   if(((bool)(tbm%2) ? a==(int)(tbm/2) : (a>=(int)(tbm/2)-1)&&(a<=(int)(tbm/2)))){
    printf("%c",cp[4]);
   }else{
    printf("%c",cp[1]);
   }
   for(int b=0;b<tbm;b++){
    if(masc(a,b)){
     printf("%d",maps(a,b));
    }else{
     if(resu(a,b)>0){
      printf("%d",resu(a,b));
     }else{
      printf("%c",cp[0]);
     }
     }
     if(((bool)(tbm%2) ? a==(int)(tbm/2) : (a>=(int)(tbm/2)-1)&&(a<=(int)(tbm/2)))&&(b==tbm-1)){
      printf("%c",cp[4]);
     }else{
      printf("%c",cp[1]);
     }
    }
    printf("\n");
   }
   for(int b=0;b<tbm+tbm+1;b++){
    if((bool)((tbm+tbm+1)%2) ? b==(int)((tbm+tbm+1)/2) : (b>=(int)((tbm+tbm+1)/2)-1)&&(b<=(int)((tbm+tbm+1)/2))){
     printf("%c",cp[5]);
    }else{
     printf("%c",cp[2]);
    }
   }
  printf("\n");
  int sa[2]={0,0};
  int pa=0;
  scanf("%d %d %d",&sa[0],&sa[1],&pa);
  sa[0]--;sa[1]--;
  if((pa>0)&&(pa<=tbm)){
   if(!(masc(sa[0],sa[1]))){
    resu(sa[0],sa[1])=pa;
    printf("%d->%d:%d\n",pa,sa[0]+1,sa[1]+1);
   }else{
    printf("Error: No puedes escribir hai.\n");
   }
  }else{
   switch(pa){
    case 333:{
     int ce=0,coi=0,tco=0;
     for(int a=0;a<tbm*tbm;a++){
      if(!(mas[a])){
       if(map[a]==res[a]){
        coi++;
       }
       if(res[a]!=0){
        ce++;
       }
       tco++;
      }
     }
     if(coi==tco){
      printf("Ganaste!\n");
      return 0;
     }else{
      printf("No esta del todo bien.[%d/%d M%d]\n",coi,ce,tco);
     for(int b=0;b<tbm+tbm+1;b++){
      printf("%c",cp[2]);
     }
     printf("\n");
     for(int a=0;a<tbm;a++){
      printf("%c",cp[1]);
      for(int b=0;b<tbm;b++){
       if(masc(a,b)){
        printf("%c",cp[3]);
       }else{
        if(resu(a,b)>0){
         printf("%d",resu(a,b));
         }else{
          printf("%c",cp[0]);
         }
        }
        printf("%c",cp[1]);
       }
       printf("\n");
      }
      for(int b=0;b<tbm+tbm+1;b++){
       printf("%c",cp[2]);
      }
     printf("\n");
     }
    }break;
    case 666:{
     printf("EXIT\n");
     for(int b=0;b<tbm+tbm+1;b++){
      printf("%c",cp[2]);
     }
     printf("\n");
     for(int a=0;a<tbm;a++){
      printf("%c",cp[1]);
      for(int b=0;b<tbm;b++){
       if(masc(a,b)){
        printf("%c",cp[3]);
       }else{
        printf("%d",maps(a,b));
       }
       printf("%c",cp[1]);
      }
      printf("\n");
     }
     for(int b=0;b<tbm+tbm+1;b++){
      printf("%c",cp[2]);
     }
     printf("\n");
     return 0;
    }break;
    default:{
     printf("Error: Numero incorrecto.\n");
    }break;
   };
  }
 }
 return 0;
}
