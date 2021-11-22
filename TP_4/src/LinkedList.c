
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../inc/LinkedList.h"


static Node* getNode(LinkedList* this, int nodeIndex);
static int addNode(LinkedList* this, int nodeIndex,void* pElement);

/** \brief Crea un nuevo LinkedList en memoria de manera dinamica
 *
 *  \param void
 *  \return LinkedList* Retorna (NULL) en el caso de no conseguir espacio en memoria
 *                      o el puntero al espacio reservado
 */
LinkedList* ll_newLinkedList(void)
{
    LinkedList* this; //Puntero a LL
    this = (LinkedList*)malloc(sizeof(LinkedList)); //Asigno espacio en memoria con malloc

    if(this != NULL) //Verifica que sea distinto de NULL para indicar que asigno espacio en memoria correctamente
    {
        this -> size = 0; //Inicializo en 0
        this -> pFirstNode = NULL; //Inicializo en NULL
    }

    return this;
}

/** \brief Retorna la cantidad de elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna (-1) si el puntero es NULL o la cantidad de elementos de la lista
 *
 */
int ll_len(LinkedList* this)
{
    int returnAux = -1; //Variable de retorno

    if (this != NULL) //Verifico que sea distinto de NULL
    {
        returnAux = this -> size; //Le asigno a la variable returnAux el valor asociado a la LL
    }

    return returnAux; //Retorna el valor de la variable
}


/** \brief  Obtiene un nodo de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pNode) Si funciono correctamente
 *
 */
static Node* getNode(LinkedList* this, int nodeIndex)
{
    Node* pNode = NULL; //Variable de retorno

    if(this != NULL) //Verifico que this sea distinto de NULL
    {
        if (nodeIndex >= 0 && nodeIndex < ll_len(this))
        {
            pNode = this -> pFirstNode;

            for(int i = 0; i < nodeIndex; i++) //Recorro hasta que encuentre el indice a buscar
            {
                pNode = pNode -> pNextNode; //Le asigno el valor del siguiente nodo
            }
        }
    }

    return pNode;
}

/** \brief  Permite realizar el test de la funcion getNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
Node* test_getNode(LinkedList* this, int nodeIndex)
{
    return getNode(this, nodeIndex);
}


/** \brief Agrega y enlaza un nuevo nodo a la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
static int addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    int returnAux = -1; //Variable de retorno
    Node* pNewNode = malloc(sizeof(Node)); //Creo espacio en memoria para un nuevo nodo
    Node* pActualNode = NULL; //Inicializo el nuevo nodo en NULL

    pNewNode -> pElement = pElement;

    if(this != NULL && nodeIndex >= 0 && nodeIndex <= ll_len(this) && pNewNode!= NULL)
    {
        if(nodeIndex == 0)
        {
            pNewNode -> pNextNode = this -> pFirstNode;
            this -> pFirstNode = pNewNode;
            this -> size ++;
            returnAux = 0;
        }
        else
        {
            pActualNode = getNode(this, nodeIndex - 1);
            pNewNode -> pNextNode = pActualNode -> pNextNode;
            pActualNode -> pNextNode = pNewNode;
            this -> size ++;
            returnAux = 0;
        }
    }

    return returnAux;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
  * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int test_addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    return addNode(this,nodeIndex,pElement);
}


/** \brief  Agrega un elemento a la lista
 * \param pList LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento a ser agregado
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_add(LinkedList* this, void* pElement)
{
    int returnAux = -1; //Variable de retorno

    if (this != NULL) //Verifico que this sea distinto de NULL
    {
        returnAux = addNode(this, this -> size, pElement);
    }

    return returnAux;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a obtener
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_get(LinkedList* this, int index)
{
    void* returnAux = NULL; //Variable de retorno
    Node* pNode;

    if(this != NULL) //Verifico que this sea distinto de NULL
    {
        if (index >= 0 && index < ll_len(this))//Verifico que this sea distinto de NULL
        {
            pNode = getNode(this, index);
            returnAux = pNode -> pElement;
        }
    }

    return returnAux;
}


/** \brief Modifica un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a modificar
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_set(LinkedList* this, int index,void* pElement)
{
    int returnAux = -1; //Variable de retorno
    Node* pNewNode;

    if(this != NULL && index >= 0 && index < ll_len(this)) //Verifico que this sea distinto de NULL
    {
        pNewNode = getNode(this, index);
        if(pNewNode != NULL)
        {
            pNewNode -> pElement = pElement;
            returnAux = 0;
        }
    }

    return returnAux;
}


/** \brief Elimina un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a eliminar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_remove(LinkedList* this,int index)
{
    int returnAux = -1; //Variable de retorno
    Node* pNodeA = NULL;
    Node* pNodeB = NULL;

    if(this != NULL && index >= 0 && index < ll_len(this) && ll_len(this) > 0)
    {
        if(index != 0 && index != (ll_len(this)))
        {
            pNodeB = getNode(this, (index - 1));
            pNodeA = getNode(this, index);
            pNodeB -> pNextNode = pNodeA -> pNextNode;
            free(pNodeA);
        }
        else
        {
            if (index == 0)
            {
                pNodeA = getNode(this, index);
                this -> pFirstNode = pNodeA -> pNextNode;
                free(pNodeA);
            }
            else
            {
                if (index!=0 && index == (ll_len(this)))
                {
                    free(pNodeA);
                }
            }
        }
        this -> size--;
        returnAux = 0;
    }

    return returnAux;
}


/** \brief Elimina todos los elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_clear(LinkedList* this)
{
    int returnAux = -1; //Variable de retorno

    if(this != NULL) //Verifico que sea distinto de NULL
    {
        for(int i = ll_len(this); i >= 0; i--)
        {
            ll_remove(this, i - 1);
        }
        returnAux = 0;
    }

    return returnAux;
}


/** \brief Elimina todos los elementos de la lista y la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_deleteLinkedList(LinkedList* this)
{
    int returnAux = -1; //Variable de retorno

    if(this != NULL) //Verifico que sea distinto de NULL
    {
        ll_clear(this);
        free(this);
        returnAux = 0;
    }

    return returnAux;
}

/** \brief Busca el indice de la primer ocurrencia del elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        (indice del elemento) Si funciono correctamente
 *
 */
