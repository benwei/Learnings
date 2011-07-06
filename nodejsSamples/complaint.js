// @file complaint.js
// Sample from Rayan_Dahl's presentation

require "http"


function afterDB1(dbres, cb) {
	db2.query(dbres[1], function(db2res) {
		afterDB2(db2res, cb);
	});
}


function afterDB2(db2res, cb) {
	cb();
}

function afterHttpRequest(res, cb) {
	db2.query(res.headers['cookie'], function(dbres) {
		afterDB1(dbres, cb);
	});
}

function get(cb) {
  http.get({host: "google.com"} , function(res) {
		afterHttpRequest(res, cb);
	});
}


