struct Usuario {
  char nombre[20];
  char apellido[20];
  char permisos;  // Se define una estructura de datos llamada Usuario que almacena el nombre, el apellido y los permisos de un usuario.
};
void agregarUsuariosAlEEPROM() {
  Usuario usuarios[3];  // Array para almacenar información de hasta 3 usuarios

  for (int i = 0; i < 3; ++i) {
    Serial.println("Ingrese nombre para el usuario:");
    while (!Serial.available()) {}
    Serial.readBytesUntil('\n', usuarios[i].nombre, sizeof(usuarios[i].nombre) - 1);

    Serial.println("Ingrese apellido para el usuario:");
    while (!Serial.available()) {}
    Serial.readBytesUntil('\n', usuarios[i].apellido, sizeof(usuarios[i].apellido) - 1);

    Serial.println("Ingrese permisos para el usuario (un carácter):");
    while (!Serial.available()) {}
    usuarios[i].permisos = Serial.read();  //

    // Escribir en EEPROM
    Wire.beginTransmission(EEPROM_ADDRESS);
    Wire.write(i * sizeof(Usuario));
    Wire.write((byte*)&usuarios[i], sizeof(Usuario));
    Wire.endTransmission();  //Esta función permite al "Administrador" ingresar la información de hasta tres usuarios y escribe esa información en la EEPROM externa.
    if (Wire.endTransmission() != 0) {
      Serial.println("Error al finalizar la transmisión");
    }
  }

  Serial.println("Usuarios agregados con éxito.");
}
void leerUsuariosDesdeEEPROM() {
  Usuario usuario;

  for (int i = 0; i < 3; ++i) {
    // Leer desde EEPROM
    Wire.beginTransmission(EEPROM_ADDRESS);
    Wire.write(i * sizeof(Usuario));
    Wire.endTransmission();
    Wire.requestFrom(EEPROM_ADDRESS, sizeof(Usuario));

    if (Wire.available() == sizeof(Usuario)) {
      Wire.readBytes((byte*)&usuario, sizeof(Usuario));  //Esta función lee la información almacenada en la EEPROM externa para cada uno de los tres usuarios y la muestra en el puerto serie.
      if (Wire.endTransmission() != 0) {
        Serial.println("Error al finalizar la transmisión");
      }

      Serial.print("Usuario ");
      Serial.print(i + 1);
      Serial.print(": ");
      Serial.print("Nombre: ");
      Serial.print(usuario.nombre);
      Serial.print(", Apellido: ");
      Serial.print(usuario.apellido);
      Serial.print(", Permisos: ");
      Serial.println(usuario.permisos);
    }
  }
}

void setup() {
}

void loop() {
}
