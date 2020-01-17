#include <iostream>	
#include <vector>
#include <stdlib.h>   
#include <time.h>       

using namespace std;

namespace BAlgoritmosDeOrdenacion {

    ///Algoritmo de burbuja
    ///Recorremos la lista de numeros comparando el numero actual con el siguiente, y si es el orden incorrecto los cambiamos
    ///Hasta que no cambiamos nada
    template <class T>
    void algoritmoBurbuja(T* list, unsigned int size) {

        bool hayCambios = true;

        while (hayCambios) {

            hayCambios = false;

            for (size_t i = 0; i < size - 1; i++) {

                if (*list[i] < *list[i + 1]) {
                    T aux = list[i];
                    list[i] = list[i + 1];
                    list[i + 1] = aux;
                    hayCambios = true;
                }

            }
        }

    }

    ///Algoritmo de inserccion directa
   ///Recorremos la lista buscando el valor mas pequeño
    ///size_tercambiamos la posicion actual con el valor mas pequeño
    template <class T>
    void algoritmoInserccionDirecta(T* list, size_t size) {

        for (size_t i = 0; i < size; i++) {
            for (size_t j = i; j < size; j++) {

                if (list[i] < list[j]) {
                    T aux = list[i];
                    list[i] = list[j];
                    list[j] = aux;
                }
            }
        }

    }


    ///Algoritmo de quick sort
   ///Elegimos un numero al alazar (Mitad de la cadena)
    //Dos listas con elementos mas grandes que el pivote y otra con los elementos mas pequeños que el pivote
    ///Llamamos a la funcion de ordenacion de quickShort para que lo reordene
    ///Cuando queden dos elementos, se retorna ordenandolos
    template <class T>
    void quickSort(T* list, size_t size) {

        if (size == 2) {
            //ARRAY DE DIRECCIONES DE MEMORIA
            if (list[0] > list[1]) {
                T aux = list[0];
                list[0] = list[1];
                list[1] = aux;
            }
        }
        else {

            size_t index = size / 2;
            T* element = &list[index];
            vector<T> menor;
            vector<T> mayor;

            for (size_t i = 0; i < size; i++) {

                if (&list[i] != element) {

                    if (list[i] <= *element)
                        menor.push_back(list[i]);
                    else
                        mayor.push_back(list[i]);
                }

            }


            //Reordeno la lista ordenada de mayor a menor
            int pivotIndex = 0;

            for (size_t i = 0; i < menor.size(); i++) {
                list[pivotIndex] = (menor[i]);
                pivotIndex++;
            }

            list[pivotIndex] = *element;
            pivotIndex++;

            for (size_t i = 0; i < mayor.size(); i++) {
                list[pivotIndex] = (mayor[i]);
                pivotIndex++;
            }



            if (menor.size() > 0)
                quickSort(list, menor.size());

            if (mayor.size() > 0)
                quickSort(list + menor.size() + 1, mayor.size());

        }


    }


    ///Necesita una lista de auxialr del tipo de dato
    ///Contamos cuantas veces aparece cada dato repetido
    ///Lista de igual tamaño
    //Variable offest que vale 0
    //Recorremos la lista de conteo y la añadimos a la nueva lista
    template <class T>
    void countShort(T* list, size_t size) {
        
            T maxValue = list[0];

        for (size_t i = 1; i < size; i++)
        {
            if (list[i] > maxValue)
            {
                maxValue = list[i];
            }
        }

        vector<T> contador(maxValue);

        for (size_t i = 0; i < size; i++)
        {
            contador[list[i] - 1]++;
        }

        unsigned int index = 0;

        for (size_t i = 0; i < contador.size(); i++)
        {
            while (contador[i] > 0) {
                list[index] = i + 1;
                index++;
                contador[i]--;
            }
        }
    }
};


