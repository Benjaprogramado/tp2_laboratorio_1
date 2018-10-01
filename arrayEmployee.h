#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

 typedef struct{

    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty;

}employee;



int showMenu();
int lookForPlace(employee array[],int len,int value);
int addEmployee(employee array[],int len);
int changeEmployee(employee array[],int len);
int removeEmployee(employee array[],int len);
void initArrayEmployee(employee array[],int len,int value);
int findEmployeeById(employee array[],int len,char mensaje[]);
int sortEmployee(employee array[],int len);
void printArrayEmployee(employee array[],int len);
int promSalaryEmployee(employee array[],int len);

int esNumerico(char str[]);//sin uso aun
int esSoloLetras(char str[]);//sin uso aun

char getChar(char mensaje[]);
int getInt(char mensaje[]);
void getString(char mensaje[],char input[]);//sin uso aun
int getStringLetras(char mensaje[],char input[]);//sin uso aun
int getStringNumeros(char mensaje[],char input[]);//sin uso aun
float getFloat (char[]);

float suma (float, float);//sin uso aun
float division (float, float);//sin uso aun


#endif // FUNCIONES_H_INCLUDED
