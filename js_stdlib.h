#pragma once
#include <mujs.h>
#include "exec.h"


void js_add_std_function(js_State *J, js_CFunction fun, const char *name, int length) {
    js_newcfunction(J, fun, name, length);
    js_setglobal(J, name);
}

void c_js_print(js_State *J) {
    const char* s = js_tostring(J, 1);
    printf("%s", s);
}

void c_js_println(js_State *J) {
    const char* s = js_tostring(J, 1);
    printf("%s\r\n", s);
}

void c_js_exec(js_State *J) {
    const char* c = js_tostring(J, 1);
    std::string r = exec(c);
    js_pushstring(J, r.c_str());
}


void js_register_stdlib(js_State *J) {
    js_add_std_function(J, c_js_print, "print", 1);
    js_add_std_function(J, c_js_println, "println", 1);
    js_add_std_function(J, c_js_exec, "exec", 1);
}
