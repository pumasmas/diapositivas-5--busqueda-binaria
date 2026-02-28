# Plantilla de Diapositivas - Club de Programación Competitiva Pu++

Esta plantilla LaTeX está diseñada para facilitar la creación de
**presentaciones modulares, limpias y profesionales** para las clases de
programación competitiva del club Pu++. Incluye soporte para **resaltado de
código**, **macros algorítmicas** y **cajas estilizadas** para material
didáctico.

---

## Guía de Uso para Profesores

**Importante**: Este repositorio funciona como una **plantilla base**. El
contenido específico de sus clases (temas, ejercicios, explicaciones) debe
residir en su propio repositorio independiente. Los cambios de contenido no
están destinados a modificarse en esta plantilla.

### 1. Inicialización de un Nuevo Curso
Para comenzar a preparar diapositivas para un nuevo tema o semestre:

1.  **Crear su Repositorio**: Utilice este proyecto como base para crear un **nuevo repositorio** independiente (ej. `slides-grafos-2026` o `curso-dp-avanzado`).
2.  **Trabajo Independiente**: Realice todos los cambios de contenido en su nuevo repositorio. Esta plantilla original solo debe recibir cambios si desea mejorar el diseño o la estructura base.

### 2. Estructura del Proyecto
Una vez en su propio repositorio, encontrará la siguiente organización:

*   **sections/**: Contiene los archivos fuente LaTeX (`.tex`) de cada tema o bloque de diapositivas.
*   **code/**: Almacena los códigos fuente (`.cpp`, `.py`) que se incluirán en las diapositivas.
*   **main.tex**: Archivo principal que orquesta la compilación de la presentación completa.

### 3. Crear un Nuevo Tema
Para agregar un nuevo tópico a su curso:

1.  **Crear el archivo**: Copie el archivo `sections/template.tex` y renómbrelo (ej. `sections/dp.tex`).
2.  **Integrar al documento**: Abra `main.tex` y añada su nuevo archivo en la lista de inclusiones:
    ```latex
    \include{sections/dp}
    ```
3.  **Redactar**: Edite `sections/dp.tex` agregando su contenido.

### 4. Entornos Predefinidos
La plantilla ofrece entornos visuales ("cajas") para estructurar la información
en las diapositivas:

*   **DefinitionP**: Para conceptos formales y estructuras de datos.
*   **TheoremP**: Para propiedades matemáticas y lemas.
*   **TipP**: Consejos prácticos y trucos de implementación.
*   **AlertP**: Advertencias sobre errores comunes.
*   **ExampleP**: Casos de prueba, trazas o diagramas.
*   **ExerciseP**: Problemas propuestos para los alumnos.

### 5. Gestión de Código Fuente
Para garantizar que el código mostrado en las diapositivas sea correcto:

1.  Cree un archivo funcional en la carpeta `code/` (ej. `code/segment_tree.cpp`).
2.  Importe el archivo en sus diapositivas utilizando el comando:
    ```latex
    \twocolumnminted{code/template.cpp}{cpp}{20}
    ```
    Note que los argumentos son el nombre de archivo, el lenguaje de
    programación y en qué línea se dividen las dos columnas de código.

### 6. Compilación
*   **Local**: Ejecute el comando `./make` en la raíz del proyecto (requiere entorno LaTeX instalado).
*   **Local (Docker)**: Ejecute el comando `./make docker` en la raíz del proyecto (requiere Docker y ~700MB).

**Nota**: La versión en Docker tomará unos pocos minutos la primera vez que se
corre, pero después debería ser tan rápido como compilar el documento
nativamente.

---

## Guía Técnica para Desarrolladores

Esta sección está dirigida a quienes deseen mejorar la **infraestructura de la
plantilla misma** (estilos, macros, configuración).

### Arquitectura del Proyecto
*   **config/pumasmas.sty**: Define la identidad visual (colores, paquetes, estilos de las diapositivas).
*   **macros.tex**: Centraliza los comandos personalizados (`\bigO`, `\practiceproblem`, `\algorithmstep`).
*   **cover.tex**: Define el aspecto de la portada de las presentaciones.
*   **logo.png**: El logo que aparecerá en la portada.
*   **make**: Automatiza el proceso de compilación.
*   **Dockerfile**: Define el ambiente de trabajo para compilar en Docker.

### Requisitos de Construcción
*   Distribución TeX completa.
*   `latexmk`, Python 3 y Pygments.
*   `python`.

### Requisitos de Construcción (Docker)
*   `docker`.
*   `python`.

### Flujo de Contribución (Pull Requests)
Si desea mejorar esta plantilla para que todos los futuros cursos se beneficien:

1.  **Branching**: Cree una rama descriptiva (ej. `feat/nueva-caja-ejemplo`).
2.  **Verificación**: Asegúrese de que `./make clean && ./make` compile sin errores.
3.  **Pull Request**: Abra un PR hacia este repositorio original describiendo sus mejoras técnicas.
