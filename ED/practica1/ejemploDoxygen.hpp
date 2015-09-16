#ifndef __LISTA_SIMPLE_LIMITADA_HPP__
#define __LISTA_SIMPLE_LIMITADA_HPP__

/*!
   \brief Espacio de nombres para la asignatura Estructura de datos.

*/
namespace ed 
{

  /*!\brief Clase para definir una lista limitada de elementos genéricos G.

  Define una colección de elementos G organizados de manera secuencial. 
  Cada elemento puede tener un anterior y un siguiente
  

  \inv estaVacia() implica not estaLlena()
  
  \inv estaVacia() implica numeroElementos() == 0
*/
template<class G>
class ListaSimpleLimitada
{
  public:

  /*!\name Creadores:
  @{
  */
	/*!\brief Crea una lista simple limitada vacía 
    Crea una lista vacía con capacidad c
    \arg[in] c
    \pre c > 0
    \post estaVacia()
    \post not estaLlena()
  */
	
	ListaSimpleLimitada(int c);
	
	/* @}*/
	
	/*!\name Observadores:
	@{
	*/
	/*!\brief Comprueba si la lista está vacía.
    \return true si la lista está vacía y false si no lo está.
  */
  bool estaVacia() const;
	
	/*!\brief Comprueba si la lista está llena.
    \return true si la lista está llena y false si no lo está.
    \post estaLlena() implica numeroItems() == capacidad()
    \post not estallena() implica numeroItems() < capacidad()
  */
	
	bool estaLlena() const;
	
	/*!\brief Devuelve el primer item de la lista
		\return el primer item de la lista si no está vacía
		\pre not estaVacia()
	*/
	const G & primerItem() const;
	
	/*!\brief Devuelve la capacidad de la lista
		\return capacidad de la lista
	*/
	int capacidad() const;

	/*!\brief Devuelve el número de items de la lista
		\return devuelve el número de items de la lista
		\post 0 <= retVal <= capacidad()
	*/
	int numeroItems() const;
	
	/* @}*/
	
	/*!\name Modificadores:
	 @{
	*/
	
  /*!\brief Inserta un elemento en la lista.

    Inserta un elemento como primero de la lista  
		
    \arg[in] item elemento a insertar
    \pre not estaLlena()
    \post not estaVacia().
    \post primerItem() == item
    \post numeroElementos() == old.numeroElementos() + 1

  */
  void insertaPrimero(const G &item);
  

  /*!\brief Borra primer elemento de la lista.

    Borra el primer elemento de la lista si no está vacía
  
    \pre not estaVacia()
    \post numeroElementos() == old.numeroElementos() - 1
					
  */
  void borraPrimero();  
  /*!@}*/
	
	private:

};


} //namespace ed

#endif //__LISTA_ORDENADA_HPP__

