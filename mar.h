/* Llanos De Luna Josue Alexander
19 de Noviembre del 2021 */

# ifndef _mar_ // Definir el archivo
# define _mar_

void gotoxy (int x, int y); // Prototipos
void cuadro (int x, int y, int x2, int y2);

void gotoxy (int x, int y) { // Define gotoxy para usarlo y posicionar los mensajes de salida (printf)
	
	HANDLE hcon;
	hcon = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwPos;
	dwPos.X = x;
	dwPos.Y = y;
	SetConsoleCursorPosition(hcon, dwPos);
	
}

void cuadro (int x1, int y1, int x2, int y2) { // Función, que al asignarle valores, se imprime un marco
	
	int i; // Contador
	
	// setlocale(LC_CTYPE, "C"); // Para usar carácteres especiales como acentos
	
	for (i=x1;i<x2;i++) {
		
		gotoxy(i, y1); printf("\304"); // Línea horizontal superior
		gotoxy(i, y2); printf("\304"); // Línea horizontal inferior
		
	}
	
	for (i=y1;i<y2;i++) {
		
		gotoxy(x1,i);printf("\263"); // Línea vertical izquierda
		gotoxy(x2,i);printf("\263"); // Línea vertical derecha
		
	}
		
	gotoxy(x1,y1);printf("\332"); // Esquinas del cuadro
	gotoxy(x1,y2);printf("\300");
	gotoxy(x2,y1);printf("\277");
	gotoxy(x2,y2);printf("\331");
	
}

#endif // Terminar de definir el archivo
