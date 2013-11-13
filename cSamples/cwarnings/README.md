
* after make -- output more warnings

main.c:6:5: warning: implicitly declaring library function 'strcat' with type 'char *(char *, const char *)'
    strcat(cathello, "hello");
    ^
main.c:6:5: note: please include the header <string.h> or explicitly provide a declaration for 'strcat'
main.c:7:5: warning: implicitly declaring library function 'printf' with type 'int (const char *, ...)'
    printf("testing string %s\n", cathello);
    ^
main.c:7:5: note: please include the header <stdio.h> or explicitly provide a declaration for 'printf'
2 warnings generated.
