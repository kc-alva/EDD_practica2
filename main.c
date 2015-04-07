#include <stdio.h>   /* required for file operations */
#include <conio.h>  /* for clrscr */
#include <dos.h>  /* for delay */
#include <stdlib.h>
#include <sys\timeb.h>




FILE *fr;            /* declare the file pointer */

typedef struct node
{  int data;
struct node *left,*right;
int ht;
}node;


typedef struct listNode
{
    int info;
    struct listNode *nextN;
}listNode;

node *insert(node *,int);
node *Delete(node *,int);
void  preorder(node *);
void  inorder(node *);
void display(node *, int);
int   height( node *);
node *rotateright(node *);
node *rotateleft(node *);
node *RR(node *);
node *LL(node *);
node *LR(node *);
node *RL(node *);
int BF(node *);
float tOrdenArbol=0;
float tOrdenQuick=0;
float tOrdenArreglo=0;
int cosa=0;


main()
{
    node *root=NULL;
    int x,n,i,op;

   int entrada;
   char line[10];
   float tiemposArregloArr[3];
    int contadorElements = 0;
    char pathx[30];

    printf("ingrese el nombre del archivo en el escritorio: \n");
    scanf("%c",&pathx);


   fr = fopen ("C:\\Users\\Cris\\Desktop\\pruebaText.txt","rt");  /* open the file for reading */



    // PARA INGRESAR NODOS AL ARBOL
    struct timeb start, end;
    int diff;
    ftime(&start);

   while(fgets(line, 10, fr) != NULL)
   {
	 sscanf (line, "%d", &entrada);
	 /* convert the string to int */
	 root=insert(root,entrada);




	 printf ("%d\n", entrada);

	 /*entrada aqui va a tener el valor de la linea que quiero meter al arbol*/

   }

   fclose(fr);  /* close the file */
     ftime(&end);
    diff = (int) (1000.0 * (end.time - start.time)
        + (end.millitm - start.millitm));
    tOrdenArbol = (((float)diff)/1000);
   printf("\nOperation took %u milliseconds\n", diff);
   printf("\n tordenarbol %f milliseconds\n", tOrdenArbol);

   contadorElements = contador(root);
   printf("numero de elementos %d \n",contadorElements);
    cosa = contadorElements;


//PARA INGRESAR NODOS AL ARREGLO
int arreglito[cosa];
int quickArr[cosa];
int piv = 0;

fr = fopen ("C:\\Users\\Cris\\Desktop\\pruebaText.txt","rt");

while(fgets(line, 10, fr) != NULL)
   {
	 sscanf (line, "%d", &entrada);
	 /* convert the string to int */
    arreglito[piv]=entrada;
    quickArr[piv]=entrada;
    piv++;

	 printf ("\n%d entra al arreglo", entrada);

	 /*entrada aqui va a tener el valor de la linea que quiero meter al arbol*/

   }

   fclose(fr);  /* close the file */


//AQUI ORDENO EL ARRAY
int tempz, swappedz;
int ii;

int varz;

for(varz = 0;varz<3;varz++){

ftime(&start);
    while(1){

        swappedz = 0;

        for(ii=0;ii<contadorElements;ii++)
        {
            if(arreglito[ii]>arreglito[ii+1]){
               int tempz = arreglito[ii];
                arreglito[ii]=arreglito[ii+1];
                arreglito[ii+1]=tempz;
                swappedz=1;
            }

        }

        if(swappedz==0){
            break;
        }
    }


        for(ii=0;ii<contadorElements;ii++)
        {
            printf("\n array en pos %d = ",ii);
            printf(" %d\n",arreglito[ii]);

        }

ftime(&end);
    diff = (int) (1000.0 * (end.time - start.time)
        + (end.millitm - start.millitm));
    tOrdenArreglo = (((float)diff)/1000);
   printf("\nOperation took %u \n", diff);
   printf("\n tArreglo %f \n", tOrdenArreglo);
    tiemposArregloArr[varz] = tOrdenArreglo;

}







printf("\n \n SALIDA ORDENADA DE BURBUJA:\n");
for(ii=0;ii<=cosa;ii++)
        {

            printf(" %d",arreglito[ii]);

        }
        printf("\n en tiempo: %f \n",tOrdenArreglo);




/* ******************************************orden quicksort */


ftime(&start);
quicksort(quickArr,0,cosa-1);



printf("\n \n \n SALIDA ORDENADA DE QUICKSORT \n");
  for(i=0;i<cosa;i++){
    printf(" %d",quickArr[i]);
  }

  ftime(&end);
    diff = (int) (1000.0 * (end.time - start.time)
        + (end.millitm - start.millitm));
    tOrdenQuick= (((float)diff)/1000);
   printf("\n quicksort en tiempo de: %f \n", tOrdenQuick);










printf("\n \nSALIDA ORDENADA DEL ARBOL:\n");
inorder(root);
printf("\n en tiempo: %f ",tOrdenArbol);


printf("\n \n Tiempos para graficar: ");
for(varz = 0; varz<3;varz++)
    {
    printf("\n tiempo %d = %f \n",varz,tiemposArregloArr[varz] );
}



FILE *archiv;
archiv = fopen("C:/Users/Cris/Desktop/archivoGA.txt","w");
int yz;



for(yz =0;yz<3;yz++){
fprintf(archiv,"%f\t%d\n",tiemposArregloArr[yz],yz);
}
fclose(archiv);



FILE *gnuplotPipeM = popen("gnuplot -persists","w");
    if(gnuplotPipeM){
        fprintf(gnuplotPipeM,"set style data lines\n");
        fprintf(gnuplotPipeM,"set title 'Grafica de ordenamiento' title 'caso a'\n");
        fprintf(gnuplotPipeM,"plot [:][:0,000008]'C:/Users/Cris/Desktop/archivoGA.txt' title 'Caso a'\n");
        fflush(gnuplotPipeM);
        getchar();
        fprintf(gnuplotPipeM,"exit \n");
        pclose(gnuplotPipeM);
    }








     do
                              {
                                             /*printf("\n0)Create:");
                                             printf("\n4)Insert:");
                                             printf("\n3)Delete:");*/

                                             printf("\n1)Print:");
                                             printf("\n2)Quit:");
                                             printf("\n\nEnter Your Choice:");
                                             scanf("%d",&op);
                                             switch(op)
                                                 {


                                                            case 4:printf("\nEnter a data:");
                                                            scanf("%d",&x);
                                                            root=insert(root,x);
                                                            break;
                                                            case 3:printf("\nEnter a data:");
                                                            scanf("%d",&x);
                                                            root=Delete(root,x);
                                                            break;
                                                            case 1:  printf("\nSalida ordenada del arbol:\n");
                                                                          ftime(&start);

                                                                           inorder(root);
                                                                           printf("\n\nARBOLITO:\n");
                                                                           display(root,0);
                                                                           //printf("fff %d",contador(root));
                                                                           ftime(&end);
    diff = (int) (1000.0 * (end.time - start.time)
        + (end.millitm - start.millitm));

    printf("\nEl recorrido del arbol tomo %u millisegundos\n", diff);


                                                                           printf("\n");
                                                                           break;

                                                  }


               }while(op!=2);

return 0;


} /*of main*/



