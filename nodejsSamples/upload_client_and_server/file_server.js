var formidable = require('formidable'),
    http = require('http'),
    path = require('path'),
    fs = require('fs');
    util = require('util');

var logger = console;
logger.debug = console.log;

function dumpError(err) {
  if (typeof err === 'object') {
    if (err.message) {
      logger.debug('\nMessage: ' + err.message)
    }
    if (err.stack) {
      logger.debug('\nStacktrace:')
      logger.debug('====================')
      logger.debug(err.stack);
    }
  } else {
    console.log('dumpError :: argument is not an object');
  }
}

var upload_dir = __dirname + "/tmp/";

function saveUploadFile(req, res) {
  var form = new formidable.IncomingForm();
  fs.mkdir(upload_dir, 0776, function(err) {
    console.log("err:" + err);
  });

  form.uploadDir = upload_dir;
  form.keepExtensions = true;

  form.on('progress', function (bytesReceived, bytesExpected) {
    console.log("progress: "+bytesReceived+ "/" + bytesExpected + ' in bytes');
  })
  .on('fileBegin', function (name, file) {
    console.log("field[" + name + "]");
  })
  .on('field', function(name, value) {
    console.log("field[" + name + "]: " + value);
  })
  .on('error', function(err) {
    console.log('error:' + err);
    dumpError(err);
  })
  .on('aborted', function() {
    console.log('aborted: timeout or close');
  })
  .on('file', function(name, file) {
    console.log("field name:" + name +
      "\nfile type: " + file.type + 
      "\nfile name:" + file.name +
      "\nfile path:" + file.path +
      "\nfile size:" + file.size +
      "\nlastModifiedDate" + file.lastModifiedDate);
  })
  
  form.on("complete", function (err) {
  });

  var parsedForm = {}
  form.parse(req, function(err, fields, files) {
    console.log("parse!");
    parsedForm.fields = fields;
    parsedForm.files = files;
    res.writeHead(200, {'content-type': 'text/plain'});
    res.write('received upload:\n\n');
    res.end(util.inspect(parsedForm));
  });

  req.addListener('data', function (chunk){
    console.log("chunk " + chunk.length + " bytes.");
  });

  req.addListener('end', function (){
    console.log("response end info");
  });
}

server = http.createServer(function(req, res) {
  if (req.url == '/upload' && req.method.toLowerCase() == 'post') {
    saveUploadFile(req,res);
  } else if (req.url == '/') {

    // show a file upload form
    res.writeHead(200, {'content-type': 'text/html'});
    res.end(
      '<form action="/upload" enctype="multipart/form-data" method="post">'+
      '<input type="text" name="title"><br>'+
      '<input type="file" name="upload" multiple="multiple"><br>'+
      '<input type="submit" value="Upload">'+
      '</form>'
      );

  } else {
    res.writeHead(404, {'content-type': 'text/plain'});
    res.end('404');
  }
});

server.listen(8000);

