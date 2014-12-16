#ifndef _LIST_HPP_
#define _LIST_HPP_

namespace asteroids
{

/**
 * @brief   A simple generic list class
 */
template<typename T>
class List
{
public:

    /**
     * @brief   Struct to represent a node in the list.
     */
    struct Node
    {
        Node*   next;
        T      data;
    };

    /**
     * @brief   Constructs an empty list.
     */
    List<T>();

    /**
     * @brief   Destructor. Frees the generated nodes.
     */
    ~List<T>();

    /**
     * @brief   Inserts an item into the list, i.e. a new node
     *          constaining @ref item is created.
     */
    void insert(T item);

    /**
     * @brief   Iterates over all items in the list and calls
     *          the given function @ref do_something(...) for
     *          every item stored in the list.
     */
    void for_each(void (*do_something)(T item));

private:

    // Root of the list
    Node*      m_list;
};

} // namespace asteroids
#endif

