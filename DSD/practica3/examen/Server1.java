import java.rmi.*;
import java.rmi.server.UnicastRemoteObject;
import java.net.MalformedURLException;
import java.util.*;
import java.rmi.registry.Registry;
import java.rmi.registry.LocateRegistry;

/*El servidor implementará 2 interafaces, una de cara al usuario donde el usuario podra donar, registrarse... y otra entre ellos, esta interfaz hará la comunicacion entre ambos servidores.
Aparte de ellos necesitaremos de un valor que tenga el numero de registros que hay en el server, hay que meter los usuarios en el servidor con menos registros
antes de hacer esto hay que consultar en el array de usuarios a ver si está y luego consultar en el array de usuarios del otro servidor*/

public class Server1 extends UnicastRemoteObject implements Cliente_I, Servidor_I{
  Map<String , Double> Datos = new HashMap<String, Double>();
  Double total=0.0;

  public Server1() throws RemoteException{
  Map<String , Double> Datos = new HashMap<String, Double>();
}

synchronized public String registrarse(String nombre) throws RemoteException {

  try{
      Registry mireg = LocateRegistry.getRegistry(1099);
      Servidor_I server2 = (Servidor_I)mireg.lookup("server2");
      Cliente_I server2c = (Cliente_I)mireg.lookup("server2");

      if(server2.consultarTamano()>= Datos.size() && !Datos.containsKey(nombre) && !server2.consultarUsuario(nombre)){
        Datos.put(nombre,0.0);
        return "\nRegistro en el server1 realizada con exito.";
      }else if(server2.consultarTamano()<= Datos.size() && !Datos.containsKey(nombre) && !server2.consultarUsuario(nombre)){
        server2c.registrarse(nombre);
        return "\nRegistro en el server2 realizado con exito.";
      }else{
        return "\nEl usuario ya está registrado";
      }
  } catch (NotBoundException e) {
      System.out.println("Exception: " + e.getMessage());
  } return "Ha habido algun error";
}
synchronized public void incrementar(Double valor) throws RemoteException{
  total=total+valor;
}

 public String ingresar(String nombre, double valor) throws RemoteException{
  try{
      Registry mireg = LocateRegistry.getRegistry(1099);
      Servidor_I server2 = (Servidor_I)mireg.lookup("server2");
      Cliente_I server2c = (Cliente_I)mireg.lookup("server2");

      if(Datos.containsKey(nombre)){
        double aux=Datos.get(nombre)+valor;
        server2.incrementar(valor);
        total=valor+total;
        Datos.put(nombre,aux);
        return "\nDonacion realizada con exito en el server1.";
      }else if(server2.consultarUsuario(nombre)){
        server2c.ingresar(nombre,valor);
        return "\nDonacion realizada con exito en el server2.";
      }else {
        return "Nombre no encontrado";
      }
/* //Nuevo para el examen
if(Datos.containsKey(nombre) || server2.consultarUsuario(nombre)){
  double aux=Datos.get(nombre)+valor;
  total=valor+total;
  Datos.put(nombre,aux);
  server2c.ingresar(nombre,aux);
  return "\nDonacion realizada con exito en el server1.";
}else {
  return "Nombre no encontrado";
}*/
    }catch (NotBoundException e) {
        System.out.println("Exception: " + e.getMessage());
    }
      return "No ha habido ningún problema";
}

/*public Double mioIngresado(String nombre) throws RemoteException {
  if(Datos.containsKey(nombre)){
    return Datos.get(nombre);
  }else{
    return 0.0;
 }
}*/

synchronized public Double totalIngresado() throws RemoteException {

  try{
    Registry mireg = LocateRegistry.getRegistry(1099);
    Servidor_I server2 = (Servidor_I)mireg.lookup("server2");
    double extra = server2.totalMio();
    //return total+extra;
    //examen
    return total;
  } catch (NotBoundException e) {
    System.out.println("Exception: " + e.getMessage());
  }
  return 0.0;
}

public int consultarTamano() throws RemoteException{
  return Datos.size();
}

public Boolean consultarUsuario(String nombre) throws RemoteException{ //Comprobar si puedes poner el server2.datos.contains...
  if(Datos.containsKey(nombre)){
  return true;
  }else{
  return false;
  }
}
public Double totalMio() throws RemoteException {
  return total; //HAY QUE PONER EL TOTAL
}

synchronized public String Prueba(String nombre, double valor) throws RemoteException {
//NO LO USO ALFINAL
  try{
      Registry mireg = LocateRegistry.getRegistry(1099);
      Servidor_I server2 = (Servidor_I)mireg.lookup("server2");
      Cliente_I server2c = (Cliente_I)mireg.lookup("server2");

      if(server2.consultarTamano()>= Datos.size() && !Datos.containsKey(nombre) && !server2.consultarUsuario(nombre)){
        Datos.put(nombre,0.0);
      }else if(server2.consultarTamano()<= Datos.size() && !Datos.containsKey(nombre) && !server2.consultarUsuario(nombre)){
        server2c.registrarse(nombre);
      }

      if(Datos.containsKey(nombre)){
        double aux=Datos.get(nombre)+valor;
        server2.incrementar(valor);
        total=valor+total;
        Datos.put(nombre,aux);
        return "\nDonacion realizada con exito en el server1.";
      }else if(server2.consultarUsuario(nombre)){
        server2c.ingresar(nombre,valor);
        return "\nDonacion realizada con exito en el server2.";
      }

  } catch (NotBoundException e) {
      System.out.println("Exception: " + e.getMessage());
  }
  return "HOLA";
}


public static void main(String[] args) {
    // Crea e instala el gestor de seguridad
    if (System.getSecurityManager() == null) {
    System.setSecurityManager(new SecurityManager());
    }
    try {
      Server1 server1 = new Server1();
    //  Implementa server1 = new Implementa();
      Registry registry = LocateRegistry.getRegistry();
      registry.rebind("server1", server1);
      System.out.println("Servidor RemoteException | MalformedURLExceptiondor preparado");
    } catch (RemoteException e) {
    System.out.println("Exception: " + e.getMessage());
    }
  }
}
