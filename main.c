#include <stddef.h>

#define VIEW_IMPLEMENTATION
#include "view.h"

int main() {
    String_View view = LITERAL_CREATE("TEST");
    printf(View_Print"\n", View_Arg(view));
    printf("%f\n", view_to_float(view_create("69.69", 5)));
}
