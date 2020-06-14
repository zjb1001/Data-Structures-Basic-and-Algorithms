#include <stdio.h>
#include <stdlib.h>

typedef int Index;
typedef struct _hashdata  HashData;
typedef struct _hashtable * HashTable;
struct _hashtable {
    int size;
    HashData * hashArr;
};
struct _hashdata {
    int data;
    int key;
};

HashTable initTable( int size )
{
    HashTable htb = (HashTable)malloc( sizeof( struct _hashtable ) );

    htb->hashArr  = (HashData *)malloc( sizeof( HashData ) * size );
    htb->size  = size;

    for ( int i = 0; i < size; i++ )
    {
        htb->hashArr[i].key = -1;
    }
        

    return htb;
}

int hashCode( int key, int size )
{
    return key % size;
}

HashData * searchHash( HashTable htb, int num )
{
    Index hashIdx = hashCode( num, htb->size );
    while ( htb->hashArr[hashIdx].key != -1 )
    {
        if ( htb->hashArr[hashIdx].data == num )
            return htb->hashArr + hashIdx;
        
        hashIdx++;
        hashIdx %= htb->size;
    }

    return NULL;
}

Index insertHash( HashTable htb, int num )
{
    Index hashIdx = hashCode( num, htb->size );
    while ( (htb->hashArr[hashIdx].key != -1) ) 
    {
        hashIdx++;
        hashIdx %= htb->size;
    }

    htb->hashArr[hashIdx].key  = hashIdx;
    htb->hashArr[hashIdx].data = num;  

    return hashIdx;
}

int deleteHash( HashTable htb, int num )
{
    HashData *ptr = searchHash( htb, num );
    
    if ( !ptr )
        return 0;
    else 
    {
        ptr->key = -1;
        return 1;
    }
}

void prtHashTable( HashTable htb )
{
    for ( int i = 0; i < htb->size; i++ )
    {
        if ( htb->hashArr[i].key != -1 )
            printf( "%d: %d\n", htb->hashArr[i].data, htb->hashArr[i].key );
    }
}
int main( int argc, char **argv )
{
    int amount, len;
    scanf( "%d %d", &amount, &len );

    int *arr =(int *)malloc( sizeof( int ) * amount );
    HashTable htb = initTable( len );
    for ( int i = 0; i < amount; i++ )
    {
        scanf( "%d", arr + i );
        insertHash( htb, arr[i] );
    }
    
    // prtHashTable( htb );
    
    HashData *ptr = NULL;
    for ( int i = 0; i < amount; i++ )
    {
        ptr = searchHash( htb, arr[i] );
        if ( i == 0 )
            printf( "%d", ptr->key );
        else 
            printf( " %d", ptr->key );
    }

    return 0;
}