#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define ARCHIVO "Clientes.txt"
#define ARCHIVO1 "Prestamos.txt"

//	 Jhon Albert Guzman Rosario
//			2019-0430

typedef struct{
	
	float capital;
	int tiempo;
	
	float cuota;
	float Monto;
	float Abono;
	float Interes;
	float ApCapital;
	float Balance;
	
}Prestamos;

typedef struct{
	
	char Nombres[51];
	char Ciudad[25];
	char CalleyCasa[30];
	char Email[30];
	char Telefono[15];
	
}Clientes;

void Datos(Clientes *p);
void Presta(Prestamos *p);
char Menu();
float Cuota_S(int tiempo, float capital);
void Simple(Prestamos *p);
float Cuota_A(float capital, int tiempo);
void Amortizado(Prestamos *p);
void Escribir_Cliente(Clientes p);
void Leer_C(Clientes p);
void Leer_P(Prestamos p);

void main(){
	
	Clientes persona;
	Prestamos primer;
	char op;
	
	Datos(&persona);
	Escribir_Cliente(persona);
	
	Presta(&primer);
	
	system("cls");
	op = Menu();
	
	switch(op){
		
		case 's':
			
			Simple(&primer);
			
		break;
		
		case 'a':
			
			Amortizado(&primer);
			
		break;
		
	}
	
	system("cls");
	Leer_C(persona);
	Leer_P(primer);
	
	printf("\n\n\n");
	system("pause");
	
}

void Datos(Clientes *p){
	
	printf("\n\n\t-|PRESTAMOS|-\n");
	
	printf("\nIngrese su Nombre: ");
	gets(p->Nombres);
	
	printf("\nIngrese su Ciudad: ");
	fflush(stdin);
	gets(p->Ciudad);
	
	printf("\nIngrese su Calle y Numero de Casa: ");
	fflush(stdin);
	gets(p->CalleyCasa);
	
	printf("\nIngrese su Email: ");
	fflush(stdin);
	gets(p->Email);
	
	printf("\nIngrese su Telefono: ");
	fflush(stdin);
	gets(p->Telefono);
	
}

void Escribir_Cliente(Clientes p){
	
	FILE *a = fopen(ARCHIVO, "a");
	
	if (a == NULL)
		printf("\nNo se pudo abrir el archivo %s", ARCHIVO);
	else
		fprintf(a, "\n\nNombre: %s.\nCiudad: %s.\nCalle y Casa: %s.\nEmail: %s.\nTelefono: %s.\n", p.Nombres, p.Ciudad, p.CalleyCasa, p.Email, p.Telefono);
		
	fclose(a);
}

void Presta(Prestamos *p){
	 
	printf("\n\n\t-|PRESTAMOS|-\n");
	 
	do{
			
		printf("\nCuanto capital nesesita: ");
		scanf("%f", &p->capital);
				
	} while (p->capital <= 0);
			
	do{
				
		printf("\nCuantos meses va a pagar ( 1 - 36 ): ");
		scanf("%d", &p->tiempo);
				
	} while (p->tiempo <= 0 || p->tiempo > 36);
	
}

char Menu(){
	
	char opcion, Opcion;
	
	while(opcion != 's' && opcion != 'a' && opcion != 'S' && opcion != 'A'){
	
		printf("\n\n\t-|PRESTAMOS|-\n");
		
		printf("\n-Ingrese la letra de que tipo de prestamos quiere: \n");
		printf("\n-Simple Ingrese (S)");
		printf("\n-Amortizado Ingrese (A)\n");
		printf("\nOpcion: ");
		opcion = getche();
	}
	
	Opcion = tolower(opcion);
	
	return Opcion;	
}

float Cuota_S(int tiempo, float capital){
	
	float cuota, tasa;
	
	if (capital <= 10000)
		tasa = 0.06;
	else if(capital > 10001 && capital <= 20000)
		tasa = 0.055;
	else if(capital > 20001 && capital <= 30000)
		tasa = 0.05;
	else if(capital > 30001 && capital <= 40000)
		tasa = 0.045;
	else if(capital > 40001 && capital <= 80000)
		tasa = 0.04;
	else if(capital > 80001 && capital <= 150000)
		tasa = 0.038;
	else
		tasa = 0.034;

	cuota =  (capital * tasa) + (capital / tiempo);
 	
	return cuota;

}

