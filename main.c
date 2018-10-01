#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include "arrayEmployee.h"

#define MAX 1000


int main()
{

    employee arrayEmployee[MAX];
    int opcion = 0;
    float promedio;

    initArrayEmployee(arrayEmployee,MAX,-1);

    do
    {
         int place=lookForPlace(arrayEmployee, MAX, -1);
         opcion=showMenu();
         int flag;

         switch(opcion)
         {
            case 1:
                flag=1;
                if(place== -1)
                   {
                     printf("No quedan registros disponibles para cargar nuevos empleados!!!");
                     getch();
                   }
                else
                   {
                    addEmployee(arrayEmployee,MAX);
                   }

                 break;

            case 2:
                if(flag!=1)
                {
                    printf("NO HAY DATOS!!!\n\nDebe cargar al menos un empleado para continuar...");
                    getch();
                }
                else
                {
                    changeEmployee(arrayEmployee, MAX);
                }
                 break;

            case 3:
                if(flag!=1)
                {
                    printf("NO HAY DATOS!!!\n\nDebe cargar al menos un empleado para continuar...");
                    getch();
                    break;
                }
                else
                {
                    removeEmployee(arrayEmployee,MAX);
                    break;
                }


            case 4:
                if(flag!=1)
                {
                    printf("NO HAY DATOS!!!\n\nDebe cargar al menos un empleado para continuar...");
                    getch();
                }
                else
                {
                    sortEmployee(arrayEmployee,MAX);
                    printArrayEmployee(arrayEmployee,MAX);
                    promedio=promSalaryEmployee(arrayEmployee,MAX);
                    printf("\n\nEl promedio de sueldos es: %.2f",promedio);

                }

         }
    }while(opcion != 5);


    return 0;
}


