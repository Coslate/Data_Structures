#ifndef _GRAPH_H_
#define _GRAPH_H_

template <class T>
class Graph{
    public:
        int n;
        int e;

    public:
        Graph(){}

        //Destructor, virtual
        virtual ~Graph(){}

        bool IsEmpty      ()        const {return (n==0);}
        int  NumOfVertices()        const {return n;}
        int  NumOfEdges   ()        const {return e;}
};

#include <Graph.hpp>
#endif

