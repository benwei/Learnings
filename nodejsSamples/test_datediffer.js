// DateDiffer sample code
/*
MIT License
Copyright (C) 2012 Ben Wei (ben@staros.mobi)

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/

function DateDiffer() {
    var dtstart = new Date();
    var dtend;

    this.reset= function () {
        dtstart = new Date()
    }

    function diffms(start, end) {
        return end.getTime() - start.getTime();
    }

    this.show = function () {
        dtend = new Date();
        var dtdiff = dtend.getTime() - dtstart.getTime();
        console.log(dtdiff + "ms");
    }
}

var dd = new DateDiffer();

for (var i = 0; i < 10; i++) {
    dd.reset()
    var counter = 10000000;
    var a=0;
    while (counter-- > 0) {
        a++;
    }


    dd.show();
}
