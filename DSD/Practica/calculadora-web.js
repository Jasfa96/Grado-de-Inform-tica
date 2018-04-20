var http = require("http");
var url = require("url");
var fs = require("fs");
var path = require("path");
var socketio = require("socket.io");
var MongoClient = require('mongodb').MongoClient;
var MongoServer = require('mongodb').Server;
var mimeTypes = { "html": "text/html", "jpeg": "image/jpeg", "jpg": "image/jpeg", "png": "image/png", "js": "text/javascript", "css": "text/css", "swf": "application/x-shockwave-flash"};
function accionTemp(val1) {
                 //   console.log("entra en accion temp: " + val1);

	if (val1>30)
        return "Aire ON";
	else if (val1<15) return "Aire OFF";
	else return "Aire OFF";
}
function accionLum(val2) {
              //  console.log("entra en accion lum: " + val2);

	if (val2 >=50) return "Subo persianas";
	else if (val2 <50 ) return "Bajo persianas";
	else return "Error: Par&aacute;metros no v&aacute;lidos";
}
var httpServer = http.createServer(
	function(request, response) {
		var uri = url.parse(request.url).pathname;
		if (uri=="/sensores") uri = "/sensor.html";
  		if (uri=="/control") uri = "/control.html";

		var fname = path.join(process.cwd(),uri);
		fs.exists(fname, function(exists) {
			if (exists) {
				fs.readFile(fname, function(err, data){
					if (!err) {
						var extension = path.extname(fname).split(".")[1];
						var mimeType = mimeTypes[extension];
						response.writeHead(200, mimeType);
						response.write(data);
						response.end();
					}
					else {
						response.writeHead(200, {"Content-Type": "text/plain"});
						response.write('Error de lectura en el fichero: '+uri);
						response.end();
					}
				});
			}
			else{
				console.log("Peticion invalida: "+uri);
				response.writeHead(200, {"Content-Type": "text/plain"});
				response.write('404 Not Found\n');
				response.end();
			}
		});
	}
);







var mongoClient = new MongoClient(new MongoServer('localhost', 27017));
mongoClient.connect("mongodb://localhost:27017/DatosLumTemp", function(err, db) {
	httpServer.listen(8080);
	var io = socketio.listen(httpServer);
	/*if(window.Prototype) {
       delete Object.prototype.toJSON;
       delete Array.prototype.toJSON;
       delete Hash.prototype.toJSON;
       delete String.prototype.toJSON;
}*/

	db.createCollection("Datos", function(err, collection){
    	io.sockets.on('connection',	function(client) {//Cuando un cliente accede a la pagina envia connection
			client.on('poner', function (data) {
                var aire =accionTemp(data.temp);
                var persiana =accionLum(data.lum);
                          //  console.log("valor persioana" + persiana);
                client.emit('AccionLum', {persi: persiana});
                client.emit('AccionTemp', {air: aire});

				collection.insert(data,{safe:true}, function(err, result) {});
			io.sockets.emit('Alerta', {persi: persiana, air: aire});
                collection.find({}).sort({$natural:-1}).limit(1).toArray(function(err,results)
                {
                io.sockets.emit('Valores',results);
                });

			});


            client.on('BajaPersianas', function (data) {
                console.log("entra");

            		io.sockets.emit('Alerta', {persi: data.per, air: data.air});


            });

             client.on('AireONOFF', function (data) {
                console.log("entra");

            			io.sockets.emit('Alerta', {persi: data.per, air: data.air});


            });
			/*client.on('obtener', function (data) {

				collection.find(data).toArray(function(err, results){
					client.emit('obtener', results);
				});
			});*/
		});
    });
});
console.log("Servicio MongoDB iniciado");



/*
	httpServer.listen(8080);
	var io = socketio.listen(httpServer);

    	io.sockets.on('connection',	function(client) {//Cuando un cliente accede a la pagina envia connection
			client.on('Temperatura', function (data) {
                resultstemp=accionTemp(data.temp);

				client.emit('AccionTemp', resultstemp);
			});
			client.on('Luminosidad', function (data) {
                    resultlum=accionLum(data.lum);
					client.emit('AccionLum', resultlum);
			});
		});

*/
