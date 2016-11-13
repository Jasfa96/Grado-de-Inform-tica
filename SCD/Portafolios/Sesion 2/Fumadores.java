import monitor.*;
import java.util.Random;
	//delate de los await poner siempre un if salvo en uno del barbero
class Estanco extends AbstractMonitor
{ 	
	private Condition papel= makeCondition();
	private Condition tabaco= makeCondition();
	private Condition cerillas= makeCondition();
	private Condition estanco= makeCondition();
	int ingrediente;

        public Estanco(){
               ingrediente = -1;
        }

// invocado por cada fumador, indicando su ingrediente o numero
public void obtenerIngrediente(int miIngrediente){
        String ingrediente_txt="";

        switch(miIngrediente){
            case 0:
                ingrediente_txt = "papel";
                break;
            case 1:
                ingrediente_txt = "tabaco";
                break;
            case 2:
                ingrediente_txt = "cerillas";
                break;
        }

	enter();
		estanco.signal();

        while(ingrediente != miIngrediente){
            switch(miIngrediente){
                case 0:
                    papel.await();
                    break;
                case 1:
                    tabaco.await();
                    break;
                case 2:
                    cerillas.await();
                    break;
            }
        }
	ingrediente=-1;
	
System.out.println("Recojo " + ingrediente_txt);	
	leave();
}
// invocado por el estanquero, indicando el ingrediente que pone
public void ponerIngrediente(int ingrediente){	
	enter();
	this.ingrediente=ingrediente;
        switch(ingrediente){
            case 0:
                System.out.println("Coloco papel");
                papel.signal();
                break;
            case 1:
                System.out.println("Coloco tabaco");
                tabaco.signal();
                break;
            case 2:
                System.out.println("Coloco cerilla");
                cerillas.signal();
                break;
        }

        leave();
    }
// invocado por el estanquero
public void esperarRecogidaIngrediente(){
	enter();
System.out.println("Espero la recogida.");
	while(ingrediente != -1){
		estanco.await();
	}
	leave();
}
}


class Fumador implements Runnable
{
   int miIngrediente;
   public Thread thr ;
   Estanco estanco;

   public Fumador( int p_miIngrediente,Estanco p_estanco ){
   miIngrediente=p_miIngrediente;
   estanco=p_estanco;
   thr = new Thread(this,"Fumador");
   }
   public void run(){
      while ( true ){ 
      estanco.obtenerIngrediente( miIngrediente );
      aux.dormir_max( 2000 );
System.out.println("Termino de fumar");
      }
   }
}

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

class Estanquero implements Runnable{
   public Thread thr ;
   Estanco estanco;
	public Estanquero(Estanco p_estanco){
	estanco = p_estanco;
	thr = new Thread(this, "Estanquero");
	};
   public void run(){
   int ingrediente ;
      while (true){
      ingrediente = (int) (Math.random () * 3.0); // 0,1 o 2
      estanco.ponerIngrediente( ingrediente );
      estanco.esperarRecogidaIngrediente() ;
      }
   }
}

public class Fumadores{

        public static void main(String [] args){
        Estanco estanco = new Estanco();
        Estanquero estanquero = new Estanquero(estanco);
        Fumador[]  fumadores = new Fumador[3];

        // crear hebras
        for(int i = 0; i < fumadores.length; i++)
            fumadores[i] = new Fumador(i, estanco);

        // poner en marcha las hebras
        estanquero.thr.start();

        for(int i = 0; i < fumadores.length; i++)
            fumadores[i].thr.start();
  }
}

