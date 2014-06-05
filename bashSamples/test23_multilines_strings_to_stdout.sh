#!/bin/sh
## written by ben6 2014-06
show_multilines_helper() {
    cat <<- EOF
    this is a helper in multilines
    use cat and EOF command,
    it is a really a good idea.
    you should put EOF at the leading of line
    because I got error on osx 10.9.2 as follow:
    
    test23_multilines_strings_to_stdout.sh: line 11: syntax error: unexpected end of file
EOF
}

show_multilines_helper
