#!/bin/bash
i=0
until [ $((i++)) -eq 10 ]; do
    echo -n " $i"
done
echo ""

### result
#> 1 2 3 4 5 6 7 8 9 10
#>
