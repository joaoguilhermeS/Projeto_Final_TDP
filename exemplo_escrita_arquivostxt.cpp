// basic file operations
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Paciente{
private:
	string nome;
	int idade;
	//Inserir um tipo que veja a hora de acesso
	
public:
	Paciente(){}
	~Paciente(){}
	void valorNome(string n){nome=n;}
	void valorIdade(int i){idade = i;}
	
	string valorNome(){return nome;}
	int valorIdade(){return idade;}
};
	

int main () {
	Paciente p;
	string nome;
	int idade;
	
	cout<<"\nMe informe o Nome  : ";
	cin>>nome;
	
	cout<<"\nMe informe a idade : ";
	getchar();
	cin>>idade;
	
	
	p.valorNome(nome);
	p.valorIdade(idade);

	ofstream myfile;
	myfile.open ("example.txt", ios::out | ios::app);
	myfile << "Paciente : " <<p.valorNome() <<", Idade:"<<p.valorIdade()<<endl;



	myfile.close();
	return 0;
	
}
