import java.net.MalformedURLException;
import java.rmi.*;
import java.rmi.registry.LocateRegistry;
import java.rmi.registry.Registry;
import java.rmi.server.*;

public interface Servidor_I extends Remote {
    public Double totalMio () throws RemoteException;
    public Boolean consultarUsuario (String nombre) throws RemoteException;
    public int consultarTamano () throws RemoteException;
    public void incrementar (Double valor) throws RemoteException;
}
