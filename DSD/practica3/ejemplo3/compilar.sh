#!/bin/sh -e
# ejecutar = Macro para compilacion y ejecucion del programa ejemplo
# en una sola maquina Unix de nombre localhost.
echo
echo "Lanzando el ligador de RMI ... "
rmiregistry &

echo
echo "Compilando con javac ..."
javac *.java
sleep 2

echo
echo "Lanzando el servidor"
sudo java -cp ../contador.jar;./icontador.jar -Djava.rmi.server.codebase=file:./ -Djava.rmi.server.hostname=localhost -Djava.security.policy=server.policy servidor
sleep 2

echo
echo "Lanzando el primer cliente"
echo
sudo java -cp .;./contador.jar;./icontador.jar -Djava.security.policy=server.policy Cliente localhost
