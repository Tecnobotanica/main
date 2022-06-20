# Tecnologia Industrial, IES Portada Alta #

Invernadero con riego automatico capaz de adaptar su cantidad de riego segun las situaciones meteorologicas, esto lo consigue mediante: dos sensores de temperatura y humedad, sensor de humedad de tierra y sensor de luminosidad. Todos los datos se pueden visualizar en un lcd o tambien en una web en tiempo real.

## Caracteristicas ##
- Riego mediante bomba atomatica.
- Control de temperatura mediante sensores y ventiladores.
- Control de luminosidad mediante sensores.
-
-
-

## Autores
- Jesus Tello (Diseño web, programacion del Arduino y NodeMCU, esquema electrico de conexiones con sensores, programacion del servidor web y diseño de todas las piezas impresas en 3D)
- Dylan Alvarez (Diseño web)
- Andres Tous
- Candela Torreblanca
- Angel Ramirez
- Angel Rios
- Juan Grande
- Sergio Ruiz

## Programacion y conexion del Arduino y NodeMCU 8266. ##

### Programacion. ###
La gran parte de la programacion esta comentada y es facil de entender pero, la parte en la cual comunicamos el Arduino con el NodeMCU puede ser bastante confusa.

El metodo por el cual hacemos esto es mediante comunicacion serial con ayuda de la libreria SoftwareSerial.h la cual nos simplifica mucho. Usando cualquier salida digital de nuestro arduino y conectandolas al RX y TX del NodeMCU conseguimos escribirle en el puerto serie a nuestro NodeMCU muy comodamente utilizando 
```cpp
monitorSerial.print()
```

Lo mas interesante que he utilizado a sido el formato en el cual se mandan los datos, a cada dato de cada sensor se le asigna una letra delante. Haciendo asi que cuando el NodeMCU reciba los datos los clasifique segun la letra que llevan delante y metiendolos en una variable que utilizaremos posteriormente para subirlo a nuestro servidor web.

### Conexiones. ###
Las conexiones entre el Arduino y el NodeMCU son:  ``` 

                                                    Arduino  ->  NodeMCU
                                                       6     ->     Tx
                                                       7     ->     Rx  ```
                                                       
                                                       
                                                       
Para los sensores las conexiones serian:

                                        ```DHT11.1  ->  4
                                           DHT11.2  ->  2
                                           LDR ->  A1
                                           LCD ->  SDA -> 11
                                                   SCL -> 10 ```
                                                   
                                                   
                                                   
                                           
