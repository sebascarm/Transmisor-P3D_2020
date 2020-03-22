Transmisor P3D 2020 v1.2.4
* 21/03/2020
    * Funciones     v1.5 (Funcion Split para string)
    * P3D           v3.1 (Envio a placa con mapeo)
    * WinApi        v2.5 (Doble Click en ListBox)
        * ListBox   v2.1 (Doble Click)

Transmisor P3D 2020 v1.2.3
=====================
* 21/03/2020
    * P3D           v3.0 (Envio completo)
    * Funciones     v1.4 (Mapeo doble y correciones)

Transmisor P3D 2020 v1.2.3
=====================
* 18/03/2020
    * WinApi        v2.4 (RichText con SetFont)
    * P3D           v2.4 (Uso de decimales)
    * Funciones     v1.3 (Split String en vector)
    * Archivo       v1.1 (Lectura de linea en vector)

* 17/03/2020
    * Transmisor    v2.2 (Usando RichText)
    * P3D           v2.3 (Enviar datos al sim)
    * Funciones     v1.2 (String a Double)
    * WinApi        v2.3 (RichText)

* 15/03/2020
    * WinApi        v2.2 (Habiltiar y deshabilitar objetos)
        * MultiLine v1.1 (Correccion al resize)
        * Objeto    v2.1 (habilitar y deshabilitar objetos)
    * Transmisor    v2.1 (Eventos separado)
    * P3D           v2.2 (Recepcion y activacion)
    * P3D           v2.2 (Recepcion PMDG separado)

* 08/03/2020
    * WinApi        v2.1
        * ListBox   v2.0 (SetFont)
        * ListBox   v2.0 (Event ChangeCell)
        * Objeto    v2.0 (SetFont)
    * P3D           v2.1 (Obtener vectores)
    * Funciones     v1.1 (Funcion RedimSTR)

* 06/02/2020
    * WinApi             (ListBox)

* 01/02/2020
    * Transmisor    v2.0
    * P3D           v2.0
    * Archivo       v1.0
    * Funciones     v1.0
    * Creacion

## Librerias
 - WinApi
 - P3D


## GIT + Github

 - Crear Proyecto en GitHub (Web)
```
 - git init 'Nombre de carpeta' 
 - // Copiar archivos al folder
 - // agregar .gitignore
 - // agregar readme.md
 - git add . // Agrega los archivos al proyecto
 - git commit -m "primer commit"
 - git remote add origin https://github.com/USUARIO/PROYECTO.git
 - git push -u origin master
```
 
### Usuario
- git config --global user.email "sebascarm@gmail.com"
- git config --global user.name "sebascar"

### GitHub Comando
- Crear proyecto
- git remote add origin
- git push -u origin master
- git pull // trae los cambios del servidor
- git clone DIRECCION // se trae a local los archivos del repositorio

### Actualizar el -gitignore
- git rm -r --cached .
- git add .
- git commit -m "Atualizando .gitignore para..."

----------------

# Transmisor P3D
Software encargado de la intercomunicacion entre Arduino y P3D PMDG mediante dos canales de comunicación.

## Caracteristicas principales
Gestión de la comunicación con Arduino.
Gestión de comunicación con P3D mediante SimConnect.
Gestión de transmision de datos a procesos remotos mediante Socket.
Gestión remota.

## Comunicación
En resumen este software se instala en un Equipo mediador, el cual se conectará fisicamente con 2 placas Arduino a travez de su puertos serie y el programa se encargara de analizar los paquetes y datos recibidos para traducirlos y transmitir en forma remota o local al Servidor P3D mediante SimConnect.

## Transmisor de datos remotos
Comunicación conta software Comandos para ejecución de procesos y eventos en forma remota.

## Gestión Remota
Aplicación Cliente Servidor para analizar y gestionar la transmisión de forma remota.


