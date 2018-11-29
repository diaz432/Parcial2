
//programa creado por:CARLOS ADIEL DIAZ DELCID
//carnet:DD18003
//catedratico:LIGIA ASTRID HERNANDEZ

/* Hacer un programa que simule 
   01.Torres de hanoi.
   02.Generar una serie de numeros aleatorios y ordenarlos
      por el metodo de la burbuja.
   03.salir.
*/

#include<iostream>//importamos las librerias
#include <stdio.h>
#include <conio.h> //include getch
#include <stdlib.h>//incluye las funciones aleatorias, entre otras
#include <time.h>//incluye las funciones temporales
using namespace std;//importamos el espacio de nombre

//
//metodo para las generar las torres de hanoi
//

void Mover_Torres(int N, int Origen, int Intermedio, int Destino){ // Abre funcion Mover_Torres

if ( N > 1 ){ // Abre if
	Mover_Torres( N - 1, Origen, Destino, Intermedio);

	cout <<"\nMueve el disco " <<  N  << " de " << Origen << " a " <<  Destino << endl;
	Mover_Torres( N - 1, Intermedio, Origen, Destino);
} // Cierra if

// El caso limite mas sencillo se resuelve directamente

if ( 1 == N )
	cout << "\nMueve el disco 1 de " << Origen << " a " << Destino << endl;

} // Cierra funcion Mover_Torres


//
//metodos para generar el metodo de burbuja
//

//Declaro una matriz de 1000 numeros enteros
int numeros[1000];

 

//Declaro dos funciones para pensar y ordenar los n£meros
void pensarnumeros(void);

void ordenarnumeros(void);

void buscarmayormenor(void);


//declaro las variables para guardar la cantidad de numeros
int N,i,j;

 
void pensarnumeros(void){
int conta=0;

//funcion que inicializa las secuencias de los numeros aleatorios
srand((unsigned)time(NULL));

//imprimo un cambio de linea por pantalla
printf("\nCreados:\n");

//Los imprimo de 15 en 15
for(i=0;i<N;i++){
conta++;
numeros[i]=rand()/327;
printf(" %d ",numeros[i]);

//Cuando al hacer la division entre 15 me da de resto 0 pongo un cambio de linea
if(conta % 15 == 0)printf("\n");

}

 

}

void ordenarnumeros(void){

//Ordeno los numeros de menor a mayor
int j,k,t,conta=0;

for(j=1;j<N;j++)
	 for(k=0;k<N-1;k++){
		  if(numeros[k+1]<numeros[k]){

			  t=numeros[k];
			
			  numeros[k]=numeros[k+1];
			
			  numeros[k+1]=t;

  			}

 		}

 printf("\nOrdenados:\n");

for(i=0;i<N;i++){
	conta++;
	printf(" %d ",numeros[i]);

	if(conta % 15 == 0)printf("\n");

}

}

 

void buscarmayormenor(){ 
int mayor,menor;

mayor=numeros[0];
menor=numeros[0];

for(i=0;i<N;i++){

      if(mayor<numeros[i])mayor=numeros[i];

      if(menor>numeros[i])menor=numeros[i];

}

printf("\n El numero menor generado es %d y el mayor es %d. ",menor,mayor);

}


int o = 0;
int main(){//iniciamos la clase principal

	do{
	
	int op = 0, c = 0;//declaramos las variables a utilizar
	cout<<"Menu\n1- Juego de torres de hanoi.\n2- Generar 100 numeros aleatorios por el metodo de la burbuja.\n3- Salir."<<endl;//imprimimos en pantalla las opciones del menu
	cin>>op;//el dato que se ingresa se guarda en la variable op
	
	if(op < 0 || op >3){//comparamos el dato dela variable op para saber si esta entre las opciones del menu
		cout<<":::ERROR:::\nPor favor ingrese una opcion valida"<<endl;//imprimimos en pantalla si no esta entre el menu
		cin>>op;//ingresamos el otra vez el dato si esta erroneo
	}	
	
	switch(op){//creamos un switch para que recorra por las opciones del menu	
		case 1:
			
			int Discos;
			cout << "\nEste programa resuelve el problema clasico de las Torres de Hanoi";
			cout <<" mediante la recursion." << endl;
			cout << "\nPor favor introduzca el numero de discos que quiere mover ";
			cout << " de la pila 1 a la pila 3" << endl;
			cin >> Discos;

			Mover_Torres( Discos, 1, 2, 3);

			cout << endl << endl;
			
			
			break;
		
		case 2:
			printf("\n***************************************************");

			printf("\n* Programa que crea y ordena N n£meros aleatorios *");

			printf("\n***************************************************");

			printf("\n\n ¨Cuantos n£meros desea crear aleatoriamente? (max 1000) N=");

			//scaneo la entrada del usuario

			scanf("%d",&N);

			//Llamo a la instruccion que piensa los numeros

			pensarnumeros();

			ordenarnumeros();

			buscarmayormenor();

			//Instruccion que mantiene la ventana abierta hasta que pulsas una tecla

			getch();
			cout<<endl<<endl;
			break;
			
		case 3:
			cout<<"¿Seguro que desea salir? 1- Si 2- No"<<endl;
			cin>>c;
			if(c == 2){
				cout<<"Menu\n1- Juego de torres de hanoi.\n2- Generar 100 numeros aleatorios por el metodo de la burbuja.\n3- Salir."<<endl;
				cin>>op;
			}else{
				system("pause");
			}
			break;
	}
	
	cout<<"¿Desea ejecutar otra vez el menu? 1- Si, 2- No"<<endl;
	cin>>o;
}while(o == 1);
		
	return 0;	
}
	
