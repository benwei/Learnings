package main 

import ( 
        "fmt" 
        "strings" 
) 

type Reference struct { 
        docNo  int 
        wordNo int 
} 

type Index map[string][]Reference 

func (x Index) AddDoc(docNo int, doc string) { 
        for wordNo, word := range strings.Fields(doc) { 
                ref, ok := x[word] 
                if !ok { 
                        ref = nil 
                } 
                x[word] = append(ref, Reference{docNo, wordNo}) 
        } 
} 

func main() { 
        index := make(Index) 
        docNo := 0 
        doc := "words to have stored and returned to " 
        index.AddDoc(docNo, doc) 
        docNo = 1 
        doc = "have to too two two" 
        index.AddDoc(docNo, doc) 
        fmt.Println(index) 
} 
