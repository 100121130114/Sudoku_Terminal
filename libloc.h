#include <stdbool.h>

int long elvl(int long numero_base, int long numero_elevar){//ElEvAr
					    //numero_base:numero que se multiplica sobre si mismo; numero_elevar:con el que se eleva; (numero_base^numero elevar)
 int long resultado=1;
 for(int long a=0;a<numero_elevar;a++){
  resultado*=numero_base;
 }
 return resultado;
}

unsigned int elvu(unsigned int numero_base,unsigned int numero_elevar){//ElEvAr
					    //numero_base:numero que se multiplica sobre si mismo; numero_elevar:con el que se eleva; (numero_base^numero elevar)
 unsigned int resultado=1;
 for(unsigned int a=0;a<numero_elevar;a++){
  resultado*=numero_base;
 }
 return resultado;
}

float elvf(float numero_base, int long numero_elevar){//ElEvAr
					    //numero_base:numero que se multiplica sobre si mismo; numero_elevar:con el que se eleva; (numero_base^numero elevar)
 float resultado=1;
 for(int long a=0;a<numero_elevar;a++){
  resultado*=numero_base;
 }
 return resultado;
}

int ces(int numb,int pi,int pf,char* numd){
 int numc=0;
 for(int long a=pf-1,b=0;a>=pi;a--){
  if(numd[a]>=0&&(numd[a-pi]<numb)){
   numc+=elvl(numb,pf-1-a+pi-b)*numd[a-pi];
  }else{
   b+=1;
  }
 }
 return numc;
}

unsigned int dco(unsigned int a){
 unsigned int b=0;
 for(int c=0;true;c++){
  if(a%elvu(10,c)!=0){b=c;break;}
 }
 b--;
 b=a/elvu(10,b);
 return b;
}

unsigned int dcon(unsigned int a){
 unsigned int b=0;
 for(int c=0;true;c++){
  if(a%elvu(10,c)!=0){b=c;break;}
 }
 b--;
 return b;
}

int rc(int num){
 int res=0;
 if(num==0){res=0;}
 if(num==1){res=1;}
 if(num==4){res=2;}
 if(num==9){res=3;}
 if(num==16){res=4;}
 if(num==25){res=5;}
 if(num==36){res=6;}
 if(num==49){res=7;}
 if(num==64){res=8;}
 if(num==81){res=9;}
 if(num==100){res=10;}
 return res;
}

bool rcpu(unsigned int* rcp,float b,unsigned int n,float d,float e,unsigned int npre){
 unsigned int puf=elvu(10,npre);
 unsigned int num=b*puf,ri=d*puf ,rf=e*puf;
 bool tr=0;
 for(unsigned int a=(d==0 ? 0 : ri);d==0 ? 0==0 : a<rf;a++){
  #define cmp elvu(a,n)
  printf("%u#%u\n",cmp,num);
  if((cmp==num)&&(npre-dcon(a)==elvu(puf,n))){rcp[0]=a;tr=1;break;}
  if(cmp<num){rcp[0]=a;}
  if(cmp>num){rcp[1]=a;tr=0;break;}
 }
 printf("RCP[%u->%u]\n",rcp[0],rcp[1]);
 rcp[2]=puf;
 return tr;
}

bool rcpf(unsigned int* rcp,float b,unsigned int n,float d,float e,unsigned int npre){
 unsigned int puf=elvu(10,npre);
 unsigned int num=b*puf,ri=d*puf ,rf=e*puf;
 bool tr=0;
 for(unsigned int a=(d==0 ? 0 : ri);d==0 ? 0==0 : a<rf;a++){
  if(elvf((float)a/puf,n)==b){rcp[0]=a;tr=1;break;}
  if(elvf((float)a/puf,n)<b){rcp[0]=a;}
  if(elvf((float)a/puf,n)>b){rcp[1]=a;tr=0;break;}
 }
 rcp[2]=puf;
 return tr;
}

float rcpf_d(float b,unsigned int n,float d,float e,unsigned int npre){
 unsigned int rcp[3];
 unsigned int puf=elvu(10,npre);
 unsigned int num=b*puf,ri=d*puf ,rf=e*puf;
 bool tr=0;
 for(unsigned int a=(d==0 ? 0 : ri);d==0 ? 0==0 : a<rf;a++){
  if(elvf((float)a/puf,n)==b){rcp[0]=a;tr=1;break;}
  if(elvf((float)a/puf,n)<b){rcp[0]=a;}
  if(elvf((float)a/puf,n)>b){rcp[1]=a;tr=0;break;}
 }
 rcp[2]=puf;
 return (float)rcp[0]/puf;
}
