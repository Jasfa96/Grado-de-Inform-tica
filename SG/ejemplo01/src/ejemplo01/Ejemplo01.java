/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package ejemplo01;

import GUI.Visualization;
import com.sun.j3d.utils.geometry.Primitive;
import com.sun.j3d.utils.geometry.Sphere;
import com.sun.j3d.utils.universe.SimpleUniverse;
import javax.media.j3d.Appearance;
import javax.media.j3d.BranchGroup;
import javax.media.j3d.Canvas3D;
import javax.media.j3d.PolygonAttributes;

/**
 *
 * @author fvelasco
 */
public class Ejemplo01 {

  /**
   * @param args the command line arguments
   */
  public static void main(String[] args) {
    // Se obtiene la configuración gráfica del sistema y se crea el Canvas3D que va a mostrar la imagen
    Canvas3D canvas = new Canvas3D (SimpleUniverse.getPreferredConfiguration());
    // Se construye la ventana de visualización
    Visualization visualizationWindow = new Visualization (canvas);
    
    // Se crea el universo y la rama de la vista con ese canvas
    SimpleUniverse universe = new SimpleUniverse (canvas);
    universe.getViewingPlatform().setNominalViewingTransform();
    
    // Vamos a hacer el grafo de escena, una esfera
    // Se necesita una geometría y un aspecto
    Appearance appearance = new Appearance();
    appearance.setPolygonAttributes(new PolygonAttributes (PolygonAttributes.POLYGON_LINE,PolygonAttributes.CULL_NONE, 0.0f)); 
    Sphere sphere = new Sphere(0.7f, appearance);
    // Como raíz se usa un BrachGroup
    BranchGroup root = new BranchGroup();
    root.addChild (sphere);
    
    // Se cuelga la raiz del grafo al universo
    universe.addBranchGraph(root);
    
    // Se muestra la ventana
    visualizationWindow.setVisible(true);
  }
  
}
