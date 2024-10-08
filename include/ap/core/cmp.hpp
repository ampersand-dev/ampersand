#ifndef AP_CMP_HPP
#define AP_CMP_HPP

#include <ap/core/operator.hpp>
#include <ap/trait.hpp>

namespace ap                                {
    template <opc C, can::cmp T, can::cmp U>
        requires is::opc::cmp<C>
    struct op<C, T, U>
        : public boolean <op <C, T, U>> {
            T self;
            U arg;

            op (T self, U arg)
                : boolean <op <C, T, U>> (*this),

                  self (self),
                  arg  (arg)
            {}
    };
}

#endif
