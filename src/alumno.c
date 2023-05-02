/*---  Code Information ------------------------------------------------------------------------ */
// Autor: Jassan, Joel
// Date: 15/04/2023
//
// Function: Permite crear un alumno y serializar alumno (escribir en pantalla sus datos)
/*---------------------------------------------------------------------------------------------- */



/*---  Includes  ------------------------------------------------------------------------------- */
#include "alumno.h"
#include <stdio.h>

/*---  Macros and Definitions  ----------------------------------------------------------------- */

/*---  Private Data Declaration  --------------------------------------------------------------- */

//! Tipo de dato nuevo "alumno_s".
struct alumno_s{
    char     apellido[FIELD_SIZE];  //!< Almacena apellido del alumno
    char     nombre[FIELD_SIZE];    //!< Almacena nombre del alumno
    uint32_t documento;             //!< Almacena documento del alumno
    bool     alocado;               //!< Determina si el espacio esta, o no, usado
};

/*---  Public Data Declaration  ---------------------------------------------------------------- */

/*---  Private Function Declaration  ----------------------------------------------------------- */

//! Serializa el campo valor. Retorna a traves de snprintf
static int SerializarCadena(const char *campo, const char *valor, char *cadena, int espacio);  

//! Serializa el campo valor. Retorna a traves de snprintf
static int SerializarNumero(const char *campo, int valor, char *cadena, int espacio); 

/*---  Private Data Definition  ---------------------------------------------------------------- */

/*---  Public Data Definition  ----------------------------------------------------------------- */

/*---  Private Function Definition  ------------------------------------------------------------ */

/*---  Public Function Definition  ------------------------------------------------------------ */

/*---  Private Function Implementation  -------------------------------------------------------- */

static int SerializarCadena(const char *campo, const char *valor, char *cadena, int espacio) {
    return snprintf(cadena, espacio, "\"%s\":\"%s\",", campo, valor);
}

static int SerializarNumero(const char *campo, int valor, char *cadena, int espacio) {
    return snprintf(cadena, espacio, "\"%s\":\"%d\",", campo, valor); 
}

/*---  Public Function Implementation  --------------------------------------------------------- */

alumno_t CrearAlumno(char * apellido,char * nombre,int documento){
    alumno_t resultado = malloc(sizeof(struct alumno_s));
    strcpy(resultado->apellido, apellido);
    strcpy(resultado->nombre, nombre);
    resultado->documento = documento;
}

void GetNombreCompleto(alumno_t alumno, char cadena[], uint32_t espacio){
    //return NULL;
}

void GetDocumento(alumno_t alumno){
    //return NULL;
}

int Serializar(alumno_t alumno, char *cadena, uint32_t espacio) {
    int disponibles = espacio;
    int resultado;  //<! almacena la longitud de la cadena agregada
    int largo = 0;  //<! mide el largo de la cadena

    *cadena = '{';  //<! cadena[0] = '{';  equivalentemente 
    cadena++;

    disponibles--;
    resultado = SerializarCadena("apellido",alumno->apellido, cadena, disponibles);

    if (resultado > 0){
        disponibles -= resultado;   //<! resta 'resultado' a 'disponibles'
        cadena += resultado;        //<! suma 'resultado' a 'cadena'
        largo += resultado;         //<! suma 'resultado' a 'largo'
        resultado = SerializarCadena("nombre",alumno->nombre, cadena, disponibles);
    }
    if (resultado > 0){
        disponibles -= resultado; 
        cadena += resultado;
        resultado = SerializarNumero("documento",alumno->documento, cadena, disponibles);
    }
    if(resultado > 0){
        cadena += resultado;
        *(cadena - 1) = '}';  //<! cadena[resultado-1] = '}';  equivalentemente
        //esto es posible porque se hacen todos los 'if' si 'SerializarCadena' != -1 siempre
        resultado = espacio - disponibles;  
    }

    return resultado;
}


/*---  End of File  ---------------------------------------------------------------------------- */
