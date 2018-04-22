-- phpMyAdmin SQL Dump
-- version 4.5.4.1deb2ubuntu2
-- http://www.phpmyadmin.net
--
-- Host: localhost
-- Generation Time: May 18, 2017 at 12:32 PM
-- Server version: 5.7.18-0ubuntu0.16.04.1
-- PHP Version: 7.0.15-0ubuntu0.16.04.4

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Database: `MotionFreak`
--

-- --------------------------------------------------------

--
-- Table structure for table `comentarios`
--

CREATE TABLE `comentarios` (
  `id` int(11) NOT NULL,
  `noticia` int(11) NOT NULL,
  `autor` varchar(20) COLLATE utf8_spanish_ci NOT NULL,
  `fecha` datetime NOT NULL DEFAULT CURRENT_TIMESTAMP,
  `cuerpo` varchar(500) COLLATE utf8_spanish_ci NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_spanish_ci;

--
-- Dumping data for table `comentarios`
--

INSERT INTO `comentarios` (`id`, `noticia`, `autor`, `fecha`, `cuerpo`) VALUES
(1, 5, 'jefe', '2017-05-16 15:50:09', 'Comentario del jefe en la noticia mother4'),
(2, 1, 'hola', '2017-05-16 15:50:09', 'Comentario de hola en la noticia de horizon'),
(4, 1, 'jefe', '2017-05-17 08:10:20', 'prueba siendo jefe'),
(5, 3, 'jefe', '2017-05-17 08:10:53', 'Comprobando que pueda meter comentarios a las 8:10'),
(6, 1, 'jefe', '2017-05-17 08:20:08', 'prueba2'),
(7, 1, 'jefe', '2017-05-17 08:22:25', 'prueba3'),
(8, 1, 'jefe', '2017-05-17 08:22:51', 'ultima prueba'),
(9, 3, 'jefe', '2017-05-17 09:40:40', 'hsdahagdha'),
(12, 1, 'jefe', '2017-05-17 11:33:21', 'hola desde gestor'),
(13, 1, 'jefe', '2017-05-17 11:40:38', 'comentario editado'),
(14, 1, 'jefe', '2017-05-17 11:41:38', 'hola hola'),
(16, 1, 'jefe', '2017-05-17 11:41:41', 'adios adios'),
(17, 2, 'hola', '2017-05-17 19:10:55', 'BUenas tardes'),
(18, 1, 'redactor', '2017-05-17 19:11:33', 'Comentario');

-- --------------------------------------------------------

--
-- Table structure for table `imagenes`
--

CREATE TABLE `imagenes` (
  `id_noticia` int(11) NOT NULL,
  `dir_img` varchar(30) COLLATE utf8_spanish_ci NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_spanish_ci;

--
-- Dumping data for table `imagenes`
--

INSERT INTO `imagenes` (`id_noticia`, `dir_img`) VALUES
(1, '/img/noticia1-cuerpo.jpeg'),
(1, '/img/noticia1-extra1.png'),
(1, '/img/noticia1-extra2.png'),
(1, '/img/noticia1-extra3.jpg'),
(1, '/img/noticia1-miniatura.jpg'),
(2, '/img/noticia2-cuerpo.png'),
(2, '/img/noticia2-extra1.jpg'),
(2, '/img/noticia2-extra2.jpg'),
(2, '/img/noticia2-miniatura.jpeg'),
(3, '/img/noticia3-cuerpo.jpg'),
(3, '/img/noticia3-extra1.jpg'),
(3, '/img/noticia3-extra2.png'),
(3, '/img/noticia3-miniatura.jpg'),
(4, '/img/noticia4-cuerpo.jpg'),
(4, '/img/noticia4-extra1.png'),
(4, '/img/noticia4-extra2.png'),
(4, '/img/noticia4-miniatura.png'),
(5, '/img/noticia5-cuerpo.jpg'),
(5, '/img/noticia5-extra1.png'),
(5, '/img/noticia5-miniatura.png'),
(6, '/img/noticia6-cuerpo.jpg'),
(6, '/img/noticia6-extra1.jpg'),
(6, '/img/noticia6-extra2.jpg'),
(6, '/img/noticia6-extra3.jpg'),
(6, '/img/noticia6-miniatura.jpg'),
(7, '/img/noticia7-cuerpo.jpg'),
(7, '/img/noticia7-extra1.jpg'),
(7, '/img/noticia7-miniatura.jpg'),
(8, '/img/noticia8-cuerpo.jpg'),
(8, '/img/noticia8-extra1.jpg'),
(8, '/img/noticia8-extra2.png'),
(8, '/img/noticia8-miniatura.png'),
(9, '/img/noticia9-cuerpo.jpg'),
(9, '/img/noticia9-extra1.jpg'),
(9, '/img/noticia9-extra2.jpg'),
(9, '/img/noticia9-miniatura.jpg'),
(10, '/img/noticia10-cuerpo.jpg'),
(10, '/img/noticia10-extra1.jpg'),
(10, '/img/noticia10-extra2.jpg'),
(10, '/img/noticia10-miniatura.jpg'),
(11, '/img/noticia11-cuerpo.jpg'),
(11, '/img/noticia11-miniatura.jpg');

-- --------------------------------------------------------

--
-- Table structure for table `noticias_publicadas`
--

CREATE TABLE `noticias_publicadas` (
  `identificador` int(11) NOT NULL,
  `titular` varchar(120) COLLATE utf8_spanish_ci NOT NULL,
  `autor` varchar(20) COLLATE utf8_spanish_ci DEFAULT NULL,
  `fecha` timestamp NULL DEFAULT NULL,
  `subtitulo` text COLLATE utf8_spanish_ci NOT NULL,
  `entradilla` text COLLATE utf8_spanish_ci NOT NULL,
  `cuerpo` text COLLATE utf8_spanish_ci NOT NULL,
  `seccion` int(11) DEFAULT NULL,
  `miniatura` varchar(30) COLLATE utf8_spanish_ci DEFAULT NULL,
  `fecha_edicion` timestamp NULL DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP,
  `publicada` tinyint(1) NOT NULL DEFAULT '1'
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_spanish_ci;

--
-- Dumping data for table `noticias_publicadas`
--

INSERT INTO `noticias_publicadas` (`identificador`, `titular`, `autor`, `fecha`, `subtitulo`, `entradilla`, `cuerpo`, `seccion`, `miniatura`, `fecha_edicion`, `publicada`) VALUES
(1, 'Horizon Zero Dawn - CD Projekt RED felicita a Guerrilla Games', 'jefe', '2017-05-16 14:03:39', 'CD Project RED parece estar encantado con el videojuego Horizon Zero Dawn y han mostrado cuánto les gusta con unas curiosas imágenes en Twitter', 'Si esta mañana os contamos que Sony y Microsoft habían felicitado a Nintendo por los lanzamientos de The Legend of Zelda Breath of the Wild y Nintendo Switch, ahora os queremos informar de una nueva felicitación entre dos conocidas compañías del sector.', '<span class="centrar-img">\r\n								<img class="img-noticia-grande" id="img-princ" src="img/noticia1-cuerpo.jpeg" ALT="Horizon y The Witcher">\r\n							</span>\r\n<div class="dos-columnas">\r\n							<p> En esta ocasión, ha sido CD Projekt, responsables de The Witcher 3 Wild Hunt, la que ha felicitado a Guerrilla Games por Horizon Zero Dawn para PS4. Además de la felicitación a través de un tuit, CD Projekt también ha publicado una imagen protagonizada por Geralt de Rivia y Aloy: </p>\r\n\r\n							<span class="centrar-img">\r\n								<p>\r\n									<a href="https://twitter.com/CDPROJEKTRED/status/837316575925514241">\r\n										<img class="img-tweet" id="tweet-cdproject" src="/img/noticia1-extra1.png"  ALT="MotionFreak">\r\n									</a>\r\n									<p class="pie-de-foto">\r\n										Imagen del tweet de CD Project.\r\n									</p>\r\n								</p>\r\n							</span>\r\n\r\n							<p>Pero eso no es todo, y es que Guerrilla Games no ha tardado en responder a la felicitación de CD Projekt por el lanzamiento de Horizon Zero Dawn y ha publicado un tuit que incluye un mensaje de agradecimiento y una nueva imagen de Aloy y Geralt de Rivia que no tiene desperdicio. Podéis verla a continuación: </p>\r\n\r\n							<span class="centrar-img">\r\n								<p>\r\n									<a href="https://twitter.com/Guerrilla/status/837735925417390085">\r\n										<img class="img-tweet" id="tweet-guerrilla" src="/img/noticia1-extra2.png"  ALT="MotionFreak">\r\n									</a>\r\n									<p class="pie-de-foto">\r\n										Imagen del tweet de Guerrilla Games.\r\n									</p>\r\n								</p>\r\n							</span>\r\n\r\n							<p>Os recordamos que hace unas horas os hemos presentado un completo unboxing de la edición coleccionista de Horizon Zero Dawn para que no perdáis detalle de todos sus contenidos entre los que destacan un libro de arte y una figura de Aloy.</p></div>', 4, '/img/noticia1-miniatura.jpg', '2017-05-21 22:00:00', 0),
(2, 'Sleeping Dogs -- Donnie Yen protagonizará la adaptación cinematográfica', 'redactor', '2017-05-16 14:03:39', 'Donnie Yen, o lo que es lo mismo Chirrut Îmwe en Rogue One, será el protagonista de la adaptación cinematográfica del videojuego Sleeping Dogs.', 'Hace tiempo que el videojuego de Sleeping Dogs está inactivo, al menos su licencia, y su desarrollador, Unite Front Games desaparecido, parece que si va tomando forma su adaptación cinematográfica. Según ha lanzado Deadline en exclusiva, el actor chino Donnie Yen, conocido por ser el maestro Chirrut Îmwe en Rogue One: Una historia de Star Wars, será el protagonista de la película.', '<span class="centrar-img">\r\n                <img class="img-noticia-grande" id="img-princ" src="/img/noticia2-cuerpo.png" ALT="sleeping-dogs">\r\n              </span><div class="dos-columnas">\r\n              <p>El actor no cesa de acumular proyectos en Hollywood, hace poco le vimos enfrentarse a Vin Diesel en xXx: Reactivated, aunque ahora tendrá el papel principal, no será ni un acompañante ni un villano del montón.\r\n              En Sleeping Dogs, Yen interpretará a un policía encubierto en Hong Kong que trata de infiltrarse en el mundo de las pandillas, con la esperanza de llevarlos ante la justicia, tal vez. La tríada Sun On Yee no se ha nombrado aún, pero teniendo en cuenta que se basa en la película, es más que probable que aparezca. La película tendrá grandes dosis de acción un montón de acción, luchas de kung fu, que como ya ha demostrado en su filmografía, a Yen se le dan muy bien. De momento no hay más información aunque teniendo al protagonista es probable que más nombres, incluidos director y guionista, salgan pronto a la luz.\r\n              La productora de la película será Original Film, encargada de la franquicia Fast and Furious, además de otras películas como Infiltrados en clase y su secuela o Soy Leyenda. Teniendo en cuenta todas estas cintas han triunfado en taquilla no podemos dudar de que harán lo mismo con la adaptación de Sleeping Dogs.\r\n              </p></div>', 8, '/img/noticia2-miniatura.jpeg', '2017-05-21 22:00:00', 0),
(3, 'Frank Miller estará en Heroes Comic Con Madrid 2017', 'jefe', '2017-05-16 14:03:39', 'El 11 y 12 de noviembre tendrá lugar en Madrid la próxima edición de Heroes Comic Con y para ir abriendo boca han lanzado la primera gran confirmación, Frank Miller.', 'Algunos estamos deseando que llegue de una vez por todas la primavera, aunque puede que después de saber que Frank Miller estará en la próxima edición de Heroes Comic Con de Madrid los días 11 y 12 de noviembre, quieras que el frio regrese más rápido que nunca.', '<span class="centrar-img">\r\n                  <img class="img-noticia-grande" id="img-princ" src="/img/noticia3-cuerpo.jpg" ALT="frank-miller">\r\n                </span><div class="dos-columnas">\r\n                <p>Así lo han anunciado los organizadores, uno de los autores más importantes de la historia del cómic estará como invitado de honor, y es que el guionista es toda una leyenda, al fin y al cabo, se trata del creador de Sin City, 300 o El regreso del Caballero Oscuro.\r\n\r\n                Frank Miller pisará por primera vez una convención de cómics en Madrid, y será uno (que no el único) de los platos fuertes de la nueva edición de Heroes Comic Con Madrid, el Salón Internacional del Cómic de la capital, la que hemos conocido antes cómo Expocómic. Esto ha sido posible gracias al trabajo de todo el equipo y a ECC Ediciones, que además contará con un stand propio durante el evento y en el que se desarrollarán todo tipo de actividades (firma de autores, presentación de novedades, etc.).\r\n\r\n                Frank Miller se convirtió en uno de los autores más destacados en la historia de DC Comics gracias a una serie de proyectos hoy reconocidos como clásicos. Con Ronin (1983-1984) sintetizó el influjo de la bande dessinée europea y del cómic oriental, inspirándose en dos referentes del manga como Kazuo Koike y Gôseki Kojima. Y sus proyectos relacionados con el Hombre Murciélago marcaron un antes y un después: por el tono y los recursos narrativos empleados, por impulsar la utilización de nuevos formatos y técnicas de impresión, y por imaginar el pasado y el futuro del personaje acompañado de autores de la talla de David Mazzucchelli, Jim Lee, Klaus Janson y Lynn Varley. Pero Miller no sólo ha destaco en el cómic su gran talento le ha llevado a  codirigir la adaptación cinematográfica de Sin City y su secuela Sin City 2: Una dama por la que matar, y ha ejercido como productor ejecutivo del largometraje 300, e incluso y con menor fortuna se atrevió e solitario a llevar a la gran pantalla de The Spirit, de Will Eisner.\r\n                </p><d/div>\r\n', 12, '/img/noticia3-miniatura.jpg', '2017-05-21 22:00:00', 0),
(4, 'Zelda Breath of the Wild en una imagen promocional de Domino\'s Pizza', 'redactor', '2017-05-16 14:03:39', '¡The Legend of Zelda Breath of the Wild ya está a la venta! Se trata de uno de los juegos más esperados de los últimos años y desde Domino\'s Pizza no han querido desaprovechar la oportunidad que ofrece un lanzamiento de estas características para lanzar una imagen promocional inspirada en el juego de Nintendo Switch y Wii U.\r\n  ', 'Como podéis ver, Domino\'s Pizza ha utilizado una de las imágenes promocionales de Zelda Breath of the Wild para crear una imagen que no tiene desperdicio y que podéis ver en el siguiente tuit publicado por la propia compañía.\r\n', '<span class="centrar-img">\r\n                    <img class="img-noticia-grande" id="img-princ" src="/img/noticia4-cuerpo.jpg" ALT="Zelda">\r\n                  </span>\r\n<div class="dos-columnas">\r\n                  <p>Nosotros ya hemos podido disfrutar de la nueva aventura de la franquicia para Nintendo Switch y Wii U, y os contamos qué nos ha parecido en nuestro completo análisis de The Legend of Zelda Breath of the Wild. Además, aquí os dejamos un contenido con los análisis y las puntuaciones de Zelda Breath of the Wild en la prensa internacional y un reportaje con nuestro análisis de Nintendo Switch, la nueva consola de la Gran N que ya está a la venta a un precio de 329,95 euros.\r\n\r\n                  Os recordamos que The Legend of Zelda Breath of the Wild seguirá recibiendo contenidos en 2017 gracias al pase de expansión que tiene un precio de 19,99 euros. Tres cofres especiales, un nuevo reto llamado Cave of Trials, un nuevo modo difícil, una nueva función para el mapa de juego y una nueva historia original con nuevos retos llegarán al juego de Nintendo Switch y Wii U en los próximos meses.\r\n                  </p></div>', 11, '/img/noticia4-miniatura.png', '2017-05-17 15:36:37', 1),
(5, 'Mother 4 cambiará de nombre para evitar problemas con Nintendo', 'jefe', '2017-05-16 14:03:39', 'Era un desarrollo amateur que pretendía continuar la querida producción de Nintendo.', 'Mother 4 es un proyecto amateur que pretendía hacer realidad el sueño de miles de seguidores de la franquicia de rol de Nintendo: una continuación, aunque sea amateur, del mítico cartucho de GameBoy Advance.', '<span class="centrar-img">\r\n                      <img class="img-noticia-grande" id="img-princ" src="/img/noticia5-cuerpo.jpg" ALT="mother">\r\n                    </span><div class="dos-columnas">\r\n                    <p> Ante los últimos problemas acaecidos entre Nintendo y algunos desarrolladores amateurs que han querido usar marcas de la firma, el equipo prefiere evitar problemas y cambiará de nombre. También sustituirán elementos que pudiesen tener que ver con el juego original de Shigesato Itoi y su equipo.\r\nAunque no han dado un nombre definitivo para el proyecto, sí han querido concretar que los avances realizados con el videojuego se aprovecharán. El proyecto comenzó su andadura en el año 2010, por lo que sería una pena que Mother 4 corriese la suerte de Pokémon Uranium o AM2R. Ayer mismo conocimos una noticia similar: Lucasfilms pidió a un equipo de desarrolladores amateur el cese de un remake del mítico Indiana Jones and the Fate of Atlantis. Restará esperar un milagro y esperar un Mother 4 oficial.\r\n</p></div>', 6, '/img/noticia5-miniatura.png', '2017-05-21 22:00:00', 0),
(6, 'Wonderboy: The Dragon’s Trap llega a PS4, Xbox One y Switch en abril', 'redactor', '2017-05-16 14:03:39', '¡Un clásico está a punto de volver de sus cenizas! Wonderboy: The Dragon’s Trap, el remake de la divertida aventura de acción Wonder Boy 3, se estrenará en PlayStation 4, Xbox One y, como novedad, también en Nintendo Switch el próximo 18 de abril según acaba de confirmar la editora DotEmu.\r\n', '¿Qué ocurre con la versión de PC? Los aficionados en compatibles tendrán que esperar a los meses de primavera para echarle el guante a este videojuego desarrollado por Lizardcube.\r\n', '<span class="centrar-img">\r\n                        <img class="img-noticia-grande" id="img-princ" src="/img/noticia6-cuerpo.jpg" ALT="wonderboy">\r\n                      </span><div class="dos-columnas">\r\n                      <p> The Dragon’s Trap está protagonizado por un joven que sufre una maldición, que le ha llevado a convertirse en un hombre mitad lagarto. Con el paso de la aventura, que se estrenó originalmente en Master System, obtendremos distintas habilidades especiales con las que derrotar a los enemigos y sortear los muchos peligros que aguardan en este colorido mundo de fantasía.\r\n\r\nEl videojuego, que presenta un renovado apartado audiovisual, nos permite también disfrutar de los gráficos y sonido del original de la 8bits de Sega.\r\n                      </p></div>', 4, '/img/noticia6-miniatura.jpg', '2017-05-21 22:00:00', 0),
(7, 'Guía básica de NieR Automata: consejos para empezar a jugar', 'jefe', '2017-05-16 14:03:39', 'Parece que el mundo de los robots con lo terrenal nunca va a tener un final feliz. NieR: Automata, la secuela del anterior título lanzado en 2010, nos vuelve a arrojar en una aventura con mucha pirotecnia mecánica pero con toques de acción, rol y exploración gracias a su mundo abierto que se aprovecha de PlayStation 4 y PC.\r\n', 'Platinum Games vuelve a crear una experiencia de pura acción cervical con personajes robóticos y otros engendros que nos llevarán a combates tan dinámicos como rápidos.\r\n', '<span class="centrar-img">\r\n                          <img class="img-noticia-grande" id="img-princ" src="/img/noticia7-cuerpo.jpg" ALT="nier">\r\n                        </span><div class="dos-columnas">\r\n                        <p>No es fácil comenzar con buen pie en el juego, y es por ello que hemos creado esta guía básica de NieR Automata con consejos para empezar a jugar para que saques partido de los recursos que te vayas encontrando para mejorar al propio personaje (mediante chips) y también a tu fiel acompañante, un Pod volador que te sacará de muchos apuros, y más cuando esté la pantalla infectada de enemigos y que te ataquen a larga distancia.\r\n\r\n                        No te obsesiones con las misiones secundarias\r\n\r\n                        Sabemos que eres un gran jugador, que te encanta no dejar pasar ni una, y que las misiones secundarias siempre son bien recibidas. Pero no te obsesiones con ellas. Algunas de las misiones secundarias en NieR Automata no son fácilmente digeribles al no ser que tengas ya un nivel de personaje o unos chips equipados. Quizá con el temor de dejarlas atrás y no volverlas a ver te hace que te obsesiones mucho con ellas.\r\n                        No te preocupes, porque una vez que te acabes el juego podrás volver a todas las misiones secundarias y pasarte las que quieras. Y eso es una buena garantía de rejugabilidad.\r\n\r\n                        Vende toda la chatarra. Otro de los miedos que puede experimentar un recién llegado a NieR Automata es lo que se vende y no se vende. Se sabe que vamos a necesitar materiales para mejorar a nuestro personaje y al Pod a lo largo de la historia, y por no saber muy bien qué nos van a pedir seguro que vas a empezar a almacenar chatarra que no te valdrá para nada.\r\n\r\nSi caemos en NieR Automata perderemos todos los chips que lleve encima el personaje, pero podremos intentar recuperar el cuerpo en una segunda intentona. Si jugamos online veremos el cuerpo de otros usuarios y podremos escoger entre tres opciones: rezar, recuperar o reparar. Si rezas consigues vida, si recuperas recibes bonus y dinero, y si reparas conseguirás un aliado de manera temporal, que siempre viene bien.\r\n                        </p></div>', 3, '/img/noticia7-miniatura.jpg', '2017-05-21 22:00:00', 0),
(8, 'Blizzard promete más contenido para la historia de Overwatch', 'redactor', '2017-05-16 14:03:39', 'Hace bastante tiempo que el shooter multijugador no recibe cortos animados o cómics para engordar su universo.', 'Michael Chu, el principal guionista de Blizzard para Overwatch, ha hablado a través de los foros oficiales de la compañía de cara a dejarles claro a los aficionados que no se olvidan de la faceta de la historia de su título de acción en primera persona, aunque ésta se desarrolle externamente al videojuego mediante cómics y vídeos.', '<span class="centrar-img">\r\n                          <img class="img-noticia-grande" id="img-princ" src="/img/noticia8-cuerpo.jpg" ALT="nier">\r\n                        </span><div class="dos-columnas">\r\n<p>"¿Se ha cancelado la historia?". Ese era el preocupante título del hilo en el que Chu se ha visto obligado a intervenir, y en el que ha garantizado que se prestará atención a esa faceta de nuevo a lo largo del año. "Una de nuestras metas para el 2017 es la de intentar tener más actualizaciones relacionadas con la historia y contenidos para ésta, así que estamos muy ocupados con ello".\r\nRecordemos que desde la pasada Navidad, con la última entrega del cómic, no recibimos nada de este tipo; y personajes como Orisa no han recibido su propio cortometraje de animación. De hecho, será la primera parada. "Tenemos mucho en camino, con Orisa y su historia siendo la primera que se lanzará este año".</p></div>', 3, '/img/noticia8-miniatura.png', '2017-05-21 22:00:00', 0),
(9, 'Toyotaro se acuerda de Cell en el manga', 'jefe', '2017-05-16 14:03:39', 'El capítulo 23 del manga de Dragon Ball Super se acaba de lanzar en la revista nipona V-Jump, y con ello, un nuevo guiño de Toyotaro a su maestro Akira Toriyama.', 'Avisamos que encontraréis un gran spoiler de la trama, por lo que si no sabéis nada de la saga de Trunks del futuro mejor que tengáis cuidado con lo que vamos a enseñar. ¿Guiño o falta de ideas? Vamos a verlo...', '<span class="centrar-img">\r\n                          <img class="img-noticia-grande" id="img-princ" src="/img/noticia9-cuerpo.jpg" ALT="vegetta">\r\n                        </span><div class="dos-columnas">\r\n<p>\r\n¿Recordáis cómo dejó Super Vegeta con su potentísimo Final Flash al todopoderoso Cell? Sí, mutiló la mitad de su cuerpo dejándolo aparentemente malherido. Obviamente, el bioandroide del Dr. Gero se recuperó gracias a las células regenerativas de Piccolo. Pues bien, aquella viñeta de Akira Toriyama seguro que os marcó a muchos de vosotros durante vuest\r\nra infancia o adolescencia. Allá va:\r\n\r\nEl caso es que, Toyotaro ha repetido la misma jugada en su manga de Dragon Ball Super. En la actualidad, sus páginas nos están mostrando el combate entre Vegetto Super Saiyan Blue y Zamasu, un combate que ha dejado de la siguiente guisa al Kaiohshin corrompido. Se parece a la viñeta de más arriba, ¿verdad?\r\n\r\nY he aquí el debate, ya que no es la primera vez que Toyotaro toma como referencia viñetas de Akira Toriyama para su manga de Dragon Ball Super. ¿Estamos ante guiños constantes a la obra de su maestro o ante una falta de ideas bastante acusada? Veremos si en el futuro Toyotaro aclara este tema, pues ya os aseguro que está dando mucho que hablar. ¡Kai, Kai!</p></div>', 9, '/img/noticia9-miniatura.jpg', '2017-05-21 22:00:00', 0),
(10, 'Ya puedes jugar gratis al título de Blizzard', 'redactor', '2017-05-16 14:03:39', 'Si sois usuarios de PC y amantes de lo retro, os encantará saber que ya podéis jugar gratis a StarCraft.', 'Desde hoy mismo se puede disfrutar del clásico título de estrategia espacial de Blizzard Entertainment sin dejarse ni un solo euro gracias a la actualización 1.18 de StarCraft. Y es que, esta actualización, la primera que recibe StarCraft en ocho años, además de corregir algunos pequeños bugs con los que contaba el juego, hace que pase a ser gratuito para todo aquel que quiera descargalo.', '<div class="centrar-img">\r\n                          <img class="img-noticia-grande" id="img-princ" src="/img/noticia10-cuerpo.jpg" ALT="starcraft">\r\n                        </div>\r\n<div class="dos-columnas">\r\n<p>\r\nSi queréis jugar a StarCraft totalmente gratis en PC, sólo tenéis que entrar en este enlace que os llevará a los foros oficiales del título y descargar el título para vuestro sistema operativo Windows o Mac. Así podréis disfrutar del que está considerado como uno de los mejores juegos de estrategia de todos los tiempos sin pagas absolutamente nada por él.\r\nPor otro lado, os recordamos que recientemente se anunció el lanzamiento de StarCraft Remastered, que llegará a Windows y Mac este mismo verano para ofrecer un renovado apartado visual con soporte UHD y 4K. Mientras que lo esperamos, iremos echando unas partidas gratis al StarCraft original. Y si es la primera vez que jugáis, no os perdáis nuestra guía de StarCraft con consejos básicos para empezar a jugar. </p></div>', 3, '/img/noticia10-miniatura.jpg', '2017-05-21 22:00:00', 0),
(11, 'Destiny 2 - Nuevos detalles sobre el juego de Bungie', 'jefe', '2017-05-16 14:03:39', 'Bungie celebrará un evento en directo la próxima semana en el que repasaran los tres años de Destiny y hablarán sobre el futuro de la saga. Eso significa que probablemente podamos conocer nuevos detalles sobre Destiny 2, que está previsto para su lanzamiento este mismo 2017.', 'Para que hacernos la espera más corta, la compañía ha publicado una nueva entrada en su blog oficial en la que ofrecen algunos datos interesantes sobre lo que podemos esperar de la secuela de su shooter multijugador para PS4, Xbox One, PS3 y Xbox 360.', '  <span class="centrar-img">\r\n              <img class="img-noticia-grande" id="img-princ" src="/img/noticia11-cuerpo.jpg" ALT="destiny">\r\n            </span><div class="dos-columnas">\r\n            <p>En palabras de Bungie: “Las secuelas son el comienzo de nuevas aventuras para todos los jugadores: explorar nuevos mundos, descubrir nuevas historias, conseguir nuevos poderes, amasar botines y mucho más. Esto nos ha llevado a tomar una decisión que beneficiará a los intereses del juego y de los jugadores: los poderes, posesiones, objetos y monedas del Eververso de Destiny 1 no se podrán transferir. Sin embargo, seguirán disponibles en el Destiny original.”\r\n\r\nEso sí, la compañía también ha querido aclarar que hay cosas que sí se mantendrán en Destiny 2, como nuestra clase, la raza de nuestro personaje, el sexo, la cara, el peinado y el emblema. La única condición que tendremos que cumplir para poder transferir los mencionados datos de Destiny a Destiny 2 es haber alcanzado el nivel 20 y completado la misión de historia Jardín Negro.\r\n\r\nBungie explica que se trata del mejor camino a seguir ya que permitirá a los jugadores disfrutar de nuevos progresos y mejoras en Destiny 2.</p></div>', 4, '/img/noticia11-miniatura.jpg', '2017-05-21 22:00:00', 0),
(16, 'JAJAJAJA LOL', 'jefe', '2017-05-17 16:32:02', 'tope guapa', 'xD', 'ahora si tiene', 4, 'no o si', '2017-05-17 16:58:14', 1),
(17, 'noticia de prueba', 'redactor', '2017-05-17 17:29:03', 'hola', 'hola', 'hola', 3, 'hola', '2017-05-17 17:29:03', 1);

-- --------------------------------------------------------

--
-- Table structure for table `publi`
--

CREATE TABLE `publi` (
  `ID` int(11) NOT NULL,
  `Nombre` varchar(50) COLLATE utf8_spanish_ci NOT NULL,
  `Enlace` varchar(200) COLLATE utf8_spanish_ci NOT NULL,
  `Imagen` varchar(30) COLLATE utf8_spanish_ci NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_spanish_ci;

--
-- Dumping data for table `publi`
--

INSERT INTO `publi` (`ID`, `Nombre`, `Enlace`, `Imagen`) VALUES
(1, 'Vodafone', 'https://www.vodafone.es/', '/img/publi1.jpg'),
(2, 'Movistar', 'https://www.movistarfusion.es/adsl', '/img/publi2.jpg'),
(7, 'Movistar', 'https://www.vodafone.es/', '/img/publi1.jpg');

-- --------------------------------------------------------

--
-- Table structure for table `secciones`
--

CREATE TABLE `secciones` (
  `id` int(11) NOT NULL,
  `seccion` varchar(20) COLLATE utf8_spanish_ci NOT NULL,
  `seccionPadre` int(11) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_spanish_ci;

--
-- Dumping data for table `secciones`
--

INSERT INTO `secciones` (`id`, `seccion`, `seccionPadre`) VALUES
(3, 'PC', 13),
(4, 'Playstation', 13),
(5, 'Xbox', 13),
(6, 'Nintendo', 13),
(7, 'Series', 14),
(8, 'Películas', 14),
(9, 'Cómics', 14),
(10, 'Tecnologías', 15),
(11, 'Novedades', 15),
(12, 'Eventos', 15),
(13, 'Videojuegos', NULL),
(14, 'Ocio', NULL),
(15, 'Industria', NULL);

-- --------------------------------------------------------

--
-- Table structure for table `Usuarios`
--

CREATE TABLE `Usuarios` (
  `nombre` varchar(20) COLLATE utf8_spanish_ci NOT NULL,
  `password` varchar(20) COLLATE utf8_spanish_ci NOT NULL,
  `email` varchar(20) COLLATE utf8_spanish_ci NOT NULL,
  `tipo` enum('normal','editor jefe','redactor') COLLATE utf8_spanish_ci NOT NULL DEFAULT 'normal'
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_spanish_ci;

--
-- Dumping data for table `Usuarios`
--

INSERT INTO `Usuarios` (`nombre`, `password`, `email`, `tipo`) VALUES
('adios', 'hola', 'hola@hola.com', 'normal'),
('dtrfghj', 'dfghj', 'm@m.c', 'normal'),
('hola', 'hola', 'hola@hola.com', 'normal'),
('jefe', 'jefe', 'jefe@jefe.jefe', 'editor jefe'),
('redactor', 'redactor', 'redactor@red.com', 'redactor'),
('uyhjk', 'dasodj', 'a@a.a', 'redactor');

--
-- Indexes for dumped tables
--

--
-- Indexes for table `comentarios`
--
ALTER TABLE `comentarios`
  ADD PRIMARY KEY (`id`),
  ADD KEY `noticia` (`noticia`),
  ADD KEY `autor` (`autor`);

--
-- Indexes for table `imagenes`
--
ALTER TABLE `imagenes`
  ADD PRIMARY KEY (`dir_img`),
  ADD KEY `id_noticia` (`id_noticia`);

--
-- Indexes for table `noticias_publicadas`
--
ALTER TABLE `noticias_publicadas`
  ADD PRIMARY KEY (`identificador`),
  ADD UNIQUE KEY `titular` (`titular`),
  ADD KEY `seccion` (`seccion`),
  ADD KEY `autor` (`autor`);

--
-- Indexes for table `publi`
--
ALTER TABLE `publi`
  ADD PRIMARY KEY (`ID`);

--
-- Indexes for table `secciones`
--
ALTER TABLE `secciones`
  ADD PRIMARY KEY (`id`),
  ADD UNIQUE KEY `id` (`id`),
  ADD KEY `subseccion` (`seccion`),
  ADD KEY `seccion` (`seccionPadre`);

--
-- Indexes for table `Usuarios`
--
ALTER TABLE `Usuarios`
  ADD PRIMARY KEY (`nombre`);

--
-- AUTO_INCREMENT for dumped tables
--

--
-- AUTO_INCREMENT for table `comentarios`
--
ALTER TABLE `comentarios`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=19;
--
-- AUTO_INCREMENT for table `noticias_publicadas`
--
ALTER TABLE `noticias_publicadas`
  MODIFY `identificador` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=18;
--
-- AUTO_INCREMENT for table `publi`
--
ALTER TABLE `publi`
  MODIFY `ID` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=8;
--
-- AUTO_INCREMENT for table `secciones`
--
ALTER TABLE `secciones`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=16;
--
-- Constraints for dumped tables
--

--
-- Constraints for table `comentarios`
--
ALTER TABLE `comentarios`
  ADD CONSTRAINT `comentarios_ibfk_1` FOREIGN KEY (`noticia`) REFERENCES `noticias_publicadas` (`identificador`),
  ADD CONSTRAINT `comentarios_ibfk_2` FOREIGN KEY (`autor`) REFERENCES `Usuarios` (`nombre`);

--
-- Constraints for table `imagenes`
--
ALTER TABLE `imagenes`
  ADD CONSTRAINT `imagenes_ibfk_1` FOREIGN KEY (`id_noticia`) REFERENCES `noticias_publicadas` (`identificador`);

--
-- Constraints for table `noticias_publicadas`
--
ALTER TABLE `noticias_publicadas`
  ADD CONSTRAINT `noticias_publicadas_ibfk_1` FOREIGN KEY (`seccion`) REFERENCES `secciones` (`id`),
  ADD CONSTRAINT `noticias_publicadas_ibfk_2` FOREIGN KEY (`autor`) REFERENCES `Usuarios` (`nombre`);

--
-- Constraints for table `secciones`
--
ALTER TABLE `secciones`
  ADD CONSTRAINT `secciones_ibfk_1` FOREIGN KEY (`seccionPadre`) REFERENCES `secciones` (`id`);

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
