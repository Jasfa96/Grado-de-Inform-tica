const TAM = 100;
typedef string nombre<TAM>;
typedef string red<TAM>;
typedef string ip<TAM>;

program DNS3 {
  version DNSVERS {
    string introducir (nombre, red, ip) = 1; /* NOMBRE,red, IP */
    string eliminar (nombre, red) = 2; /* NOMBRE, red */
    string consultar (nombre, red) = 3; /*NOMBRE,red */
  } = 1;
} = 0x20000003;
