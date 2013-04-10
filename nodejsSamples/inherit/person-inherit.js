
// reference Pro javascript + design patterns

function Person(name) {
    this.name = name;
}

Person.prototype.getName = function() {
    return this.name;
}

function Author(name, books) {
    // Person.call(this, name);
    Author.superclass.constructor.call(this, name);
    this.books = books;
}

function extend(subClass, superClass) {
    var F = function() {};
    F.prototype = superClass.prototype;
    subClass.prototype = new F();
    subClass.prototype.constructor = subClass;
    subClass.superclass = superClass.prototype;
    if(superClass.prototype.constructor == Object.prototype.constructor) {
        superClass.prototype.constructor = superClass;
    }
}
// Author.prototype = new Person();
// Author.constructor = Author;
extend(Author, Person);

Author.prototype.getBooks = function(){
    return this.books;
}

Author.prototype.introduction = function () {
    var books = this.getBooks();
    var msg;
    if (books)
        msg = books.join(', ');

    console.log(this.getName() + " has " + msg + '.');
}

function Student(name, books, school) {
    Student.superclass.constructor.call(this, name, books);
    this.school = school;
}

extend(Student, Author);

Student.prototype.getSchool = function() {
    return this.school;
}

Student.prototype.introduction = function() {
    console.log("=========================")
    console.log(this.getName() + " is a " + this.getSchool() + " student.");
    Student.superclass.introduction.call(this);
}

var a = new Author('Sue', ['book1', 'book2']);
a.introduction();

var s = new Student('Jon', ['book3', 'book4'], 'test school');
s.introduction();

