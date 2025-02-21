#include<iostream>
#include<unordered_map>

using namespace std;

int main(){
	// Declarar un unordered_map que asocia strings a enteros
	unordered_map<string, int> edades;
	//Agregar elementos al unordered_map
	edades["Juan"] = 25;
	edades.insert({"Alfonso", 25});
	edades["Maria"] = 30;
	edades["Pedro"] = 22;
	edades.insert(make_pair("Ana", 28)); //Acceder a un elemento
	
	cout << "La edad de Maria es: " << edades["Maria"] << endl;
	
	//Iterar sobre el unordered_map
	cout << "La lista de edades: " << endl;
	
	for(const auto& par : edades){
		cout << par.first << " tiene " << par.second << "a os " << endl;
	}
	
	//Buscar un elemento
	string nombre = "Pedro";
	if(edades.find(nombre) != edades.end()){
		cout << nombre << " esta en el mapa con " << edades[nombre] << " a os." << endl;
	}else{
		cout << nombre << " no esta en el mapa." << endl;
	}
	return 0;
}
