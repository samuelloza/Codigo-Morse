#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <map>
#include <windows.h>
using namespace std;
map<string,string> mapa;
//genera codigo morse
// si quieren agregar mas codigo solo seguir como ejemplo
void genera(){
	mapa["A"]=".-";
	mapa["B"]="-...";
	mapa["C"]="-.-.";
	mapa["D"]="-..";
	mapa["E"]=".";
	mapa["F"]="..-.";
	mapa["G"]="--.";
	mapa["H"]="....";
	mapa["I"]="..";
	mapa["J"]=".---";
	mapa["K"]="-.-";
	mapa["L"]=".-..";
	mapa["M"]="--";
	mapa["N"]="-.";
	mapa["O"]="---";
	mapa["P"]=".--.";
	mapa["Q"]="--.-";
	mapa["R"]=".-.";
	mapa["S"]="...";
	mapa["T"]="-";
	mapa["U"]="..-";
	mapa["V"]="...-";
	mapa["W"]=".--";
	mapa["X"]="-..-";
	mapa["Y"]="-.--";
	mapa["Z"]="--..";
	mapa["1"]=".----";
	mapa["2"]="..---";
	mapa["3"]="...--";
	mapa["4"]="....-";
	mapa["5"]=".....";
	mapa["6"]="-....";
	mapa["7"]="--...";
	mapa["8"]="---..";
	mapa["9"]="----.";
	mapa["0"]="-----";
	mapa["."]=".-.-.-";
	mapa[","]="--..--";
	mapa[":"]="---…";
	mapa["?"]="..--..";
	mapa["/"]="-..-.";
}

/*
For Code::Blocks, go to Project/Build Options/Linker settings and add winmm to the link libraries (no .lib at the end!).
*/
void play(string proy_uri,string uri){
    //"/home/sam/qt_proy/morse/sound_morse/"
    string rutas=proy_uri+"/"+uri+".wav";
    char *y = new char[rutas.length() + 1];
    strcpy(y, rutas.c_str());
PlaySound( y, NULL, SND_FILENAME);
	//para q exista una pqueña pausa al escuchar

}
void dalida(string conver){
	cout<<"La salida es :"<<endl;
	cout<<"+---------------------------------------------------+"<<endl;
	cout<<"  "<<conver<<endl;
	cout<<"+---------------------------------------------------+"<<endl;
}
void letra_a_morse(){
	string uri1="sound_morse";
	cout<<"Su mensaje es -> ";
	string cade,conver="";
	getchar();//lee el enter
	getline(cin,cade);
	cout<<"Procesando ...."<<endl;
	for(int i=0;i<cade.size();i++){
		string  data;
		data=toupper(cade[i]);
		conver+=mapa[data];
		//reproduce sonido
		play(uri1,data);
		//fin  sonido
		conver+=" ";
	}
	dalida(conver);
}

void morse_a_letra(){
	//separador por espacios
	cout<<"Su mensaje en morse es 'separado por espacios':";
	string code="",aux="",convert="";
	getchar();
	getline(cin,code);
	string uri1="sound_sp/";
	for(int i=0;i<code.size();i++){
		if(code.at(i)==' '){
			bool encontro=false;
            //iterator begin search
			map<string, string>::iterator it = mapa.begin();
			for(;it!=mapa.end();it++){
				if(it->second.compare(aux)==0){
					convert+=it->first;
                    //reproduce
					play(uri1,it->first);
					encontro=true;
                    break;//como encontro el valor sale del for
                }
            }
            //iterator end
            if(encontro==false){
            	convert+=" ";
            }
            aux="";
        }else{
        	aux+=code[i];
        }
    }
	//prueba por si no termina con espacio el final
    if(aux!=""){
    	map<string, string>::iterator it = mapa.begin();
    	for(;it!=mapa.end();it++){
    		if(it->second.compare(aux)==0){
    			convert+=it->first;
                //
    			play(uri1,it->first);
                //
    			break;
    		}
    	}

    	aux="";
    }
    dalida(convert);
}
void menu(){
	cout<<endl;
	cout<<"-----------------------------------------"<<endl;
	cout<<"------Letra a morse o Morse a letra------"<<endl;
	cout<<"-----------------------------------------"<<endl;
	cout<<"   Ingrese una opcion : "<<endl;
	cout<<"1.- Letra [A-Z][0-9][.,:?/] a morse "<<endl;
	cout<<"2.- Morse a Letra [A-Z][0-9][.,:?/]"<<endl;
	cout<<"3.- Terminar"<<endl;
	cout<<"*****************************************"<<endl;
	cout<<"*****************************************"<<endl;

}
int main(){
	int opcion=0;
	menu();
	genera();
	while(true){
		cin>>opcion;
		if(opcion==3){cout<<"Bye"<<endl;break;}
		if(opcion==1){
			cout<<"Ingrese solo Letra [A-Z][0-9][ ]"<<endl;
			letra_a_morse();
		}else if(opcion==2){
			cout<<"Ingrese solo [.] o [-] [ ]"<<endl;
			morse_a_letra();
		}
		menu();
	}
	return 0;
}
