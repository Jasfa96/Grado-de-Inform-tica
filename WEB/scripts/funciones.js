function toggle (element) {
  var relacionadas = document.getElementById('not-relacionadas')
  var noti = document.getElementById('noti');
  var imgPrinc = document.getElementById('img-princ');
  var imgTweet1 = document.getElementById('tweet-cdproject');
  var imgTweet2 = document.getElementById('tweet-guerrilla');
  var lateral= document.getElementById('panel-lateral');

  if (isElementHidden(element)) {
    relacionadas.style.display = 'none';
    element.style.display = 'block';
    noti.style.width = "600px";
    imgPrinc.style.width = "400px";
    if(imgTweet1!=null)
    imgTweet1.style.width = "330px";
    if(imgTweet2!=null)

    imgTweet2.style.width = "330px";
    if(imgTweet1!=null)

    imgTweet1.style.height = "400px";
    if(imgTweet2!=null)

    imgTweet2.style.height = "400px";
    lateral.style.width="594px";

  } else {
    relacionadas.style.display = 'block';
    element.style.display = 'none';
    noti.style.width = "900px";
    imgPrinc.style.width = "400px";
    if(imgTweet1!=null)

    imgTweet1.style.width = "400px";
    if(imgTweet2!=null)

    imgTweet2.style.width = "400px";
    lateral.style.width="300px";
  }
}

function isElementHidden (element) {
  return window.getComputedStyle(element, null).getPropertyValue('display') === 'none';
}

function DameLaFechaHora() {
  var hora = new Date()
  var hrs = hora.getHours();
  var min = hora.getMinutes();
  var hoy = new Date();
  var m = new Array();
  var d = new Array()
  var an= hoy.getYear();
  m[0]="Enero"; m[1]="Febrero"; m[2]="Marzo";
  m[3]="Abril"; m[4]="Mayo"; m[5]="Junio";
  m[6]="Julio"; m[7]="Agosto"; m[8]="Septiembre";
  m[9]="Octubre"; m[10]="Noviembre"; m[11]="Diciembre";

  if(min<10){
    min = "0"+min;
  }

  var salida = "Escrito el " + hoy.getDate() + " de " + m[hoy.getMonth()] + " a las " + hrs + ":" + min;

  return salida;
}


function enviarComentario(){
  var lista_comentarios = document.getElementById('lista-comentarios');
  var nuevo_comentario = document.createElement("ARTICLE");
  nuevo_comentario.className = "comentario";
/*
  var x = document.forms["formComentario"]["email"].value;
  if (x == "") {
      alert("El campo de email es obligatorio.");
      return false;
  }

//Introduccion de autor
  var p_autor = document.createElement("P");
  p_autor.className = "autor-comentario";
  var autor = document.createTextNode(document.getElementById("nombre").value);
  p_autor.appendChild(autor);
/*
  x = document.forms["formComentario"]["nombre"].value;
  if (x == "") {
      alert("El campo de nombre es obligatorio.");
      return false;
  }
  */

//Introduccion de fecha

  var p_fecha = document.createElement("P");
  p_fecha.className = "fecha-hora-comentario";
  var fecha = document.createTextNode(DameLaFechaHora());
  p_fecha.appendChild(fecha);

//Introduccion de comentario

var p_comentario = document.createElement("P");
p_comentario.className = "cuerpo-comentario";
var cuerpo = document.createTextNode(document.getElementById("mensaje").value);
p_comentario.appendChild(cuerpo);

x = document.forms["formComentario"]["mensaje"].value;
if (x == "") {
    alert("No has escrito un comentario.");
    return false;
}

/////////////////
  //nuevo_comentario.appendChild(p_autor);
  nuevo_comentario.appendChild(p_fecha);
  nuevo_comentario.appendChild(p_comentario);

  lista_comentarios.appendChild(nuevo_comentario);

/////////////////////
document.getElementById("formComentario").reset();

}

function filtro(texto){
  var textfield = document.getElementById(texto);
  var regex =/\b(puta|religion|puto|politica|mierda|coño|joder|subnormal|cipollo|fuck|shit|polla)\b/gi;
  if(textfield.value.search(regex) > -1) {
    textfield.value = textfield.value.replace(regex, function (regex) {
        return new Array(regex.length+1).join('*');
    });
  }
}
