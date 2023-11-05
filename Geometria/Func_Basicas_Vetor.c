#include <stdio.h>
#include <math.h>
#include <stdlib.h>
// stuct que define origem de ponto org ate o ponto des o que define um vetor, module guarda o modulo do vetor
//inv_vector guarda o vetor inversor
typedef struct {
	double *vec;
	double module;
	double *inv_vector;
} vector_t;

//definindo as funcoes
void getModule(vector_t *vector);
void getInversor(vector_t *vector);
vector_t *defineVector(double *cord);
void printVector (vector_t *vector);
// um vetor e composto por 2 pontos no plano.
int main(){
	vector_t *AB;
	double crd[3] = {3,-4, 0};
	AB = defineVector(crd);
	printVector(AB);
	return 0;
}

void printVector (vector_t *vector){
	printf("[+]vector(%.2f, %.2f,%.2f)\n[+]o module de |%.2f|\n[+]inversor_vector(%.2f, %.2f,%.2f)\n",
			vector->vec[0], vector->vec[1], vector->vec[2], vector->module, vector->inv_vector[0], vector->inv_vector[1], vector->inv_vector[2]);
}

vector_t *defineVector(double *cord){
	vector_t *vec = (vector_t *)malloc(sizeof(vector_t));
	vec->vec = (double *)malloc(3 * sizeof(double));
	vec->vec[0] = cord[0]; //define x = i
	vec->vec[1] = cord[1]; //define y = j
	vec->vec[2] = cord[2]; //define z = k
	//if(vec == NULL){return NULL;}
	vec->inv_vector = (double *)malloc(3 * sizeof(double));
	//if(vec->inv_vector == NULL){return NULL;}

	//chama a funcao para calcular o modulo
	getModule(vec);
	getInversor(vec);
	return vec;
}

void getInversor(vector_t *vector){
	vector->inv_vector[0] = (vector->vec[0] / vector->module);
	vector->inv_vector[1] = (vector->vec[1] / vector->module);
	vector->inv_vector[2] = (vector->vec[2] / vector->module);
}
void getModule(vector_t *vector){
	vector->module = sqrt(pow(vector->vec[0],2) + pow(vector->vec[1],2) + pow(vector->vec[2],2));
}
