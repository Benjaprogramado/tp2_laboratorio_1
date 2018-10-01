#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "arrayEmployee.h"




/////////////////////////////////////////////////////////////////////////////////

 /**
 * \brief Imprime un mensaje y devuelve un numero
 * \param mensaje, es el mensaje a mostrar
 * \param numero, es el numero ingresado
 * \return el numero ingresado
 *
 */

 int getInt(char mensaje[])
    {
    int numero;
    printf("%s",mensaje);
    scanf("%d",&numero);
    return numero;
    }

/////////////////////////////////////////////////////////////////////////////////

  /**
 * \brief Muestra un menu de opciones enumeradas y devuelve un entero
 * \param opcionMenu, variable que guarda el numero de la opcion seleccionada
 * \return el numero ingresado
 *
 */

 int showMenu()
 {
     int opcionMenu;
     system("cls");
     printf("\n    -----ADMINISTRAR NOMINA DE EMPLEADOS-----\n\nPor favor, ingrese el numero correspondiente a la opcion deseada:");
     opcionMenu = getInt("\n\n\n1 - ALTAS \n2 - MODIFICACIONES \n3 - BAJAS\n4 - INFORMAR\n5 - SALIR\n\n\n");
     return opcionMenu;
 }


/////////////////////////////////////////////////////////////////////////////////

 /**
 * \brief Inicializa el array de empleados con el valor indicado
 * \param array, es el array a ser inicializado
 * \param len, es el tope de carga del array
 * \param value, es el valor que sera cargado en cada posición "i" del array mencionado
 * \return void, la funcion no requiere devolver ningun valor
 *
 */
void initArrayEmployee(employee array[],int len,int value)
{
    int i;
    for(i=0;i < len; i++)
    {
        array[i].isEmpty = value;

    }
}

/////////////////////////////////////////////////////////////////////////////////

/**
 * \brief Busca los datos de un empleado basandose en el ID asignado al mismo
 * \param array, es el array donde se buscara el dato
 * \param len, Indica la logitud del array mencionado
 * \param value, es el ID que se esta buscando
 * \return -1 si no lo encuentra, el indice "i" del array si lo encuentra
 *
 */
int findEmployeeById(employee array[],int len,char mensaje[])
{
    int i;
    int flag=0;
    int value=getInt(mensaje);

    for(i=0;i < len; i++)
    {
        if(array[i].id == value)
        {

            printf("\nIngreso el ID coreespondiente a %s %s\n\nPresione una tecla para continuar", array[i].name,array[i].lastName);
            flag=1;
            getch();

            break;
        }

    }
    if(flag==0)
    {
       printf("Empleado no encontrado");
       getch();
       return -1;


    }
 return i;

}

/////////////////////////////////////////////////////////////////////////////////

/**
 * \brief Busca el primer espacio disponible en el array indicado
 * \param array, es el array en se buscará
 * \param len, logitud del array utilizado
 * \param value Es el valor que se busca
 * \return Si no encuentra coincidencias (-1) y si la hay, devuelve la posición de la misma
 *
 */
int lookForPlace(employee array[],int len,int value)
{
    int i;
    for(i=0;i < len; i++)
    {
        if(array[i].isEmpty == value)
        {
            return i;
        }
    }
    return -1;
}


/////////////////////////////////////////////////////////////////////////////////


/**
 * \brief carga un empleado en el array validando previamente los datos ingresados
 * \param array, es el array de empleados donde se cargaran datos
 * \param len, es el tamaño del array
 * \return devuelve 1 si la carga fue exitosa, de lo contrario retorna cero
 */

int addEmployee(employee array[],int len)
{
  int i;
  employee auxiliar;


    for(i=0;i<len;i++)
    {

        if(array[i].isEmpty==-1)

        {
          printf("\nALTA DE NUEVOS EMPLEADOS\n");
          if (!getStringLetras("Ingrese el nombre: ",auxiliar.name))
           {
             printf ("El nombre debe estar compuesto solo por letras\n");
             getch();
             return 0;
             break;
           }
         if (!getStringLetras("Ingrese el apellido: ",auxiliar.lastName))
           {
             printf ("El apellido debe estar compuesto solo por letras\n");
             getch();
             return 0;
             break;
           }

            auxiliar.sector=getInt("Ingrese el numero correspondiente al sector: \n\n 1-Administración\n 2-Depto. Comercial\n 3-Marketing\n 4-Depto. Sistemas\n\n");

         if(auxiliar.sector!=1&&auxiliar.sector!=2&&auxiliar.sector!=3&&auxiliar.sector!=4)
           {
             printf ("Opción Incorrecta, debe ingresar un numero del 1 al 4...\n");
             getch();
             return 0;
             break;
           }
        auxiliar.salary=getFloat("Ingrese el salario: ");

        auxiliar.id=(i+1);
        auxiliar.isEmpty=0;

        array[i]=auxiliar;
        printf("ALTA EXITOSA!!!\n\nPresiones una tecla para continuar...");
        getch();
        break;

      }


    }

  return 1;

}



