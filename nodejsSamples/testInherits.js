require('./lib/Method');

function Book(name, price)
{
    this.name = name;
    this.price = price;
    this.type = 'book';
}

Book.method('browse', function (){
    return "The name of the book is '" + this.name + "' which costs " + this.price + ".";
});


var Bookjs = function (name, price) {
    this.name = name;
    this.category = 'Javascript';
    this.price = price;
}.inherits(Book).method('get_category', function (){
    return this.browse() + " Category is " + this.category + ".";
});

var book = new Bookjs('JS Good Parts', 300);
console.log(book.get_category());
