#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"


static Node* getNode(LinkedList* this, int nodeIndex);
static int addNode(LinkedList* this, int nodeIndex,void* pElement);


LinkedList* ll_newLinkedList(void)
{
    LinkedList* this = NULL;
    this = (LinkedList*) malloc(sizeof(LinkedList));
    if(this!=NULL){
        this->pFirstNode=NULL;  //inicializo direccion de memoria pero en NULL - si no apuntaria a basura y rompe
        this->size=0;           //inicializo size en 0
    }

    return this;
}


int ll_len(LinkedList* this)
{
    int returnAux = -1;
    if(this !=NULL){
        returnAux= this->size;
    }
    return returnAux;
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
    Node* pNode = NULL;
    if(this!=NULL && nodeIndex>=0 && nodeIndex< ll_len(this)){
        /*if(nodeIndex==0){
            pNode = this->pFirstNode;
        }else{*/
            /*auxNode=this->pFirstNode; //direccion de vagon 0
            auxNode->pNextNode      // direccion de vagon 1
            auxNode = auxNode->pNextNode;   //direccion de vagon 2
            pNode = auxNode;*/
            pNode = this->pFirstNode;
            while(nodeIndex>0){     //saco el if por que jamas va a entrar cuando valga 0, entonces retorna lo anterior si el indice es 0
                pNode = pNode->pNextNode;
                nodeIndex--;
            }
        }
    //}
    return pNode;
}


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
    int returnAux = -1;
    Node* newNode = NULL;
    Node* anterior = NULL;
    if(this!=NULL && nodeIndex<=ll_len(this)){ //pElement no lo validamos para el TP.
        newNode = (Node*) malloc(sizeof(Node));
        if(newNode!=NULL){
            newNode->pElement=pElement;
            newNode->pNextNode = getNode(this, nodeIndex);
            if(nodeIndex==0){
                this->pFirstNode = newNode; //si lo quiere agregar en index =0 entra aca
            }else{
                //si el index es distinto de cero, usamos pNextNode (con el getNode teniendo en cuenta el nodo de adelante)
                anterior = getNode(this, nodeIndex-1);
                anterior->pNextNode = newNode;
            }

            this->size++;
            returnAux=0;
        }
    }

    return returnAux;
}


int test_addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    return addNode(this,nodeIndex,pElement);
}



int ll_add(LinkedList* this, void* pElement)    //agrega al final
{

        return addNode(this, ll_len(this), pElement);

}


void* ll_get(LinkedList* this, int index)
{
    void* returnAux = NULL;
    Node* nodo =NULL;
    if(this!=NULL && index>=0 && index<ll_len(this)){
        nodo= getNode(this, index);
        if(nodo!=NULL){
            returnAux = nodo->pElement;
        }
    }

    return returnAux;
}



int ll_set(LinkedList* this, int index,void* pElement)
{
    int returnAux = -1;
    Node* aux = NULL;
    if(this!=NULL && index>=0 && index<ll_len(this))
    {
        aux = getNode(this, index);
        if(aux!=NULL){
            aux->pElement =pElement;
            returnAux=0;
        }

    }

    return returnAux;
}



int ll_remove(LinkedList* this,int index)
{
    int returnAux = -1;
    Node* nodeToRemove=NULL;
    Node* previousNode=NULL;
    if(this!=NULL && index>=0 && index<ll_len(this))
    {
        nodeToRemove=getNode(this,index);
        if(nodeToRemove!=NULL){
            if(index==0){
                this->pFirstNode=nodeToRemove->pNextNode;

            }else{
                previousNode=getNode(this,index-1);

                    previousNode->pNextNode= nodeToRemove->pNextNode;

            }
            free(nodeToRemove);
                    this->size--;
                    returnAux=0;
        }

    }
    return returnAux;
}



int ll_clear(LinkedList* this)
{
    int returnAux = -1;
    if(this!=NULL){
        while(ll_len(this)){
            returnAux = ll_remove(this, 0);
            if(returnAux){
                break;
            }
        }

    }

    return returnAux;
}



int ll_deleteLinkedList(LinkedList* this)
{
    int returnAux = -1;
    if(this!=NULL){
        if(!ll_clear(this)){
            free(this);
            returnAux=0;
        }
    }

    return returnAux;
}


