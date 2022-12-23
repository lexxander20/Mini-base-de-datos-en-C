// BLOQUE DEL PROGRAMADOR

/* Nombre del programador: Josue Alexander Llanos De Luna
Nombre del programa: Base de datos
Fecha de inicio: 24 de Noviembre del 2021
Descripción del programa: Este programa crea una base de datos para registrar refrescos y proveedores. */

// Libreráas empleadas 

# include <stdio.h> // Procesos básicos
# include <conio.h> // Función getch ()
// # include <clocale> // Idioma español
# include <windows.h> // Pantallas
# include "mar.h" // Documento externo donde se encuentran las funciones de los marcos

# define correcto 1234 // Definición de la contraseña correcta

struct base { // Definición de estructuras anidadas
	
	struct ventas {
	
	char nombre_refresco [50], presentacion [20], volumen [10], color [15], sabor [25];
	char precio_al_publico [15], precio_al_proveedor [15];
	char observaciones [50];
	
	} refrescos;

	struct compras {
	
	char codigo [20], nombre_proveedor [20], empresa [20], domicilio [50];
	char telefono [10], productos [50], observaciones [50];
	
	} proveedores;
	
} datos [10]; 

int cont = 0; // Contador útil para llevar a cabo todas las funciones

void figura () { // Función para imprimir pantalla de carga
	
	system("cls"); // Limpiar pantalla
	
	cuadro (0, 0, 78, 24); // Genera un margen
	
	gotoxy (16, 6); Sleep (400); printf("           //((##           SADIBEBSADIBEBSA"); // Sleep para simular una pantalla de carga
	gotoxy (16, 7); Sleep (400); printf("       #..,,,,,,..*        BEBIDASBEBIDASBEB");
	gotoxy (16, 8); Sleep (400); printf("       #..((####,,*       SADIBEBSADIBEBSADI");
	gotoxy (16, 9); Sleep (400); printf("           ,,@@,,        BEBIDASBEBIDASBEBID");
	gotoxy (16, 10); Sleep (400); printf("           .,@@,,         SADIBEBSADIBEBSADI");
	gotoxy (16, 11); Sleep (400); printf("     ..*##..%%%%##/**     BEBIDASBEBIDASBEBI");
	gotoxy (16, 12); Sleep (400); printf("   ..%%/..%%%%%%###%%,,     LUNALUNALUNALUNA");
	gotoxy (16, 13); Sleep (400); printf("   ,,%%/..%%%%%%###%%,,     ANULANULANULANUL");
	gotoxy (16, 14); Sleep (400); printf("   ,,%%########%,,#%%,,      UNALUNALUNALUNA");
	gotoxy (16, 15); Sleep (400); printf("   ,,%%###%%####,,#%%,,       ULANULANULANUL");
	gotoxy (16, 16); Sleep (400); printf("   ,,,,/%%####,,%%/,,,,       NALUNALUNALUNA");
	gotoxy (16, 17); Sleep (400); printf("       *,,,,,,,,,,*         ULANULANULANULAN");

}

// Funciones de las bebidas carbonatadas

void capturar_refrescos () { 

	system("cls");
	
	cuadro (0, 0, 78, 24);
	cuadro (1, 1, 77, 3); // Margen pequeño para el título
	
	gotoxy (32, 2); printf("CAPTURA"); // Posición del título

	if (cont <= 10) { // Si la condición se cumple, se pueden registrar hasta 10 datos diferentes
		
		cont++; // Contador en aumento
		
		gotoxy (3, 5); printf("Nombre del refresco: ");
		fflush(stdin); gets(datos[cont].refrescos.nombre_refresco); // Captura del dato
		gotoxy (3, 7); printf("Presentación: ");
		fflush(stdin); gets(datos[cont].refrescos.presentacion);
		gotoxy (3, 9); printf("Volumen: ");
		fflush(stdin); gets(datos[cont].refrescos.volumen);
		gotoxy (3, 11); printf("Color: ");
		fflush(stdin); gets(datos[cont].refrescos.color);
		gotoxy (3, 13); printf("Sabor: ");
		fflush(stdin); gets(datos[cont].refrescos.sabor);
		gotoxy (3, 15); printf("Precio al público: ");
		fflush(stdin); gets(datos[cont].refrescos.precio_al_publico);
		gotoxy (3, 17); printf("Precio al proveedor: ");
		fflush(stdin); gets(datos[cont].refrescos.precio_al_proveedor);
		gotoxy (3, 19); printf("Observaciones (NA si no aplica): ");
		fflush(stdin); gets(datos[cont].refrescos.observaciones);
		
	}
	
	if (cont == 10) { // Si se llega al límite, no permite guardar más datos
	
	gotoxy (3, 5); printf("No hay más espacio disponible"); } 
		
}

