/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package Model;

import com.sun.j3d.utils.behaviors.vp.OrbitBehavior;
import com.sun.j3d.utils.geometry.Primitive;
import com.sun.j3d.utils.geometry.Sphere;
import com.sun.j3d.utils.image.TextureLoader;
import com.sun.j3d.utils.universe.SimpleUniverse;
import com.sun.j3d.utils.universe.Viewer;
import com.sun.j3d.utils.universe.ViewingPlatform;
import javax.media.j3d.Appearance;
import javax.media.j3d.Background;
import javax.media.j3d.BoundingSphere;
import javax.media.j3d.BranchGroup;
import javax.media.j3d.Canvas3D;
import javax.media.j3d.PolygonAttributes;
import javax.media.j3d.Texture;
import javax.media.j3d.Transform3D;
import javax.media.j3d.TransformGroup;
import javax.media.j3d.View;
import javax.vecmath.Point3d;
import javax.vecmath.Vector3d;

/**
 *
 * @author fvelasco
 */
public class TheUniverse {
  
  private Canvas3D canvas;
  private SimpleUniverse universe;
  private BranchGroup scene;
  private BranchGroup background;
  private Axes axes;
  
  public TheUniverse (Canvas3D canvas) {
    // Atributos de referencia
    this.canvas = canvas;
    // Se crea el universo y la rama de la vista con ese canvas
    universe = createUniverse(canvas);
    
    // Se crea la rama del fondo y se cuelga al universo
    background = createBackground();
    universe.addBranchGraph(background);
    
    // Se crea la rama de los ejes y se cuelga al universo
    axes = new Axes(10.0f);
    universe.addBranchGraph(axes);
    
    // Se crea la rama de la escena y se cuelga al universo
    scene = createScene();
    universe.addBranchGraph(scene);
    
  }
  private SimpleUniverse createUniverse (Canvas3D canvas) {
    // Se crea manualmente un ViewingPlatform para poder personalizarlo y asignárselo al universo
    ViewingPlatform viewingPlatform = new ViewingPlatform();
    // Se establece el radio de activación
    viewingPlatform.getViewPlatform().setActivationRadius (100f);
    
    // La transformación de vista, dónde se está, a dónde se mira, Vup
    TransformGroup viewTransformGroup = viewingPlatform.getViewPlatformTransform();
    Transform3D viewTransform3D = new Transform3D();
    viewTransform3D.lookAt (new Point3d (10,10,10), new Point3d (0,0,0), new Vector3d (0,1,0));
    viewTransform3D.invert();
    viewTransformGroup.setTransform (viewTransform3D);

    // El comportamiento, para mover la camara con el raton
    OrbitBehavior orbit = new OrbitBehavior(canvas, OrbitBehavior.REVERSE_ALL);
    orbit.setSchedulingBounds(new BoundingSphere(new Point3d (0.0f, 0.0f, 0.0f), 100.0f));
    orbit.setZoomFactor (2.0f);
    viewingPlatform.setViewPlatformBehavior(orbit);
    
    // Se establece el angulo de vision a 45 grados y el plano de recorte trasero
    Viewer viewer = new Viewer (canvas);
    View view = viewer.getView();
    view.setFieldOfView(Math.toRadians(45));
    view.setBackClipDistance(50.0);

    // Se construye y devuelve el Universo con los parametros definidos
    return new SimpleUniverse (viewingPlatform, viewer);
  }
  
  private BranchGroup createScene () {
    // Vamos a hacer el grafo de escena, una esfera
    // Se necesita una geometría y un aspecto
    Appearance appearance = new Appearance();
    appearance.setPolygonAttributes(new PolygonAttributes (PolygonAttributes.POLYGON_LINE, PolygonAttributes.CULL_BACK, 0.0f)); 
    Sphere sphere = new Sphere(3f, Primitive.GENERATE_NORMALS, 32, appearance);
    // Como raíz se usa un BrachGroup
    BranchGroup root = new BranchGroup();
    root.addChild (sphere);
    return root;
  }
  
  private BranchGroup createBackground () {
    // Se crea el objeto para el fondo y 
    //     se le asigna un área de influencia
    Background backgroundNode = new Background ();
    backgroundNode.setApplicationBounds (new BoundingSphere (new Point3d (0.0, 0.0, 0.0), 10.0));
    
    // Se crea un aspecto basado en la textura a mostrar
    Appearance app = new Appearance ();
    Texture texture = new TextureLoader ("imgs/back.jpg", null).getTexture();
    app.setTexture (texture);
    
    // Se hace la esfera con un determinado radio indicándole:
    //    - Que genere coordenadas de textura
    //    - Que genere las normales hacia adentro
    //    - Que tenga el aspecto creado
    Primitive sphere = new Sphere (1.0f, Primitive.GENERATE_TEXTURE_COORDS | Primitive.GENERATE_NORMALS_INWARD, app);
    
    // Se establece esa esfera como background
    // Es necesario que cuelgue de un BranchGroup para poder asignárselo al nodo Background
    BranchGroup bgSphere = new BranchGroup();
    bgSphere.addChild(sphere);
    backgroundNode.setGeometry(bgSphere);
    
    // Finalmente se crea el BranchGroup para devolver el Background
    BranchGroup bgBackground = new BranchGroup();
    bgBackground.addChild(backgroundNode);
    return bgBackground;    
  }
  
  public Canvas3D getCanvas () {
    return canvas;
  }
  
  public SimpleUniverse getUniverse () {
    return universe;
  }
  
  public void showAxes (boolean onOff) {
    axes.showAxes(onOff);
  }
  
}
