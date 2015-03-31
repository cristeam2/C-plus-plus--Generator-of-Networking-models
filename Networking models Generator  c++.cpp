/*Program to generate Barabási–Albert (Scale-free networks) and Erdős–Rényi (random networks) networks models in .CSV formats */

#include <iostream>
#include <fstream>
#include <time.h>
#include <stdlib.h>
#include <vector>
#include <string>

using namespace std;


//Method for the model of random networks:
void Erdos–Renyi(int nodo, double p)
{
    double probabilidad;
	bool nodoUnido ;
    ofstream archivo;
    string nod = to_string(nodo);
    string prob = to_string(p);
    string nomArchivo = "Erdos-Renyi " + nod +" "+ prob + ".csv";
    // Control for probabilities:
    if(p > 1 || p < 0) {
        cout<<"p debe estar entre 0 y 1 "<<endl;
    }
    //Generate the file and the random pattern
    else {
        srand (time(NULL));
        archivo.open(nomArchivo);
		
        //Algorithm to calculate the network model
		for (int i = 0; i < nodo; i++)
		{
			nodoUnido = false;
			cout << "\rCalculating node:" << i+1;
			for(int j = nodo-1; j > i;j--){
				probabilidad = (rand()/(double)(RAND_MAX + 1));
				//Do the link if the probabilities is good
                if( probabilidad <= p){
					archivo << i <<"; " << j << endl;
					nodoUnido = true;
				}
			}
			if(!nodoUnido)
				archivo << i <<endl;


		}

	}
        archivo.close();
        cout<<endl;
        cout<<"File with name: "<<nomArchivo<< " has been generated successfully"<<endl;
}


//Method for the model of scale-free network
void  Barabasi–Albert(int m,int t)
{
    double probabilidad;
    ofstream archivo;
    string enlaces = to_string(m);
    string iterac = to_string(t);
    string nomArchivo = "Barabasi-Albert " + enlaces +" "+ iterac + ".csv";
    archivo.open(nomArchivo);
    srand(time(NULL));
    probabilidad = (rand()/(double)(RAND_MAX +1));
    vector<double> listaProbabilidad;
    vector <bool> listaPasada ;
    vector <int> listaGradoNodo;
    int nodoActuales;
    
    //Started nodes
    int m0 = m + 1;
    
    //Initial links for each node
    double SumaKjIni = m0*m;
    
    //Calculating ki (Degree of each node)
    double ki = SumaKjIni/m0;
    
    //Calculating the probability of each node
    for (int i =0;i<m0; i++){
        listaProbabilidad.push_back(ki/SumaKjIni);
        //Started degrees
        listaGradoNodo.push_back(ki);
    }
    
    //We link all the started nodes
    for (int i = 0; i < m0; i++)
    {
        for(int j = i+1; j < m0;j++)
        {
            archivo << i <<"; " << j << endl;
        }
    }
    
    //Assign to the  variable the current nodes values
    nodoActuales = m0;
    
    //Add nodes as many times as it requeries
    for (int j =0;j<t; j++)
    {
        cout <<"\rCalculando Nodo:"<<(j+1);
       
        //Reload and restart the vector
        listaPasada.clear();
        for (int i =0;i<nodoActuales; i++)
        {
            listaPasada.push_back(false);
        }
        int contador = 0;
        
        //As we do not have the m links
        while( contador < m )
        {
            //probabilidad = (rand()/(double)(RAND_MAX +1));
            for (int i =0;i<nodoActuales; i++)
            {
                //Check if we have to link
                probabilidad = (rand()/(double)(RAND_MAX +1));
                int numAleatorio= rand()%(nodoActuales);
                if(!listaPasada[i] && contador < m && probabilidad < listaProbabilidad[i] )
                {
                    //Recalculamos la probabilida del nodo al que se une
                    listaGradoNodo[i]++;
                    listaProbabilidad[i]=listaGradoNodo[i]/(SumaKjIni+m*(j+1));
                    listaPasada[i]= true;
                    //Creating link
                    archivo << i <<"; " << listaProbabilidad.size()<< endl;
                    contador++;
                }
            }
        }
        //Are creating the m links, so we will calculated the probability of the new node
        listaProbabilidad.push_back(m/(SumaKjIni+m*(j+1)));
        nodoActuales++;
        
        //Refresh the worth of the new node (this is the numbers of links it will have )
        listaGradoNodo.push_back(m);
    }
    archivo.close();
    cout<<endl;
    cout<<"File with name: "<<nomArchivo<< " has been generatad successfully "<<endl;
}


//Main launch method with a little console message:
int main(int argc, char *argv[])
{
    if(argc == 1 || argc > 4 || *argv[1] == 'h')
    {
        cout<<"Arguments of the application: "<<endl;
        cout<<"    -Help: [h]"<<endl;
        cout<<"    -Erdos-Renyi: [e] [Number of nodes] [Probability of the link ]"<<endl;
        cout<<"    -Barabasi-Albert: [b] [Number of nodes] [Total number of iterations]"<<endl;
    }
    else
        //start Erdos-Renyi model
        if (*argv[1] == 'e')
        {
            int n = atof(argv[2]);
            double p = atof(argv[3]);
            Erdos–Renyi(n, p);
        }
    else
        //start Barabasi-Albert model
        if (*argv[1] == 'b')
        {
            int m = atof(argv[2]);
            int t = atof(argv[3]);
            Barabasi–Albert(m, t);
        }
    return 0;
}




