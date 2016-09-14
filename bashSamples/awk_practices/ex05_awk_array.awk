function listmatrix(m, row, array)
{
    printf("================\nm%d :%d [{%d, %d, %d}\n",  m, row, array[0,0], array[1,0], array[2,0])
    printf("m%d :%d [{%d, %d, %d}\n",  m, row, array[0,1], array[1,1], array[2,1])
    printf("m%d :%d [{%d, %d, %d}\n",m, row, array[0,2], array[1,2], array[2,2])
}

function get_a_matrix(array)
{
    r=getline
    if (r != 1) return 1
    array[0,0] = $1
    array[1,0] = $2
    array[2,0] = $3
    r=getline
    if (r != 1) return 1
    array[0,1] = $1
    array[1,1] = $2
    array[2,1] = $3
    r=getline
    if (r != 1) return 1
    array[0,2] = $1
    array[1,2] = $2
    array[2,2] = $3
    return 0
}

function main() {
    for(x=0; x < 3; x++) {
        r=get_a_matrix(array0)
        if (r == 1) return 1
        listmatrix(1, NR, array0)

        r = get_a_matrix(array1)
        if (r == 1) return 1
        listmatrix(2, NR, array1)
        print "m0=m1+m2"
        for (i = 0; i < 3; i++ ){
            for (j = 0; j < 3; j++) {
                sum[i,j] = array0[i,j] + array1[i,j]
            }
        }
        listmatrix(0, 0, sum)
    }
}

BEGIN {
    main()
}
