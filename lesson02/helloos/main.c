// Jason 2021-05-12
#include "vgastr.h"
void main(){
    printf("Hello OS!\nWelcome to new tinyOS world.\n  bye.");
    _strwritepos(10, 5, "Love is more than a word,");
    _strwritepos(10, 6, "it says so much.");
    _strwritepos(10, 7, "When I see these four letters,");
    _strwritepos(10, 8, "I almost feel your touch.");
    return;
}
