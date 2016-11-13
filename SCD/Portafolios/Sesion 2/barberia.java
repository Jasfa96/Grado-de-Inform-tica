import java.util.Random;
import monitor.*;

class aux{
  static Random genAlea = new Random() ;
  static void dormir_max( int milisecsMax ){
    try{
        Thread.sleep(genAlea.nextInt(milisecsMax)) ;
    } 
    catch(InterruptedException e){
        System.err.println("sleep interumpido en 'aux.dormir_max()'");
    }
  }
}

class Barberia extends AbstractMonitor{
    boolean barbero_libre;
    int cola;
    private Condition cliente = makeCondition();
    private Condition barbero = makeCondition();
    private Condition nuevo_corte = makeCondition();

    public Barberia(){
        barbero_libre = true;
        cola = 0;
    }

    // invcado por los clientes para cortarse el pelo
    public void cortarPelo(){
        enter();

        cola++;

        System.out.println("Entro a la barbería, soy el " + cola + "º en la cola");

        cliente.signal();

        while(!barbero_libre){
            barbero.await();
        }

        barbero_libre = false;

        System.out.println("Entro a pelarme");
        nuevo_corte.await();

        cola--;

        barbero_libre = true;

        System.out.println("Salgo de pelarme");

        leave();
    }

    // invocado por el barbero para esperar (si procede) a un nuevo cliente y sentarlo para el corte
    public void siguienteCliente (){
        enter();

        while(cola == 0){
            System.out.println("Espero al siguiente cliente");
            System.out.println("Durmiendo");
            cliente.await();
        }

        System.out.println("Tengo un nuevo cliente");

        leave();
    }

    // invocado por el barbero para indicar que ha terminado de cortar el pelo
    public void finCliente(){
        enter();

        System.out.println("He acabado de pelar");

        nuevo_corte.signal();

        barbero.signal();

        leave();
    }
}

class Barbero implements Runnable{
    public Thread thr;
    Barberia barberia;

    public Barbero(Barberia p_barberia){
        barberia = p_barberia;
        thr = new Thread(this, "Barbero");
    };

    public void run(){
        while (true){
            barberia.siguienteCliente();
            aux.dormir_max(2500);
            barberia.finCliente();
        }
    }
}

class Cliente implements Runnable{
    public Thread thr;
    Barberia barberia;

    public Cliente(int id_cliente, Barberia p_barberia){
        barberia = p_barberia;

        thr = new Thread(this, "Cliente " + id_cliente);
    }

    public void run(){
        while (true){
            barberia.cortarPelo();
            aux.dormir_max(2000);
        }
    }
}

public class barberia{
    public static void main(String [] args){

        int nclientes = Integer.parseInt(args[0]);

        Barberia barberia = new Barberia();
        Barbero barbero = new Barbero(barberia);
        Cliente[]  clientes = new Cliente[nclientes];

        // crear hebras
        for(int i = 0; i < nclientes; i++)
            clientes[i] = new Cliente(i, barberia);

        // poner en marcha las hebras
        for(int i = 0; i < nclientes; i++)
            clientes[i].thr.start();

        barbero.thr.start();
  }
}
