#pragma once
#include "BtypeDef.hpp"
#include "BMemoryAllocator.hpp"

  class BMemoryPool
    {

    //    Array< byte * > blobs;              ///< Array de bloques de memoria usados como base donde alojar
    //    size_t          blob_size;          ///< Tama�o fijo de cada bloque
    //    byte          * blob;               ///< Bloque con espacio libre en un momento dado (el �ltimo de los blobs)
    //    size_t          consumed;           ///< Tama�o consumido del �ltimo bloque

    //public:

    //    BMemoryPool(size_t blob_size = 1048576u)
    //    :
    //        blobs(1),
    //        blob_size(blob_size)
    //    {
    //        blobs[0] = BMemoryAllocator::instance ().allocate (blob_size);
    //        blob     = blobs[0];
    //        consumed = 0;

    //        assert(blob);
    //    }

    //   ~BMemoryPool()
    //    {
    //        for (auto blob : blobs)
    //        {
    //            BMemoryAllocator::instance ().free (blob);
    //        }
    //    }

    //public:

    //    // MOVER A UN ARCHIVO DE IMPLEMENTACI�N...
    //    void * allocate (size_t size)
    //    {
    //        if (size > 0 && size < blob_size)
    //        {
    //            if (consumed + size > blob_size)
    //            {
    //                blobs.push_back (blob = BMemoryAllocator::instance ().allocate (blob_size));

    //                consumed = 0;
    //            }

    //            void * slice = blob + consumed;

    //            consumed += (size + sizeof(word) - 1) / sizeof(word) * sizeof(word);    // Se reserva un tama�o m�ltiplo de sizeof(word)

    //            return slice;
    //        }

    //        return nullptr;
    //    }

    };