void Simple(Prestamos *p){
	
	float capital; 
	int tiempo;
	float cuota;
	float tasa;
	
	int i;
	
	float *interes, *balance, *abono;

	if (p->capital <= 10000)
		tasa = 0.06;
	else if(p->capital > 10001 && p->capital <= 20000)
		tasa = 0.055;
	else if(p->capital > 20001 && p->capital <= 30000)
		tasa = 0.05;
	else if(p->capital > 30001 && p->capital <= 40000)
		tasa = 0.045;
	else if(p->capital > 40001 && p->capital <= 80000)
		tasa = 0.04;
	else if(p->capital > 80001 && p->capital <= 150000)
		tasa = 0.038;
	else
		tasa = 0.034;

	tiempo = p->tiempo;
	capital = p->capital;
	
	cuota = Cuota_S(tiempo, capital);

	while(abono == NULL || interes == NULL || balance == NULL){
		
		abono = (float *) malloc(tiempo * (sizeof(float)));
		interes = (float *) malloc(tiempo * (sizeof(float)));
		balance = (float *) malloc(tiempo * (sizeof(float)));
		
		if (abono == NULL || interes == NULL || balance == NULL)
			printf("\nNO SE PUDO RESERVAR LA MEMORIA SOLICIDATA...\n");
			
	}
	
	for (i = 0; i < tiempo; i++){

		p->Abono = (p->capital / p->tiempo);
		p->Interes = (p->capital * tasa);
		p->Balance = (p->capital - (p->Abono * (i + 1)));
		
		*(abono+i) = p->Abono;
		*(interes+i) = p->Interes;
		*(balance+i) = p->Balance;
		
	}

	FILE *a = fopen(ARCHIVO1, "a");
	
	if (a == NULL)
		printf("\nNo se pudo abrir el archivo %s", ARCHIVO1);
	else{

		fprintf(a,"\n\t-|PRESTAMO|-\n");
		fprintf(a,"===========================================================================");
		fprintf(a,"\nNumero \t    Capital \t    Interes \t    cuota \t    Balance\n");
		fprintf(a,"---------------------------------------------------------------------------");
	
		for(i = 0; i < tiempo; i++){
	
			*(abono+i);
			*(interes+i);
			*(balance+i);
			
			if(*(balance+i) < 0)
				*(balance+i) = 0;
						
			if(*(balance+i) < 1)
				*(balance+i) = 0;
		
			fprintf(a,"\n%3d \t %10.2f \t %10.2f \t %10.2f \t %10.2f", i + 1, abono[i], interes[i], cuota, balance[i]);
		}
				 	
		fprintf(a,"\n---------------------------------------------------------------------------");
		fprintf(a,"\n===========================================================================");
		
		fclose(a);		
	}
	 
	free(interes);
	free(abono);
	free(balance);
}

float Cuota_A(float capital, int tiempo){
	
	float cuota, tasa;
	
	if (capital <= 10000)
		tasa = 0.06;
	else if(capital > 10001 && capital <= 20000)
		tasa = 0.055;
	else if(capital > 20001 && capital <= 30000)
		tasa = 0.05;
	else if(capital > 30001 && capital <= 40000)
		tasa = 0.045;
	else if(capital > 40001 && capital <= 80000)
		tasa = 0.04;
	else if(capital > 80001 && capital <= 150000)
		tasa = 0.038;
	else
		tasa = 0.034;
	
	cuota = capital / (( 1 - pow(1 + tasa, -tiempo))  / tasa);
	
	return cuota;	

}

