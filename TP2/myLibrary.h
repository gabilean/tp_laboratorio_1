#ifndef MYLIBRARY_H_INCLUDED
#define MYLIBRARY_H_INCLUDED

void myLibrary_cargarListado(int notas[], int tamanio);
void myLibrary_mostrarInformacionDelArray(int notas[], int tamanio);
int myLibrary_retornarTotal(int notas[], int tamanio);
int myLibrary_retornarPromedio(int notas[], int tamanio);
int myLibrary_retornarMaximo(int notas[], int tamanio);
int myLibrary_retornarMinimo(int notas[], int tamanio);
int myLibrary_retornarCantidadPares(int notas[], int tamanio);
int myLibrary_retornarCantidadEntreNotas(int notas[], int tamanio, int limInferior, int limSuperior);
int myLibrary_getInt(char mensaje[]);
float myLibrary_getFloat(char mensaje[]);
char myLibrary_getChar(char mensaje[]);
int myLibrary_esNumerico(char str[]);
int myLibrary_esSoloLetras(char str[]);
int myLibrary_esAlfaNumerico(char str[]);
int myLibrary_getString(char*, int);
int myLibrary_getStringLetras(char str[], char input[]);
int myLibrary_getStringNumeros(char*, int, char*, char*, int);
int myLibrary_isValidLetras(char*, int);
int myLibrary_getNombre(char* ,int , char*, char*, int);
//void myLibrary_mostrarEmpleado(struct datos, int);




#endif // MYLIBRARY_H_INCLUDED
