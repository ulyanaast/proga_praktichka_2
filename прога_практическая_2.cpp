#include <iostream>
#include <algorithm>
#include <chrono>
#include <ctime>
using namespace std;
using namespace chrono;

int main()
{
    setlocale(0, "");
    srand(time(0));
    const int n = 100;
    int arr[n]{};
    int copyArr[n]{};
    time_point<steady_clock, duration<__int64, ratio<1, 1000000000>>> start, end;
    nanoseconds result;
    // 1 task
    cout << "\n1) Неотсортированный массив: ";
    for (int v = 0; v < n; v++)
    {
        arr[v] = rand() % 199 - 99;
        cout << arr[v] << ' ';
    }

    for (int i = 0; i < n; i++)
        copyArr[i] = arr[i];

    // 2 task
    start = steady_clock::now();
    for (int i = 0; i < n - 1; i++)          // bubble sort
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (copyArr[j] > copyArr[j + 1])
                swap(copyArr[j], copyArr[j + 1]);
        }
    }
    end = steady_clock::now();
    result = duration_cast<nanoseconds>(end - start);

    cout << "\n\n2) Отсортированный массив: ";
    for (int w = 0; w < n; w++)
        cout << copyArr[w] << ' ';

    cout << "\n\n   Время, затраченное на сортировку массива bubble sort'отом: " << result.count() << " ns";

    for (int i = 0; i < n; i++)
        copyArr[i] = arr[i];

    start = steady_clock::now();
    for (int i = 0; i < n - 1; i++)            // shaker sort
    {
        for (int j = i; j < n - 1 - i; j++)
        {
            if (copyArr[j] > copyArr[j + 1])
                swap(copyArr[j], copyArr[j + 1]);
        }
        for (int l = n - 2 - i; l > i; l--)
        {
            if (copyArr[l] < copyArr[l - 1])
                swap(copyArr[l], copyArr[l - 1]);
        }
    }
    end = steady_clock::now();
    result = duration_cast<nanoseconds>(end - start);
    cout << "\n   Время, затраченное на сортировку массива shaker sort'отом: " << result.count() << " ns";

    for (int i = 0; i < n; i++)
        copyArr[i] = arr[i];

    start = steady_clock::now();
    for (int i = 1; i < n; i++)                                 // insert sort
        for (int j = i; copyArr[j - 1] > copyArr[j]; j--)
            swap(copyArr[j - 1], copyArr[j]);
    end = steady_clock::now();
    result = duration_cast<nanoseconds>(end - start);
    cout << "\n   Время, затраченное на сортировку массива вставками: " << result.count() << " ns";

    for (int i = 0; i < n; i++)
        copyArr[i] = arr[i];

    float k = 1.247;
    int step = n - 1;
    bool flag = true;
    start = steady_clock::now();
    while (step >= 1)                                              // comb sort
    {
        for (int i = 0; i + step < n; i++)
        {
            if (copyArr[i] > copyArr[int(i + step)])
                swap(copyArr[i], copyArr[int(i + step)]);
        }
        step = step / k;
    }
    while (flag)
    {
        for (int i = 0; i < n - 1; i++)
        {
            flag = false;
            for (int j = 0; j < n - 1 - i; j++)
            {
                if (copyArr[j] > copyArr[j + 1])
                {
                    swap(copyArr[j], copyArr[j + 1]);
                    flag = true;
                }
            }
        }
    }
    end = steady_clock::now();
    result = duration_cast<nanoseconds>(end - start);
    cout << "\n   Время, затраченное на сортировку массива расчёской: " << result.count() << " ns";

    // 3 task
    start = steady_clock::now();
    int minOm = copyArr[0];
    int maxOm = copyArr[n - 1];
    end = steady_clock::now();
    result = duration_cast<nanoseconds>(end - start);
    cout << "\n\n3) Минимальный элемент массива: " << minOm;
    cout << "\n   Максимальный элемент массива: " << maxOm;
    cout << "\n   Время, затраченное на поиск минимального и максимального элементов массива в Oтсортированном массиве: " << result.count() << " ns";

    for (int i = 0; i < n; i++)
        copyArr[i] = arr[i];

    int maxNm = -100;
    int minNm = 100;

    start = steady_clock::now();
    for (int l = 0; l < n; l++)
    {
        if (copyArr[l] > maxNm)
            maxNm = copyArr[l];
        if (copyArr[l] < minNm)
            minNm = copyArr[l];
    }
    end = steady_clock::now();
    result = duration_cast<nanoseconds>(end - start);
    cout << "\n   Время, затраченное на поиск минимального и максимального элементов массива в Неотсортированном массиве: " << result.count() << " ns";

    // 4 task
    int midNm, count = 0;
    midNm = (minNm + maxNm) / 2;
    cout << "\n\n4) Среднее значение максимального и минимального элементов в Неотсортированном массиве: " << midNm;
    cout << "\n   Индексы элементов в Неотсортированном массиве, равных среднему значению: ";
    start = steady_clock::now();
    for (int i = 0; i < n; i++)
    {
        if (copyArr[i] == midNm)
        {
            count += 1;
            cout << i << " ";
        }
    }
    end = steady_clock::now();
    result = duration_cast<nanoseconds>(end - start);
    cout << "\n   Количество элементов в Неотсортированном массиве, равных среднему значению: " << count;
    cout << "\n   Время, затраченное на поиск элементов, равных среднему значению, в Неотсортированном массиве: " << result.count() << " ns";

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (copyArr[j] > copyArr[j + 1])
                swap(copyArr[j], copyArr[j + 1]);
        }
    }

    int midOm;
    count = 0;
    int in = 100;
    midOm = (copyArr[0] + copyArr[n - 1]) / 2;
    cout << "\n\n   Среднее значение максимального и минимального элементов в Oтсортированном массиве: " << midOm;
    cout << "\n   Индексы элементов в Oтсортированном массиве, равных среднему значению: ";
    for (int u = 0; u < n; u++)
        if (copyArr[u] > midOm)
            in = u - 1;
    start = steady_clock::now();
    for (int i = 0; i < in; i++)
    {
        while (copyArr[i] <= midOm)
        {
            if (copyArr[i] == midOm)
            {
                count += 1;
                cout << i << " ";
            }
            break;
        }
    }
    end = steady_clock::now();
    result = duration_cast<nanoseconds>(end - start);
    cout << "\n   Количество элементов в Oтсортированном массиве, равных среднему значению: " << count;
    cout << "\n   Время, затраченное на поиск элементов, равных среднему значению, в Oтсортированном массиве: " << result.count() << " ns";

    // 5 task
    int a;
    count = 0;
    cout << "\n\n5) Введите число. Будет выведено количество элементов в отсортированном массиве, которые меньше этого числа ->  ";
    cin >> a;
    for (int i = 0; i < n; i++)
    {
        if (copyArr[i] < a)
            count += 1;
        if (copyArr[i] > a)
            break;
    }
    cout << "   Kоличество элементов в отсортированном массиве, которые меньше вашего числа: " << count;

    // 6 task
    int b;
    count = 0;
    cout << "\n\n6) Введите число. Будет выведено количество элементов в отсортированном массиве, которые больше этого числа ->  ";
    cin >> b;
    for (int i = 0; i < n; i++)
    {
        if (copyArr[i] > b)
            count += 1;
    }
    cout << "   Kоличество элементов в отсортированном массиве, которые больше вашего числа: " << count;

    // 7 task (*) 
    int key;
    cout << "\n\n7) Введите число, наличие которого в массиве хотите проверить бинарным поиском ->  ";
    cin >> key;

    int midIndex;
    int left = 0;
    int right = n - 1;
    bool flagBin = false;

    start = steady_clock::now();
    while (left <= right)        // бинарный поиск
    {
        midIndex = (left + right) / 2;

        if (copyArr[midIndex] == key)
        {
            flagBin = true;
            break;
        }
        if (copyArr[midIndex] > key)
            right = midIndex - 1;
        else
            left = midIndex + 1;
    }
    end = steady_clock::now();
    result = duration_cast<nanoseconds>(end - start);
    if (flagBin == true)
        cout << "   Ваше число есть в массиве под индексом " << midIndex;
    else
        cout << "   Вашего числа нет в массиве :(";
    cout << "\n   Время, затраченное на поиск элемента бинарным поиском: " << result.count() << " ns";

    int countI = 0;
    start = steady_clock::now();
    for (int i = 0; i < n; i++)
    {
        if (copyArr[i] == key)
        {
            countI += 1;
            break;
        }
    }
    end = steady_clock::now();
    result = duration_cast<nanoseconds>(end - start);
    if (countI > 0)
        cout << "\n\n   Ваше число есть в массиве под индексом " << midIndex;
    else
        cout << "\n   Вашего числа нет в массиве :(";
    cout << "\n   Время, затраченное на поиск элемента обычным перебором: " << result.count() << " ns";

    // 8 task
    int el1, el2;
    cout << "\n\n8) Введите 2 индекса, элементы которых в массиве (отсортированном) нужно поменять местами -> ";
    cin >> el1;
    cin >> el2;
    start = steady_clock::now();
    swap(copyArr[el1], copyArr[el2]);
    end = steady_clock::now();
    result = duration_cast<nanoseconds>(end - start);
    cout << "\n   Массив с элементами, которые поменяли местами: ";
    for (int w = 0; w < n; w++)
        cout << copyArr[w] << ' ';
    cout << "\n   Время, затраченное на обмен элементов: " << result.count() << " ns\n";

    return 0;
}