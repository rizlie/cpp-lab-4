#include <iostream>
using namespace std;

int main()
{
    long long n;
    cin >> n;

    long long summ_p = 0;
    long long summ_m = 0;
    long long l = 0;
    long long k = 0;
    long long a = 0;
    long long b = 0;

    long long s;
    s = (n * (n + 1)) / 2;

    if (s % 2 != 0)
    {
        cout << "NO" << endl;
        return 0;
    }
    else
    {
        cout << "YES" << endl;
        long long portion = s / 2;

        // считаем кол-во мини порций у Пети и  Маши
        for (long long i = n; i >= 1; --i)
        {
            if (summ_p + i <= portion)
            {
                if (summ_p + i + (n - i + 1) <= portion)
                {
                    summ_p = summ_p + i + (n - i + 1);
                    l += 2;
                }
                else
                {
                    summ_p = summ_p + i;
                    l += 1;
                }
            }
        }

        k = n - l;
        cout << l << endl;
        summ_p = 0;

        // считаем грамовки этих порций
        for (long long i = n; i >= 1; --i)
        {
            if (summ_p + i <= portion)
            {
                if (summ_p + i + (n - i + 1) <= portion)
                {
                    summ_p = summ_p + i + (n - i + 1);
                    cout << i << "," << ' ' << (n - i + 1) << "," << ' ';
                    b = (n - i + 1);
                    a = i;
                }
                else
                {
                    summ_p = summ_p + i ;
                    cout << i;
                    a = i;
                }
            }
        }

        cout << endl;
        cout << k << endl;

        for (long long i = b + 1; i < a; ++i)
        {
            cout << i << "," << ' ';
        }
    }

}
