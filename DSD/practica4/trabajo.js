var http = require("http");
var url = require("url");
var fs = require("fs");
var path = require("path");
var socketio = require("socket.io");
var MongoClient = require('mongodb').MongoClient;
var MongoServer = require('mongodb').Server;
var mimeTypes = { "html": "text/html", "jpeg": "image/jpeg", "jpg": "image/jpeg", "png": "image/png", "js": "text/javascript", "css": "text/css", "swf": "application/x-shockwave-flash"};


var estadoPersiana;
var otroestadoPersiana;
var estadoAire;
var otroestadoAire;
var comprobador=false;
function accionAire(val1) {
	if (val1>40 && estadoPersiana=="Subo persianas" && otroestadoPersiana=="Subo persianas"){estadoAire="Aire acondicionado encendido";otroestadoAire="Aire acondicionado encendido";estadoPersiana="Bajo persianas";otroestadoPersiana="Bajo persianas";comprobador=true; return "Aire acondicionado encendido y persiana bajada";}
 	else if (val1>=25){estadoAire="Aire acondicionado encendido";otroestadoAire="Aire acondicionado encendido"; return "Aire acondicionado encendido";}
	else if (val1<15) {estadoAire="Aire acondicionado apagado";otroestadoAire="Aire acondicionado apagado"; return "Aire acondicionado apagado";}
	else if (val1>15 && val1<=25 && estadoPersiana=="Subo persianas" && otroestadoPersiana=="Subo persianas") {estadoAire="";estadoPersiana="Bajo persianas";otroestadoPersiana="Bajo persianas"; otroestadoAire="Aire acondicionado apagado";comprobador=true; return "Bajo persianas";}
	else {estadoAire="";otroestadoAire="Aire acondicionado apagado"; return "";}
}

function accionPersiana(val2) {
	if (comprobador==false){
		console.log("entro");
	if (val2>=60 && estadoPersiana=="Bajo persianas"){estadoPersiana="Subo persianas"; otroestadoPersiana="Subo persianas"; return "Bajo persianas";}

	else if (val2>=60){estadoPersiana="Bajo persianas"; otroestadoPersiana="Bajo persianas"; return "Bajo persianas";}

	else if (val2<15 && estadoPersiana=="Subo persianas" ){estadoPersiana="Bajo persianas";otroestadoPersiana="Bajo persianas"; return "Bajo persianas";}

	else if (val2<15) {estadoPersiana="Subo persianas";otroestadoPersiana="Subo persianas"; return "Subo persianas";}

	else {estadoPersiana=""; otroestadoPersiana="Bajo persianas"; return "";}
}else {estadoPersiana=""; otroestadoPersiana="Bajo persianas"; return "";}

}

var httpServer = http.createServer(
	function(request, response) {
		var uri = url.parse(request.url).pathname;
		if (uri=="/") uri = "/sensor.html";
		if (uri=="/funcion") uri = "/funcion.html";



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
mongoClient.connect("mongodb://localhost:27017/mibd", function(err, db) {
	httpServer.listen(8080);
	var io = socketio.listen(httpServer);

	db.createCollection("Trabajo", function(err, collection){
    	io.sockets.on('connection', function(client) {

	//		client.emit('my-address', {host:client.request.connection.remoteAddress, port:client.request.connection.remotePort});

			client.on('enviar', function (data) {

				var aire=accionAire(data.temperatura);
				var persiana=accionPersiana(data.luz);
				comprobador=false;
				client.emit('AccionAire', {aire: aire});
				client.emit('AccionPersiana', {persiana: persiana});

				collection.insert(data, {safe:true}, function(err, result) {});
				io.sockets.emit('Alerta', {persiana: estadoPersiana, aire: estadoAire});
				io.sockets.emit('Cambio',{persiana: otroestadoPersiana, aire: otroestadoAire});

				io.sockets.emit('Cambio2',{persiana: otroestadoPersiana, aire: otroestadoAire});

				collection.find({}).sort({$natural:-1}).limit(1).toArray(function(err,results){
					io.sockets.emit('Valores',results);
				});


			});
			//client.on('Renovar', function (data){
							io.sockets.emit('Alerta', {persiana: estadoPersiana, aire: estadoAire});

							io.sockets.emit('Cambio',{persiana: otroestadoPersiana, aire: otroestadoAire});

							io.sockets.emit('Cambio2',{persiana: otroestadoPersiana, aire: otroestadoAire});


							collection.find({}).sort({$natural:-1}).limit(1).toArray(function(err,results){
								io.sockets.emit('Valores',results);
							});
				//		});

			collection.find({}).sort({$natural:-1}).limit(1).toArray(function(err,results){
				io.sockets.emit('Valores',results);
			});

			client.on('PersianasUD', function (data) {
				io.sockets.emit('Cambio', {persiana: data.luz, aire: data.temperatura});
				otroestadoPersiana=data.luz;
    	});

 			client.on('AireOO', function (data) {
			  io.sockets.emit('Cambio2', {persiana: data.luz, aire: data.temperatura});
				otrostadoAire=data.temperatura;
			});


		});
    });
});
/*
function calcular ( operacion , put ) {
  if (operacion=="persiana"){
		if(put=="encender"){
			response.write ('Subiendo la persiana, la temperatura subirá');
			return;
		}else{
			response.write ('Bajando la persiana, la temperatura bajará');
			return;
		}
	}
	if(operacion=="aire") {
		if(put=="encender"){
			response.write ('Encendiendo el aire, la temperatura bajará');
			return;
		}else{
			response.write ('Apagando el aire, la temperatura subirá');
			return;
		}
	}
}*/

console.log("Servicio MongoDB iniciado");
