Enunciado: Gestión de Inventario de una Tienda

Eres el encargado de desarrollar un sistema de gestión de inventario para una tienda que almacena información sobre sus productos. El sistema debe permitir:

Leer la información de los productos desde un archivo de texto (productos.txt). Cada línea del archivo contiene la información de un producto con el siguiente formato:

ID Nombre Cantidad Precio
ID: Número entero que identifica el producto.
Nombre: Nombre del producto (máximo 30 caracteres).
Cantidad: Cantidad de productos en stock (entero positivo).
Precio: Precio del producto (flotante positivo).
Almacenar esta información en memoria usando una estructura de datos adecuada.

Implementar las siguientes funcionalidades:

Añadir un nuevo producto: Permitir al usuario ingresar un nuevo producto (con ID, Nombre, Cantidad y Precio) y agregarlo a la lista de productos en memoria.
Eliminar un producto: Eliminar un producto del inventario a partir de su ID.
Modificar la cantidad de un producto: Permitir modificar la cantidad de stock de un producto a partir de su ID.
Buscar un producto: Buscar un producto por su ID y mostrar su información.
Listar todos los productos: Mostrar en pantalla la lista completa de productos, ordenada alfabéticamente por el nombre del producto.
Al final de la ejecución del programa, guardar la lista actualizada de productos en un archivo binario (productos.bin), manteniendo el mismo formato de datos (ID, Nombre, Cantidad y Precio).

Requisitos adicionales:
Implementar un menú que permita al usuario realizar las distintas operaciones del sistema (añadir, eliminar, modificar, buscar, listar).
Manejar archivos de texto para la lectura inicial y archivos binarios para la escritura final.