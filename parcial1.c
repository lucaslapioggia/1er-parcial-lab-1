const int dimPalabra  = 20;
const int filasMax = 15;
 
int cargar_arreglo(int a[],int);
void mostrarArr (int a[], int dias);
int mayor_tramo(int arr[],int validos, int *dia);
void suma_km(int arr[], Pila * P, int cantDias);
int cargar_strings(char string[][dimPalabra], int dimFil);
void mostrar_str(char string[][dimPalabra], int validos);
int menor_nombre (char string[][dimPalabra],int validos,int pos);
void ordxseleccion_especial (char string[][dimPalabra],int validos);
 
 
int main()
{
    int ahre[100]= {0};
    int dia = 0;
    int mayorT = 0;
    Pila pili;
    inicpila(&pili);
 
    char names[filasMax][dimPalabra];
 
    /**1**/
    int validos = cargar_arreglo(ahre, 100);
 
    /**2**/
    mayorT = mayor_tramo(ahre, validos, &dia);
    printf("\nEl mayor tramo fue de %d km y se realizo el dia %d \n", mayorT, dia);
 
    /**3**/
    printf("\nEl arreglo quedo con forma: \n");
    mostrarArr(ahre, validos);
 
    /**4**/
    suma_km(ahre, &pili, validos);
    printf("\nLa cantidad de km recorridos por dias fueron: \n");
    mostrar(&pili);
 
    /**5**/
    int valstr=cargar_strings(names,filasMax);
    mostrar_str(names, valstr);
 
    /**6**/
    ordxseleccion_especial(names,valstr);
    printf("\n\n");
    mostrar_str(names, valstr);
 
    return 0;
}
 
/**1**/
int cargar_arreglo(int a[], int dim)
{
    char yes = 's';
    int tramo = 0;
    int i=0;
 
    do
    {
        for (i = 0; i<5; i++)
        {
            printf("\nIngrese el tramo %d: ",i );
            fflush(stdin);
            scanf("%d", &a[tramo]);
            tramo++;
        }
        printf("\nDesea cargar otro dia? \n");
        fflush(stdin);
        scanf("%c", &yes);
    }
    while(yes == 's' && i<dim);
 
 
    return tramo;
}
 
/**3**/
///Primera forma
void mostrarArr (int a[], int tramosVal)
{
    int cont = 0;
    int tramo = 0;
    ///Primera forma
    for (int i = 0; i<tramosVal; i++)
    {
        while (cont < 5)
        {
            if (a[tramo] != 0) ///Solamente muestro los elementos distintos a 0
            {
                printf("|%d|", a[tramo]);
            }
            tramo++;
            cont++;
        }
        printf("\n");   ///Cuando termina de mostrar 5 elementos, salto una línea
        cont = 0;
    }
}
    /// Segunda forma
void mostrarArr2 (int a[], int tramosVal)
{
    for (int i = 0; i<tramosVal; i++)
    {
            if (i%5 == 0)  ///Cada 5 elementos, salto una línea, cuando la posición es divisible por 5
            {
                printf("\n");
            }
            if (a[i] != 0) ///Solamente muestro los elementos distintos a 0
            {
                printf("|%d|", a[i]);
            }
    }
}
 
/**2**/
int mayor_tramo(int arr[],int validos, int *dia)
{
    int mayor = arr[0];
    int pos = 0;
 
    for (int i = 0; i<validos; i++)
    {
        if(arr[i]>mayor)
        {
            mayor = arr[i];
            pos = i/5;
        }
    }
 
    *dia = pos;
    return mayor;
}
 
/**4**/
void suma_km(int arr[], Pila * P, int tramosVal)
{
    int suma = 0;
    for (int i = 0; i<tramosVal; i++)
    {
        suma = suma + arr[i];
        if ( (i+1)%5 == 0 ) /// Cada 5 elementos guarda la suma en la pila (como arrancamos contando desde 0, cuando llega a 4 en realidad es 5, por eso el i+1)
        {
            apilar(P, suma);
            suma = 0;  /// Ponemos el contador de nuevo en 0 para que no sólo sea la suma de los 5 elementos sin contar los anteriores
        }
 
    }
}
 
/**5**/
int cargar_strings (char string[][dimPalabra], int dimFil)
{
    char yes = 's';
    int val = 0;
    do
    {
        printf("Ingrese un nombre: \n");
        fflush(stdin);
        gets(string[val]);
        val++;
 
        printf("Desea seguir ingresando nombres? \n");
        fflush(stdin);
        scanf("%c", &yes);
 
    }
    while(yes == 's' && val<dimFil);
    return val;
}
 
/**5**/
void mostrar_str(char string[][dimPalabra], int filasValidas)
{
    for(int i = 0; i<filasValidas; i++)
    {
        printf("|%s|\n", string[i]);
    }
}
 
/**6**/
int menor_nombre (char string[][dimPalabra],int filasValidas,int pos)
{
    int posMenor = pos;
    char menorPal[dimPalabra];
    strcpy(menorPal,string[pos]);
    for(int f=pos; f<filasValidas; f++)
    {
        if(strcmp(menorPal,string[f])>0)
        {
            strcpy(menorPal,string[f]);
            posMenor=f;
        }
    }
    return posMenor;
}
 
/**6**/
void ordxseleccion_especial (char strings[][dimPalabra],int filasValidas)
{
    int i=0;
    int posM=0;
    char aux[dimPalabra];
 
    for(i=1; i<filasValidas-2; i++) ///Empiezo una posición después y termino una antes para ignorar el primer y último elemento
    {
        posM=menor_nombre(strings,filasValidas-1,i); /// Busco el menor elemento pero ignoro el último elemento
        strcpy(aux,strings[posM]);
        strcpy(strings[posM],strings[i]);
        strcpy(strings[i],aux);
    }
}
