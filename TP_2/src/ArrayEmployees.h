#define CHARSIZE 51
typedef struct
{
    int id;
    char name [CHARSIZE];
    char lastName [CHARSIZE];
    float salary;
    int sector;
    int isEmpty;

}sEmployee;


/** \brief To indicate that all position in the array are empty,
* this function put the flag (isEmpty) in TRUE in all
* position of the array
* \param list Employee* Pointer to array of employees
* \param len int Array length
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int initEmployees(sEmployee* list, int len);

/** \brief add in a existing list of employees the values received as parameters in the first empty position.
 * \param list employee* Pointer to array of employees
 * \param len int Array length
 * \param id int Id number
 * \param name[] char Name array
 * \param lastName[] char Last name array
 * \param salary float salary number
 * \param sector int Sector number
 * \return Return -1 if error (NULL or invalid), 0 if no error
 */
int addEmployee (sEmployee[], int, int, char[], char[], float, int);

/** \brief Gets free space from the index
 *
 * \param list employee* Pointer to array of employees
 * \param len int Array length
 * \return Return -1 if error (NULL or invalid), 0 if no error
 *
 */
int findEmptySpace (sEmployee[], int);

/** \brief find an sEmployee by Id en returns the index position in array.
 * \param list sEmployee* Pointer to array of employees
 * \param len int Array length
 * \param id int Id number
 * \return Return -1 if error (NULL or invalid), 0 if no error
 */
int findEmployeeById (sEmployee[], int, int);

/** \brief Find an employee by id and asks what wants the user to modify
 *
 * \param list sEmployee* Pointer to array of employees
 * \param len int Array length
 * \return Return modified data
 *
 */
int modifyEmployee (sEmployee[], int);

/** \brief Remove a sEmployee by Id (put isEmpty Flag in 1).
 * \param list sEmployee* Pointer to array of employees
 * \param len int Array length
 * \param id int Id number
 * \return Return -1 if error (NULL or invalid), 0 if no error
 */
int removeEmployee (sEmployee[], int, int);

/** \brief print the content of employees array.
 * \param list sEmployee* Pointer to array of employees
 * \param length int Array length
 * \return int.
 */
int printEmployees (sEmployee[], int);

/** \brief Sort the elements in the array of employees, the argument order indicate ascendent or descendant order.
 * \param list sEmployee* Pointer to array of employees
 * \param len int Array length
 * \param order int 1 for ascendente, 2 for descendente
 * \return Return -1 if error (NULL or invalid), 0 if no error
 */
int sortEmployeeByName (sEmployee[], int, int);

/** \brief Shows the total amount of salaries, the average of salaries and all employees with salaries greater than the average
 *
 * \param list sEmployee* Pointer to array of employees
 * \param len int Array length
 * \return void
 *
 */
void averageEmployeesSalary (sEmployee[], int);

/** \brief Verifies if there's at least one employee in the array
 *
 * \param list sEmployee* Pointer to array of employees
 * \param len int Array length
 * \return 0 if there's no emplotee, 1 if there's at least one
 *
 */
int existEmployees (sEmployee[], int);

/**
 * \brief Ask the user a character and returns the result
 * \param message Message to be shown
 * \return Character that user gave
 *
 */
char getChar(char[]);

/**
 * \brief Verifies if value is numeric and can get floats
 * \param str Array with string to be initialized
 * \return 1 if it's numeric, 0 if is not
 *
 */
int isNumericFloat(char[]);

/**
 * \brief Verifies if entered value is a number
 * \param str Array with string to be initialized
 * \return 1 if it's numeric, 0 if is not
 *
 */
int isNumeric(char[]);

/**
 * \brief Verifies if entered value only contains letters
 * \param str Array with string to be initialized
 * \return 1 If it only contains ' ' and letters, 0 if is not
 *
 */
int isOnlyLetters(char[]);

/**
 * \brief Asks the user for a text and returns it
 * \param message Message to be shown
 * \param input Array where entered text is charged
 * \return void
 */
void getString(char [],char []);

/**
 * \brief Asks the user for a text and returns it
 * \param message Message to be shown
 * \param input Array where entered text is charged
 * \return 1 if text is only letters
 */
int getStringLetters(char [],char[]);

/**
 * \brief Ask the user for a numbered text and returns it
 * \param message Message to be shown
 * \param input Array where entered text is charged
 * \return 1 if text is only numbers
 */
int getStringNumbers(char [],char[]);

/**
 * \brief Ask the user for a numbered text and returns it (accepts float)
 * \param message Message to be shown
 * \param input Array where entered text is charged
 * \return 1 if text is only numbers
 */
int getStringFloatNumbers(char[],char[]);

/**
 * \brief Ask for an integer number
 * \param requestMessage Message to be shown to ask for the number
 * \param requestMessage Message to be shown in case of error
 * \return Number entered by the user
 *
 */
int getValidInt(char[],char[], int, int);

/**
 * \brief Asks fot a float number and verifies it
 * \param requestMessage Message to be shown to ask for the number
 * \param requestMessage Message to be shown in case of error
 * \return Number entered by the user
 *
 */
int getValidFloat(char[],char [], int, int);

/**
 * \brief Asks for a string
 * \param requestMessage Message to be shown to ask for the number
 * \param requestMessage Message to be shown in case of error
 * \param input Array where entered text is charged
 * \return -
 *
 */
void getValidString(char[],char[], char[]);

/**
 * \brief Cleans the stdin, similar to fflush
 * \param -
 * \return -
 *
 */
void cleanStdin(void);
