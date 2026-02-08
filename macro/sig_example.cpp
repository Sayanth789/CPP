#include <cstring>
#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

/* ===============================
   (#) Stringizing operator
   =============================== */

// Normal macro: uses s as-is
#define exp(s)  printf("test s is: %s\n", s)

// Stringizing: turns token into string
#define exp1(s) printf("test s is: %s\n", #s)

// Returns argument as string
#define exp2(s) #s


/* ===============================
   (##) Token-pasting operator
   =============================== */

// Concatenates gc_ with argument
#define expA(s) printf("Prefixed string is: %s\n", gc_##s)
#define expB(s) printf("Prefixed string is: %s\n", gc_##s)

// Symbols that must exist
const char *gc_hello  = "I am gc_hello";
#define gc_hello1 "I am gc_hello1"


/* ===============================
   Macro behaving like function
   =============================== */

#define MAX(a, b) ((a) > (b) ? (a) : (b))


int main() {

    /* ---------- (#) stringizing ---------- */

    exp("hello");      // normal string
    exp1(hello);       // token → "hello"

    string str = exp2(bac);
    cout << str << " " << str.size() << endl;

    // Spaces are normalized to a single space
    string str1 = exp2(asda    bac);
    cout << str1 << " " << str1.size() << endl;


    /* ---------- (##) token pasting ---------- */

    expA(hello);    // gc_hello
    expB(hello1);   // gc_hello1


    /* ---------- MAX macro ---------- */

    int max_val = MAX(3, 6);
    cout << max_val << endl;

    return 0;
}