int ll_indexOf(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    if(this!=NULL){
        for(int i =0; i<ll_len(this); i++){
            if(ll_get(this, i)== pElement){
                returnAux=i;
                break;
            }
        }
    }
    return returnAux;
}


int ll_isEmpty(LinkedList* this)
{
    int returnAux = -1;
    if(this!=NULL){
            int tam = ll_len(this);
        if(tam){
            if(tam>0){
                 returnAux=0;
            }

        }else{
            returnAux=1;
        }
    }

    return returnAux;
}


int ll_push(LinkedList* this, int index, void* pElement)
{
    return addNode(this, index, pElement);
}



void* ll_pop(LinkedList* this,int index)
{
    void* returnAux = NULL;
    if(this!=NULL && index>=0 && index<ll_len(this)){
        returnAux = ll_get(this, index);
        ll_remove(this, index);
    }

    return returnAux;
}



int ll_contains(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    if(this!=NULL){
        returnAux =0;
        if(ll_indexOf(this, pElement)!= -1){
            returnAux=1;
        }
    }

    return returnAux;
}


int ll_containsAll(LinkedList* this,LinkedList* this2)
{
  int returnAux = -1;
  void* aux;
    if(this!=NULL && this2!=NULL)
    {
        returnAux =1;
        int tam = ll_len(this2);

        for(int i=0; i<tam; i++){   //recorro this2

            aux = ll_get(this2, i);
            if(!ll_contains(this,aux))  //cuando encuentro un elemento que no este en la lista, ahi salgo )break) para no recorrerlo todo
            {
                returnAux=0;
                break;
            }

        }
    }

    return returnAux;
}


LinkedList* ll_subList(LinkedList* this,int from,int to)
{
    LinkedList* cloneArray = NULL;
    if(this!=NULL && from<=to && from >=0 && to <=ll_len(this)){
        cloneArray = ll_newLinkedList();
        if(cloneArray!=NULL){
            for(int i = from; i<to; i++ ){
                ll_add(cloneArray, ll_get(this, i));
            }
        }
    }
    return cloneArray;
}




LinkedList* ll_clone(LinkedList* this)
{
    return ll_subList(this, 0, ll_len(this));
}



int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order)
{
    int returnAux =-1;
    void* aux = NULL;
    if(this!=NULL && pFunc!=NULL && order>=0 && order <=1){
        int tam = ll_len(this);
        for(int i = 0; i<tam-1; i++){
            for(int j = i+1; j<tam; j++){
                if((pFunc(ll_get(this,i), ll_get(this,j))>0 && order) || (pFunc(ll_get(this,i), ll_get(this,j))<0 && !order)){
                    aux = ll_get(this, i);
                    ll_set(this,i,ll_get(this,j));
                    ll_set(this, j, aux);
                }
            }
        }
        returnAux=0;
    }
    return returnAux;

}


LinkedList* ll_filter(LinkedList* this, int (*pFunc) (void* pElement)){
    LinkedList* filterArray=NULL;
    int tam;
    if(this!=NULL && pFunc!=NULL){
        filterArray=ll_newLinkedList();
        if(filterArray!=NULL){
            tam=ll_len(this);
            for(int i =0; i<tam; i++){
                    if(pFunc(ll_get(this, i))){
                       if(ll_add(filterArray, ll_get(this, i))){
                            ll_deleteLinkedList(filterArray);
                            filterArray=NULL;

                       }
                    }
            }
        }
    }
    return filterArray;
}


LinkedList* ll_map(LinkedList *this, void* (*pFunc)(void* pElement))
{
    LinkedList* listaMapeada = NULL;
    int tam;
    void* aux= NULL;;
    if(this!=NULL && pFunc!=NULL)
    {
        tam = ll_len(this);
        listaMapeada=ll_newLinkedList();
        if(listaMapeada!=NULL)
        {
            for(int i =0; i<tam; i++)
            {
                aux=ll_get(this,i);
                if(pFunc(aux))
                {
                    if(ll_add(listaMapeada,aux)){

                        ll_deleteLinkedList(listaMapeada);
                        listaMapeada=NULL;
                        break;
                    }
                }

            }
        }
    }

    return listaMapeada;
}
