#include <iostream>

using namespace std;

int main()
{
    int A, B, l = 0, r = 0;
    cin >> A >> B;
    while (!(A == 1 && B == 1))
    {
        if (A > B)
        {
            ++l;
            A -= B;
        }
        else
        {
            ++r;
            B -= A;
        }
    }
    cout << l << ' ' << r;
}

/*
 *                                  (1, 1)
 *                  (2, 1)                          (1, 2)
 *          (3, 1)          (2, 3)          (3, 2)          (1, 3)
 *      (4, 1)  (3, 4)  (5, 3)  (2, 5)                          (1, 4)
 *                        ()                                   (5, 4)
 *
 *
 *
 *
 *
 *
 */