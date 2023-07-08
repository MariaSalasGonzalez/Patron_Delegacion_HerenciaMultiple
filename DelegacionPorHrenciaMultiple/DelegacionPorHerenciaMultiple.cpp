#include <iostream>
#include <string>
using namespace std;

class Persona {
protected:
	string nombre;
public:
	Persona(string nom) {
		nombre = nom;
		cout << "Creando Persona" << endl;
	}
	virtual ~Persona(){

	}

	virtual void alimenta() {
		cout << "Yo" << nombre << "me alimento 3 veces al dia." << endl;
	}

	virtual void camino() {
		cout << "Yo camino diariamente" << endl;
	}

	virtual void dormir() {
		cout<<"Yo duermo 8 horas" << endl;
	}
};

class Estudiante {
public:
	void asistirALecciones() {
		cout << "Yo asisto a clases en la U." << endl;
	}

	void hacerAsignaciones() {
		cout << "Yo realizo trabajos morales en programacion" << endl;
	}
};

class Deportista {
public:
	void correMaraton() {
		cout << "Yo corro maraton por las carreteras" << endl;
	}

	void saltoAlto() {
		cout << "Soy deportista y salto alto como el sapito" << endl;
	}
};

class Amigo : public Persona {
private:
	Estudiante* estPtr;
	Deportista* depPtr;
public:
	Amigo(string nom):Persona(nom){
		cout << "Creando objeto amigo" << endl;
		estPtr = new Estudiante();
		depPtr = new Deportista();
	}

	virtual ~Amigo() {
		cout << "Eliminando al objeto amigo" << endl;
		delete estPtr;
		delete depPtr;
	}

	void AsistirALecciones() {
		estPtr->asistirALecciones();
	}

	void saltoAlto() {
		depPtr->saltoAlto();
	}

};

int main() {
	cout << "Creando instancia de la clase Amigo" << endl;
	Amigo* ptrAmig = new Amigo("Pablo");

	//Accediendo a sus metodos

	ptrAmig->alimenta();
	ptrAmig->camino();
	ptrAmig->dormir();
	ptrAmig->AsistirALecciones();
	ptrAmig->saltoAlto();

	system("pause");
	return 0;
}