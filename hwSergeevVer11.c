/* Программа поиска простых чисел.
автор Сергеев В.Ф.

Алгоритм инициализирует все елементы массива 0, проход в цикле по массиву
помечая все числа кратные квадрату текущего в иттерации числа, заменяя значение елемента массива на 1,
по завершению алгоритм перемещает все простые числа, елемент массива которых равен 0 в начало массива.

v1.1.9
04.08.2021*/

#include <stdio.h>
#include <limits.h>
#include <windows.h>

#define N USHRT_MAX

int main(void)
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    register unsigned div;  // Для хранения просто числа и перебора потенциальных делителей
    register unsigned notPrime; // marker filtered
    register unsigned primeCount = 0;
    register unsigned short primeIndex = 0;
    unsigned int arr[N]; //

    for (div = 1; div <= N; div+=2) //
            arr[div] = 0;

    for( div = 3; div * div <= N; div+=2)
    {
        if(arr[div] == 0)
            for (notPrime = div*div; notPrime <= N; notPrime += div)
                arr[notPrime] = 1;
    }
    for(div = 1; div <= N; div+=2)
        if(arr[div] == 0)
        {
            primeCount++;
            arr[++primeIndex] = div;
            //printf("\t%u", arr[primeIndex]);
        }
    printf("\nTotal amount of primes - %d", primeCount);

    return 0;
}

/*Обратите внимание на строки
#define NUM 65535
unsigned int arr[NUM] = {0};
for(prime=2; prime*prime <= NUM; prime++)

 возможно где-то удастс что-то уменьшить?

 Все комментарии мне как обычно не нравятся.
0. Алгоритм инициализирует все елементы массива 0 и иттерируется в диапозоне данного массива..
  проход в цикле по массиву.
1. unsigned int arr[NUM] = {0}; // Инициализация массива
из самого кода видно, что массив инициализируется. Но что он хранит?
2. prime; // Для хранения просто числа
не понтна суть
3. primeIndex=0; // Увеличения индекса массива
4. Не елемент, а элемент
5. Теперь по оптимизации памяти вашей программы. Обратите внимание на строки
#define NUM 65535
unsigned int arr[NUM] = {0};
for(prime=2; prime*prime <= NUM; prime++)

возможно где-то удастс что-то уменьшить?
 */
