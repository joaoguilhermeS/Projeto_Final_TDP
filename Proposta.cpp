#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
class Paciente_t
{
  protected:
  string nome,sexo;
  int idade,diag;
  public:
  Paciente_t(string n,string s, int i)
  {
     nome = n;
     idade = i;
	 sexo = s;
  }
  string  name(){return nome;};
  string  sex(){return sexo;};
  int  id(){return idade;}; 
  void set_name(string n){nome = n;};
  void set_sex(string s){sexo = s;};
  void set_id(int i){idade = i;};
};
class Pisico_t : public Paciente_t
{
	string linha;
	public:
	Pisico_t(string n, string s, int i):Paciente_t(n,s,i)
	{
		set_name(n);
		set_sex(s);
		set_id(i);
		fstream arquivo;
		arquivo.open("Usuarios.txt",ios::out|ios::app);
		arquivo<<nome<<"  "<<sexo<<"  "<<idade<<" anos  ";
		arquivo.close();
	}
	~Pisico_t()
	{
		//Passar as respostas das questoes e sintomas para o arquivo;
	}
	void syntoms()
	{
		fstream lista;
		lista.open("Sintomas.txt",ios::in);
		if(lista.is_open())
		{   
			while(getline(lista,linha))
			{
				cout<<linha<<endl;
			}
			cout<<"Quantos dos sintomas abaixo voce possui?"<<endl;	
			cin>>diag;
		}
	}
};
class Corona_t : public Paciente_t
{
	//Falta fazer a class Corona;
};
int main()
{
     string n,se;
     int i,s;
     cout<<"Digite o seu nome: ";
     cin>>n;
     cout<<endl;
	 Erro:
	 cout<<"Digite a sua idade: ";
	 cin>>i;
	 cout<<endl;
	 if(cin.fail())
	 {
		 cin.clear();
		 cin.ignore();
		 goto Erro;
	 }
	 Erro1:
	 cout<<"Digite o seu sexo: 1-Masculino 2-Feminino"<<endl;
     cin>>s;
	 switch(s)
	 {
		 case 1:
			se = "Masculino";
		break;
		case 2:
			se = "Feminino";
		break;
		default: 
			cout<<"Opcao de sexo invalida!!"<<endl;
			goto Erro1;
	 }
	 ajuda:
	 int help;
	 cout<<"Digite 1 para ajuda psicologica e digite 2 para ajuda com o coronavirus?"<<endl;
	 cin>>help;
   //A ideia aqui seria escolher para qual classe o usuario iria, porém esta dando erro na compilação, tenta me ajudar; 
	 switch(help)
	 {
		 case 1:
			Pisico_t usuario(n,se,i);
			usuario.syntoms();
		break;
		case 2:
			//Corona_t...
			break;
	 }
  return 0;
}
