# Tecnologia Industrial, IES Portada Alta #

Jesús García, Andres Tous, Candela Torreblanca, Angel Ramirez, Angel Rios, Dylan Alvarez, Juan Grande y Sergio Ruiz.



## Caracteristicas ##
-
-
-
-



## Autores
- Jesus Tello (Diseño web)
- Dylan Alvarez (Diseño web)
-
-
-


## Lista de cambios ##
#### Version 0.1.0 (30/05/2022) ####
- Version inicial.



## Programacion y conexion del Arduino y NodeMCU 8266 ##

### Programacion ###
- La gran parte de la programacion esta comentada y es facil de entender pero, la parte en la cual comunicamos el Arduino con el NodeMCU puede ser bastante confusa.

El metodo por el cual hacemos esto es mediante comunicacion serial con ayuda de la libreria SoftwareSerial.h la cual nos simplifica mucho. Usando cualquier salida digital de nuestro arduino y conectandolas al RX y TX del NodeMCU conseguimos escribirle en el puerto serie a nuestro NodeMCU muy comodamente utilizando 
```cpp
monitorSerial.print()
```

Lo mas interesante que he utilizado a sido el formato en el cual se mandan los datos, a cada dato de cada sensor se le asigna una letra delante. Haciendo asi que cuando el NodeMCU reciba los datos los clasifique segun la letra que llevan delante y metiendolos en una variable que utilizaremos posteriormente para subirlo a nuestro servidor web.

### Conexiones ###
-
