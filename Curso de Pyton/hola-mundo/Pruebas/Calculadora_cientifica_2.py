def calcular(): 
    password = "hola"
    user_password = input("ingrese contraseña para acceder a la calculadora: ")
    if user_password!= password:
        print("Contraseña incorrecta!")
        return
    while True:
        print("Bienvenido a la super calculadora de Python")
        print("Selecciona una operación:")
        print("1. Suma")
        print("2. Resta")
        print("3. Multiplicación")
        print("4. División")
        print("5. Potencia")
        print("6. Raíz cuadrada")
        print("7. Porcentaje")

        opciones = {
            "1": suma,
            "2": resta,
            "3": multiplicacion,
            "4": division,
            "5": potencia,
            "6": raiz_cuadrada,
            "7": porcentaje
        }

        opcion = input("Ingresa el número de la operación que deseas realizar: ")

        if opcion in opciones:
            num1 = float(input("Ingresa el primer número: "))
            num2 = float(input("Ingresa el segundo número: "))
            resultado = opciones[opcion](num1, num2)
            print(f"El resultado es: {resultado}")
        else:
            print("Opción inválida. Por favor, selecciona una opción válida.")

def suma(num1, num2):
    return num1 + num2

def resta(num1, num2):
    return num1 - num2

def multiplicacion(num1, num2):
    return num1 * num2

def division(num1, num2):
    if num2!= 0:
        return num1 / num2
    else:
        print("No se puede dividir entre cero.")
        return None

def potencia(num1, num2):
    return num1 ** num2

def raiz_cuadrada(num):
    if num >= 0:
        return num ** 0.5
    else:
        print("No se puede calcular la raíz cuadrada de un número negativo.")
        return None

def porcentaje(num1, num2):
    return (num1 * num2) / 100

entrada =  True
while entrada!= "no":
    calcular()
    entrada = input("¿Quieres hacer otro calculo?")