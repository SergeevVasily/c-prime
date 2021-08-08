/* ��������� ������ ������� �����.
����� ������� �.�.

�������� �������������� ��� �������� ������� 0, ������ � ����� �� �������
������� ��� ����� ������� �������� �������� � ��������� �����, ������� �������� �������� ������� �� 1,
�� ���������� �������� ���������� ��� ������� �����, ������� ������� ������� ����� 0 � ������ �������.

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

    register unsigned div;  // ��� �������� ������ ����� � �������� ������������� ���������
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

/*�������� �������� �� ������
#define NUM 65535
unsigned int arr[NUM] = {0};
for(prime=2; prime*prime <= NUM; prime++)

 �������� ���-�� ������ ���-�� ���������?

 ��� ����������� ��� ��� ������ �� ��������.
0. �������� �������������� ��� �������� ������� 0 � ������������ � ��������� ������� �������..
  ������ � ����� �� �������.
1. unsigned int arr[NUM] = {0}; // ������������� �������
�� ������ ���� �����, ��� ������ ����������������. �� ��� �� ������?
2. prime; // ��� �������� ������ �����
�� ������ ����
3. primeIndex=0; // ���������� ������� �������
4. �� �������, � �������
5. ������ �� ����������� ������ ����� ���������. �������� �������� �� ������
#define NUM 65535
unsigned int arr[NUM] = {0};
for(prime=2; prime*prime <= NUM; prime++)

�������� ���-�� ������ ���-�� ���������?
 */
