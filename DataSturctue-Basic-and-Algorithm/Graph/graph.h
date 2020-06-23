typedef int ElementType, Weight;
typedef struct _graph Graph;
struct _graph
{
    int vcount;
    int ecount;
    int capa;
    ElementType *vertice;
    Weight *edge;
};

Graph initGraph( int capa );

int isGraphFull( Graph g );

ElementType *addNode( Graph *g, ElementType vx );

void prtEdge( const Graph *g );

ElementType *findAdj( const Graph *g, ElementType vt );

void _DFS( const Graph *g, ElementType vt, int *visited, int *first );

void DFS( const Graph *g, ElementType vt, int *visited );