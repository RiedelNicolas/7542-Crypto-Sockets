* Documentar brevemente TDAs (structs) además de los métodos.
* `#define _POSIX_C_SOURCE` va en la unidad de compilación (el .c), sino se propaga a todas las unidades que hagan include
* Headers: incluir sólo los necesarios, sobre todos los includes dentro de headers, es preferible que estén en las unidades de compilación.
* Usar static en métodos "privados" del tda.
* El diseño de los TDAs Server y Receiver es poco flexible. Fuera de que los nombres no son muy intuitivos (Un Receiver que posee un Server es medio extraño, pero supongo que si estaba documentado el TDA era más fácil de entender), que el Server tenga en su estado un socket Peer dificulta la extensión de la aplicación (por ejemplo, aceptar más de un cliente ya sea secuencial o concurrentemente. Cambiar para que `serverAcceptOne(&(this->server));` esté en receiverRun(), y que su firma sea igual a la de socketAccept(listener, accepted&).

Tener en cuenta para TP3 que tener el `init` y el `bind` (o `connect`) por separado no es muy RAII. 

Respecto a common_parser, no está mal porque hay lógica compartida. Hilando fino, al ser *common* en su totalidad, el ejecutable de Client tiene lógica de parseo del servidor y viceversa. Por eso es que hace un poco de ruido que esté "solo". Si hubiera un ClientArgsParser, y ServerArgsParser que utilicen el *common* se notaría la dependencia que tienen ambos módulos.

Nota: 7

