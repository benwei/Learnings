#include "testshared.h"
#define MAX_SW_NUM 5
#define dispatch2(s, h)  { int n = (*++s) ? (s - h) % \
                          (sizeof(tdispatch_list)/sizeof(void *) - 1) : \
                          sizeof(tdispatch_list)/sizeof(void *) - 1; \
                          goto *tdispatch_list[n]; }

#define dispatch(s, h)  { int n = (*++s) ? (s - h) % MAX_SW_NUM : MAX_SW_NUM; \
                          goto *tdispatch_list[n]; }

int run(const char *s)
{
        const char *head = s;
        void *tdispatch_list[] = {&&la, &&lb, &&lc, &&ld, &&le, &&lf};
        int a = 1;

        la:
               dmsg("a:%c\n", *s);
               a++;
               dispatch(s, head);
        lb:
               dmsg("b:%c\n", *s);
               a++;
               dispatch(s, head);
        lc:
               a-=2;
               dmsg("c:%c\n", *s);
               dispatch(s, head);
        ld:
               a+=3;
               dmsg("d:%c\n", *s);
               dispatch(s, head);
        le:
               a-=2;
               dmsg("e:%c\n", *s);
               dispatch(s, head);
        lf:
        return a;
}

