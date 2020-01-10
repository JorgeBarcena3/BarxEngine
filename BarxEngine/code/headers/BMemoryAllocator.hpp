#pragma once


#include <cstdlib>


class BMemoryAllocator
{
public:

    static BMemoryAllocator& instance()
    {
        static BMemoryAllocator memory_allocator;
        return memory_allocator;
    }

private:

    size_t allocations;
    size_t deallocations;

private:

    BMemoryAllocator()
    {
        allocations = deallocations = 0;
    }

public:

    size_t get_allocations() const { return allocations; }
    size_t get_deallocations() const { return deallocations; }
    size_t get_allocation_balance() const { return allocations - deallocations; }

public:

    void* allocate(size_t size)
    {
        allocations++;

        return std::malloc(size);
    }

    /// Intenta cambiar el tamaño del buffer sin moverlo.
    void* reallocate(void* buffer, size_t new_size)
    {
        return std::realloc(buffer, new_size);
    }

    void free(void* buffer)
    {
        if (buffer) deallocations++;

        std::free(buffer);
    }

};

// SOBRECARGAS ESTÁNDAR DEL OPERADOR NEW:

void* operator new       (size_t size) { return  BMemoryAllocator::instance().allocate(size); }
void   operator delete    (void* data) noexcept {  BMemoryAllocator::instance().free(data); }
void* operator new    [](size_t size) { return  BMemoryAllocator::instance().allocate(size); }
void   operator delete [](void* data) noexcept {         BMemoryAllocator::instance().free(data); }

// SOBRECARGAS ESTÁNDAR DEL OPERADOR NEW QUE NO LANZA EXCEPCIONES:

void* operator new       (size_t size, const std::nothrow_t&) noexcept { return  BMemoryAllocator::instance().allocate(size); }
void   operator delete    (void* data, const std::nothrow_t&) noexcept {  BMemoryAllocator::instance().free(data); }
void* operator new    [](size_t size, const std::nothrow_t&) noexcept { return  BMemoryAllocator::instance().allocate(size); }
void   operator delete [](void* data, const std::nothrow_t&) noexcept {         BMemoryAllocator::instance().free(data); }
