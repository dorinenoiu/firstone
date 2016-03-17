#include<conio.h>
#include<stdio.h>
int x[10], a[10][10], n, m, i, j, k, ok, b, y;
int cond(int k) //Functia testeaza conditia de oprire
{
	ok = 1; //Consideram initial ok=1 si daca este cazul il modificam ulterior
	if (a[x[k]][x[k - 1]] == 0) //testeaza daca 2 orase selectate sunt vecine
		ok = 0;
	if ((k == n) && (a[x[k]][x[1]] == 0)) //Testez daca primul oras este diferit de ultimul
		ok = 0;
	for (i = 1; i<k; i++)
	if (x[k] == x[i]) //testez sa nu mai fi vizitat orasul
		ok = 0;
	return (ok); //returnez pe k pentru a putea fi testat in fct back
}
void back()
{
	for (i = 1; i <= n; i++)
		x[i] = 0;
	k = 2;
	x[1] = 1;
	while (k>1)
	if (k == n + 1) // daca am vizitat toate nodurile afisez vectorul
	{
		for (i = 1; i <= n + 1; i++) // parcurg vectorul solutie si il afisez
			printf("%d", x[i]);
		printf("\n");
		k--;
	}
	else
	if (x[k]<n) //daca x[k]<n inseamna ca mai sunt noduri nevizitate un
		//merita testate conditiile de continuare
	{
		x[k] = x[k] + 1;
		if (cond(k)) //interoghez functia cond pentru a vedea daca mai am
			//solutii
			k++; //daca am solutii il incrementez pe k pentru a cauta
		// mai eparte
	}
	else //altfel decrementez pe k
	{
		x[k] = 0;
		k--;
	}
}
void main()
{
	printf("n=");  
	scanf_s("%d", &n);
	for (i = 1; i <= n; i++)
	for (j = 1; j <= n; j++)
		a[i][j] = 0;
	printf("m="); //citesc numarul de muchii din graf
	scanf_s("%d", &m);
	for (j = 1; j <= m; j++) // marchez in matrice arcele grafului
	{
		printf("x=");
		scanf_s("%d", &b);
		printf("y=");
		scanf_s("%d", &y);
		a[b][y] = 1;
		a[y][b] = 1;
	}
	x[n + 1] = 1; //initializez ultimul element cu 1
	back();
}