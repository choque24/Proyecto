# hola
def calcular():
    password = "hola"
    user_password = input("ingrese contraseña para acceder a la calculadora: ")
    if user_password != password:
        print("Contraseña incorrecta!")
        return 
    print("Bienvenido a la super calculadora de Python")
    print("Selecciona una operación:")
    print("1. Suma")
    print("2. Resta")
    print("3. Multiplicación")
    print("4. División")
    print("5. Potencia")
    print("6. Raíz cuadrada")
    print("7. Porcentaje")

    opcion = input("Ingresa el número de la operación que deseas realizar: ")

    if opcion == "1":
        num1 = float(input("Ingresa el primer número: "))
        num2 = float(input("Ingresa el segundo número: "))
        resultado = num1 + num2
        print(f"El resultado de la suma es: {resultado}")

    elif opcion == "2":
        num1 = float(input("Ingresa el primer número: "))
        num2 = float(input("Ingresa el segundo número: "))
        resultado = num1 - num2
        print(f"El resultado de la resta es: {resultado}")

    elif opcion == "3":
        num1 = float(input("Ingresa el primer número: "))
        num2 = float(input("Ingresa el segundo número: "))
        resultado = num1 * num2
        print(f"El resultado de la multiplicación es: {resultado}")

    elif opcion == "4":
        num1 = float(input("Ingresa el primer número: "))
        num2 = float(input("Ingresa el segundo número: "))
        if num2 != 0:
            resultado = num1 / num2
            print(f"El resultado de la división es: {resultado}")
        else:
            print("No se puede dividir entre cero.")

    elif opcion == "5":
        num1 = float(input("Ingresa la base: "))
        num2 = float(input("Ingresa el exponente: "))
        resultado = num1 ** num2
        print(f"El resultado de la potencia es: {resultado}")

    elif opcion == "6":
        num1 = float(input("Ingresa el número: "))
        if num1 >= 0:
            resultado = num1 ** 0.5
            print(f"La raíz cuadrada de {num1} es: {resultado}")
        else:
            print("No se puede calcular la raíz cuadrada de un número negativo.")

    elif opcion == "7":
        num1 = float(input("Ingresa el número base: "))
        num2 = float(input("Ingresa el porcentaje: "))
        resultado = (num1 * num2) / 100
        print(f"El {num2}% de {num1} es: {resultado}")

    else:
        print("Opción inválida. Por favor, selecciona una opción válida.")
entrada = input("¿Quieres hacer un calculo? ")
while entrada != "no":
    calcular()
    entrada = input("¿Quieres hacer un calculo?")
