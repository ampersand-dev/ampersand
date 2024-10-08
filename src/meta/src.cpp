#include <ap/meta/meta.hpp>
#include <ap/meta/ope.hpp>

#include <ap/meta/pack.hpp>
#include <ap/meta/src.hpp>
#include <ap/meta/fn.hpp>

#include <stack>

namespace ap::meta::builtin                            {
    thread_local static std::stack<ap::meta::src> scope;
}

namespace ap::meta {
    src::src() {}
}

// src::push implemenetation
namespace ap::meta                                  {
    void
        src::push
            (ap::meta::pack pack)                   {
                auto& ret = ap::meta::builtin::scope;
                auto  str = ap::meta::name(pack);
                
                if (ret.empty()) return;
                if (str.empty()) return;

                auto& cur = ret.top();
                cur.pack.insert({ str, pack });
    }

    void
        src::push()                             {
            auto& ret = ap::meta::builtin::scope;
            ret.push (meta::src {});
    }

    void
        src::push
            (ap::meta::var var)                     {
                auto& src = ap::meta::builtin::scope;
                auto  opt = ap::meta::name(var);

                if (src.empty()) return;
                if (!opt)        return;

                auto& cur = src.top();
                auto& ret = cur.var;
                
                ret.insert ({ opt.value(), var });
    }

    void
        src::push
            (ap::meta::op op)                       {
                auto& src = ap::meta::builtin::scope;
                if (src.empty()) return;

                auto& cur = src.top();
                auto& ret = cur.ops;
                
                ret.push_back (op);
    }

    void 
        src::push
            (ap::meta::fn fn)                       {
                auto& src = ap::meta::builtin::scope;
                if (src.empty()) return;

                auto& cur = src.top();
                cur.fun.insert({ ap::meta::name(fn), fn });
    }
}


namespace ap::meta                              {
    std::optional<src>
        src::pop ()                             {
            auto &src = ap::meta::builtin::scope;

            if (src.empty()) return std::nullopt;
            auto ret = src.top();
            src.pop ();

            return ret;
    }

    std::optional<src>
        src::capture()                          {
            auto &src = ap::meta::builtin::scope;

            if (src.empty()) return std::nullopt;
            auto &ret = src.top();

            return ret;
    }
}