int ll_indexOf(LinkedList* this, void* pElement)
{
    int returnAux = -1; //Variable de retorno
    Node* pNodeAux = NULL;

    if(this != NULL) //Verifico que sea distinto de NULL
    {
        for (int i = 0; i < ll_len(this); i++)
        {
            pNodeAux = getNode(this, i);
            if (pNodeAux -> pElement == pElement)
            {
                returnAux = i;
                break;
            }
        }
    }

    return returnAux;
}

/** \brief Indica si la lista esta o no vacia
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si la lista NO esta vacia
                        ( 1) Si la lista esta vacia
 *
 */
int ll_isEmpty(LinkedList* this)
{
    int returnAux = -1; //Variable de retorno

    if(this != NULL) //Verifico que sea distinto de NULL
    {
        if(ll_len(this) > 0)
        {
            returnAux = 0;
        }
        else
        {
            returnAux = 1;
        }
    }

    return returnAux;
}

/** \brief Inserta un nuevo elemento en la lista en la posicion indicada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo elemento
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_push(LinkedList* this, int index, void* pElement)
{
    int returnAux = -1; //Variable de retorno

    if (this != NULL && index >= 0 && index <= ll_len(this))
    {
        returnAux = addNode(this, index, pElement);
    }

    return returnAux;
}


/** \brief Elimina el elemento de la posicion indicada y retorna su puntero
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento eliminar
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_pop(LinkedList* this,int index)
{
    void* returnAux = NULL; //Variable de retorno

    if (this != NULL && index >= 0 && index <= ll_len(this))
    {
        returnAux = ll_get(this, index);
        if(returnAux != NULL)
        {
            ll_remove(this, index);
        }
    }

    return returnAux;
}


/** \brief  Determina si la lista contiene o no el elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero del elemento a verificar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 1) Si contiene el elemento
                        ( 0) si No contiene el elemento
*/
int ll_contains(LinkedList* this, void* pElement)
{
    int returnAux = -1; //Variable de retorno
    Node* pNodeAux = NULL;

    if(this != NULL) //Verifico que sea distinto de NULL
    {
        returnAux = 0;
        for(int i = 0; i < ll_len(this); i++)
        {
            pNodeAux = getNode(this, i);
            if(pNodeAux -> pElement == pElement)
            {
                returnAux = 1;
                break;
            }
        }
    }

    return returnAux;
}

