

double Prueba(const Enviroment &T, int jugador, int prof, int od){
  double max==menos_inf;

  if(prof==0)
    return ValorarPosicion(T, jugador);
  else{
    int val_oct=-1, kk;
    double valor;
    Enviroment hijo=T.GenerateNextare(ult_odc);
    while(ult_ac < 8){
      valor=Prueba(hijo, jugador, prof-1, kk);
      if(valor>max){
        max=valor;
        oct=ult_ac;
      }
      hijo=T.GenerateNextare(ult_odc);
    }
    return max;
  }
}
