import java.rmi.Remote;
import java.rmi.RemoteException;

public interface Cliente_I extends Remote {
     String registrarse (String nombre) throws RemoteException;
     public String ingresar (String nombre, double cantidad) throws RemoteException;
     public Double totalIngresado () throws RemoteException;
     public String Prueba(String nombre, double cantidad) throws RemoteException; //una prueba del examen al final no utilizado
     
     //public Double mioIngresado (String nombre) throws RemoteException;
}
