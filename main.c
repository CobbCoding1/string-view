#define VIEW_IMPLEMENTATION
#include "view.h"

int main() {
    String_View view = LITERAL_CREATE("   TEST");
    view = view_trim_left(view);
    printf(View_Print"\n", View_Arg(view));
}
