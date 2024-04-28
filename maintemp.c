#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define pi 3.14


int main()
{
    //Exercice 3
/*double R1,R2,R3,R4,Req1,Req2;
printf("Donnez svp 4 valeurs de resistance.\n");
scanf("%lf %lf %lf %lf",&R1,&R2,&R3,&R4);
Req1=R1+R2+R3+R4;
Req2=((R1*R2*R3*R4)/(R2*R3*R4+R1*R3*R4+R2*R1*R4+R1*R2*R3));
printf("La resistance en serie est egale a %f\n",Req1);
printf("La resistance en parallele est egale a %f\n",Req2);
*/
    //Exercice 4
/*int B,b,h,aire;
printf("Donnez les valeurs des bases et de la hauteur respectivement\n");
scanf("%d %d %d",&B,&b,&h);
aire=((B+b)*h)/2;
printf("aire du trapeze est egale a %d\n",aire);
*/
/*int r,h,v;
printf("donnez la hauteur puis le rayon de cylindre\n");
scanf("%d %d",&h,&r);
v=(pi*h*pow(r,2));
printf("le volume du cylindre est %d",v);
*/
/*int R,H,V;
printf("donnez le rayon puis la hauteur du cone\n");
scanf("%d %d",&R,&H);
V=(pi*(H/3)*pow(R,2));
printf("le volume du cone est %d",V);
*/
   //Exercice 8
/*int u1=1,u2=1,un,n,i=1;
printf("donnez svp l'ordre de la suite\n");
scanf("%d",&n);
while (n<=0){
    printf("donnez l'ordre de la suite\n");
    scanf("%d",&n);
}
if(n==1)
    printf("le premier terme de Fibonacci est:u1=1\n");
else if(n==2)
printf("les deux premiers termes de la suite de Fibonacci sont:\n u1=1\n u2=1");
else{
    printf("u1=1 et u2=1");
    for(i=3;i<=n;i++){
     un=u1+u2;
     u1=u2;
     u2=un;
     printf("u%d=%d",i,un);
    }
}*/
   //Exercice 9
/*float note=0,moyenne=0;
int i=0;
while (note>=0){
  i++;
printf("Note%d:",i);
scanf("%f",&note);
if(note>=0){
    moyenne=moyenne+note;
}
}
 moyenne/=(i-1);
printf("la moyenne des %d notes est %.2f",i-1,moyenne);*/

   //Exercice 15
int n,i;
 do{
 printf("Donnez un chiffre 1<=n<=10\n");
 scanf("%d",&n);
}while(n<1 || n>10);
printf("Table de multiplication de %d:\n",n);
printf("\n");

for(i=1;i<=10;i++){
    printf("%d x %d= %d \n",n,i,n*i);
    printf("\n");
    }

   //Exercice 14
/*float H(int x){
return cos(x)+sin(x)-sqrt(x);
}
int x;
for(x=1;x<=100;x++){
    printf("x=%d\t h(x)=%f\n",x,H(x));
}*/

   //Exercice 12
/*double fact(int n){
double res;
for(res=1.0;n>=1;n--){
  res*=n;
}
return res;
}
int n;
printf("veuillez saisir un entier\n");
scanf("%d",&n);
printf("La factorielle de %d est %.0f",n,fact(n));*/


return 0;
}

