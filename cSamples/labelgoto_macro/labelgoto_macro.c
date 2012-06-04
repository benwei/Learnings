#include <stdio.h>
#define label_goto(label) { goto  x##_lbl ;}
#define label_setshow(label,msg)  { x##_lbl: printf("%s", msg); }

int main(int argc, char **argv)
{
        label_goto(x);

        label_setshow(x,"test");
        return 0;
}
