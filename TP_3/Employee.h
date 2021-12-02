#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    float sueldo;
}Employee;

/** \brief Almacena un espacio en memoria dinamica para un empleado
 *
 * \param -
 * \param -
 * \return retorna el empleado
 */
Employee* employee_new();

/** \brief Creo nuevos empleados con parametros
 *
 * \param char* idStr Id generado
 * \param char* nombreStr Nombre generado
 * \param char* horasTrabajadasStr Horas trabajadas generadas
 * \param char* sueldoStr Sueldo
 * \return retorna la direccion del empleado
 *
 */
Employee* employee_newParametros(char* idStr, char* nombreStr, char* horasTrabajadasStr, char* sueldoStr);

/** \brief Libera espacio de un empleado eliminado
 *
 * \param -
 * \return -
 *
 */
void employee_delete(Employee* this);

/** \brief Valida el id
 *
 * \param Employee* this Puntero del array de empleados
 * \param int id recibe una cantidad de id
 * \return retorno, si esta bien es 1, si esta mal es 0
 *
 */
int employee_setId(Employee* this, int id);

/** \brief Me escribe el parametro del id en el argumento pasado
 *
 * \param Employee* this Puntero del array de empleados
 * \param int* id recibe un puntero al id
 * \return retorno, si esta bien es 1, si esta mal es 0
 *
 */
int employee_getId(Employee* this, int* id);

/** \brief Valida el Nombre
 *
 * \param Employee* this Puntero del array de empleados
 * \param char* nombre recibe un nombre
 * \return retorno, si esta bien es 1, si esta mal es 0
 *
 */
int employee_setNombre(Employee* this, char* nombre);

/** \brief Me escribe el parametro del nombre en el argumento pasado
 *
 * \param Employee* this Puntero del array de empleados
 * \param char* nombre Recibe un nombre
 * \return retorno, si esta bien es 1, si esta mal es 0
 *
 */
int employee_getNombre(Employee* this, char* nombre);

/** \brief Valida las horas de trabajo
 *
 * \param Employee* this Puntero del array de empleados
 * \param int horasTrabajadas Recibe una cantidad de horas de trabajo
 * \return retorno, si esta bien es 1, si esta mal es 0
 *
 */
int employee_setHorasTrabajadas(Employee* this, int horasTrabajadas);

/** \brief Me escribe el parametro de las horas trabajadas en el argumento pasado
 *
 * \param Employee* this Puntero del array de empleados
 * \param int* horasTrabajadas Recibe un puntero a las horas trabajadas
 * \return retorno, si esta bien es 1, si esta mal es 0
 *
 */
int employee_getHorasTrabajadas(Employee* this, int* horasTrabajadas);

/** \brief Valida el sueldo
 *
 * \param Employee* this Puntero del array de empleados
 * \param float sueldo Recibe una cantidad de sueldo
 * \return retorno, si esta bien es 1, si esta mal es 0
 *
 */
int employee_setSueldo(Employee* this, float sueldo);

/** \brief Me escribe el parametro del sueldo en el argumento pasado
 *
 * \param Employee* this Puntero del array de empleados
 * \param float* sueldo recibe un puntero del sueldo
 * \return retorno, si esta bien es 1, si esta mal es 0
 *
 */
int employee_getSueldo(Employee* this, float* sueldo);

/** \brief Valida el id
 *
 * \param Employee* empleado Puntero del array de empleados
 * \return -
 *
 */
void mostrarEmpleado(Employee* empleado);

/** \brief Compara dos parametros que serian string (por el nombre)
 *
 * \param void* empleadoA
 * \param void* empleadoB
 * \return retorno Devuelve la comparacion de los dos parametros, o devuelve 0 si falla
 *
 */
int employeeSortByName(void* empleadoA, void* empleadoB);

/** \brief Compara dos parametros que serian int (por el id)
 *
 * \param void* empleadoA
 * \param void* empleadoB
 * \return retorno Devuelve 1 si el empleadoA es igual a empleado B, devuelve -1 si el empleadoA es mayor al empleado B y devuelve 1 si el empleadoA es menor al empleado B
 *
 */
int employeeSortById(void* empleadoA, void* empleadoB);

/** \brief Compara dos parametros que serian int (por las horas trabajadas)
 *
 * \param void* empleadoA
 * \param void* empleadoB
 * \return retorno Devuelve 1 si el empleadoA es igual a empleado B, devuelve -1 si el empleadoA es mayor al empleado B y devuelve 1 si el empleadoA es menor al empleado B
 *
 */
int employeeSortByWorkHours(void* empleadoA, void* empleadoB);

/** \brief Compara dos parametros que serian float (por el salario)
 *
 * \param void* empleadoA
 * \param void* empleadoB
 * \return retorno Devuelve 1 si el empleadoA es igual a empleado B, devuelve -1 si el empleadoA es mayor al empleado B y devuelve 1 si el empleadoA es menor al empleado B
 *
 */
int employeeSortBySalary(void* empleadoA, void* empleadoB);

#endif // employee_H_INCLUDED
