add_library                           (
        ampersand-trait
        STATIC

        ../../include/ap/trait/bool.hpp
        ../../include/ap/trait/float.hpp
        ../../include/ap/trait/int.hpp
        ../../include/ap/trait/num.hpp
        ../../include/ap/trait/var.hpp
        ../../include/ap/trait/type.hpp
        ../../include/ap/trait/pack.hpp
        ../../include/ap/trait/arg.hpp

        ../../include/ap/trait/opc.hpp
        ../../include/ap/trait/op.hpp

        ../../include/ap/trait/ari.hpp
        ../../include/ap/trait/boolean.hpp
        ../../include/ap/trait/bit.hpp
        ../../include/ap/trait/ord.hpp
        ../../include/ap/trait/cmp.hpp
        ../../include/ap/trait/move.hpp

        ../../include/ap/trait.hpp
)

set_target_properties(ampersand-trait PROPERTIES LINKER_LANGUAGE CXX)