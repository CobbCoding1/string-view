# String View Implementation in C

## Quick Start
```sh
./build.sh
./main
```
Import into file like this
```C
#define VIEW_IMPLEMENTATION
#include "view.h"
```

### Structs
```C
typedef struct {
    char *data; // pointer to a string
    size_t len;
} String_View;
```

### Functions
```C
String_View view_create(char *str, size_t len); // Creates a String_View from a pointer to a string and a length
char *view_to_cstr(String_View view); // Converts a String View into a cstr. (currently mallocs but that will change)
String_View view_trim_left(String_View view); // Trims left until not whitespace
String_View view_trim_right(String_View view); // Trims right until not whitespace
int view_cmp(String_View a, String_View b); // Compares two String_Views
int view_starts_with_c(String_View view, char c); // Checks if String_View starts with character
int view_starts_with_s(String_View a, String_View b); // Checks if String_View starts with other String_View
int view_ends_with_c(String_View view, char c); // Checks if String_View ends with character
int view_ends_with_s(String_View a, String_View b); // Checks if String_View ends with other String_View
int view_contains(String_View haystack, String_View needle); // Check if String_View contains another String_View
size_t view_first_of(String_View view, char target); // Returns index of first occurance of character in String_View
size_t view_last_of(String_View view, char target); // Returns index of last occurance of character in String_View
size_t view_split(String_View view, char c, String_View *arr, size_t arr_s); // Splits String_View by delimiter c, places String_Views into array arr
String_View view_chop(String_View view, char c); // Removes starting characters up until index of c
String_View view_rev(String_View view, char *data, size_t data_s); // Reverses Sring_View
size_t view_find(String_View haystack, String_View needle); // Finds String_View in another String_View
```

### Macros
```C
View_Print // expands to %.*s for printing with printf
View_Arg(view) // expands for printf passing the length and the data 
LITERAL_CREATE(lit) // expands to view_create(lit, sizeof(lit)-1) for creating String_Views
```
