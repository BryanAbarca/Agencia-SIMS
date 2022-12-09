#include<iostream>
#include <fstream>

using namespace std;
int menu(){
	int x;
	system("cls");
	cout<<"1-Agregar"<<endl;
	cout<<"2-Ver"<<endl;
	cout<<"3-Buscar"<<endl;
	cout<<"4-Modificar"<<endl;
	
	cout<<"opcion"<<endl;
	cin>>x;
	return x;
}
	//////////////////////////////////////////////////
void agregar(ofstream &tex){
	system("cls");
	string nombre,ID,Ingreso,Tipo,Telefono,Correo,Monto;
	tex.open("Usuarios.txt",ios::out|ios::app);
	cout<<"Nombre ";
	cin>>nombre;
	cout<<"Cedula ";
	cin>>ID;
	cout<<"Ingreso ";
	cin>>Ingreso;
	cout<<"Prepago o Pospago ";
	cin>>Tipo;
	cout<<"Telefono ";
	cin>>Telefono;
	cout<<"Correo ";
	cin>>Correo;
	cout<<"Monto ";
	cin>>Monto;
	
	tex<<nombre<<" "<<ID<<" "<<Ingreso<<" "<<Tipo<<" "<<Telefono<<" "<<Correo<<" "<<Monto<<"\n";
	tex.close();
}
//////////////////////////////////////////////////

void Ver(ifstream &Lectura){
	system("cls");
	string nombre,ID,Ingreso,Tipo,Telefono,Correo,Monto;
	Lectura.open("Usuarios.txt",ios::in);
	if(Lectura.is_open()){
	Lectura>>nombre;
	while(!Lectura.eof()){
		Lectura>>ID;
		Lectura>>Ingreso;
		Lectura>>Tipo;
		Lectura>>Telefono;
		Lectura>>Correo;
		Lectura>>Monto;
		cout<<"nombre= "<<nombre<<endl;
		cout<<"Cedula= "<<ID<<endl;
		cout<<"Ingreso= "<<Ingreso<<endl;
		cout<<"Tipo= "<<Tipo<<endl;
		cout<<"Telefono= "<<Telefono<<endl;
		cout<<"Correo= "<<Correo<<endl;
		cout<<"Monto= "<<Monto<<endl;
		cout<<"___________________"<<endl;
		Lectura>>nombre;
	}
	Lectura.close();}
	
	system("pause");
}
//////////////////////////////////////////////////
void Buscar(ifstream &Lectura){
	system("cls");
	Lectura.open("Usuarios.txt",ios::in);
	string nombre,ID,Ingreso,Tipo,Telefono,Correo,Monto,aux;
	bool encontrado=false;
	cout<<"Digite la Cedula a Buscar ";
	cin>>aux;
	Lectura>>nombre;
	while(!Lectura.eof()&& !encontrado){
		Lectura>>ID;
		Lectura>>Ingreso;
		Lectura>>Tipo;
		Lectura>>Telefono;
		Lectura>>Correo;
		Lectura>>Monto;
		if(ID==aux){
			cout<<"nombre= "<<nombre<<endl;
			cout<<"Cedula= "<<ID<<endl;
			cout<<"Ingreso= "<<Ingreso<<endl;
			cout<<"Tipo= "<<Tipo<<endl;
			cout<<"Telefono= "<<Telefono<<endl;
			cout<<"Correo= "<<Correo<<endl;
			cout<<"Monto= "<<Monto<<endl;
			cout<<"___________________"<<endl;
			encontrado=true;
		}
	Lectura>>nombre;
	}
	Lectura.close();
	if(!encontrado){
		cout<<"Usuario no encontrado"<<endl;
	}
	system("pause");
}
//////////////////////////////////////////////////
void Modificar(ifstream &Lectura){
	system("cls");
	string nombre,ID,Ingreso,Tipo,Telefono,Correo,Monto;
	string auxnombre,auxID,auxIngreso,auxTipo,auxTelefono,auxCorreo,auxMonto;
	
	Lectura.open("Usuarios.txt",ios::in);
	ofstream aux("Auxiliar.txt",ios::out);
	
	if(Lectura.is_open()){
		cout<<"Cedula";
		cin>>auxID;
		Lectura>>nombre;
		while(!Lectura.eof()){
			Lectura>>ID;
			Lectura>>Ingreso;
			Lectura>>Tipo;
			Lectura>>Telefono;
			Lectura>>Correo;
			Lectura>>Monto;
			
			if(ID==auxID){
				cout<<"Dgite el nuevo nombre";
				cin>>auxnombre;
				cout<<"Dgite el nuevo Ingreso";
				cin>>auxIngreso;
				cout<<"Dgite el nuevo Tpo";
				cin>>auxTipo;
				cout<<"Dgite el nuevo Telefono";
				cin>>auxTelefono;
				cout<<"Dgite el nuevo Correo";
				cin>>auxCorreo;
				cout<<"Dgite el nuevo Monto";
				cin>>auxMonto;
				
				aux<<auxnombre<<" "<<ID<<" "<<auxIngreso<<" "<<auxTipo<<" "<<auxTelefono<<" "<<auxCorreo<<" "<<auxMonto<<"\n";
			}else{
				aux<<nombre<<" "<<ID<<" "<<Ingreso<<" "<<Tipo<<" "<<Telefono<<" "<<Correo<<" "<<Monto<<"\n";
			}
			Lectura>>nombre;
		}Lectura.close();
		aux.close();
	}else{cout<<"Error"<<endl;}
	remove("Usuarios.txt");
	rename("Auxiliar.txt","Usuarios.txt");
	
}
//////////////////////////////////////////////////
int main () {
	ofstream Texto;
	ifstream Lectura;
	int op;
	do{
		system("cls");
		op=menu();
		switch(op){
		case 1:
			agregar(Texto);
			break;
		////////////////////
		case 2:
			Ver(Lectura);
			break;
		///////////////////
		case 3:
			Buscar(Lectura);
			break;
			///////////////////
		case 4:
			Modificar(Lectura);
			break;
		}
	} while(op!=5);
	
	return 0;
}

