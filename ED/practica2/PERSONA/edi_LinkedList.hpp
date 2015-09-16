#ifndef __EDI_LinkedList_HPP__
#define __EDI_LinkedList_HPP__
 
#include <cassert>
#include <vector>
#include "edi_exports.hpp"
#include "edi_List.hpp"
#include "edi_LinkedNode.hpp"
#include <cstddef>
#include <iostream>

using namespace std;
 
namespace edi {
 
  /** @brief Implement the List[T] ADT as a linked list.*/
  template <class T>
  class EDI_API LinkedList : public edi::List<T>
  {

    private:
      edi::LinkedNode<T> * _head;
      edi::LinkedNode<T> * _curr;
      edi::LinkedNode<T> * _prev;


    public:
      
    /** @name Makers*/
    /**@{*/
      /** @brief Makes a new list.
      * @post isEmpty()
      */
      LinkedList ()
      {
				_head=NULL;
				_curr=NULL;
				_prev=NULL;
      }
  
      virtual ~LinkedList () {
        flush();
	     }
    /**@}*/
    
    /** @name Observers*/
    /**@{*/
      /** @brief Is the list empty?
      * Time analysis: O(1)
      @return true if the list is empty.
      */
      virtual bool isEmpty() const
      {
				return (head()==NULL);
      }
      /** @brief Is pos the last list's position?
      * Time analysis: O(n)
      * @arg[in] pos is the position to be tested.
      * @return true if the position is the last.
      * @pre pos is a valid list's position.
      */

      virtual bool isLast(const int pos) const
      {
				assert(isValid(pos));
				edi::LinkedList<T> * _this = const_cast<edi::LinkedList<T>*>(this);
				edi::LinkedNode<T> * savedCurr=_this->current();
				edi::LinkedNode<T> * savedPrev=_this->previous();
				_this->goTo(pos);
				bool retVal=(current()->next()==NULL);
				_this->setCurrent(savedCurr);
				_this->setPrevious(savedPrev);
				return retVal;
      }
      /** @brief Is pos a valid List's position?
      * Time analysis: O(N)
      * @return true if pos is a valid list's position.
      */
      virtual bool isValid (const int pos) const
      {
				edi::LinkedList<T> * _this = const_cast<edi::LinkedList<T>*>(this);
				edi::LinkedNode<T> * savedCurr=_this->current();
				edi::LinkedNode<T> * savedPrev=_this->previous();
				_this->goTo(pos);
				bool retVal=(current()!=NULL);
				_this->setCurrent(savedCurr);
				_this->setPrevious(savedPrev);
				return retVal;
      }
      /** @brief Get the item at a given position.
      * Time analysis: O(N)
      * @arg[in] pos is the list's position.
      * @return a const reference to the stored.
      * @pre isValid(pos)
      */
      virtual const T& item(const int pos) const
      {
				assert(isValid(pos));
				edi::LinkedList<T> * _this = const_cast<edi::LinkedList<T>*>(this);
				edi::LinkedNode<T> * savedCurr=_this->current();
				edi::LinkedNode<T> * savedPrev=_this->previous();
				_this->goTo(pos);
				const T& retVal= current()->item();
				_this->setCurrent(savedCurr);
				_this->setPrevious(savedPrev);
				return retVal;
      }
      /** @brief Find the position of a given item.
      * Time analysis: O(n)
      * @arg[in] it is the data to be found.
      * @arg[in] from give a position to start the search.
      * @return -1 if it does not found or the item's position.
      * @pre isValid(from)
      * @post retVal>=0 implies isValid(retVal)
      * @post retVal>=0 implies item(retVal)=item
      */
      virtual int findItem(const T& it, const int from=0) const
      {
				assert(isValid(from));
				int retVal=-1;
				edi::LinkedList<T> * _this = const_cast<edi::LinkedList<T>*>(this);
				edi::LinkedNode<T> * savedCurr=_this->current();
				_this->goTo(from);
        for (int i=from; retVal==-1 and _this->current()!=NULL; ++i){
          if (current()->item() == it){
            retVal = i;
          }else{
            _this->setCurrent(_this->current()->next());
            
          }
        }
				_this->setCurrent(savedCurr);
				assert(not (retVal==-1) or isValid(retVal));
				assert(not (retVal==-1) or item(retVal)==it);
				return retVal;
      }
    /**@}*/
 
