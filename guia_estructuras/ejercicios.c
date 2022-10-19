#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>

/*
ej1
Definir las estructuras que se piden en los siguientes incisos:

Una estructura para manejar inventarios que contenga un campo para la descripción del producto (máximo 30 caracteres), un número para el número de parte en el inventario, un punto flotante para el precio, un entero para la cantidad que hay en el almacén y un entero para el lugar donde se almacena.
Una para manejar una dirección física que contiene arreglos para el país (máximo 40 caracteres), la provincia (máximo 30 caracteres), la ciudad (máx. 20), la dirección (máx. 30) y el código postal (10).
Una persona, con un arreglo para el nombre, otro para el apellido y una estructura como la del inciso anterior.
Una estructura, registro, que nos sirva para mantener un registro de los consumos de un vehículo, como en el último ejercicio de la guía 1. Para ello, debe contener un número para almacenar una cantidad de kilómetros, un número real para almacenar el costo del combustible, un número real para almacenar el dinero utilizado en una recarga, un time_t para almacenar la fecha, un booleano para indicar si se llenó el tanque y un arreglo para almacenar algún comentario.
*/

typedef struct inventario_t{
    char descripcion[30];
    int numeroParte;
    float precio;
    int cantidad;
    int lugar;
}inventario_t;

typedef struct direccion_t{
    char pais[40];
    char provincia[30];
    char ciudad[20];
    char direccion[30];
    char codigoPostal[10];
}direccion_t;

typedef struct persona_t{
    char nombre[30];
    char apellido[30];
    direccion_t direccion;
}persona_t;



typedef struct registro_t{
    int kilometros;
    float costoCombustible;
    float dineroRecarga;
    time_t fecha;
    bool llenoTanque;
    char comentario[100];
}registro_t;


/*
ej2
Definir una estructura punto que contenga las coordenadas de un punto en .
Definir un nuevo tipo utilizando la definición de la estructura punto.
Implementar una función que reciba dos estructuras punto y calcule la distancia euclídea entre ambos puntos. 
Implementar la función del inciso c ¡pero ahora validando!
*/

struct punto
{
    double x;
    double y;
};

typedef struct punto punto;

typedef enum{
    ST_OK,
    ST_NOT_OK
}status_t;

status_t distancia(punto* a,punto* b, double* result){
    if(a == NULL || b == NULL || result == NULL){
        return ST_NOT_OK;
    }else{
        //(*result) = sqrt((a->x - b->x)*(a->x - b->x) + (a->y - b->y)*(a->y - b->y)); /* por formula de distancia euclidea*/
        result = 0;
    }

}


/*
Estamos armando nuestra propia plaforma social y decidimos que vamos a permitir que las personas se envíen mensajes que a lo sumo tengan 143 caracteres. Para ello, vamos a utilizar una estructura. La misma tiene que tener un número no signado que identifica al mensaje dentro de los millones y millones de mensajes que nos van a mandar, un time_t para la fecha, un arreglo para almacenar el mensaje y un arreglo para almacenar el nombre de usuario de quien lo publica.

Definir la estructura del enunciado.
Implementar una función que tome un mensaje y lo publique en la terminal, con el siguiente formato:


YYYY-MM-DD HH:mm:ss

<MENSAJE>

            Sos lo mejor. Besos. <usuario>
*/

typedef struct message{
    char msg[143];
    time_t date;
    unsigned int id;
    char user[30];
}message;

status_t createMessage(message* msg){
    if(msg == NULL){
        return ST_NOT_OK;
    }else{
        printf("Ingrese el mensaje: ");
        fgets(msg->msg,143,stdin);
        printf("Ingrese el nombre de usuario: ");
        fgets(msg->user,30,stdin);
        
        msg->date = time(NULL);
        msg->id = rand();
    }
}

status_t msg2stdout(message* msg){
    //from msg->date to YYYY-MM-DD HH:mm:ss
    char date[20];
    struct tm * timeinfo;
    timeinfo = localtime(&msg->date);
    strftime(date,20,"%Y-%m-%d %H:%M:%S",timeinfo);
    
    printf("%s\n%s\n\t\t\tSos lo mejor. Besos. %s",date,msg->msg,msg->user);
}

/*
(menú) Volvamos sobre nuestros pasos y rehagamos los menúes.
Definir una estructura que contenga un valor que el usuario tenga que ingresar (puede ser entero, enum, char, cadena) y una cadena con lo que se debe mostrar como mensaje para la opción.
Implementar una función que reciba un vector con estructuras e imprima un menú.
Como variante del inciso anterior, la función puede imprimir el menú, leer lo que se ingresa y retornar la opción seleccionada.
¿Cómo se debe definir la estructura para poder utilizarla de la siguiente manera?


struct nombre_struct vector[] = {
    {1, "Opción primera"}, 
    {6, "Opción segunda"}, 
    {0, "Opción quinta"}   
};
*/
status_t get_valid_int(int* result);


typedef struct menu{
    int value;
    char msg[30];
}menu;

// print array of menus
status_t printMenu(const menu* m, int size){
    if(m == NULL || size <= 0){
        return ST_NOT_OK;
    }
    
    for(int i = 0; i < size; i++){
        printf("%d - %s\n",m[i].value,m[i].msg);
    }

    return ST_OK;
}

