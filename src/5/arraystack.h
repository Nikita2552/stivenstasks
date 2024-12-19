#ifndef ARRAYSTACK_H
#define ARRAYSTACK_H

#include <iostream>
#include <cinttypes>
#include "entryformanyrealize.h"


using namespace std;
using namespace sixchapter;

namespace sixchapter
{

    template<typename T>
    class StackArray
    {
    public:
        StackArray();
        StackArray(const unsigned int &esize);
        ~StackArray();

        void initstruct(const unsigned int &esize);

        void push(const T &info);
        T pop();

        unsigned int getsize();
        unsigned int getnum();
        T getelement(unsigned int i);

        void printall();
    private:
        T* head;
        unsigned int num;
        unsigned int size;
    };

    template<typename T>
    StackArray<T>::StackArray()
    {
        initstruct(5);
    }

    template<typename T>
    StackArray<T>::StackArray(const unsigned int &esize)
    {
        initstruct(esize);
    }

    template<typename T>
    StackArray<T>::~StackArray()
    {
        //При копировании экземпляров класса с динамически выделенной памятью необходимо явно определить конструктор копирования и оператор =
        //У вас фактически происходит двойное освобождение выделенной памяти, т. к. конструктор копирования по умолчанию осуществляет поверхностное копирование
        //delete[] head;
    }

    template<typename T>
    void StackArray<T>::initstruct(const unsigned int &esize)
    {
        head = new T[esize];
        num = 0;
        size = esize;
    }

    template<typename T>
    void StackArray<T>::push(const T &info)
    {
        if (num < size)
        {           
            head[num] = info;
            num++;
         }
    }

    template<typename T>
    T StackArray<T>::pop()
    {
        if (num > 0)
        {
            T info = head[--num];
            head[num] = 0;
            return info;
        }
        return 0;
    }

    template<typename T>
    unsigned int StackArray<T>::getsize()
    {
        return size;
    }

    template<typename T>
    unsigned int StackArray<T>::getnum()
    {
        return num;
    }

    template<typename T>
    T StackArray<T>::getelement(unsigned int i)
    {
        if (i < num)
            return head[i];
        return 0;
    }

    template<typename T>
    void StackArray<T>::printall()
    {
        unsigned int i = 0;
        while(i < size)
        {
            cout << "arraystack[" << i << "] = " << head[i] << endl;
            i++;
        }
    }

    /* сортировка вставкой */
    /*
Сперва сам алгоритм: идея в том, чтобы завести второй стек, элементы в котором будут отсортированы между итерациями. В конце работы он будет содержать все
 элементы исходного в отсортированном порядке.

Снимаем с верхушки исходного стека элемент x.
Находим позицию, в которую его можно добавить во временный стек, такую, чтобы не нарушался инвариант. Эта позиция - либо единственно возможная, если временный
стек пуст, либо сразу после элемента, который больше x, ибо тогда ниже в стеке окажутся элементы меньшие или равные (напоминаю, временный стек всегда отсортирован).
Для того, чтобы x поместить в эту позицию, мы последовательно вынимаем из стека все, что нам мешает, и кладем в исходный стек (позже мы все равно это отсортируем). (строчки 2 и 3)
Помещаем x во временный стек. Временный стек остается отсортирован после этого шага. (строчка 4)
Повторяем до тех пор, пока в исходном стеке не осталось элементов. (строчка 1)
При особенно сильном желании вернуть именно исходный стек всегда в конце можно вынуть все элементы из временного и поместить в исходный, предварительно переделав сравнение.

def sort_stack(s):
    t = []
    while s:                          # (1)
        x = s.pop()
        while t and t[-1] > x:        # (2)
            s.append(t.pop())         # (3)
        t.append(x)                   # (4)
    return t
  */

    template<typename T>
    StackArray<T> *sortstack_vs(StackArray<T> *inputstack)
    {
        if (inputstack)
        {
            StackArray<T> *temp = new StackArray<T>(inputstack->getnum());            

            while(inputstack->getnum())
            {
                T item = inputstack->pop();
                unsigned int i = temp->getnum() - 1;
                while (temp->getnum() && (temp->getelement(i) > item))
                {
                    inputstack->push(temp->pop());
                    i--;
                }
                temp->push(item);
            }
            return temp;
        }
        return nullptr;
    }

    /* сортировка выбором */
    /*
    Алгоритм сортировки выбором имеет сложность O(n^2), как и сортировка вставками, но его производительность не зависит от состояния списка, то есть он работает
    одинаково хорошо как для уже отсортированных списков, так и для случайных списков.

    Как работает алгоритм сортировки выбором:

    Алгоритм начинает с первого элемента в списке и считает, что он отсортирован.
    Далее, алгоритм ищет минимальный элемент в оставшейся неотсортированной части массива и меняет его местами с первым элементом в неотсортированной части массива.
    Теперь первые два элемента в списке отсортированы.
    Процесс повторяется для оставшейся части массива, до тех пор, пока не все элементы в списке не будут отсортированы.
    Вот пример кода на C++ для сортировки выбором:

    template <typename type_arr>
    void selection_sort(type_arr *arr, int size)
    {
        for (int i = 0; i < size - 1; i++)
        {
            int min_index = i;
            for (int j = i + 1; j < size; j++)
            {
                if (arr[j] < arr[min_index])
                {
                    min_index = j;
                }
            }
            if (min_index != i)
            {
                swap(arr[i], arr[min_index]);
            }
        }
    }
    */

    template<typename T>
    StackArray<T> *sortstack_vi(StackArray<T> *inputstack)
    {
        if (inputstack)
        {
            StackArray<T> *temp = new StackArray<T>(inputstack->getnum());
            unsigned int i = 0;
            unsigned int n = inputstack->getnum();
            while(i < n)
            {
                T max = inputstack->pop();
                inputstack->push(max);
                unsigned int j = 0;
                unsigned int m = n - i;

                while (j < m)
                {
                    T item = inputstack->pop();
                    if (item > max)
                        max = item;
                    temp->push(item);
                    j++;
                }
                j = 0;
                inputstack->push(max);

                while (j < m)
                {
                    T item = temp->pop();
                    if (item != max)
                        inputstack->push(item);
                    j++;
                }
                i++;
            }
            return inputstack;
        }
        return nullptr;
    }
}

#endif // ARRAYSTACK_H
