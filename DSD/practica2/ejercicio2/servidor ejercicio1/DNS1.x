const TAM = 100;
typedef string nombre<TAM>;
typedef string red<TAM>;
typedef string ip<TAM>;

program DNS1 {
  version DNSVERS {
    string introducir (nombre, red, ip) = 1; /* NOMBRE,red, IP */
    string eliminar (nombre, red) = 2; /* NOMBRE, red */
    string consultar (nombre, ip) = 3; /*NOMBRE,red */
    void introducirdns(nombre, ip) = 4;
    void eliminardns(nombre) = 5;

  } = 1;
} = 0x20000001;
