#ifndef LIST_H

#define LIST_H

/**
 * @brief   A simple generic list class
 */
template<typename T> class List
{
   public:
      /**
       * @brief Struct to represent a node in the list.
       */
      struct Node {
         Node* next;
         T data;
      };
      /**
       * @brief Constructs an empty list.
       */
      List<T>();
      /**
       * @brief  Destructor. Frees the generated nodes.
       */
      ~List<T>();
      /**
       * @brief Inserts an item into the list, i.e. a new node
       *        constaining @ref item is created.
       * @param item To be inserted
       *
       */
      void insert(T item);
      /**
       * @brief Iterates over all items in the list and calls
       * the given function @ref do_something(...) for
       * every item stored in the list.
       *
       * @param do_something Function pointer to apply to all elements.
       */
      void for_each(void (*do_something)(T& item));
   private:
      // Root of the list 
      Node* m_list;
};


#include "List.tcc"
#endif
/* end of include guard: LIST_H */
