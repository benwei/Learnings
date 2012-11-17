package main 

import ( 
        "bytes" 
        "fmt" 
        "encoding/gob" 
        "strings" 
) 

type Reference struct { 
        DocNo  int 
        WordNo int 
} 

type Index map[string][]Reference 

func (x Index) AddDoc(DocNo int, doc string) { 
        for wordNo, word := range strings.Fields(doc) { 
                ref, ok := x[word] 
                if !ok { 
                        ref = nil 
                } 
                x[word] = append(ref, Reference{DocNo, wordNo}) 
        } 
} 

func EncodeAndDecode(in, out interface{}) error{ 
        b := new(bytes.Buffer) 
        enc := gob.NewEncoder(b) 
        err := enc.Encode(in) 
        if err != nil { 
                return err 
        } 
        dec := gob.NewDecoder(b) 
        err = dec.Decode(out) 
        if err != nil { 
                return err 
        } 
        return nil 
} 

func main() { 
        indexEnc := make(Index) 
        DocNo := 0 
        doc := "words to have stored and returned to " 
        indexEnc.AddDoc(DocNo, doc) 
        DocNo = 1 
        doc = "have to too two two" 
        indexEnc.AddDoc(DocNo, doc) 
        indexDec := make(Index) 
        err := EncodeAndDecode(indexEnc, &indexDec) 
        if err != nil { 
                fmt.Println(err) 
        } 
        fmt.Println(indexEnc) 
        fmt.Println(indexDec) 
} 

