#ifndef NODE_H
#define NODE_H
#include <cstdlib>
#include <stdexcept>

namespace node_h {
    class node {
    private:
        double data_field;
        node *link_field;
    public:
        node();
        node(double df, node *lf=nullptr);
        ~node();
    }
}
#endif
