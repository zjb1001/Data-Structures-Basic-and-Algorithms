#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

int main( int argc, char **argv )
{
    int pointN, edgeM;
    ElementType va, vb;
    scanf( "%d %d", &pointN, &edgeM );

    Graph g = initGraph( pointN );
    for ( int i = 0; i < pointN; i++ )
        addNode( &g, i );

    for ( int i = 0; i < edgeM; i++ )
    {
        scanf( " %d %d", &va, &vb );
        addEdge( &g, va, vb );
    }

    prtEdge( &g );

    int *visited = (int *)malloc( sizeof(int) * g.vcount );
    for ( int i = 0; i < g.vcount; i++ ) visited[i] = 0;

    for ( int i = 0; i < pointN; i++ )
    {
        if ( !visited[i] )
        {
            DFS( &g, i, visited );
            printf( "\n" );
        }
    }
    
    free( g.vertice );
    free( g.edge );
    free( visited );
    return 0;
}