/////////////////////////////////////////////////////////////////////////////////


/**
 * \brief modifica datos de un empleado en el array validando previamente los datos ingresados
 * \param array, es el array de empleados donde se cargaran datos
 * \param len, es el tamaño del array
 * \param id, es el identificador del empleado a modificar
 * \return devuelve 1 si la carga fue exitosa, de lo contrario retorna cero
 */

int changeEmployee(employee array[],int len)
{
  int indice;
  employee auxiliar;

  indice=findEmployeeById(array,len,"Ingrese el ID del empleado a modificar\n\n");

        while(indice!=-1)

        {
          printf("\nMODIFICACION DE EMPLEADOS\n");
          if (!getStringLetras("Ingrese el nombre: ",auxiliar.name))
           {
             printf ("El nombre debe estar compuesto solo por letras\n");
             getch();
             return 0;
             break;
           }
         if (!getStringLetras("Ingrese el apellido: ",auxiliar.lastName))
           {
             printf ("El apellido debe estar compuesto solo por letras\n");
             getch();
             return 0;
             break;
           }

            auxiliar.sector=getInt("Ingrese el numero correspondiente al sector: \n\n 1-Administración\n 2-Depto. Comercial\n 3-Marketing\n 4-Depto. Sistemas\n\n");

         if(auxiliar.sector!=1&&auxiliar.sector!=2&&auxiliar.sector!=3&&auxiliar.sector!=4)
           {
             printf ("Opción Incorrecta, debe ingresar un numero del 1 al 4...\n");
             getch();
             return 0;
             break;
           }
        auxiliar.salary=getFloat("Ingrese el salario: ");

        auxiliar.id=(indice+1);
        auxiliar.isEmpty=0;

        array[indice]=auxiliar;
        printf("MODIFICACION EXITOSA!!!\n\nPresione una tecla para continuar...");
        getch();
        break;

      }


  return 1;

}

/////////////////////////////////////////////////////////////////////////////////

/**
 * \brief Busca los datos de un empleado basandose en el ID asignado al mismo
 * \param array, es el array de empleados donde se buscara el dato
 * \param maxItems, Indica la logitud del array mencionado
 * \param value, es el ID que se esta buscando
 * \return 1
 *
 */
int removeEmployee(employee array[],int len)
{
    int i,id;
    int flag=0;
    char confirma;

    id=getInt("Ingrese el ID del empleado que desea borrar: \n\n");

    for(i=0;i < len; i++)
    {
        if(array[i].id == id&&array[i].isEmpty!=-1)
        {

            confirma=getChar("\nEmpleado encontrado, Quiere proceder con la eliminacion??\n\nPara confirmar presione s, para cancelar presione cualquier otra tecla...");
            flag=1;
            if(confirma=='s')
            {
                array[i].isEmpty=-1;
                printf("Eliminacion exitosa!!\n\nPresione una tecla para continuar...");
                getch();
            }
            break;
        }
    }
    if(flag==0)
    {
       printf("Empleado no encontrado");
       getch();

    }
 return 1;

}

/////////////////////////////////////////////////////////////////////////////////

/**
 * \brief ordena el array de empleados indicado
 * \param array, es el array de empleados a ordenar
 * \param len, Indica la logitud del array mencionado
 * \return 0
 *
 */
int sortEmployee(employee array[],int len)
{
    int i,j;
    employee auxiliar;

                for(i=0; i < len - 1; i++)
                {
                    if(array[i].isEmpty == -1)
                    {
                        continue;
                    }
                    for(j=i+1; j < len; j++)
                    {
                        if(array[j].isEmpty == -1)
                        {
                            continue;
                        }
                        if(stricmp(array[i].lastName,array[j].lastName) > 0)
                        {
                            auxiliar = array[j];
                            array[j] = array[i];
                            array[i] = auxiliar;
                        }
                    }
                }

                for(i=0; i < len - 1; i++)
                {
                    if(array[i].isEmpty == -1)
                    {
                        continue;
                    }
                    for(j=i+1; j < len; j++)
                    {
                        if(array[j].isEmpty == -1)
                        {
                            continue;
                        }
                        if((array[i].sector)>(array[j].sector))
                        {
                            auxiliar = array[j];
                            array[j] = array[i];
                            array[i] = auxiliar;
                        }
                    }
                }

  return 0;
}
/////////////////////////////////////////////////////////////////////////////////

