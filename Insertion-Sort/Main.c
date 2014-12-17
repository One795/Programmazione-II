/*==============================================================================
Autore      : Andrea Capone		Matricola: N86001676
Programma   : insertion sort dinamico
Data        : 12/12/2014

Da Fare:
Ordinare un array in modo crescente con il metodo dell'insertion sort, ma
stavolta sviluppandolo in una funzione e utilizzando l'allocazione dinamica.
===============================================================================*/
#include<stdio.h>
#include<stdlib.h> // in questa libreria son presenti le funzioni per l'allocazione dinamica (Malloc)
#include<math.h>

void InsertionSort(int a[], int n); // dichiaro la funzione e i parametri

main()
{
    // dichiaro le variabili:

    int *a; // dichiaro un array come puntatore in modo tale che posso allocargli dinamicamente lo spazio che mi serve
            // e posso disfarmene quando non ne ho più bisogno

    int n, // dimensione dell'array
        i;

    // dichiaro la dimensione dell'array e alloco quanto spazio mi serve in memoria per contenere gli elementi

    do
    {
        printf("inserisci la dimensione dell'array\n"); // ormai non ho più limiti sul massimo della dimensione
        scanf("%d", &n);
    }while(n<1); // non posso mica inserire meno di un elemento nell'array giusto?

    // è arrivato il momento di riservarmi spazio di n elementi per l'array tramite la malloc:

    a=(int*) malloc(n*sizeof(int)); // ora che ho preso lo spazio per l'array, potrò liberarmene quando non mi serve più.

    // inserisco gli elementi dell'array:

    for(i=0;i<n;i++)
    {
        printf("inserisci l' elemento %d dell'array\n",i+1); // ormai non ho più limiti sul massimo della dimensione
        scanf("%d", &a[i]);
    }

    // trovo il minimo e lo metto al primo posto:

    int min= a[0]; // elemento di partenza
    int p=0; // posizione iniziale che mi servirà per spostare il minimo al primo posto
    for(i=1;i<n;i++)
    {
        if (min>a[i])
        {
            min=a[i]; //salvo il valore del minimo e uso min come variabile di appoggio
            p=i; // salvo la posizione del minimo
        }
    }
    a[p]=a[0];
    a[0]=min;
    printf("minimo: %d\n", min); // stampo il minimo

    // richiamo la funzione:

    InsertionSort(a,n);
    
    // stampo l'array :

    printf("elementi dell'array:\n");
    for(i=0;i<n;i++)
    {
        printf("a[%d] %d\n",i+1, a[i]);
    }
}
    free(a); // libero la memoria che non mi serve più
}



    
