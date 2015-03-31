# Network-models-Generator-c-
(C++) Program to generate Barabási–Albert (Scale-free networks) and Erdős–Rényi (random networks) networks models in two .CSV files

You can see the networks definition on:
http://en.wikipedia.org/wiki/Erdős–Rényi_model
http://en.wikipedia.org/wiki/Barabási–Albert_model


Algorithm strategy (in Spanish):

Erdős–Rényi:
Se desarrollara una pequeña aplicación que genere una red aleatoria dados los valores N(>0) –el número de nodos inicial– y p (0 ≤ p ≤ 1) –la probabilidad de enlaces 1 dentro de la red. 

Barabási–Albert:
Se desarrollar una pequeña aplicación que genere una red libre de escala siguiendo el modelo de Barabasi-Albert dados los valores m(>0) –el número de enlaces con los que entra un nodo nuevo a la red– y t (>0)) –el número de pasos del modelo. Suponer que m0 = m + 1 y que en la configuración inicial todos los nodos están unidos con todos.En estas redes el número de nodos es dependiente del número de pasos dados en el modelo: N (t) = m0 + t.


La aplicación generara un fichero en  formato CSV el cual es capaz de importar Gephi (CSV  nodos y aristas van por separado).
