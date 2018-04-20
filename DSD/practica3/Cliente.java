import java.net.MalformedURLException;
import java.rmi.registry.LocateRegistry;
import java.rmi.*;
import java.rmi.registry.Registry;
import java.util.Scanner;


public class Cliente{
public static void main(String args[]) {
      if (System.getSecurityManager() == null) {
        System.setSecurityManager(new SecurityManager());
      }
      try {
        String s1 = new String("server1");
        String s2 = new String("server2");
      //Creamos un stub para el cliente y especificamos el nombre del servidor
          Registry mireg = LocateRegistry.getRegistry(1099);
          Cliente_I server = (Cliente_I)mireg.lookup("server1"); // Si no introduces este, tiene un error al compilar,preguntar al profesor.
      if(s1.equals(args[0])){
          server = (Cliente_I)mireg.lookup("server1");
        }
      else if (s2.equals(args[0])){
          server = (Cliente_I)mireg.lookup("server2");
      }else {
        System.out.println("No ha introducido un servidor correcto, repita con server1 o server2");
        System.exit(0);

      }
      int select=20;
      String nombre=null;
      Double cantidad=0.0;
      Scanner capt = new Scanner(System.in);
      while(true){
      	try{
      		System.out.println("Pulse un numero para elegir: \n1.- ¡Registrate!" + "\n2.- Quiero depositar\n" + "3.- Consultar donación\n"+ "0.- Salir\n");
          select = capt.nextInt();
          switch(select){

          		case 1:
          		System.out.println("Introduzca su nombre\n");
          		 nombre = capt.next();
          		 if(nombre!=null){
          		   System.out.println(server.registrarse(nombre));
          		 }break;

              case 2:
              System.out.println("Introduzca el nombre del donante,recuerde que debe estar registrado en el sistema.\n");
              nombre = capt.next();
              if(nombre!=null){
                System.out.println("Introduzca la cantidad\n");
                cantidad = capt.nextDouble();
                System.out.println(server.ingresar(nombre,cantidad));
              }break;

             case 3:
              System.out.println("Introduzca su nombre, recuerde que no puede consultar el dinero ingresado si no se ha registrado.\n");
              nombre = capt.next();
              if(nombre!=null){
              //  System.out.println("El dinero ingresado por usted es: ");
              //  System.out.println(server.mioIngresado(nombre));
                System.out.println("El dinero total donado es de: ");
                System.out.println(server.totalIngresado());
              }break;

              case 0:
			            System.out.println("Adios!");
                  System.exit(0);
			        break;

              default:
		             System.out.println("Número no reconocido");
              break;
          }
        }catch(Exception e){
            System.out.println("Uoop! Error!" + e);
            System.exit(0);
        }
      }} catch(NotBoundException | RemoteException e) {
        System.err.println("Exception del sistema: " + e);
      }
    System.exit(0);
}
}
