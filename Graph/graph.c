#include "graph.h"
#include <stdio.h>

Graph initGraph( int capa )
{
    Graph g;
    g.vcount  = 0;
    g.capa    = capa;
    g.ecount  = 0;
    g.vertice = (ElementType *)malloc( sizeof(ElementType) * capa );
    g.edge    = (Weight *)malloc( sizeof(Weight) * (capa + 1) * capa / 2 );

    return g;
}

int isGraphFull( Graph g )
{
    return g.vcount == g.capa;
}

ElementType *addNode( Graph *g, ElementType vx )
{
    if ( isGraphFull( *g ) )
        return NULL;
    g->vertice[g->vcount++] = vx;

    // update graph edge 
    int ncount = g->vcount * ( g->vcount + 1) / 2;
    for (int i = g->ecount; i < ncount; i++ ) g->edge[i] = 0;
    g->ecount  = ncount;

    return g->vertice + g->vcount;
}

void addEdge( Graph *g, ElementType va, ElementType vb )
{
    int curr = ( va > vb) ? (va * (va + 1) / 2 + vb) : (vb * (vb + 1) / 2 + va);
    g->edge[curr] = 1;
}

void prtEdge( const Graph *g )
{
    int curr;
    for ( int i = 0; i < g->vcount; i++ )
    {
        printf( "row=%2d: ", i );
        for ( int j = 0; j <= i; j++ )
        {
            curr = ( i + 1) * i / 2 + j;
            printf( "%3d", g->edge[curr] );
        }
        printf( "\n" );
    }
}

ElementType *findAdj( const Graph *g, ElementType vt )
{
    ElementType  *adjArr = (ElementType *)malloc( sizeof(ElementType) * g->vcount );

    int curr, idx = 0;
    for ( int i = 0; i < g->vcount; i++ )
    {
        curr = ( i > vt ) ? (i * (i + 1) / 2 + vt) : (vt * (vt + 1) / 2 + i);
        if ( g->edge[curr] )
            adjArr[idx++] = i;
    }
    adjArr[idx] = -1;   // mark array end

    return adjArr;
}

void _DFS( const Graph *g, ElementType vt, int *visited, int *first )
{
    if ( !visited[vt] )
    {
        visited[vt] = 1;

        if ( *first )
        {
            printf( "%d", vt );
            *first = 0;
        }
        else 
            printf( " %d", vt );
    }

    ElementType *adjArr = findAdj( g,  vt );
    for ( ElementType *iter = adjArr; *iter != -1; iter++ )
    {
        if ( !visited[*iter] )
            _DFS( g,  *iter, visited, first );
    }
}

void DFS( const Graph *g, ElementType vt, int *visited )
{
    int first =  1;
    _DFS( g, vt, visited, &first );
    // printf( "\n" );
}