
// npm install sqlite3

var sqlite3 = require('sqlite3')

var usersDB = new sqlite3.Database("users.db");

function upsertValues(usersDB, items) {
        var stmt = usersDB.prepare("INSERT or replace INTO foobar VALUES (?, ?)");
        for (var i = 0; i < items.length; i++) {
            stmt.bind(items[i].pid, items[i].oid);
            stmt.run(function (err) {
                    if (err) 
                    console.log(err); });
        }
        stmt.finalize();
}

function newItem(p, o) {
    return {pid:p, oid:o};
}

var counter = 0;

function testUpsert(cb) {
    usersDB.serialize(function() {

            var items = [];

            items.push(newItem('aa', 'bb'))
            items.push(newItem('aa1', 'bb1'))
            items.push(newItem('aa', 'bb'))
            items.push(newItem('aa1', 'bb2'))
            items.push(newItem('aa2', 'bb1'))


            upsertValues(usersDB, items);


            items.push(newItem('aa2', 'bb0'))

            upsertValues(usersDB, items);

            console.log('->' + counter +  '<-')
            console.log(items);
            usersDB.each("SELECT * FROM foobar", function(err, row) {
                    console.log(row.pid + ": " + row.oid);
                    });

            
            if (counter == 0) {
                counter++;
                setTimeout(function (){
                        cb()}, 2);
            } else {
                usersDB.close();
            }
    }
    );
}

var sql1 = "DROP TABLE foobar";
var sql2 = "CREATE TABLE foobar(pid TEXT not NULL, oid TEXT not NULL, Primary Key(pid, oid))";

usersDB.run(sql1, function (err){
        usersDB.run(sql2, function (err){
            testUpsert(testUpsert);
            });
        }); 

