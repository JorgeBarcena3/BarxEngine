#pragma once
#include "BtypeDef.hpp"

// TYPE debe tener un constructor por defecto.
// Todos los objetos se crearán al crear el BObjectPool y se destruirán con él.

template< typename TYPE >
class BObjectPool
{
private:

    struct Element
    {
        TYPE      object;
        Element* next;
        Element* prev;
    };

public:

    class Iterator
    {

        Element* current;

    public:

        Iterator(Element* start)
        {
            current = start;
        }

        ~Iterator()
        {
            current = nullptr;      // Ayuda a detectar posibles bugs
        }

        // Sobrecarga del operador de pre-incremento:

        Iterator& operator ++ ()
        {
            if (current) current = current->next;

            return *this;
        }

        // Sobrecarga del operador de pre-decremento:

        Iterator& operator -- ()
        {
            if (current) current = current->prev;

            return *this;
        }

        // Sobrecarga del operator de indirección de puntero:

        TYPE& operator * ()
        {
            assert(current);
            return current->object;
        }

        const TYPE& operator * () const
        {
            assert(current);
            return current->object;
        }

        // Sobrecarga del operador de acceso a miembro a través de puntero:

        TYPE* operator -> ()
        {
            assert(current);
            return &current->object;
        }

        const TYPE* operator -> () const
        {
            assert(current);
            return &current->object;
        }

        // Sobrecarga de los operadores de igualdad y desigualdad:

        bool operator == (const Iterator& other) const
        {
            return this->current == other.current;
        }

        bool operator != (const Iterator& other) const
        {
            return this->current != other.current;
        }

    };

private:

    std::vector< Element > elements;        ///< Contenedor de todos los objetos prealojados

    Element* free;                         ///< Puntero al primer elemento de la lista enlazada de elementos libres
    Element* used;                         ///< Puntero al primer elemento de la lista enlazada de elementos usados

public:

    BObjectPool(size_t size);

public:

    TYPE* get_free_element();
    void   free_element(TYPE* object);

public:

    // Si se permitiese ordenar la lista de elementos usados según su dirección de memoria podría
    // mejorar el rendimiento al iterarlos gracias al acceso secuencial vs. aleatorio.

    Iterator begin()
    {
        return Iterator(used);
    }

    Iterator end()
    {
        return Iterator(nullptr);
    }

};

template< typename TYPE >
BObjectPool< TYPE >::BObjectPool(size_t size) : elements(size)
{
    // Se crea una lista enlazada con todos los elementos libres:

    for (size_t i = 1; i < size - 1; ++i)
    {
        elements[i].next = &elements[i + 1];
        elements[i].prev = &elements[i - 1];
    }

    elements[0].next = &elements[1];
    elements[0].prev = nullptr;
    elements[size - 1].next = nullptr;
    elements[size - 1].prev = &elements[size - 2];

    free = &elements[0];
    used = nullptr;

}

template< typename TYPE >
TYPE* BObjectPool< TYPE >::get_free_element()
{
    // Se toma el primer elemento de la lista de elementos libres:

    Element* element = free;

    if (free)
    {
        // Se quita de la lista de elementos libres:

        free = element->next;

        if (free) free->prev = nullptr;

        // Se añade a la lista de elementos usados:

        element->next = used;
        element->prev = nullptr;

        if (used) used->prev = element;

        used = element;
    }

    return reinterpret_cast<TYPE*>(element);
}

template< typename TYPE >
void BObjectPool< TYPE >::free_element(TYPE* object)
{
    if (object)
    {
        Element* element = reinterpret_cast<Element*>(object);

        // Se quita de la lista de elementos usados:

        if (element->prev) element->prev->next = element->next;
        if (element->next) element->next->prev = element->prev;

        // Se añade a la lista de elementos libres:

        element->next = free;
        element->prev = nullptr;

        if (free) free->prev = element;

        free = element;
    }
}

