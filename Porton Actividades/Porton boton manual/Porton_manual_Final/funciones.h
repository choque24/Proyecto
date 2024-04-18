void abrir_porton() {  // Funcion para abrir el porton
  estado_porton = Apertura;
}
void cerrar_porton() {  // Funcion para cerrar el porton
  estado_porton = Cerraje;
}
void parar_porton() {  // Funcion para parar el porton
  estado_porton = Frenado;
}

// Funcion verificacion estados
void verificacion_estado_porton() {
  switch (estado_porton) {

    case Apertura:  //Si el porton se esta ABRIENDO y llego al FCA FRENAR el porton
      if (!estado_FCA) parar_porton();
      else if (boton_presionado == 2) cerrar_porton();
      else abrir_porton();
      break;

    case Cerraje:  // Si el porton se esta CERRANDO y llego al FCC FRENAR el porton
      if (!estado_FCC) parar_porton();
      else if (boton_presionado == 1) abrir_porton();
      else cerrar_porton();
      break;

    case Frenado:  //Si el porton esta QUIETO y llego al FCA y se presiono el boton CERRAR el porton
      if (!estado_FCC && boton_presionado == 1) abrir_porton();
      else if (!estado_FCA && boton_presionado == 2) cerrar_porton();
      else parar_porton();
      break;

    default:
      parar_porton();
      break;
  }
}