void mostrar_refrescos () {
	
	system("cls");
	
	cuadro (0, 0, 78, 24);
	cuadro (1, 1, 77, 3);
	
	gotoxy (32, 2); printf("MUESTRA");
	
	if (cont != 0) { // Verifica haya datos

		for (int i = 1; i<=cont ; i++) { // Ciclo para imprimir todas las bebidas registradas
			
			gotoxy (3, 5); printf("Nombre del refresco: %s", datos[i].refrescos.nombre_refresco);
			gotoxy (3, 7); printf("Presentación: %s", datos[i].refrescos.presentacion);
			gotoxy (3, 9); printf("Volumen: %s", datos[i].refrescos.volumen);
			gotoxy (3, 11); printf("Color: %s", datos[i].refrescos.color);
			gotoxy (3, 13); printf("Sabor: %s", datos[i].refrescos.sabor);
			gotoxy (3, 15); printf("Precio al consumidor: %s", datos[i].refrescos.precio_al_publico);
			gotoxy (3, 17); printf("Precio del proveedor: %s", datos[i].refrescos.precio_al_proveedor);
			gotoxy (3, 19); printf("Observaciones: %s", datos[i].refrescos.observaciones);
			
		}
	}	

	if (cont == 0) { // En caso de la inexistencia de datos, arroja este mensaje
	
	gotoxy (3, 5); printf("El arreglo está vacío"); 
	
	}
	
}

void buscar_refrescos () {
	
	system("cls");
	
	cuadro (0, 0, 78, 24);
	cuadro (1, 1, 77, 3);
	
	gotoxy (32, 2); printf("BÚSQUEDA");
	
	if (cont != 0) { // Nuevamente se verifica si hay al menos un dato registrado
		
		int band = 0; // Bandera que cambia si hay algún tipo de dato
		char n[30]; // Entrada de texto para buscar el refresco
		
		gotoxy(3, 5); printf("Ingresa el nombre del refresco: "); // Aquí puede variar el tipo de dato, puede ser el nombre, color, sabor, entre otros
		scanf("%s", &n);
		
		for (int i = 0;i<cont;i++) // Inicia contador para buscar el nombre
		
			if(strcmp(n,datos[i].refrescos.nombre_refresco) == 0) { // Se verifica si coincide con un dato ingresado
				
				gotoxy(3, 7); printf("\n   Nombre del refresco: %s", datos[i].refrescos.nombre_refresco);
				gotoxy(3, 9); printf("\n   Presentación: %s", datos[i].refrescos.presentacion);
				gotoxy(3, 11); printf("\n   Volumen: %s", datos[i].refrescos.volumen);
				gotoxy(3, 13); printf("\n   Color: %s", datos[i].refrescos.color);
				gotoxy(3, 15); printf("\n   Sabor: %s", datos[i].refrescos.sabor);
				gotoxy(3, 17); printf("\n   Precio al consumidor: %s", datos[i].refrescos.precio_al_publico);
				gotoxy(3, 19); printf("\n   Precio del proveedor: %s", datos[i].refrescos.precio_al_proveedor);
				gotoxy(3, 21); printf("\n   Observaciones: %s", datos[i].refrescos.observaciones);
				
				band = 1; // Se imprimen los datos y el valor de la bandera cambia
				
			}
			
			if (band == 0) { // En caso de que no se encuentre el elemento
			
			gotoxy(3, 7); printf("No existe el dato"); }
					
	}
	
	if (cont == 0) { // En caso de que no haya ningún dato registrado
		
	gotoxy(3, 5); printf("No hay elementos en el arreglo"); }
	
}

// Funciones de los individuos responsables del comercio

