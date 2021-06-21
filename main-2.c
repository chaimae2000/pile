//
//  main.c
//  devoir-chaimae-manal
//
//  Created by mac on 3/26/21.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 20
/*initialiser la pile empile depile sommet estplein
* l'empile et la depile
* ceer la la fonction sommet et la fct estplein
 */
typedef struct {
    char T[MAX];
    int sommet;
}*Pile;

Pile init(){
    Pile P=(Pile) malloc(MAX);
    P->sommet=-1;
    return P;
}

int EstPlein(Pile P)
{
    if (P->sommet==MAX-1) {
    return 1;}
    return 0;
}

int EstVide(Pile P)
{
    if (P->sommet==-1) {
    return 1;}
    return 0;
}

void empiler(Pile P,int e){
    if (EstPlein(P)==1) printf("Pile pleine\n");
    else {P->T[++P->sommet] = e;}
}

void depiler(Pile P){
    if (P->sommet==-1) printf("Pile vide\n");
    else {
        P->sommet--;
    }
}

char  Sommet(Pile P){
if(P->sommet==-1)
{return 1;}
else return P->T[P->sommet];
}

Pile consp(char C[]){
    Pile P=init();
    int s=-1;
    long N=strlen(C), i;
    for (i=0;i<N;i++){
        if (C[i]<='9' && C[i]>='0') empiler(P,C[i]-'0');
        else if (C[i]==')') {empiler(P,s);s=0;}
        else if (C[i]=='+') s=-1;
        else if (C[i]=='-') s=-2;
        else if (C[i]=='*') s=-3;
        else if (C[i]=='/') s=-4;
        
    }
    if (s!=0) empiler(P,s);
    Pile invP=init();
    while(!EstVide(P)){
        int a=Sommet (P);
        depiler(P);
        empiler(invP,a);
    }
    return invP;

}

int eval(Pile P){
        int s=Sommet(P),v=-1;
    depiler(P);
    while(!EstVide(P)){
        int a=Sommet (P);
        depiler(P);
        if (v<0) v=a;
        else {
             if (a==-1) s+=v;
             if (a==-2) s-=v;
             if (a==-3) s*=v;
             if (a==-4) s/=v;
             v=-1;
        }
    }
    return s;
}


int main ()
{    Pile P=init();
    char E[]="((7+2)*3)";
    printf ("Calculer : ");
    puts(E);
    P=consp(E);    printf("\n");
    printf("\tresultat= %d\n\n",eval(P));
                                 
    
    char R[]="(6*4)+1";
    printf ("Calculer : ");
    puts(R);
    P=consp(R);    printf("\n");
    printf("\tresultat= %d\n",eval(P));
    
    
    
}