status_t menuLoader(const menu* m,const int size, int* result){
    if(ST_OK != printMenu(m,size)|| result == NULL){
        return ST_NOT_OK;
    }
    
    printf("Ingrese una opcion: ");
    
    int aux;
    if(ST_OK != get_valid_int(&aux)){
        return ST_NOT_OK;
    }
    
    for(int i = 0; i < size; i++){
        if(m[i].value == aux){
            *result = aux;
            return ST_OK;
        }
    }

    return ST_NOT_OK;

    return ST_OK;
}

status_t get_valid_int(int* result){
    if (NULL == result) return ST_NOT_OK;
    char buffer[100];
    fgets(buffer, 100, stdin);

    char *endptr = NULL;
    int tempInt = strtol(buffer,&endptr,10);
    
    if (endptr == buffer || *endptr != '\n') return ST_NOT_OK;
    
    *result = tempInt;
    return ST_OK;
}

void ej4(){
    menu menu[] = {
        {1, "Opción primera"}, 
        {2, "Opción segunda"}, 
        {3, "Opción quinta"}   
    };
    //printMenu(menu,3);
    int result;
    
    if (menuLoader(menu,3,&result) == ST_OK){
        printf("El resultado es: %d",result);
    }else{
        printf("Error");
    }
}
//ej4 segunda forma

typedef enum {TIPO_CHAR,TIPO_ENUM,TIPO_INT,TIPO_STR} tipo_t;

struct opcion
{
    tipo_t tipo;
    char c;
    int i;
    bool s;
    const char* str;
    const char* msg;
};

struct option op1 = {.tipo = TIPO_STR,.s = "1", .msg = "Opción primera"};

void imprimir_tipo_str(const struct opcion* op)
{
    if(NULL == 0 || op->tipo != TIPO_STR) return;
    
    printf("%s - %s\n",op->s,op->msg);

}

int menuv2(const struct opcion* op, size_t cant)
{
    if(NULL == op || cant == 0) return -1;
    
    for(size_t i = 0; i < cant; i++)
    {
        switch(op[i].tipo)
        {
            case TIPO_STR:
                imprimir_tipo_str(&op[i]);
                break;
            default:
                break;
        }
    }

}




/*
ej5
(estructuras anidadas) Dada las siguientes definiciones

*/

// struct header {
//     int secuencia;
//     time_t stamp;
//     char * frame;
// };

// struct pose {
//     struct {
//         double x, y, z;
//     } posicion;
//     struct {
//         double qx, qy, qz, qw;
//     } orientacion;
// };

// struct pose_stamped {
//     struct header encabezado;
//     struct pose pose;
// } robot_pose;
/*
Para acceder a cada uno de los campos de las estructuras, escribir una expresión. Por ejemplo, para acceder al campo stamp:


robot_pose.encabezado.stamp
*/

void ej5(){
    struct header {
        int secuencia;
        time_t stamp;
        char * frame;
    };

    struct pose {
        struct {
            double x, y, z;
        } posicion;
        struct {
            double qx, qy, qz, qw;
        } orientacion;
    };

    struct pose_stamped {
        struct header encabezado;
        struct pose pose;
    } robot_pose;
    
    //load robot_pose
    robot_pose.encabezado.secuencia = 1;
    robot_pose.encabezado.stamp = time(NULL);
    robot_pose.encabezado.frame = "frame";
    robot_pose.pose.posicion.x = 1;
    robot_pose.pose.posicion.y = 2;
    robot_pose.pose.posicion.z = 3;
    robot_pose.pose.orientacion.qx = 1;
    robot_pose.pose.orientacion.qy = 2;
    robot_pose.pose.orientacion.qz = 3;
    robot_pose.pose.orientacion.qw = 4;


}





//ej6
//(estructuras anidadas 2) Dadas las siguientes definiciones


struct header {
    int secuencia;
    time_t stamp;
    char * frame;
} header;

struct puntov {
    double x, y, z;
} point;

struct cuaternion {
    double qx, qy, qz, qw;
} quaternion;

struct pose {
    struct puntov * posicion;
    struct cuaternion * orientacion;
} pose;


struct pose_stamped {
    int rr;
    struct header * encabezado;
    struct pose * pose;
} robot_pose, * robot_pose_ptr;
/*
Escribir una porción de código para cargar la estructura robot_pose usando las demás estructuras. 
Luego, para acceder a cada uno de los campos de las estructuras, escribir una expresión. 
Por ejemplo, cualquiera de las siguientes accede al campo stamp, aunque la primera es la más clara:
robot_pose_ptr->encabezado->stamp;
robot_pose.encabezado->stamp;
*(robot_pose.encabezado).stamp;
*((*robot_pose_ptr).encabezado).stamp;
*/

status_t load_robot_pose(struct pose_stamped* robo,  struct header* h,  struct pose* p){
    if(robo == NULL){
        return ST_NOT_OK;
    }

    //load rr
    robo->rr = 459;
    //load header
    robo->encabezado = h;
    //load pose
    robo->pose = p;
}

int main(){

    //ej3
    // message msg;
    // createMessage(&msg);
    // msg2stdout(&msg);
    // return 0;

    //ej4
    struct opcion op1 = {.tipo = TIPO_STR,.s = "1", .msg = "Opción primera"};

    //ej4();

    //ej5

    load_robot_pose(&robot_pose,&header,&pose);
    printf("%d\n",robot_pose.rr);
    printf("%d\n",robot_pose.encabezado->secuencia);
    point.x = 1;

    printf("%f\n",robot_pose.pose->posicion->x);
}