void capturar_proveedores () {
	
	system("cls");
	
	cuadro (0, 0, 78, 24);
	cuadro (1, 1, 77, 3);
	
	gotoxy (32, 2); printf("CAPTURA");
	
	if (cont <= 10) {
		
		cont++;
		
		gotoxy (3, 5); printf("Código del proveedor: ");
		fflush(stdin); gets(datos[cont].proveedores.codigo);
		gotoxy (3, 7); printf("Nombre del proveedor: ");
		fflush(stdin); gets(datos[cont].proveedores.nombre_proveedor);
		gotoxy (3, 9); printf("Empresa: ");
		fflush(stdin); gets(datos[cont].proveedores.empresa);
		gotoxy (3, 11); printf("Domicilio: ");
		fflush(stdin); gets(datos[cont].proveedores.domicilio);
		gotoxy (3, 13); printf("Tel�fono: ");
		fflush(stdin); gets(datos[cont].proveedores.telefono);
		gotoxy (3, 15); printf("Productos: ");
		fflush(stdin); gets(datos[cont].proveedores.productos);
		gotoxy (3, 17); printf("Observaciones (NA si no aplica): ");
		fflush(stdin); gets(datos[cont].proveedores.observaciones);
		
	}
	
	if (cont == 10) {
	
	gotoxy (3, 5); printf("No hay espacio disponible"); }
		
}

void mostrar_proveedores () {
	
	system("cls");
	
	cuadro (0, 0, 78, 24);
	cuadro (1, 1, 77, 3);
	
	gotoxy (32, 2); printf("MUESTRA");
	
	if (cont != 0)

	for (int i = 1; i<=cont ; i++) {
		
		gotoxy (3, 5); printf("Código del proveedor: %s", datos[i].proveedores.codigo);
		gotoxy (3, 7); printf("Nombre del proveedor: %s", datos[i].proveedores.nombre_proveedor);
		gotoxy (3, 9); printf("Empresa: %s", datos[i].proveedores.empresa);
		gotoxy (3, 11); printf("Domicilio: %s", datos[i].proveedores.domicilio);
		gotoxy (3, 13); printf("Teléfono: %s", datos[i].proveedores.telefono);
		gotoxy (3, 15); printf("Productos: %s", datos[i].proveedores.productos);
		gotoxy (3, 17); printf("Observaciones: %s", datos[i].proveedores.observaciones);
		
	}
	
	if (cont == 0) {
	
	gotoxy (3, 5); printf("El arreglo está vacío"); }
	
}

void buscar_proveedores () {
	
	system("cls");
	
	cuadro (0, 0, 78, 24);
	cuadro (1, 1, 77, 3);
	
	gotoxy (32, 2); printf("BÚSQUEDA");
	
	if (cont != 0) {
		
		int band = 0;
		char c[30];
		
		gotoxy (3, 5); printf("Ingresa el codigo del proveedor: ");
		scanf("%s", &c);
		
		for (int i = 0; i<cont ; i++) 
		
			if(strcmp(c,datos[i].proveedores.codigo) == 0) {
				
				gotoxy (3, 7); printf("Codigo del proveedor: %s", datos[i].proveedores.codigo);
				gotoxy (3, 9); printf("Nombre del proveedor: %s", datos[i].proveedores.nombre_proveedor);
				gotoxy (3, 11); printf("Empresa: %s", datos[i].proveedores.empresa);
				gotoxy (3, 13); printf("Domicilio: %s", datos[i].proveedores.domicilio);
				gotoxy (3, 15); printf("Telefono: %s", datos[i].proveedores.telefono);
				gotoxy (3, 17); printf("Productos: %s", datos[i].proveedores.productos);
				gotoxy (3, 5); printf("Observaciones: %s", datos[i].proveedores.observaciones);
				
				band = 1;	
				
			}
			
			if (band == 0) {
			
			gotoxy(3, 5); printf("No existe el dato"); }
					
	}
	
	if (cont == 0) {
		
	gotoxy(3, 5); printf("No hay elementos en el arreglo"); }
	
}

// Funciones para los menús 

