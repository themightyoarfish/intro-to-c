#include <iostream>
template<typename T> List<T>::List()
{
   m_list = NULL;
}
template<typename T> List<T>::~List()
{
   if (m_list->next != NULL) delete m_list->next;
   delete m_list;
}
template<typename T> void List<T>::insert(T item)
{
   if (m_list == NULL) 
   {
      m_list = new Node;
      m_list->data = item;
      m_list->next = NULL;
   } else
   {
      Node* m = new Node;
      m->data = item;
      m->next = m_list;
      m_list = m;
   }
}
template<typename T> void List<T>::for_each(void (*do_something)(T item))
{
   Node* tmp = m_list;
   while (tmp != NULL) 
   {
      do_something(tmp->data);
      tmp = tmp->next;
   }
}

