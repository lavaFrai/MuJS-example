#include <cstdio>
#include <mujs.h>

#include "js_stdlib.h"


int main(int argc, char **argv)
{
    js_State *J = js_newstate(NULL, NULL, JS_STRICT);

    js_register_stdlib(J);

    js_dofile(J, "test.js");

    js_freestate(J);
}