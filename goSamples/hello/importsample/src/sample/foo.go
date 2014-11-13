package sample

import (
        "fmt"
        "sample/sample2"
)

func Foo() int {
    fmt.Println(GetName())
    fmt.Println(sample2.GetName2())
    return 13
}
