// from http://golang.org/doc/effective_go.html#web_server
package main

import (
    "flag"
    "http"
    "io"
    "log"
    "template"
)

var addr = flag.String("addr", ":1718", "http service address") // Q=17, R=18
var fmap = template.FormatterMap{
    "html": template.HTMLFormatter,
    "url+html": UrlHtmlFormatter,
}
var templ = template.MustParse(templateStr, fmap)

func main() {
    flag.Parse()
    http.Handle("/", http.HandlerFunc(QR))
    err := http.ListenAndServe(*addr, nil)
    if err != nil {
        log.Fatal("ListenAndServe:", err)
    }
}

func QR(w http.ResponseWriter, req *http.Request) {
    templ.Execute(w, req.FormValue("s"))
}

func UrlHtmlFormatter(w io.Writer, fmt string, v ...interface{}) {
    template.HTMLEscape(w, []byte(http.URLEscape(v[0].(string))))
}


const templateStr = `
<html>
<head>
<title>QR Link Generator</title>
</head>
<body>
{.section @}
<img src="http://chart.apis.google.com/chart?chs=300x300&cht=qr&choe=UTF-8&chl={@|url+html}"
/>
<br>
{@|html}
<br>
<br>
{.end}
<form action="/" name=f method="GET"><input maxLength=1024 size=70
name=s value="" title="Text to QR Encode"><input type=submit
value="Show QR" name=qr>
</form>
</body>
</html>
`
