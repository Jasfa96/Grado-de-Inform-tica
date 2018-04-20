/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package ejemplo03;

import GUI.Control;
import Model.TheUniverse;
import com.sun.j3d.utils.universe.SimpleUniverse;
import javax.media.j3d.Canvas3D;

/**
 *
 * @author fvelasco
 */
public class Ejemplo03 {

  /**
   * @param args the command line arguments
   */
  public static void main(String[] args) {
    // Se obtiene la configuración gráfica del sistema y se crea el Canvas3D que va a mostrar la imagen
    Canvas3D canvas = new Canvas3D (SimpleUniverse.getPreferredConfiguration());
    
    // Se crea el universo, incluye una vista para ese canvas
    TheUniverse universe = new TheUniverse (canvas);
    
    // Se construye la ventana de control
    // La ventana de control es la que abre la ventana de visualización
    Control controlWindow = new Control (universe);
        
    // Se hace la aplicación visible
    controlWindow.setVisible(true);
  }
  
}
