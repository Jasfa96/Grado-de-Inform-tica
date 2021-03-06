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
import java.util.Random;
import javax.media.j3d.AmbientLight;
import javax.media.j3d.Appearance;
import javax.media.j3d.Background;
import javax.media.j3d.BoundingSphere;
import javax.media.j3d.BranchGroup;
import javax.media.j3d.Canvas3D;
import javax.media.j3d.DirectionalLight;
import javax.media.j3d.Light;
import javax.media.j3d.SpotLight;
import javax.media.j3d.Texture;
import javax.media.j3d.Transform3D;
import javax.media.j3d.TransformGroup;
import javax.media.j3d.View;
import javax.vecmath.Color3f;
import javax.vecmath.Point3d;
import javax.vecmath.Point3f;
import javax.vecmath.Vector3d;
import javax.vecmath.Vector3f;

/**
 *
 * @author fvelasco
 */
public class TheUniverse {
  
  public static final int SPOTLIGHT = 1;
  public static final int DIRECTIONALLIGHT = 2;
  
  private Random r;
  private Canvas3D canvas;
  private SimpleUniverse universe;
  private BranchGroup background;
  private Axes axes;
  private BranchGroup lights;
//  private BranchGroup scene;
  private Pendulum pendulum;
  
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
    
    // Se crean y se añaden luces
    lights = createLights();
    universe.addBranchGraph(lights);
    
    // Se crea la rama de la escena y se cuelga al universo
    pendulum = createScene();
    universe.addBranchGraph(pendulum);
    
  }
  private SimpleUniverse createUniverse (Canvas3D canvas) {
    // Se crea manualmente un ViewingPlatform para poder personalizarlo y asignárselo al universo
    ViewingPlatform viewingPlatform = new ViewingPlatform();
    // Se establece el radio de activación
    viewingPlatform.getViewPlatform().setActivationRadius (100f);
    
    // La transformación de vista, dónde se está, a dónde se mira, Vup
    TransformGroup viewTransformGroup = viewingPlatform.getViewPlatformTransform();
    Transform3D viewTransform3D = new Transform3D();
    viewTransform3D.lookAt (new Point3d (20,20,20), new Point3d (0,0,0), new Vector3d (0,1,0));
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
  
  private Pendulum createScene () {
    // Se crea el primer péndulo y se devuelve
    // Dado que Pendulum hereda de Branchgroup,
    //    el constructor de TheUniverse lo colgará directamente del
    //    SimpleUniverse
    // El periodo es aleatorio entre 1 y 2 segundos
    r = new Random();
    return new Pendulum (r.nextFloat()+1);
  }
  
  private BranchGroup createBackground () {
    // Se crea el objeto para el fondo y 
    //     se le asigna un área de influencia
    Background backgroundNode = new Background ();
    backgroundNode.setApplicationBounds (new BoundingSphere (new Point3d (0.0, 0.0, 0.0), 100.0));
    
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
  
  private BranchGroup createLights () {
    BranchGroup lightsNode = new BranchGroup();
    BoundingSphere influencingBound = new BoundingSphere (new Point3d (0.0, 0.0, 0.0), 100.0);
    // Se crea la luz ambiente
    Light aLight = new AmbientLight (new Color3f (0.9f, 0.9f, 0.9f));
    aLight.setInfluencingBounds (influencingBound);
    aLight.setEnable(true);
    lightsNode.addChild(aLight);
    
    // Se crea la primera luz
    Color3f white = new Color3f (1.0f, 1.0f, 1.0f);
    Vector3f direction = new Vector3f (0f, -1f, 0f);
    Point3f position = new Point3f (4f, 0f, -4f);
    Point3f atenuation = new Point3f (1f, 0f, 0f);
    aLight = new SpotLight (white, position, atenuation, direction, 0.5f, 1f);
    aLight.setInfluencingBounds (influencingBound);
    aLight.setCapability(Light.ALLOW_STATE_WRITE);
    aLight.setEnable (true);
    lightsNode.addChild(aLight);
    
    // Se crea la segunda luz
    aLight = new DirectionalLight (new Color3f (0.7f, 0.7f, 0.7f), 
                    new Vector3f (1.0f, -1.0f, -4.0f));
    aLight.setInfluencingBounds (influencingBound);
    aLight.setCapability(Light.ALLOW_STATE_WRITE);
    aLight.setEnable (true);
    lightsNode.addChild(aLight);
    
    return lightsNode;
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
  
  public void addPendulum () {
    Pendulum otherPendulum = new Pendulum (r.nextFloat()+1);
    pendulum.addPendulum(otherPendulum);
  }
  
  public void startStop (int what, boolean onOff) {
    pendulum.startStop (what, onOff);
  }
  
  public void setLightOnOff (int lightIndex, boolean onOff) {
    if (lightIndex == SPOTLIGHT || lightIndex == DIRECTIONALLIGHT) {
      ((Light) lights.getChild (lightIndex)).setEnable(onOff);
    }   
  }    
  
}