    /** @name Mutators*/
    /**@{*/
      /** @brief Inserts item before a given position.
      * Time analysis: O(n).
      * @arg[in] it is the item to store.
      * @pre isValid(pos).
      * @pre not isFull().
      * @post isValid(pos+1).
      * @post not isEmpty().
      * @post item(pos)=item.
      * @post not old.isEmpty() implies item(pos+1)==old.item(pos)
      */
      virtual void insert(const T& it)
      {
				int insertado=0;
        int pos;

				if (isEmpty())
				{
					setHead (new edi::LinkedNode<T>(NULL,it,NULL));
				}else{
					
          goTo(0);
					
          for(int i=0; (current() !=NULL) && (insertado==0); i++){
						
						goTo(i);
						
            //PRIMER ELEMENTO DE LA LISTA
						if ( (previous()==NULL) && ((current()->item()) > it) && (insertado==0)){
						//new head.
              setHead(new edi::LinkedNode<T>(NULL, it, head()));
							current()->setPrevious(head());
							insertado=1;             
						}
            //ULTIMO ELEMENTO DE LA LISTA
						if ( current()->next()==NULL && ( (current()->item()) < it ) && (insertado==0) ){
							current()->setNext(new edi::LinkedNode<T>(current(),it, NULL));
							insertado=1;
						}		
					   //VALOR EN MEDIO DE LA LISTA
            if( (previous()!=NULL) && ((previous()->item())<it) && ((current()->item())>it) && (insertado==0))
            { 
							previous()->setNext(new edi::LinkedNode<T>(previous(), it, current()));
              current()->setPrevious(previous()->next());
							insertado=1;
						}

					}//for
				}//else isEmpty

				assert(!isEmpty());
        assert(not ((pos=findItem(it)) && (isValid(pos-1)==true)) or (item(pos-1)<=it) );
        assert(not ((pos=findItem(it)) && (isValid(pos+1)==true)) or (it<=item(pos+1)) );
      } 

      /** @brief Deletes the given position.
      * Time analysis: O(n).
      * @arg[in] pos is the position to be deleted.
      * @pre isValid(pos).
      * @post not old.isLast(pos) implies not old.item(pos+1)=item(pos).
      */
      virtual void deletePosition(const int pos)	
      {
				assert(isValid(pos));
        assert(isEmpty()==false);
				#ifndef NDEBUG
					bool oldIsLast = isLast(pos);
					T oldItemNext = T();
					if (not oldIsLast)
						oldItemNext = item(pos+1);
				#endif
				goTo(pos);
				edi::LinkedNode<T> * old = current();
				if (previous()==NULL){
					setHead(current()->next());
				}else{
					previous()->setNext(current()->next());
					if(current()->next()!=NULL)					
					( current()->next() )->setPrevious(previous());
				}
				delete old;
				#ifndef NDEBUG
					assert(oldIsLast or item(pos)==oldItemNext);
          assert(not (isValid(pos+1)==true) or item(pos)==oldItemNext);
				#endif //NDEBUG
      }

      /** @brief Deallocate the list.*/
      void flush ()
      {
				setCurrent(head());
				while(current()!=NULL)
				{
					setPrevious(current());
					setCurrent(current()->next());
					delete previous();
				}
				setHead(0);
      }
    /**@}*/
    protected:
      /** @brief Go to a given list's position.
      * Go to a given list's position. If it does not exist, _curr will be a null pointer.
      */
      virtual void goTo(const unsigned idx)
      {
				setCurrent(head());
				setPrevious(NULL);
				for (unsigned i=0; i<idx && _curr!=NULL; ++i)
				{
					setPrevious(current());
					setCurrent(current()->next());
				}
      }
      virtual const edi::LinkedNode<T> * head() const
      {
				return _head;
      }
      virtual edi::LinkedNode<T> * head()
      {
				return _head;
      }
      virtual void setHead(edi::LinkedNode<T> *newV)
      {
				_head=newV;
      }
      virtual const edi::LinkedNode<T> * current() const
      {
				return _curr;
      }
      virtual edi::LinkedNode<T> * current()
      {
				return _curr;
      }
      virtual void setCurrent(edi::LinkedNode<T> *newV)
      {
				_curr=newV;
      }
      virtual const edi::LinkedNode<T> * previous() const
      {
				return _prev;
      }
      virtual edi::LinkedNode<T> * previous()
      {
				return _prev;
      }
      virtual void setPrevious(edi::LinkedNode<T> *newV)
      {
				_prev=newV;
      }

  };
 
} //namespace
 
#endif //__EDI_LinkedList_HPP__
