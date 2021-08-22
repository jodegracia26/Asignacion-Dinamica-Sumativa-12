#include <stdio.h>
#include <string.h>

/*Elaborar una aplicación de línea de comandos en C que simule un gestor de contactos simple de un dispositivo movil.
Esta programa debe permitir agregar nuevos registros, listarlos, modificarlos, buscar contactos guardados, eliminar registros telefonicos.
Tome en consideracion que la informacion personal por almacenar debe ser nombre, telefono y correo electronico*/

//Inicializar estructura para los contactos
typedef struct entrada{
   char nombre[50];
   char telefono[12];
   char correo[50];
   } entrada;

int main(){

    //Inicializar las variables dinamicas
    entrada * contacto, * buscador;
    contacto = (entrada*) malloc(10 * sizeof(entrada));
    buscador = (entrada*) malloc(10 * sizeof(entrada));
    int menu=0, num=1, eliminar, posicion, i, pos;
    char searchbar[50];

    while (menu!=6){ //Loop para el menu principal
        printf("------Phonebook------\n");
        printf("\n[1] Agregar entrada");
        printf("\n[2] Lista de contactos");
        printf("\n[3] Modificar entrada");
        printf("\n[4] Eliminar entrada");
        printf("\n[5] Buscador de contactos");
        printf("\n[6] SALIR");
        printf("\nSu eleccion: ");
        scanf("%d", &menu);

        switch(menu){ //Sentencias para las diferentes opciones del menu
            case 1: //Agregar contactos
                for (i=num-1; i<num; i++){
                    printf("Agregar contacto:\n");
                    printf("Nombre: ");
                    scanf("%s", contacto[i].nombre);
                    strcpy(buscador[i].nombre, contacto[i].nombre);
                    printf("Telefono: ");
                    scanf("%s", contacto[i].telefono);
                    strcpy(buscador[i].telefono, contacto[i].telefono);
                    printf("Correo: ");
                    scanf("%s", contacto[i].correo);
                    strcpy(buscador[i].telefono, contacto[i].correo);
                }
            num++;
            printf("Contacto guardado exitosamente\n\n");
            break;

            case 2: //Listado de contactos
                printf("\n\nLista de contactos:\n");
                pos=1;
                for (i=0; i<num-1; i++){
                    printf("Contacto %i:\nNombre: %s\nTelefono: %s\nCorreo: %s\n---------\n", pos, contacto[i].nombre, contacto[i].telefono, contacto[i].correo);
                    pos++;
                }
            break;

            case 3: //Editar entrada de contactos
                pos=1;
                printf("Indique el numero de contacto a editar:\n");
                for (i=0; i<num-1; i++){
                    printf("Contacto %i:\nNombre: %s\n---------\n", pos, contacto[i].nombre);
                    pos++;
                }
                printf("Su eleccion: ");
                scanf("%d", &posicion);
                posicion--;
                printf("Nuevo nombre: ");
                scanf("%s", contacto[posicion].nombre);
                strcpy(buscador[posicion].nombre, contacto[posicion].nombre);
                printf("Nuevo telefono: ");
                scanf("%s", contacto[posicion].telefono);
                strcpy(buscador[posicion].telefono, contacto[posicion].telefono);
                printf("Nuevo correo: ");
                scanf("%s", contacto[posicion].correo);
                strcpy(buscador[posicion].correo, contacto[posicion].correo);
            break;

            case 4: //Eliminar entrada de contactos
                printf("Indique el numero de contacto a eliminar: ");
                pos=1;
                for (i=0; i<num-1; i++){
                    printf("Contacto %i:\nNombre: %s\n---------\n", pos, contacto[i].nombre);
                    pos++;
                }
                printf("Su eleccion: ");
                scanf("%d", &posicion);
                posicion--;
                eliminar=num;
                eliminar++;
                contacto[posicion]=contacto[eliminar];
                buscador[posicion]=contacto[eliminar];
            break;

            case 5: //Buscador de contactos
                printf("Introduzca el nombre a buscar: ");
                scanf("%s", searchbar);
                printf("Contactos similares: ");
                pos=1;
                for (i=0; i<num-1; i++){
                    //Comparamos con strcmp y si nos sale un "match" imprimimos la informacion
                    if (strcmp(searchbar,buscador[i].nombre)==0) {
                        printf("Contacto %i:\nNombre: %s\nTelefono: %s\Correo: %s\n---------\n", pos, contacto[i].nombre, contacto[i].telefono, contacto[i].correo);
                        pos++;
                    }
                }
            break;

            case 6:
            break;

            //Si no se selecciona una opcion entre 1-6
            default: printf("Por favor seleccione una opcion del menu\n");
        }

    }

    //Libera la informacion/memoria de la asignacion dinamica
    free(contacto);
    free(buscador);
    return 0;
}