void Amortizado(Prestamos *p){
	
	float capital; 
	int tiempo;
	float cuota;
	float tasa;
	
	int i;
	
	float *monto, *interes, *apcapital, *balance;
	
	if (p->capital <= 10000)
		tasa = 0.06;
	else if(p->capital > 10001 && p->capital <= 20000)
		tasa = 0.055;
	else if(p->capital > 20001 && p->capital <= 30000)
		tasa = 0.05;
	else if(p->capital > 30001 && p->capital <= 40000)
		tasa = 0.045;
	else if(p->capital > 40001 && p->capital <= 80000)
		tasa = 0.04;
	else if(p->capital > 80001 && p->capital <= 150000)
		tasa = 0.038;
	else
		tasa = 0.034;
	
	tiempo = p->tiempo;
	capital = p->capital;
	
	cuota = Cuota_A(capital, tiempo);
	
	while(monto == NULL || interes == NULL || apcapital == NULL || balance == NULL){
		
		monto = (float *) malloc(tiempo * (sizeof(float)));
		interes = (float *) malloc(tiempo * (sizeof(float)));
		apcapital = (float *) malloc(tiempo * (sizeof(float)));
		balance = (float *) malloc(tiempo * (sizeof(float)));		
		
		if (monto == NULL || interes == NULL || apcapital == NULL || balance == NULL)
			printf("\nNO SE PUDO RESERVAR LA MEMORIA SOLICIDATA...\n");
			
	}
	
	p->Monto = p->capital;
	p->Interes = (p->Monto * tasa);
	p->ApCapital = cuota - p->Interes;
	p->Balance = p->Monto - p->ApCapital;
	
	i = 0;
	
	*(monto+i) = p->Monto;
	*(interes+i) = p->Interes;
	*(apcapital+i) = p->ApCapital;
	*(balance+i) = p->Balance;
	
	for(i = 1; i < tiempo; i++){
		
		p->Monto = p->Balance;
		p->Interes = (p->Monto * tasa);
		p->ApCapital = cuota - p->Interes;
		p->Balance = p->Monto - p->ApCapital;
		
		*(monto+i) = p->Monto;
		*(interes+i) = p->Interes;
		*(apcapital+i) = p->ApCapital;
		*(balance+i) = p->Balance;
		
		if(*(balance+i) < 0)
			*(balance+i) = 0;

		if(*(balance+i) < 1)
			*(balance+i) = 0;
			
	}	
	
	FILE *a = fopen(ARCHIVO1, "a");
	
	if (a == NULL)
		printf("\nNo se pudo abrir el archivo %s", ARCHIVO1);
	else{

		i = 0;
		fprintf(a,"\n\t-|PRESTAMO|-\n");

		fprintf(a,"\n===============================================================================");
		fprintf(a,"\nNumero \t    Monto \t    Interes \t    Ap. Capital \t    Balance\n");
		fprintf(a,"-------------------------------------------------------------------------------");
	
		fprintf(a,"\n%3d \t %10.2f \t %10.2f \t %10.2f \t\t %10.2f", 1, *(monto+i), *(interes+i), *(apcapital+i), *(balance+i));
	
		for(i = 1; i < tiempo; i++){
		
			*(monto+i);
			*(interes+i);
			*(apcapital+i);
			*(balance+i);
					
			if(*(balance+i) < 0)
				*(balance+i) = 0;
						
			if(*(balance+i) < 1)
				*(balance+i) = 0;
		
			fprintf(a,"\n%3d \t %10.2f \t %10.2f \t %10.2f \t\t %10.2f", i + 1, *(monto+i), *(interes+i), *(apcapital+i), *(balance+i));	
		}
		
		fprintf(a,"\n-------------------------------------------------------------------------------");
		fprintf(a,"\n===============================================================================");	
	
		fclose(a);
	
	}
	
	free(monto);
	free(interes);
	free(apcapital);
	free(balance);
		
}

void Leer_C(Clientes p){
	
	FILE *a;
	char e;
	
	printf("\n-------|Prestamos|-------\n");
	printf("\n\n-|Cliente|-");
	
	a = fopen(ARCHIVO,"r");
	
	if(a == NULL)
		printf("\nNo se pudo abrir el archivo %s", ARCHIVO);
	else{
		
		while(!feof(a)){
			e = fgetc(a);
			printf("%c", e);
		}
	}
	
	fclose(a);	

}

void Leer_P(Prestamos p){
	
	FILE *a;
	char e;
		
	a = fopen(ARCHIVO1,"r");
	
	if(a == NULL)
		printf("\nNo se pudo abrir el archivo %s", ARCHIVO);
	else{
		
		while(!feof(a)){
			e = fgetc(a);
			printf("%c", e);
		}
	}
	
	fclose(a);		
	
}
