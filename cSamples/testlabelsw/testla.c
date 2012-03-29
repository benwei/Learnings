#include "stdio.h"

#define dispatch(s, h)  { int n = (*++s) ? (s - h) % \
                          (sizeof(tdispatch_list)/sizeof(void *) - 1) : \
                          sizeof(tdispatch_list)/sizeof(void *) - 1; \
                          goto *tdispatch_list[n]; }

int run(const char *s)
{
        const char *head = s;
        void *tdispatch_list[] = {&&la, &&lb, &&lc, &&ld};

        la:
               printf("a:%c\n", *s);
               dispatch(s, head);
        lb:
               printf("b:%c\n", *s);
               dispatch(s, head);
        lc:
               printf("c:%c\n", *s);
               dispatch(s, head);

        ld:
        return 0;
}

int main(int argc, char **argv) {
        const char *s = "hello";
        run(s);
        return 0;
}

/*
switch(a){
 0:
        lll
        break;
 1:
        sss
        break;
}
*/
