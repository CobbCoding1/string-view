#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>

typedef struct {
    char *data;
    size_t len;
} String_View;

#define View_Print "%.*s"

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

String_View view_trim_left(String_View view) {
    size_t i = 0;
    while(isspace(view.data[i])) {
        i++;
    }
    return (String_View){
        .data = view.data + i,
        .len = view.len - i,
    };
}

String_View view_trim_right(String_View view) {
    size_t i = view.len - 1;
    while(isspace(view.data[i])) {
        i--;
    }
    return (String_View){
        .data = view.data,
        .len = i+1,
    };
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

int view_starts_with(String_View view, char c) {
    return view.data[0] == c;
}

int view_ends_with(String_View view, char c) {
    return view.data[view.len-1] == c;
}

size_t view_first_of(String_View view, char target) {
    for(size_t i = 0; i < view.len; i++) {
        if(view.data[i] == target) {
            return i;
        }
    }
    return 0;
}

size_t view_last_of(String_View view, char target) {
    for(size_t i = view.len-1; i > 0; i--) {
        if(view.data[i] == target) {
            return i;
        }
    }
    return 0;
}

size_t view_split(String_View view, char c, String_View *arr, size_t arr_s) {
    char *cur = view.data;
    size_t arr_index = 0;
    size_t i;
    for(i = 0; i < view.len; i++) {
        if(view.data[i] == c) {
            if(arr_index < arr_s-2) {
                String_View new = {.data = cur, .len = view.data + i - cur};
                arr[arr_index++] = new;
                cur = view.data + i + 1;
            } else {
                String_View new = {.data = view.data + i+1, .len = view.len - i-1};
                arr[arr_index++] = new;
                return arr_index;
            }
        }
    }
    String_View new = {.data = cur, .len = view.data + i - cur};
    arr[arr_index++] = new;
    return arr_index;
}

String_View view_chop(String_View view, char c) {
    size_t i = 0;
    while(view.data[i] != c && i != view.len) {
        i++;
    }
    if(i < view.len) {
        i++; 
    }
    return (String_View){
        .data = view.data + i,
        .len = view.len - i,
    };
}

String_View view_rev(String_View view, char *data, size_t data_s) {
    if(view.len >= data_s) {
        return (String_View){.data = NULL, .len = 0};
    }
    String_View result;
    result.data = data;
    result.len = view.len;
    for(int i = view.len-1; i >= 0; i--) {
        result.data[view.len-1 - i] = view.data[i]; 
    }
    return result;
}

int main() {
    String_View view = view_create("hello there sir expand one", sizeof("hello there sir expand one")-1);
    printf("%d\n", view_ends_with(view, 'e'));
}
