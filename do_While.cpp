#include <iostream>
#include <cstdlib>

using namespace std;

/* Simple macros */
#define f1() cout << "f1()" << endl
#define f2() cout << "f2()" << endl

/* Correct macro pattern */
#define fun() do { \
    f1(); \
    f2(); \
} while (0)

/* Same idea, different name */
#define fun1() do { \
    f1(); \
    f2(); \
} while (0)

/* Demonstrates goto-style cleanup */
int f() {
    int *p = (int *)malloc(sizeof(int));
    if (!p) return -1;

    *p = 10;
    cout << *p << endl;

    int error = 0;
#ifndef DEBUG
    error = 1;
#endif

    if (error)
        goto END;

    // do something here

END:
    cout << "free" << endl;
    free(p);
    return 0;
}

/* Demonstrates do-while(0) cleanup instead of goto */
int ff() {
    int *p = (int *)malloc(sizeof(int));
    if (!p) return -1;

    *p = 10;
    cout << *p << endl;

    int error = 0;
#ifndef DEBUG
    error = 1;
#endif

    do {
        if (error)
            break;

        // do something here
    } while (0);

    cout << "free" << endl;
    free(p);
    return 0;
}

/* Demonstrates block scope and shadowing */
int fc() {
    int k1 = 10;
    cout << k1 << endl;

    do {
        int k1 = 100;   // shadows outer k1
        cout << k1 << endl;
    } while (0);

    cout << k1 << endl;
    return 0;
}

int main() {
    if (1 > 0)
        fun();

    if (2 > 0)
        fun1();

    f();
    ff();
    fc();

    return 0;
}
