#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *data;
    size_t len;
} String_View;

String_View view_create(char *str, size_t len) {
    String_View view = {
        .data = str,
        .len = len,
    };
    return view;
}

char *view_to_cstr(String_View view) {
    char *str = malloc(sizeof(char) * view.len+1);
    strncpy(str, view.data, view.len);
    str[view.len] = '\0';
    return str;
}

int view_cmp(String_View a, String_View b) {
    if(a.len != b.len) return 0;
    for(size_t i = 0; i < a.len; i++) {
        if(a.data[i] != b.data[i]) {
            return 0;
        }
    }
    return 1;
}

int main() {
    String_View view = view_create("Hello, world!", sizeof("Hello, world!")-1);
    String_View view2 = view_create("Hello, world!", sizeof("Hello, world!")-1);
    printf("%d\n", view_cmp(view, view2));

}