/** \brief  Determina si todos los elementos de la lista (this2)
            estan contenidos en la lista (this)
 *
 * \param this LinkedList* Puntero a la lista
 * \param this2 LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si alguno de los punteros a las listas son NULL
                        ( 1) Si los elementos de (this2) estan contenidos en la lista (this)
                        ( 0) si los elementos de (this2) NO estan contenidos en la lista (this)
*/
int ll_containsAll(LinkedList* this,LinkedList* this2)
{
    int returnAux = -1; //Variable de retorno
    void* pAuxiliar = NULL;
    int indice;

    if (this != NULL && this2 != NULL)
    {
        returnAux = 1;
        for(int i = 0; i < ll_len(this2); i++)
        {
            pAuxiliar = ll_get(this, i);
            indice = ll_contains(this2, pAuxiliar);
            if (indice == 0)
            {
                returnAux = 0;
                break;
            }
        }
    }

    return returnAux;
}

/** \brief Crea y retorna una nueva lista con los elementos indicados
 *
 * \param pList LinkedList* Puntero a la lista
 * \param from int Indice desde el cual se copian los elementos en la nueva lista
 * \param to int Indice hasta el cual se copian los elementos en la nueva lista (no incluido)
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                o (si el indice from es menor a 0 o mayor al len de la lista)
                                o (si el indice to es menor o igual a from o mayor al len de la lista)
                         (puntero a la nueva lista) Si ok
*/
LinkedList* ll_subList(LinkedList* this,int from,int to)
{
    LinkedList* cloneArray = NULL; //Variable de retorno
    void* pAuxiliar = NULL;

    if(this != NULL && from >= 0 && from < ll_len(this) && to >= 0 && to <= ll_len(this))
    {
        cloneArray = ll_newLinkedList();
        for (int i = from; i < to; i++)
        {
            pAuxiliar = ll_get(this, i);
            ll_add(cloneArray, pAuxiliar);
        }
    }

    return cloneArray;
}



/** \brief Crea y retorna una nueva lista con los elementos de la lista pasada como parametro
 *
 * \param pList LinkedList* Puntero a la lista
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                (puntero a la nueva lista) Si ok
*/
LinkedList* ll_clone(LinkedList* this)
{
    LinkedList* cloneArray = NULL; //Variable de retorno

    if(this != NULL) //Verifico que sea distinto de NULL
    {
        cloneArray = ll_subList(this, 0, ll_len(this));
    }

    return cloneArray;
}


/** \brief Ordena los elementos de la lista utilizando la funcion criterio recibida como parametro
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \param order int  [1] Indica orden ascendente - [0] Indica orden descendente
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                                ( 0) Si ok
 */
int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order)
{
    int returnAux = -1; //Variable de retorno
    void* pElementA = NULL;
    void* pElementB = NULL;
    void* pAuxiliar = NULL;
    if(this != NULL && pFunc != NULL && (order == 1 || order == 0))
    {
        for(int i = 0; i < ll_len(this) - 1; i++)
        {
            pElementA = ll_get(this, i);
            for(int j = i + 1; j < ll_len(this); j++)
            {
                pElementB = ll_get(this, j);
                if(order == 0)
                {
                    if(pFunc(pElementA, pElementB) < 0)
                    {
                        pAuxiliar = pElementB;
                        pElementB = pElementA;
                        pElementA = pAuxiliar;
                    }
                }
                else
                {
                    if(pFunc(pElementA, pElementB) > 0)
                    {
                        pAuxiliar = pElementB;
                        pElementB = pElementA;
                        pElementA = pAuxiliar;
                    }
                }
                ll_set(this, i, pElementA);
                ll_set(this, j, pElementB);
            }
        }
        returnAux = 0;
    }
    return returnAux;

}

int ll_map(LinkedList* this, void (*pFunc)(void*))
{
    int retorno = -1;
    void* pElement = NULL;

    if(this != NULL && pFunc != NULL)
    {
        for(int i = 0; i < ll_len(this); i++)
        {
            pElement = ll_get(this, i);
            pFunc(pElement);
            retorno = 0;
        }
    }
    return retorno;
}



LinkedList* ll_filter(LinkedList* this, int (*pFunc)(void*))
{
    LinkedList* this2 = NULL; //Variable de retorno
    void* pElement = NULL;

    if(this != NULL && pFunc != NULL && !ll_isEmpty(this))
    {
        this2 = ll_newLinkedList();
        for(int i = 0; i < ll_len(this); i++)
        {
            pElement = ll_get(this, i);
            if(pFunc(pElement))
            {
                ll_add(this2, pElement);
            }
        }
    }

    return this2;
}

