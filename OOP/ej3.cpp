// Números enteros

// Suponer (imaginar) que crea la clase Integer con el siguiente método de instancia:

class Integer {
    public:
        int value;
        Integer(int value);
        int getValue();
        void setValue(int value);
        Integer mcd(Integer& other);
};


Integer Integer::mcd( Integer& anInteger)  {
    return anInteger.value == 0 ? *this : anInteger.mcd(*this % anInteger);
}
// Nota: a % b devuelve el resto de dividir a por b.

// Considerar las siguientes expresiones:

new Integer(42).mcd(18);
new Integer(18).mcd(6);
new Integer(6).mcd(0);

// Durante la ejecución de cada una, cuántas veces es enviado el mensaje mcd?

// Para cada mensaje mcd enviado, cuál es el objeto receptor?
// Realizar los diagramas de secuencia.