/**
 * \brief imprime el array indicado
 * \param len, longitud del array
 * \return 0
 *
 */

void printArrayEmployee(employee array[],int len)

{
    int i;
    printf(" ID-SECTOR-Apellido-Nombre-Salario\n\n");
                    for(i=0;i<len;i++)
                      {
                        if(array[i].isEmpty!=(-1))
                              {
                                printf("  %d - %d - %s - %s - %.2f\n\n",array[i].id,array[i].sector,array[i].lastName,array[i].name,array[i].salary);

                              }
                      }
                printf("\n\nPresione una tecla para continuar...");
                getch();

}




/////////////////////////////////////////////////////////////////////////////////

/**
 * \brief imprime el array indicado
 * \param len, longitud del array
 * \return 0
 *
 */

int promSalaryEmployee(employee array[],int len)
{
    int i;
    float contador=0;
    float auxiliar=0;
    float promedio;
    for(i=0;i<len;i++)
    {
        if(array[i].isEmpty!=-1)
        {
            auxiliar=suma(auxiliar,array[i].salary);
            contador ++;
        }
    }

    promedio=division(auxiliar,contador);
return 1;
}

/////////////////////////////////////////////////////////////////////////////////


/**
 * \brief Solicita un número al usuario y devuelve el resultado
 * \param mensaje Es el mensaje a ser mostrado
 * \return El número ingresado por el usuario
 *
 */
float getFloat(char mensaje[]){

    float numero;
    printf("%s",mensaje);
    scanf("%f",&numero);
    return numero;
    }
////////////////////////////////////////////////////////////////////////////////////////

/**
 * \brief Suma dos variables del tipo float y devuelve el resultado
 * \param A y B son los operando
 * \return El resultado de la suma
 */
float suma (float A, float B){

return A + B;

}

/////////////////////////////////////////////////////////////////////////////////

/**
 * \brief Divide dos variables del tipo float y devuelve el resultado
 * \param A y B son los operando
 * \return El resultado de la división
 */

float division (float A, float B){


    if(B==0){

        float resultado=0;
        return resultado;

    }
    else{
        float resultado=0;
        resultado=A/B;
        return resultado;
    }



}


/////////////////////////////////////////////////////////////////////////////////


/**
 * \brief Solicita un caracter al usuario y devuelve el resultado
 * \param mensaje Es el mensaje a ser mostrado
 * \return El caracter ingresado por el usuario
 *
 */
char getChar(char mensaje[])
{
    char auxiliar;
    printf("%s",mensaje);
    fflush(stdin);
    scanf("%c",&auxiliar);
    return auxiliar;
}


/////////////////////////////////////////////////////////////////////////////////


 /**
 * \brief Verifica si el valor recibido es numérico
 * \param str Array con la cadena a ser analizada
 * \return 1 si es númerico y 0 si no lo es
 *
 */

int esNumerico(char str[])
{
   int i=0;
   while(str[i] != '\0')
   {
       if(str[i] < '0' || str[i] > '9')
           return 0;
       i++;
   }
   return 1;
}

/////////////////////////////////////////////////////////////////////////////////


/**
 * \brief Verifica si el valor recibido contiene solo letras
 * \param str Array con la cadena a ser analizada
 * \return 1 si contiene solo ' ' y letras y 0 si no lo es
 *
 */
int esSoloLetras(char str[])
{
   int i=0;
   while(str[i] != '\0')
   {
       if((str[i] != ' ') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z'))
           return 0;
       i++;
   }
   return 1;
}


/////////////////////////////////////////////////////////////////////////////////


/**
 * \brief Solicita un texto al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargará el texto ingresado
 * \return void
 */
void getString(char mensaje[],char input[])
{
    printf("%s",mensaje);
    scanf ("%s", input);
}


/////////////////////////////////////////////////////////////////////////////////


/**
 * \brief Solicita un texto al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargará el texto ingresado
 * \return 1 si el texto contiene solo letras
 */
int getStringLetras(char mensaje[],char input[])
{
    char aux[256];
    getString(mensaje,aux);
    if(esSoloLetras(aux))
    {
        strcpy(input,aux);
        return 1;
    }
    return 0;
}

/////////////////////////////////////////////////////////////////////////////////


/**
 * \brief Solicita un texto numérico al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargará el texto ingresado
 * \return 1 si el texto contiene solo números
 */
int getStringNumeros(char mensaje[],char input[])
{
    char aux[256];
    getString(mensaje,aux);
    if(esNumerico(aux))
    {
        strcpy(input,aux);
        return 1;
    }
    return 0;
}


/////////////////////////////////////////////////////////////////////////////////

