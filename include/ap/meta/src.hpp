#ifndef AP_META_SRC_HPP
#define AP_META_SRC_HPP

#include <ap/trans/trans.hpp>
#include <ap/core/core.hpp>
#include <ap/meta/meta.hpp>

#include <string_view>
#include <unordered_map>
#include <list>

namespace ap  {
    auto For();
}


namespace ap::meta                                            {
    class src                                                 {
        template <opc C, typename... T> friend struct ap::op;
        template <typename... T>        friend class  ap::pack;
        template <typename... T>        friend class  ap::var;
        template <typename... T>        friend class  ap::fn;

        template <typename... T> friend class trans::boolean;
        template <typename... T> friend class trans::func;
        template <typename... T> friend class trans::mem;
        template <typename... T> friend class trans::ari;
        template <typename... T> friend class trans::bit;
        template <typename... T> friend class trans::cmp;
        template <typename... T> friend class trans::ord;

        template <typename... T> friend class trans::pack;
        template <typename... T> friend class trans::var;
        template <typename... T> friend class trans::ops;
        template <typename... T> friend class trans::op;
        template <typename... T> friend class trans::fn;

        template <typename T>    friend class ari_eq;
        template <typename T>    friend class bit_eq;
        template <typename T>    friend class move;
        template <typename T>    friend class call;
        friend class meta::op;

        using str_t = std::string_view;
        src();

        using pack_t = std::unordered_map<str_t, ap::meta::pack>;
        using var_t  = std::unordered_map<str_t, ap::meta::var>;
        using fun_t  = std::unordered_map<str_t, ap::meta::fn>;
        using ops_t  = std::list<ap::meta::op>;
        pack_t pack;
        fun_t  fun;
        var_t  var;
        ops_t  ops;
    public:
        static void push(ap::meta::pack);
        static void push(ap::meta::var);
        static void push(ap::meta::op);
        static void push(ap::meta::fn);
        static void push();

        static std::optional<src> capture();
        static std::optional<src> pop    ();
    };
}

#endif
