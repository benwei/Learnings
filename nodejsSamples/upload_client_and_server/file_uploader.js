var http = require('http'),
    mime = require('mime'),
    path = require('path'),
    fs = require('fs');

function doUpload(filename) {
  var boundary = Math.random();
  var post_data = [];
  var mimetype = mime.lookup(filename);

  function isImage(mimetype) {
    return mimetype.match(/image\/.*/);
  }

  function EncodeFieldPart(boundary,name,value) {
    var return_part = "--" + boundary + "\r\n";
    return_part += "Content-Disposition: form-data; name=\"" + name + "\"\r\n\r\n";
    return_part += value + "\r\n";
    return return_part;
  }

  function EncodeFilePart(boundary,type,name,filename) {
    var return_part = "--" + boundary + "\r\n";
    return_part += "Content-Disposition: form-data; name=\"" + name + "\"; filename=\"" + filename + "\"\r\n";
    return_part += "Content-Type: " + type + "\r\n\r\n";
    return return_part;
  }

  function MakePost(post_data, boundary) {

    var length = 0;

    for(var i = 0; i < post_data.length; i++) {
      length += post_data[i].length;
    }

    var post_options = {
      host: 'localhost',
      port: '8000',
      path: '/upload',
      method: 'POST',
      headers : {
        'Content-Type' : 'multipart/form-data; boundary=' + boundary,
        'Content-Length' : length
      }
    };

    var post_request = http.request(post_options, function(response){
      response.setEncoding('utf8');
      response.on('data', function(chunk){
        console.log(chunk);
      });
    });

    for (var i = 0; i < post_data.length; i++) {
      post_request.write(post_data[i]);
    }
    post_request.end();
  }

  post_data.push(new Buffer.from(EncodeFieldPart(boundary, 'image_meta', 'origin'), 'ascii'));
  post_data.push(new Buffer.from(EncodeFieldPart(boundary, 'object_id', 'sample-object-id'), 'ascii'));
  post_data.push(new Buffer.from(EncodeFieldPart(boundary, 'Last-Modified', 'Tue, 15 Nov 1994 12:45:26 GMT'), 'ascii'));
  var field_type = 'ascii';
  var encoding = {encoding: 'utf8'};
  if (isImage(mimetype) ) {
    encoding.encoding = 'binary';
    field_type = 'binary';
  }

  post_data.push(new Buffer.from(EncodeFilePart(boundary, mimetype, 'upload', filename), field_type));

  var file_reader = fs.createReadStream(filename, encoding);
  var file_contents = '';
  file_reader.on('data', function(data){
    file_contents += data;
  });
  file_reader.on('end', function(){
    post_data.push(new Buffer.from(file_contents, field_type == 'binary' ? field_type: 'utf8'));
    post_data.push(new Buffer.from("\r\n--" + boundary + "--"), 'ascii');

    MakePost(post_data, boundary);
  });
}

function syntax() {
  var program = path.basename(process.argv[1]);
  console.log("syntax: " + program + " <filename>");
}

function main() {
  process.argv.forEach(function(arg, index, array) {
    console.log("argv[" + index + "]=" + arg);
  });

  var argc = process.argv.length;

  if (argc > 2) {
    doUpload(process.argv[2]);
  } else {
    syntax();
  }
}

main();
