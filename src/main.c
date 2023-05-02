/*---  Code Information ------------------------------------------------------------------------ */
// Autor: Jassan, Joel
// Date: 15/04/2023
//
// Function: Genera alumno a partir de sus datos
/*---------------------------------------------------------------------------------------------- */



/*---  Includes  ------------------------------------------------------------------------------- */
#include "alumno.h"
#include <stdio.h>


/*---  Macros and Definitions  ----------------------------------------------------------------- */

/*---  Private Data Declaration  --------------------------------------------------------------- */

/*---  Public Data Declaration  ---------------------------------------------------------------- */

/*---  Private Function Declaration  ----------------------------------------------------------- */

/*---  Public Function Declaration  ------------------------------------------------------------ */

/*---  Private Data Definition  ---------------------------------------------------------------- */

/*---  Public Data Definition  ----------------------------------------------------------------- */

/*---  Private Function Definition  ------------------------------------------------------------ */

/*---  Public Function Definition  ------------------------------------------------------------ */

/*---  Private Function Implementation  -------------------------------------------------------- */

/*---  Public Function Implementation  --------------------------------------------------------- */


/**
 * @brief Funcion princial del codigo.
 * Serializa los datos del alumno_1 (datos en memoria), si es que puede.
 * @return Nada relevante. Se toma como resultado lo que se imprime en pantalla.
 */ 
int main(void) {
    char cadena[128];     
    alumno_t yo = CrearAlumno("Jassan", "Joel", 41870435);

    // & representa la direccion de memoria de...
    if(Serializar(yo, cadena, sizeof(cadena)) >= 0) {
        printf("%s\n", cadena);
    }
    else{
        printf("Error al serializar\n");
    };
    
    return 0;
}


/*---  End of File  ---------------------------------------------------------------------------- */
