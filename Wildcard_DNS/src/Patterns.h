#ifndef WILDCARD_DNS_PATTERNS_H
#define WILDCARD_DNS_PATTERNS_H

struct Pattern {
    const char *pattern;
};

static const struct Pattern patterns[] = {
    {"*.bbb.cc.d"},
    {"g.h.i.*"},
    {"*.j.k"},
    {"*.net"},
    {"*.co.uk"},
    {"*.com.br"},
    {"m.n.o.*"},
    {"*.org"},
    {"p.q.*"},
    {"*.r.s.t.u"},
    {"*.ac.jp"},
    {"v.w.x.*"},
    {"*.y.z"},
    {"*.net"},
    {"*.com"},
    {"*.com.au"},
    {"*.e"},
    {"*.nz"},
    {"*.uk"},
    {"*.i"},
    {"*.uk"},
    {"*.edu"},
    {"*.l"},
    {"*.o"},
    {"*.s"},
    {"*.eu"},
    {"*.gov"},
    {"*.mil"},
    {"*.w"},
    {"*.int"},
    {"*.z"},
    {"*.net"},
    {"*.f"},
    {"*.edu"},
    {"*.gov"},
    {"*.mil"},
    {"*.eu"},
    {"*.int"},
    {"*.org"},
    {"a.*.c.d"},
    {"e.*.g.h"},
    {"i.*.k.l"},
    {"m.*.o.p"},
    {"q.*.s.t"},
    {"y.*.a.b"},
    {"c.*.e.f"},
    {"g.*.i.j"},
};

#endif
