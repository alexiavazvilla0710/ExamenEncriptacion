#include <iostream>
#include <string> //se usa para poder utilizar palabras en el código
using namespace std;

// Se necesita un for para descubir la palabra de 2 en 2- esta es la función para las palabras
string descifrar(string palabra) { // Esta función recibe una palabra y devolverá la palabra descifrada
    for (int i = 0; i < palabra.length() - 1; i += 2) {
    	//este es un ciclo for que recorre la palabra de 2n en 2 como 0-1, 2-3, 4-5, etc.
    	//.length es algo que usa c++ ppara saber cuantas letras tiene una palabra
    	// la i empieza en 0, luego vale 2, 4 y así sucesivamente
        char temp = palabra[i]; //es pareccido a lo que hicimos con bubble sort donde guardamos temporalmente la letra en la posición i 
        palabra[i] = palabra[i + 1]; //aqui se cambia la letra i por la letra que está en la en i+1
        palabra[i + 1] = temp; //y finalmente pone la letra guardada en i en la posición i+1
    }
    return palabra; //nada más devuelve la palabra descifrada
}

//ahora vamos con el programa principal
int main() {
    string mensaje; //una variable para el mensaje cifrado que escriba el usuario
    cout << "Ingresa el mensaje cifrado: ";
    getline(cin, mensaje); //lo lee incluyendo los espacios

    // Validación: solo minúsculas y espacios para que no haya ningun error o bug
    for (int i = 0; i < mensaje.length(); i++) { //se recorre cada letra del mensaje
        char c = mensaje[i]; //se toma la letra actual en i
        if (!((c >= 'a' && c <= 'z') || c == ' ')) {
        	//si la letra NO está entre 'a' y 'z' o no es espacio arroja el siguiente mensaje
            cout << "Error: solo se permiten minusculas y espacios." << endl;
            return 0;
        }
    }

    string palabra = ""; //se construye la palabra letra por letra
    string resultado = ""; //se guarda el mensaje descifrado final

    // Recorrer el mensaje
    for (int i = 0; i < mensaje.length(); i++) {
        if (mensaje[i] == ' ') {
            // si ya tenemos una palabra, descifrarla
            if (palabra != "") {
				resultado += descifrar(palabra) + " "; //se descifra y agregamos un espacio
            	palabra = ""; //se reinicia para la siguiente palabra
            }
        } else {
            palabra += mensaje[i]; //si no hay espacio, solamente se agrega la letra a la palabra actual
        }
    }

    // Última palabra si no terminó en espacio
    if (palabra != "") {   //para la palabra pendiente
        resultado += descifrar(palabra); //se descifra
    }

    cout << "Mensaje descifrado: " << resultado << endl; //manda el mensaje resuelto
    return 0;
}