void menu_refrescos () {
	
	int rop; // Refrescos opción
	
	do {
		
		system("cls");
		
		cuadro (0, 0, 78, 24);
		cuadro (1, 1, 77, 3);
		
		gotoxy (32, 2); printf("REFRESCOS"); // Menú
		gotoxy (3, 5); printf("1. Registrar");
		gotoxy (3, 7); printf("2. Mostar");
		gotoxy (3, 9); printf("3. Buscar");
		gotoxy (3, 11); printf("4. Regresar");
		gotoxy (3, 13); printf("¿Que deseas hacer?: ");
		scanf("%i", &rop);
		
		switch (rop) { // Para lo que desee hacer el usuario
			
			case 1: system("cls"); capturar_refrescos (); break; // Llamado a la función
					
			case 2: system ("cls"); mostrar_refrescos (); break;
				
			case 3: system ("cls"); buscar_refrescos (); break;
										
		}
		
		getch (); // Espera la entrada de cualquier tecla
		
	} while (rop != 4); // En caso de elegir la 4ta opción, se regresa al menú principal
		
}

void menu_proveedores () {
	
	int pop; // Proveedores opción
	
	do {
		
		system("cls");
		
		cuadro (0, 0, 78, 24);
		cuadro (1, 1, 77, 3);
				
		gotoxy (32, 2); printf("PROVEEDORES");
		gotoxy (3, 5); printf("1. Registrar");
		gotoxy (3, 7); printf("2. Mostrar");
		gotoxy (3, 9); printf("3. Buscar");
		gotoxy (3, 11); printf("4. Regresar");
		gotoxy (3, 13); printf("¿Que deseas hacer?: ");
		scanf("%i", &pop);
		
		switch (pop) {
			
			case 1: system ("cls"); capturar_proveedores (); break;
			
			case 2: system ("cls"); mostrar_proveedores (); break;
			
			case 3: system ("cls"); buscar_proveedores (); break;
				
		}
		
		getch ();
			
	} while (pop != 4);
		
}

// Funcion "principal" para registrar los datos

void eleccion () { // Aquí el usuario escoge que desea registrar, mostrar o buscar
	
	int eop; // Elección opción
	
	do {
		
		system("cls");
		
		cuadro (0, 0, 78, 24);
		cuadro (1, 1, 77, 3);
		
		gotoxy (32, 2); printf("MENÜ PRINCIPAL");
		gotoxy (3, 5); printf("1. Refrescos");
		gotoxy (3, 7); printf("2. Proveedores");
		gotoxy (3, 9); printf("3. Cerrar sesión"); // Para regresar a la pantalla principal
		gotoxy (3, 12); printf("¿A que parte del programa desea ingresar?: ");
		scanf("%i", &eop);
		
		if (eop == 1) { // Lleva al menú de refrescos
		
		system("cls"); menu_refrescos (); 
		
		}
		
		if (eop == 2) {
			
		system("cls"); menu_proveedores (); // Lleva al menú de proveedores
		
		}
		
	} while (eop != 3);
		
}

// Armando el sistema completo

int main () {
	
	system("color 1E"); // Cambia color de fondo y pantalla
	
	int contra, i = 1; // Contra = Contraseña a ingresar, i = Contador
			
	while (i <= 3) { // Tres intentos disponibles
		
		cuadro (0, 0, 78, 24);
		cuadro (1, 1, 77, 3);
		gotoxy (32, 2); printf("BASE DE DATOS");
		gotoxy (3, 5); printf("Usuario: Admin"); 
		gotoxy (3, 7); printf("Contraseña: ");
		scanf("%i", &contra);
		
		if (contra == correcto) { // Si la contraseña es correcta, se accede al menú principal
			
			gotoxy (3, 9); printf("Correcto"); // Confirmación de entrada
			Sleep(600); // Ligero retraso
			system("cls");
			figura(); // Pantalla de carga
			Sleep(1200);
			eleccion (); // Menú principal
					
		}
		
		if (contra != correcto) { // Contador de intentos
		
		system("cls"); gotoxy (3, 9); printf("Incorrecto, intente nuevamente...");
		
			if (i == 3) { // Si a los 3 intentos el usuario falla, el programa finaliza
			
			system("cls"); gotoxy (3, 5); printf("Programa finalizado, límite de intentos excedido\n\n   ");
			system("PAUSE");
			
			}
		
		}
				
		i++;
		
	}
			
}
