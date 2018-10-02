#ifndef MYLIBRARY_H_INCLUDED
#define MYLIBRARY_H_INCLUDED

int myLibrary_esInt(char* str);
int myLibrary_esFloat(char* str);
int myLibrary_esSoloLetras(char* str);
int myLibrary_esAlfaNumerico(char* str);
int myLibrary_getString(char* pBuffer, int limite);
int myLibrary_getFloat(float* num, int limite, char* msg, char* msgErr, int reintentos);
int myLibrary_getInt(int* num, int limite, char* msg, char* msgErr, int reintentos);
int myLibrary_isValidLetras(char* pBuffer, int limite);
int myLibrary_getNombre(char* pNombre,int limite, char* msg, char* msgErr, int reintentos);

#endif // MYLIBRARY_H_INCLUDED
