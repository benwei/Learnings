//http://golang.org/doc/articles/json_and_go.html
package main

import (
    "encoding/json"
    "log"
)

type Message struct {
    Name string
    Body string
    Time int64
}

func main() {
    m := new(Message);
    m.Name = "Alice"
    m.Body = "Hello"
    m.Time = 1294706395881547000

    n := Message{"Alice", "Hello", 1294706395881547000}
    n.Name = "Alice2"
    n.Body = "Hi"

    bm, err := json.Marshal(m)
    if err != nil {
            log.Println(err)
    }

    bn, err := json.Marshal(n)
    if err != nil {
            log.Println(err)
    }

    log.Printf("%s", bm);
    log.Printf("%s", bn);
}