node * insert(node *T,int x)
{
               if(T==NULL)
               {
                              T=(node*)malloc(sizeof(node));
                              T->data=x;
                              T->left=NULL;
                              T->right=NULL;
               }
               else
                              if(x > T->data)                // insert in right subtree
                              {
                                             T->right=insert(T->right,x);
                                             if(BF(T)==-2)
                                                            if(x>T->right->data)
                                                                           T=RR(T);
                                                            else
                                                                           T=RL(T);
                              }
                              else
                                             if(x<T->data)
                                             {
                                                            T->left=insert(T->left,x);
                                                            if(BF(T)==2)
                                                                           if(x < T->left->data)
                                                                                          T=LL(T);
                                                                           else
                                                                                          T=LR(T);
                                             }
                                             T->ht=height(T);

                                             return(T);

}

node * Delete(node *T,int x)
{       node *p;

               if(T==NULL)
               {
                              return NULL;
               }
               else

                              if(x > T->data)                // insert in right subtree
                              {
                                             T->right=Delete(T->right,x);
                                             if(BF(T)==2)
                                                            if(BF(T->left)>=0)
                                                                           T=LL(T);
                                                            else
                                                                           T=LR(T);
                              }
                              else
                                             if(x<T->data)
                                                            {
                                                                           T->left=Delete(T->left,x);
                                                                           if(BF(T)==-2)//Rebalance during windup
                                                                                          if(BF(T->right)<=0)
                                                                                                         T=RR(T);
                                                                                          else
                                                                                                         T=RL(T);
                                                            }
                                             else
                                               {
                                                 //data to be deleted is found
                                             if(T->right !=NULL)
                                                            {  //delete its inordersuccesor
                                                                  p=T->right;
                                                            while(p->left != NULL)
                                                                             p=p->left;

                                                                  T->data=p->data;
                                                                  T->right=Delete(T->right,p->data);
                                                            if(BF(T)==2)//Rebalance during windup
                                                                                          if(BF(T->left)>=0)
                                                                                                         T=LL(T);
                                                                                          else
                                                                                                         T=LR(T);
                                                               }
                                             else
                                                            return(T->left);

                                               }
               T->ht=height(T);
               return(T);
}

