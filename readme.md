Transmisor P3D 2020 v1.0.0
=====================
* 01/02/2020
    * Creacion

## Librerias
 - WinApi
 - P3D

--------------
## GIT + Github
--------------
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

# Transmisor P3D
=====================
Software encargado de la intercomunicacion entre Arduino y P3D PMDG mediante dos canales de comunicación.

## Caracteristicas principales
------------------------------
Gestión de la comunicación con Arduino.
Gestión de comunicación con P3D mediante SimConnect.
Gestión de transmision de datos a procesos remotos mediante Socket.
Gestión remota.

## Comunicación
---------------
En resumen este software se instala en un Equipo mediador, el cual se conectará fisicamente con 2 placas Arduino a travez de su puertos serie y el programa se encargara de analizar los paquetes y datos recibidos para traducirlos y transmitir en forma remota o local al Servidor P3D mediante SimConnect.

## Transmisor de datos remotos
------------------------------
Comunicación conta software Comandos para ejecución de procesos y eventos en forma remota.

## Gestión Remota
-----------------
Aplicación Cliente Servidor para analizar y gestionar la transmisión de forma remota.