int height(node *T)
{
               int lh,rh;
               if(T==NULL)
                              return(0);
               if(T->left==NULL)
                              lh=0;
               else
                              lh=1+T->left->ht;
               if(T->right==NULL)
                              rh=0;
               else
                              rh=1+T->right->ht;
               if(lh>rh)
                              return(lh);
               return(rh);
}
node * rotateright(node *x)
{
               node *y;
               y=x->left;
               x->left=y->right;
               y->right=x;
               x->ht=height(x);
               y->ht=height(y);
               return(y);
}
node * rotateleft(node *x)
{
               node *y;
               y=x->right;
               x->right=y->left;
               y->left=x;
               x->ht=height(x);
               y->ht=height(y);
               return(y);
}
node * RR(node *T)
{
               T=rotateleft(T);
               return(T);
}
node * LL(node *T)
{
               T=rotateright(T);
               return(T);
}
node * LR(node *T)
{
               T->left=rotateleft(T->left);
               T=rotateright(T);
               return(T);
}
node * RL(node *T)
{
               T->right=rotateright(T->right);
               T=rotateleft(T);
               return(T);
}
int BF(node *T)
{
               int lh,rh;
               if(T==NULL)
               return(0);
               if(T->left==NULL)
                              lh=0;
               else
                              lh=1+T->left->ht;
               if(T->right==NULL)
                              rh=0;
               else
                              rh=1+T->right->ht;
               return(lh-rh);
}
void preorder(node *T)
{
               if(T!=NULL)
               {
                              printf("%d(Bf=%d) ",T->data,BF(T));
                              preorder(T->left);
                              preorder(T->right);
               }
}

void inorder(node *T)
{
               if(T!=NULL)
               {
                              inorder(T->left);
                              printf("%d ",T->data,BF(T));
                              inorder(T->right);
               }

}

void display(node *T,int level){
    if(T->right != NULL){
        display(T->right, level+1);
        printf("%*s \n",level*6 ,"  /");
    }

    printf("%*d \n",level*6 ,T->data);

    if(T->left != NULL){
    printf("%*s \n",level*6 ,"  \\");
    display(T->left, level+1);
    }

}

int contador(node *T){
    int cont = 0;
    if(T->right != NULL)
        cont += contador(T->right);
    if(T->left != NULL)
        cont += contador(T->left);
    cont ++;
    return cont;

}



void quicksort(int x[cosa],int first,int last){
    int pivot,j,temp,i;

     if(first<last){
         pivot=first;
         i=first;
         j=last;

         while(i<j){
             while(x[i]<=x[pivot]&&i<last)
                 i++;
             while(x[j]>x[pivot])
                 j--;
             if(i<j){
                 temp=x[i];
                  x[i]=x[j];
                  x[j]=temp;
             }
         }

         temp=x[pivot];
         x[pivot]=x[j];
         x[j]=temp;
         quicksort(x,first,j-1);
         quicksort(x,j+1,last);

    }
}


